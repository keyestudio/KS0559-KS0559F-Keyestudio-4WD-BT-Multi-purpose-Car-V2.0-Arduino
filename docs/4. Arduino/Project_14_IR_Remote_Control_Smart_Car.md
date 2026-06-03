# Project 14 IR Afstandsbediening Smart Car

![ff2fec813f8765e1bcd593b37b9c0a4f](media/A123.jpeg)

### **1.Beschrijving**

In dit project maken we een IR afstandsbediening smart car en drukken we op de knop van de IR afstandsbediening om de auto te laten bewegen.

### **2.Stroomschema**

![img](media/A124.png)

**De specifieke logica van de IR afstandsbediening smart car wordt hieronder weergegeven:**

| Initiële setup                          |           | LED-board toont glimlachend gezicht              |
| ------------------------------------- | --------- | ------------------------------------------------ |
| Afstandsbediening                     | Sleutelwaarde | Sleutelstatus                                    |
| ![img](media/A125.jpg)                | FF629D    | Vooruit8*8 LED-board toont voorwaarts icoon      |
| ![img](media/A126.jpg)                | FFA857    | Achteruit8*8 LED-board toont achterwaarts icoon  |
| ![img](media/A127.jpg)                | FF22DD    | Draai naar links8*8 LED-board toont links icoon  |
| ![img](media/A128.jpg)                | FFC23D    | Draai naar rechts8*8 LED-board toont rechts icoon|
| ![img](media/A129.jpg)                | FF02FD    | Stop8*8 LED-board toont “STOP”                    |

### **3.Aansluitschema**

![9d8b58dff14fe22b5c87514db944530c](media/A130.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-board module zijn verbonden met G (GND), V (VCC), A4 en A5 van de uitbreidingskaart.

2). Omdat de IR-ontvanger geïntegreerd is op de 8833 motor Shield, is extra bedrading niet nodig. De pinnen van de IR-ontvanger op de 8833 kaart zijn respectievelijk G (GND), V (VCC) en D3.

3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad op 5V (V) en de oranje draad op A3.

4). De voeding is aangesloten op de BAT-poort
    

### **4.Testcode**

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
les 14
IR afstandsbediening Auto
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Stel de klokpin in op A5
#define SDA_Pin  A4  //Stel de datapin in op A4
//Array, gebruikt om de gegevens van het patroon op te slaan, kan zelf berekend worden of verkregen via de modulus tool
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#include <Arduino.h>
#include <IRremote.h>//functie bibliotheek van IR afstandsbediening
int RECV_PIN = 3;//stel de pin van IR ontvanger in op D3
IRrecv irrecv(RECV_PIN);
long irr_val;
decode_results results;

int left_ctrl = 2;//definieer de richtingsbesturingspinnen van motor groep B
int left_pwm = 5;//definieer de PWM besturingspinnen van motor groep B
int right_ctrl = 4;//definieer de richtingsbesturingspinnen van motor groep A
int right_pwm = 6;//definieer de PWM besturingspinnen van motor groep A

#include <Servo.h>
Servo servo_A3;//stel de pin van servo in op A3 

unsigned char data_line = 0;
unsigned char delay_count = 0;

void setup() {
  Serial.begin(9600);//
  // Voor het geval de interrupt driver crasht bij het opstarten, geef een aanwijzing
  // aan de gebruiker wat er aan de hand is.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start de ontvanger
  Serial.println("Enabled IRin");
  pinMode(left_ctrl,OUTPUT);//stel de richtingsbesturingspinnen van groep B motor in op OUTPUT
  pinMode(left_pwm,OUTPUT);//stel de PWM-besturingspinnen van groep B motor in op OUTPUT
  pinMode(right_ctrl,OUTPUT);//stel de richtingsbesturingspinnen van groep A motor in op OUTPUT
  pinMode(right_pwm,OUTPUT);//stel de PWM-besturingspinnen van groep A motor in op OUTPUT
  servo_A3.attach(A3);
  servo_A3.write(90);//de hoek van de servo is 90 graden
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Stel de klokpin in op output
  pinMode(SDA_Pin,OUTPUT);//Stel de datapin in op output
  matrix_display(clear);
  matrix_display(start01); //toon start01 expressiepatroon
}

void loop()
 {
  if (irrecv.decode(&results)) 
 {
    irr_val = results.value;
    Serial.println(irr_val, HEX);//serieel print de gelezen IR afstandsbedieningssignalen 
    switch(irr_val)
    {
      case 0xFF629D : car_front(); //Ontvang 0xFF629D, de auto gaat vooruit
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 0xFFA857 : car_back(); //Ontvang 0xFFA857, de auto gaat achteruit
      matrix_display(clear);
      matrix_display(back); 
      break;
    
      case 0xFF22DD : car_left(); //Ontvang 0xFF22DD, de auto draait naar links
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 0xFFC23D : car_right();//Ontvang 0xFFC23D, de auto draait naar rechts
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 0xFF02FD : car_Stop();//Ontvang 0xFF02FD, de auto stopt
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
    }
        irrecv.resume(); // Ontvang de volgende waarde
  }
}

void car_front()//definieer de status van vooruit rijden
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,105);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,105);
}
void car_back()//definieer de status van achteruit rijden
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void car_left()//stel de status van linksaf draaien in
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//stel de status van rechtsaf draaien in
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//definieer de status van stoppen
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

//deze functie wordt gebruikt voor dot matrix display
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //de functie die de startconditie van datatransfer aanroept
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
//Voorwaarden waaronder dataoverdracht begint
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Geeft het einde van dataoverdracht aan
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

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet de externe voeding aan en zet vervolgens de DIP-schakelaar op ON. Daarna kunnen we de IR-afstandsbediening gebruiken om de auto te laten bewegen en zal het 8X16 LED-bord het overeenkomstige statuspatroon weergeven.