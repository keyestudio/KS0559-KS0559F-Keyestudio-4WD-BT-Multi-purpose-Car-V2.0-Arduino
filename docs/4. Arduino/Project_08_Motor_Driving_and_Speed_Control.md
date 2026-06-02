# Proyecto 8 Conducción y Control de Velocidad del Motor

![image-20250510090044895](media/A77.png)

### **1.Descripción**

Existen muchas formas de conducir motores. Nuestro coche utiliza el chip controlador de motor DRV8833 más comúnmente usado, que proporciona una solución de conducción eléctrica de puente de dos canales para juguetes, impresoras y otras aplicaciones integradas de motores.

Cuando apilamos el Shield sobre la placa de desarrollo 4.0 y encendemos la BAT, luego configuramos el interruptor DIP en el extremo ON, la fuente de alimentación externa alimentará ambas placas al mismo tiempo. Para facilitar las conexiones de cableado, el Shield viene con un puerto anti-inversión (PH2.0-2P-3P-4P-5P). Puedes conectar los motores, la fuente de alimentación y los módulos sensores directamente al Shield.

La interfaz Bluetooth del Shield es totalmente compatible con el módulo Bluetooth DX-BT24 5.1. Al conectar el módulo Bluetooth, solo necesitas enchufarlo en la interfaz correspondiente. Al mismo tiempo, se utilizan pines en fila de 2.54 para sacar algunos puertos digitales y analógicos no usados en el Shield, haciéndolo accesible para que añadas otros sensores y realices experimentos de extensión.

La placa de expansión puede conectarse a cuatro motores DC. Cuando el puente jumper está conectado por defecto, los motores de los puertos A y A1 y B y B1 están conectados en paralelo y tienen la misma ley de movimiento. Se pueden usar 8 puentes jumper para controlar la dirección de rotación de las 4 interfaces de motor.

Por ejemplo, cuando los 2 puentes jumper delante de B1 del motor M1 cambian de conexión transversal a conexión longitudinal, la dirección de rotación del motor M1 será opuesta a la dirección original.

### **2.Especificaciones**

- Voltaje de entrada para lógica: DC 5V

- Voltaje de entrada para conducción: DC 6-9 V

- Corriente de trabajo para lógica: \<36mA

- Corriente de trabajo para conducción: \<2A

- Disipación máxima de potencia: 25W（T=75℃）

- Nivel de entrada para señal de control: nivel alto es 2.3V\<Vin\<5V, nivel bajo es -0.3V\<Vin\<1.5V

- Temperatura de trabajo: -25＋130℃

**Placa de expansión controladora de motor Keyestudio 8833**

![image-20250510090404192](media/A78.png)

### **3.Principio de Funcionamiento**

Usamos el modo de conexión paralela del mismo lado para los cuatro motores, que pueden considerarse dos grupos de motores. Como se muestra en el diagrama de cableado, B y B1 son un grupo, y A y A1 son otro grupo.

Los motores en el mismo grupo deben girar en la misma dirección. Si son diferentes, ajusta los puentes jumper correspondientes junto al terminal para cambiar la dirección.

Como se muestra a continuación, si las direcciones de A y A1 son diferentes, ajusta la dirección de los puentes jumper hasta que la dirección de movimiento de los motores del mismo grupo sea consistente.

![image-20250510090532851](media/A79.png)

Del diagrama anterior, se sabe que el pin de dirección del motor A es D4, el pin de velocidad es D6; D2 es el pin de dirección del motor B; y D6 es el pin de velocidad.

<span style="color:red;">PWM conduce el coche robot. El valor PWM está en el rango de 0-255. Cuando configuramos la dirección en HIGH, cuanto menor sea el número PWM, más rápido girará el motor.</span>

|            | D2   | D5（PWM） | Motor B（izquierdo） | D4   | D6（PWM） | Motor A（derecho）   |
| ---------- | ---- | --------- | -------------------- | ---- | --------- | -------------------- |
| Avanzar    | HIGH | 255-200   | Gira en sentido horario | HIGH | 255-200   | Gira en sentido horario |
| Retroceder | LOW  | 200       | Gira en sentido antihorario | LOW  | 200       | Gira en sentido antihorario |
| Girar izquierda | HIGH | 255-200   | Gira en sentido horario | LOW  | 200       | Gira en sentido antihorario |
| Girar derecha | LOW  | 200       | Gira en sentido antihorario | HIGH | 255-200   | Gira en sentido horario |

### **4.Componentes**

| Placa de Desarrollo *1      | Driver de Motor 8833 *1      | Cable USB*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A80.jpg) | ![img](media/A81.jpg) | ![img](media/A82.jpg)         |
| Soporte para Batería 18650*1    | Motor*4                   | Batería 18650 *2（auto-proporcionada） |
| ![img](media/A83.png) | ![img](media/A84.jpg) | ![img](media/A85.png)         |

### **5.Diagrama de Conexiones**

![image-20250510090733191](media/A86.png)

Conecte la fuente de alimentación al puerto BAT.

### **6.Código de Prueba**

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.1
 Motor driver shield
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //define los pines de control de dirección del motor grupo B
#define ML_PWM 5   //define los pines PWM de control del motor grupo B
#define MR_Ctrl 4    //define los pines de control de dirección del motor grupo A
#define MR_PWM 6   //define los pines PWM de control del motor grupo A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//configura los pines de control de dirección del motor grupo B como salida
  pinMode(ML_PWM, OUTPUT);//configura los pines PWM de control del motor grupo B como salida
  pinMode(MR_Ctrl, OUTPUT);//configura los pines de control de dirección del motor grupo A como salida
  pinMode(MR_PWM, OUTPUT);//configura los pines PWM de control del motor grupo A como salida
}
void loop()
{ 
  //adelante
  digitalWrite(ML_Ctrl,HIGH);//configura los pines de control de dirección del motor grupo B a HIGH
  analogWrite(ML_PWM,55);//configura la velocidad PWM del motor grupo B a 55
  digitalWrite(MR_Ctrl,HIGH);//configura los pines de control de dirección del motor grupo A a HIGH
  analogWrite(MR_PWM,55);// configura la velocidad PWM del motor grupo A a 55
  delay(2000);//retardo de 2000ms
  //atrás
  digitalWrite(ML_Ctrl,LOW);//configura los pines de control de dirección del motor grupo B a nivel LOW
  analogWrite(ML_PWM,200);// configura la velocidad PWM del motor grupo B a 200 
  digitalWrite(MR_Ctrl,LOW);//configura los pines de control de dirección del motor grupo A a nivel LOW
  analogWrite(MR_PWM,200);//configura la velocidad PWM del motor grupo A a 200
  delay(2000);//retardo de 2000ms
  //izquierda
  digitalWrite(ML_Ctrl,LOW);//configura los pines de control de dirección del motor grupo B a nivel LOW
  analogWrite(ML_PWM,200);//configura la velocidad PWM del motor grupo B a 200 
  digitalWrite(MR_Ctrl,HIGH);//configura los pines de control de dirección del motor grupo A a nivel HIGH
  analogWrite(MR_PWM,55);//configura la velocidad PWM del motor grupo A a 55
  delay(2000);//retardo de 2000ms
  //derecha
  digitalWrite(ML_Ctrl,HIGH);//configura los pines de control de dirección del motor grupo B a nivel HIGH
  analogWrite(ML_PWM,55);//configura la velocidad PWM del motor grupo B a 55 
  digitalWrite(MR_Ctrl,LOW);// configura los pines de control de dirección del motor grupo A a nivel LOW
  analogWrite(MR_PWM,200);//configura la velocidad PWM del motor grupo A a 200
  delay(2000);//retardo de 2000ms
  //parar
  digitalWrite(ML_Ctrl, LOW);// configura los pines de control de dirección del motor grupo B a nivel LOW
  analogWrite(ML_PWM,0);//configura la velocidad PWM del motor grupo B a 0
  digitalWrite(MR_Ctrl, LOW);// configura los pines de control de dirección del motor grupo A a nivel LOW
  analogWrite(MR_PWM,0);//configura la velocidad PWM del motor grupo A a 0
  delay(2000);// retardo de 2000ms
}
//****************************************************************************
```

### **7.Resultado de la Prueba**

Después de subir el código exitosamente a la placa V4.0, conecte los cables según el diagrama de conexiones, luego encienda la fuente de alimentación externa y ponga el interruptor DIP en ON, el coche avanzará durante 2s, retrocederá durante 2s, girará a la izquierda durante 2s, a la derecha durante 2s y se detendrá durante 2s.

### **8.Explicación del Código**

**digitalWrite(ML\_Ctrl,LOW):** La dirección de rotación del motor se decide por el nivel alto/bajo y los pines que deciden la dirección de rotación son pines digitales.

**analogWrite(ML\_PWM,200):** La velocidad del motor se regula mediante PWM, y los pines que deciden la velocidad del motor deben ser pines PWM.

### **9.Explicación del Código**

Ajusta la velocidad con la que el PWM controla el motor, conecta de la misma manera.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.2
 Motor driver
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //define los pines de control de dirección del motor del grupo B
#define ML_PWM 5   //define los pines de control PWM del motor del grupo B
#define MR_Ctrl 4    //define los pines de control de dirección del motor del grupo A
#define MR_PWM 6   //define los pines de control PWM del motor del grupo A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//configura los pines de control de dirección del motor del grupo B como salida
  pinMode(ML_PWM, OUTPUT);//configura los pines de control PWM del motor del grupo B como salida
  pinMode(MR_Ctrl, OUTPUT);//configura los pines de control de dirección del motor del grupo A como salida
  pinMode(MR_PWM, OUTPUT);//configura los pines de control PWM del motor del grupo A como salida
}
void loop()
{ 
  //adelante
  digitalWrite(ML_Ctrl,HIGH);//configura los pines de control de dirección del motor del grupo B a HIGH
  analogWrite(ML_PWM,105);//configura la velocidad de control PWM del motor del grupo B a 55
  digitalWrite(MR_Ctrl,HIGH);//configura los pines de control de dirección del motor del grupo A a HIGH
  analogWrite(MR_PWM,105);// configura la velocidad de control PWM del motor del grupo A a 55
  delay(2000);//retardo de 2000ms
  //atrás
  digitalWrite(ML_Ctrl,LOW);//configura los pines de control de dirección del motor del grupo B a nivel LOW
  analogWrite(ML_PWM,150);// configura la velocidad de control PWM del motor del grupo B a 200 
  digitalWrite(MR_Ctrl,LOW);//configura los pines de control de dirección del motor del grupo A a nivel LOW
  analogWrite(MR_PWM,150);//configura la velocidad de control PWM del motor del grupo A a 200
  delay(2000);//retardo de 2000ms
  //izquierda
  digitalWrite(ML_Ctrl,LOW);//configura los pines de control de dirección del motor del grupo B a nivel LOW
  analogWrite(ML_PWM,150);//configura la velocidad de control PWM del motor del grupo B a 200 
  digitalWrite(MR_Ctrl,HIGH);//configura los pines de control de dirección del motor del grupo A a nivel HIGH
  analogWrite(MR_PWM,105);//configura la velocidad de control PWM del motor del grupo A a 200
  delay(2000);//retardo de 2000ms
  //derecha
  digitalWrite(ML_Ctrl,HIGH);//configura los pines de control de dirección del motor del grupo B a nivel HIGH
  analogWrite(ML_PWM,105);//configura la velocidad de control PWM del motor del grupo B a 55 
  digitalWrite(MR_Ctrl,LOW);// configura los pines de control de dirección del motor del grupo A a nivel LOW
  analogWrite(MR_PWM,150);//configura la velocidad de control PWM del motor del grupo A a 200
  delay(2000);//retardo de 2000ms
  //parar
  digitalWrite(ML_Ctrl, LOW);// configura los pines de control de dirección del motor del grupo B a nivel LOW
  analogWrite(ML_PWM,0);//configura la velocidad de control PWM del motor del grupo B a 0
  digitalWrite(MR_Ctrl, LOW);// configura los pines de control de dirección del motor del grupo A a nivel LOW
  analogWrite(MR_PWM,0);//configura la velocidad de control PWM del motor del grupo A a 0
  delay(2000);// retardo de 2000ms
}
//************************************************************************
```

Después de subir con éxito el código a la placa V4.0, conecta los cables según el diagrama de conexiones, luego enciende la alimentación externa y gira el interruptor DIP a ON, entonces notarás que la velocidad del motor es mucho más lenta.

<span style="color: rgb(255, 76, 65);">Nota: Una batería baja provocará una velocidad lenta del motor.</span> 