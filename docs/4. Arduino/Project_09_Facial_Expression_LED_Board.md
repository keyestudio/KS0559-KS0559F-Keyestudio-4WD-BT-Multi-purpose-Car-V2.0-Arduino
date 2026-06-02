# Proyecto 9 Tablero LED de Expresiones Faciales

![image-20250510090912741](media/A87.png)

### **1. Descripción**

Qué divertido sería si se añadiera un tablero de expresiones al robot. Y el tablero LED Keyestudio 8\*16 puede hacer el trabajo. Con su ayuda, podrías diseñar expresiones faciales, imágenes, patrones y otras visualizaciones por ti mismo.

El tablero LED 8\*16 viene con 128 LEDs. Los datos del microprocesador (Arduino) se comunican con el AiP1640 a través de una interfaz de bus de dos cables. Por lo tanto, puede controlar el encendido y apagado de los 128 LEDs en el módulo, para que la matriz de puntos en el módulo muestre el patrón que necesitas. Se proporciona un cable HX-2.54 de 4 pines para facilitar el cableado.

### **2. Especificaciones**

- Voltaje de trabajo: DC 3.3-5V

- Pérdida de potencia: 400mW

- Frecuencia de oscilación: 450KHz

- Corriente de conducción: 200mA

- Temperatura de trabajo: -40\~80℃

- Modo de comunicación: I2C

### **3. Diagrama del circuito**

![image-20250510091309725](media/A88.png)

### **4. Principio de funcionamiento**

¿Cómo controlar cada LED de la matriz de puntos 8\*16? Se sabe que cada byte tiene 8 bits y cada bit es 0 o 1. Cuando es 0, el LED está apagado, mientras que cuando es 1, el LED está encendido. Un byte puede controlar una columna del LED, y naturalmente 16 bytes pueden controlar 16 columnas de LEDs, esa es la matriz de puntos 8\*16.

### **5. Descripción de pines y protocolo de comunicación**

Los datos del microprocesador (Arduino) se comunican con el AiP1640 a través de un cable de bus de dos cables.

El diagrama del protocolo de comunicación es el siguiente (SCLK) es SCL, (DIN) es SDA.

![image-20250510091407219](media/A89.png)

① Condición de inicio para la entrada de datos: SCL está en nivel alto y SDA cambia de alto a bajo.

② Para la configuración del comando de datos, existen métodos como se muestra en la figura a continuación.

En nuestro programa de ejemplo, seleccionamos la forma de **sumar 1 a la dirección automáticamente**, el valor binario es 0100 0000 y el valor hexadecimal correspondiente es 0x40.

![Img](media/A90.png)

③ Para la configuración del comando de dirección, la dirección puede seleccionarse como se muestra a continuación.

Se selecciona el primer 00H en nuestro programa de ejemplo, y el número binario 1100 0000 corresponde al hexadecimal 0xc0.

![Img](media/A91.png)

④ El requisito para la entrada de datos es que cuando SCL está en nivel alto al ingresar datos, la señal en SDA debe permanecer sin cambios. Solo cuando la señal de reloj en SCL está en nivel bajo, la señal en SDA puede cambiarse. La entrada de datos es primero el bit bajo, y luego el bit alto.

⑤ La condición para el fin de la transmisión de datos es que cuando SCL está en nivel bajo, SDA en nivel bajo y SCL en nivel alto, el nivel de SDA se vuelve alto.

⑥ Control de visualización, configurar diferentes anchos de pulso, el ancho de pulso puede seleccionarse como se muestra en la figura a continuación.

En el ejemplo, el ancho de pulso es 4/16, y el hexadecimal correspondiente a 1000 1010 es 0x8A.

![Img](media/A92.png)

**Instrucciones para el uso de la herramienta de matriz**

La herramienta de matriz de puntos usa la versión en línea, y el enlace es: [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

① Ingresa al enlace y la página aparece como se muestra a continuación

![image-20250510091438524](media/A93.png)

② La matriz de puntos es 8\*16, así que ajusta la altura a 8 y el ancho a 16, como se muestra en la figura a continuación.

![image-20250510091446519](media/A94.png)

③ Generar datos hexadecimales a partir del patrón

Como se muestra en la figura a continuación, presiona el botón izquierdo del ratón para seleccionar, clic derecho para cancelar; dibuja el patrón que deseas, haz clic en Generar, y se generarán los datos hexadecimales que necesitamos.

![image-20250510091457463](media/A95.png)

### **6. Componentes**

| Placa de Desarrollo *1                                         | Driver de Motor 8833 *1                                         | Cable USB*1               |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------- |
| ![img](media/A80.jpg)                                    | ![img](media/A81.jpg)                                    | ![img](media/A82.jpg) |
| Cable USB*1                                                  | Cable Dupont HX-2.54 4P 200mm *1                              |                           |
| ![image-20250512155818434](media/A96.png) | ![image-20250512155822969](media/A97.png) |                           |

### **7.Diagrama de Conexiones**

![cec50fec4a335b6922e4c6694a133bc1](media/A98.png)

El GND, VCC, SDA y SCL de la placa de luces LED 8x16 están conectados respectivamente a la placa de expansión de sensores keyestudio-(GND), + (VCC), A4, A5 para comunicación serial de dos hilos.

(<span style="color: rgb(255, 76, 65);">Nota:</span> Aunque está conectado al pin IIC de Arduino, este módulo no es para comunicación IIC. Y el puerto IO aquí es para simular comunicación I2C y puede conectarse a cualquier dos pines).

### **8.Código de Prueba**  

El código mostrará la cara sonriente.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lesson 9.1
  Matrix face
  http://www.keyestudio.com
*/
//Datos del patrón de sonrisa obtenidos de la herramienta táctil
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};
#define SCL_Pin  A5  //Configurar el pin de reloj a A5
#define SDA_Pin  A4  //Configurar el pin de datos a A4
void setup() {
  //Configurar pin como salida
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //limpiar
  //matrix_display(clear);
}
void loop() {
  matrix_display(smile);  //mostrar patrón de expresión sonriente
}
//esta función se usa para la pantalla de matriz de puntos
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //función que llama a la condición de inicio de transferencia de datos
  IIC_send(0xc0);  //seleccionar dirección

  for (int i = 0; i < 16; i++) //los datos del patrón son 16 bytes
  {
    IIC_send(matrix_value[i]); //Transmitir los datos del patrón
  }
  IIC_end();   //Finalizar transmisión de datos del patrón
  IIC_start();
  IIC_send(0x8A);  //Control de pantalla, seleccionar ancho de pulso 4/16
  IIC_end();
}
//Condiciones bajo las cuales comienza la transmisión de datos
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Indica el fin de la transmisión de datos
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
//transmitir datos
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Cada byte tiene 8 bits y se verifica bit a bit comenzando por el menos significativo
  {
    if (send_data & mask) { //Configura los niveles alto y bajo de SDA_Pin dependiendo si cada bit del byte es 1 o 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Elevar el pin de reloj SCL_Pin para detener la transmisión de datos
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //bajar el pin de reloj SCL_Pin para cambiar la SEÑAL de SDA 
  }
}
//************************************************************************
```

### **9.Resultado de la Prueba**

Después de subir el código exitosamente a la placa V4.0, conecta los cables según el diagrama de conexiones, luego enciende el interruptor DIP a ON, se mostrará un patrón con forma de sonrisa en la placa LED.

![95bb011957896b12285fc6763137bb9a](media/A99.png)

### **10.Explicación del Código**

Usamos la herramienta de módulos que acabamos de aprender, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), para hacer que la matriz de puntos muestre el patrón de inicio, avanzar, detenerse y luego limpiar el patrón. El intervalo de tiempo es de 2000 ms.

![image-20250512155957415](media/A100.png)![image-20250512160002378](media/A101.png)![image-20250512160006841](media/A102.png)![image-20250512160010543](media/A103.png)

**Código obtenido de la herramienta de módulos：**

**Código para el patrón de inicio:**

0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01

**Código para el patrón de avance:**

0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Código para el patrón de retroceso:**

0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Código para el patrón de giro a la izquierda：**

0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00

**Código para el patrón de giro a la derecha：**

0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00

**Código para el patrón de parada：**

0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00

**Código para limpiar la pantalla：**

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

![cec50fec4a335b6922e4c6694a133bc1](media/A104.png)

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lección 9.2
  Cara de matriz
  http://www.keyestudio.com
*/
//Datos del patrón de sonrisa obtenidos de la herramienta táctil
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char front[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x12, 0x09, 0x12, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char back[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char left[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00};
unsigned char right[] = {0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char STOP01[] = {0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00};
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define SCL_Pin  A5  //Configurar el pin de reloj a A5
#define SDA_Pin  A4  //Configurar el pin de datos a A4
void setup() {
  //Configurar pin como salida
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //limpiar
  //matrix_display(clear);
}
void loop() {
    matrix_display(start01);  //Mostrar patrón de inicio
    delay(2000);
    matrix_display(front);    //Mostrar patrón de avance
    delay(2000);
    matrix_display(STOP01);   //Mostrar patrón de parada
    delay(2000);
    matrix_display(clear);    //Limpiar pantalla
    delay(2000);
}
//esta función se usa para mostrar en la matriz de puntos
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la función que llama a la condición de inicio de transferencia de datos
  IIC_send(0xc0);  //seleccionar dirección

for (int i = 0; i < 16; i++) // los datos del patrón son 16 bytes
{
  IIC_send(matrix_value[i]); // Transmitir los datos del patrón
}
IIC_end();   // Finalizar la transmisión de datos del patrón
IIC_start();
IIC_send(0x8A);  // Control de pantalla, seleccionar ancho de pulso 4/16
IIC_end();
}
// Condiciones bajo las cuales comienza la transmisión de datos
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
// Indica el fin de la transmisión de datos
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
// transmitir datos
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) // Cada byte tiene 8 bits y se verifica bit a bit comenzando por el menos significativo
  {
    if (send_data & mask) { // Establece los niveles alto y bajo de SDA_Pin dependiendo de si cada bit del byte es un 1 o un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); // Elevar el pin de reloj SCL_Pin para detener la transmisión de datos
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); // Bajar el pin de reloj SCL_Pin para cambiar la SEÑAL de SDA 
  }
}
//************************************************************************
```

Después de subir el código de prueba, la placa de expresión facial muestra estos patrones ordenadamente y repite esta secuencia.

![image-20250512160131674](media/A105.png)![image-20250512160135717](media/A106.png)![image-20250512160139283](media/A107.png)