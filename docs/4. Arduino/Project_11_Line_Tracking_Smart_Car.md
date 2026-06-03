# Project 11 Lijnvolgende Slimme Auto

![eff7a15e697e8b78bde391f806ea024d](media/A112.png)

### **1. Beschrijving**

Gebaseerd op het werkingsprincipe van de lijnvolgsensor, maken we een lijnvolgende slimme auto.

In dit project detecteren we of er een zwarte lijn onder de slimme auto is via een lijnvolgsensor, en vervolgens besturen we de rotatie van de twee groepen motoren op basis van de detectieresultaten op een manier die de slimme auto langs de zwarte lijn laat rijden.

### **2. Stroomschema**

![img](media/A113.png)

![Img](media/A114.png)

### **3. Aansluitschema**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A115.png)

G, V, S1, S2 en S3 van de lijnvolgsensor zijn verbonden met G (GND), V (VCC), D11, D7 en D8 van de sensor uitbreidingskaart.

De voeding is aangesloten op de BAT-poort.

### **4. Testcode**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 les 11
 Volgauto
 http://www.keyestudio.com
*/ 
//Data van het smile-patroon verkregen via de touch tool
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //Stel datapin in op A4
#define SCL_Pin  A5  //Stel klokpin in op A5

int left_ctrl = 2; //definieer de richtingsbesturingspinnen van groep B motor
int left_pwm = 5;  //definieer de PWM-besturingspinnen van groep B motor
int right_ctrl = 4; //definieer de richtingsbesturingspinnen van groep A motor
int right_pwm = 6;  //definieer de PWM-besturingspinnen van groep A motor
int sensor_L = 11;  //definieer de pin van de linker lijnvolgsensor
int sensor_M = 7;   //definieer de pin van de middelste lijnvolgsensor
int sensor_R = 8;   //definieer de pin van de rechter lijnvolgsensor
int L_val, M_val, R_val; //definieer deze variabelen

void setup() {
  Serial.begin(9600); //start seriële monitor en stel baudrate in op 9600
  pinMode(left_ctrl, OUTPUT); //stel richtingsbesturingspinnen van groep B motor in als OUTPUT
  pinMode(left_pwm, OUTPUT);  //stel PWM-besturingspinnen van groep B motor in als OUTPUT
  pinMode(right_ctrl, OUTPUT); //stel richtingsbesturingspinnen van groep A motor in als OUTPUT
  pinMode(right_pwm, OUTPUT);  //stel PWM-besturingspinnen van groep A motor in als OUTPUT
  pinMode(sensor_L, INPUT);   //stel de pinnen van linker lijnvolgsensor in als INPUT
  pinMode(sensor_M, INPUT);   //stel de pinnen van middelste lijnvolgsensor in als INPUT
  pinMode(sensor_R, INPUT);   //stel de pinnen van rechter lijnvolgsensor in als INPUT
  //Stel pin in als output
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(start01); //Toon startpatroon
}

void loop() 
{
  tracking(); //voer hoofdprogramma uit
}

void tracking()
{
  L_val = digitalRead(sensor_L); //lees de waarde van linker lijnvolgsensor
  M_val = digitalRead(sensor_M); //lees de waarde van middelste lijnvolgsensor
  R_val = digitalRead(sensor_R); //lees de waarde van rechter lijnvolgsensor

  if(M_val == 1){ //als de status van de middelste sensor 1 is, wat betekent dat er een zwarte lijn wordt gedetecteerd

```cpp
     if (L_val == 1 && R_val == 0) { //Als er een zwarte lijn aan de linkerkant wordt gedetecteerd, maar niet aan de rechterkant, ga dan linksaf
        left();
    }
     else if (L_val == 0 && R_val == 1) { //Anders, als er een zwarte lijn aan de rechterkant wordt gedetecteerd en niet aan de linkerkant, ga dan rechtsaf
      right();
    }
     else { //Anders, rechtdoor
      front();
    }
  }
  else { //Geen zwarte lijnen gedetecteerd in het midden
    if (L_val == 1 && R_val == 0) { //Als er een zwarte lijn aan de linkerkant wordt gedetecteerd, maar niet aan de rechterkant, ga dan linksaf
      left();
    }
    else if (L_val == 0 && R_val == 1) { //Anders, als er een zwarte lijn aan de rechterkant wordt gedetecteerd en niet aan de linkerkant, ga dan rechtsaf
      right();
    }
    else { //Anders, stop
      Stop();
    }
  }
}
void front()//definieer de status van vooruitgaan
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void back()//definieer de status van achteruitgaan
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
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

//deze functie wordt gebruikt voor dot matrix display
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //de functie die de startconditie van datatransmissie aanroept
  IIC_send(0xc0);  //selecteer adres

  for (int i = 0; i < 16; i++) //het patroon data is 16 bytes
  {
    IIC_send(matrix_value[i]); //Zend de data van het patroon
  }
  IIC_end();   //Eindig patroon data transmissie
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
//*************************************************************************
```

### **5. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet de externe voeding aan en zet vervolgens de DIP-schakelaar op ON. Dan zal de slimme auto langs de lijnen rijden.