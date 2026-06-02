# Proyecto 4 Control de Servo

### **1.Descripción**

![](media/A90.jpeg)

El motor servo es un actuador rotativo de control de posición. Principalmente consta de una carcasa, una placa de circuito, un motor sin núcleo, un engranaje y un sensor de posición. Su principio de funcionamiento es que el servo recibe la señal enviada por MCUs o receptores y produce una señal de referencia con un período de 20 ms y un ancho de 1.5 ms, luego compara el voltaje de polarización continua adquirido con el voltaje del potenciómetro y obtiene la salida de la diferencia de voltaje.

![](media/A91.png)

En general, el servo tiene tres cables en marrón, rojo y naranja. El cable marrón está conectado a tierra, el rojo es la línea de polo positivo y el naranja es la línea de señal.

El ángulo de rotación del motor servo se controla regulando el ciclo de trabajo de la señal PWM (Modulación por Ancho de Pulso). El ciclo estándar de la señal PWM es de 20 ms (50 Hz). Teóricamente, el ancho se distribuye entre 1 ms y 2 ms, pero en la práctica está entre 0.5 ms y 2.5 ms. El ancho corresponde al ángulo de rotación de 0° a 180°. Pero tenga en cuenta que para motores de diferentes marcas, la misma señal puede tener diferentes ángulos de rotación.

![](media/A92.jpg)

Los ángulos correspondientes del servo se muestran a continuación:

![](media/A93.png)

### **2.Especificaciones**

- Voltaje de trabajo: DC 4.8V ~ 6V

- Rango de ángulo operativo: aproximadamente 180 ° (en 500 → 2500 μsec)

- Rango de ancho de pulso: 500 → 2500 μsec

- Velocidad sin carga: 0.12 ± 0.01 seg / 60 (DC 4.8V) 0.1 ± 0.01 seg / 60 (DC 6V)
  
- Corriente sin carga: 200 ± 20mA (DC 4.8V) 220 ± 20mA (DC 6V)

- Torque de parada: 1.3 ± 0.01kg · cm (DC 4.8V) 1.5 ± 0.1kg · cm (DC 6V)
  
- Corriente de parada: ≦ 850mA (DC 4.8V) ≦ 1000mA (DC 6V)

- Corriente en espera: 3 ± 1mA (DC 4.8V) 4 ± 1mA (DC 6V)

### **3.Componentes**

| Placa de Desarrollo *1    | Driver de Motor 8833 *1    | Servo*1                                     |
| ------------------------- | ------------------------- | ------------------------------------------- |
| ![img](media/A94.jpg)  | ![img](media/A95.jpg)  | ![img](media/A96.png)                   |
| Portabaterías 18650*1     | Cable USB*1               | Batería 18650*2 (auto-proporcionada)        |
| ![img](media/A97.png) | ![img](media/A98.jpg) | ![img](media/A99.png) |

### **4.Diagrama de Conexiones**

![](media/A100.png)

Nota de conexión: El servo se conecta a G (GND), V (VCC) y A3, el cable marrón del servo está conectado a Gnd (G), el rojo está conectado a 5V (V) y el naranja está conectado a A3.

El servo debe conectarse a una fuente de alimentación externa debido a su alta demanda de corriente para el accionamiento. Generalmente, la corriente de la placa de desarrollo no es suficiente. Si no se conecta la fuente de alimentación externa, la placa de desarrollo podría quemarse.

### **5.Código de Prueba**

Antes de escribir el código, es necesario importar el archivo de la biblioteca del servo. Los pasos específicos son los siguientes:

Haga clic en ![](media/A29.png) para entrar en la interfaz de la biblioteca de extensiones de sensores/módulos/componentes, luego busque "**Servo**".

![](media/A101.png)

Seleccione el componente y haga clic en él. De esta manera, "**Not Loaded**" cambia a "**loaded**", indicando que el componente "**Servo**" fue agregado con éxito.

![Img](media/A102.png)

![](media/A103.png)

Haga clic en ![](media/A33.png) para volver al editor de código, y en el área de módulos podrá ver el bloque directivo del componente "**Servo**" agregado.

![](media/A104.png)

Puede arrastrar bloques para editar. Los bloques listados a continuación son para su referencia.

(1).![](media/A105.png)

(2).![](media/A106.png)

(3).![](media/A107.png)

**Código Completo de Prueba**

![](media/A108.png)

### **6.Resultado de la Prueba**

Después de cargar con éxito el código en la placa V4.0, conecte los cables según el diagrama de conexiones y encienda la fuente de alimentación externa. Después de encender, gire el interruptor DIP al extremo "ON", entonces el servo oscilará en el rango de 0° a 180°.