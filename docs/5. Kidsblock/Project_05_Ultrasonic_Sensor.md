# Proyecto 5 Sensor Ultrasónico

### **1.Descripción**

![](media/A109.png)

El sensor ultrasónico HC-SR04 utiliza sonar para determinar la distancia a un objeto, similar a lo que hacen los murciélagos. Ofrece una excelente detección de rango sin contacto con alta precisión y lecturas estables en un paquete fácil de usar. Viene completo con módulos transmisor y receptor ultrasónicos.

![Img](media/A110.png)

El HC-SR04 o sensor ultrasónico se utiliza en una amplia gama de proyectos electrónicos para crear aplicaciones de detección de obstáculos y medición de distancia, así como diversas otras aplicaciones. Aquí presentamos el método simple para medir la distancia con Arduino y un sensor ultrasónico y cómo usar el sensor ultrasónico con Arduino.

### **2.Especificaciones**

- Voltaje de trabajo: +5V DC

- Corriente en reposo: \<2mA

- Corriente de trabajo: 15mA

- Ángulo efectivo: \<15°

- Rango de distancia: 2cm – 300 cm

- Precisión: 0.3 cm

- Ángulo de medición: 30 grados

- Ancho del pulso de entrada Trigger: 10uS

![](media/A111.png)

### **3.Componentes**

| Placa de desarrollo *1    | Driver de motor 8833 *1    | Módulo LED rojo *1        | Sensor ultrasónico *1     |
| ------------------------- | ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A112.jpg)    | ![img](media/A113.jpg)    | ![img](media/A114.jpg)    | ![img](media/A115.jpg)    |
| Cable Dupont 4P *1        | Cable USB *1              | Cable Dupont 3P *1        |                           |
| ![img](media/A116.jpg)    | ![img](media/A117.jpg)    | ![img](media/A118.jpg)    |                           |

### **4.Principio de funcionamiento**

Como muestra la imagen superior, es como dos ojos. Uno es el extremo transmisor, el otro es el extremo receptor.

El módulo ultrasónico emitirá ondas ultrasónicas después de recibir una señal de activación. Cuando las ondas ultrasónicas encuentran un objeto y se reflejan, el módulo emite una señal de eco, por lo que puede determinar la distancia del objeto a partir de la diferencia de tiempo entre la señal de activación y la señal de eco.

t es el tiempo que tarda la señal emitida en encontrar el obstáculo y regresar. La velocidad de propagación del sonido en el aire es aproximadamente 343 m/s, y distancia = velocidad \* tiempo. Sin embargo, la onda ultrasónica se emite y regresa, lo que es 2 veces la distancia. Por lo tanto, debe dividirse por 2, la distancia medida por la onda ultrasónica = (velocidad \* tiempo)/2.

**Método de uso y gráfico del módulo ultrasónico:**

1).Usar el pin GPIO para dar una señal de nivel alto de al menos 10μs al pin Trig del SR04, lo que puede activarlo para detectar distancia.

2).Después de activar, el módulo enviará automáticamente ocho pulsos ultrasónicos de 40KHz y detectará si hay una señal de retorno. Este paso se completará automáticamente por el módulo.

3).Si la señal regresa, el pin Echo emitirá un nivel alto, y la duración del nivel alto es el tiempo desde la transmisión de la onda ultrasónica hasta el retorno.

![image-20250509143833078](media/A119.png)


**Diagrama del circuito del sensor ultrasónico:**

![](media/A120.jpeg)

### **5.Diagrama de conexión**

![](media/A121.png)

VCC, Trig, Echo y Gnd del sensor ultrasónico están conectados a 5V(V), D12, D13 y Gnd(G)

### **6.Código de prueba**

Antes de escribir el código, es necesario importar el archivo de la biblioteca del sensor ultrasónico. Los pasos específicos son los siguientes: 

Haga clic en ![](media/A29.png) para entrar en la interfaz de biblioteca de extensiones de sensores/módulos/componentes, luego busque el sensor "**Ultrasonic**" ![](media/A122.png) y haga clic en él. De esta manera, "**Not loaded**" cambia a "**loaded**", indicando que el sensor "**Ultrasonic**" fue agregado con éxito. 

![Img](media/A123.png)

![](media/A124.png)

Haga clic en ![](media/A33.png) para volver a la interfaz del editor de código, se puede ver el bloque de instrucciones del sensor "**Ultrasonic**" agregado en el área de módulos. 

![](media/A125.png)

Puede arrastrar bloques para editar. Los bloques listados a continuación son para su referencia.

(1).![](media/A126.png)

(2).![](media/A127.png)

(3).![](media/A128.png)

(4).![](media/A129.png)

(5).![](media/A130.png)

(6).![](media/A131.png)

(7).![](media/A132.png)

**Código de prueba completo**

![](media/A133.png)

### **7. Resultado de la prueba**

Después de cargar el código con éxito en la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, haz clic en ![](media/A80.png) para configurar la velocidad en baudios a 9600.

La distancia detectada se mostrará, y la unidad es cm y pulgadas. Obstaculiza el sensor ultrasónico con la mano, el valor de la distancia mostrada se hará más pequeño.

![](media/A134.png)

### **8. Práctica de extensión**

Acabamos de medir la distancia mostrada por el ultrasónico. ¿Qué tal controlar el LED con la distancia medida? Vamos a intentarlo y conectar un módulo de luz LED al pin D9.

![](media/A135.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A136.png)

(3).![](media/A128.png)

(4).![](media/A137.png)

(5).![](media/A130.png)

(6).![](media/A138.png)

(7).![](media/A132.png)

**Código de prueba completo**

![](media/A139.png)

![](media/A140.png)

Después de cargar el código con éxito en la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, bloquea el sensor ultrasónico con la mano (la distancia está entre 2-10 cm), luego verifica si el LED está encendido.