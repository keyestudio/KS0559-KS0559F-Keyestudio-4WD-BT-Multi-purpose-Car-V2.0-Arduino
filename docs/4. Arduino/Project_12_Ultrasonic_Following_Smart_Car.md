# Project 12 Ultrasonic Following Smart Car

![a3beaada39eb1471b7df6d9788e2bea3](media/A116.png)

### **1.Beschrijving**

In dit project zullen we de afstand tussen de 4WD smart car en de obstakels voor hem detecteren met een ultrasone sensor om twee motoren aan te sturen zodat de auto beweegt en het 8\*8 LED-bord een glimlachend gezichts patroon toont.

### **2.Stroomschema**

![img](media/A117.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Detectie</td>
<td>Gemeten afstand van voorliggende obstakels</td>
<td>afstand (eenheid: cm)</td>
</tr>
<tr class="even">
<td>Instelling</td>
<td>8*16 LED-bord toont een glimlachpatroon.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Servo instellen op 90°</td>
<td></td>
</tr>
<tr class="even">
<td>Voorwaarde</td>
<td>afstand≥20 en afstand≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>Status</td>
<td>Vooruit rijden</td>
<td></td>
</tr>
<tr class="even">
<td>Voorwaarde</td>
<td>afstand＞10 en afstand＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>afstand＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Voorwaarde</td>
<td>stop</td>
<td></td>
</tr>
<tr class="odd">
<td>Voorwaarde</td>
<td>afstand≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Voorwaarde</td>
<td>Achteruit rijden</td>
<td></td>
</tr>
</tbody>
</table>


### **3.Aansluitschema**

![568a66655a14dd34afd8cb1e6ae5951c](media/A118.png)

**Aansluiten:**

1). GND, VCC, SDA en SCL van het 8\*8 LED-bord zijn verbonden met G (GND), V (VCC), A4 en A5 van de uitbreidingskaart.

2). VCC, Trig, Echo en Gnd van de ultrasone sensor zijn verbonden met 5V (V), D12 (S), D13 (S) en Gnd (G).

3). De servo is verbonden met G, V en A3. De bruine draad is verbonden met Gnd (G), de rode draad met 5V (V) en de oranje draad met A3.

4). De voeding is verbonden met de BAT-poort.

### **4.Testcode**

```c
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 les 12
 Volgende auto
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  // Stel de klokpin in op A5
#define SDA_Pin  A4  // Stel de datapin in op A4

//Array, gebruikt om de data van het patroon op te slaan, kan zelf berekend worden of verkregen via de modultool
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};

const int servopin = A3;// Stel de pin van het stuurmechanisme in
 
#include "SR04.h" //definieer de functiebibliotheek van de ultrasone sensor
#define TRIG_PIN 12// stel het signaal van de ultrasone sensor in op D12
#define ECHO_PIN 13// stel het signaal van de ultrasone sensor in op D13
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

int left_ctrl = 2;//definieer de richtingsbesturingspinnen van motor groep B
int left_pwm = 5;//definieer de PWM-besturingspinnen van motor groep B
int right_ctrl = 4;//definieer de richtingsbesturingspinnen van motor groep A
int right_pwm = 6;//definieer de PWM-besturingspinnen van motor groep A

void setup() {
  pinMode(left_ctrl,OUTPUT);//stel richtingsbesturingspinnen van motor groep B in als OUTPUT
  pinMode(left_pwm,OUTPUT);//stel PWM-besturingspinnen van motor groep B in als OUTPUT
  pinMode(right_ctrl,OUTPUT);//stel richtingsbesturingspinnen van motor groep A in als OUTPUT
  pinMode(right_pwm,OUTPUT);//stel PWM-besturingspinnen van motor groep A in als OUTPUT
  pinMode(TRIG_PIN, OUTPUT); //Stel de trig pin in als output
  pinMode(ECHO_PIN, INPUT); //Stel de echo pin in als input
  pinMode(SCL_Pin,OUTPUT);//Stel de klokpin in als output
  pinMode(SDA_Pin,OUTPUT);//Stel de datapin in als output
  servopulse(servopin,90);//Stel de beginhoek van het stuurmechanisme in op 90°
  delay(500); //wacht 500ms
  matrix_display(smile);  //toon glimlachend gezichts patroon  
}

void loop() {
  distance = sr04.Distance();//de afstand gedetecteerd door de ultrasone sensor
   if(distance <= 10)//als afstand minder is dan 10
  {
    back();//rij achteruit
  }
  else if((distance > 10)&&(distance< 20 ))//als 10<afstand<20
  {
    Stop();//stop
  }
  else if((distance >= 20)&&(distance <= 50))//als 20≤afstand≤50  
{
    front();//volg
  }
  else//anders
  {
    Stop();//stop
  }
}

void front()//definieer de status van vooruitgaan
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,100);
}
void back()//definieer de status van achteruitgaan
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void left()//definieer de status van linksaf slaan
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//definieer de status van rechtsaf slaan
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void Stop()//definieer de status van stoppen
{
  digitalWrite(left_ctrl, LOW);  
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm,0);
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

  for (int i = 0; i < 16; i++) //het patroon bestaat uit 16 bytes
  {
    IIC_send(matrix_value[i]); //zend de data van het patroon
  }
  IIC_end();   //Einde van patroon data transmissie
  IIC_start();
  IIC_send(0x8A);  //Display controle, selecteer 4/16 pulsbreedte
  IIC_end();
}
//Condities waaronder datatransmissie begint
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Elke byte heeft 8 bits en wordt bit voor bit gecontroleerd beginnend bij het laagste bit
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
//*******************************************************************************
```

### **5. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet de externe voeding aan
en zet vervolgens de DIP-schakelaar op ON. Stel de servo in op 90°, de slimme auto zal bewegen met de obstakels en het 8X16 LED-bord zal “smile” tonen.