# Proyecto 17 Coche Inteligente Bluetooth Multiusos

![2c1198e0ebd7c31622b7438469fb572c](media/A138.jpeg)

### **1.Descripción**

En proyectos anteriores, el coche solo realiza una función única. Sin embargo, en esta lección, integraremos todas sus funciones a través de Bluetooth.

### **2.Diagrama de Flujo**

![73f4da1e321bc29282d3b2f5cb3168dd](media/A139.png)

### **3.Diagrama de Conexiones**

![fce8edd349ddbcfe02e6f27feb73e90f](media/A140.png)

1). GND, VCC, SDA y SCL de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). RXD, TXD, GND y VCC del módulo Bluetooth están conectados respectivamente a TX, RX, G y 5V en el Shield motor 8833, mientras que los pines STATE y BRK del módulo Bluetooth no necesitan ser conectados.

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo a 5V (V) y el cable naranja a A3.

4). G, V, S1, S2 y S3 del sensor de seguimiento de línea están conectados a G (GND), V (VCC), D11, D7 y D8 de la placa de expansión del sensor.

5). VCC, Trig, Echo y Gnd del sensor ultrasónico están conectados a 5V (V), D12 (S), D13 (S) y Gnd (G).

6). La alimentación está conectada al puerto BAT.

### **4.Código de Prueba**

<span style="color: rgb(255, 76, 65);">**Nota:** Antes de subir el código de prueba, debe retirar el módulo Bluetooth, de lo contrario el código no se podrá subir. Conecte el módulo Bluetooth después de subir el código con éxito.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lección 17
Coche Multifuncional Bluetooth
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Configurar el pin de reloj a A5
#define SDA_Pin  A4  //Configurar el pin de datos a A4
//Array, usado para almacenar los datos del patrón, puede calcularse por sí mismo o obtenerse de la herramienta de módulo
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
int speeds = 150; //Establecer la velocidad inicial a 150

const int servopin = A3;//configurar el pin del servo a A3 

int L_pin = 11; //definir el pin del sensor de seguimiento izquierdo como D11
int M_pin = 7; //definir el pin del sensor de seguimiento medio como D7
int R_pin = 8; //definir el pin del sensor de seguimiento derecho como D8
int L_val, M_val, R_val;

int trigPin = 12; //Pin TRIG conectado a D12
int echoPin = 13; //Pin ECHO conectado a D13
int distance, distance_l, distance_r;

char BLE_val;

void setup() {
  Serial.begin(9600);//Establecer la tasa de baudios a 9600
  pinMode(left_ctrl,OUTPUT);//configurar los pines de control de dirección del motor del grupo B como OUTPUT
  pinMode(left_pwm,OUTPUT);//configurar los pines de control PWM del motor del grupo B como OUTPUT
  pinMode(right_ctrl,OUTPUT);//configurar los pines de control de dirección del motor del grupo A como OUTPUT
  pinMode(right_pwm,OUTPUT);//configurar los pines de control PWM del motor del grupo A como OUTPUT
  servopulse(servopin,90);//el ángulo del servo es de 90 grados
  delay(300);
  pinMode(L_pin, INPUT); //Los pines del sensor de seguimiento se configuran en modo entrada
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(trigPin, OUTPUT); //definir TRIG como modo de salida
  pinMode(echoPin, INPUT); //definir ECHO como modo de entrada
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
    
      case  'U':  follow();  //Recibiendo ‘U’, entrar en modo seguimiento
      break; 
      case  'Y':  avoid(); //Recibiendo ‘Y’, entrar en modo evitación de obstáculos  
      break;  
      case  'G':  confinement(); //Recibiendo ‘G’, entrar en modo confinamiento
      break;  
      case  'X':  tracking(); //Recibiendo ‘X’, entrar en modo seguimiento
      break;  
    }
}

void car_front()//definir el estado de avanzar
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//definir el estado de retroceder
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//establecer el estado de giro a la izquierda
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//establecer el estado de giro a la derecha
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//definir el estado de parada
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //función de aumento rápido
  while (1) {
    Serial.println(speeds);  //mostrar información de velocidad 
    if (speeds < 255) { //Hasta 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //ajustar la velocidad de crecimiento 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Recibir 'S', el coche deja de acelerar
    break;
  }
}
void speeds_d() { //función de reducción de velocidad
  while (1) {
    Serial.println(speeds);  //mostrar información de velocidad
    if (speeds > 0) { //hasta 0
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //ajustar la velocidad de desaceleración
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Recibir 'S', el coche deja de desacelerar
    break;
}
}

int get_distance() {
  int distance = 0;
  digitalWrite(trigPin, LOW);     // enviar pulso a través de Trig/Pin, activar el rango HC-SR04, para que la interfaz de señal ultrasónica envíe nivel bajo durante 2μs
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);    // hacer que la interfaz de señal ultrasónica esté en nivel alto durante 10μs, aquí es al menos 10μs
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);     // mantener la interfaz de señal ultrasónica en nivel bajo
  distance = pulseIn(echoPin, HIGH) / 58; // leer el tiempo del pulso y convertir el tiempo del pulso a distancia (unidad: cm)
  Serial.println(distance);        // imprimir valor de distancia
  return distance;
}

void follow() {
  servopulse(servopin,90);
  delay(200);
  int follow_flag = 1;
  while (follow_flag) {
    distance = get_distance(); // llamar a la función de medición de distancia
    if (distance < 8 ) {// Si la distancia es menor que 8
      car_back();// el coche retrocede
      matrix_display(clear);
      matrix_display(back); 
    }
    else if (distance >= 8 && distance < 13) { // Si la distancia es mayor o igual a 8 y menor que 13
      car_Stop();// detener
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    else if (distance >= 13 && distance <= 35 ) { // Si la distancia es mayor o igual a 13 y menor o igual a 35
      car_front();// el coche avanza
      matrix_display(clear);
      matrix_display(front);
    }
    else {// Si no se cumple ninguna de las anteriores
      car_Stop();// detener
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // Cuando se recibe 'S', el coche se detiene
      follow_flag = 0;
      car_Stop();
    }
  }
}

void avoid() {
  int avoid_flag = 1;
  while (avoid_flag) {
    distance = get_distance(); // Llamar a la función de medición de distancia
    if (distance > 0 && distance < 20) { // Si la distancia es menor que 20 y mayor que 0
      car_Stop();// detener
      matrix_display(clear);
      matrix_display(STOP01);   // la matriz de puntos muestra un patrón de parada
      delay(1000);
      servopulse(servopin,160); // mover el servo más allá de 180 grados
      delay(500);
      distance_l = get_distance(); // obtener la distancia izquierda
      delay(100);
      servopulse(servopin,20); // girar el servo a 0 grados
      delay(500);
      distance_r = get_distance(); // obtener la distancia derecha
      delay(100);
      if (distance_l > distance_r) { // comparar distancias, si la izquierda es mayor que la derecha
        car_left();  // el coche gira a la izquierda
        matrix_display(clear);
        matrix_display(left);   // la matriz de puntos muestra un patrón a la izquierda
        servopulse(servopin,90);// el servo vuelve a 90 grados
        delay(700);
        matrix_display(clear);
        matrix_display(front);   // la matriz de puntos muestra un patrón hacia adelante
      } 
      else { // De lo contrario, si la derecha es mayor que la izquierda
        car_right();// el coche gira a la derecha
        matrix_display(clear);
        matrix_display(right);   // la matriz de puntos muestra un patrón a la derecha
        servopulse(servopin,90);// el servo vuelve a 90 grados
        delay(700);
        matrix_display(clear);
        matrix_display(front);   // la matriz de puntos muestra un patrón hacia adelante
      }
    }
    else { // Cuando la distancia frontal es mayor o igual a 20 cm
      car_front();// el coche avanza
      matrix_display(clear);
      matrix_display(front);   // la matriz de puntos muestra un patrón hacia adelante

    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') {// Cuando se recibe 'S', el coche se detiene
      avoid_flag = 0;
      car_Stop();
    }
  }
}

void confinement() {
  int confinement_flag = 1;
  while (confinement_flag) {
    L_val = digitalRead(L_pin); //leer el valor del sensor izquierdo
    M_val = digitalRead(M_pin); //leer el valor del sensor del medio
    R_val = digitalRead(R_pin); //leer el valor del sensor derecho
    if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //el coche avanza cuando no se detecta línea negra
      car_front();
    }
    else { //De lo contrario, si alguno de los sensores de seguimiento detecta una línea negra, el coche retrocede y luego gira a la izquierda
      car_back();
      delay(500);
      car_left();
      delay(800);
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { //Cuando se recibe S, el coche se detiene
      confinement_flag = 0;
      car_Stop();
    }
  }
}

void tracking() {
  int track_flag = 1;
  while (track_flag) {
    L_val = digitalRead(L_pin); //leer el valor del sensor izquierdo
    M_val = digitalRead(M_pin); //leer el valor del sensor del medio
    R_val = digitalRead(R_pin); //leer el valor del sensor derecho
    if (M_val == 1) { //Línea negra detectada en el medio
      if (L_val == 1 && R_val == 0) { //Si se detecta línea negra a la izquierda, pero no a la derecha, girar a la izquierda
        car_left();
      }
      else if (L_val == 0 && R_val == 1) { //De lo contrario, si se detecta línea negra a la derecha y no a la izquierda, girar a la derecha
        car_right();
      }
      else { //De lo contrario, el coche avanza
        car_front();
      }
    }
    else { //no se detectan líneas negras en el medio
      if (L_val == 1 && R_val == 0) { //Si se detecta línea negra a la izquierda, pero no a la derecha, girar a la derecha
        car_right();
      }
      else if (L_val == 0 && R_val == 1) { //De lo contrario, si se detecta línea negra a la derecha y no a la izquierda, girar a la derecha
        car_right();;
      }
      else { //De lo contrario, detenerse
        car_Stop();
      }
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { //Cuando se recibe S, el coche se detiene
      track_flag = 0;
      car_Stop();
    }
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

### **5. Resultado de la prueba**

Después de cargar con éxito el código en la placa V4.0, conecte los cables según el diagrama de conexiones, encienda la alimentación externa y luego ponga el interruptor DIP en ON.

Después de que el módulo Bluetooth esté conectado a la APP y la APP móvil se conecte correctamente al Bluetooth, el coche inteligente puede ser controlado por la APP móvil. Podemos lograr las funciones correspondientes presionando los botones correspondientes en la APP móvil.