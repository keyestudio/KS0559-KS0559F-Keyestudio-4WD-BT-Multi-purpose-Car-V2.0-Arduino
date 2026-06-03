# Project 7 Bluetooth Afstandsbediening

![](media/A161.png)

### **1.Beschrijving**

Er zit een DX-BT24 5.1 Bluetooth-module in deze kit. Deze bluetooth-module heeft 256Kb opslagruimte en voldoet aan de V5.1BLE bluetooth-specificatie, die AT-commando's ondersteunt. Gebruikers kunnen parameters zoals de baudrate en apparaatsnaam van de seriële poort naar wens aanpassen.

Daarnaast ondersteunt het een UART-interface en bluetooth seriële poort transparante transmissie, wat ook de voordelen heeft van lage kosten, klein formaat, laag stroomverbruik en hoge gevoeligheid voor zenden en ontvangen. Opvallend is dat het slechts een paar randcomponenten nodig heeft om zijn krachtige functies te realiseren.

### **2.Specificatie**

- Bluetooth protocol: Bluetooth Specificatie V5.1 BLE

- Werkafstand: In een open omgeving kan het 40m ultra-lange afstand communicatie bereiken
  
- Werkfrequentie: 2.4GHz ISM-band

- Communicatie-interface: UART

- Bluetooth certificering: Voldoet aan FCC CE ROHS REACH certificeringsstandaard
  
- Seriële poort parameters: 9600, 8 databits, 1 stopbit, geen pariteitsbit, geen flow control
  
- Voeding: 5V DC

- Werktemperatuur: –10℃ tot +65℃
  

### **3.Toepassing**

De DX-BT24 module ondersteunt ook het BT5.1 BLE protocol, dat direct kan worden verbonden met iOS-apparaten met BLE Bluetooth-functie, en ondersteunt resident draaien van achtergrondprogramma's. Het wordt voornamelijk gebruikt op het gebied van draadloze gegevensoverdracht over korte afstand. Het maakt het mogelijk om omslachtige kabelverbindingen te vermijden en kan seriële kabels direct vervangen.

**Succesvolle toepassingsgebieden van BT24 modules:**

※ Bluetooth draadloze gegevensoverdracht;

※ Mobiele telefoon, computer randapparatuur;

※ Handheld POS-apparatuur;

※ Draadloze gegevensoverdracht van medische apparatuur;

※ Slimme huisbesturing;

※ Bluetooth printer;

※ Bluetooth afstandsbediening speelgoed;

※ Gedeelde fietsen;

**Poorten**

![](media/A162.png)

①STATE：Status pin

②RX：Ontvangst pin

③TX：Zend pin

④GND：GND

⑤VCC：Voeding

⑥EN： Enable pin

Verbind de BT-module met de ontwikkelbord.

<table border="1">
<tbody>
<tr class="odd">
<td>Uno</td>
<td>BT24</td>
</tr>
<tr class="even">
<td>TX</td>
<td>RX</td>
</tr>
<tr class="odd">
<td>RX</td>
<td>TX</td>
</tr>
<tr class="even">
<td>VCC</td>
<td>5V</td>
</tr>
<tr class="odd">
<td>GND</td>
<td>GND</td>
</tr>
</tbody>
</table>


### **4.Componenten**

| Ontwikkelbord *1           | 8833 Motor Driver *1       | Rode LED Module*1          |
| ------------------------- | ------------------------- | -------------------------- |
| ![img](media/A163.jpg) | ![img](media/A164.jpg) | ![img](media/A165.jpg)  |
| 3P F-F Dupont Draad*1      | USB Kabel*1               | DX-BT24 Bluetooth Module*1 |
| ![img](media/A166.jpg) | ![img](media/A167.jpg) | ![img](media/A168.jpg)  |

### **5.Aansluitschema**

![](media/A169.png)

RXD, TXD, GND en VCC van de BT-module zijn verbonden met TX, RX, G en 5V.

STATE en BRK van de BT-module hoeven niet verbonden te worden.

<span style="color: rgb(255, 76, 65);">Let op:</span> de richting van de BT-module bij het plaatsen op de 8833 board. En steek hem niet in voordat je de code uploadt.

### **6.Testcode**

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A172.png)

(5).![](media/A173.png)

**Volledige Testcode**

<span style="color: rgb(255, 76, 65);">**Let op:** Verwijder de Bluetooth-module voordat je de testcode uploadt, anders lukt het uploaden niet. Verbind de Bluetooth-module pas nadat de code succesvol is geüpload.</span>

![](media/A174.png)

### **7.Testresultaat**

Na het succesvol uploaden van de code naar het V4.0 bord, verbind je de bedrading volgens het aansluitschema, en sluit je het bord via een USB-kabel aan op de computer om het bord van stroom te voorzien. Na het inschakelen steek je de BT-module in en zal de LED knipperen, daarna moeten we de BT-app downloaden.

### **8.Download Bluetooth APP**

**Apple systeem**

(1).Open de App Store op de iPhone.

(2). Zoek naar keyes BT auto en download de APP naar je telefoon.

![](media/A175.png)
    

(3). Na installatie, ga naar de interface.

![](media/A176.png)
    

(4). Klik op de knop "**Connect**" linksboven om automatisch naar Bluetooth te zoeken. Wanneer **BT24** wordt gevonden, klik op "**Connect**" om Bluetooth te verbinden, en klik vervolgens op ![](media/A177.png) om de bedieningsinterface van de 4WD smart car te openen. 

![](media/A178.png)
    
**Android Systeem**
    

(1). Ga naar de Google Play Store en zoek naar “**keyes 4wd**”.

![](media/A179.png)

(2). Het app-pictogram wordt hieronder weergegeven na installatie.

![](media/A180.png)

(3). Klik op de app om de volgende pagina te openen.

![](media/A181.png)

(4). Na het verbinden van Bluetooth, sluit de voeding aan en zal de LED-indicator van de Bluetooth-module knipperen. Tik op “Connect” om naar Bluetooth te zoeken.

![](media/A182.jpeg)

(5). Wanneer **BT24** wordt gevonden, klik op "**connect**" om Bluetooth te verbinden. Wanneer "**connect**" verandert in "**is connected**", betekent dit dat de Bluetooth-verbinding succesvol is. Zoals te zien is in de onderstaande afbeelding, blijft de Bluetooth LED aan.

![](media/A183.jpeg)

(6). Na het verbinden van de Bluetooth-module, klik op ![](media/A80.png) om de baudrate in te stellen op 9600. Druk op de knop van de Bluetooth APP, en de bijbehorende tekens worden weergegeven, zoals hieronder:

![](media/A184.png)

| Toets                                        | Functie                          |
| -------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Koppel DX-BT24 5.1 Bluetooth-module |
| ![wps15](media/A186.jpg) | Verbreek Bluetooth-verbinding              |

|                                                              | Controlekarakter                                            | Functie                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Druk: F  <br />Loslaten: S                                   | Druk op de knop, de auto rijdt vooruit; <br />loslaten om te stoppen |
| ![wps17](media/A188.jpg)                 | Druk: L  <br />Loslaten: S                                   | Druk op de knop, de auto draait naar links; <br />loslaten om te stoppen  |
| ![wps18](media/A189.jpg)                 | Druk: R  <br />Loslaten: S                                   | Druk op de knop, de auto draait naar rechts; <br />loslaten om te stoppen |
| ![wps19](media/A190.jpg)                 | Druk: B  <br />Loslaten: S                                   | Druk op de knop, de auto rijdt achteruit; <br />loslaten om te stoppen   |
| ![wps20](media/A191.jpg)                 | Druk: “a”  <br />Loslaten: “S”                               | Klik om te versnellen (maximaal: 255)                               |
| ![wps21](media/A192.jpg)                 | Druk: “d”  <br />Loslaten: “S”                               | Klik om te vertragen (minimaal: 0)                                |
| ![wps22](media/A193.jpg)                 | Klik om de zwaartekrachtsensorfunctie van de <br />mobiele telefoon te starten: klik opnieuw om <br />de zwaartekrachtsensorbesturing te verlaten |                                                              |
| ![wps23](media/A194.jpg)                 | Klik om “X” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start lijnvolgfunctie; <br />klik opnieuw om te stoppen      |
| ![wps24](media/A195.jpg)                 | Klik om “Y” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start ultrasone vermijdingsfunctie; <br />klik opnieuw om te stoppen |
| ![wps25](media/A196.jpg) | Klik om “U” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start ultrasone volgfunctie; <br />klik opnieuw om te stoppen |
| ![wps26](media/A197.jpg)                 | Klik om “G” te verzenden, <br />klik opnieuw om “S” te verzenden                | Start begrenzingsfunctie; <br />klik opnieuw om te stoppen       |

### **9. Uitbreidingspraktijk**

Hier gebruiken we het commando dat door de mobiele telefoon wordt verzonden om een LED-licht aan of uit te zetten. Volgens het aansluitdiagram is een LED verbonden met de D9-pin.

![](media/A198.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A199.png)

(5).![](media/A173.png)

(6).![](media/A200.png)

(7).![](media/A201.png)

**Volledige testcode**

![](media/A202.png)

Nadat je de code succesvol naar de V4.0-board hebt geüpload, verbind je de bedrading volgens het aansluitdiagram, en sluit je vervolgens de computer via een USB-kabel aan om het board van stroom te voorzien. Na het inschakelen klik je op <td>![](media/A203.png)</td> en <td>![](media/A204.png)</td> om de LED aan en uit te zetten.