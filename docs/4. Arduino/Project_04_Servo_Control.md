# Projekt 4 Servo Steuerung

### **1. Beschreibung**

![image-20250509084654137](media/A25.png)

Ein Servomotor ist ein positionsgesteuerter Drehaktuator. Er besteht hauptsächlich aus einem Gehäuse, einer Leiterplatte, einem kernlosen Motor, einem Getriebe und einem Positionssensor. Sein Funktionsprinzip besteht darin, dass der Servo das von MCUs oder Empfängern gesendete Signal empfängt und ein Referenzsignal mit einer Periode von 20 ms und einer Breite von 1,5 ms erzeugt, dann die erfasste Gleichspannungs-Vorspannung mit der Spannung des Potentiometers vergleicht und die Spannungsdifferenz ausgibt.

![image-20250509084710719](media/A26.png)

Im Allgemeinen hat ein Servo drei Leitungen in Braun, Rot und Orange. Die braune Leitung ist Masse, die rote ist die Plusleitung und die orange ist die Signalleitung.

Der Drehwinkel des Servomotors wird durch Regulierung des Tastverhältnisses des PWM (Pulsweitenmodulation)-Signals gesteuert. Die Standardperiode des PWM-Signals beträgt 20 ms (50 Hz). Theoretisch liegt die Pulsbreite zwischen 1 ms und 2 ms, tatsächlich jedoch zwischen 0,5 ms und 2,5 ms. Die Breite entspricht dem Drehwinkel von 0° bis 180°. Beachten Sie jedoch, dass bei Motoren verschiedener Marken dasselbe Signal unterschiedliche Drehwinkel bewirken kann.

![image-20250509084727797](media/A27.png)

Die entsprechenden Servo-Winkel sind unten dargestellt:

![image-20250509084739380](media/A28.png)

### **2. Spezifikation**

- Betriebsspannung: DC 4,8 V \~ 6 V

- Betriebswinkelbereich: ca. 180 ° (bei 500 → 2500 μs)

- Pulsbreitenbereich: 500 → 2500 μs

- Leerlaufdrehzahl: 0,12 ± 0,01 s / 60 (DC 4,8 V) 0,1 ± 0,01 s / 60 (DC 6 V)

- Leerlaufstrom: 200 ± 20 mA (DC 4,8 V) 220 ± 20 mA (DC 6 V)

- Haltemoment: 1,3 ± 0,01 kg·cm (DC 4,8 V) 1,5 ± 0,1 kg·cm (DC 6 V)

- Haltestrom: ≦ 850 mA (DC 4,8 V) ≦ 1000 mA (DC 6 V)

- Standby-Strom: 3 ± 1 mA (DC 4,8 V) 4 ± 1 mA (DC 6 V)

### **3. Komponenten**

|                     Entwicklungsboard *1                     |           8833 Motor Driver *1           |                           Servo*1                            |
| :----------------------------------------------------------: | :--------------------------------------: | :----------------------------------------------------------: |
|           ![img](media/A8.jpg)           | ![img](media/A9.jpg) | ![image-20250509084654137](media/A25.png) |
|                    18650 Batteriehalter*1                    |               USB-Kabel*1                |               18650 Batterie*2 (selbst bereitgestellt)       |
| ![image-20250509084950601](media/A29.png) |         ![img](media/A12.jpg)         | ![image-20250509085010348](media/A30.png) |

### **4. Schaltplan**

![image-20250509085038006](media/A31.png)

Anschluss-Hinweis: Der Servo ist mit G (GND), V (VCC) und A3 verbunden, die braune Leitung des Servos ist mit GND (G) verbunden, die rote mit 5 V (V) und die orange mit A3.

Der Servo muss aufgrund seines hohen Strombedarfs an eine externe Stromversorgung angeschlossen werden. In der Regel reicht der Strom des Entwicklungsboards nicht aus. Wird keine externe Stromversorgung angeschlossen, kann das Entwicklungsboard beschädigt werden.

### **5. Testcode**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 4.1
Servo
http://www.keyestudio.com
*/
#define servoPin A3  // Servo-Pin
int pos; // Winkelvariable des Servos
int pulsewidth; // Pulsbreitenvariable des Servos

void setup() {
  pinMode(servoPin, OUTPUT);  // Setze den Pin des Servos auf Ausgang
  procedure(0); // Setze den Winkel des Servos auf 0 Grad
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // geht von 0 Grad bis 180 Grad
    // in Schritten von 1 Grad
    procedure(pos);              // sagt dem Servo, zur Position im Variablen 'pos' zu gehen
    delay(15);                   // steuert die Drehgeschwindigkeit des Servos
  }
  for (pos = 180; pos >= 0; pos -= 1) { // geht von 180 Grad bis 0 Grad
    procedure(pos);              // sagt dem Servo, zur Position im Variablen 'pos' zu gehen
    delay(15);                    
  }
}

// Funktion zur Steuerung des Servos
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  // berechnet den Wert der Pulsbreite
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);   // Die Dauer des High-Levels ist die Pulsbreite
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));  // der Zyklus beträgt 20 ms, das Low-Level dauert die restliche Zeit
}
//****************************************************************************
```

### **6. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board, verbinden Sie die Verkabelung gemäß dem Schaltplan und schalten Sie die externe Stromversorgung ein. Nach dem Einschalten drehen Sie den Dip-Schalter auf die "ON"-Position, dann schwingt der Servo im Bereich von 0° bis 180°.

### **7. Erweiterte Übung**

Außerdem ermöglichen wir die Steuerung des Servos über eine Bibliotheksdatei. Bitte beachten Sie den Link: [https://www.arduino.cc/en/Reference/Servo](https://www.arduino.cc/en/Reference/Servo).

![image-20250509085122183](media/A32.png)

```c

//***************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 4.2
 Servo
 http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo;  // erstellt ein Servo-Objekt zur Steuerung eines Servos
// auf den meisten Boards können zwölf Servo-Objekte erstellt werden
int pos = 0;    // Variable zur Speicherung der Servo-Position

void setup() {
  myservo.attach(A3);  // verbindet den Servo an Pin A3 mit dem Servo-Objekt
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // geht von 0 Grad bis 180 Grad
    // in Schritten von 1 Grad
    myservo.write(pos);              // sagt dem Servo, zur Position im Variablen 'pos' zu gehen
    delay(15);                       // wartet 15 ms, damit der Servo die Position erreicht
  }
  for (pos = 180; pos >= 0; pos -= 1) { // geht von 180 Grad bis 0 Grad
    myservo.write(pos);              // sagt dem Servo, zur Position im Variablen 'pos' zu gehen
    delay(15);                       // wartet 15 ms, damit der Servo die Position erreicht
  }
}
//***************************************************************************
```

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board, verbinden Sie die Verkabelung gemäß dem Schaltplan und schalten Sie die externe Stromversorgung ein. Nach dem Einschalten drehen Sie den Dip-Schalter auf die "ON"-Position, dann schwingt der Servo ebenfalls im Bereich von 0° bis 180°. Üblicherweise steuern wir ihn über die Bibliotheksdatei.

### **8. Code-Erklärung**

Arduino enthält **\#include \<Servo.h\>** (Servo-Funktion und Anweisungen)

Die folgenden sind einige gängige Anweisungen der Servo-Funktion:

1). **attach(interface)** —— Setzt die Schnittstelle des Servos

2). **write(angle)** —— Wird verwendet, um den Drehwinkel des Servos einzustellen, der Einstellbereich liegt zwischen 0° und 180°

3). **read()** —— Wird verwendet, um den Winkel des Servos auszulesen, also den Befehlswert von „write()“

4). **attached()** —— Prüft, ob der Parameter des Servos an seine Schnittstelle gesendet wurde

<span style="color: rgb(255, 76, 65);">Hinweis:</span> Das oben geschriebene Format lautet „Servo-Variablenname, spezifische Anweisung()“, zum Beispiel: myservo.attach(9).