# Proyecto 1 Parpadeo de LED

### **1. Descripción**

![](media/A40.jpeg)

Para principiantes y entusiastas, el parpadeo de LED es un programa fundamental. LED, la abreviatura de diodos emisores de luz, está compuesto por compuestos químicos como Ga, As, P, N, entre otros.

El LED puede parpadear en diversos colores al alterar el tiempo de retardo en el código de prueba. Cuando está bajo control, con alimentación en GND y VCC, el LED se encenderá si el extremo S está en nivel alto, de lo contrario se apagará.

### **2. Especificaciones**

- Interfaz de control: puerto digital

- Voltaje de trabajo: DC 3.3-5V

- Espaciado de pines: 2.54mm

- Color de visualización del LED: rojo

![](media/A41.png)

### **3. Componentes**

| Placa de desarrollo *1    | Driver de motor 8833 *1    | Módulo LED rojo *1        |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg)     | ![img](media/A44.jpg)     |
| Cable Dupont 3P F-F *1    | Cable USB *1              |                           |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg)     |                           |

### **4. Diagrama de conexión**

![](media/A47.png)

Como se puede ver en la figura anterior, la placa de expansión del driver de motor Keyestudio 8833 está apilada sobre la placa de desarrollo Keyestudio 4.0.

Los pines G, V y S del módulo LED están conectados respectivamente a G, 5V y D9 de la placa de expansión.

### **5. Código de prueba**

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A48.png)

(2).![](media/A49.png)

(3).![](media/A50.png)

**Código de prueba completo**

![](media/A51.png)

### **6. Resultado de la prueba**

Después de subir exitosamente el código a la placa V4.0, conecta los cables según el diagrama de conexión y usa un cable USB para conectar la computadora y alimentar la placa. Al encender, verás que el LED conectado al D9 se enciende y apaga.

### **7. Práctica de extensión**

A continuación, vamos a cambiar la frecuencia del parpadeo del LED modificando el tiempo de espera.

![](media/A52.png)

Después de subir exitosamente el código a la placa V4.0, conecta los cables según el diagrama de conexión y usa un cable USB para conectar la computadora y alimentar la placa. El resultado de la prueba muestra que el LED parpadea más rápido.