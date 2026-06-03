# Project 10 Beperkende Slimme Auto

![644a1976bf17a6b64e0aed1a7240ff1e](media/A108.jpeg)

### **1.Beschrijving**

In dit project combineren we de kennis van een lijnvolgsensor en motordrivermodules om een beperkende slimme auto te maken. In het experiment willen we de lijnvolgsensor gebruiken om te detecteren of er een zwarte lijn rondom de slimme auto is, en vervolgens de rotatie van de twee motoren aansturen op basis van de detectieresultaten op een manier die de slimme auto in een cirkel, getekend met een zwarte lijn, vergrendelt.

### **2.Stroomschema**

![img](media/A109.png)

De specifieke logica van de beperkende 4WD slimme auto wordt weergegeven in de tabel.

![Img](media/A110.png)

### **3.Aansluitschema**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A111.png)

G, V, S1, S2 en S3 van de lijnvolgsensor zijn verbonden met G (GND), V (VCC), D11, D7 en D8 van de sensor uitbreidingskaart.

De voeding is aangesloten op de BAT-poort.

### **4.Testcode**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 les 10
 Beperkende Slimme Auto
 http://www.keyestudio.com
*/ 
//Data van het smile-patroon verkregen via het touch-gereedschap
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //Stel datapin in op A4
#define SCL_Pin  A5  //Stel klokpin in op A5

int left_ctrl = 2;//definieer de richtingsbesturingspinnen van motor groep B
int left_pwm = 5;//definieer de PWM-besturingspinnen van motor groep B
int right_ctrl = 4;//definieer de richtingsbesturingspinnen van motor groep A
int right_pwm = 6;//definieer de PWM-besturingspinnen van motor groep A
int sensor_L = 11;//definieer de pin van de linker lijnvolgsensor
int sensor_M = 7;//definieer de pin van de middelste lijnvolgsensor
int sensor_R = 8;//definieer de pin van de rechter lijnvolgsensor
int L_val,M_val,R_val;//definieer deze variabelen

void setup() {
  Serial.begin(9600);//start seriële monitor en stel baudrate in op 9600
  pinMode(left_ctrl,OUTPUT);//stel richtingsbesturingspinnen van motor groep B in als OUTPUT
  pinMode(left_pwm,OUTPUT);//stel PWM-besturingspinnen van motor groep B in als OUTPUT
  pinMode(right_ctrl,OUTPUT);//stel richtingsbesturingspinnen van motor groep A in als OUTPUT
  pinMode(right_pwm,OUTPUT);//stel PWM-besturingspinnen van motor groep A in als OUTPUT
  pinMode(sensor_L,INPUT);//stel de pinnen van linker lijnvolgsensor in als INPUT
  pinMode(sensor_M,INPUT);//stel de pinnen van middelste lijnvolgsensor in als INPUT
  pinMode(sensor_R,INPUT);//stel de pinnen van rechter lijnvolgsensor in als INPUT
 //Stel pin in als output
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(start01);//Toon startpatroon
}

void loop() 
{
  tracking(); //voer hoofdprogramma uit
}

void tracking()
{
  L_val = digitalRead(sensor_L);//lees de waarde van linker lijnvolgsensor
  M_val = digitalRead(sensor_M);//lees de waarde van middelste lijnvolgsensor
  R_val = digitalRead(sensor_R);//lees de waarde van rechter lijnvolgsensor
  if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //wanneer geen zwarte lijnen worden gedetecteerd, rijdt de turtle auto vooruit
    Car_front();
  }
  else { //Anders, als een van de patrouillesensoren een zwarte lijn detecteert, rijdt hij achteruit en draait naar links
    Car_back();
    delay(500);
    Car_left();
    delay(500);
  }
}

void Car_front()
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 180);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 180);
}
void Car_back()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 80);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 80);
}
void Car_left()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 150);
}

void Car_Stop()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 0);
}

//deze functie wordt gebruikt voor dot matrix display
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //de functie die de startconditie voor datatransmissie aanroept
  IIC_send(0xc0);  //selecteer adres

  for (int i = 0; i < 16; i++) //de patroon data is 16 bytes
  {
    IIC_send(matrix_value[i]); //Zend de data van het patroon
  }
  IIC_end();   //Eindig de overdracht van patroon data
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

### **5.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet de externe voeding aan
en zet vervolgens de DIP-schakelaar op ON. Plaats de smart car in de zwarte cirkel, dan zal deze uitsluitend in de cirkel bewegen.