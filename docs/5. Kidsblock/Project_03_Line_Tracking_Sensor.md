# Proyecto 3: Sensor de Seguimiento de Línea

![](media/A63.png)

### **1. Descripción**

El sensor de seguimiento es en realidad un sensor infrarrojo. El componente utilizado aquí es el tubo infrarrojo TCRT5000. Su principio de funcionamiento es usar la diferente reflectividad de la luz infrarroja en los colores, luego convertir la intensidad de la señal reflejada en una señal de corriente.

Durante el proceso de detección, el negro está activo en nivel ALTO mientras que el blanco está activo en nivel BAJO. La altura de detección es de 0-3 cm.

El módulo de seguimiento de línea de 3 canales de Keyestudio ha integrado 3 conjuntos de tubos infrarrojos TCRT5000 en una placa, lo que es más conveniente para el cableado y control.

Girando el potenciómetro ajustable en el sensor, se puede ajustar la sensibilidad de detección del sensor.

### **2. Especificaciones**

- Voltaje de operación: 3.3-5V (DC)

- Interfaz: 5PIN

- Señal de salida: Señal digital

- Altura de detección: 0-3 cm

![](media/A64.jpeg)

<span style="color: rgb(255, 76, 65);">Nota:</span> Antes de la prueba, gire el potenciómetro en el sensor para ajustar la sensibilidad de detección. La sensibilidad es óptima cuando se ajusta el LED a un umbral entre ENCENDIDO y APAGADO.

### **3. Componentes**

| Placa de Desarrollo *1   | Driver de Motor 8833 *1  | Módulo LED Rojo *1       | Sensor de Seguimiento de Línea *1 |
| ------------------------ | ------------------------ | ------------------------ | --------------------------------- |
| ![img](media/A65.jpg)    | ![img](media/A66.jpg)    | ![img](media/A67.jpg)    | ![img](media/A68.png)             |
| Cable Dupont 5P *1       | Cable USB *1             | Cable Dupont 3P *1       |                                   |
| ![img](media/A69.png)    | ![img](media/A70.jpg)    | ![img](media/A71.jpg)    |                                   |

### **4. Diagrama de Conexiones**

![](media/A72.png)

G, V, S1, S2 y S3 del sensor de seguimiento de línea están conectados a G (GND), V (VCC), D11, D7 y D8 de la placa de expansión del sensor.

### **5. Código de Prueba**

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A75.png)

(4).![](media/A76.png)

(5).![](media/A77.png)

**Código Completo de Prueba**

![](media/A78.png)

![](media/A79.png)

### **6. Resultado de la Prueba**

Después de subir exitosamente el código a la placa V4.0, conecta los cables según el diagrama de conexiones y usa un cable USB para conectar la computadora y alimentar la placa.

Después de encender, haz clic en ![](media/A80.png) para configurar la velocidad en baudios a 9600 y podrás ver el estado de los tres sensores de seguimiento de línea. Cuando no se reciben señales, el valor es 1. Si cubrimos el sensor con un papel blanco, el valor será 0.

![](media/A81.png)

![](media/A82.png)

### **7. Práctica de Extensión**

Después de conocer su principio de funcionamiento, puedes conectar un LED a D9 para controlar el LED con él.

![](media/A83.png)

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A84.png)

(4).![](media/A85.png)

(5).![](media/A77.png)

(6).![](media/A86.png)

(7).![](media/A87.png)

**Código Completo de Prueba**

![](media/A88.png)

![](media/A89.png)

Después de subir exitosamente el código a la placa V4.0, conecta los cables según el diagrama de conexiones y usa un cable USB para conectar la computadora y alimentar la placa.

Después de encender, acerca un papel al sensor, entonces veremos que el LED se enciende al cubrir el sensor de seguimiento de línea.