# Project 15 Bluetooth Control Smart Car

![8abdadfa2fc462bdcc0542df52a793e3](media/A131.jpeg)

### **1.Beschrijving**

We hebben de basiskennis van Bluetooth geleerd. In deze les gaan we een Bluetooth-gestuurde slimme auto maken. In dit project beschouwen we de mobiele telefoon als de zender (host), en de slimme auto die verbonden is met de BT24 Bluetooth-module (slave) als de ontvanger, en gebruiken we de mobiele APP om de slimme auto via Bluetooth te bedienen.

### **2.APP Bedieningsknoppen**

|                           | Bedieningskarakter                                            | Bedieningskarakter                                            |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Druk: F  <br />Loslaten: S                                   | Druk op de knop, de auto gaat vooruit; <br />loslaten om te stoppen |
| ![img](media/A64.jpg) | Druk: L  <br />Loslaten: S                                   | Druk op de knop, de auto draait naar links; <br />loslaten om te stoppen  |
| ![img](media/A65.jpg) | Druk: R  <br />Loslaten: S                                   | Druk op de knop, de auto draait naar rechts; <br />loslaten om te stoppen |
| ![img](media/A66.jpg) | Druk: B  <br />Loslaten: S                                   | Druk op de knop, de auto gaat achteruit; <br />loslaten om te stoppen   |
| ![img](media/A67.jpg) | Druk: “a”  <br />Loslaten: “S”                               | Klik om te versnellen (maximaal: 255)                         |
| ![img](media/A68.jpg) | Druk: “d”  <br />Loslaten: “S”                               | Klik om te vertragen (minimaal: 0)                            |
| ![img](media/A69.jpg) | Klik om de zwaartekracht <br />sensorfunctie van de <br />mobiele telefoon te starten: klik opnieuw om <br />de zwaartekrachtsensorbesturing te verlaten |                                                              |
| ![img](media/A70.jpg) | Klik om “X” te verzenden, <br />klik opnieuw om “S” te verzenden | Start lijnvolgfunctie; <br />klik opnieuw om te stoppen      |
| ![img](media/A71.jpg) | Klik om “Y” te verzenden, <br />klik opnieuw om “S” te verzenden | Start ultrasone vermijdingsfunctie; <br />klik opnieuw om te stoppen |
| ![img](media/A72.jpg) | Klik om “U” te verzenden, <br />klik opnieuw om “S” te verzenden | Start ultrasone volgfunctie; <br />klik opnieuw om te stoppen |
| ![img](media/A73.jpg) | Klik om “G” te verzenden, <br />klik opnieuw om “S” te verzenden | Start begrenzingsfunctie; <br />klik opnieuw om te stoppen   |

### **3.Stroomschema**

![img](media/A132.png)

### **4.Aansluitschema**



![61be6959693b2111639252ea45ec60fc](media/A133.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-bord zijn verbonden met G (GND), V (VCC), A4 en A5 van het uitbreidingsbord.
    
2). De RXD, TXD, GND en VCC van de Bluetooth-module zijn respectievelijk verbonden met TX, RX, G en 5V op de 8833 motor Shield, terwijl de STATE- en BRK-pinnen van de Bluetooth-module niet hoeven te worden aangesloten.
    
3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad op 5V (V) en de oranje draad op A3.
    
4). De voeding is aangesloten op de BAT-poort
    

### **5.Testcode**

<span style="color: rgb(255, 76, 65);">**Opmerking:** Verwijder de Bluetooth-module voordat je de testcode uploadt, anders kan de code niet worden geüpload. Sluit de Bluetooth-module aan nadat de code succesvol is geüpload.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
les 15
Bluetooth Besturing Auto
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

int left_ctrl = 2;//definieer de richtingsbesturingspinnen van motor groep B
int left_pwm = 5;//definieer de PWM-besturingspinnen van motor groep B
int right_ctrl = 4;//definieer de richtingsbesturingspinnen van motor groep A
int right_pwm = 6;//definieer de PWM-besturingspinnen van motor groep A

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
      case 'F' : car_front(); //Ontvang 'F', de auto rijdt vooruit
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); //Ontvang 'B', de auto rijdt achteruit
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); //Ontvang 'L', de auto draait naar links
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();//Ontvang 'R', de auto draait naar rechts
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();//Ontvang 'S', de auto stopt
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
}
}

void car_front()//definieer de status van vooruit rijden
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//definieer de status van achteruit rijden
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
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

void servopulse(int servopin,int myangle)//Stuuras loophoek
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

  for (int i = 0; i < 16; i++) //het patroon data is 16 bytes
  {
    IIC_send(matrix_value[i]); //Verzend de data van het patroon
  }
  IIC_end();   //Einde patroon data transmissie
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
//verzend data
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Elke byte heeft 8 bits en wordt bit voor bit gecontroleerd beginnend bij het laagste niveau
  {
    if (send_data & mask) { //Stelt de hoge en lage niveaus van SDA_Pin in afhankelijk of elk bit van de byte een 1 of een 0 is
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

### **6. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet de externe voeding aan en zet vervolgens de DIP-schakelaar op ON.

Plaats de BT-module en open je telefoon om via Bluetooth verbinding te maken en de smart car te besturen. De auto zal vooruit, achteruit rijden, naar links en rechts draaien en stoppen. Ook zal het 8\*8 LED-bord de bijbehorende patronen tonen.