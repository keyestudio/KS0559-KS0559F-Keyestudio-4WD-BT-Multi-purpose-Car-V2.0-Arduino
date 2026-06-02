# Proyecto 12 Coche Inteligente Seguimiento Ultrasónico

![a3beaada39eb1471b7df6d9788e2bea3](media/A116.png)

### **1.Descripción**

En este proyecto, buscaremos detectar la distancia entre el coche inteligente 4WD y los obstáculos delante mediante un sensor ultrasónico para controlar dos motores de manera que el coche se mueva y el tablero LED 8\*8 muestre un patrón facial sonriente.

### **2.Diagrama de Flujo**

![img](media/A117.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Detección</td>
<td>Distancia medida de los obstáculos frontales</td>
<td>distancia (unidad: cm)</td>
</tr>
<tr class="even">
<td>Configuración</td>
<td>El tablero LED 8*16 muestra un patrón de sonrisa.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Configurar servo a 90°</td>
<td></td>
</tr>
<tr class="even">
<td>Condición</td>
<td>distancia≥20 y distancia≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>Estado</td>
<td>Avanzar</td>
<td></td>
</tr>
<tr class="even">
<td>Condición</td>
<td>distancia＞10 y distancia＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>distancia＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Condición</td>
<td>detenerse</td>
<td></td>
</tr>
<tr class="odd">
<td>Condición</td>
<td>distancia≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Condición</td>
<td>Retroceder</td>
<td></td>
</tr>
</tbody>
</table>


### **3.Diagrama de Conexiones**

![568a66655a14dd34afd8cb1e6ae5951c](media/A118.png)

**Conexiones:**

1). GND, VCC, SDA y SCL del tablero LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). VCC, Trig, Echo y Gnd del sensor ultrasónico están conectados a 5V (V), D12 (S), D13 (S) y Gnd (G).

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo a 5V (V) y el cable naranja a A3.

4). La alimentación está conectada al puerto BAT.

### **4.Código de Prueba**

```c
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lección 12
 Coche Seguimiento
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Configurar el pin de reloj a A5
#define SDA_Pin  A4  //Configurar el pin de datos a A4

//Array, usado para almacenar los datos del patrón, puede ser calculado por ti mismo o obtenido de la herramienta del módulo
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};

const int servopin = A3;//Configurar el pin del servo
 
#include "SR04.h" //definir la librería de funciones del sensor ultrasónico
#define TRIG_PIN 12// configurar la señal del sensor ultrasónico a D12
#define ECHO_PIN 13// configurar la señal del sensor ultrasónico a D13
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

int left_ctrl = 2;//definir los pines de control de dirección del motor grupo B
int left_pwm = 5;//definir los pines de control PWM del motor grupo B
int right_ctrl = 4;//definir los pines de control de dirección del motor grupo A
int right_pwm = 6;//definir los pines de control PWM del motor grupo A

void setup() {
  pinMode(left_ctrl,OUTPUT);//configurar los pines de control de dirección del motor grupo B como OUTPUT
  pinMode(left_pwm,OUTPUT);//configurar los pines PWM del motor grupo B como OUTPUT
  pinMode(right_ctrl,OUTPUT);//configurar los pines de control de dirección del motor grupo A como OUTPUT
  pinMode(right_pwm,OUTPUT);//configurar los pines PWM del motor grupo A como OUTPUT
  pinMode(TRIG_PIN, OUTPUT); //Configurar el pin trig como salida
  pinMode(ECHO_PIN, INPUT); //Configurar el pin echo como entrada
  pinMode(SCL_Pin,OUTPUT);//Configurar el pin de reloj como salida
  pinMode(SDA_Pin,OUTPUT);//Configurar el pin de datos como salida
  servopulse(servopin,90);//Configurar el ángulo inicial del servo a 90°
  delay(500); //esperar 500ms
  matrix_display(smile);  //mostrar patrón de expresión sonriente  
}

void loop() {
  distance = sr04.Distance();//la distancia detectada por el sensor ultrasónico
   if(distance <= 10)//si la distancia es menor o igual a 10
  {
    back();//retroceder
  }
  else if((distance > 10)&&(distance< 20 ))//si 10<distancia<20
  {
    Stop();//detenerse
  }
  else if((distance >= 20)&&(distance <= 50))//si 20≤distancia≤50  
{
    front();//avanzar
  }
  else//de lo contrario
  {
    Stop();//detenerse
  }
}

void front()//define el estado de avanzar hacia adelante
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,100);
}
void back()//define el estado de retroceder
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void left()//define el estado de girar a la izquierda
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//define el estado de girar a la derecha
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void Stop()//define el estado de detenerse
{
  digitalWrite(left_ctrl, LOW);  
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//Ángulo de funcionamiento del servo
{
  for(int i=0; i<30; i++)
  {
    int pulsewidth = (myangle*11)+500;
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servopin,LOW);
    delay(20-pulsewidth/1000);
  }  
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
//*******************************************************************************
```

### **5.Resultado de la prueba**

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la fuente de alimentación externa y luego activa el interruptor DIP a ON. Ajusta el servo a 90°, el coche inteligente se moverá con los obstáculos y la placa LED 8X16 mostrará “smile”.