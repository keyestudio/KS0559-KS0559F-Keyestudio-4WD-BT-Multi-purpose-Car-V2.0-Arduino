# Proyecto 17 Coche Inteligente Bluetooth Multiusos

![](media/A349.jpeg)

### **1.Descripción**

En proyectos anteriores, el coche solo realiza una función única. Sin embargo, en esta lección, integraremos todas sus funciones a través de Bluetooth.

### **2.Diagrama de Flujo**

![](media/A350.png)

### **3.Diagrama de Conexiones**

![](media/A351.png)

1). GND, VCC, SDA y SCL de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). RXD, TXD, GND y VCC del módulo Bluetooth están conectados respectivamente a TX, RX, G y 5V en la placa de expansión del controlador de motor 8833, mientras que los pines STATE y BRK del módulo Bluetooth no necesitan ser conectados.

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo está conectado a 5V (V) y el cable naranja está conectado a A3.

4). G, V, S1, S2 y S3 del sensor de seguimiento de línea están conectados a G (GND), V (VCC), D11, D7 y D8 de la placa de expansión del sensor.

5). VCC, Trig, Echo y Gnd del sensor ultrasónico están conectados a 5V (V), D12 (S), D13 (S) y Gnd (G).

6). La alimentación está conectada al puerto BAT.

### **4.Código de Prueba**

Antes de escribir el código, es necesario importar los archivos de biblioteca del sensor ultrasónico, la placa LED 8x16 y el servo. Los pasos específicos son los siguientes:

Haz clic en ![](media/A29.png) para entrar en la interfaz de biblioteca de extensiones de sensores/módulos/componentes, luego busca el sensor “**Ultrasonic**” ![](media/A122.png) y haz clic en él. De esta manera, "**Not loaded**" cambia a "**loaded**", indicando que el sensor “**Ultrasonic**” fue agregado con éxito.

![Img](media/A300.png)

![](media/A124.png)

Haz clic en ![](media/A33.png) para volver a la interfaz del editor de código, se pueden ver los bloques de instrucciones del sensor “**Ultrasonic**” agregado, el módulo “**Matrix 8\*16 Aip1640**” y el componente “**Servo**” en el área de módulos.

![](media/A285.png)

**Código Completo de Prueba**

<span style="color: rgb(255, 76, 65);">**Nota:** Antes de subir el código de prueba, necesitas retirar el módulo Bluetooth, de lo contrario el código no se podrá subir. Conecta el módulo Bluetooth después de subir el código con éxito.</span>

![](media/A352.png)

### **5.Resultado de la Prueba**

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la alimentación externa y luego gira el interruptor DIP a ON.

Después de que el módulo Bluetooth esté conectado a la APP y la APP móvil se conecte con éxito al Bluetooth, el coche inteligente puede ser controlado por la APP móvil. Podemos lograr las funciones correspondientes presionando los botones correspondientes en la APP móvil.