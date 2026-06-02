# Proyecto 14 Coche Inteligente Controlado por Mando IR

![ff2fec813f8765e1bcd593b37b9c0a4f](media/A123.jpeg)

### **1.Descripción**

En este proyecto, haremos un coche inteligente controlado por mando IR y presionaremos el botón en el mando IR para conducir el coche y hacerlo moverse.

### **2.Diagrama de Flujo**

![img](media/A124.png)

**La lógica específica del coche inteligente controlado por mando IR se muestra a continuación:**

| Configuración inicial                     |           | La placa LED muestra una cara sonriente          |
| ----------------------------------------- | --------- | ------------------------------------------------- |
| Control remoto                           | Valor clave | Estado de la tecla                                |
| ![img](media/A125.jpg) | FF629D    | Adelante La placa LED 8*8 muestra el icono de frente |
| ![img](media/A126.jpg) | FFA857    | Atrás La placa LED 8*8 muestra el icono de atrás  |
| ![img](media/A127.jpg)                  | FF22DD    | Girar a la izquierda La placa LED 8*8 muestra el icono hacia la izquierda |
| ![img](media/A128.jpg)                  | FFC23D    | Girar a la derecha La placa LED 8*8 muestra el icono hacia la derecha |
| ![img](media/A129.jpg)                 | FF02FD    | Parar La placa LED 8*8 muestra “STOP”             |

### **3.Diagrama de Conexiones**

![9d8b58dff14fe22b5c87514db944530c](media/A130.png)

1). GND, VCC, SDA y SCL del módulo de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). Como el receptor IR está integrado en el Shield de motor 8833, no es necesario cableado adicional. Los pines del receptor IR en la placa 8833 son G (GND), V (VCC) y D3 respectivamente.

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo está conectado a 5V (V) y el cable naranja está conectado a A3.

4). La alimentación está conectada al puerto BAT
    

### **4.Código de Prueba**

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lección 14
Coche controlado por mando IR
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Configurar el pin de reloj a A5
#define SDA_Pin  A4  //Configurar el pin de datos a A4
//Array, usado para almacenar los datos del patrón, puede ser calculado por ti mismo o obtenido de la herramienta de módulo
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#include <Arduino.h>
#include <IRremote.h>//biblioteca de funciones del control remoto IR
int RECV_PIN = 3;//configurar el pin del receptor IR a D3
IRrecv irrecv(RECV_PIN);
long irr_val;
decode_results results;

int left_ctrl = 2;//definir los pines de control de dirección del motor grupo B
int left_pwm = 5;//definir los pines de control PWM del motor grupo B
int right_ctrl = 4;//definir los pines de control de dirección del motor grupo A
int right_pwm = 6;//definir los pines de control PWM del motor grupo A

#include <Servo.h>
Servo servo_A3;//configurar el pin del servo a A3 

unsigned char data_line = 0;
unsigned char delay_count = 0;

void setup() {
  Serial.begin(9600);//
  // En caso de que el controlador de interrupciones falle en el setup, dar una pista
  // al usuario sobre lo que está ocurriendo.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Iniciar el receptor
  Serial.println("Enabled IRin");
  pinMode(left_ctrl,OUTPUT);//configurar los pines de control de dirección del motor grupo B como OUTPUT
  pinMode(left_pwm,OUTPUT);//configurar los pines de control PWM del motor grupo B como OUTPUT
  pinMode(right_ctrl,OUTPUT);//configurar los pines de control de dirección del motor grupo A como OUTPUT
  pinMode(right_pwm,OUTPUT);//configurar los pines de control PWM del motor grupo A como OUTPUT
  servo_A3.attach(A3);
  servo_A3.write(90);//el ángulo del servo es 90 grados
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Configurar el pin de reloj como salida
  pinMode(SDA_Pin,OUTPUT);//Configurar el pin de datos como salida
  matrix_display(clear);
  matrix_display(start01); //mostrar patrón de expresión start01
}

void loop()
 {
  if (irrecv.decode(&results)) 
 {
    irr_val = results.value;
    Serial.println(irr_val, HEX);//imprime por serial las señales IR remotas leídas 
    switch(irr_val)
    {
      case 0xFF629D : car_front(); //Recibe 0xFF629D, el coche avanza
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 0xFFA857 : car_back(); //Recibe 0xFFA857, el coche retrocede
      matrix_display(clear);
      matrix_display(back); 
      break;
    
      case 0xFF22DD : car_left(); //Recibe 0xFF22DD, el coche gira a la izquierda
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 0xFFC23D : car_right();//Recibe 0xFFC23D, el coche gira a la derecha
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 0xFF02FD : car_Stop();//Recibe 0xFF02FD, el coche se detiene
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
    }
        irrecv.resume(); // Recibe el siguiente valor
  }
}

void car_front()//definir el estado de avance
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,105);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,105);
}
void car_back()//definir el estado de retroceso
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
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

//esta función se usa para la pantalla de matriz de puntos
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la función que llama la condición de inicio de transferencia de datos
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
    digitalWrite(SCL_Pin, LOW); //bajar el pin de reloj SCL_Pin para cambiar la SEÑAL de SDA 
  }
}
//*******************************************************************************
```

### **5. Resultado de la prueba**

Después de cargar correctamente el código en la placa V4.0, conecte los cables según el diagrama de conexiones, encienda la alimentación externa y luego ponga el interruptor DIP en ON. Entonces podremos usar el control remoto IR para conducir el coche y la placa LED 8X16 mostrará el patrón de estado correspondiente.