# Projekt 15 Bluetooth-gesteuertes Smart Car

![8abdadfa2fc462bdcc0542df52a793e3](media/A131.jpeg)

### **1. Beschreibung**

Wir haben die Grundkenntnisse über Bluetooth gelernt. In dieser Lektion werden wir ein Bluetooth-gesteuertes Smart Car bauen. In diesem Projekt betrachten wir das Mobiltelefon als Sender (Host) und das Smart Car, das mit dem BT24 Bluetooth-Modul (Slave) verbunden ist, als Empfänger. Die Steuerung des Smart Cars erfolgt über die mobile APP via Bluetooth.

### **2. APP-Steuertasten**

|                           | Steuerzeichen                                              | Steuerzeichen                                              |
| ------------------------- | ---------------------------------------------------------- | ---------------------------------------------------------- |
| ![img](media/A63.jpg) | Drücken: F  <br />Loslassen: S                             | Taste drücken, das Auto fährt vorwärts; <br />loslassen zum Anhalten |
| ![img](media/A64.jpg) | Drücken: L  <br />Loslassen: S                             | Taste drücken, das Auto dreht nach links; <br />loslassen zum Anhalten  |
| ![img](media/A65.jpg) | Drücken: R  <br />Loslassen: S                             | Taste drücken, das Auto dreht nach rechts; <br />loslassen zum Anhalten |
| ![img](media/A66.jpg) | Drücken: B  <br />Loslassen: S                             | Taste drücken, das Auto fährt rückwärts; <br />loslassen zum Anhalten   |
| ![img](media/A67.jpg) | Drücken: „a“  <br />Loslassen: „S“                         | Klicken zum Beschleunigen (maximal: 255)                    |
| ![img](media/A68.jpg) | Drücken: „d“  <br />Loslassen: „S“                         | Klicken zum Verlangsamen (minimal: 0)                       |
| ![img](media/A69.jpg) | Klicken zum Starten der Schwerkraft- <br />erkennungsfunktion des <br />Mobiltelefons: erneut klicken zum <br />Beenden der Schwerkraftsteuerung |                                                              |
| ![img](media/A70.jpg) | Klicken zum Senden von „X“, <br />erneut klicken zum Senden von „S“ | Linienverfolgungsfunktion starten; <br />erneut klicken zum Beenden |
| ![img](media/A71.jpg) | Klicken zum Senden von „Y“, <br />erneut klicken zum Senden von „S“ | Ultraschall-Hindernisvermeidung starten; <br />erneut klicken zum Beenden |
| ![img](media/A72.jpg) | Klicken zum Senden von „U“, <br />erneut klicken zum Senden von „S“ | Ultraschall-Folgefunktion starten; <br />erneut klicken zum Beenden |
| ![img](media/A73.jpg) | Klicken zum Senden von „G“, <br />erneut klicken zum Senden von „S“ | Einschränkungsfunktion starten; <br />erneut klicken zum Beenden |

### **3. Flussdiagramm**

![img](media/A132.png)

### **4. Schaltplan**

![61be6959693b2111639252ea45ec60fc](media/A133.png)

1). GND, VCC, SDA und SCL der 8\*8 LED-Platine sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.
    
2). RXD, TXD, GND und VCC des Bluetooth-Moduls sind jeweils mit TX, RX, G und 5V auf dem 8833 Motor Shield verbunden, während die STATE- und BRK-Pins des Bluetooth-Moduls nicht angeschlossen werden müssen.
    
3). Das Servo ist mit G, V und A3 verbunden. Der braune Draht ist mit Gnd (G), der rote Draht mit 5V (V) und der orange Draht mit A3 verbunden.
    
4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.
    

### **5. Testcode**

<span style="color: rgb(255, 76, 65);">**Hinweis:** Vor dem Hochladen des Testcodes müssen Sie das Bluetooth-Modul entfernen, da sonst der Code nicht hochgeladen werden kann. Verbinden Sie das Bluetooth-Modul erst nach erfolgreichem Hochladen des Codes wieder.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Auto 
Lektion 15
Bluetooth Steuerung Auto
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Setze den Clock-Pin auf A5
#define SDA_Pin  A4  //Setze den Daten-Pin auf A4
//Array, verwendet zum Speichern der Musterdaten, kann selbst berechnet oder mit dem Modul-Tool erhalten werden
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//definiere die Richtungssteuerungs-Pins des Motors Gruppe B
int left_pwm = 5;//definiere die PWM-Steuerungs-Pins des Motors Gruppe B
int right_ctrl = 4;//definiere die Richtungssteuerungs-Pins des Motors Gruppe A
int right_pwm = 6;//definiere die PWM-Steuerungs-Pins des Motors Gruppe A

const int servopin = A3;//setze den Pin des Servos auf A3 

char BLE_val;

void setup() {
  Serial.begin(9600);//
  pinMode(left_ctrl,OUTPUT);//setze die Richtungssteuerungs-Pins des Motors Gruppe B auf OUTPUT
  pinMode(left_pwm,OUTPUT);//setze die PWM-Steuerungs-Pins des Motors Gruppe B auf OUTPUT
  pinMode(right_ctrl,OUTPUT);//setze die Richtungssteuerungs-Pins des Motors Gruppe A auf OUTPUT
  pinMode(right_pwm,OUTPUT);//setze die PWM-Steuerungs-Pins des Motors Gruppe A auf OUTPUT
  servopulse(servopin,90);//der Winkel des Servos ist 90 Grad
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Setze den Clock-Pin auf Ausgang
  pinMode(SDA_Pin,OUTPUT);//Setze den Daten-Pin auf Ausgang
  matrix_display(clear);
  matrix_display(start01); //zeige das Muster start01 an
}

void loop() {
   if(Serial.available()>0) {
    BLE_val = Serial.read();
    Serial.println(BLE_val);
  } 
    switch(BLE_val)
    {
      case 'F' : car_front(); //Empfange 'F', das Auto fährt vorwärts
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); //Empfange 'B', das Auto fährt rückwärts
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); //Empfange 'L', das Auto dreht nach links
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();//Empfange 'R', das Auto dreht nach rechts
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();//Empfange 'S', das Auto stoppt
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
}
}

void car_front()//definiere den Zustand Vorwärtsfahren
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//definiere den Zustand Rückwärtsfahren
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//setze den Zustand Linksdrehung
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//setze den Zustand Rechtsdrehung
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//definiere den Zustand Stop
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//Lenkgetriebe Laufwinkel
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
  IIC_start();  //die Funktion, die die Datenübertragungs-Startbedingung aufruft
  IIC_send(0xc0);  //Adresse auswählen

  for (int i = 0; i < 16; i++) //die Musterdaten sind 16 Bytes
  {
    IIC_send(matrix_value[i]); //Übertrage die Daten des Musters
  }
  IIC_end();   //Ende der Musterdatenübertragung
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

### **6. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten die externe Stromversorgung ein und stellen den DIP-Schalter auf ON.

Setzen Sie das BT-Modul ein und öffnen Sie Ihr Handy, um die Bluetooth-Verbindung herzustellen und das Smart Car zu steuern. Das Auto wird vorwärts, rückwärts fahren, nach links und rechts abbiegen und anhalten. Außerdem zeigt die 8\*8 LED-Anzeige die entsprechenden Muster an.