# Proyecto 16 Control de Velocidad por Bluetooth para Coche Inteligente

![](media/A131.jpeg)

### **1. Descripción**

En este proyecto, usaremos Bluetooth para ajustar la velocidad del coche inteligente. Permitimos definir velocidades variables y cambiarlas para modificar la velocidad del coche inteligente.

### **2. Diagrama de Flujo**

![90ab1f7fb1e16ad3c018b1c631e407c3](media/A134.png)

### **3. Diagrama de Conexiones**

![](media/A135.png)

1). GND, VCC, SDA y SCL de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). RXD, TXD, GND y VCC del módulo Bluetooth están conectados respectivamente a TX, RX, G y 5V en el Shield motor 8833, mientras que los pines STATE y BRK del módulo Bluetooth no necesitan ser conectados.

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo a 5V (V) y el cable naranja a A3.

4). La alimentación está conectada al puerto BAT.

### **4. Código de Prueba**

<span style="color: rgb(255, 76, 65);">**Nota:** Antes de subir el código de prueba, debe retirar el módulo Bluetooth, de lo contrario el código no se podrá subir. Conecte el módulo Bluetooth después de subir el código con éxito.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 16
Bluetooth Speed Control Car
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Establecer el pin de reloj en A5
#define SDA_Pin  A4  //Establecer el pin de datos en A4
//Array, usado para almacenar los datos del patrón, puede ser calculado por usted mismo o obtenido de la herramienta de módulo
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char speed_a[] = 
{0x00,0x40,0x20,0x10,0x08,0x04,0x02,0xff,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00};
unsigned char speed_d[] = 
{0x00,0x02,0x04,0x08,0x10,0x20,0x40,0xff,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00};

int left_ctrl = 2;//definir los pines de control de dirección del motor grupo B
int left_pwm = 5;//definir los pines de control PWM del motor grupo B
int right_ctrl = 4;//definir los pines de control de dirección del motor grupo A
int right_pwm = 6;//definir los pines de control PWM del motor grupo A

int speeds = 150; //Establecer la velocidad inicial en 150

const int servopin = A3;//establecer el pin del servo en A3 

char BLE_val;

void setup() {
  Serial.begin(9600);//
  pinMode(left_ctrl,OUTPUT);//establecer los pines de control de dirección del motor grupo B como OUTPUT
  pinMode(left_pwm,OUTPUT);//establecer los pines de control PWM del motor grupo B como OUTPUT
  pinMode(right_ctrl,OUTPUT);//establecer los pines de control de dirección del motor grupo A como OUTPUT
  pinMode(right_pwm,OUTPUT);//establecer los pines de control PWM del motor grupo A como OUTPUT
  servopulse(servopin,90);//el ángulo del servo es 90 grados
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Establecer el pin de reloj como salida
  pinMode(SDA_Pin,OUTPUT);//Establecer el pin de datos como salida
  matrix_display(clear);
  matrix_display(start01); //mostrar el patrón start01
}

void loop() {
   if(Serial.available()>0) {
    BLE_val = Serial.read();
    Serial.println(BLE_val);
  } 
    switch(BLE_val)
    {
      case 'F' : car_front(); 
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); 
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); 
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();
      matrix_display(clear);
      matrix_display(STOP01); 
      break;

      case 'a' : speeds_a();
      matrix_display(clear);
      matrix_display(speed_a);  
      break;
     
      case 'd' : speeds_d();
      matrix_display(clear);
      matrix_display(speed_d); 
      break;
    }
}

void car_front()//define el estado de avanzar
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//define el estado de retroceder
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//establece el estado de giro a la izquierda
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//establece el estado de giro a la derecha
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//define el estado de parada
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //función de aumento rápido
  while (1) {
    Serial.println(speeds);  //muestra la información de velocidad
    if (speeds < 255) { //Hasta 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //ajusta la velocidad de crecimiento
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Recibe 'S', el coche deja de acelerar
    break;
  }
}
void speeds_d() { //función de reducción de velocidad
  while (1) {
    Serial.println(speeds);  //muestra la información de velocidad
    if (speeds > 0) { //hasta 0
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //ajusta la velocidad de desaceleración
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Recibe 'S', el coche deja de desacelerar
    break;
}
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
    digitalWrite(SCL_Pin, LOW); //Bajar el pin de reloj SCL_Pin para cambiar la SEÑAL de SDA 
  }
}
//*******************************************************************************
```

### **5. Resultado de la prueba**

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la fuente de alimentación externa y luego activa el interruptor DIP. Empareja la APP con Bluetooth, el coche inteligente podrá ser controlado para moverse mediante la APP.

Presiona ![049343f587e0e7cf19fe8b665d735321](media/A136.png), el coche acelerará, presiona ![264f77cce6018584b54f46676fee4247](media/A137.png), el coche desacelerará, y la placa LED 8\*16 mostrará el patrón de estado correspondiente del coche inteligente.