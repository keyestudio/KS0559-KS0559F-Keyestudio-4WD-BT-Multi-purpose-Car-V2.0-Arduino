# Projekt 9 Gesichtsausdruck LED-Board

![image-20250510090912741](media/A87.png)

### **1. Beschreibung**

Wie lustig wäre es, wenn ein Ausdrucksboard zum Roboter hinzugefügt wird. Und das Keyestudio 8\*16 LED-Board kann genau das ermöglichen. Mit seiner Hilfe könnt ihr Gesichtsausdrücke, Bilder, Muster und andere Anzeigen selbst gestalten.

Das 8\*16 LED-Board verfügt über 128 LEDs. Die Daten des Mikroprozessors (Arduino) kommunizieren über eine Zwei-Draht-Busschnittstelle mit dem AiP1640. Dadurch kann es das Ein- und Ausschalten der 128 LEDs auf dem Modul steuern, um die Punktmatrix auf dem Modul so anzuzeigen, dass das gewünschte Muster dargestellt wird. Ein HX-2.54 4Pin-Kabel wird für eine bequeme Verkabelung mitgeliefert.

### **2. Spezifikation**

- Betriebsspannung: DC 3,3-5V

- Leistungsverlust: 400mW

- Oszillationsfrequenz: 450KHz

- Ansteuerstrom: 200mA

- Arbeitstemperatur: -40\~80℃

- Kommunikationsmodus: I2C

### **3. Schaltplan**

![image-20250510091309725](media/A88.png)

### **4. Funktionsprinzip**

Wie steuert man jede LED der 8\*16 Punktmatrix? Es ist bekannt, dass jedes Byte 8 Bits hat und jedes Bit 0 oder 1 ist. Wenn es 0 ist, ist die LED aus, wenn es 1 ist, ist die LED an. Ein Byte kann eine Spalte der LEDs steuern, und natürlich können 16 Bytes 16 Spalten von LEDs steuern, das ist die 8\*16 Punktmatrix.

### **5. Pin-Beschreibung und Kommunikationsprotokoll**

Die Daten des Mikroprozessors (Arduino) kommunizieren über ein Zwei-Draht-Buskabel mit dem AiP1640.

Das Kommunikationsprotokoll-Diagramm ist wie folgt (SCLK) ist SCL, (DIN) ist SDA.

![image-20250510091407219](media/A89.png)

① Die Startbedingung für die Dateneingabe: SCL ist auf hohem Pegel und SDA wechselt von hoch nach niedrig.

② Für die Datenbefehls-Einstellung gibt es die im folgenden Bild gezeigten Methoden.

In unserem Beispielprogramm wählen wir die Methode, **die Adresse automatisch um 1 zu erhöhen**, der Binärwert ist 0100 0000 und der entsprechende Hexadezimalwert ist 0x40.

![Img](media/A90.png)

③ Für die Adressbefehls-Einstellung kann die Adresse wie unten gezeigt ausgewählt werden.

Im Beispielprogramm wird die erste 00H ausgewählt, und die Binärzahl 1100 0000 entspricht dem Hexadezimalwert 0xc0.

![Img](media/A91.png)

④ Die Anforderung für die Dateneingabe ist, dass wenn SCL auf hohem Pegel ist, während der Dateneingabe das Signal auf SDA unverändert bleiben muss. Nur wenn das Taktsignal auf SCL auf niedrigem Pegel ist, darf das Signal auf SDA geändert werden. Die Dateneingabe erfolgt zuerst mit dem niederwertigen Bit, dann mit dem höherwertigen Bit.

⑤ Die Bedingung für das Ende der Datenübertragung ist, dass wenn SCL auf niedrigem Pegel, SDA auf niedrigem Pegel und SCL auf hohem Pegel ist, der Pegel von SDA auf hoch wechselt.

⑥ Anzeige-Steuerung, verschiedene Pulsweiten einstellen, die Pulsweite kann wie im Bild unten ausgewählt werden.

Im Beispiel ist die Pulsweite 4/16, und der Hexadezimalwert, der 1000 1010 entspricht, ist 0x8A.

![Img](media/A92.png)

**Anleitung zur Verwendung des Modultools**

Das Punktmatrix-Tool verwendet die Online-Version, der Link ist: [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

① Link eingeben und die Seite erscheint wie unten gezeigt

![image-20250510091438524](media/A93.png)

② Die Punktmatrix ist 8\*16, also Höhe auf 8 und Breite auf 16 einstellen, wie im Bild unten gezeigt.

![image-20250510091446519](media/A94.png)

③ Hexadezimale Daten aus dem Muster generieren

Wie im Bild unten gezeigt, mit der linken Maustaste auswählen, mit der rechten Maustaste abwählen; das gewünschte Muster zeichnen, auf Generate klicken, und die benötigten hexadezimalen Daten werden generiert.

![image-20250510091457463](media/A95.png)

### **6. Komponenten**

| Development Board *1                                         | 8833 Motor Driver *1                                         | USB-Kabel*1               |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------- |
| ![img](media/A80.jpg)                                    | ![img](media/A81.jpg)                                    | ![img](media/A82.jpg) |
| USB-Kabel*1                                                  | HX-2.54 4P Dupont Kabel 200mm *1                              |                           |
| ![image-20250512155818434](media/A96.png) | ![image-20250512155822969](media/A97.png) |                           |

### **7. Schaltplan**

![cec50fec4a335b6922e4c6694a133bc1](media/A98.png)

Die GND, VCC, SDA und SCL des 8x16 LED-Lichtboards sind jeweils mit dem keyestudio Sensor-Erweiterungsboard verbunden – (GND), + (VCC), A4, A5 für die Zwei-Draht-Serienkommunikation.

(<span style="color: rgb(255, 76, 65);">Hinweis:</span> Obwohl es mit dem IIC-Pin des Arduino verbunden ist, ist dieses Modul nicht für die IIC-Kommunikation gedacht. Und der IO-Port hier dient zur Simulation der I2C-Kommunikation und kann mit beliebigen zwei Pins verbunden werden).

### **8. Testcode**

Der Code zeigt ein lächelndes Gesicht.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lesson 9.1
  Matrix face
  http://www.keyestudio.com
*/
//Daten vom Smile-Muster, erhalten mit dem Touch-Tool
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};
#define SCL_Pin  A5  //Setze den Clock-Pin auf A5
#define SDA_Pin  A4  //Setze den Daten-Pin auf A4
void setup() {
  //Setze Pin als Ausgang
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //löschen
  //matrix_display(clear);
}
void loop() {
  matrix_display(smile);  //zeige das lächelnde Ausdrucksmuster an
}
//diese Funktion wird für die Punktmatrixanzeige verwendet
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //Funktion, die die Datenübertragungs-Startbedingung aufruft
  IIC_send(0xc0);  //Adresse auswählen

  for (int i = 0; i < 16; i++) //Das Musterdaten sind 16 Bytes
  {
    IIC_send(matrix_value[i]); //Übertrage die Daten des Musters
  }
  IIC_end();   //Beende die Musterdatenübertragung
  IIC_start();
  IIC_send(0x8A);  //Anzeige-Steuerung, wähle 4/16 Pulsbreite
  IIC_end();
}
//Bedingungen, unter denen die Datenübertragung beginnt
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Zeigt das Ende der Datenübertragung an
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
//Daten übertragen
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Jedes Byte hat 8 Bits und wird bitweise vom niedrigsten Bit geprüft
  {
    if (send_data & mask) { //Setzt die Pegel von SDA_Pin je nachdem, ob jedes Bit des Bytes eine 1 oder 0 ist
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Ziehe den Clock-Pin SCL_Pin hoch, um die Datenübertragung zu stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Ziehe den Clock-Pin SCL_Pin runter, um das SIGNAL von SDA zu ändern
  }
}
//************************************************************************
```

### **9. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie dann den DIP-Schalter auf ON, es wird ein lächelndes Muster auf dem LED-Board angezeigt.

![95bb011957896b12285fc6763137bb9a](media/A99.png)

### **10. Code-Erklärung**

Wir verwenden das Modul-Tool, das wir gerade gelernt haben, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), um die Punktmatrix das Startmuster anzeigen zu lassen, vorwärts zu gehen, anzuhalten und dann das Muster zu löschen. Das Zeitintervall beträgt 2000 ms.

![image-20250512155957415](media/A100.png)![image-20250512160002378](media/A101.png)![image-20250512160006841](media/A102.png)![image-20250512160010543](media/A103.png)

**Vom Modul-Tool erhaltene Codes：**

**Code für das Startmuster:**

0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01

**Code für das Vorwärtsmuster:**

0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Code für das Rückwärtsmuster:**

0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Code für das Linksdrehmuster：**

0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00

**Code für das Rechtsdrehmuster：**

0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00

**Code für das Stoppmuster：**

0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00

**Code zum Bildschirm löschen：**

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

![cec50fec4a335b6922e4c6694a133bc1](media/A104.png)

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lesson 9.2
  Matrix face
  http://www.keyestudio.com
*/
//Daten vom Smile-Muster, erhalten vom Touch-Tool
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char front[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x12, 0x09, 0x12, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char back[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char left[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00};
unsigned char right[] = {0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char STOP01[] = {0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00};
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define SCL_Pin  A5  //Setze den Clock-Pin auf A5
#define SDA_Pin  A4  //Setze den Daten-Pin auf A4
void setup() {
  //Setze Pin als Ausgang
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //löschen
  //matrix_display(clear);
}
void loop() {
    matrix_display(start01);  //Zeige Startmuster
    delay(2000);
    matrix_display(front);    //Zeige Vorwärtsmuster
    delay(2000);
    matrix_display(STOP01);   //Zeige Stoppmuster
    delay(2000);
    matrix_display(clear);    //Bildschirm löschen
    delay(2000);
}
//Diese Funktion wird für die Punktmatrix-Anzeige verwendet
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //Funktion, die den Startzustand der Datenübertragung aufruft
  IIC_send(0xc0);  //Adresse auswählen

for (int i = 0; i < 16; i++) // die Musterdaten sind 16 Bytes
{
  IIC_send(matrix_value[i]); // Übertrage die Daten des Musters
}
IIC_end();   // Beende die Musterdatenübertragung
IIC_start();
IIC_send(0x8A);  // Anzeige-Steuerung, wähle 4/16 Pulsbreite
IIC_end();
}
// Bedingungen, unter denen die Datenübertragung beginnt
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
// Zeigt das Ende der Datenübertragung an
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
// Daten übertragen
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) // Jedes Byte hat 8 Bits und wird bitweise beginnend mit dem niedrigsten Bit geprüft
  {
    if (send_data & mask) { // Setzt die High- und Low-Pegel von SDA_Pin abhängig davon, ob jedes Bit des Bytes eine 1 oder 0 ist
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); // Ziehe den Clock-Pin SCL_Pin auf High, um die Datenübertragung zu stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); // Ziehe den Clock-Pin SCL_Pin auf Low, um das SIGNAL von SDA zu ändern
  }
}
//************************************************************************
```

Nach dem Hochladen des Testcodes zeigt die Gesichtsausdrucksplatine diese Muster der Reihe nach an und wiederholt diese Sequenz.

![image-20250512160131674](media/A105.png)![image-20250512160135717](media/A106.png)![image-20250512160139283](media/A107.png)