# Proyecto 9 Panel LED de Expresiones Faciales

![](media/A221.png)

### **1.Descripción** 

Qué divertido sería si se añadiera un panel de expresiones al robot. Y el panel LED Keyestudio 8\*16 puede hacer el truco. Con su ayuda, podrías diseñar expresiones faciales, imágenes, patrones y otras visualizaciones por ti mismo.

El panel LED 8\*16 viene con 128 LEDs. Los datos del microprocesador (Arduino) se comunican con el AiP1640 a través de una interfaz de bus de dos cables. Por lo tanto, puede controlar el encendido y apagado de los 128 LEDs en el módulo, para que la matriz de puntos en el módulo muestre el patrón que necesitas. Se proporciona un cable HX-2.54 de 4 pines para tu comodidad en el cableado.

### **2.Especificaciones**

- Voltaje de trabajo: DC 3.3-5V

- Pérdida de potencia: 400mW

- Frecuencia de oscilación: 450KHz

- Corriente de conducción: 200mA

- Temperatura de trabajo: -40\~80℃

- Modo de comunicación: I2C
  

### **3.Diagrama del circuito**

![](media/A222.png)

### **4.Principio de funcionamiento**

¿Cómo controlar cada LED de la matriz de puntos 8\*16? Se sabe que cada byte tiene 8 bits y cada bit es 0 o 1. Cuando es 0, el LED está apagado, mientras que cuando es 1, el LED está encendido. Un byte puede controlar una columna del LED, y naturalmente 16 bytes pueden controlar 16 columnas de LEDs, esa es la matriz de puntos 8\*16.

### **5.Descripción de pines y protocolo de comunicación**

Los datos del microprocesador (Arduino) se comunican con el AiP1640 a través de un cable de bus de dos cables.

El diagrama del protocolo de comunicación es el siguiente (SCLK) es SCL, (DIN) es SDA.

![](media/A223.png)

①Condición de inicio para la entrada de datos: SCL está en nivel alto y SDA cambia de alto a bajo.

②Para la configuración del comando de datos, existen métodos como se muestra en la figura a continuación.

En nuestro programa de ejemplo, seleccionamos la forma de **sumar 1 a la dirección automáticamente**, el valor binario es 0100 0000 y el valor hexadecimal correspondiente es 0x40.

![Img](media/A224.png)

③Para la configuración del comando de dirección, la dirección puede seleccionarse como se muestra a continuación.

Se selecciona el primer 00H en nuestro programa de ejemplo, y el número binario 1100 0000 corresponde al hexadecimal 0xc0.

![Img](media/A225.png)

④El requisito para la entrada de datos es que cuando SCL está en nivel alto al ingresar datos, la señal en SDA debe permanecer sin cambios. Solo cuando la señal de reloj en SCL está en nivel bajo, puede cambiarse la señal en SDA. La entrada de datos es primero el bit bajo, y luego el bit alto.

⑤La condición para el fin de la transmisión de datos es que cuando SCL está en nivel bajo, SDA en nivel bajo y SCL en nivel alto, el nivel de SDA se vuelve alto.

⑥Control de visualización, configurar diferentes anchos de pulso, el ancho de pulso puede seleccionarse como se muestra en la figura a continuación.

En el ejemplo, el ancho de pulso es 4/16, y el hexadecimal correspondiente a 1000 1010 es 0x8A.

![Img](media/A226.png)

**Instrucciones para el uso de la herramienta de matriz**

La herramienta de matriz de puntos usa la versión en línea, y el enlace es: [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

①Ingresa al enlace y la página aparece como se muestra a continuación

![](media/A227.png)

②La matriz de puntos es 8\*16, así que ajusta la altura a 8 y el ancho a 16, como se muestra en la figura a continuación.

![](media/A228.png)

③Generar datos hexadecimales a partir del patrón

Como se muestra en la figura a continuación, presiona el botón izquierdo del ratón para seleccionar, clic derecho para cancelar; dibuja el patrón que deseas, haz clic en Generar, y se generarán los datos hexadecimales que necesitamos.

![](media/A229.png)

### **6.Componentes**

| Placa de desarrollo *1      | Driver de motor 8833 *1            | Panel LED 8x16*1          |
| --------------------------- | --------------------------------- | ------------------------- |
| ![img](media/A230.jpg)      | ![img](media/A231.jpg)             | ![img](media/A232.jpg)    |
| Cable USB*1                 | Cable Dupont HX-2.54 4P 200mm *1  |                           |
| ![img](media/A233.jpg)      | ![img](media/A234.jpg)             |                           |



### **7.Diagrama de cableado**

![](media/A235.png)

El GND, VCC, SDA y SCL de la placa de luz LED 8x16 están conectados respectivamente a la placa de expansión de sensores keyestudio-(GND), + (VCC), A4, A5 para comunicación serial de dos hilos.

(<span style="color: rgb(255, 76, 65);">Nota:</span> Aunque está conectado con el pin IIC de Arduino, este módulo no es para comunicación IIC. Y el puerto IO aquí es para simular la comunicación I2C y puede conectarse con cualquier dos pines).

### **8.Código de prueba**

Antes de escribir el código, es necesario importar el archivo de la biblioteca de la placa LED 8x16. Los pasos específicos son los siguientes:

Haz clic en ![](media/A29.png) para entrar en la interfaz de la biblioteca de extensiones de sensores/módulos/componentes, luego busca el módulo “**Matrix 8\*16 Aip1640**” ![](media/A236.png) y haz clic en él. De esta manera, "**Not loaded**" cambia a "**loaded**", indicando que el módulo “**Matrix 8\*16 Aip1640**” fue agregado con éxito.

![Img](media/A237.png)

![](media/A238.png)

Haz clic en ![](media/A33.png) para volver a la interfaz del editor de código, se puede ver el bloque de instrucciones del módulo “**Matrix 8\*16 Aip1640**” agregado en el área de módulos.

![](media/A239.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A240.png)

**Código de prueba completo**

![](media/A241.png)

### **9.Resultado de la prueba**

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexión, luego gira el interruptor DIP a ON, se mostrará un patrón con forma de sonrisa en la placa LED.

![](media/A242.png)

**10.Explicación del código**

Usamos la herramienta de módulo que acabamos de aprender, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), para hacer que la matriz de puntos muestre el patrón de inicio, avanzar, detenerse y luego limpiar el patrón. El intervalo de tiempo es de 2000 ms.

![image-20250513092102687](media/A243.png)![image-20250513092107293](media/A244.png)![image-20250513092113035](media/A245.png)![image-20250513092116952](media/A246.png)


Bloque de instrucciones para cara sonriente ![](media/A247.png)

Bloque de instrucciones para expresión: ![](media/A248.png)

Bloque de instrucciones para corazón ![](media/A249.png)

Bloque de instrucciones para avanzar ![](media/A250.png)

Bloque de instrucciones para **retroceder** ![](media/A251.png)

Bloque de instrucciones para **girar a la izquierda** ![](media/A252.png)

Bloque de instrucciones para **girar a la derecha** ![](media/A253.png)

Bloque de instrucciones para **detenerse** ![](media/A254.png)

Bloque de instrucciones para **limpiar pantalla** ![](media/A255.png)

![](media/A235.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A240.png)

(3).![](media/A256.png)

**Código de prueba completo**

![](media/A257.png)

Después de subir el código de prueba, la placa de expresiones faciales muestra estos patrones en orden y repite esta secuencia.

![image-20250513092222972](media/A258.png)![image-20250513092233711](media/A259.png)![image-20250513092238552](media/A260.png)