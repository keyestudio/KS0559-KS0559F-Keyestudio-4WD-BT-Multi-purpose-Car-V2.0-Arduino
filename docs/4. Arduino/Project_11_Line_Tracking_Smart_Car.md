# Proyecto 11 Coche Inteligente de Seguimiento de Línea

![eff7a15e697e8b78bde391f806ea024d](media/A112.png)

### **1.Descripción**

Basado en el principio de funcionamiento del sensor de seguimiento de línea, creamos un coche inteligente de seguimiento de línea.

En este proyecto, detectamos si hay una línea negra en la parte inferior del coche inteligente mediante un sensor de seguimiento de línea, y luego controlamos la rotación de los dos grupos de motores según los resultados de la detección de manera que el coche inteligente se desplace a lo largo de la línea negra.

### **2.Diagrama de Flujo**

![img](media/A113.png)

![Img](media/A114.png)

### **3.Diagrama de Conexiones**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A115.png)

G, V, S1, S2 y S3 del sensor de seguimiento de línea están conectados a G (GND), V (VCC), D11, D7 y D8 de la placa de expansión del sensor.

La alimentación está conectada al puerto BAT.

### **4.Código de Prueba**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lección 11
 Coche de Seguimiento
 http://www.keyestudio.com
*/ 
//Datos del patrón de sonrisa obtenidos de la herramienta táctil
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //Configurar pin de datos en A4
#define SCL_Pin  A5  //Configurar pin de reloj en A5

int left_ctrl = 2;//definir los pines de control de dirección del motor grupo B
int left_pwm = 5;//definir los pines de control PWM del motor grupo B
int right_ctrl = 4;//definir los pines de control de dirección del motor grupo A
int right_pwm = 6;//definir los pines de control PWM del motor grupo A
int sensor_L = 11;//definir el pin del sensor de seguimiento de línea izquierdo
int sensor_M = 7;//definir el pin del sensor de seguimiento de línea central
int sensor_R = 8;//definir el pin del sensor de seguimiento de línea derecho
int L_val,M_val,R_val;//definir estas variables

void setup() {
  Serial.begin(9600);//iniciar monitor serial y establecer baud rate a 9600
  pinMode(left_ctrl,OUTPUT);//configurar pines de control de dirección del motor grupo B como OUTPUT
  pinMode(left_pwm,OUTPUT);//configurar pines de control PWM del motor grupo B como OUTPUT
  pinMode(right_ctrl,OUTPUT);//configurar pines de control de dirección del motor grupo A como OUTPUT
  pinMode(right_pwm,OUTPUT);//configurar pines de control PWM del motor grupo A como OUTPUT
  pinMode(sensor_L,INPUT);//configurar pines del sensor de seguimiento de línea izquierdo como INPUT
  pinMode(sensor_M,INPUT);//configurar pines del sensor de seguimiento de línea central como INPUT
  pinMode(sensor_R,INPUT);//configurar pines del sensor de seguimiento de línea derecho como INPUT
  //Configurar pines como salida
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(start01);//Mostrar patrón de inicio
}

void loop() 
{
  tracking(); //ejecutar programa principal
}

void tracking()
{
  L_val = digitalRead(sensor_L);//leer el valor del sensor de seguimiento de línea izquierdo
  M_val = digitalRead(sensor_M);//leer el valor del sensor de seguimiento de línea central
  R_val = digitalRead(sensor_R);//leer el valor del sensor de seguimiento de línea derecho

  if(M_val == 1){//si el estado del sensor central es 1, lo que significa que detecta línea negra

     if (L_val == 1 && R_val == 0) { //Si se detecta una línea negra a la izquierda, pero no a la derecha, gira a la izquierda
        left();
    }
     else if (L_val == 0 && R_val == 1) { //De lo contrario, si se detecta una línea negra a la derecha y no a la izquierda, gira a la derecha
      right();
    }
     else { //De lo contrario, avanza
      front();
    }
  }
  else { //No se detectan líneas negras en el centro
    if (L_val == 1 && R_val == 0) { //Si se detecta una línea negra a la izquierda, pero no a la derecha, gira a la izquierda
      left();
    }
    else if (L_val == 0 && R_val == 1) { //De lo contrario, si se detecta una línea negra a la derecha y no a la izquierda, gira a la derecha
      right();
    }
    else { //De lo contrario, detente
      Stop();
    }
  }
}
void front()//define el estado de avanzar hacia adelante
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void back()//define el estado de retroceder
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void left()//define el estado de giro a la izquierda
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//define el estado de giro a la derecha
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void Stop()//define el estado de parada
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm,0);
}

//esta función se usa para la pantalla de matriz de puntos
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la función que llama a la condición de inicio de transferencia de datos
  IIC_send(0xc0);  //seleccionar dirección

  for (int i = 0; i < 16; i++) //los datos del patrón son 16 bytes
  {
    IIC_send(matrix_value[i]); //Transmitir los datos del patrón
  }
  IIC_end();   //Fin de la transmisión de datos del patrón
  IIC_start();
  IIC_send(0x8A);  //Control de pantalla, seleccionar ancho de pulso 4/16
  IIC_end();
}
//Condiciones bajo las cuales comienza la transmisión de datos
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Indica el fin de la transmisión de datos
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
//transmitir datos
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Cada byte tiene 8 bits y se verifica bit a bit comenzando por el menos significativo
  {
    if (send_data & mask) { //Establece los niveles alto y bajo de SDA_Pin dependiendo de si cada bit del byte es un 1 o un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Eleva el pin de reloj SCL_Pin para detener la transmisión de datos
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //baja el pin de reloj SCL_Pin para cambiar la SEÑAL de SDA 
  }
}
//*************************************************************************
```

### **5. Resultado de la prueba**

Después de subir con éxito el código a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la fuente de alimentación externa y luego gira el interruptor DIP a ON. Entonces, el coche inteligente seguirá las líneas.