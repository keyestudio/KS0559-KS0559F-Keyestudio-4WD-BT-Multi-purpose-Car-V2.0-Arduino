# Proyecto 11 Coche Inteligente de Seguimiento de Línea

![](media/A271.png)

### **1. Descripción**

Basándonos en el principio de funcionamiento del sensor de seguimiento de línea, creamos un coche inteligente de seguimiento de línea.

En este proyecto, detectamos si hay una línea negra en la parte inferior del coche inteligente mediante un sensor de seguimiento de línea, y luego controlamos la rotación de los dos grupos de motores según los resultados de la detección, de manera que el coche inteligente se desplace siguiendo la línea negra.

### **2. Diagrama de Flujo**

![img](media/A272.png)

![Img](media/A273.png)

### **3. Diagrama de Conexiones**

![](media/A264.png)

G, V, S1, S2 y S3 del sensor de seguimiento de línea están conectados a G (GND), V (VCC), D11, D7 y D8 de la placa de expansión de sensores.

La alimentación se conecta al puerto BAT.

### **4. Código de Prueba**

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia

(1).![](media/A126.png)

(2).![](media/A274.png)

(3).![](media/A275.png)

(4).![](media/A268.png)

(5).![](media/A276.png)

**Código Completo de Prueba**

![](media/A277.png)

![](media/A278.png)

![](media/A279.png)

### **5. Resultado de la Prueba**

Después de subir correctamente el código a la placa V4.0, conecta los cables según el diagrama de conexiones, enciende la alimentación externa y luego gira el interruptor DIP a ON. Entonces el coche inteligente seguirá las líneas.