# Project 16 Bluetooth Snelheidsregeling Slimme Auto

![](media/A131.jpeg)

### **1.Beschrijving**

In dit project gebruiken we Bluetooth om de snelheid van de slimme auto aan te passen. We definiëren variabele snelheden en veranderen deze om de snelheid van de slimme auto te regelen.

### **2.Stroomschema**

![90ab1f7fb1e16ad3c018b1c631e407c3](media/A134.png)

### **3.Aansluitschema**

![](media/A135.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-bord zijn verbonden met G (GND), V (VCC), A4 en A5 van het uitbreidingsbord.

2). De RXD, TXD, GND en VCC van de Bluetooth-module zijn respectievelijk verbonden met TX, RX, G en 5V op de 8833 motor Shield, terwijl de STATE en BRK pinnen van de Bluetooth-module niet hoeven te worden aangesloten.

3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad op 5V (V) en de oranje draad op A3.

4). De voeding is aangesloten op de BAT-poort.

### **4.Testcode**

<span style="color: rgb(255, 76, 65);">**Opmerking:** Verwijder de Bluetooth-module voordat je de testcode uploadt, anders kan de code niet worden geüpload. Sluit de Bluetooth-module pas aan nadat de code succesvol is geüpload.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
les 16
Bluetooth Snelheidsregeling Auto
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

char BLE_val;

void setup() {
  Serial.begin(9600);//
  pinMode(left_ctrl,OUTPUT);//stel richtingsbesturingspinnen van motor groep B in als OUTPUT
  pinMode(left_pwm,OUTPUT);//stel PWM-besturingspinnen van motor groep B in als OUTPUT
  pinMode(right_ctrl,OUTPUT);//stel richtingsbesturingspinnen van motor groep A in als OUTPUT
  pinMode(right_pwm,OUTPUT);//stel PWM-besturingspinnen van motor groep A in als OUTPUT
  servopulse(servopin,90);//de hoek van de servo is 90 graden
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Stel de klokpin in als output
  pinMode(SDA_Pin,OUTPUT);//Stel de datapin in als output
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
    }
}

void car_front()//definieer de status van vooruit rijden
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//definieer de status van achteruit rijden
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//stel de status van linksaf slaan in
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//stel de status van rechtsaf slaan in
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//definieer de status van stoppen
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //functie voor snel toenemen
  while (1) {
    Serial.println(speeds);  //snelheidsinformatie weergeven
    if (speeds < 255) { //tot 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //pas de snelheid van toename aan
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Ontvang 'S', de auto stopt met versnellen
    break;
  }
}
void speeds_d() { //functie voor snelheidsvermindering
  while (1) {
    Serial.println(speeds);  //snelheidsinformatie weergeven
    if (speeds > 0) { //tot 0
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //pas de snelheid van vertraging aan
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Ontvang 'S', de auto stopt met vertragen
    break;
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
  IIC_start();  //de functie die de startconditie van datatransmissie aanroept
  IIC_send(0xc0);  //selecteer adres

  for (int i = 0; i < 16; i++) //de patroon data is 16 bytes
  {
    IIC_send(matrix_value[i]); //Zend de data van het patroon
  }
  IIC_end();   //Beëindig de overdracht van patroon data
  IIC_start();
  IIC_send(0x8A);  //Display controle, selecteer 4/16 pulsbreedte
  IIC_end();
}
//Voorwaarden waaronder de dataoverdracht begint
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Geeft het einde van de dataoverdracht aan
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
//zend data
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Elke byte heeft 8 bits en wordt bit voor bit gecontroleerd beginnend bij het laagste niveau
  {
    if (send_data & mask) { //Stelt de hoge en lage niveaus van SDA_Pin in afhankelijk van of elk bit van de byte een 1 of een 0 is
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Trek de klokpin SCL_Pin hoog om de dataoverdracht te stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //trek de klokpin SCL_Pin laag om het SIGNaal van SDA te veranderen
  }
}
//*******************************************************************************
```

### **5. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet de externe voeding aan en zet vervolgens de DIP-schakelaar op ON. Koppel de APP via Bluetooth, de slimme auto kan worden bestuurd om te bewegen via de APP.

Druk op ![049343f587e0e7cf19fe8b665d735321](media/A136.png), de auto zal versnellen, druk op ![264f77cce6018584b54f46676fee4247](media/A137.png), de auto zal vertragen, en het 8\*16 LED-bord zal het overeenkomstige statuspatroon van de slimme auto weergeven.