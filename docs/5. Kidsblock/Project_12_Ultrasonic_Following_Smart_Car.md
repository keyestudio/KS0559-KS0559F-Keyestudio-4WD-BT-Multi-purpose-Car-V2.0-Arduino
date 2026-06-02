# Proyecto 12 Coche Inteligente Seguidor Ultrasónico

![](media/A280.png)

### **1. Descripción**

En este proyecto, buscaremos detectar la distancia entre el coche inteligente 4WD y los obstáculos delante mediante un sensor ultrasónico para controlar dos motores de manera que el coche se mueva y el tablero LED 8\*8 muestre un patrón facial sonriente.

### **2. Diagrama de Flujo**

![img](media/A281.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Detección</td>
<td>Distancia medida de los obstáculos frontales</td>
<td>distancia (unidad: cm)</td>
</tr>
<tr class="even">
<td>Configuración</td>
<td>El tablero LED 8*16 muestra un patrón de sonrisa.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Configurar servo a 90°</td>
<td></td>
</tr>
<tr class="even">
<td>Condición</td>
<td>distancia≥20 y distancia≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>Estado</td>
<td>Avanzar</td>
<td></td>
</tr>
<tr class="even">
<td>Condición</td>
<td>distancia＞10 y distancia＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>distancia＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Condición</td>
<td>detener</td>
<td></td>
</tr>
<tr class="odd">
<td>Condición</td>
<td>distancia≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Condición</td>
<td>Retroceder</td>
<td></td>
</tr>
</tbody>
</table>


### **3. Diagrama de Conexiones**

![](media/A282.png)

**Conexiones:**

1). GND, VCC, SDA y SCL del tablero LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.

2). VCC, Trig, Echo y Gnd del sensor ultrasónico están conectados a 5V (V), D12 (S), D13 (S) y Gnd (G).

3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo a 5V (V) y el cable naranja a A3.

4). La alimentación está conectada al puerto BAT.

### **4. Código de Prueba**

Antes de escribir el código, es necesario importar los archivos de biblioteca del sensor ultrasónico, el tablero LED 8x16 y el servo. Los pasos específicos son los siguientes:

Haz clic en ![](media/A29.png) para entrar en la interfaz de biblioteca de extensiones de sensores/módulos/componentes, luego busca el sensor “Ultrasonic” ![](media/A122.png) y haz clic en él.

De esta manera, "**Not loaded**" cambia a "**loaded**", indicando que el sensor “**Ultrasonic**” fue añadido con éxito.

![Img](media/A283.png)

![](/media/A284.png)

Los archivos de biblioteca del tablero LED 8x16 y del servo se añaden de la misma forma que el sensor ultrasónico.

Haz clic en ![](media/A33.png) para volver a la interfaz del editor de código, se pueden ver los bloques de instrucciones del sensor “**Ultrasonic**”, el módulo “**Matrix 8\*16 Aip1640**” y el componente “**Servo**” en el área de módulos.

![](media/A285.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia

(1).![](media/A126.png)

(2).![](media/A286.png)

(3).![](media/A287.png)

(4).![](media/A288.png)

(5).![](media/A268.png)

(6).![](media/A289.png)

(7).![](media/A290.png)

(8).![](media/A291.png)

(9).![](media/A292.png)

**Código Completo de Prueba**

![](media/A293.png)

![](media/A294.png)

![](media/A295.png)

### **5. Resultado de la Prueba**

Después de subir el código con éxito a la placa V4.0, conecta las conexiones según el diagrama de conexiones, enciende la alimentación externa y luego gira el interruptor DIP a ON. Configura el servo a 90°, el coche inteligente se moverá con los obstáculos y el tablero LED 8X16 mostrará una “sonrisa”.