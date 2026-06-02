# Proyecto 13 Coche Inteligente con Evitación de Obstáculos por Ultrasonidos

![fd4044796307f709987b9d2e215e0911](media/A119.png)

### **1. Descripción**

En este proyecto, nuestro objetivo es crear un coche inteligente con evitación de obstáculos por ultrasonidos. Usaremos el sensor ultrasónico para detectar la distancia al obstáculo, lo cual se puede usar para controlar el servo y hacer que gire para que el coche se mueva. Mientras tanto, la placa LED 8X16 mostrará el patrón de estado correspondiente.

### **2. Diagrama de Flujo**

![img](media/A120.png)

**La lógica específica del coche inteligente con evitación de obstáculos por ultrasonidos se muestra a continuación:**

![Img](media/A121.png)

![Img](media/A122.png)

### **3. Diagrama de Conexiones**

![](media/A118.png)

1). GND, VCC, SDA y SCL del módulo de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). VCC, Trig, Echo y Gnd del sensor ultrasónico están conectados a 5V (V), D12 (S), D13 (S) y Gnd (G).

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo está conectado a 5V (V) y el cable naranja está conectado a A3.

4). La alimentación está conectada al puerto BAT.

### **4. Código de Prueba**

```c 
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 13
 Avoiding Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Establecer el pin de reloj a A5
#define SDA_Pin  A4  //Establecer el pin de datos a A4
//Array, usado para almacenar los datos del patrón, puede calcularse por sí mismo o obtenerse de la herramienta de módulo
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//definir los pines de control de dirección del motor grupo B
int left_pwm = 5;//definir los pines de control PWM del motor grupo B
int right_ctrl = 4;//definir los pines de control de dirección del motor grupo A
int right_pwm = 6;//definir los pines de control PWM del motor grupo A

#include "SR04.h"//definir la librería del sensor ultrasónico
#define TRIG_PIN 12// establecer la salida de señal del sensor ultrasónico a D12 
#define ECHO_PIN 13//establecer la entrada de señal del sensor ultrasónico a D13 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance,a1,a2;//definir tres variables de distancia
const int servopin = A3;//establecer el pin del servo a A3 

void setup() {
  pinMode(left_ctrl,OUTPUT);//establecer los pines de control de dirección del motor grupo B como OUTPUT
  pinMode(left_pwm,OUTPUT);//establecer los pines de control PWM del motor grupo B como OUTPUT
  pinMode(right_ctrl,OUTPUT);//establecer los pines de control de dirección del motor grupo A como OUTPUT
  pinMode(right_pwm,OUTPUT);//establecer los pines de control PWM del motor grupo A como OUTPUT
  pinMode(TRIG_PIN, OUTPUT); //Establecer el pin trig como salida
  pinMode(ECHO_PIN, INPUT); //Establecer el pin echo como entrada
  servopulse(servopin,90);//el ángulo del servo es 90 grados
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Establecer el pin de reloj como salida
  pinMode(SDA_Pin,OUTPUT);//Establecer el pin de datos como salida
  matrix_display(clear);
}
 
void loop()
 {
  avoid();//ejecutar el programa principal
}

void avoid()
{
  distance=sr04.Distance(); //obtener el valor detectado por el sensor ultrasónico 

  if((distance < 20)&&(distance != 0))//si la distancia es mayor que 0 y menor que 10  

  {
    car_Stop();//detener
    matrix_display(clear);
    matrix_display(STOP01);//mostrar patrón de parada
    delay(1000);
    servopulse(servopin,160);//el servo gira a 160°
    delay(500);
    a1=sr04.Distance();//medir la distancia
    delay(100);
    servopulse(servopin,20);//girar a 20 grados
    delay(500);
    a2=sr04.Distance();//medir la distancia
    delay(100);
    servopulse(servopin,90);  //Regresar a la posición de 90 grados
    delay(500);
    if(a1 > a2)//comparar la distancia, si la distancia izquierda es mayor que la derecha
    {
      car_left();//girar a la izquierda
      matrix_display(clear);
      matrix_display(left);    //mostrar patrón de giro a la izquierda
      servopulse(servopin,90);//el servo gira a 90 grados
      delay(700); //girar a la izquierda 700ms
      matrix_display(clear);
      matrix_display(front);  //mostrar patrón hacia adelante
    }
    else//si la distancia derecha es mayor que la izquierda
    {
      car_right();//girar a la derecha
      matrix_display(clear);
      matrix_display(right);  //mostrar patrón de giro a la derecha
      servopulse(servopin,90);//el servo gira a 90 grados
      delay(700);
      matrix_display(clear);
      matrix_display(front);  //mostrar patrón hacia adelante
    }
  }
  else//de lo contrario
  {
    car_front();//avanzar
    matrix_display(clear);
    matrix_display(front);  // mostrar patrón hacia adelante
  }
}

void car_front()//el coche avanza
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//retroceder
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//el coche gira a la izquierda
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//el coche gira a la derecha
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//detener
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//el ángulo de funcionamiento del servo
{
  for(int i=0; i<20; i++)
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

```cpp
  for (int i = 0; i < 16; i++) //los datos del patrón son 16 bytes
  {
    IIC_send(matrix_value[i]); //Transmitir los datos del patrón
  }
  IIC_end();   //Finalizar la transmisión de datos del patrón
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
    digitalWrite(SCL_Pin, HIGH); //Elevar el pin de reloj SCL_Pin para detener la transmisión de datos
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //bajar el pin de reloj SCL_Pin para cambiar la SEÑAL de SDA 
  }
}
//*******************************************************************************
```

### **5.Resultado de la prueba**

Después de cargar con éxito el código en la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la fuente de alimentación externa y luego gira el interruptor DIP a ON.

El coche inteligente avanza y evita obstáculos automáticamente. Cuando no hay camino adelante, el servo moverá el sensor ultrasónico para escanear las distancias izquierda, central y derecha, y el coche girará hacia el lado abierto. Mientras tanto, la placa LED 8X16 mostrará el patrón de estado correspondiente.