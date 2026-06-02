# Proyecto 10 Coche Inteligente Restringido

![](media/A261.jpeg)

### **1. Descripción**

En este proyecto, buscamos combinar el conocimiento de un sensor de seguimiento de línea y módulos controladores de motor para crear un coche inteligente restringido. En el experimento, nuestro objetivo es usar el sensor de seguimiento de línea para detectar si hay una línea negra alrededor del coche inteligente, y luego controlar la rotación de los dos motores según los resultados de la detección de manera que se bloquee el coche inteligente dentro de un círculo dibujado con línea negra.

### **2. Diagrama de Flujo**

![img](media/A262.png)

La lógica específica del coche inteligente 4WD restringido se muestra en la tabla.

![Img](media/A263.png)

### **3. Diagrama de Conexiones**

![](media/A264.png)

G, V, S1, S2 y S3 del sensor de seguimiento de línea están conectados a G (GND), V (VCC), D11, D7 y D8 de la placa de expansión del sensor.

La alimentación está conectada al puerto BAT.

### **4. Código de Prueba**

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A126.png)

(2).![](media/A265.png)

(3).![](media/A266.png)

(4).![](media/A267.png)

(5).![](media/A268.png)

(6).![](media/A269.png)

**Código Completo de Prueba**

![KidsBlock Project-1747127137354](media/A270.png)

### **5. Resultado de la Prueba**

Después de subir exitosamente el código a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la alimentación externa y luego gira el interruptor DIP a ON. Coloca el coche inteligente dentro del círculo negro, entonces se moverá únicamente dentro del círculo.