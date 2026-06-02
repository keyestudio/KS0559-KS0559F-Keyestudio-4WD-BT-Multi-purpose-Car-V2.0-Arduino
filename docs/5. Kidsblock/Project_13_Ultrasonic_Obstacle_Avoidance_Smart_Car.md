# Proyecto 13 Coche Inteligente con Evitación de Obstáculos por Ultrasonidos

![](media/A296.png)

### **1. Descripción**

En este proyecto, nuestro objetivo es crear un coche inteligente con evitación de obstáculos por ultrasonidos. Usaremos el sensor ultrasónico para detectar la distancia al obstáculo, lo cual se puede usar para controlar el servo y hacer que gire para que el coche se mueva. Mientras tanto, la placa LED 8X16 mostrará el patrón de estado correspondiente.

### **2. Diagrama de Flujo**

![img](media/A297.png)

**La lógica específica del coche inteligente con evitación de obstáculos por ultrasonidos se muestra a continuación:**

![Img](media/A298.png)

![Img](media/A299.png)

### **3. Diagrama de Conexiones**

![](media/A282.png)

1). GND, VCC, SDA y SCL del módulo de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). VCC, Trig, Echo y Gnd del sensor ultrasónico están conectados a 5V (V), D12 (S), D13 (S) y Gnd (G).

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo está conectado a 5V (V) y el cable naranja está conectado a A3.

4). La alimentación está conectada al puerto BAT.

### **4. Código de Prueba**

Antes de escribir el código, es necesario importar los archivos de biblioteca del sensor ultrasónico, la placa LED 8x16 y el servo. Los pasos específicos son los siguientes:

Haz clic en ![](media/A29.png) para entrar en la interfaz de biblioteca de extensiones de sensores/módulos/componentes, luego busca el sensor “Ultrasonic” ![](media/A122.png) y haz clic en él. De esta forma, "**Not loaded**" cambia a "**loaded**", indicando que el sensor “**Ultrasonic**” se añadió correctamente.

![Img](media/A300.png)

![](/media/A284.png)

Haz clic en ![](media/A33.png) para volver a la interfaz del editor de código, se pueden ver los bloques de instrucciones del sensor “**Ultrasonic**”, el módulo “**Matrix 8\*16 Aip1640**” y el componente “**Servo**” en el área de módulos.

![](media/A285.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A301.png)

(3).![](media/A302.png)

(4).![](media/A287.png)

(5).![](media/A288.png)

(6).![](media/A268.png)

(7).![](media/A289.png)

(8).![](media/A292.png)

(9).![](media/A290.png)

(10).![](media/A291.png)

**Código de Prueba Completo**

![](media/A303.png)

![](media/A304.png)

![](media/A305.png)

![](media/A306.png)

### **5. Resultado de la Prueba**

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la alimentación externa y luego gira el interruptor DIP a ON.

El coche inteligente avanza y evita obstáculos automáticamente. Cuando no hay camino adelante, el servo hará girar el sensor ultrasónico para escanear las distancias a la izquierda, en el centro y a la derecha, y el coche girará hacia el lado abierto. Mientras tanto, la placa LED 8X16 mostrará el patrón de estado correspondiente.