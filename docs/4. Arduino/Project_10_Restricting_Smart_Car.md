# Projekt 10 Einschränkendes Smart Car

![644a1976bf17a6b64e0aed1a7240ff1e](media/A108.jpeg)

### **1. Beschreibung**

In diesem Projekt kombinieren wir das Wissen über einen Linienverfolgungssensor und Motortreiber-Module, um ein einschränkendes Smart Car zu bauen. Im Experiment wollen wir den Linienverfolgungssensor verwenden, um zu erkennen, ob sich eine schwarze Linie um das Smart Car befindet, und dann die Drehung der beiden Motoren entsprechend den Erkennungsergebnissen so steuern, dass das Smart Car in einem im Kreis gezogenen schwarzen Linien eingeschlossen wird.

### **2. Flussdiagramm**

![img](media/A109.png)

Die spezifische Logik des einschränkenden 4WD Smart Cars ist in der Tabelle dargestellt.

![Img](media/A110.png)

### **3. Schaltplan**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A111.png)

G, V, S1, S2 und S3 des Linienverfolgungssensors sind mit G (GND), V (VCC), D11, D7 und D8 des Sensor-Erweiterungsboards verbunden.

Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 10
 Restricting Smart Car
 http://www.keyestudio.com
*/ 
//Daten vom Smile-Muster, erhalten vom Touch-Tool
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //Datenpin auf A4 setzen
#define SCL_Pin  A5  //Taktpin auf A5 setzen

int left_ctrl = 2; //Definiere die Richtungssteuerungspins des Motors Gruppe B
int left_pwm = 5;  //Definiere die PWM-Steuerungspins des Motors Gruppe B
int right_ctrl = 4; //Definiere die Richtungssteuerungspins des Motors Gruppe A
int right_pwm = 6;  //Definiere die PWM-Steuerungspins des Motors Gruppe A
int sensor_L = 11;  //Definiere den Pin des linken Linienverfolgungssensors
int sensor_M = 7;   //Definiere den Pin des mittleren Linienverfolgungssensors
int sensor_R = 8;   //Definiere den Pin des rechten Linienverfolgungssensors
int L_val, M_val, R_val; //Definiere diese Variablen

void setup() {
  Serial.begin(9600); //Starte den seriellen Monitor und setze die Baudrate auf 9600
  pinMode(left_ctrl, OUTPUT); //Setze die Richtungssteuerungspins des Motors Gruppe B auf OUTPUT
  pinMode(left_pwm, OUTPUT);  //Setze die PWM-Steuerungspins des Motors Gruppe B auf OUTPUT
  pinMode(right_ctrl, OUTPUT); //Setze die Richtungssteuerungspins des Motors Gruppe A auf OUTPUT
  pinMode(right_pwm, OUTPUT);  //Setze die PWM-Steuerungspins des Motors Gruppe A auf OUTPUT
  pinMode(sensor_L, INPUT);    //Setze die Pins des linken Linienverfolgungssensors auf INPUT
  pinMode(sensor_M, INPUT);    //Setze die Pins des mittleren Linienverfolgungssensors auf INPUT
  pinMode(sensor_R, INPUT);    //Setze die Pins des rechten Linienverfolgungssensors auf INPUT
  //Setze Pin auf Ausgang
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(start01); //Zeige Startmuster an
}

void loop() 
{
  tracking(); //Führe Hauptprogramm aus
}

void tracking()
{
  L_val = digitalRead(sensor_L); //Lese den Wert des linken Linienverfolgungssensors
  M_val = digitalRead(sensor_M); //Lese den Wert des mittleren Linienverfolgungssensors
  R_val = digitalRead(sensor_R); //Lese den Wert des rechten Linienverfolgungssensors
  if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //Wenn keine schwarzen Linien erkannt werden, fährt das Turtle Car vorwärts
    Car_front();
  }
  else { //Andernfalls, wenn einer der Sensoren eine schwarze Linie erkennt, rückwärts fahren und nach links drehen
    Car_back();
    delay(500);
    Car_left();
    delay(500);
  }
}

void Car_front()
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 180);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 180);
}
void Car_back()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 80);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 80);
}
void Car_left()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 150);
}

void Car_Stop()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 0);
}


//diese Funktion wird für die Punktmatrixanzeige verwendet
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //die Funktion, die die Datenübertragungs-Startbedingung aufruft
  IIC_send(0xc0);  //Adresse auswählen

  for (int i = 0; i < 16; i++) //die Musterdaten sind 16 Bytes lang
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Jedes Byte hat 8 Bits und wird bitweise beginnend mit dem niedrigsten Bit geprüft
  {
    if (send_data & mask) { //Setzt die High- und Low-Pegel von SDA_Pin abhängig davon, ob jedes Bit des Bytes eine 1 oder 0 ist
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Ziehe den Clock-Pin SCL_Pin auf High, um die Datenübertragung zu stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Ziehe den Clock-Pin SCL_Pin auf Low, um das SIGNAL von SDA zu ändern
  }
}
//*************************************************************************
```

### **5. Testergebnis**

Nach dem erfolgreichen Hochladen des Codes auf das V4.0 Board, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie die externe Stromversorgung einund stellen Sie dann den DIP-Schalter auf ON. Stellen Sie das Smart Car in den schwarzen Kreis, dann wird es sich ausschließlich im Kreis bewegen.