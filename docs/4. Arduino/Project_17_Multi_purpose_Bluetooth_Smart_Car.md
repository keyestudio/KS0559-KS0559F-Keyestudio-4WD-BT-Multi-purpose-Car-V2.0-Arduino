# Projekt 17 Multifunktionales Bluetooth Smart Car

![2c1198e0ebd7c31622b7438469fb572c](media/A138.jpeg)

### **1. Beschreibung**

In vorherigen Projekten führt das Auto nur eine einzelne Funktion aus. In dieser Lektion werden wir jedoch alle seine Funktionen über Bluetooth integrieren.

### **2. Flussdiagramm**

![73f4da1e321bc29282d3b2f5cb3168dd](media/A139.png)

### **3. Schaltplan**

![fce8edd349ddbcfe02e6f27feb73e90f](media/A140.png)

1). GND, VCC, SDA und SCL des 8\*8 LED-Boards sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). RXD, TXD, GND und VCC des Bluetooth-Moduls sind jeweils mit TX, RX, G und 5V auf dem 8833 Motor Shield verbunden, während die STATE- und BRK-Pins des Bluetooth-Moduls nicht angeschlossen werden müssen.

3). Der Servo ist mit G, V und A3 verbunden. Der braune Draht ist mit Gnd (G), der rote Draht mit 5V (V) und der orange Draht mit A3 verbunden.

4). G, V, S1, S2 und S3 des Linienverfolgungssensors sind mit G (GND), V (VCC), D11, D7 und D8 des Sensor-Erweiterungsboards verbunden.

5). VCC, Trig, Echo und Gnd des Ultraschallsensors sind mit 5V (V), D12 (S), D13 (S) und Gnd (G) verbunden.

6). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

<span style="color: rgb(255, 76, 65);">**Hinweis:** Vor dem Hochladen des Testcodes muss das Bluetooth-Modul entfernt werden, da sonst der Code nicht hochgeladen werden kann. Verbinden Sie das Bluetooth-Modul erst nach erfolgreichem Hochladen des Codes.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 17
Bluetooth Multifunctional Car
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
unsigned char speed_a[] = 
{0x00,0x40,0x20,0x10,0x08,0x04,0x02,0xff,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00};
unsigned char speed_d[] = 
{0x00,0x02,0x04,0x08,0x10,0x20,0x40,0xff,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00};

int left_ctrl = 2; //definiere die Richtungskontrollpins des Motors Gruppe B
int left_pwm = 5;  //definiere die PWM-Kontrollpins des Motors Gruppe B
int right_ctrl = 4; //definiere die Richtungskontrollpins des Motors Gruppe A
int right_pwm = 6;  //definiere die PWM-Kontrollpins des Motors Gruppe A
int speeds = 150;   //Setze die Anfangsgeschwindigkeit auf 150

const int servopin = A3; //setze den Pin des Servos auf A3 

int L_pin = 11; //definiere den linken Tracking-Sensor-Pin als D11
int M_pin = 7;  //definiere den mittleren Tracking-Sensor-Pin als D7
int R_pin = 8;  //definiere den rechten Tracking-Sensor-Pin als D8
int L_val, M_val, R_val;

int trigPin = 12; //TRIG-Pin ist mit D12 verbunden
int echoPin = 13; //ECHO-Pin ist mit D13 verbunden
int distance, distance_l, distance_r;

char BLE_val;

void setup() {
  Serial.begin(9600);//Setze Baudrate auf 9600
  pinMode(left_ctrl,OUTPUT);//Setze Richtungssteuerungs-Pins des Motors Gruppe B auf OUTPUT
  pinMode(left_pwm,OUTPUT);//Setze PWM-Steuerungs-Pins des Motors Gruppe B auf OUTPUT
  pinMode(right_ctrl,OUTPUT);//Setze Richtungssteuerungs-Pins des Motors Gruppe A auf OUTPUT
  pinMode(right_pwm,OUTPUT);//Setze PWM-Steuerungs-Pins des Motors Gruppe A auf OUTPUT
  servopulse(servopin,90);//Der Winkel des Servos ist 90 Grad
  delay(300);
  pinMode(L_pin, INPUT); //Tracking-Sensor-Pins werden als Eingabemodus konfiguriert
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(trigPin, OUTPUT); //Definiere TRIG als Ausgangsmodus
  pinMode(echoPin, INPUT); //Definiere ECHO als Eingabemodus
  pinMode(SCL_Pin,OUTPUT);// Setze den Clock-Pin auf Ausgang
  pinMode(SDA_Pin,OUTPUT);//Setze den Daten-Pin auf Ausgang
  matrix_display(clear);
  matrix_display(start01); //zeige das Ausdrucksmuster start01 an
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
    
      case  'U':  follow();  //Empfange ‘U’, betrete Follow-Modus
      break; 
      case  'Y':  avoid(); //Empfange ‘Y’, betrete Hindernisvermeidungsmodus  
      break;  
      case  'G':  confinement(); //Empfange ‘G’, betrete Einschlussmodus
      break;  
      case  'X':  tracking(); //Empfange ‘X’, betrete Tracking-Modus
      break;  
    }
}

void car_front()//definiere den Zustand Vorwärtsfahren
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//definiere den Zustand Rückwärtsfahren
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//setze den Zustand Linkskurve
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//setze den Zustand Rechtskurve
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//definiere den Zustand Stop
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //Funktion für schnelles Beschleunigen
  while (1) {
    Serial.println(speeds);  //zeige Geschwindigkeitsinformationen an
    if (speeds < 255) { //Bis zu 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //passe die Geschwindigkeit des Wachstums an
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Empfange 'S', das Auto hört auf zu beschleunigen
    break;
  }
}
void speeds_d() { //Funktion zur Geschwindigkeitsreduzierung
  while (1) {
    Serial.println(speeds);  //zeige Geschwindigkeitsinformationen an
    if (speeds > 0) { //Bis auf 0
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

int get_distance() {
  int distance = 0;
  digitalWrite(trigPin, LOW);     // sende Impuls über Trig/Pin, löse HC-SR04 Abstandsmessung aus, sodass das Ultraschallsignal Interface 2μs lang auf Low-Pegel gesetzt wird
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);    // setze Ultraschallsignal Interface für mindestens 10μs auf High-Pegel
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);     // halte das Ultraschallsignal Interface auf Low-Pegel
  distance = pulseIn(echoPin, HIGH) / 58; // lese die Impulsdauer und wandle die Impulsdauer in die Entfernung um (Einheit: cm)
  Serial.println(distance);        // Ausgabe des Entfernungswerts
  return distance;
}

void follow() {
  servopulse(servopin,90);
  delay(200);
  int follow_flag = 1;
  while (follow_flag) {
    distance = get_distance(); // rufe die Abstandsmessfunktion auf
    if (distance < 8 ) {// Wenn die Entfernung kleiner als 8 ist
      car_back();// fährt das Auto rückwärts
      matrix_display(clear);
      matrix_display(back); 
    }
    else if (distance >= 8 && distance < 13) { // Wenn die Entfernung größer oder gleich 8 und kleiner als 13 ist
      car_Stop();// stoppt
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    else if (distance >= 13 && distance <= 35 ) { // Wenn die Entfernung größer oder gleich 13 und kleiner oder gleich 35 ist
      car_front();// fährt das Auto vorwärts
      matrix_display(clear);
      matrix_display(front);
    }
    else {// Wenn keine der obigen Bedingungen zutrifft
      car_Stop();// stoppt
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // Wenn 'S' empfangen wird, stoppt das Auto
      follow_flag = 0;
      car_Stop();
    }
  }
}

void avoid() {
  int avoid_flag = 1;
  while (avoid_flag) {
    distance = get_distance(); // Rufe die Abstandsmessfunktion auf
    if (distance > 0 && distance < 20) { // Wenn die Entfernung kleiner als 20 und größer als 0 ist
      car_Stop();// stoppt
      matrix_display(clear);
      matrix_display(STOP01);   // die Punktmatrix zeigt ein Stop-Muster an
      delay(1000);
      servopulse(servopin,160); // dreht das Servomotor über 180 Grad
      delay(500);
      distance_l = get_distance(); // ermittelt die linke Entfernung
      delay(100);
      servopulse(servopin,20); // dreht das Servomotor auf 0 Grad
      delay(500);
      distance_r = get_distance(); // ermittelt die rechte Entfernung
      delay(100);
      if (distance_l > distance_r) { // vergleicht die Entfernungen, wenn links größer als rechts ist
        car_left();  // dreht das Auto nach links
        matrix_display(clear);
        matrix_display(left);   // die Punktmatrix zeigt ein Links-Muster an
        servopulse(servopin,90);// das Servomotor kehrt auf 90 Grad zurück
        delay(700);
        matrix_display(clear);
        matrix_display(front);   // die Punktmatrix zeigt ein Vorwärts-Muster an
      } 
      else { // Andernfalls, wenn rechts größer als links ist
        car_right();// dreht das Auto nach rechts
        matrix_display(clear);
        matrix_display(right);   // die Punktmatrix zeigt ein Rechts-Muster an
        servopulse(servopin,90);// das Servomotor kehrt auf 90 Grad zurück
        delay(700);
        matrix_display(clear);
        matrix_display(front);   // die Punktmatrix zeigt ein Vorwärts-Muster an
      }
    }
    else { // Wenn die Entfernung vor dem Auto größer oder gleich 20 cm ist
      car_front();// fährt das Auto vorwärts
      matrix_display(clear);
      matrix_display(front);   // die Punktmatrix zeigt ein Vorwärts-Muster an

    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') {// Wenn 'S' empfangen wird, stoppt das Auto
      avoid_flag = 0;
      car_Stop();
    }
  }
}

void confinement() {
  int confinement_flag = 1;
  while (confinement_flag) {
    L_val = digitalRead(L_pin); // Wert des linken Sensors lesen
    M_val = digitalRead(M_pin); // Wert des mittleren Sensors lesen
    R_val = digitalRead(R_pin); // Wert des rechten Sensors lesen
    if ( L_val == 0 && M_val == 0 && R_val == 0 ) { // Das Auto fährt vorwärts, wenn keine schwarze Linie erkannt wird
      car_front();
    }
    else { // Andernfalls, wenn einer der Tracking-Sensoren eine schwarze Linie erkennt, fährt das Auto rückwärts und dreht dann nach links
      car_back();
      delay(500);
      car_left();
      delay(800);
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // Wenn 'S' empfangen wird, stoppt das Auto
      confinement_flag = 0;
      car_Stop();
    }
  }
}

void tracking() {
  int track_flag = 1;
  while (track_flag) {
    L_val = digitalRead(L_pin); // Wert des linken Sensors lesen
    M_val = digitalRead(M_pin); // Wert des mittleren Sensors lesen
    R_val = digitalRead(R_pin); // Wert des rechten Sensors lesen
    if (M_val == 1) { // Schwarze Linie in der Mitte erkannt
      if (L_val == 1 && R_val == 0) { // Wenn eine schwarze Linie links erkannt wird, aber nicht rechts, nach links abbiegen
        car_left();
      }
      else if (L_val == 0 && R_val == 1) { // Andernfalls, wenn eine schwarze Linie rechts erkannt wird, aber nicht links, nach rechts abbiegen
        car_right();
      }
      else { // Andernfalls fährt das Auto vorwärts
        car_front();
      }
    }
    else { // keine schwarze Linie in der Mitte erkannt
      if (L_val == 1 && R_val == 0) { // Wenn eine schwarze Linie links erkannt wird, aber nicht rechts, nach links abbiegen
        car_right();
      }
      else if (L_val == 0 && R_val == 1) { // Andernfalls, wenn eine schwarze Linie rechts erkannt wird, aber nicht links, nach rechts abbiegen
        car_right();;
      }
      else { // Andernfalls anhalten
        car_Stop();
      }
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // Wenn 'S' empfangen wird, stoppt das Auto
      track_flag = 0;
      car_Stop();
    }
  }
}

void servopulse(int servopin,int myangle)// Lenkgetriebe Laufwinkel
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

// Diese Funktion wird für die Punktmatrixanzeige verwendet
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  // Funktion, die die Startbedingung für die Datenübertragung aufruft
  IIC_send(0xc0);  // Adresse auswählen

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

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie die externe Stromversorgung ein und stellen Sie den DIP-Schalter auf ON.

Nachdem das Bluetooth-Modul in die APP eingesteckt wurde und die mobile APP erfolgreich mit dem Bluetooth verbunden ist, kann das Smart Car über die mobile APP gesteuert werden. Wir können die entsprechenden Funktionen durch Drücken der entsprechenden Tasten in der mobilen APP erreichen. 