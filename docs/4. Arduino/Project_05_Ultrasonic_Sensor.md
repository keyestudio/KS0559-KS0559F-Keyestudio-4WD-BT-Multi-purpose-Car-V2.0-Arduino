# Projekt 5 Ultraschallsensor

### **1. Beschreibung**

![image-20250509085643931](media/A33.png)

Der HC-SR04 Ultraschallsensor verwendet Sonar, um die Entfernung zu einem Objekt zu bestimmen, ähnlich wie Fledermäuse. Er bietet eine ausgezeichnete berührungslose Abstandserkennung mit hoher Genauigkeit und stabilen Messwerten in einem einfach zu verwendenden Paket. Er wird komplett mit einem Ultraschall-Sender- und Empfangsmodul geliefert.

![Img](media/A34.png)

Der HC-SR04 oder der Ultraschallsensor wird in einer Vielzahl von Elektronikprojekten verwendet, um Hinderniserkennung und Abstandsmessanwendungen sowie verschiedene andere Anwendungen zu realisieren. Hier haben wir eine einfache Methode vorgestellt, um mit Arduino und einem Ultraschallsensor die Entfernung zu messen und wie man den Ultraschallsensor mit Arduino verwendet.

### **2. Spezifikation**

- Betriebsspannung: +5V DC

- Ruhestrom: <2mA

- Betriebsstrom: 15mA

- Effektiver Winkel: <15°

- Entfernungsbereich: 2cm – 300 cm

- Genauigkeit: 0,3 cm

- Messwinkel: 30 Grad

- Trigger-Eingang Impulsbreite: 10µs

![image-20250509085705309](media/A35.png)

### **3. Komponenten**

| Entwicklungsboard *1                                         | 8833 Motor Driver *1                     | Rotes LED Modul*1         | Ultraschallsensor*1                                          |
| ------------------------------------------------------------ | ---------------------------------------- | ------------------------ | ------------------------------------------------------------ |
| ![img](media/A8.jpg)                     | ![img](media/A9.jpg) | ![img](media/A10.jpg) | ![image-20250509085643931](media/A33.png) |
| 4P Dupont Kabel*1                                             | USB Kabel*1                              | 3P Dupont Kabel*1         |                                                              |
| ![image-20250509143737972](media/A36.png) | ![img](media/A12.jpg)                 | ![img](media/A11.jpg) |                                                              |

### **4. Funktionsprinzip**

Wie auf dem obigen Bild gezeigt, ist es wie zwei Augen. Eines ist der Sender, das andere der Empfänger.

Das Ultraschallmodul sendet nach Auslösen eines Signals Ultraschallwellen aus. Wenn die Ultraschallwellen auf ein Objekt treffen und reflektiert werden, gibt das Modul ein Echo-Signal aus, sodass es die Entfernung des Objekts anhand der Zeitdifferenz zwischen dem Trigger-Signal und dem Echo-Signal bestimmen kann.

t ist die Zeit, die das ausgesendete Signal benötigt, um auf ein Hindernis zu treffen und zurückzukehren. Die Ausbreitungsgeschwindigkeit des Schalls in der Luft beträgt etwa 343 m/s, und Entfernung = Geschwindigkeit \* Zeit. Da die Ultraschallwelle ausgesendet wird und zurückkommt, entspricht dies der doppelten Entfernung. Daher muss durch 2 geteilt werden, die vom Ultraschall gemessene Entfernung = (Geschwindigkeit \* Zeit)/2.

**Verwendungsmethode und Diagramm des Ultraschallmoduls:**

1. Verwenden Sie den GPIO-Pin, um ein High-Level-Signal von mindestens 10μs an den Trig-Pin des SR04 zu geben, um die Entfernungsmessung auszulösen.
2. Nach dem Auslösen sendet das Modul automatisch acht 40KHz Ultraschallimpulse aus und erkennt, ob ein Signal zurückkommt. Dieser Schritt wird automatisch vom Modul ausgeführt.
3. Wenn das Signal zurückkommt, gibt der Echo-Pin ein High-Level-Signal aus, dessen Dauer die Zeit vom Aussenden der Ultraschallwelle bis zum Empfang des Echos ist.

![image-20250509143833078](media/A37.png)

**Schaltplan des Ultraschallsensors:**

![image-20250509154035287](media/A38.png)

### **5. Anschlussdiagramm**

![image-20250509154107103](media/A39.png)

VCC, Trig, Echo und Gnd des Ultraschallsensors sind mit 5V(V), D12, D13 und Gnd(G) verbunden.

### **6. Testcode**

```c
//***************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 5.1
 Ultrasonic Sensor
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches;
void setup() {
  //Serielle Schnittstelle starten
  Serial.begin (9600);
  //Eingänge und Ausgänge definieren
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Der Sensor wird durch einen HIGH-Impuls von 10 oder mehr Mikrosekunden ausgelöst.
  // Geben Sie vorher einen kurzen LOW-Impuls, um einen sauberen HIGH-Impuls zu gewährleisten:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   // Lesen Sie das Signal vom Sensor: ein HIGH-Impuls, dessen
  // Dauer die Zeit (in Mikrosekunden) vom Senden
  // des Pings bis zum Empfang seines Echos von einem Objekt ist.
  duration = pulseIn(echoPin, HIGH);
   // Konvertieren Sie die Zeit in eine Entfernung
  cm = (duration/2) / 29.1;     // Teilen durch 29,1 oder multiplizieren mit 0,0343
  inches = (duration/2) / 74;   // Teilen durch 74 oder multiplizieren mit 0,0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
}
//***************************************************************************
```

### **7. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan und schließen Sie dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten öffnen Sie den seriellen Monitor und stellen die Baudrate auf 9600 ein.

Die erkannte Entfernung wird angezeigt, und die Einheit ist cm und Zoll. Blockieren Sie den Ultraschallsensor mit der Hand, wird der angezeigte Entfernungswert kleiner.

![image-20250509154147537](media/A40.png)

### **8. Code-Erklärung**

**int trigPin -** Dieser Pin ist definiert, um Ultraschallwellen zu senden, normalerweise Ausgang.

**int echoPin -** Dieser Pin ist als Empfangspin definiert, normalerweise Eingang.

**cm = (duration/2) / 29.1 -**

**inches = (duration/2) / 74 -**

Wir können die Entfernung mit der folgenden Formel berechnen:

distance = (Reisezeit/2) x Schallgeschwindigkeit

Die Schallgeschwindigkeit beträgt: 343 m/s = 0,0343 cm/µs = 1/29,1 cm/µs

Oder in Zoll: 13503,9 in/s = 0,0135 in/µs = 1/74 in/µs

Wir müssen die Reisezeit durch 2 teilen, da wir berücksichtigen müssen, dass die Welle gesendet wurde, das Objekt getroffen hat und dann zum Sensor zurückgekehrt ist.

### **9. Erweiterte Übung**

Wir haben gerade die vom Ultraschall gemessene Entfernung angezeigt. Wie wäre es, die LED mit der gemessenen Entfernung zu steuern? Versuchen wir es und verbinden ein LED-Lichtmodul mit dem Pin D9.

![image-20250509154232505](media/A41.png)

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lesson 5.2
 Ultrasonic LED
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches;

void setup() {
  Serial.begin (9600);  //Serielle Schnittstelle starten
  pinMode(trigPin, OUTPUT);  //Definiere Ein- und Ausgänge
  pinMode(echoPin, INPUT);
}

void loop() 
{
  // Der Sensor wird durch einen HIGH-Impuls von 10 oder mehr Mikrosekunden ausgelöst.
  // Geben Sie vorher einen kurzen LOW-Impuls, um einen sauberen HIGH-Impuls zu gewährleisten:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Lesen Sie das Signal vom Sensor: ein HIGH-Impuls, dessen
  // Dauer die Zeit (in Mikrosekunden) vom Senden
  // des Pings bis zum Empfang seines Echos von einem Objekt ist.
  duration = pulseIn(echoPin, HIGH);
  // Konvertieren Sie die Zeit in eine Entfernung
  cm = (duration/2) / 29.1;     // Teilen durch 29,1 oder multiplizieren mit 0,0343
  inches = (duration/2) / 74;   // Teilen durch 74 oder multiplizieren mit 0,0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
  if (cm>=2 && cm<=10)
  {
    Serial.println("HIGH");
    digitalWrite(9, HIGH);
  }
  else
  {
    Serial.println("LOW");
    digitalWrite(9, LOW);
  }
}
//*****************************************************************
```

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan und schließen Sie dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten blockieren Sie den Ultraschallsensor mit der Hand (der Abstand liegt zwischen 2-10 cm) und prüfen, ob die LED leuchtet.