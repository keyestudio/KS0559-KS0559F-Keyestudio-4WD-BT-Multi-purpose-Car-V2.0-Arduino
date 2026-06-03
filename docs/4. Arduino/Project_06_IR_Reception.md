# Project 6 IR Ontvangst

![9681c7da-a7c9-49ed-ad8c-32e00c6aeb07](media/A42.png)

### **1.Beschrijving** 

Er is geen twijfel dat infrarood afstandsbediening alomtegenwoordig is in het dagelijks leven. Het wordt gebruikt om verschillende huishoudelijke apparaten te bedienen, zoals tv's, stereosystemen, videorecorders en satellietsignaalontvangers. Infrarood afstandsbediening bestaat uit een infrarood zend- en ontvangstsysteem, dat wil zeggen een infrarood afstandsbediening en infrarood ontvangermodule en een microcontroller die kan decoderen.  

![image-20250509154423060](media/A43.png)

Het 38K infrarood draaggolfsignaal dat door de afstandsbediening wordt uitgezonden, wordt gecodeerd door de coderingschip in de afstandsbediening. Het bestaat uit een sectie pilotcode, gebruikerscode, gebruikers inverse code, datacode en data inverse code. Het tijdsinterval van de puls wordt gebruikt om te onderscheiden of het een 0- of 1-signaal is en de codering bestaat uit deze 0- en 1-signalen.

De gebruikerscode van dezelfde afstandsbediening is constant terwijl de datacode de toets kan onderscheiden.

Wanneer de afstandsbedieningknop wordt ingedrukt, zendt de afstandsbediening een infrarood draaggolfsignaal uit. Wanneer de IR-ontvanger het signaal ontvangt, zal het programma het draaggolfsignaal decoderen en bepalen welke toets is ingedrukt. De MCU decodeert het ontvangen 01-signaal en bepaalt zo welke toets op de afstandsbediening is ingedrukt.

De infraroodontvanger die we gebruiken is een infrarood ontvanger module. Deze bestaat voornamelijk uit een infrarood ontvangerkop, een apparaat dat ontvangst, versterking en demodulatie integreert. De interne IC heeft de demodulatie voltooid en kan van infraroodontvangst naar uitgang gaan en is compatibel met TTL-signalen.

Daarnaast is het geschikt voor infrarood afstandsbediening en infrarood gegevensoverdracht. De infrarood ontvangermodule gemaakt door de ontvanger heeft slechts drie pinnen: signaallijn, VCC en GND. Het is zeer handig om te communiceren met Arduino en andere microcontrollers.

### **2.Specificatie**

- Bedrijfsspanning: 3.3-5V (DC)

- Uitgangssignaal: Digitaal signaal

- Ontvangshoek: 90 graden

- Frequentie: 38kHz

- Ontvangstafstand: 10m

De afbeelding toont het echte product en het circuitdiagram van de infraroodontvanger.

![image-20250510082651985](media/A44.png)

### **3.Componenten**

|           Ontwikkelbord *1           |           8833 Motor Driver *1           |     Rode LED Module*1     |
| :----------------------------------: | :-------------------------------------: | :-----------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             3P Dupont Draad*1             |               USB Kabel*1                |                          |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                          |


Aangezien het 8833 bord geïntegreerd is met de IR-ontvanger, is bedrading niet nodig. De pinnen van de IR-ontvanger module zijn G (GND), V (VCC) en D3.

### **4.Testcode**

```c
//*************************************************************************************
/*
 keyestudio 4wd BT Car
 les 6.1
 IR afstandsbediening
 http://www.keyestudio.com
*/ 
#include <IRremote.h>     //IRremote bibliotheek declaratie  
int RECV_PIN = 3;        //definieer de pin van IR ontvanger als D3
IRrecv irrecv(RECV_PIN);   
decode_results results;   // decodeer resultaten bevinden zich in “result” van “decode results”
void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Ontvanger inschakelen
}  
  
 void loop() {  
  if (irrecv.decode(&results))//succesvol decoderen, ontvang een set infrarood signalen  
   {  
     Serial.println(results.value, HEX);//Wikkel woord in 16 HEX om code uit te voeren en te ontvangen 
     irrecv.resume(); // Ontvang de volgende waarde
   }  
   delay(100);  
 } 
//*************************************************************************************
```

### **5.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om de board van stroom te voorzien. Na het inschakelen, open de seriële monitor en stel de baudrate in op 9600.

Pak de afstandsbediening en stuur een signaal naar de infraroodontvanger sensor. Je kunt de toetswaarde van de overeenkomstige toets zien; als de toetsduur te lang is, is FFFFFFFF gevoelig voor corrupte tekens.

![image-20250510082931375](media/A45.png)

De toetswaarden van de Keyestudio afstandsbediening worden hieronder weergegeven.

![image-20250510082942450](media/A46.png)

### **6. Code Uitleg**

**irrecv.enableIRIn():** Na het inschakelen van IR-decodering, worden de IR-signalen ontvangen,

**decode():** De functie “decode()” controleert continu of het decoderen succesvol is.

**irrecv.decode(\&results):** na succesvol decoderen, zal deze functie “true” teruggeven en het resultaat opslaan in “results”. Na het decoderen van de IR-signalen, wordt de resume()-functie uitgevoerd om door te gaan met het ontvangen van het volgende signaal.

### **7. Uitbreidingspraktijk**

We hebben de toetswaarde van de IR-afstandsbediening gedecodeerd. Wat dacht je ervan om de LED te bedienen met de gemeten waarde? We kunnen een experiment ontwerpen.

Sluit een LED aan op D9, druk vervolgens op de toetsen van de afstandsbediening om de LED aan en uit te zetten.

![image-20250508161123490](media/A13.png)

```c
//*************************************************************************************
/* 
keyestudio 4wd BT Car
lesson 6.2
IR remote LED
http://www.keyestudio.com
*/ 
#include <IRremote.h>
int RECV_PIN = 3;//definieer de pin van IR-ontvanger als D3
int LED_PIN = 9;//definieer de pin van LED als pin 9
int a=0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{Serial.begin(9600);
  irrecv.enableIRIn(); //Initialiseer de IR-ontvanger
  pinMode(LED_PIN,OUTPUT);//zet pin 9 van LED op OUTPUT
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    if(results.value==0xFF02FD && (a==0)) //volgens bovenstaande toetswaarde, druk op “OK” op de afstandsbediening, LED wordt bediend
    {
      Serial.println("HIGH");
      digitalWrite(LED_PIN,HIGH);//LED gaat aan
      a=1;
    }
    else if(results.value==0xFF02FD && (a==1)) //druk opnieuw
    {
      Serial.println("LOW");
      digitalWrite(LED_PIN,LOW);//LED gaat uit
      a=0;
    }
    irrecv.resume(); // ontvang de volgende waarde
  }
}
//*************************************************************************************
```

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om de board van stroom te voorzien. Na het inschakelen, kan het indrukken van de "**OK**" toets op de afstandsbediening de LED aan en uit zetten.