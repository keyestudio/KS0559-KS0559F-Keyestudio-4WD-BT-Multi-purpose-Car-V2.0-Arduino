# Proyecto 15 Coche Inteligente Controlado por Bluetooth

![](media/A327.jpeg)

### **1.Descripción**

Hemos aprendido los conocimientos básicos sobre Bluetooth. Y en esta lección, haremos un coche inteligente controlado por Bluetooth. En este proyecto, nuestro objetivo es considerar el teléfono móvil como el transmisor (host), y el coche inteligente conectado al módulo Bluetooth BT24 (esclavo) como el receptor, y usar la APP móvil para controlar el coche inteligente vía Bluetooth.

### **2.Botones de Control de la APP**

| Tecla                                         | Función                          |
| --------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Emparejar módulo Bluetooth DX-BT24 5.1 |
| ![wps15](media/A186.jpg) | Desconectar Bluetooth              |

|                                                              | Carácter de control                                            | Función                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Pulsar: F  <br />Soltar: S                                   | Pulsar el botón, el coche avanza; <br />soltar para detener  |
| ![wps17](media/A188.jpg)                 | Pulsar: L  <br />Soltar: S                                   | Pulsar el botón, el coche gira a la izquierda; <br />soltar para detener  |
| ![wps18](media/A189.jpg)                 | Pulsar: R  <br />Soltar: S                                   | Pulsar el botón, el coche gira a la derecha; <br />soltar para detener |
| ![wps19](media/A190.jpg)                 | Pulsar: B  <br />Soltar: S                                   | Pulsar el botón, el coche retrocede; <br />soltar para detener   |
| ![wps20](media/A191.jpg)                 | Pulsar: “a”  <br />Soltar: “S”                               | Clic para acelerar (máximo:255)                               |
| ![wps21](media/A192.jpg)                 | Pulsar: “d”  <br />Soltar: “S”                               | Clic para desacelerar (mínimo:0)                                |
| ![wps22](media/A193.jpg)                 | Clic para iniciar la función de detección de gravedad del <br />teléfono móvil: clic de nuevo para <br />salir del control por gravedad |                                                              |
| ![wps23](media/A194.jpg)                 | Clic para enviar “X”,<br />clic de nuevo para enviar “S”     | Iniciar función de seguimiento de línea; <br />clic de nuevo para salir      |
| ![wps24](media/A195.jpg)                 | Clic para enviar “Y”, <br />clic de nuevo para enviar “S”    | Iniciar función de evitación ultrasónica;<br />clic de nuevo para salir |
| ![wps25](media/A196.jpg) | Clic para enviar “U”, <br />clic de nuevo para enviar “S”    | Iniciar función de seguimiento ultrasónico;<br />clic de nuevo para salir |
| ![wps26](media/A197.jpg)                 | Clic para enviar “G”,<br />clic de nuevo para enviar “S”     | Iniciar función de restricción;<br />clic de nuevo para salir       |

### **3.Diagrama de Flujo**

![img](media/A328.png)

### **4.Diagrama de Conexiones**

![](media/A329.png)

1). GND, VCC, SDA y SCL de la placa LED 8\*8 están conectados a G (GND), V (VCC), A4 y A5 de la placa de expansión.
    
2). RXD, TXD, GND y VCC del módulo Bluetooth están conectados respectivamente a TX, RX, G y 5V en la placa de expansión del controlador de motor 8833, mientras que los pines STATE y BRK del módulo Bluetooth no necesitan ser conectados.
    
3). El servo está conectado a G, V y A3. El cable marrón está conectado a Gnd (G), el cable rojo está conectado a 5V (V) y el cable naranja está conectado a A3.
    
4). La alimentación está conectada al puerto BAT
    

### **5.Código de Prueba**

Antes de escribir el código, es necesario importar los archivos de la biblioteca de la placa LED 8x16 y del servo. Los pasos específicos son los siguientes:

Haz clic en ![](media/A29.png) para entrar en la interfaz de la biblioteca de extensiones de sensores/módulos/componentes, luego busca el módulo “**Matrix 8\*16 Aip1640**” ![](media/A236.png) y haz clic en él. De esta manera, "**Not loaded**" cambia a "**loaded**", indicando que el módulo “**Matrix 8\*16 Aip1640**” se agregó correctamente.

![Img](media/A237.png)  

![](media/A238.png)

Haz clic en ![](media/A33.png) para volver a la interfaz del editor de código, se pueden ver los bloques de instrucciones del módulo “**Matrix 8\*16 Aip1640**” agregado y del componente “**Servo**” en el área de módulos.

![](media/A330.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

**Código de prueba completo**

<span style="color: rgb(255, 76, 65);">**Nota:** Antes de subir el código de prueba, necesitas retirar el módulo Bluetooth, de lo contrario el código no se podrá subir. Conecta el módulo Bluetooth después de subir el código con éxito.</span>

![](media/A335.png)

![](media/A336.png)

![](media/A337.png)

![](media/A338.png)

![](media/A339.png)

### **6. Resultado de la prueba**

Después de subir el código con éxito a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la alimentación externa y luego gira el interruptor DIP a ON.

Inserta el módulo BT y abre tu celular para conectar el Bluetooth y controlar el coche inteligente. El coche se moverá hacia adelante, hacia atrás, girará a la izquierda y a la derecha y se detendrá. Además, la placa LED 8\*8 mostrará los patrones correspondientes.