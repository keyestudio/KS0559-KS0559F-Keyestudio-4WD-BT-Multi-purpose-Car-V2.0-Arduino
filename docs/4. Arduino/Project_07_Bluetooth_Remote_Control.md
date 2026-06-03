# Project 7 Bluetooth Afstandsbediening

### **1.Beschrijving**

![image-20250510083107283](media/A47.png)

Er zit een DX-BT24 5.1 Bluetooth-module in deze kit. Deze bluetooth-module heeft 256Kb ruimte en voldoet aan de V5.1BLE bluetooth-specificatie, die AT-commando's ondersteunt. Gebruikers kunnen parameters zoals de baudrate en apparaatsnaam van de seriële poort naar wens aanpassen.

Daarnaast ondersteunt het UART-interface en bluetooth seriële poort transparante transmissie, wat ook de voordelen heeft van lage kosten, kleine afmetingen, laag stroomverbruik en hoge gevoeligheid voor zenden en ontvangen. Opmerkelijk is dat het slechts een paar randcomponenten nodig heeft om zijn krachtige functies te realiseren.

### **2.Specificatie**

- Bluetooth-protocol: Bluetooth Specificatie V5.1 BLE

- Werkafstand: In een open omgeving kan het 40m ultra-lange afstand communicatie bereiken

- Werkfrequentie: 2.4GHz ISM-band

- Communicatie-interface: UART

- Bluetooth-certificering: Voldoet aan FCC CE ROHS REACH certificeringsstandaard

- Seriële poort parameters: 9600, 8 databits, 1 stopbit, geen pariteitsbit, geen flow control

- Voeding: 5V DC

- Werktemperatuur: –10℃ tot +65℃

### **3.Toepassing**

De DX-BT24 module ondersteunt ook het BT5.1 BLE-protocol, dat direct kan worden verbonden met iOS-apparaten met BLE Bluetooth-functie, en ondersteunt resident draaien van achtergrondprogramma's. Het wordt voornamelijk gebruikt op het gebied van draadloze gegevensoverdracht op korte afstand. Het maakt het mogelijk om omslachtige kabelverbindingen te vermijden en kan seriële kabels direct vervangen.

**Succesvolle toepassingsgebieden van BT24 modules:**

※ Bluetooth draadloze gegevensoverdracht;

※ Mobiele telefoon, computer randapparatuur;

※ Handheld POS-apparatuur;

※ Draadloze gegevensoverdracht van medische apparatuur;

※ Slimme huisbesturing;

※ Bluetooth printer;

※ Bluetooth afstandsbediening speelgoed;

※ Gedeelde fietsen;

### **4.Poorten**

![420af966-aaa4-4736-9d35-2a9ccc7215f3](media/A48.png)

①STATE：Status pin

②RX：Ontvangst pin

③TX：Zend pin

④GND：GND

⑤VCC：Voeding

⑥EN： Enable pin

Verbind de BT-module met de ontwikkelbord.

| Uno  | BT24 |
| :--: | :--: |
|  TX  |  RX  |
|  RX  |  TX  |
| VCC  |  5V  |
| GND  | GND  |

### **5.Componenten**

|           Ontwikkelbord *1           |           8833 Motor Driver *1           |                       Rode LED Module*1                       |
| :----------------------------------: | :--------------------------------------: | :----------------------------------------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) |                   ![img](media/A10.jpg)                   |
|             3P Dupont Draad*1             |               USB Kabel*1                |                  DX-BT24 Bluetooth Module*1                  |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         | ![image-20250510083534209](media/A49.png) |

### **6.Aansluitschema**

![image-20250510083927915](media/A50.png)

RXD, TXD, GND en VCC van de BT-module zijn verbonden met TX, RX, G en 5V.

STATE en BRK van de BT-module hoeven niet verbonden te worden.

<span style="color: rgb(255, 76, 65);">Let op: de richting van de BT-module bij het plaatsen op de 8833 board. En steek hem niet in voordat je de code uploadt.</span> 

### **7.Testcode**

<span style="color: rgb(255, 76, 65);">**Let op:** Verwijder de Bluetooth-module voordat je de testcode uploadt, anders lukt het uploaden niet. Verbind de Bluetooth-module pas nadat de code succesvol is geüpload.</span>

```c
//***********************************************************************
/*
keyestudio 4wd BT Car
lesson 7.1
Bluetooth 
http://www.keyestudio.com
*/
char ble_val; //karaktervariabele, gebruikt om de waarde die via Bluetooth ontvangen wordt op te slaan 

void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0)  // zorg ervoor dat er data in de seriële buffer staat
  {
    ble_val = Serial.read();  // Lees data uit de seriële buffer
    Serial.println(ble_val);  // Print
  }
}
//***********************************************************************
```

### **8.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om de board van stroom te voorzien. Na het inschakelen, steek de BT-module in en de LED zal knipperen, daarna moeten we de BT-app downloaden.

### **9.Download Bluetooth APP**

**Apple systeem**

(1). Open de App Store op de iPhone.

(2). Zoek naar keyes BT car en download de APP naar je telefoon.



![image-20250510084716811](media/A51.png)
    

(3). Na installatie, ga naar de interface.

![image-20250510084812821](media/A52.png)
    

(4). Klik op de knop "**Connect**" linksboven om automatisch naar Bluetooth te zoeken. Wanneer **BT24** wordt gevonden, klik op "**Connect**" om Bluetooth te verbinden, en klik vervolgens op ![image-20250510084833837](media/A53.png) om de bedieningsinterface van de 4WD smart car te openen. 

![image-20250510084902641](media/A54.png)
    **Android Systeem**
    

(1). Ga naar de Google Play Store en zoek naar “keyes 4wd”.

![image-20250510084916086](media/A55.png)

(2). Het app-icoon wordt hieronder weergegeven na installatie.

![image-20250510084933465](media/A56.png)

(3). Klik op de app om de volgende pagina te openen.

![image-20250510084946146](media/A57.png)

(4). Na het verbinden van Bluetooth, sluit de voeding aan en zal de LED-indicator van de Bluetooth-module knipperen. Tik op “**Connect**” om naar Bluetooth te zoeken.

![image-20250510085007028](media/A58.png)

(5). Wanneer **BT24** wordt gevonden, klik op "Connect" om Bluetooth te verbinden. Wanneer "**Connect**" verandert in "**is Connected**", betekent dit dat de Bluetooth-verbinding succesvol is. Zoals hieronder afgebeeld, blijft de Bluetooth LED aan.

![image-20250510085026219](media/A59.png)

(6). Na het verbinden van de Bluetooth-module, open de seriële monitor en stel de baudrate in op 9600. Druk op de knop van de Bluetooth APP, en de bijbehorende tekens worden weergegeven, zoals hieronder:

![image-20250510085039562](media/A60.png)

| Toets                     | Functie                          |
| ------------------------- | --------------------------------- |
| ![img](./media/A61.jpg) | Koppel DX-BT24 5.1 Bluetooth-module |
| ![img](./media/A62.jpg) | Verbreek Bluetooth-verbinding              |

|                           | Besturingskarakter                                          | Besturingskarakter                                          |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Druk: F  <br />Loslaten: S                                   | Druk op de knop, de auto gaat vooruit; <br />loslaten om te stoppen |
| ![img](media/A64.jpg) | Druk: L  <br />Loslaten: S                                   | Druk op de knop, de auto draait naar links; <br />loslaten om te stoppen  |
| ![img](media/A65.jpg) | Druk: R  <br />Loslaten: S                                   | Druk op de knop, de auto draait naar rechts; <br />loslaten om te stoppen |
| ![img](media/A66.jpg) | Druk: B  <br />Loslaten: S                                   | Druk op de knop, de auto gaat achteruit; <br />loslaten om te stoppen   |
| ![img](media/A67.jpg) | Druk: “a”  <br />Loslaten: “S”                               | Klik om te versnellen (maximaal: 255)                               |
| ![img](media/A68.jpg) | Druk: “d”  <br />Loslaten: “S”                               | Klik om te vertragen (minimaal: 0)                                |
| ![img](media/A69.jpg) | Klik om de zwaartekracht <br />detectiefunctie van de <br />mobiele telefoon te starten: klik opnieuw om <br />de zwaartekrachtbesturing te verlaten |                                                              |
| ![img](media/A70.jpg) | Klik om “X” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start lijnvolgfunctie; <br />klik opnieuw om te stoppen      |
| ![img](media/A71.jpg) | Klik om “Y” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start ultrasone vermijdingsfunctie; <br />klik opnieuw om te stoppen |
| ![img](media/A72.jpg) | Klik om “U” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start ultrasone volgfunctie; <br />klik opnieuw om te stoppen |
| ![img](media/A73.jpg) | Klik om “G” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start begrenzingsfunctie;<br /> klik opnieuw om te stoppen       |

**9. Code Uitleg**

**Serial.available()** : Geeft het aantal karakters terug dat momenteel nog in de seriële poort buffer aanwezig is. Over het algemeen wordt deze functie gebruikt om te bepalen of er data in de buffer van de seriële poort aanwezig is. Wanneer Serial.available() > 0, betekent dit dat de seriële poort data heeft ontvangen en gelezen kan worden;

**Serial.read() :** Verwijst naar het eruit halen en lezen van één Byte data uit de seriële poort buffer. Bijvoorbeeld, als een apparaat data via de seriële poort naar Arduino stuurt, kunnen we Serial.read() gebruiken om de verzonden data te lezen.

### **10. Uitbreidingsopdracht**

Hier willen we de opdracht gebruiken die door de mobiele telefoon wordt verzonden om een LED-licht aan of uit te zetten. Kijkend naar het aansluitingsschema is een LED verbonden met de D9 pin.

![image-20250510085856954](media/A74.png)

```c
//****************************************************************************
/*
 keyestudio smart turtle robot
 les 7.2
 Bluetooth LED
 http://www.keyestudio.com
*/ 
int ledpin=9;
char ble_val;// Een integer variabele die gebruikt wordt om de waarde die via Bluetooth ontvangen wordt op te slaan

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop()
{ 
  if (Serial.available() > 0) // Controleer of er data in de seriële poort buffer aanwezig is
  {
    ble_val = Serial.read();  // Lees data uit de seriële poort buffer
    Serial.print("DATA ONTVANGEN:");
    Serial.println(ble_val);
    if (ble_val == 'F') {
      digitalWrite(ledpin, HIGH);
      Serial.println("led aan");
    }
    if (ble_val == 'B') {
      digitalWrite(ledpin, LOW);
      Serial.println("led uit");
    }
   }
}
//****************************************************************************
```

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om de board van stroom te voorzien. Na het inschakelen, klik op ![image-20250510085919039](media/A75.png) en ![image-20250510085931709](media/A76.png) om de LED aan en uit te schakelen.