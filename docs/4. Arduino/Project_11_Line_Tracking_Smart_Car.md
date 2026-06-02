# Projekt 11 Linienverfolgungs-Smartcar

![eff7a15e697e8b78bde391f806ea024d](media/A112.png)

### **1. Beschreibung**

Basierend auf dem Arbeitsprinzip des Linienverfolgungssensors ermöglichen wir die Herstellung eines Linienverfolgungs-Smartcars.

In diesem Projekt erkennen wir durch einen Linienverfolgungssensor, ob sich eine schwarze Linie unter dem Smartcar befindet, und steuern dann die Drehung der beiden Motorgruppen entsprechend den Messergebnissen, um das Smartcar entlang der schwarzen Linie fahren zu lassen.

### **2. Flussdiagramm**

![img](media/A113.png)

![Img](media/A114.png)

### **3. Schaltplan**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A115.png)

G, V, S1, S2 und S3 des Linienverfolgungssensors sind mit G (GND), V (VCC), D11, D7 und D8 des Sensor-Erweiterungsboards verbunden.

Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 11
 Tracking Car
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

  if(M_val == 1){ //Wenn der Zustand des mittleren Sensors 1 ist, bedeutet das, dass eine schwarze Linie erkannt wurde


     if (L_val == 1 && R_val == 0) { //Wenn eine schwarze Linie links erkannt wird, aber nicht rechts, nach links abbiegen
        left();
    }
     else if (L_val == 0 && R_val == 1) { //Andernfalls, wenn eine schwarze Linie rechts erkannt wird und nicht links, nach rechts abbiegen
      right();
    }
     else { //Andernfalls geradeaus
      front();
    }
  }
  else { //Keine schwarzen Linien in der Mitte erkannt
    if (L_val == 1 && R_val == 0) { //Wenn eine schwarze Linie links erkannt wird, aber nicht rechts, nach links abbiegen
      left();
    }
    else if (L_val == 0 && R_val == 1) { //Andernfalls, wenn eine schwarze Linie rechts erkannt wird und nicht links, nach rechts abbiegen
      right();
    }
    else { //Andernfalls anhalten
      Stop();
    }
  }
}
void front()//definiert den Zustand des Vorwärtsfahrens
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void back()//definiert den Zustand des Rückwärtsfahrens
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void left()//definiert den Zustand des Linksabbiegens
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//definiert den Zustand des Rechtsabbiegens
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void Stop()//definiert den Zustand des Anhaltens
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm,0);
}

//diese Funktion wird für die Punktmatrixanzeige verwendet
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //die Funktion, die die Startbedingung für die Datenübertragung aufruft
  IIC_send(0xc0);  //Adresse auswählen

  for (int i = 0; i < 16; i++) //Die Musterdaten sind 16 Bytes
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
    if (send_data & mask) { //Setzt die Pegel von SDA_Pin je nachdem, ob jedes Bit des Bytes eine 1 oder 0 ist
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Ziehe den Takt-Pin SCL_Pin hoch, um die Datenübertragung zu stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Ziehe den Takt-Pin SCL_Pin runter, um das SIGNAL von SDA zu ändern
  }
}
//*************************************************************************
```

### **5. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie die externe Stromversorgung ein und stellen Sie dann den DIP-Schalter auf ON. Dann wird das Smart Car den Linien folgen.