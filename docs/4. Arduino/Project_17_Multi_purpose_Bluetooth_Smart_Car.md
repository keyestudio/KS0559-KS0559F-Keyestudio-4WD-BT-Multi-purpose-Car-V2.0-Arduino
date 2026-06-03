# Project 17 Multi-purpose Bluetooth Smart Car

![2c1198e0ebd7c31622b7438469fb572c](media/A138.jpeg)

### **1.Beschrijving**

In eerdere projecten voert de auto slechts één enkele functie uit. In deze les zullen we echter al zijn functies integreren via Bluetooth.

### **2.Stroomschema**

![73f4da1e321bc29282d3b2f5cb3168dd](media/A139.png)

### **3.Aansluitschema**

![fce8edd349ddbcfe02e6f27feb73e90f](media/A140.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-bord zijn verbonden met G (GND), V (VCC), A4 en A5 van het uitbreidingsbord.

2). De RXD, TXD, GND en VCC van de Bluetooth-module zijn respectievelijk verbonden met TX, RX, G en 5V op de 8833 motor Shield, terwijl de STATE- en BRK-pinnen van de Bluetooth-module niet hoeven te worden aangesloten.

3). De servo is verbonden met G, V en A3. De bruine draad is verbonden met Gnd (G), de rode draad is verbonden met 5V (V) en de oranje draad is verbonden met A3.

4). G, V, S1, S2 en S3 van de lijnvolgsensor zijn verbonden met G (GND), V (VCC), D11, D7 en D8 van het sensor uitbreidingsbord.

5). VCC, Trig, Echo en Gnd van de ultrasone sensor zijn verbonden met 5V (V), D12 (S), D13 (S) en Gnd (G).

6). De voeding is verbonden met de BAT-poort.

### **4.Testcode**

<span style="color: rgb(255, 76, 65);">**Opmerking:** Verwijder de Bluetooth-module voordat je de testcode uploadt, anders kan de code niet worden geüpload. Verbind de Bluetooth-module pas nadat de code succesvol is geüpload.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
les 17
Bluetooth multifunctionele auto
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Stel de klokpin in op A5
#define SDA_Pin  A4  //Stel de datapin in op A4
//Array, gebruikt om de gegevens van het patroon op te slaan, kan zelf worden berekend of verkregen via de modulus tool
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

int left_ctrl = 2;//definieer de richtingsbesturingspinnen van motor groep B
int left_pwm = 5;//definieer de PWM-besturingspinnen van motor groep B
int right_ctrl = 4;//definieer de richtingsbesturingspinnen van motor groep A
int right_pwm = 6;//definieer de PWM-besturingspinnen van motor groep A
int speeds = 150; //Stel de beginsnelheid in op 150

const int servopin = A3;//stel de pin van de servo in op A3 

int L_pin = 11; //definieer de linker lijnvolgsensor pin als D11
int M_pin = 7; //definieer de middelste lijnvolgsensor pin als D7
int R_pin = 8; //definieer de rechter lijnvolgsensor pin als D8
int L_val, M_val, R_val;

int trigPin = 12; //TRIG pin verbonden met D12
int echoPin = 13; //ECHO pin verbonden met D13
int distance, distance_l, distance_r;

char BLE_val;

void setup() {
  Serial.begin(9600);//Stel baudrate in op 9600
  pinMode(left_ctrl,OUTPUT);//stel richtingbesturingspinnen van groep B motor in op OUTPUT
  pinMode(left_pwm,OUTPUT);//stel PWM-besturingspinnen van groep B motor in op OUTPUT
  pinMode(right_ctrl,OUTPUT);//stel richtingbesturingspinnen van groep A motor in op OUTPUT
  pinMode(right_pwm,OUTPUT);//stel PWM-besturingspinnen van groep A motor in op OUTPUT
  servopulse(servopin,90);//de hoek van de servo is 90 graden
  delay(300);
  pinMode(L_pin, INPUT); //Tracking sensorpinnen zijn geconfigureerd voor inputmodus
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(trigPin, OUTPUT); //definieer TRIG als outputmodus
  pinMode(echoPin, INPUT); //definieer ECHO als inputmodus
  pinMode(SCL_Pin,OUTPUT);// Stel de klokpin in op output
  pinMode(SDA_Pin,OUTPUT);//Stel de datapin in op output
  matrix_display(clear);
  matrix_display(start01); //toon start01 expressiepatroon
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
    
      case  'U':  follow();  //Ontvang ‘U’, ga naar volgmodus
      break; 
      case  'Y':  avoid(); //Ontvang ‘Y’, ga naar obstakelvermijdingsmodus  
      break;  
      case  'G':  confinement(); //Ontvang ‘G’, ga naar begrenzingsmodus
      break;  
      case  'X':  tracking(); //Ontvang ‘X’, ga naar volgmodus
      break;  
    }
}

void car_front()//definieer de toestand van vooruit rijden
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//definieer de toestand van achteruit rijden
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//stel de toestand van linksaf slaan in
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//stel de toestand van rechtsaf slaan in
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//definieer de toestand van stoppen
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //functie voor snelheidsverhoging
  while (1) {
    Serial.println(speeds);  //toon snelheidsinformatie 
    if (speeds < 255) { //tot 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //pas de snelheid van de toename aan 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Ontvang 'S', de auto stopt met versnellen
    break;
  }
}
void speeds_d() { //functie voor snelheidsvermindering
  while (1) {
    Serial.println(speeds);  //toon snelheidsinformatie
    if (speeds > 0) { //tot 0
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //pas de snelheid van de vertraging aan
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Ontvang 'S', de auto stopt met vertragen
    break;
}
}

int get_distance() {
  int distance = 0;
  digitalWrite(trigPin, LOW);     // stuur puls via Trig/Pin, activeer HC-SR04 afstandsmeting, zodat het ultrasone signaalinterface laag niveau 2μs uitzendt
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);    // maak ultrasoon signaalinterface hoog niveau 10μs, hier minimaal 10μs
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);     // houd het ultrasone signaalinterface laag niveau
  distance = pulseIn(echoPin, HIGH) / 58; // lees de pulstijd en zet de pulstijd om naar afstand (eenheid: cm)
  Serial.println(distance);        // output afstandswaarde
  return distance;
}

void follow() {
  servopulse(servopin,90);
  delay(200);
  int follow_flag = 1;
  while (follow_flag) {
    distance = get_distance(); //roep de afstandsmeetfunctie aan
    if (distance < 8 ) {//Als de afstand minder is dan 8
      car_back();//rijdt de auto achteruit
      matrix_display(clear);
      matrix_display(back); 
    }
    else if (distance >= 8 && distance < 13) { //Als de afstand groter dan of gelijk aan 8 is, maar minder dan 13
      car_Stop();//stoppen
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    else if (distance >= 13 && distance <= 35 ) { //Als de afstand groter dan of gelijk aan 13 is, maar minder dan of gelijk aan 35
      car_front();//rijdt de auto vooruit
      matrix_display(clear);
      matrix_display(front);
    }
    else {//Als geen van bovenstaande
      car_Stop();//stoppen
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { //Wanneer S wordt ontvangen, stopt de auto
      follow_flag = 0;
      car_Stop();
    }
  }
}

void avoid() {
  int avoid_flag = 1;
  while (avoid_flag) {
    distance = get_distance(); //roep de afstandsmeetfunctie aan
    if (distance > 0 && distance < 20) { //Als de afstand minder is dan 20 en groter dan 0
      car_Stop();//stoppen
      matrix_display(clear);
      matrix_display(STOP01);   //de dot matrix toont een stop patroon
      delay(1000);
      servopulse(servopin,160); //breng het stuurmechanisme over 180 graden
      delay(500);
      distance_l = get_distance(); //meet de linker afstand 
      delay(100);
      servopulse(servopin,20); //draai het stuurmechanisme naar 0 graden
      delay(500);
      distance_r = get_distance(); //meet de rechter afstand
      delay(100);
      if (distance_l > distance_r) { //vergelijk de afstanden, als links groter is dan rechts
        car_left();  //de auto draait naar links
        matrix_display(clear);
        matrix_display(left);   //de dot matrix toont een links patroon
        servopulse(servopin,90);//het stuurmechanisme keert terug naar 90 graden
        delay(700);
        matrix_display(clear);
        matrix_display(front);   //de dot matrix toont een vooruit patroon
      } 
      else { //Anders als rechts groter is dan links
        car_right();//de auto draait naar rechts
        matrix_display(clear);
        matrix_display(right);   //de dot matrix toont een rechts patroon
        servopulse(servopin,90);//het stuurmechanisme keert terug naar 90 graden
        delay(700);
        matrix_display(clear);
        matrix_display(front);   //de dot matrix toont een vooruit patroon
      }
    }
    else { //Wanneer de afstand voor minder dan of gelijk aan 10cm is
      car_front();//rijdt de auto vooruit
      matrix_display(clear);
      matrix_display(front);   //de dot matrix toont een vooruit patroon

    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') {//Wanneer S wordt ontvangen, stopt de auto
      avoid_flag = 0;
      car_Stop();
    }
  }
}

void confinement() {
  int confinement_flag = 1;
  while (confinement_flag) {
    L_val = digitalRead(L_pin); //lees de waarde van de linkersensor
    M_val = digitalRead(M_pin); //lees de waarde van de middensensor
    R_val = digitalRead(R_pin); //lees de waarde van de rechtersensor
    if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //de auto gaat vooruit wanneer er geen zwarte lijn wordt gedetecteerd
      car_front();
    }
    else { //Anders, als een van de volg sensoren een zwarte lijn detecteert, gaat de auto achteruit en draait dan naar links
      car_back();
      delay(500);
      car_left();
      delay(800);
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { //Wanneer S wordt ontvangen, stopt de auto
      confinement_flag = 0;
      car_Stop();
    }
  }
}

void tracking() {
  int track_flag = 1;
  while (track_flag) {
    L_val = digitalRead(L_pin); //lees de waarde van de linkersensor
    M_val = digitalRead(M_pin); //lees de waarde van de middensensor
    R_val = digitalRead(R_pin); //lees de waarde van de rechtersensor
    if (M_val == 1) { //Zwarte lijn gedetecteerd in het midden
      if (L_val == 1 && R_val == 0) { //Als een zwarte lijn aan de linkerkant wordt gedetecteerd, maar niet aan de rechterkant, draai dan naar links
        car_left();
      }
      else if (L_val == 0 && R_val == 1) { //Anders, als een zwarte lijn aan de rechterkant wordt gedetecteerd en niet aan de linkerkant, draai dan naar rechts
        car_right();
      }
      else { //Anders gaat de auto vooruit
        car_front();
      }
    }
    else { //geen zwarte lijnen gedetecteerd in het midden
      if (L_val == 1 && R_val == 0) { //Als een zwarte lijn aan de linkerkant wordt gedetecteerd, maar niet aan de rechterkant, draai dan naar links
        car_right();
      }
      else if (L_val == 0 && R_val == 1) { //Anders, als een zwarte lijn aan de rechterkant wordt gedetecteerd en niet aan de linkerkant, draai dan naar rechts
        car_right();;
      }
      else { //Anders, stop
        car_Stop();
      }
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { //Wanneer S wordt ontvangen, stopt de auto
      track_flag = 0;
      car_Stop();
    }
  }
}

void servopulse(int servopin,int myangle)//Stuurservo draaihoek
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

//deze functie wordt gebruikt voor dot matrix display
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //de functie die de startconditie voor datatransfer aanroept
  IIC_send(0xc0);  //selecteer adres

  for (int i = 0; i < 16; i++) //de patroongegevens zijn 16 bytes
  {
    IIC_send(matrix_value[i]); //Zend de gegevens van het patroon
  }
  IIC_end();   //Beëindig de overdracht van patroongegevens
  IIC_start();
  IIC_send(0x8A);  //Displaycontrole, selecteer 4/16 pulsbreedte
  IIC_end();
}
//Voorwaarden waaronder gegevensoverdracht begint
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Geeft het einde van de gegevensoverdracht aan
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
//zend gegevens
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Elke byte heeft 8 bits en wordt bit voor bit gecontroleerd, beginnend bij het laagste niveau
  {
    if (send_data & mask) { //Stelt de hoge en lage niveaus van SDA_Pin in afhankelijk van of elk bit van de byte een 1 of een 0 is
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Trek de klokpin SCL_Pin hoog om de gegevensoverdracht te stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //trek de klokpin SCL_Pin laag om het SIGNaal van SDA te veranderen
  }
}
//*******************************************************************************
```

### **5. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, sluit de bedrading aan volgens het bedradingsschema, zet de externe voeding aan en zet vervolgens de DIP-schakelaar op AAN.

Nadat de Bluetooth-module is aangesloten op de APP en de mobiele APP succesvol is verbonden met de Bluetooth, kan de slimme auto worden bestuurd via de mobiele APP. We kunnen de bijbehorende functies bereiken door op de overeenkomstige knoppen op de mobiele APP te drukken.