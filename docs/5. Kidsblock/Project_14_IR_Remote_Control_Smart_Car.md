# Proyecto 14 Coche Inteligente Controlado por Mando IR

![](media/A307.jpeg)

### **1. Descripción**

En este proyecto, haremos un coche inteligente controlado por mando IR y presionaremos el botón del mando IR para que el coche se mueva.

### **2. Diagrama de Flujo**

![img](media/A308.png)

**La lógica específica del coche inteligente controlado por mando IR se muestra a continuación:**

| Configuración inicial                                      |           | La placa LED muestra una cara sonriente           |
| --------------------------------------------------------- | --------- | ------------------------------------------------- |
| Mando a distancia                                         | Valor clave | Estado de la tecla                                |
| ![wps6-1747037981476-25](media/A309.jpg) | FF629D    | Avanzar La placa LED 8*8 muestra el icono de avance |
| ![wps7-1747037985784-27](media/A310.jpg) | FFA857    | Retroceder La placa LED 8*8 muestra el icono de retroceso |
| ![wps8](media/A311.jpg)                  | FF22DD    | Girar a la izquierda La placa LED 8*8 muestra el icono hacia la izquierda |
| ![wps9](media/A312.jpg)                  | FFC23D    | Girar a la derecha La placa LED 8*8 muestra el icono hacia la derecha |
| ![wps10](media/A313.jpg)                                 | FF02FD    | Parar La placa LED 8*8 muestra “STOP”              |



### **3. Diagrama de Conexiones**

![](media/A314.png)

1). GND, VCC, SDA y SCL del módulo de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.
    
2). Como el receptor IR está integrado en la placa de expansión del controlador de motor 8833, no es necesario cableado adicional. Los pines del receptor IR en la placa 8833 son G (GND), V (VCC) y D3 respectivamente. 
    
3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo a 5V (V) y el cable naranja a A3.
    
4). La alimentación está conectada al puerto BAT.
    

### **4. Código de Prueba**

<span style="color: rgb(255, 76, 65);">Por favor, tenga en cuenta: El módulo infrarrojo mostrado en la demostración del software ya está integrado en la placa de expansión y no se suministra por separado. Por lo tanto, no encontrará el módulo representado en la imagen a continuación dentro del producto.![](media/A144.png)</span>

Antes de escribir el código, es necesario importar los archivos de biblioteca del sensor ultrasónico, la placa LED 8x16 y el servo. Los pasos específicos son los siguientes: 
    
Haga clic en ![](media/A29.png) para entrar en la interfaz de biblioteca de extensiones de sensores/módulos/componentes, luego busque el sensor “ir remote” ![](media/A144.png) y haga clic en él. De esta manera, "**Not loaded**" cambia a "**loaded**", indicando que el sensor “**ir remote**” fue añadido con éxito. 

![Img](media/A315.png)

![](media/A146.png)

Haga clic en ![](media/A33.png) para volver a la interfaz del editor de código, se pueden ver los bloques de instrucciones del sensor “**ir remote**”, el módulo “**Matrix 8\*16 Aip1640**” y el componente “**Servo**” en el área de módulos. 

![](media/A316.png)

Puede arrastrar bloques para editar. Los bloques listados a continuación son para su referencia

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A318.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A320.png)

(7).![](media/A291.png)

(8).![](media/A321.png)

**Código de Prueba Completo**

![](media/A322.png)

![](media/A323.png)

![](media/A324.png)

![](media/A325.png)

![](media/A326.png)

### **5. Resultado de la Prueba**

Después de subir el código con éxito a la placa V4.0, conecte los cables según el diagrama de conexiones, encienda la alimentación externa y luego ponga el interruptor DIP en ON. Entonces podremos usar el mando IR para conducir el coche y la placa LED 8X16 mostrará el patrón de estado correspondiente.