# Projekt 8 Motorsteuerung und Geschwindigkeitsregelung

![image-20250510090044895](media/A77.png)

### **1. Beschreibung**

Es gibt viele Möglichkeiten, Motoren anzusteuern. Unser Auto verwendet den am häufigsten eingesetzten DRV8833 Motor-Treiberchip, der eine zweikanalige Brückenantriebslösung für Spielzeuge, Drucker und andere integrierte Motoranwendungen bietet.

Wenn wir das Shield auf das 4.0 Entwicklungsboard stecken und die BAT einschalten, dann den DIP-Schalter auf die ON-Seite stellen, wird die externe Stromversorgung beide Boards gleichzeitig mit Strom versorgen. Zur Erleichterung der Verkabelung verfügt das Shield über einen Verpolungsschutzanschluss (PH2.0-2P-3P-4P-5P). Sie können die Motoren, die Stromversorgung und Sensormodule direkt an das Shield anschließen.

Die Bluetooth-Schnittstelle des Shields ist vollständig kompatibel mit dem DX-BT24 5.1 Bluetooth-Modul. Beim Anschluss des Bluetooth-Moduls müssen Sie es nur in die entsprechende Schnittstelle stecken. Gleichzeitig werden 2,54 mm Stiftleisten verwendet, um einige ungenutzte digitale und analoge Ports auf dem Shield herauszuführen, sodass Sie weitere Sensoren hinzufügen und Erweiterungsexperimente durchführen können.

Das Erweiterungsboard kann an vier Gleichstrommotoren angeschlossen werden. Wenn die Jumperkappe standardmäßig verbunden ist, sind die Motoren der Ports A und A1 sowie B und B1 parallel geschaltet und haben das gleiche Bewegungsverhalten. 8 Jumperkappen können verwendet werden, um die Drehrichtung der 4 Motoranschlüsse zu steuern.

Zum Beispiel, wenn die 2 Jumperkappen vor B1 des M1-Motors von Quer- auf Längsverbindung geändert werden, wird sich die Drehrichtung des M1-Motors gegenüber der ursprünglichen Drehrichtung umkehren.

### **2. Spezifikation**

- Eingangsspannung für Logik: DC 5V

- Eingangsspannung für Antrieb: DC 6-9 V

- Betriebsstrom für Logik: \<36mA

- Betriebsstrom für Antrieb: \<2A

- Maximale Verlustleistung: 25W (T=75℃)

- Eingangspegel für Steuersignal: High-Pegel ist 2,3V\<Vin\<5V, Low-Pegel ist -0,3V\<Vin\<1,5V

- Betriebstemperatur: -25 bis +130℃

**Keyestudio 8833 Motor-Treiber-Erweiterungsboard**

![image-20250510090404192](media/A78.png)

### **3. Funktionsprinzip**

Wir verwenden für die vier Motoren die gleiche Seiten-Parallelverbindung, die als zwei Motorgruppen betrachtet werden kann. Wie im Schaltplan gezeigt, sind B und B1 eine Gruppe, und A und A1 eine Gruppe.

Die Motoren in derselben Gruppe sollten sich in die gleiche Richtung drehen. Wenn sie unterschiedlich sind, passen Sie bitte die entsprechenden Jumperkappen neben dem Anschluss an, um die Richtung zu ändern.

Wie unten gezeigt, wenn die Richtungen von A und A1 unterschiedlich sind, stellen Sie die Richtung der Jumperkappen so ein, bis die Bewegungsrichtung der Motoren in derselben Gruppe übereinstimmt.

![image-20250510090532851](media/A79.png)

Aus dem obigen Diagramm ist ersichtlich, dass der Richtungs-Pin des A-Motors D4 ist, der Geschwindigkeits-Pin D6; D2 ist der Richtungs-Pin des B-Motors; und D6 ist der Geschwindigkeits-Pin.

<span style="color:red;">PWM steuert das Roboterauto. Der PWM-Wert liegt im Bereich von 0-255. Wenn wir die Richtung auf HIGH setzen, gilt: Je kleiner die PWM-Zahl, desto schneller dreht sich der Motor.</span>

|            | D2   | D5（PWM） | B Motor (links)       | D4   | D6（PWM） | A Motor (rechts)      |
| ---------- | ---- | --------- | --------------------- | ---- | --------- | --------------------- |
| Vorwärts   | HIGH | 255-200   | Dreht im Uhrzeigersinn | HIGH | 255-200   | Dreht im Uhrzeigersinn |
| Rückwärts  | LOW  | 200       | Dreht gegen den Uhrzeigersinn | LOW  | 200       | Dreht gegen den Uhrzeigersinn |
| Links abbiegen | HIGH | 255-200   | Dreht im Uhrzeigersinn | LOW  | 200       | Dreht gegen den Uhrzeigersinn |
| Rechts abbiegen | LOW  | 200       | Dreht gegen den Uhrzeigersinn | HIGH | 255-200   | Dreht im Uhrzeigersinn |

### **4. Komponenten**

| Development Board *1      | 8833 Motor Driver *1      | USB-Kabel*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A80.jpg) | ![img](media/A81.jpg) | ![img](media/A82.jpg)         |
| 18650 Batteriehalter*1    | Motor*4                   | 18650 Batterie *2 (selbst bereitgestellt) |
| ![img](media/A83.png) | ![img](media/A84.jpg) | ![img](media/A85.png)         |

### **5. Schaltplan**

![image-20250510090733191](media/A86.png)

Verbinden Sie die Stromversorgung mit dem BAT-Anschluss.

### **6. Testcode**

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.1
 Motor driver shield
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //definiere die Richtungskontrollpins des Motors Gruppe B
#define ML_PWM 5   //definiere die PWM-Kontrollpins des Motors Gruppe B
#define MR_Ctrl 4    //definiere die Richtungskontrollpins des Motors Gruppe A
#define MR_PWM 6   //definiere die PWM-Kontrollpins des Motors Gruppe A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//setze Richtungskontrollpins des Motors Gruppe B als Ausgang
  pinMode(ML_PWM, OUTPUT);//setze PWM-Kontrollpins des Motors Gruppe B als Ausgang
  pinMode(MR_Ctrl, OUTPUT);//setze Richtungskontrollpins des Motors Gruppe A als Ausgang
  pinMode(MR_PWM, OUTPUT);//setze PWM-Kontrollpins des Motors Gruppe A als Ausgang
}
void loop()
{ 
  //vorwärts
  digitalWrite(ML_Ctrl,HIGH);//setze die Richtungskontrollpins des Motors Gruppe B auf HIGH
  analogWrite(ML_PWM,55);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe B auf 55
  digitalWrite(MR_Ctrl,HIGH);//setze die Richtungskontrollpins des Motors Gruppe A auf HIGH
  analogWrite(MR_PWM,55);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe A auf 55
  delay(2000);//Verzögerung von 2000ms
  //rückwärts
  digitalWrite(ML_Ctrl,LOW);//setze die Richtungskontrollpins des Motors Gruppe B auf LOW
  analogWrite(ML_PWM,200);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe B auf 200 
  digitalWrite(MR_Ctrl,LOW);//setze die Richtungskontrollpins des Motors Gruppe A auf LOW
  analogWrite(MR_PWM,200);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe A auf 200
  delay(2000);//Verzögerung von 2000ms
  //links
  digitalWrite(ML_Ctrl,LOW);//setze die Richtungskontrollpins des Motors Gruppe B auf LOW
  analogWrite(ML_PWM,200);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe B auf 200 
  digitalWrite(MR_Ctrl,HIGH);//setze die Richtungskontrollpins des Motors Gruppe A auf HIGH
  analogWrite(MR_PWM,55);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe A auf 55
  delay(2000);//Verzögerung von 2000ms
  //rechts
  digitalWrite(ML_Ctrl,HIGH);//setze die Richtungskontrollpins des Motors Gruppe B auf HIGH
  analogWrite(ML_PWM,55);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe B auf 55 
  digitalWrite(MR_Ctrl,LOW);//setze die Richtungskontrollpins des Motors Gruppe A auf LOW
  analogWrite(MR_PWM,200);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe A auf 200
  delay(2000);//Verzögerung von 2000ms
  //stop
  digitalWrite(ML_Ctrl, LOW);//setze die Richtungskontrollpins des Motors Gruppe B auf LOW
  analogWrite(ML_PWM,0);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe B auf 0
  digitalWrite(MR_Ctrl, LOW);//setze die Richtungskontrollpins des Motors Gruppe A auf LOW
  analogWrite(MR_PWM,0);//setze die PWM-Steuergeschwindigkeit des Motors Gruppe A auf 0
  delay(2000);//Verzögerung von 2000ms
}
//****************************************************************************
```

### **7. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten dann die externe Stromversorgung ein und stellen den DIP-Schalter auf ON. Das Auto fährt 2 Sekunden vorwärts, 2 Sekunden rückwärts, 2 Sekunden nach links, 2 Sekunden nach rechts und hält dann 2 Sekunden an.

### **8. Code-Erklärung**

**digitalWrite(ML\_Ctrl,LOW):** Die Drehrichtung des Motors wird durch den HIGH/LOW-Pegel bestimmt, und die Pins, die die Drehrichtung bestimmen, sind digitale Pins.

**analogWrite(ML\_PWM,200):** Die Geschwindigkeit des Motors wird durch PWM geregelt, und die Pins, die die Geschwindigkeit des Motors bestimmen, müssen PWM-Pins sein.

### **9. Code-Erklärung**

Stellen Sie die Geschwindigkeit ein, mit der PWM den Motor steuert, und schließen Sie ihn auf die gleiche Weise an.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.2
 Motor driver
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //definiere die Richtungskontrollpins des Motors der Gruppe B
#define ML_PWM 5   //definiere die PWM-Steuerpins des Motors der Gruppe B
#define MR_Ctrl 4    //definiere die Richtungskontrollpins des Motors der Gruppe A
#define MR_PWM 6   //definiere die PWM-Steuerpins des Motors der Gruppe A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//setze die Richtungskontrollpins des Motors der Gruppe B auf Ausgang
  pinMode(ML_PWM, OUTPUT);//setze die PWM-Steuerpins des Motors der Gruppe B auf Ausgang
  pinMode(MR_Ctrl, OUTPUT);//setze die Richtungskontrollpins des Motors der Gruppe A auf Ausgang
  pinMode(MR_PWM, OUTPUT);//setze die PWM-Steuerpins des Motors der Gruppe A auf Ausgang
}
void loop()
{ 
  //vorwärts
  digitalWrite(ML_Ctrl,HIGH);//setze die Richtungskontrollpins des Motors der Gruppe B auf HIGH
  analogWrite(ML_PWM,105);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe B auf 55
  digitalWrite(MR_Ctrl,HIGH);//setze die Richtungskontrollpins des Motors der Gruppe A auf HIGH
  analogWrite(MR_PWM,105);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe A auf 55
  delay(2000);//Verzögerung um 2000ms
  //rückwärts
  digitalWrite(ML_Ctrl,LOW);//setze die Richtungskontrollpins des Motors der Gruppe B auf LOW
  analogWrite(ML_PWM,150);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe B auf 200 
  digitalWrite(MR_Ctrl,LOW);//setze die Richtungskontrollpins des Motors der Gruppe A auf LOW
  analogWrite(MR_PWM,150);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe A auf 200
  delay(2000);//Verzögerung um 2000ms
  //links
  digitalWrite(ML_Ctrl,LOW);//setze die Richtungskontrollpins des Motors der Gruppe B auf LOW
  analogWrite(ML_PWM,150);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe B auf 200 
  digitalWrite(MR_Ctrl,HIGH);//setze die Richtungskontrollpins des Motors der Gruppe A auf HIGH
  analogWrite(MR_PWM,105);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe A auf 200
  delay(2000);//Verzögerung um 2000ms
  //rechts
  digitalWrite(ML_Ctrl,HIGH);//setze die Richtungskontrollpins des Motors der Gruppe B auf HIGH
  analogWrite(ML_PWM,105);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe B auf 55 
  digitalWrite(MR_Ctrl,LOW);//setze die Richtungskontrollpins des Motors der Gruppe A auf LOW
  analogWrite(MR_PWM,150);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe A auf 200
  delay(2000);//Verzögerung um 2000ms
  //stop
  digitalWrite(ML_Ctrl, LOW);//setze die Richtungskontrollpins des Motors der Gruppe B auf LOW
  analogWrite(ML_PWM,0);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe B auf 0
  digitalWrite(MR_Ctrl, LOW);//setze die Richtungskontrollpins des Motors der Gruppe A auf LOW
  analogWrite(MR_PWM,0);//setze die PWM-Steuerungsgeschwindigkeit des Motors der Gruppe A auf 0
  delay(2000);//Verzögerung um 2000ms
}
//************************************************************************
```

Nachdem der Code erfolgreich auf die V4.0-Platine hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie dann die externe Stromversorgung ein und stellen Sie den DIP-Schalter auf ON, dann werden Sie feststellen, dass die Geschwindigkeit des Motors viel langsamer ist.

<span style="color: rgb(255, 76, 65);">Hinweis: Eine niedrige Batteriespannung führt zu einer langsamen Motordrehzahl.</span> 