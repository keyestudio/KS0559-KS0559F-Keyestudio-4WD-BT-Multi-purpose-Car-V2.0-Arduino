# Proyecto 2: Ajustar el Brillo del LED

### **1.Descripción**

En la lección anterior, controlamos el encendido y apagado del LED y lo hicimos parpadear.

En este proyecto, controlaremos el brillo del LED mediante PWM simulando un efecto de respiración.

PWM es un medio para controlar la salida analógica mediante medios digitales. El control digital se usa para generar ondas cuadradas con diferentes ciclos de trabajo (una señal que cambia constantemente entre niveles alto y bajo) para controlar la salida analógica. En general, los voltajes de entrada de los puertos son 0V y 5V.

¿Qué pasa si se requiere 3V? ¿O un cambio entre 1V, 3V y 3.5V? No podemos cambiar las resistencias constantemente. Por esta razón, recurrimos al PWM.

![](media/A53.gif)

Para la salida de voltaje del puerto digital de Arduino, solo existen LOW y HIGH, que corresponden a la salida de voltaje de 0V y 5V. Puedes definir LOW como 0 y HIGH como 1, y hacer que Arduino emita quinientas señales 0 o 1 dentro de 1s.

Si todas las quinientas salidas son 1, eso es 5V; si todas son 0, eso es 0V. Si se emite 010101010101 de esta manera, entonces el puerto de salida es 2.5V, lo que es como mostrar una película. La película que vemos no es completamente continua. En realidad, emite 25 imágenes por segundo. En este caso, el humano no puede verlo, tampoco el PWM. Si queremos un voltaje diferente, necesitamos controlar la proporción de 0 y 1. Cuantas más señales 0 y 1 se emitan por unidad de tiempo, más preciso será el control.

PWM es una tecnología que usa métodos digitales para obtener cantidades analógicas. El control digital permite formar una onda cuadrada, la señal de onda cuadrada solo tiene dos estados: encendido y apagado (alto y bajo). Un voltaje que varía de 0 a 5V puede simularse controlando la proporción de duración de encendido a apagado. El tiempo que dura encendido (técnicamente llamado nivel alto) se llama ancho de pulso, por lo que PWM también se llama modulación por ancho de pulso.

![](media/A54.png)

Las barras verticales verdes representan un período de la onda cuadrada. El valor escrito en cada analogWrite(value) corresponde a un porcentaje, que también se llama Ciclo de Trabajo (Duty Cycle). Este porcentaje se refiere a la proporción de tiempo ocupado por el nivel alto en un ciclo, es decir, ciclo de trabajo = tiempo de nivel alto / tiempo del ciclo.

En la figura, de arriba hacia abajo, el ciclo de trabajo de la primera onda cuadrada es 0%, y el valor correspondiente es 0, y el brillo del LED es el más bajo, es decir, estado apagado. Cuanto más tiempo dure el nivel alto, más brillante será. Por lo tanto, el valor del último ciclo de trabajo del 100% es 255, y el LED es el más brillante. El 50% es la mitad de brillo, y el 25% es más oscuro.

PWM se usa más para ajustar el brillo de luces LED o la velocidad de rotación de motores, y la velocidad de las ruedas impulsadas por los motores puede controlarse fácilmente. Al jugar con algunos robots Arduino, los beneficios del PWM se reflejan mejor.

### **2.Componentes**

| Placa de Desarrollo *1    | Driver de Motor 8833 *1    | Módulo LED Rojo *1         |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg)     | ![img](media/A44.jpg)     |
| Cable Dupont 3P F-F *1    | Cable USB *1              |                           |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg)     |                           |

### **3.Diagrama de Conexiones**

Mantén las conexiones sin cambios.

![](media/A47.png)

### **4.Código de Prueba**

Puedes arrastrar bloques para editar. Los bloques listados a continuación son para tu referencia.

(1).![](media/A55.png)

(2).![](media/A56.png)

(3).![](media/A57.png)

(4).![](media/A58.png)

(5).![](media/A59.png)

(6).![](media/A60.png)

**Código Completo de Prueba**

![](media/A61.png)

### **5.Resultado de la Prueba**

Después de subir correctamente el código a la placa V4.0, conecta las conexiones según el diagrama de conexiones y usa un cable USB para conectar la computadora y alimentar la placa. Al encender, verás que el LED cambia gradualmente de brillante a oscuro, como la respiración humana, en lugar de encenderse y apagarse inmediatamente.

### **6.Práctica de Extensión**

Mantén los pines del LED sin cambios, luego cambia el código (valores detrás de wait)

![](media/A62.png)

Sube el código a la placa de desarrollo, luego el LED parpadeará más lentamente.