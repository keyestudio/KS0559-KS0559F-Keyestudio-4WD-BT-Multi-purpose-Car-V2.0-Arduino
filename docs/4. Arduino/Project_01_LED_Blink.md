# Proyecto 1: Parpadeo de LED

### **1.Descripción**

![image-20250508161034535](media/A6.png)

Para principiantes y entusiastas, el parpadeo de LED es un programa fundamental. LED, la abreviatura de diodos emisores de luz, está compuesto por compuestos químicos como Ga, As, P, N, entre otros.

El LED puede parpadear en diversos colores al alterar el tiempo de retardo en el código de prueba. Cuando está bajo control, con alimentación en GND y VCC, el LED se encenderá si el extremo S está en nivel alto, de lo contrario se apagará.

### **2.Especificaciones**

- Interfaz de control: puerto digital

- Voltaje de trabajo: DC 3.3-5V

- Espaciado de pines: 2.54mm

- Color de visualización del LED: rojo

![image-20250508161015086](media/A7.png)

### **3.Componentes**

|           Placa de Desarrollo *1           |           Driver de Motor 8833 *1           |     Módulo LED Rojo*1     |
| :----------------------------------------: | :-----------------------------------------: | :-----------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             Cable Dupont 3P *1             |               Cable USB *1                   |                           |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                           |

### **4.Diagrama de Conexiones**

![image-20250508161123490](media/A13.png)

Como se puede ver en la figura anterior, el Shield de motor Keyestudio 8833 está apilado sobre la placa de desarrollo Keyestudio 4.0.

Los pines G, V y S del módulo LED están conectados respectivamente a G, 5V y D9 de la placa de expansión.

### **5.Código de Prueba**

```c 
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 1.1
Blink
http://www.keyestudio.com
*/
void setup()
{ 
  pinMode(9, OUTPUT);// inicializa el pin digital 9 como salida.
}
    
void loop() // la función loop se ejecuta una y otra vez para siempre
{  
  digitalWrite(9, HIGH); // enciende el LED (HIGH es el nivel de voltaje)
   delay(1000); // espera un segundo
   digitalWrite(9, LOW); // apaga el LED poniendo el voltaje en LOW
   delay(1000); // espera un segundo
}
//****************************************************************************
```

### **6.Resultado de la Prueba**

Después de subir con éxito el código a la placa V4.0, conecta los cables según el diagrama de conexiones y usa un cable USB para conectar la computadora y alimentar la placa. Al encender, verás que el LED conectado al D9 se enciende y apaga.

### **7.Explicación del Código**

pinMode(9，OUTPUT) - Esta función indica que el pin es ENTRADA o SALIDA

digitalWrite(9，HIGH) - Cuando el pin es SALIDA, podemos configurarlo en HIGH (salida 5V) o LOW (salida 0V)

### **8.Práctica de Extensión**

Hemos logrado hacer parpadear el LED. Ahora, observemos qué sucede con el LED si modificamos el tiempo de retardo.

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 1.2
 delay
 http://www.keyestudio.com
*/
void setup()
{  
  // inicializa el pin digital 11 como salida.
  pinMode(9, OUTPUT);
}
// la función loop se ejecuta una y otra vez para siempre
void loop()
{ 
  digitalWrite(9, HIGH); // enciende el LED (HIGH es el nivel de voltaje)
  delay(100); // espera 0.1 segundo
  digitalWrite(9, LOW); // apaga el LED poniendo el voltaje en LOW
  delay(100); // espera 0.1 segundo
}
//*****************************************************************
```

El resultado de la prueba muestra que el LED parpadea más rápido. Por lo tanto, el tiempo de retardo afecta la frecuencia de parpadeo del LED.