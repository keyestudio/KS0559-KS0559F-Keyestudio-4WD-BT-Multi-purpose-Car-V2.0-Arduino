# Project 1: LED Knipperen

### **1.Beschrijving**

![image-20250508161034535](media/A6.png)

Voor beginners en enthousiastelingen is LED Knipperen een fundamenteel programma. LED, de afkorting van light emitting diodes, bestaat uit Ga, As, P, N chemische verbindingen enzovoort.

De LED kan in diverse kleuren knipperen door de vertragingstijd in de testcode te wijzigen. Bij bediening, met stroom op GND en VCC, zal de LED aan zijn als het S-eind op hoog niveau staat, anders zal deze uitgaan.

### **2.Specificatie**

- Besturingsinterface: digitale poort

- Werkspanning: DC 3.3-5V

- Pinafstand: 2.54mm

- LED weergavekleur: rood

![image-20250508161015086](media/A7.png)

### **3.Componenten**

|           Development Board *1           |           8833 Motor Driver *1           |     Rode LED Module*1     |
| :--------------------------------------: | :--------------------------------------: | :-----------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             3P Dupont Draad*1             |               USB Kabel*1                |                           |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                           |

### **4.Aansluitschema**

![image-20250508161123490](media/A13.png)

Zoals te zien is in bovenstaande afbeelding, is de Keyestudio 8833 motor Shield gestapeld op de Keyestudio 4.0 development board.

De pinnen G, V en S van de LED-module zijn respectievelijk verbonden met G, 5V en D9 van de uitbreidingskaart.

### **5.Testcode**

```c 
//****************************************************************************
/*
keyestudio 4wd BT Car
les 1.1
Knipperen
http://www.keyestudio.com
*/
void setup()
{ 
  pinMode(9, OUTPUT);// initialiseert digitale pin 9 als uitgang.
}
    
void loop() // de loop functie draait oneindig door
{  
  digitalWrite(9, HIGH); // zet de LED aan (HIGH is het spanningsniveau)
   delay(1000); // wacht een seconde
   digitalWrite(9, LOW); // zet de LED uit door de spanning op LOW te zetten
   delay(1000); // wacht een seconde
}
//****************************************************************************
```

### **6.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het aansluitschema en gebruik een USB-kabel om de computer met de board te verbinden voor voeding. Na het inschakelen zal je zien dat de LED verbonden met D9 aan en uit gaat.

### **7.Code Uitleg**

pinMode(9，OUTPUT) - Deze functie geeft aan dat de pin INPUT of OUTPUT is

digitalWrite(9，HIGH) - Wanneer de pin OUTPUT is, kunnen we deze instellen op HIGH (uitgang 5V) of LOW (uitgang 0V)

### **8.Uitbreidingsopdracht**

We zijn erin geslaagd de LED te laten knipperen. Laten we nu observeren wat er met de LED gebeurt als we de vertragingstijd aanpassen.

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 les 1.2
 vertraging
 http://www.keyestudio.com
*/
void setup()
{  
  // initialiseert digitale pin 11 als uitgang.
  pinMode(9, OUTPUT);
}
// de loop functie draait oneindig door
void loop()
{ 
  digitalWrite(9, HIGH); // zet de LED aan (HIGH is het spanningsniveau)
  delay(100); // wacht 0.1 seconde
  digitalWrite(9, LOW); // zet de LED uit door de spanning op LOW te zetten
  delay(100); // wacht 0.1 seconde
}
//*****************************************************************
```

Het testresultaat toont dat de LED sneller knippert. Daarom beïnvloedt de vertragingstijd de knippersnelheid van de LED.