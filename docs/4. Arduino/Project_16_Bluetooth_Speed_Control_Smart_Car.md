# Projekt 16 Bluetooth Geschwindigkeitssteuerung Smart Car

![](media/A131.jpeg)

### **1. Beschreibung**

In diesem Projekt verwenden wir Bluetooth, um die Geschwindigkeit des Smart Cars anzupassen. Wir definieren variable Geschwindigkeiten und ändern diese, um die Geschwindigkeit des Smart Cars zu steuern.

### **2. Flussdiagramm**

![90ab1f7fb1e16ad3c018b1c631e407c3](media/A134.png)

### **3. Schaltplan**

![](media/A135.png)

1). GND, VCC, SDA und SCL des 8\*8 LED-Boards sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). RXD, TXD, GND und VCC des Bluetooth-Moduls sind jeweils mit TX, RX, G und 5V auf dem 8833 Motor Shield verbunden, während die STATE- und BRK-Pins des Bluetooth-Moduls nicht angeschlossen werden müssen.

3). Der Servo ist mit G, V und A3 verbunden. Der braune Draht ist mit Gnd (G), der rote Draht mit 5V (V) und der orange Draht mit A3 verbunden.

4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

<span style="color: rgb(255, 76, 65);">**Hinweis:** Vor dem Hochladen des Testcodes muss das Bluetooth-Modul entfernt werden, da sonst das Hochladen fehlschlägt. Verbinden Sie das Bluetooth-Modul erst nach erfolgreichem Hochladen des Codes wieder.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 16
Bluetooth Speed Control Car
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Setze den Clock-Pin auf A5
#define SDA_Pin  A4  //Setze den Daten-Pin auf A4
//Array, verwendet zur Speicherung der Musterdaten, kann selbst berechnet oder mit dem Modultool erhalten werden
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char speed_a[] = 
{0x00,0x40,0x20,0x10,0x08,0x04,0x02,0xff,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00};
unsigned char speed_d[] = 
{0x00,0x02,0x04,0x08,0x10,0x20,0x40,0xff,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00};

int left_ctrl = 2;//definiere die Richtungssteuerungs-Pins des Motors Gruppe B
int left_pwm = 5;//definiere die PWM-Steuerungs-Pins des Motors Gruppe B
int right_ctrl = 4;//definiere die Richtungssteuerungs-Pins des Motors Gruppe A
int right_pwm = 6;//definiere die PWM-Steuerungs-Pins des Motors Gruppe A

int speeds = 150; //Setze die Anfangsgeschwindigkeit auf 150

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
      case 'F' : car_front(); 
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); 
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); 
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
    
      case 'a' : speeds_a();
      matrix_display(clear);
      matrix_display(speed_a);  
      break;
     
      case 'd' : speeds_d();
      matrix_display(clear);
      matrix_display(speed_d); 
      break;
    }
}

void car_front()//definiere den Zustand des Vorwärtsfahrens
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//definiere den Zustand des Rückwärtsfahrens
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//setze den Zustand des Linksabbiegens
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//setze den Zustand des Rechtsabbiegens
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//definiere den Zustand des Anhaltens
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //Funktion für schnelles Beschleunigen
  while (1) {
    Serial.println(speeds);  //zeige Geschwindigkeitsinformationen an
    if (speeds < 255) { //bis zu 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //passe die Beschleunigungsgeschwindigkeit an
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Empfange 'S', das Auto hört auf zu beschleunigen
    break;
  }
}
void speeds_d() { //Funktion zur Geschwindigkeitsreduzierung
  while (1) {
    Serial.println(speeds);  //zeige Geschwindigkeitsinformationen an
    if (speeds > 0) { //bis auf 0
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //passe die Verzögerungsgeschwindigkeit an
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Empfange 'S', das Auto hört auf zu verzögern
    break;
}
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
  IIC_start();  //die Funktion, die die Startbedingung für die Datenübertragung aufruft
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
    if (send_data & mask) { // Setzt die High- und Low-Pegel von SDA_Pin abhängig davon, ob jedes Bit des Bytes eine 1 oder 0 ist
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); // Ziehe den Takt-Pin SCL_Pin auf High, um die Datenübertragung zu stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); // Ziehe den Takt-Pin SCL_Pin auf Low, um das SIGNAL von SDA zu ändern
  }
}
//*******************************************************************************
```

### **5. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie die externe Stromversorgung ein und stellen Sie den DIP-Schalter auf ON. Koppeln Sie die APP mit Bluetooth, kann das Smart Car über die APP gesteuert werden.

Drücken Sie ![049343f587e0e7cf19fe8b665d735321](media/A136.png), das Auto beschleunigt, drücken Sie ![264f77cce6018584b54f46676fee4247](media/A137.png), das Auto verlangsamt sich, und die 8\*16 LED-Anzeige zeigt das entsprechende Statusmuster des Smart Cars an.