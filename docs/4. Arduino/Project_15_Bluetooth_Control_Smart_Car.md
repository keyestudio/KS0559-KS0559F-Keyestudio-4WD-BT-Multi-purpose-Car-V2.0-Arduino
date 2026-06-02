# Proyecto 15 Coche Inteligente Controlado por Bluetooth

![8abdadfa2fc462bdcc0542df52a793e3](media/A131.jpeg)

### **1.Descripción**

Hemos aprendido los conocimientos básicos de Bluetooth. Y en esta lección, haremos un coche inteligente controlado por Bluetooth. En este proyecto, nuestro objetivo es considerar el teléfono móvil como el transmisor (host), y el coche inteligente conectado al módulo Bluetooth BT24 (esclavo) como el receptor, y usar la APP móvil para controlar el coche inteligente vía Bluetooth.

### **2.Botones de Control de la APP**

|                           | Carácter de control                                         | Carácter de control                                         |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Pulsar: F  <br />Soltar: S                                   | Pulsar el botón, el coche avanza; <br />soltar para detener |
| ![img](media/A64.jpg) | Pulsar: L  <br />Soltar: S                                   | Pulsar el botón, el coche gira a la izquierda; <br />soltar para detener  |
| ![img](media/A65.jpg) | Pulsar: R  <br />Soltar: S                                   | Pulsar el botón, el coche gira a la derecha; <br />soltar para detener |
| ![img](media/A66.jpg) | Pulsar: B  <br />Soltar: S                                   | Pulsar el botón, el coche retrocede; <br />soltar para detener   |
| ![img](media/A67.jpg) | Pulsar: “a”  <br />Soltar: “S”                               | Clic para acelerar (máximo:255)                               |
| ![img](media/A68.jpg) | Pulsar: “d”  <br />Soltar: “S”                               | Clic para desacelerar (mínimo:0)                                |
| ![img](media/A69.jpg) | Clic para iniciar la función de detección de gravedad del <br />teléfono móvil: clic de nuevo para <br />salir del control por gravedad |                                                              |
| ![img](media/A70.jpg) | Clic para enviar “X”, <br />clic de nuevo para enviar “S”    | Iniciar función de seguimiento de línea; <br />clic de nuevo para salir      |
| ![img](media/A71.jpg) | Clic para enviar “Y”, <br />clic de nuevo para enviar “S”    | Iniciar función de evitación ultrasónica; <br />clic de nuevo para salir |
| ![img](media/A72.jpg) | Clic para enviar “U”, <br />clic de nuevo para enviar “S”    | Iniciar función de seguimiento ultrasónico; <br />clic de nuevo para salir |
| ![img](media/A73.jpg) | Clic para enviar “G”, <br />clic de nuevo para enviar “S”    | Iniciar función de restricción; <br />clic de nuevo para salir       |

### **3.Diagrama de Flujo**

![img](media/A132.png)

### **4.Diagrama de Conexiones**



![61be6959693b2111639252ea45ec60fc](media/A133.png)

1). GND, VCC, SDA y SCL de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.
    
2). RXD, TXD, GND y VCC del módulo Bluetooth están conectados respectivamente a TX, RX, G y 5V en el Shield motor 8833, mientras que los pines STATE y BRK del módulo Bluetooth no necesitan ser conectados.
    
3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo está conectado a 5V (V) y el cable naranja está conectado a A3.
    
4). La alimentación está conectada al puerto BAT
    

### **5.Código de Prueba**

<span style="color: rgb(255, 76, 65);">**Nota:** Antes de subir el código de prueba, necesitas retirar el módulo Bluetooth, de lo contrario el código no se podrá subir. Conecta el módulo Bluetooth después de subir el código con éxito.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lección 15
Control del coche por Bluetooth
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Configurar el pin de reloj en A5
#define SDA_Pin  A4  //Configurar el pin de datos en A4
//Array, usado para almacenar los datos del patrón, puede ser calculado por ti mismo o obtenido de la herramienta del módulo
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//definir los pines de control de dirección del motor del grupo B
int left_pwm = 5;//definir los pines de control PWM del motor del grupo B
int right_ctrl = 4;//definir los pines de control de dirección del motor del grupo A
int right_pwm = 6;//definir los pines de control PWM del motor del grupo A

const int servopin = A3;//configurar el pin del servo en A3 

char BLE_val;

void setup() {
  Serial.begin(9600);//
  pinMode(left_ctrl,OUTPUT);//configurar los pines de control de dirección del motor del grupo B como OUTPUT
  pinMode(left_pwm,OUTPUT);//configurar los pines de control PWM del motor del grupo B como OUTPUT
  pinMode(right_ctrl,OUTPUT);//configurar los pines de control de dirección del motor del grupo A como OUTPUT
  pinMode(right_pwm,OUTPUT);//configurar los pines de control PWM del motor del grupo A como OUTPUT
  servopulse(servopin,90);//el ángulo del servo es de 90 grados
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Configurar el pin de reloj como salida
  pinMode(SDA_Pin,OUTPUT);//Configurar el pin de datos como salida
  matrix_display(clear);
  matrix_display(start01); //mostrar el patrón de expresión start01
}

void loop() {
   if(Serial.available()>0) {
    BLE_val = Serial.read();
    Serial.println(BLE_val);
  } 
    switch(BLE_val)
    {
      case 'F' : car_front(); //Recibe 'F', el coche avanza
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); //Recibe 'B', el coche retrocede
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); //Recibe 'L', el coche gira a la izquierda
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();//Recibe 'R', el coche gira a la derecha
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();//Recibe 'S', el coche se detiene
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
}
}

void car_front()//definir el estado de avance
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//definir el estado de retroceso
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//establecer el estado de giro a la izquierda
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//establecer el estado de giro a la derecha
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//definir el estado de parada
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//Ángulo de funcionamiento del servomotor
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Cada byte tiene 8 bits y se verifica bit a bit comenzando por el nivel más bajo
  {
    if (send_data & mask) { //Establece los niveles alto y bajo de SDA_Pin dependiendo de si cada bit del byte es un 1 o un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Elevar el pin de reloj SCL_Pin para detener la transmisión de datos
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //bajar el pin de reloj SCL_Pin para cambiar la SEÑAL de SDA 
  }
}
//*******************************************************************************
```

### **6. Resultado de la prueba**

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la alimentación externa y luego gira el interruptor DIP a ON.

Inserta el módulo BT y abre tu celular para conectar el Bluetooth y controlar el smart car. El coche se moverá hacia adelante, hacia atrás, girará a la izquierda y a la derecha y se detendrá. Además, la placa LED 8\*8 mostrará los patrones correspondientes.