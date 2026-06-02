# Projekt 3: Linienverfolgungssensor

![](media/A17.png)

### **1. Beschreibung** 

Der Verfolgungssensor ist tatsächlich ein Infrarotsensor. Die hier verwendete Komponente ist die TCRT5000 Infrarot-Röhre. Ihr Arbeitsprinzip besteht darin, die unterschiedliche Reflexionsfähigkeit von Infrarotlicht auf Farben zu nutzen und dann die Stärke des reflektierten Signals in ein Stromsignal umzuwandeln.

Während des Erkennungsprozesses ist Schwarz auf HIGH-Pegel aktiv, während Weiß auf LOW-Pegel aktiv ist. Die Erkennungshöhe beträgt 0-3 cm.

Das Keyestudio 3-Kanal Linienverfolgungsmodul hat 3 Sätze TCRT5000 Infrarot-Röhren auf einer Platine integriert, was die Verkabelung und Steuerung bequemer macht.

Durch Drehen des einstellbaren Potentiometers am Sensor kann die Erkennungsempfindlichkeit des Sensors angepasst werden.

### **2. Spezifikation**

- Betriebsspannung: 3,3-5V (DC)

- Schnittstelle: 5PIN

- Ausgangssignal: Digitalsignal

- Erkennungshöhe: 0-3 cm

![image-20250508163247479](media/A18.png)

<span style="color: rgb(255, 76, 65);">Hinweis: Vor dem Testen drehen Sie das Potentiometer am Sensor, um die Erkennungsempfindlichkeit einzustellen. Die Empfindlichkeit ist am besten, wenn die LED an einer Schwelle zwischen EIN und AUS eingestellt wird.</span> 

### **3. Komponenten**

| Entwicklungsboard *1                     | 8833 Motor Driver *1                     | Rotes LED-Modul *1         | Linienverfolgungssensor *1   |
| ---------------------------------------- | ---------------------------------------- | ------------------------ | ------------------------ |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) | ![img](media/A19.png) |
| 5P Dupont Kabel *1                         | USB-Kabel *1                              | 3P Dupont Kabel *1         |                          |
| ![img](media/A20.png)                 | ![img](media/A12.jpg)                 | ![img](media/A11.jpg) |                          |

### **4. Schaltplan**

![image-20250508164243044](media/A21.png)

G, V, S1, S2 und S3 des Linienverfolgungssensors sind mit G (GND), V (VCC), D11, D7 und D8 des Sensor-Erweiterungsboards verbunden.

### **5. Testcode**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 3.1 
 Line Track sensor
 http://www.keyestudio.com
*/
int L_pin = 11;  //Pins des linken Linienverfolgungssensors
int M_pin = 7;  //Pins des mittleren Linienverfolgungssensors
int R_pin = 8;  //Pins des rechten Linienverfolgungssensors
int val_L,val_R,val_M;// definiere die Variablenwerte der drei Sensoren

void setup()
{
  Serial.begin(9600); // initialisiere serielle Kommunikation mit 9600 Baud
  pinMode(L_pin,INPUT); // definiere L_pin als Eingang
  pinMode(M_pin,INPUT); // definiere M_pin als Eingang
  pinMode(R_pin,INPUT); // definiere R_pin als Eingang
}

void loop() 
{ 
  val_L = digitalRead(L_pin);// lese den L_pin aus:
  val_R = digitalRead(R_pin);// lese den R_pin aus:
  val_M = digitalRead(M_pin);// lese den M_pin aus:
  Serial.print("links:");
  Serial.print(val_L);
  Serial.print(" mitte:");
  Serial.print(val_M);
  Serial.print(" rechts:");
  Serial.println(val_R);
  delay(500);// Verzögerung zwischen den Messungen für Stabilität
}
//****************************************************************************
```

### **6. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan und verwenden ein USB-Kabel, um den Computer mit Strom für das Board zu versorgen.

Nach dem Einschalten öffnen Sie den seriellen Monitor und sehen den Status der drei Linienverfolgungssensoren. Wenn keine Signale empfangen werden, ist der Wert 1. Wenn wir den Sensor mit weißem Papier abdecken, wird der Wert 0.

![image-20250508164424571](media/A22.png)

![image-20250508164453274](media/A23.png)

**7. Code-Erklärung**

Serial.begin(9600) - Initialisiert die serielle Schnittstelle, setzt die Baudrate auf 9600

pinMode - Definiert den Pin als Eingangs- oder Ausgangsmodus

digitalRead - Liest den Zustand des Pins, der in der Regel HIGH- oder LOW-Pegel ist

**8. Erweiterte Übung**

Nachdem Sie das Funktionsprinzip verstanden haben, können Sie eine LED an D9 anschließen, um die LED darüber zu steuern.

![image-20250508164527429](media/A24.png)

```c
/*
keyestudio 4wd BT Car
lesson 3.2
 Line Track Sensor LED
 http://www.keyestudio.com
*/
int L_pin = 11;  //Pins des linken Linienverfolgungssensors
int M_pin = 7;  //Pins des mittleren Linienverfolgungssensors
int R_pin = 8;  //Pins des rechten Linienverfolgungssensors
int val_L,val_R,val_M;// definiere die Variablen der drei Sensoren 

void setup()
{
  Serial.begin(9600); // initialisiere serielle Kommunikation mit 9600 Bits pro Sekunde
  pinMode(L_pin,INPUT); // setze L_pin als Eingang
  pinMode(M_pin,INPUT); // setze M_pin als Eingang
  pinMode(R_pin,INPUT); // setze R_pin als Eingang
  pinMode(9, OUTPUT);
}

void loop() 
{ 
  val_L = digitalRead(L_pin);// lese L_pin:
  val_R = digitalRead(R_pin);// lese R_pin:
  val_M = digitalRead(M_pin);// lese M_pin:
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500);// Verzögerung zwischen den Messungen für Stabilität
  if ((val_L == LOW) || (val_M == LOW) || (val_R == LOW))// wenn der linke Linienverfolgungssensor Signale erkennt
  { 
    Serial.println("HIGH");
    digitalWrite(9, HIGH);// LED ist an
  }
  else// wenn der linke Linienverfolgungssensor keine Signale erkennt
  { 
    Serial.println("LOW");
    digitalWrite(9, LOW);// LED ist aus
  }
 }
//****************************************************************************
```

Nach dem erfolgreichen Hochladen des Codes auf das V4.0 Board, verbinden Sie die Verkabelung gemäß dem Schaltplan und verwenden Sie ein USB-Kabel, um den Computer mit Strom für das Board zu versorgen.

Nach dem Einschalten halten Sie ein Blatt Papier nahe an den Sensor, dann können Sie feststellen, dass die LED aufleuchtet, wenn der Linienverfolgungssensor abgedeckt wird.