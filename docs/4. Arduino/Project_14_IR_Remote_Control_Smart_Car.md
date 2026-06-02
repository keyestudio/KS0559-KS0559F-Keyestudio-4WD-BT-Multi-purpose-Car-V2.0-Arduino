# Projekt 14 IR Fernbedienung Smart Car

![ff2fec813f8765e1bcd593b37b9c0a4f](media/A123.jpeg)

### **1. Beschreibung**

In diesem Projekt bauen wir ein IR-Fernbedienungs-Smart-Car und drücken die Taste auf der IR-Fernbedienung, um das Auto zu steuern.

### **2. Flussdiagramm**

![img](media/A124.png)

**Die spezifische Logik des IR-Fernbedienungs-Smart-Cars ist unten dargestellt:**

| Anfangskonfiguration                      |           | LED-Board zeigt Smiley                         |
| ----------------------------------------- | --------- | ---------------------------------------------- |
| Fernbedienung                            | Tastencode | Tastenzustand                                  |
| ![img](media/A125.jpg) | FF629D    | Vorwärts 8*8 LED-Board zeigt Vorwärtssymbol    |
| ![img](media/A126.jpg) | FFA857    | Rückwärts 8*8 LED-Board zeigt Rückwärtssymbol  |
| ![img](media/A127.jpg)                  | FF22DD    | Nach links drehen 8*8 LED-Board zeigt Links-Symbol |
| ![img](media/A128.jpg)                  | FFC23D    | Nach rechts drehen 8*8 LED-Board zeigt Rechts-Symbol |
| ![img](media/A129.jpg)                 | FF02FD    | Stopp 8*8 LED-Board zeigt „STOP“               |

### **3. Schaltplan**

![9d8b58dff14fe22b5c87514db944530c](media/A130.png)

1). GND, VCC, SDA und SCL des 8\*8 LED-Board-Moduls sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). Da der IR-Empfänger im 8833 Motor Shield integriert ist, ist keine zusätzliche Verkabelung erforderlich. Die Pins des IR-Empfängers auf dem 8833 Board sind jeweils G (GND), V (VCC) und D3.

3). Der Servo ist mit G, V und A3 verbunden. Das braune Kabel ist mit Gnd (G) verbunden, das rote Kabel mit 5V (V) und das orange Kabel mit A3.

4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 14
IR remote Control Car
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Setze den Clock-Pin auf A5
#define SDA_Pin  A4  //Setze den Daten-Pin auf A4
//Array, verwendet zum Speichern der Musterdaten, kann selbst berechnet oder mit dem Modultool erhalten werden
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#include <Arduino.h>
#include <IRremote.h>//Funktionsbibliothek für IR-Fernbedienung
int RECV_PIN = 3;//Setze den Pin des IR-Empfängers auf D3
IRrecv irrecv(RECV_PIN);
long irr_val;
decode_results results;

int left_ctrl = 2;//Definiere die Richtungssteuerungs-Pins des Motors Gruppe B
int left_pwm = 5;//Definiere die PWM-Steuerungs-Pins des Motors Gruppe B
int right_ctrl = 4;//Definiere die Richtungssteuerungs-Pins des Motors Gruppe A
int right_pwm = 6;//Definiere die PWM-Steuerungs-Pins des Motors Gruppe A

#include <Servo.h>
Servo servo_A3;//Setze den Pin des Servos auf A3 

unsigned char data_line = 0;
unsigned char delay_count = 0;

void setup() {
  Serial.begin(9600);//
  // Falls der Interrupt-Treiber beim Setup abstürzt, gibt dies dem Benutzer einen Hinweis,
  // was gerade passiert.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Starte den Empfänger
  Serial.println("Enabled IRin");
  pinMode(left_ctrl,OUTPUT);//Setze Richtungssteuerungs-Pins des Gruppe B Motors auf OUTPUT
  pinMode(left_pwm,OUTPUT);//Setze PWM-Steuerungs-Pins des Gruppe B Motors auf OUTPUT
  pinMode(right_ctrl,OUTPUT);//Setze Richtungssteuerungs-Pins des Gruppe A Motors auf OUTPUT
  pinMode(right_pwm,OUTPUT);//Setze PWM-Steuerungs-Pins des Gruppe A Motors auf OUTPUT
  servo_A3.attach(A3);
  servo_A3.write(90);//Der Winkel des Servos ist 90 Grad
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Setze den Clock-Pin auf Ausgang
  pinMode(SDA_Pin,OUTPUT);//Setze den Daten-Pin auf Ausgang
  matrix_display(clear);
  matrix_display(start01); //zeige das Start01 Ausdrucksmuster an
}

void loop()
 {
  if (irrecv.decode(&results)) 
 {
    irr_val = results.value;
    Serial.println(irr_val, HEX);//Serielle Ausgabe der gelesenen IR-Fernbedienungssignale 
    switch(irr_val)
    {
      case 0xFF629D : car_front(); //Empfange 0xFF629D, das Auto fährt vorwärts
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 0xFFA857 : car_back(); //Empfange 0xFFA857, das Auto fährt rückwärts
      matrix_display(clear);
      matrix_display(back); 
      break;
    
      case 0xFF22DD : car_left(); //Empfange 0xFF22DD, das Auto dreht nach links
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 0xFFC23D : car_right();//Empfange 0xFFC23D, das Auto dreht nach rechts
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 0xFF02FD : car_Stop();//Empfange 0xFF02FD, das Auto stoppt
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
    }
        irrecv.resume(); // Empfange den nächsten Wert
  }
}

void car_front()//definiert den Zustand des Vorwärtsfahrens
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,105);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,105);
}
void car_back()//definiert den Zustand des Rückwärtsfahrens
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void car_left()//setzt den Zustand des Linksabbiegens
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//setzt den Zustand des Rechtsabbiegens
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//definiert den Zustand des Anhaltens
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

//diese Funktion wird für die Punktmatrixanzeige verwendet
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //die Funktion, die die Startbedingung der Datenübertragung aufruft
  IIC_send(0xc0);  //Adresse auswählen

  for (int i = 0; i < 16; i++) //die Musterdaten sind 16 Bytes
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
//*******************************************************************************
```

### **5. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie die externe Stromversorgung ein und stellen Sie dann den DIP-Schalter auf ON. Danach können wir die IR-Fernbedienung verwenden, um das Auto zu steuern, und die 8X16 LED-Anzeige zeigt das entsprechende Statusmuster an.