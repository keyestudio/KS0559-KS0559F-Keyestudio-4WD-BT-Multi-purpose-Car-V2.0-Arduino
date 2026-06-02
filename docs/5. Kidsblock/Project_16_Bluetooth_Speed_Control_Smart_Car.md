# Proyecto 16 Control de Velocidad por Bluetooth para Coche Inteligente

![](media/A327.jpeg)

### **1. Descripción**

En este proyecto, utilizaremos Bluetooth para ajustar la velocidad del coche inteligente. Permitimos definir velocidades variables y cambiarlas para modificar la velocidad del coche inteligente.

### **2. Diagrama de Flujo**

![image-20250513095810478](media/A340.png)

### **3. Diagrama de Conexiones**

![](media/A329.png)

1). GND, VCC, SDA y SCL de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). RXD, TXD, GND y VCC del módulo Bluetooth están conectados respectivamente a TX, RX, G y 5V en la placa de expansión del controlador de motor 8833, mientras que los pines STATE y BRK del módulo Bluetooth no necesitan ser conectados.

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo está conectado a 5V (V) y el cable naranja está conectado a A3.

4). La alimentación está conectada al puerto BAT.

### **4. Código de Prueba**

Antes de escribir el código, es necesario importar los archivos de la biblioteca de la placa LED 8x16 y del servo. Los pasos específicos son los siguientes:

Haz clic en ![](media/A29.png) para entrar en la interfaz de la biblioteca de extensiones de sensores/módulos/componentes, luego busca el módulo “Matrix 8\*16 Aip1640” ![](media/A236.png) y haz clic en él. De esta manera, "**Not loaded**" cambia a "**loaded**", indicando que el módulo “**Matrix 8\*16 Aip1640**” fue añadido exitosamente.

![Img](media/A237.png)

![](media/A238.png)

Haz clic en ![](media/A33.png) para volver a la interfaz del editor de código, se pueden ver los bloques de instrucciones del módulo “**Matrix 8\*16 Aip1640**” y del componente “**Servo**” en el área de módulos.

![](media/A330.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia:

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

(10).![](media/A341.png)

**Código Completo de Prueba**

<span style="color: rgb(255, 76, 65);">**Nota:** Antes de subir el código de prueba, necesitas retirar el módulo Bluetooth, de lo contrario el código no se podrá subir. Conecta el módulo Bluetooth después de subir el código exitosamente.</span>

![](media/A342.png)

![](media/A343.png)

![](media/A344.png)

![](media/A345.png)

![](media/A346.png)

![](media/A346.png)

### **5. Resultado de la Prueba**

Después de subir exitosamente el código a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la alimentación externa y luego coloca el interruptor DIP en ON. Empareja la APP con Bluetooth, el coche inteligente podrá ser controlado para moverse mediante la APP.

Presiona ![](media/A347.png), el coche acelerará, presiona ![](media/A348.png), el coche reducirá la velocidad, y la placa LED 8\*16 mostrará el patrón de estado correspondiente del coche inteligente.