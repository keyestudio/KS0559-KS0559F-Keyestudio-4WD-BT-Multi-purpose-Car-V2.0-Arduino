# Projekt 6 IR-Empfang

![9681c7da-a7c9-49ed-ad8c-32e00c6aeb07](media/A42.png)

### **1. Beschreibung** 

Es besteht kein Zweifel, dass Infrarot-Fernbedienungen im täglichen Leben allgegenwärtig sind. Sie werden verwendet, um verschiedene Haushaltsgeräte zu steuern, wie Fernseher, Stereoanlagen, Videorekorder und Satellitensignalempfänger. Die Infrarot-Fernbedienung besteht aus einem Infrarot-Sende- und einem Infrarot-Empfangssystem, das heißt einer Infrarot-Fernbedienung und einem Infrarot-Empfangsmodul sowie einem Mikrocontroller, der in der Lage ist, die Signale zu dekodieren.  

![image-20250509154423060](media/A43.png)

Das 38K Infrarot-Trägersignal, das vom Fernbediener ausgesendet wird, wird vom Kodierungschip im Fernbediener codiert. Es besteht aus einem Abschnitt Pilotcode, Benutzercode, Benutzer-Inverscode, Daten-Code und Daten-Inverscode. Das Zeitintervall des Pulses wird verwendet, um zu unterscheiden, ob es sich um ein 0- oder 1-Signal handelt, und die Kodierung besteht aus diesen 0- und 1-Signalen.

Der Benutzercode derselben Fernbedienung ist konstant, während der Daten-Code die Taste unterscheidet.

Wenn die Fernbedienungstaste gedrückt wird, sendet die Fernbedienung ein Infrarot-Trägersignal aus. Wenn der IR-Empfänger das Signal empfängt, dekodiert das Programm das Trägersignal und bestimmt, welche Taste gedrückt wurde. Der MCU dekodiert das empfangene 01-Signal und erkennt so, welche Taste von der Fernbedienung gedrückt wurde.

Der von uns verwendete Infrarot-Empfänger ist ein Infrarot-Empfangsmodul. Es besteht hauptsächlich aus einem Infrarot-Empfängerkopf, einem Gerät, das Empfang, Verstärkung und Demodulation integriert. Sein interner IC hat die Demodulation abgeschlossen und kann vom Infrarot-Empfang bis zur Ausgabe arbeiten und ist mit TTL-Signalen kompatibel.

Außerdem ist es geeignet für Infrarot-Fernbedienungen und Infrarot-Datenübertragung. Das vom Empfänger hergestellte Infrarot-Empfangsmodul hat nur drei Pins: Signalleitung, VCC und GND. Es ist sehr bequem, mit Arduino und anderen Mikrocontrollern zu kommunizieren.

### **2. Spezifikation**

- Betriebsspannung: 3,3-5V (DC)

- Ausgangssignal: Digitalsignal

- Empfangswinkel: 90 Grad

- Frequenz: 38 kHz

- Empfangsreichweite: 10 m

Das Bild zeigt das reale Produkt und den Schaltplan des Infrarot-Empfängers.

![image-20250510082651985](media/A44.png)

### **3. Komponenten**

|           Entwicklungsboard *1           |           8833 Motor Driver *1           |     Rotes LED-Modul *1     |
| :--------------------------------------: | :--------------------------------------: | :------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             3P Dupont Kabel *1             |               USB-Kabel *1                |                            |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                            |

Da das 8833 Board den IR-Empfänger integriert hat, ist keine Verkabelung erforderlich. Die Pins des IR-Empfängermoduls sind G (GND), V (VCC) und D3.

### **4. Testcode**

```c
//*************************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 6.1
 IR remote
 http://www.keyestudio.com
*/ 
#include <IRremote.h>     // IRremote Bibliothek einbinden  
int RECV_PIN = 3;        // Definiere den Pin des IR-Empfängers als D3
IRrecv irrecv(RECV_PIN);   
decode_results results;   // Dekodierungsergebnisse befinden sich in „results“ vom Typ „decode_results“
void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Empfänger aktivieren
}  
  
 void loop() {  
  if (irrecv.decode(&results)) // Erfolgreich dekodiert, ein Satz von Infrarotsignalen empfangen  
   {  
     Serial.println(results.value, HEX); // Ausgabe des Codes im 16er HEX-Format 
     irrecv.resume(); // Empfang des nächsten Wertes
   }  
   delay(100);  
 } 
//*************************************************************************************
```

### **5. Testergebnis**

Nach dem erfolgreichen Hochladen des Codes auf das V4.0-Board verbinden Sie die Verkabelung gemäß dem Schaltplan und schließen dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten öffnen Sie den seriellen Monitor und stellen die Baudrate auf 9600 ein.

Nehmen Sie die Fernbedienung heraus und senden Sie ein Signal an den Infrarot-Empfängersensor. Sie können den Tastwert der entsprechenden Taste sehen. Wenn die Tastzeit zu lang ist, neigt FFFFFFFF zu fehlerhaften Zeichen.

![image-20250510082931375](media/A45.png)

Die Tastwerte der Keyestudio-Fernbedienung sind unten dargestellt.

![image-20250510082942450](media/A46.png)

### **6. Code-Erklärung**

**irrecv.enableIRIn():** Nach dem Aktivieren der IR-Dekodierung werden die IR-Signale empfangen,

**decode():** Die Funktion „decode()“ überprüft kontinuierlich, ob die Dekodierung erfolgreich war.

**irrecv.decode(\&results):** Nach erfolgreicher Dekodierung gibt diese Funktion „true“ zurück und speichert das Ergebnis in „results“. Nach der Dekodierung der IR-Signale wird die Funktion resume() ausgeführt und der nächste Signalempfang fortgesetzt.

### **7. Erweiterte Übung**

Wir haben den Tastwert der IR-Fernbedienung dekodiert. Wie wäre es damit, die LED mit dem gemessenen Wert zu steuern? Wir könnten ein Experiment entwerfen.

Schließen Sie eine LED an D9 an und drücken Sie dann die Tasten der Fernbedienung, um die LED ein- und auszuschalten.

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
int RECV_PIN = 3;//definiere den Pin des IR-Empfängers als D3
int LED_PIN = 9;//definiere den Pin der LED als Pin 9
int a=0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{Serial.begin(9600);
  irrecv.enableIRIn(); //Initialisiere den IR-Empfänger
  pinMode(LED_PIN,OUTPUT);//setze Pin 9 der LED auf OUTPUT
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    if(results.value==0xFF02FD && (a==0)) //entsprechend dem obigen Tastwert, drücke „OK“ auf der Fernbedienung, LED wird gesteuert
    {
      Serial.println("HIGH");
      digitalWrite(LED_PIN,HIGH);//LED wird eingeschaltet
      a=1;
    }
    else if(results.value==0xFF02FD && (a==1)) //erneut drücken
    {
      Serial.println("LOW");
      digitalWrite(LED_PIN,LOW);//LED wird ausgeschaltet
      a=0;
    }
    irrecv.resume(); // empfange den nächsten Wert
  }
}
//*************************************************************************************
```

Nach dem erfolgreichen Hochladen des Codes auf das V4.0-Board verbinden Sie die Verkabelung gemäß dem Schaltplan und schließen dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten kann durch Drücken der "**OK**"-Taste auf der Fernbedienung die LED ein- und ausgeschaltet werden.