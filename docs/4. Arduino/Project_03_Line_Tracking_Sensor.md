# Project 3: Lijnvolgsensor

![](media/A17.png)

### **1.Beschrijving** 

De lijnvolgsensor is eigenlijk een infraroodsensor. De component die hier wordt gebruikt is de TCRT5000 infraroodbuis. Het werkingsprincipe is het gebruik van verschillende reflectiviteit van infraroodlicht op kleuren, en vervolgens de sterkte van het gereflecteerde signaal omzetten in een stroomsignaal.

Tijdens het detectieproces is zwart actief op HOOG niveau terwijl wit actief is op LAAG niveau. De detectiehoogte is 0-3 cm.

De Keyestudio 3-kanaals lijnvolgmodule heeft 3 sets TCRT5000 infraroodbuizen geïntegreerd op een bord, wat het bedraden en besturen gemakkelijker maakt.

Door de instelbare potentiometer op de sensor te draaien, kan de detectiegevoeligheid van de sensor worden aangepast.

### **2.Specificatie**

- Bedrijfsspanning: 3.3-5V (DC)

- Interface: 5PIN

- Uitgangssignaal: Digitaal signaal

- Detectiehoogte: 0-3 cm

![image-20250508163247479](media/A18.png)

<span style="color: rgb(255, 76, 65);">Opmerking: Draai vóór het testen de potentiometer op de sensor om de detectiegevoeligheid aan te passen. De gevoeligheid is het beste wanneer de LED wordt afgesteld op een drempel tussen AAN en UIT.</span> 

### **3.Componenten**

| Ontwikkelbord *1                     | 8833 Motor Driver *1                     | Rode LED Module*1         | Lijnvolgsensor*1   |
| ----------------------------------- | --------------------------------------- | ------------------------ | ------------------ |
| ![img](media/A8.jpg)                | ![img](media/A9.jpg)                     | ![img](media/A10.jpg)    | ![img](media/A19.png) |
| 5P Dupont Kabel*1                   | USB Kabel*1                             | 3P Dupont Kabel*1        |                    |
| ![img](media/A20.png)               | ![img](media/A12.jpg)                    | ![img](media/A11.jpg)    |                    |

### **4.Aansluitschema**

![image-20250508164243044](media/A21.png)

G, V, S1, S2 en S3 van de lijnvolgsensor zijn verbonden met G (GND), V (VCC), D11, D7 en D8 van het sensor uitbreidingsbord.

### **5.Testcode**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 3.1 
 Line Track sensor
 http://www.keyestudio.com
*/
int L_pin = 11;  //pinnen van de linker lijnvolgsensor
int M_pin = 7;  //pinnen van de middelste lijnvolgsensor
int R_pin = 8;  //pinnen van de rechter lijnvolgsensor
int val_L,val_R,val_M;// definieer de variabele waarde van drie sensoren

void setup()
{
  Serial.begin(9600); // initialiseer seriële communicatie op 9600 bits per seconde
  pinMode(L_pin,INPUT); // stel L_pin in als input
  pinMode(M_pin,INPUT); // stel M_pin in als input
  pinMode(R_pin,INPUT); // stel R_pin in als input
}

void loop() 
{ 
  val_L = digitalRead(L_pin);//lees de L_pin:
  val_R = digitalRead(R_pin);//lees de R_pin:
  val_M = digitalRead(M_pin);//lees de M_pin:
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500);// vertraging tussen metingen voor stabiliteit
}
//****************************************************************************
```

### **6.Testresultaat**

Na het succesvol uploaden van de code naar het V4.0 bord, verbind de bedrading volgens het aansluitschema en gebruik een USB-kabel om de computer met het bord te verbinden en van stroom te voorzien.

Na het inschakelen, open de seriële monitor en je ziet de status van de drie lijnvolgsensoren. Wanneer er geen signalen worden ontvangen, is de waarde 1. Als we de sensor bedekken met een wit papier, wordt de waarde 0.

![image-20250508164424571](media/A22.png)

![image-20250508164453274](media/A23.png)

### **7.Code-uitleg**

Serial.begin(9600) - Initialiseer seriële poort, stel baudrate in op 9600

pinMode - Definieer de pin als input- of outputmodus

digitalRead - Lees de status van de pin, dit zijn doorgaans HOOG en LAAG niveau

### **8.Uitbreidingspraktijk**

Na het begrijpen van het werkingsprincipe, kun je een LED aansluiten op D9 om de LED ermee te besturen.

![image-20250508164527429](media/A24.png)

```c
/*
keyestudio 4wd BT Car
les 3.2
 Lijnvolgsensor LED
 http://www.keyestudio.com
*/
int L_pin = 11;  //pinnen van de linker lijnvolgsensor
int M_pin = 7;  //pinnen van de middelste lijnvolgsensor
int R_pin = 8;  //pinnen van de rechter lijnvolgsensor
int val_L,val_R,val_M;// definieer de variabelen van drie sensoren 

void setup()
{
  Serial.begin(9600); // initialiseer seriële communicatie op 9600 bits per seconde
  pinMode(L_pin,INPUT); // stel L_pin in als input
  pinMode(M_pin,INPUT); // stel M_pin in als input
  pinMode(R_pin,INPUT); // stel R_pin in als input
  pinMode(9, OUTPUT);
}

void loop() 
{ 
  val_L = digitalRead(L_pin);//lees de L_pin:
  val_R = digitalRead(R_pin);//lees de R_pin:
  val_M = digitalRead(M_pin);//lees de M_pin:
  Serial.print("links:");
  Serial.print(val_L);
  Serial.print(" midden:");
  Serial.print(val_M);
  Serial.print(" rechts:");
  Serial.println(val_R);
  delay(500);// vertraging tussen metingen voor stabiliteit
  if ((val_L == LOW) || (val_M == LOW) || (val_R == LOW))//als linker lijnvolgsensor signalen detecteert
  { 
    Serial.println("HIGH");
    digitalWrite(9, HIGH);//LED gaat uit
  }
  else//als linker lijnvolgsensor geen signalen detecteert
  { 
    Serial.println("LOW");
    digitalWrite(9, LOW);//LED gaat aan
  }
 }
//****************************************************************************
```

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema en gebruik een USB-kabel om de computer aan te sluiten om het board van stroom te voorzien.

Na het inschakelen, houd een papier dicht bij de sensor, dan zien we dat de LED oplicht wanneer de lijnvolgsensor wordt bedekt.