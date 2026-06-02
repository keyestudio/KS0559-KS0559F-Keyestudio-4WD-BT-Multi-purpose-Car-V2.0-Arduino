# Projekt 12 Ultraschall Folgender Smart Car

![a3beaada39eb1471b7df6d9788e2bea3](media/A116.png)

### **1.Beschreibung**

In diesem Projekt werden wir versuchen, den Abstand zwischen dem 4WD Smart Car und den Hindernissen davor durch einen Ultraschallsensor zu erkennen, um zwei Motoren so zu steuern, dass das Auto sich bewegt und die 8\*8 LED-Anzeige ein lächelndes Gesichtsmuster zeigt.

### **2.Flussdiagramm**

![img](media/A117.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Erkennung</td>
<td>Gemessener Abstand der vorderen Hindernisse</td>
<td>Abstand (Einheit: cm)</td>
</tr>
<tr class="even">
<td>Einstellung</td>
<td>8*16 LED-Anzeige zeigt ein Lächelmuster.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Servo auf 90° einstellen</td>
<td></td>
</tr>
<tr class="even">
<td>Bedingung</td>
<td>Abstand≥20 und Abstand≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>Status</td>
<td>Vorwärts fahren</td>
<td></td>
</tr>
<tr class="even">
<td>Bedingung</td>
<td>Abstand＞10 und Abstand＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Abstand＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Bedingung</td>
<td>Anhalten</td>
<td></td>
</tr>
<tr class="odd">
<td>Bedingung</td>
<td>Abstand≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Bedingung</td>
<td>Rückwärts fahren</td>
<td></td>
</tr>
</tbody>
</table>


### **3.Schaltplan**

![568a66655a14dd34afd8cb1e6ae5951c](media/A118.png)

**Anschluss:**

1). GND, VCC, SDA und SCL der 8\*8 LED-Anzeige sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). VCC, Trig, Echo und GND des Ultraschallsensors sind mit 5V (V), D12 (S), D13 (S) und GND (G) verbunden.

3). Das Servo ist mit G, V und A3 verbunden. Der braune Draht ist mit GND (G), der rote Draht mit 5V (V) und der orange Draht mit A3 verbunden.

4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4.Testcode**

```c
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 12
 Flowing Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Setze den Clock-Pin auf A5
#define SDA_Pin  A4  //Setze den Daten-Pin auf A4

//Array, verwendet zur Speicherung der Musterdaten, kann selbst berechnet oder aus dem Modul-Tool erhalten werden
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};

const int servopin = A3;//Setze den Pin des Servos
 
#include "SR04.h" //definiere die Funktionsbibliothek des Ultraschallsensors
#define TRIG_PIN 12// setze das Signal des Ultraschallsensors auf D12
#define ECHO_PIN 13// setze das Signal des Ultraschallsensors auf D13
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

int left_ctrl = 2;//definiere die Richtungssteuerungspins des Motors Gruppe B
int left_pwm = 5;//definiere die PWM-Steuerungspins des Motors Gruppe B
int right_ctrl = 4;//definiere die Richtungssteuerungspins des Motors Gruppe A
int right_pwm = 6;//definiere die PWM-Steuerungspins des Motors Gruppe A

void setup() {
  pinMode(left_ctrl,OUTPUT);//setze die Richtungssteuerungspins des Motors Gruppe B auf OUTPUT
  pinMode(left_pwm,OUTPUT);//setze die PWM-Steuerungspins des Motors Gruppe B auf OUTPUT
  pinMode(right_ctrl,OUTPUT);//setze die Richtungssteuerungspins des Motors Gruppe A auf OUTPUT
  pinMode(right_pwm,OUTPUT);//setze die PWM-Steuerungspins des Motors Gruppe A auf OUTPUT
  pinMode(TRIG_PIN, OUTPUT); //Setze den Trig-Pin auf Ausgang
  pinMode(ECHO_PIN, INPUT); //Setze den Echo-Pin auf Eingang
  pinMode(SCL_Pin,OUTPUT);//Setze den Clock-Pin auf Ausgang
  pinMode(SDA_Pin,OUTPUT);//Setze den Daten-Pin auf Ausgang
  servopulse(servopin,90);//Setze den Anfangswinkel des Servos auf 90°
  delay(500); //warte 500ms
  matrix_display(smile);  //zeige das lächelnde Gesichtsmuster  
}

void loop() {
  distance = sr04.Distance();//der vom Ultraschallsensor erkannte Abstand
   if(distance <= 10)//wenn der Abstand kleiner als 10 ist
  {
    back();//fahre rückwärts
  }
  else if((distance > 10)&&(distance< 20 ))//wenn 10<Abstand<20
  {
    Stop();//stoppen
  }
  else if((distance >= 20)&&(distance <= 50))//wenn 20≤Abstand≤50  
{
    front();//folge
  }
  else//ansonsten
  {
    Stop();//stoppen
  }
}

void front()//definiert den Zustand für Vorwärtsfahrt
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,100);
}
void back()//definiert den Zustand für Rückwärtsfahrt
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void left()//definiert den Zustand für Linksdrehung
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//definiert den Zustand für Rechtsdrehung
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void Stop()//definiert den Zustand für Stopp
{
  digitalWrite(left_ctrl, LOW);  
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//Lenkservo Laufwinkel
{
  for(int i=0; i<30; i++)
  {
    int pulsewidth = (myangle*11)+500;
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servopin,LOW);
    delay(20-pulsewidth/1000);
  }  
}

//diese Funktion wird für die Punktmatrixanzeige verwendet
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //Funktion, die die Startbedingung für die Datenübertragung aufruft
  IIC_send(0xc0);  //Adresse auswählen

  for (int i = 0; i < 16; i++) //Das Musterdaten sind 16 Bytes
  {
    IIC_send(matrix_value[i]); //Überträgt die Musterdaten
  }
  IIC_end();   //Beendet die Musterdatenübertragung
  IIC_start();
  IIC_send(0x8A);  //Anzeige-Steuerung, wählt 4/16 Pulsbreite
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
//Datenübertragung
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
    digitalWrite(SCL_Pin, HIGH); //Zieht den Taktpin SCL_Pin hoch, um die Datenübertragung zu stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Zieht den Taktpin SCL_Pin runter, um das SIGNAL von SDA zu ändern
  }
}
//*******************************************************************************
```

### **5. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten die externe Stromversorgung einund stellen dann den DIP-Schalter auf ON. Stellen Sie den Servo auf 90° ein, das Smart Car bewegt sich mit Hindernissen und die 8X16 LED-Anzeige zeigt „smile“.