# Proyecto 2: Ajustar el Brillo del LED

### **1.Descripción**

En la lección anterior, controlamos el encendido y apagado del LED y lo hicimos parpadear.

En este proyecto, controlaremos el brillo del LED mediante PWM simulando un efecto de respiración.

PWM es un medio para controlar la salida analógica mediante medios digitales. El control digital se utiliza para generar ondas cuadradas con diferentes ciclos de trabajo (una señal que cambia constantemente entre niveles alto y bajo) para controlar la salida analógica. En general, los voltajes de entrada de los puertos son 0V y 5V.

¿Qué pasa si se requiere 3V? ¿O un interruptor entre 1V, 3V y 3.5V? No podemos cambiar las resistencias constantemente. Por esta razón, recurrimos al PWM.

![bbcfcb9ae56abb7e80ee587246fc4be9](media/A14.gif)

Para la salida de voltaje del puerto digital de Arduino, solo existen LOW y HIGH, que corresponden a la salida de voltaje de 0V y 5V. Puedes definir LOW como 0 y HIGH como 1, y dejar que Arduino emita quinientas señales 0 o 1 dentro de 1s.

Si todas las quinientas salidas son 1, eso es 5V; si todas son 0, eso es 0V. Si se emite 010101010101 de esta manera, entonces el puerto de salida es 2.5V, lo que es como mostrar una película. La película que vemos no es completamente continua. En realidad, emite 25 imágenes por segundo. En este caso, el humano no puede verlo, ni tampoco el PWM. Si queremos un voltaje diferente, necesitamos controlar la proporción de 0 y 1. Cuantas más señales 0,1 se emitan por unidad de tiempo, más preciso será el control.

PWM es una tecnología que utiliza métodos digitales para obtener cantidades analógicas. El control digital permite formar una onda cuadrada, la señal de onda cuadrada solo tiene dos estados: encendido y apagado (alto y bajo). Un voltaje que varía de 0 a 5V puede simularse controlando la proporción de duración de encendido a apagado. El tiempo que dura encendido (técnicamente llamado nivel alto) se llama ancho de pulso, por lo que PWM también se llama modulación por ancho de pulso.

Las barras verticales verdes representan un período de la onda cuadrada. El valor escrito en cada analogWrite(value) corresponde a un porcentaje, que también se llama Ciclo de Trabajo (Duty Cycle). Este porcentaje se refiere a la proporción de tiempo ocupado por el nivel alto en un ciclo, es decir, ciclo de trabajo = tiempo de nivel alto / tiempo del ciclo.

En la figura, de arriba hacia abajo, el ciclo de trabajo de la primera onda cuadrada es 0%, y el valor correspondiente es 0, y el brillo del LED es el más bajo, es decir, estado apagado. Cuanto más tiempo dure el nivel alto, más brillante será. Por lo tanto, el valor del último ciclo de trabajo del 100% es 255, y el LED está en su máximo brillo. El 50% es la mitad del brillo máximo, y el 25% es más oscuro.

PWM se usa más para ajustar el brillo de luces LED o la velocidad de rotación de motores, y la velocidad de las ruedas impulsadas por los motores puede controlarse fácilmente. Al jugar con algunos robots Arduino, los beneficios del PWM se reflejan mejor.

### **2.Componentes**

|           Placa de Desarrollo *1           |           Driver de Motor 8833 *1           |     Módulo LED Rojo *1     |
| :-----------------------------------------: | :------------------------------------------: | :------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             Cable Dupont 3P *1              |               Cable USB *1                    |                            |
|         ![img](media/A11.jpg)               |         ![img](media/A12.jpg)                 |                            |

### **3.Diagrama de Conexiones**

Mantén las conexiones sin cambios.

![image-20250508161123490](media/A13.png)

### **4.Código de Prueba**

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.1
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Definir el pin del LED en D9
int value;

void setup () {
  pinMode (ledPin, OUTPUT); // inicializar ledPin como salida.
}


void loop () {
  for (value = 0; value <255; value = value + 1) 
  {
    analogWrite (ledPin, value); // El LED se enciende gradualmente
    delay (5); // retardo de 5 ms
  }
  for (value = 255; value> 0; value = value-1) 
  {
    analogWrite (ledPin, value); // El LED se apaga gradualmente
    delay (5); // retardo de 5 ms
  }
}
//*****************************************************************
```

### **5.Resultado de la Prueba**

Después de subir con éxito el código a la placa V4.0, conecta los cables según el diagrama de conexiones y usa un cable USB para conectar la computadora y alimentar la placa. Al encender, verás que el LED cambia gradualmente de brillante a oscuro, como la respiración humana, en lugar de encenderse y apagarse inmediatamente.

### **6.Explicación del Código**



Si necesitamos repetir una cierta instrucción, podemos usar la instrucción for.

El formato de la instrucción for se muestra a continuación:

![image-20250508162458776](media/A15.png)

Secuencia cíclica FOR:

Ronda 1：1 → 2 → 3 → 4

Ronda 2：2 → 3 → 4

…

Hasta que el número 2 no se cumpla, el bucle “for” termina,

Después de entender este orden, volvamos al código:

**for (int value = 0; value < 255; value=value+1)**

**for (int value = 255; value > 0; value=value-1)**

Las dos instrucciones “for” hacen que value aumente de 0 a 255, luego disminuya de 255 a 0, luego aumente a 255... en un bucle infinito.

Hay una función nueva en lo siguiente ----- analogWrite().

Sabemos que el puerto digital solo tiene dos estados: 0 y 1. Entonces, ¿cómo enviar un valor analógico a un valor digital? Aquí se necesita esta función. Observemos la placa Arduino y encontremos 6 pines marcados con “\~” que pueden emitir señales PWM.

El formato de la función es el siguiente:

**analogWrite(pin,value)**

analogWrite() se usa para escribir un valor analógico de 0~255 para el puerto PWM, por lo que el valor está en el rango de 0~255. Atención que solo puedes escribir en los pines digitales con función PWM, como los pines 3, 5, 6, 9, 10, 11.

PWM es una tecnología para obtener cantidad analógica mediante método digital. El control digital forma una onda cuadrada, y la señal de onda cuadrada solo tiene dos estados de encendido y apagado (es decir, niveles alto o bajo). Controlando la proporción del tiempo de encendido y apagado, se puede simular un voltaje que varía de 0 a 5V. El tiempo de encendido (académicamente llamado nivel alto) se llama ancho de pulso, por lo que PWM también se llama modulación por ancho de pulso.

A través de las siguientes cinco ondas cuadradas, aprendamos más sobre el PWM.

![image-20250508162529349](media/A16.png)

En la figura anterior, la línea verde representa un período, y el valor de analogWrite() corresponde a un porcentaje que también se llama Ciclo de Trabajo (Duty Cycle). El ciclo de trabajo implica la proporción de tiempo ocupado por el nivel alto en el ciclo. De arriba hacia abajo, el ciclo de trabajo de la primera onda cuadrada es 0% y su valor correspondiente es 0.

El brillo del LED es el más bajo, es decir, apagado. Cuanto más tiempo dure el nivel alto, más brillante será el LED. Por lo tanto, el último ciclo de trabajo es 100%, que corresponde a 255, y el LED es el más brillante. Y 50% es la mitad más brillante, 25% significa más oscuro.

PWM se usa más para ajustar el brillo del LED o la velocidad de rotación de motores.

Juega un papel vital en el control de autos robot inteligentes. Creo que no puedes esperar para aprender el siguiente proyecto.

### **7.Práctica de Extensión**

Modifiquemos el valor del retardo y mantengamos el pin sin cambios, luego observemos cómo cambia el LED.

```c
//***********************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.2
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Definir el pin del LED en D9
void setup () {
   pinMode(ledPin, OUTPUT); // inicializar ledPin como salida.
}

void loop () {
   for (int value = 0; value <255; value = value + 1) {
     analogWrite (ledPin, value); // El LED se enciende gradualmente
     delay (30); // retardo de 30 ms
   }
   for (int value = 255; value> 0; value = value-1) {
     analogWrite (ledPin, value); // El LED se apaga gradualmente
     delay (30); // retardo de 30 ms
   }
}
//***********************************************************
```

Sube el código a la placa de desarrollo, luego el LED parpadeará más lentamente.