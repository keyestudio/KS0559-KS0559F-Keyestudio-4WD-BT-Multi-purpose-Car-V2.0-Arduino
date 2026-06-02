# Proyecto 5 Sensor Ultrasónico

### **1.Descripción**

![image-20250509085643931](media/A33.png)

El sensor ultrasónico HC-SR04 utiliza sonar para determinar la distancia a un objeto, como lo hacen los murciélagos. Ofrece una excelente detección de rango sin contacto con alta precisión y lecturas estables en un paquete fácil de usar. Viene completo con módulos transmisor y receptor ultrasónicos.

![Img](media/A34.png)

El HC-SR04 o sensor ultrasónico se utiliza en una amplia gama de proyectos electrónicos para crear aplicaciones de detección de obstáculos y medición de distancia, así como diversas otras aplicaciones. Aquí hemos presentado el método simple para medir la distancia con Arduino y un sensor ultrasónico y cómo usar el sensor ultrasónico con Arduino.

### **2.Especificaciones**

- Voltaje de trabajo: +5V DC

- Corriente en reposo: \<2mA

- Corriente de trabajo: 15mA

- Ángulo efectivo: \<15°

- Rango de distancia: 2cm – 300 cm

- Precisión: 0.3 cm

- Ángulo de medición: 30 grados

- Ancho de pulso de entrada Trigger: 10uS

![image-20250509085705309](media/A35.png)

### **3.Componentes**

| Placa de desarrollo *1                                      | Driver de motor 8833 *1                  | Módulo LED rojo*1        | Sensor ultrasónico*1                                         |
| ------------------------------------------------------------ | ---------------------------------------- | ------------------------ | ------------------------------------------------------------ |
| ![img](media/A8.jpg)                     | ![img](media/A9.jpg) | ![img](media/A10.jpg) | ![image-20250509085643931](media/A33.png) |
| Cable Dupont 4P*1                                           | Cable USB*1                             | Cable Dupont 3P*1        |                                                              |
| ![image-20250509143737972](media/A36.png) | ![img](media/A12.jpg)                 | ![img](media/A11.jpg) |                                                              |

### **4.Principio de funcionamiento**

Como muestra la imagen anterior, es como dos ojos. Uno es el extremo transmisor, el otro es el extremo receptor.

El módulo ultrasónico emitirá ondas ultrasónicas después de recibir una señal de disparo. Cuando las ondas ultrasónicas encuentran un objeto y se reflejan, el módulo emite una señal de eco, por lo que puede determinar la distancia del objeto a partir de la diferencia de tiempo entre la señal de disparo y la señal de eco.

t es el tiempo que tarda la señal emitida en encontrar el obstáculo y regresar. La velocidad de propagación del sonido en el aire es aproximadamente 343 m/s, y distancia = velocidad \* tiempo. Sin embargo, la onda ultrasónica se emite y regresa, lo que equivale a 2 veces la distancia. Por lo tanto, debe dividirse por 2, la distancia medida por la onda ultrasónica = (velocidad \* tiempo)/2.

**Método de uso y gráfico del módulo ultrasónico:**

1. Use el pin GPIO para dar una señal de nivel alto de al menos 10μs al pin Trig del SR04, lo que puede activarlo para detectar la distancia.
2. Después de activar, el módulo enviará automáticamente ocho pulsos ultrasónicos de 40KHz y detectará si hay una señal de retorno. Este paso se completará automáticamente por el módulo.
3. Si la señal regresa, el pin Echo emitirá un nivel alto, y la duración del nivel alto es el tiempo desde la transmisión de la onda ultrasónica hasta su retorno.

![image-20250509143833078](media/A37.png)

**Diagrama del circuito del sensor ultrasónico:**

![image-20250509154035287](media/A38.png)

### **5.Diagrama de conexiones**

![image-20250509154107103](media/A39.png)

VCC, Trig, Echo y Gnd del sensor ultrasónico están conectados a 5V(V), D12, D13 y Gnd(G)

### **6.Código de prueba**

```c
//***************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 5.1
 Ultrasonic Sensor
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches;
void setup() {
  //Iniciar puerto serial
  Serial.begin (9600);
  //Definir entradas y salidas
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  // El sensor se activa con un pulso HIGH de 10 o más microsegundos.
  // Da un pulso LOW corto antes para asegurar un pulso HIGH limpio:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   // Lee la señal del sensor: un pulso HIGH cuya
  // duración es el tiempo (en microsegundos) desde el envío
  // del ping hasta la recepción de su eco reflejado por un objeto.
  duration = pulseIn(echoPin, HIGH);
   // Convierte el tiempo en una distancia
  cm = (duration/2) / 29.1;     // Divide por 29.1 o multiplica por 0.0343
  inches = (duration/2) / 74;   // Divide por 74 o multiplica por 0.0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
}
//***************************************************************************
```

### **7.Resultado de la Prueba**

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, abre el monitor serial y configura la velocidad en baudios a 9600.

Se mostrará la distancia detectada, y la unidad es cm y pulgadas. Obstaculiza el sensor ultrasónico con la mano, el valor de distancia mostrado se hará más pequeño.

![image-20250509154147537](media/A40.png)

### **8.Explicación del Código**

**int trigPin-** este pin está definido para transmitir ondas ultrasónicas, generalmente salida.

**int echoPin -** este está definido como el pin de recepción, generalmente entrada.

**cm = (duration/2) / 29.1-**

**inches = (duration/2) / 74-**

Podemos calcular la distancia usando la siguiente fórmula:

distancia = (tiempo de viaje/2) x velocidad del sonido

La velocidad del sonido es: 343m/s = 0.0343 cm/us = 1/29.1 cm/us

O en pulgadas: 13503.9in/s = 0.0135in/us = 1/74in/us

Necesitamos dividir el tiempo de viaje por 2 porque debemos tener en cuenta que la onda fue enviada, golpeó el objeto y luego regresó al sensor.

### **9.Práctica de Extensión**

Acabamos de medir la distancia mostrada por el ultrasónico. ¿Qué tal controlar el LED con la distancia medida? Probémoslo y conecta un módulo de luz LED al pin D9.

![image-20250509154232505](media/A41.png)

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lesson 5.2
 Ultrasonic LED
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches;

void setup() {
  Serial.begin (9600);  //Inicio del puerto serial
  pinMode(trigPin, OUTPUT);  //Define entradas y salidas
  pinMode(echoPin, INPUT);
}

void loop() 
{
  // El sensor se activa con un pulso HIGH de 10 o más microsegundos.
  // Da un pulso LOW corto antes para asegurar un pulso HIGH limpio:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Lee la señal del sensor: un pulso HIGH cuya
  // duración es el tiempo (en microsegundos) desde el envío
  // del ping hasta la recepción de su eco reflejado por un objeto.
  duration = pulseIn(echoPin, HIGH);
  // Convierte el tiempo en una distancia
  cm = (duration/2) / 29.1;     // Divide por 29.1 o multiplica por 0.0343
  inches = (duration/2) / 74;   // Divide por 74 o multiplica por 0.0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
  if (cm>=2 && cm<=10)
  {
    Serial.println("HIGH");
    digitalWrite(9, HIGH);
  }
  else
  {
    Serial.println("LOW");
    digitalWrite(9, LOW);
  }
}
//*****************************************************************
```

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, bloquea el sensor ultrasónico con la mano (la distancia está entre 2-10cm), luego verifica si el LED está encendido.