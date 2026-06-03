# Project 13 Ultrasonic Obstakel Vermijdende Slimme Auto

![fd4044796307f709987b9d2e215e0911](media/A119.png)

### **1.Beschrijving**

In dit project willen we een ultrasone obstakel vermijdende slimme auto maken. We zullen de ultrasone sensor gebruiken om de afstand tot het obstakel te detecteren, wat gebruikt kan worden om de servo te besturen zodat deze draait en de auto kan bewegen. Tegelijkertijd zal het 8X16 LED-bord het bijbehorende statuspatroon weergeven.

### **2.Stroomschema**

![img](media/A120.png)

**De specifieke logica van de ultrasone obstakel vermijdende slimme auto wordt hieronder weergegeven:**

![Img](media/A121.png)

![Img](media/A122.png)

### **3.Aansluitschema**

![](media/A118.png)

1). GND, VCC, SDA en SCL van de 8\*8 LED-bordmodule zijn verbonden met G (GND), V (VCC), A4 en A5 van het uitbreidingsbord.

2). VCC, Trig, Echo en Gnd van de ultrasone sensor zijn verbonden met 5V (V), D12 (S), D13 (S) en Gnd (G).

3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad is aangesloten op 5V (V) en de oranje draad is aangesloten op A3.

4). De voeding is aangesloten op de BAT-poort.

### **4.Testcode**

```c 
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 les 13
 Vermijdende Auto
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  // Stel de klokpin in op A5
#define SDA_Pin  A4  // Stel de datapin in op A4
//Array, gebruikt om de data van het patroon op te slaan, kan zelf berekend worden of verkregen via de modulus tool
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//definieer de richtingsbesturingspinnen van motor groep B
int left_pwm = 5;//definieer de PWM-besturingspinnen van motor groep B
int right_ctrl = 4;//definieer de richtingsbesturingspinnen van motor groep A
int right_pwm = 6;//definieer de PWM-besturingspinnen van motor groep A

#include "SR04.h"//definieer de bibliotheek van de ultrasone sensor
#define TRIG_PIN 12// stel het signaaluitgang van de ultrasone sensor in op D12 
#define ECHO_PIN 13//stel het signaalingang van de ultrasone sensor in op D13 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance,a1,a2;//definieer drie afstanden
const int servopin = A3;//stel de pin van de servo in op A3 

void setup() {
  pinMode(left_ctrl,OUTPUT);//stel de richtingsbesturingspinnen van motor groep B in als OUTPUT
  pinMode(left_pwm,OUTPUT);//stel de PWM-besturingspinnen van motor groep B in als OUTPUT
  pinMode(right_ctrl,OUTPUT);//stel de richtingsbesturingspinnen van motor groep A in als OUTPUT
  pinMode(right_pwm,OUTPUT);//stel de PWM-besturingspinnen van motor groep A in als OUTPUT
  pinMode(TRIG_PIN, OUTPUT); //Stel de trig pin in als output
  pinMode(ECHO_PIN, INPUT); //Stel de echo pin in als input
  servopulse(servopin,90);//de hoek van de servo is 90 graden
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Stel de klokpin in als output
  pinMode(SDA_Pin,OUTPUT);//Stel de datapin in als output
  matrix_display(clear);
}
 
void loop()
 {
  avoid();//voer het hoofdprogramma uit
}

void avoid()
{
  distance=sr04.Distance(); //verkrijg de waarde gedetecteerd door de ultrasone sensor 

  if((distance < 20)&&(distance != 0))//als de afstand groter is dan 0 en kleiner dan 10  

  {
    car_Stop();//stop
    matrix_display(clear);
    matrix_display(STOP01);//toon stop patroon
    delay(1000);
    servopulse(servopin,160);//servo draait naar 160°
    delay(500);
    a1=sr04.Distance();//meet de afstand
    delay(100);
    servopulse(servopin,20);//draai naar 20 graden
    delay(500);
    a2=sr04.Distance();//meet de afstand
    delay(100);
    servopulse(servopin,90);  //Keer terug naar de 90 graden positie
    delay(500);
    if(a1 > a2)//vergelijk de afstand, als de linker afstand groter is dan de rechter afstand
    {
      car_left();//sla linksaf
      matrix_display(clear);
      matrix_display(left);    //toon linksaf patroon
      servopulse(servopin,90);//servo draait naar 90 graden
      delay(700); //sla 700ms linksaf
      matrix_display(clear);
      matrix_display(front);  //toon vooruit patroon
    }
    else//als de rechter afstand groter is dan de linker
    {
      car_right();//sla rechtsaf
      matrix_display(clear);
      matrix_display(right);  //toon rechtsaf patroon
      servopulse(servopin,90);//servo draait naar 90 graden
      delay(700);
      matrix_display(clear);
      matrix_display(front);  //toon vooruit patroon
    }
  }
  else//anders
  {
    car_front();//rij vooruit
    matrix_display(clear);
    matrix_display(front);  // toon vooruit patroon
  }
}

void car_front()//auto rijdt vooruit
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//rij achteruit
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//auto slaat linksaf
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//auto slaat rechtsaf
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//stop
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//de draaihoek van de servo
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

//deze functie wordt gebruikt voor dot matrix display
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //de functie die de startconditie van datatransfer aanroept
  IIC_send(0xc0);  //selecteer adres

  for (int i = 0; i < 16; i++) //de patroon data is 16 bytes
  {
    IIC_send(matrix_value[i]); //Zend de data van het patroon
  }
  IIC_end();   //Einde van patroon data transmissie
  IIC_start();
  IIC_send(0x8A);  //Display controle, selecteer 4/16 pulsbreedte
  IIC_end();
}
//Voorwaarden waaronder datatransmissie begint
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Geeft het einde van datatransmissie aan
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
    digitalWrite(SCL_Pin, HIGH); //Trek de klokpin SCL_Pin hoog om datatransmissie te stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //trek de klokpin SCL_Pin laag om het SIGNaal van SDA te veranderen
  }
}
//******************************************************************************
```

### **5. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet de externe voeding aan en zet vervolgens de DIP-schakelaar op ON.

De slimme auto rijdt vooruit en ontwijkt automatisch obstakels. Wanneer er geen weg vooruit is, zal de servo de ultrasone sensor aansturen om de afstanden links, midden en rechts te scannen, en zal de auto naar de open zijde draaien. Ondertussen zal het 8X16 LED-bord het overeenkomstige statuspatroon weergeven.