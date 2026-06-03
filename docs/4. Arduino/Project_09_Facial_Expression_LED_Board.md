# Project 9 Gezichtsuitdrukking LED Bord

![image-20250510090912741](media/A87.png)

### **1. Beschrijving**

Hoe leuk is het als er een expressiebord aan de robot wordt toegevoegd. En het Keyestudio 8\*16 LED bord kan dat voor elkaar krijgen. Met de hulp ervan kun je zelf gezichtsuitdrukkingen, afbeeldingen, patronen en andere weergaven ontwerpen.

Het 8\*16 LED bord heeft 128 LEDs. De data van de microprocessor (Arduino) communiceert met de AiP1640 via een tweedraads businterface. Daardoor kan het de aan- en uitstand van 128 LEDs op de module aansturen, zodat de dotmatrix op de module het patroon kan weergeven dat je nodig hebt. Een HX-2.54 4Pin kabel wordt meegeleverd voor het gemak bij het bedraden.

### **2. Specificaties**

- Werkspanning: DC 3.3-5V

- Vermogensverlies: 400mW

- Oscillatiefrequentie: 450KHz

- Stroomsterkte aansturing: 200mA

- Werktemperatuur: -40\~80℃

- Communicatiemodus: I2C

### **3. Schema**

![image-20250510091309725](media/A88.png)

### **4. Werking**

Hoe wordt elke LED van de 8\*16 dotmatrix aangestuurd? Het is bekend dat elke byte 8 bits heeft en elke bit 0 of 1 is. Wanneer het 0 is, is de LED uit, wanneer het 1 is, is de LED aan. Eén byte kan één kolom van de LED aansturen, en vanzelfsprekend kunnen 16 bytes 16 kolommen LEDs aansturen, dat is de 8\*16 dotmatrix.

### **5. Pinbeschrijving en communicatieprotocol**

De data van de microprocessor (Arduino) communiceert met de AiP1640 via een tweedraads buskabel.

Het communicatieprotocoldiagram is als volgt (SCLK) is SCL, (DIN) is SDA.

![image-20250510091407219](media/A89.png)

① De startconditie voor datainvoer: SCL is hoog en SDA verandert van hoog naar laag.

② Voor het instellen van datacommandos zijn er methoden zoals hieronder weergegeven.

In ons voorbeeldprogramma wordt gekozen voor de manier om **automatisch 1 bij het adres op te tellen**, de binaire waarde is 0100 0000 en de overeenkomstige hexadecimale waarde is 0x40.

![Img](media/A90.png)

③ Voor het instellen van het adrescommando kan het adres als volgt worden gekozen.

In ons voorbeeldprogramma is het eerste 00H geselecteerd, en het binaire getal 1100 0000 komt overeen met hexadecimaal 0xc0.

![Img](media/A91.png)

④ De eis voor datainvoer is dat wanneer SCL hoog is tijdens het invoeren van data, het signaal op SDA onveranderd moet blijven. Alleen wanneer het kloksignaal op SCL laag is, mag het signaal op SDA veranderen. De invoer van data is eerst de laagste bit, daarna de hoogste bit.

⑤ De conditie voor het einde van datatransmissie is dat wanneer SCL laag is, SDA laag is en SCL hoog wordt, het niveau van SDA hoog wordt.

⑥ Displaycontrole, stel verschillende pulsbreedtes in, pulsbreedte kan worden gekozen zoals in de onderstaande afbeelding.

In het voorbeeld is de pulsbreedte 4/16, en de hexadecimale waarde die overeenkomt met 1000 1010 is 0x8A.

![Img](media/A92.png)

**Instructies voor het gebruik van de modulus tool**

De dotmatrix tool gebruikt de online versie, en de link is: [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

① Ga naar de link en de pagina verschijnt zoals hieronder

![image-20250510091438524](media/A93.png)

② De dotmatrix is 8\*16, dus stel de hoogte in op 8 en de breedte op 16, zoals in de afbeelding hieronder.

![image-20250510091446519](media/A94.png)

③ Genereer hexadecimale data van het patroon

Zoals in de afbeelding hieronder, druk met de linkermuisknop om te selecteren, rechts klikken om te annuleren; teken het gewenste patroon, klik op Generate, en de benodigde hexadecimale data wordt gegenereerd.

![image-20250510091457463](media/A95.png)

### **6. Componenten**

| Development Board *1                                         | 8833 Motor Driver *1                                         | USB-kabel*1               |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------- |
| ![img](media/A80.jpg)                                    | ![img](media/A81.jpg)                                    | ![img](media/A82.jpg) |
| USB-kabel*1                                                  | HX-2.54 4P Dupont-draad 200mm *1                              |                           |
| ![image-20250512155818434](media/A96.png) | ![image-20250512155822969](media/A97.png) |                           |

### **7. Aansluitschema**

![cec50fec4a335b6922e4c6694a133bc1](media/A98.png)

De GND, VCC, SDA en SCL van het 8x16 LED-lichtbord zijn respectievelijk verbonden met de Keyestudio sensor uitbreidingskaart-(GND), + (VCC), A4, A5 voor tweedraads seriële communicatie.

(<span style="color: rgb(255, 76, 65);">Opmerking:</span> Hoewel het is verbonden met de IIC-pin van Arduino, is deze module niet bedoeld voor IIC-communicatie. En de IO-poort hier simuleert I2C-communicatie en kan worden verbonden met willekeurige twee pinnen).

### **8. Testcode**

De code toont het glimlachende gezicht.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  les 9.1
  Matrix gezicht
  http://www.keyestudio.com
*/
//Gegevens van het glimlachpatroon verkregen via de touch tool
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};
#define SCL_Pin  A5  //Stel de klokpin in op A5
#define SDA_Pin  A4  //Stel de datapin in op A4
void setup() {
  //Stel pin in als uitgang
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //wissen
  //matrix_display(clear);
}
void loop() {
  matrix_display(smile);  //toon glimlachend expressiepatroon
}
//deze functie wordt gebruikt voor dot matrix display
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //de functie die de startconditie van gegevensoverdracht aanroept
  IIC_send(0xc0);  //selecteer adres

  for (int i = 0; i < 16; i++) //het patroon bestaat uit 16 bytes
  {
    IIC_send(matrix_value[i]); //Zend de gegevens van het patroon
  }
  IIC_end();   //Beëindig de overdracht van patroongegevens
  IIC_start();
  IIC_send(0x8A);  //Display control, selecteer 4/16 pulsbreedte
  IIC_end();
}
//Condities waaronder gegevensoverdracht begint
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Geeft het einde van gegevensoverdracht aan
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Elke byte heeft 8 bits en wordt bit voor bit gecontroleerd beginnend bij het laagste niveau
  {
    if (send_data & mask) { //Stelt de hoge en lage niveaus van SDA_Pin in afhankelijk van of elk bit van de byte een 1 of een 0 is
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Trek de klokpin SCL_Pin hoog om gegevensoverdracht te stoppen
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //trek de klokpin SCL_Pin laag om het SIGNaal van SDA te veranderen
  }
}
//************************************************************************
```

### **9. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het aansluitschema, zet vervolgens de DIP-schakelaar op ON, er zal een glimlachvormig patroon worden weergegeven op het LED-bord.

![95bb011957896b12285fc6763137bb9a](media/A99.png)

### **10. Code-uitleg**

We gebruiken de moduletool die we zojuist hebben geleerd, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), om de dot matrix het startpatroon te laten weergeven, vooruit te laten gaan, te stoppen en vervolgens het patroon te wissen. Het tijdsinterval is 2000 ms.

![image-20250512155957415](media/A100.png)![image-20250512160002378](media/A101.png)![image-20250512160006841](media/A102.png)![image-20250512160010543](media/A103.png)

**Code verkregen uit de moduletool：**

**Code voor het startpatroon:**

0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01

**Code voor het patroon vooruit:**

0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Code voor het patroon achteruit:**

0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Code voor het patroon linksaf:**

0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00

**Code voor het patroon rechtsaf:**

0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00

**Code voor het stop patroon:**

0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00

**Code om het scherm te wissen:**

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

![cec50fec4a335b6922e4c6694a133bc1](media/A104.png)

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  les 9.2
  Matrix gezicht
  http://www.keyestudio.com
*/
//Data van het smiley patroon verkregen uit de touch tool
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char front[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x12, 0x09, 0x12, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char back[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char left[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00};
unsigned char right[] = {0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char STOP01[] = {0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00};
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define SCL_Pin  A5  //Stel de klokpin in op A5
#define SDA_Pin  A4  //Stel de datapin in op A4
void setup() {
  //Stel pin in als output
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //wissen
  //matrix_display(clear);
}
void loop() {
    matrix_display(start01);  //Toon startpatroon
    delay(2000);
    matrix_display(front);    //Toon vooruit patroon
    delay(2000);
    matrix_display(STOP01);   //Toon stop patroon
    delay(2000);
    matrix_display(clear);    //Wis scherm
    delay(2000);
}
//deze functie wordt gebruikt voor dot matrix weergave
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //de functie die de startconditie voor datatransfer aanroept
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
//************************************************************************
```

Na het uploaden van de testcode toont het gezichtsuitdrukking bord deze patronen ordelijk en herhaalt deze volgorde.

![image-20250512160131674](media/A105.png)![image-20250512160135717](media/A106.png)![image-20250512160139283](media/A107.png)