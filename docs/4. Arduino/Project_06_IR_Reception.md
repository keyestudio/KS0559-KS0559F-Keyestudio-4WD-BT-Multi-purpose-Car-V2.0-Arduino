# Proyecto 6 Recepción IR

![9681c7da-a7c9-49ed-ad8c-32e00c6aeb07](media/A42.png)

### **1. Descripción**

No hay duda de que el control remoto infrarrojo es omnipresente en la vida diaria. Se utiliza para controlar varios electrodomésticos, como televisores, estéreos, grabadoras de video y receptores de señal satelital. El control remoto infrarrojo está compuesto por sistemas de transmisión y recepción infrarroja, es decir, un control remoto infrarrojo y un módulo receptor infrarrojo junto con un microcontrolador capaz de decodificar.

![image-20250509154423060](media/A43.png)

La señal portadora infrarroja de 38K emitida por el control remoto es codificada por el chip de codificación en el control remoto. Está compuesta por una sección de código piloto, código de usuario, código inverso de usuario, código de datos y código inverso de datos. El intervalo de tiempo del pulso se usa para distinguir si es una señal 0 o 1 y la codificación está formada por estas señales 0 y 1.

El código de usuario del mismo control remoto es constante mientras que el código de datos puede distinguir la tecla.

Cuando se presiona un botón del control remoto, este envía una señal portadora infrarroja. Cuando el receptor IR recibe la señal, el programa decodifica la señal portadora y determina qué tecla fue presionada. El MCU decodifica la señal 01 recibida, juzgando así qué tecla fue presionada en el control remoto.

El receptor infrarrojo que usamos es un módulo receptor infrarrojo. Está compuesto principalmente por una cabeza receptora infrarroja, que es un dispositivo que integra recepción, amplificación y demodulación. Su IC interno ha completado la demodulación y puede lograr desde la recepción infrarroja hasta la salida, siendo compatible con señales TTL.

Además, es adecuado para control remoto infrarrojo y transmisión de datos infrarrojos. El módulo receptor infrarrojo fabricado por el receptor tiene solo tres pines: línea de señal, VCC y GND. Es muy conveniente para comunicarse con Arduino y otros microcontroladores.

### **2. Especificaciones**

- Voltaje de operación: 3.3-5V (DC)
- Señal de salida: Señal digital
- Ángulo de recepción: 90 grados
- Frecuencia: 38 kHz
- Distancia de recepción: 10 m

La imagen muestra el producto real y el diagrama del circuito del receptor infrarrojo.

![image-20250510082651985](media/A44.png)

### **3. Componentes**

|           Placa de desarrollo *1           |           Driver de motor 8833 *1           |     Módulo LED rojo *1     |
| :----------------------------------------: | :-----------------------------------------: | :------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             Cable Dupont 3P *1             |               Cable USB *1                   |                            |
|         ![img](media/A11.jpg)               |         ![img](media/A12.jpg)                |                            |

Dado que la placa 8833 integra el receptor IR, no necesita cableado adicional. Los pines del módulo receptor IR son G (GND), V (VCC) y D3.

### **4. Código de prueba**

```c
//*************************************************************************************
/*
 keyestudio 4wd BT Car
 lección 6.1
 Control remoto IR
 http://www.keyestudio.com
*/ 
#include <IRremote.h>     // Declaración de la librería IRremote  
int RECV_PIN = 3;        // definir el pin del receptor IR como D3
IRrecv irrecv(RECV_PIN);   
decode_results results;   // los resultados decodificados existen en “results” de “decode_results”
void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Habilitar receptor 
}  
  
 void loop() {  
  if (irrecv.decode(&results))// decodificación exitosa, recibe un conjunto de señales infrarrojas  
   {  
     Serial.println(results.value, HEX);// Imprime el valor en hexadecimal de 16 bits y recibe el código 
     irrecv.resume(); // Recibe el siguiente valor
   }  
   delay(100);  
 } 
//*************************************************************************************
```

### **5. Resultado de la prueba**

Después de cargar con éxito el código en la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, abre el monitor serial y configura la velocidad en baudios a 9600.

Saca el control remoto y envía la señal al sensor receptor infrarrojo. Puedes ver el valor de la tecla correspondiente; si el tiempo de pulsación es demasiado largo, FFFFFFFF tiende a mostrar caracteres corruptos.

![image-20250510082931375](media/A45.png)

Los valores de las teclas del control remoto Keyestudio se muestran a continuación.

![image-20250510082942450](media/A46.png)

### **6. Explicación del Código**

**irrecv.enableIRIn():** Después de habilitar la decodificación IR, se recibirán las señales IR,

**decode():** La función “decode()” verificará continuamente para asegurarse de si la decodificación fue exitosa.

**irrecv.decode(\&results):** después de decodificar con éxito, esta función devolverá “true” y guardará el resultado en “results”. Después de decodificar las señales IR, ejecuta la función resume() y continúa recibiendo la siguiente señal.

**7. Práctica de Extensión**

Hemos decodificado el valor de la tecla del control remoto IR. ¿Qué tal controlar un LED con el valor medido? Podríamos diseñar un experimento.

Conecta un LED al pin D9, luego presiona las teclas del control remoto para encender y apagar el LED.

![image-20250508161123490](media/A13.png)

```c
//*************************************************************************************
/* 
keyestudio 4wd BT Car
lesson 6.2
IR remote LED
http://www.keyestudio.com
*/ 
#include <IRremote.h>
int RECV_PIN = 3;//define el pin del receptor IR como D3
int LED_PIN = 9;//define el pin del LED como pin 9
int a=0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{Serial.begin(9600);
  irrecv.enableIRIn(); //Inicializa el receptor IR
  pinMode(LED_PIN,OUTPUT);//configura el pin 9 del LED como OUTPUT
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    if(results.value==0xFF02FD && (a==0)) //según el valor de la tecla anterior, al presionar “OK” en el control remoto, se controlará el LED
    {
      Serial.println("HIGH");
      digitalWrite(LED_PIN,HIGH);//el LED se encenderá
      a=1;
    }
    else if(results.value==0xFF02FD && (a==1)) //presiona de nuevo
    {
      Serial.println("LOW");
      digitalWrite(LED_PIN,LOW);//el LED se apagará
      a=0;
    }
    irrecv.resume(); // recibe el siguiente valor
  }
}
//*************************************************************************************
```

Después de cargar con éxito el código en la placa V4.0, conecta los cables según el diagrama de conexiones, luego conecta la computadora mediante un cable USB para alimentar la placa. Después de encenderla, presionar la tecla "**OK**" en el control remoto puede hacer que el LED se encienda y apague.