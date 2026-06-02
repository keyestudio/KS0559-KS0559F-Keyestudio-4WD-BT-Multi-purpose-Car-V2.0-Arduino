# Proyecto 4 Control de Servo

### **1.Descripción**

![image-20250509084654137](media/A25.png)

El motor servo es un actuador rotativo de control de posición. Principalmente consta de una carcasa, una placa de circuito, un motor sin núcleo, un engranaje y un sensor de posición. Su principio de funcionamiento es que el servo recibe la señal enviada por MCUs o receptores y produce una señal de referencia con un período de 20 ms y un ancho de 1.5 ms, luego compara el voltaje de polarización continua adquirido con el voltaje del potenciómetro y obtiene la salida de diferencia de voltaje.

![image-20250509084710719](media/A26.png)

En general, el servo tiene tres cables en marrón, rojo y naranja. El cable marrón está conectado a tierra, el rojo es la línea de polo positivo y el naranja es la línea de señal.

El ángulo de rotación del motor servo se controla regulando el ciclo de trabajo de la señal PWM (Modulación por Ancho de Pulso). El ciclo estándar de la señal PWM es de 20 ms (50 Hz). Teóricamente, el ancho se distribuye entre 1 ms y 2 ms, pero en la práctica, está entre 0.5 ms y 2.5 ms. El ancho corresponde al ángulo de rotación de 0° a 180°. Pero tenga en cuenta que para motores de diferentes marcas, la misma señal puede tener diferentes ángulos de rotación.

![image-20250509084727797](media/A27.png)

Los ángulos correspondientes del servo se muestran a continuación:

![image-20250509084739380](media/A28.png)

### **2.Especificaciones**

- Voltaje de trabajo: DC 4.8V \~ 6V

- Rango de ángulo operativo: aproximadamente 180 ° (en 500 → 2500 μsec)

- Rango de ancho de pulso: 500 → 2500 μsec

- Velocidad sin carga: 0.12 ± 0.01 seg / 60 (DC 4.8V) 0.1 ± 0.01 seg / 60 (DC 6V)

- Corriente sin carga: 200 ± 20mA (DC 4.8V) 220 ± 20mA (DC 6V)

- Torque de parada: 1.3 ± 0.01kg · cm (DC 4.8V) 1.5 ± 0.1kg · cm (DC6V)

- Corriente de parada: ≦ 850mA (DC 4.8V) ≦ 1000mA (DC 6V)

- Corriente en espera: 3 ± 1mA (DC 4.8V) 4 ± 1mA (DC 6V)

### **3.Componentes**

|                     Placa de Desarrollo *1                     |           Driver de Motor 8833 *1           |                           Servo*1                            |
| :------------------------------------------------------------: | :------------------------------------------: | :----------------------------------------------------------: |
|           ![img](media/A8.jpg)           | ![img](media/A9.jpg) | ![image-20250509084654137](media/A25.png) |
|                    Portabaterías 18650*1                      |               Cable USB*1                     |               Batería 18650*2 (proporcionada por el usuario)               |
| ![image-20250509084950601](media/A29.png) |         ![img](media/A12.jpg)         | ![image-20250509085010348](media/A30.png) |

### **4.Diagrama de Conexiones**

![image-20250509085038006](media/A31.png)

Nota de conexión: El servo está conectado a G (GND), V (VCC) y A3, el cable marrón del servo está conectado a Gnd (G), el rojo está conectado a 5V (V) y el naranja está conectado a A3.

El servo debe conectarse a una fuente de alimentación externa debido a su alta demanda de corriente para conducir el servo. Generalmente, la corriente de la placa de desarrollo no es suficiente. Si no se conecta la alimentación externa, la placa de desarrollo podría quemarse.

### **5.Código de Prueba**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 4.1
Servo
http://www.keyestudio.com
*/
#define servoPin A3  //Pin del servo
int pos; //variable del ángulo del servo
int pulsewidth; //variable del ancho de pulso del servo

void setup() {
  pinMode(servoPin, OUTPUT);  //configura los pines del servo como salida
  procedure(0); //configura el ángulo del servo a 0 grados
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // va de 0 grados a 180 grados
    // en pasos de 1 grado
    procedure(pos);              // indica al servo que vaya a la posición en la variable 'pos'
    delay(15);                   // controla la velocidad de rotación del servo
  }
  for (pos = 180; pos >= 0; pos -= 1) { // va de 180 grados a 0 grados
    procedure(pos);              // indica al servo que vaya a la posición en la variable 'pos'
    delay(15);                    
  }
}

//función para controlar el servo
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  //calcula el valor del ancho del pulso
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);   //La duración del nivel alto es el ancho del pulso
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));  //el ciclo es de 20ms, el nivel bajo dura el resto del tiempo
}
//****************************************************************************
```

### **6.Resultado de la Prueba**

Después de subir con éxito el código a la placa V4.0, conecta los cables según el diagrama de conexiones y enciende la alimentación externa. Tras encender, gira el interruptor DIP al extremo "ON", entonces el servo oscilará en el rango de 0° a 180°.

### **7.Práctica de Extensión**

Además, podemos controlar el servo mediante un archivo de biblioteca. Por favor, consulta el enlace: [https://www.arduino.cc/en/Reference/Servo](https://www.arduino.cc/en/Reference/Servo).

![image-20250509085122183](media/A32.png)

```c
//***************************************************************************
/*
 keyestudio 4wd BT Car
 lección 4.2
 Servo
 http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo;  // crea un objeto servo para controlar un servo
// se pueden crear doce objetos servo en la mayoría de las placas
int pos = 0;    // variable para almacenar la posición del servo

void setup() {
  myservo.attach(A3);  // conecta el servo en el pin A3 al objeto servo
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // va de 0 grados a 180 grados
    // en pasos de 1 grado
    myservo.write(pos);              // indica al servo que vaya a la posición en la variable 'pos'
    delay(15);                       // espera 15ms para que el servo alcance la posición
  }
  for (pos = 180; pos >= 0; pos -= 1) { // va de 180 grados a 0 grados
    myservo.write(pos);              // indica al servo que vaya a la posición en la variable 'pos'
    delay(15);                       // espera 15ms para que el servo alcance la posición
  }
}
//***************************************************************************
```

Después de subir con éxito el código a la placa V4.0, conecta los cables según el diagrama de conexiones y enciende la alimentación externa. Tras encender, gira el interruptor DIP al extremo "ON", entonces el servo también oscilará en el rango de 0° a 180°. Normalmente lo controlamos mediante archivo de biblioteca.

### **8.Explicación del Código**

Arduino incluye **\#include \<Servo.h\>** (función y declaraciones del servo)

A continuación, algunas declaraciones comunes de la función servo:

1). **attach（interface）**——Configura la interfaz del servo

2). **write（angle）**——Se usa para establecer el ángulo de rotación del servo, y el rango de ángulo establecido es de 0° a 180°

3). **read（）**——se usa para leer el ángulo del servo, es decir, leer el valor del comando de “write()”

4). **attached（）**——Determina si el parámetro del servo está asignado a su interfaz

<span style="color: rgb(255, 76, 65);">Nota:</span> El formato escrito anterior es “nombre de variable servo, declaración específica（）”, por ejemplo: myservo.attach(9).