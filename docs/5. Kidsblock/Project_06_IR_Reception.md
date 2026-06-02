# Proyecto 6 Recepción IR

![](media/A141.png)

### **1. Descripción**

No hay duda de que el control remoto por infrarrojos es omnipresente en la vida diaria. Se utiliza para controlar varios electrodomésticos, como televisores, estéreos, grabadoras de video y receptores de señal satelital. El control remoto por infrarrojos está compuesto por sistemas de transmisión y recepción infrarroja, es decir, un control remoto infrarrojo y un módulo receptor infrarrojo junto con un microcontrolador capaz de decodificar.

![](media/A142.png)

La señal portadora infrarroja de 38K emitida por el control remoto es codificada por el chip de codificación en el control remoto. Está compuesta por un segmento de código piloto, código de usuario, código inverso de usuario, código de datos y código inverso de datos. El intervalo de tiempo del pulso se usa para distinguir si es una señal 0 o 1 y la codificación está formada por estas señales 0 y 1.

El código de usuario del mismo control remoto es constante mientras que el código de datos puede distinguir la tecla.

Cuando se presiona un botón del control remoto, el control remoto envía una señal portadora infrarroja. Cuando el receptor IR recibe la señal, el programa decodifica la señal portadora y determina qué tecla fue presionada. El MCU decodifica la señal 01 recibida, juzgando así qué tecla fue presionada en el control remoto.

El receptor infrarrojo que usamos es un módulo receptor infrarrojo. Está compuesto principalmente por una cabeza receptora infrarroja, que es un dispositivo que integra recepción, amplificación y demodulación. Su IC interno ha completado la demodulación y puede lograr desde la recepción infrarroja hasta la salida, siendo compatible con señales TTL.

Además, es adecuado para control remoto infrarrojo y transmisión de datos infrarrojos. El módulo receptor infrarrojo fabricado por el receptor tiene solo tres pines: línea de señal, VCC y GND. Es muy conveniente para comunicarse con Arduino y otros microcontroladores.

### **2. Especificaciones**

- Voltaje de operación: 3.3-5V (DC)

- Señal de salida: Señal digital

- Ángulo de recepción: 90 grados

- Frecuencia: 38 kHz

- Distancia de recepción: 10 m

La imagen muestra el producto real y el diagrama del circuito del receptor infrarrojo.

![](media/A141.png)

![](media/A143.png)

### **3. Componentes**

| Placa de desarrollo *1      | Driver de motor 8833 *1      | Módulo LED rojo *1          |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg) | ![img](media/A43.jpg) | ![img](media/A44.jpg) |
| Cable Dupont 3P H-H *1      | Cable USB *1               |                           |
| ![img](media/A45.jpg) | ![img](media/A46.jpg) |                           |

Dado que la placa 8833 integra el receptor IR, no necesita cableado adicional. Los pines del módulo receptor IR son G (GND), V (VCC) y D3.

### **4. Código de prueba**

<span style="color: rgb(255, 76, 65);">Por favor, tenga en cuenta: El módulo infrarrojo mostrado en la demostración del software ya está integrado en la placa de expansión y no se suministra por separado. Por lo tanto, no encontrará el módulo representado en la imagen a continuación dentro del producto.![](media/A144.png)</span>

Antes de escribir el código, es necesario importar el archivo de la biblioteca del sensor receptor IR. Los pasos específicos son los siguientes:

Haga clic en ![](media/A29.png) para entrar en la interfaz de biblioteca de extensiones de sensores/módulos/componentes, luego busque el sensor “**ir remote**” ![](media/A144.png) y haga clic en él. De esta manera, "**Not loaded**" cambia a "**loaded**", indicando que el sensor “ir remote” fue agregado con éxito.

![Img](media/A145.png)

![](media/A146.png)

Haga clic en ![](media/A33.png) para volver a la interfaz del editor de código, podrá ver el bloque de instrucciones del sensor “**ir remote**” agregado en el área de módulos.

![](media/A147.png)

Puede arrastrar bloques para editar. Los bloques listados a continuación son para su referencia.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A149.png)

(4).![](media/A150.png)

**Código completo de prueba**

![](media/A151.png)

### **5. Resultado de la prueba**

Después de cargar con éxito el código en la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, haz clic en ![](media/A80.png) para configurar la velocidad en baudios a 9600.

Saca el control remoto y envía la señal al sensor receptor infrarrojo. Puedes ver el valor de la tecla correspondiente; si el tiempo de pulsación es demasiado largo, FFFFFFFF tiende a mostrar caracteres corruptos.

![](media/A152.png)

Los valores de las teclas del control remoto se muestran a continuación.

![](media/A153.jpeg)

### **6. Práctica de Extensión**

Hemos decodificado el valor de la tecla del control remoto IR. ¿Qué tal controlar el LED con el valor medido? Podríamos diseñar un experimento.

Conecta un LED al pin D9, luego presiona las teclas del control remoto para encender y apagar el LED.

![](media/A154.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A155.png)

(4).![](media/A150.png)

(5).![](media/A156.png)

(6).![](media/A157.png)

(7).![](media/A158.png)

(8).![](media/A159.png)

**Código de Prueba Completo**

![](media/A160.png)

Después de cargar con éxito el código en la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, presiona la tecla "**OK**" en el control remoto para encender y apagar el LED.