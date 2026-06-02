# Projekt 13 Ultraschall-Hindernisvermeidung Smart Car

![fd4044796307f709987b9d2e215e0911](media/A119.png)

### **1. Beschreibung**

In diesem Projekt wollen wir ein Ultraschall-Hindernisvermeidungs-Smart Car bauen. Wir verwenden den Ultraschallsensor, um den Abstand zum Hindernis zu messen, welcher genutzt wird, um den Servo zu steuern und das Auto zu bewegen. Gleichzeitig zeigt das 8x16 LED-Board das entsprechende Statusmuster an.

### **2. Flussdiagramm**

![img](media/A120.png)

**Die spezifische Logik des Ultraschall-Hindernisvermeidungs-Smart Cars ist unten dargestellt:**

![Img](media/A121.png)

![Img](media/A122.png)

### **3. Schaltplan**

![](media/A118.png)

1). GND, VCC, SDA und SCL des 8\*8 LED-Board-Moduls sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). VCC, Trig, Echo und GND des Ultraschallsensors sind mit 5V (V), D12 (S), D13 (S) und GND (G) verbunden.

3). Der Servo ist mit G, V und A3 verbunden. Das braune Kabel ist mit GND (G), das rote Kabel mit 5V (V) und das orange Kabel mit A3 verbunden.

4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

```c 
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 13
 Avoiding Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Setze den Clock-Pin auf A5
#define SDA_Pin  A4  //Setze den Daten-Pin auf A4
//Array, verwendet zur Speicherung der Musterdaten, kann selbst berechnet oder mit dem Modultool erhalten werden
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2; //definiere die Richtungssteuerungs-Pins des Motors Gruppe B
int left_pwm = 5;  //definiere die PWM-Steuerungs-Pins des Motors Gruppe B
int right_ctrl = 4; //definiere die Richtungssteuerungs-Pins des Motors Gruppe A
int right_pwm = 6;  //definiere die PWM-Steuerungs-Pins des Motors Gruppe A

#include "SR04.h" //definiere die Bibliothek des Ultraschallsensors
#define TRIG_PIN 12 //setze das Signal-Ausgangspin des Ultraschallsensors auf D12 
#define ECHO_PIN 13 //setze das Signal-Eingangspin des Ultraschallsensors auf D13 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance,a1,a2; //definiere drei Distanzvariablen
const int servopin = A3; //setze den Pin des Servos auf A3 

void setup() {
  pinMode(left_ctrl,OUTPUT); //setze Richtungssteuerungs-Pins des Motors Gruppe B auf OUTPUT
  pinMode(left_pwm,OUTPUT);  //setze PWM-Steuerungs-Pins des Motors Gruppe B auf OUTPUT
  pinMode(right_ctrl,OUTPUT);//setze Richtungssteuerungs-Pins des Motors Gruppe A auf OUTPUT
  pinMode(right_pwm,OUTPUT); //setze PWM-Steuerungs-Pins des Motors Gruppe A auf OUTPUT
  pinMode(TRIG_PIN, OUTPUT); //Setze den Trig-Pin auf Ausgang
  pinMode(ECHO_PIN, INPUT);  //Setze den Echo-Pin auf Eingang
  servopulse(servopin,90);   //der Winkel des Servos ist 90 Grad
  delay(300);
  pinMode(SCL_Pin,OUTPUT);   //Setze den Clock-Pin auf Ausgang
  pinMode(SDA_Pin,OUTPUT);   //Setze den Daten-Pin auf Ausgang
  matrix_display(clear);
}
 
void loop()
 {
  avoid(); //führe das Hauptprogramm aus
}

void avoid()
{
  distance=sr04.Distance(); //ermittle den Wert, der vom Ultraschallsensor gemessen wurde

  if((distance < 20)&&(distance != 0)) //wenn der Abstand größer als 0 und kleiner als 10 ist  

  {
    car_Stop();//stoppen
    matrix_display(clear);
    matrix_display(STOP01);//Stop-Muster anzeigen
    delay(1000);
    servopulse(servopin,160);//Servo dreht sich auf 160°
    delay(500);
    a1=sr04.Distance();//Entfernung messen
    delay(100);
    servopulse(servopin,20);//auf 20 Grad drehen
    delay(500);
    a2=sr04.Distance();//Entfernung messen
    delay(100);
    servopulse(servopin,90);  //Zurück zur 90-Grad-Position
    delay(500);
    if(a1 > a2)//Entfernung vergleichen, wenn linke Entfernung größer als rechte Entfernung ist
    {
      car_left();//nach links abbiegen
      matrix_display(clear);
      matrix_display(left);    //Linkskurven-Muster anzeigen
      servopulse(servopin,90);//Servo dreht sich auf 90 Grad
      delay(700); //links 700ms drehen
      matrix_display(clear);
      matrix_display(front);  //Vorwärts-Muster anzeigen
    }
    else//wenn die rechte Entfernung größer als die linke ist
    {
      car_right();//nach rechts abbiegen
      matrix_display(clear);
      matrix_display(right);  //Rechtskurven-Muster anzeigen
      servopulse(servopin,90);//Servo dreht sich auf 90 Grad
      delay(700);
      matrix_display(clear);
      matrix_display(front);  //Vorwärts-Muster anzeigen
    }
  }
  else//ansonsten
  {
    car_front();//vorwärts fahren
    matrix_display(clear);
    matrix_display(front);  //Vorwärts-Muster anzeigen
  }
}

void car_front()//Auto fährt vorwärts
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//rückwärts fahren
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//Auto dreht nach links
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//Auto dreht nach rechts
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//anhalten
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//der Laufwinkel des Servos
{
  for(int i=0; i<20; i++)
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
  IIC_start();  //die Funktion, die die Datenübertragungs-Startbedingung aufruft
  IIC_send(0xc0);  //Adresse auswählen

```cpp
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
    if (send_data & mask) { // Setzt die Pegel von SDA_Pin je nachdem, ob jedes Bit des Bytes eine 1 oder 0 ist
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); // Ziehe den Clock-Pin SCL_Pin auf HIGH, um die Datenübertragung zu stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); // Ziehe den Clock-Pin SCL_Pin auf LOW, um das SIGNAL von SDA zu ändern
  }
}
//*******************************************************************************
```

### **5.Testergebnis**

Nach dem erfolgreichen Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten die externe Stromversorgung ein und stellen den DIP-Schalter auf ON.

Das Smart Car fährt vorwärts und weicht automatisch Hindernissen aus. Wenn kein Weg voraus ist, steuert der Servo den Ultraschallsensor, um die Entfernungen links, mittig und rechts zu scannen, und das Auto fährt in die offene Richtung. Gleichzeitig zeigt die 8X16 LED-Anzeige das entsprechende Statusmuster an.