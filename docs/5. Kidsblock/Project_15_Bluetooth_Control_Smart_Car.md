# Project 15 Bluetooth Control Smart Car

![](media/A327.jpeg)

### **1.Beschrijving**

We hebben de basiskennis van Bluetooth geleerd. In deze les gaan we een Bluetooth-gestuurde slimme auto maken. In dit project beschouwen we de mobiele telefoon als de zender (host) en de slimme auto die is verbonden met de BT24 Bluetooth-module (slave) als de ontvanger, en gebruiken we de mobiele APP om de slimme auto via Bluetooth te bedienen.

### **2.APP Bedieningsknoppen**

| Toets                                         | Functie                          |
| --------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Koppel DX-BT24 5.1 Bluetooth-module |
| ![wps15](media/A186.jpg) | Verbreek Bluetooth-verbinding              |

|                                                              | Bedieningskarakter                                            | Functie                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Druk: F  <br />Loslaten: S                                   | Druk op de knop, de auto rijdt vooruit; <br />loslaten om te stoppen |
| ![wps17](media/A188.jpg)                 | Druk: L  <br />Loslaten: S                                   | Druk op de knop, de auto draait naar links; <br />loslaten om te stoppen  |
| ![wps18](media/A189.jpg)                 | Druk: R  <br />Loslaten: S                                   | Druk op de knop, de auto draait naar rechts; <br />loslaten om te stoppen |
| ![wps19](media/A190.jpg)                 | Druk: B  <br />Loslaten: S                                   | Druk op de knop, de auto rijdt achteruit; <br />loslaten om te stoppen   |
| ![wps20](media/A191.jpg)                 | Druk: “a”  <br />Loslaten: “S”                               | Klik om te versnellen (maximaal: 255)                               |
| ![wps21](media/A192.jpg)                 | Druk: “d”  <br />Loslaten: “S”                               | Klik om te vertragen (minimaal: 0)                                |
| ![wps22](media/A193.jpg)                 | Klik om de zwaartekracht- <br />detectiefunctie van de <br />mobiele telefoon te starten: klik opnieuw om <br />de zwaartekrachtbesturing te stoppen |                                                              |
| ![wps23](media/A194.jpg)                 | Klik om “X” te verzenden,<br /> klik opnieuw om “S” te verzenden               | Start lijnvolgfunctie; <br />klik opnieuw om te stoppen      |
| ![wps24](media/A195.jpg)                 | Klik om “Y” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start ultrasone vermijdingsfunctie;<br /> klik opnieuw om te stoppen |
| ![wps25](media/A196.jpg) | Klik om “U” te verzenden, <br />klik opnieuw om “S” te verzenden               | Start ultrasone volgfunctie;<br /> klik opnieuw om te stoppen |
| ![wps26](media/A197.jpg)                 | Klik om “G” te verzenden,<br />klik opnieuw om “S” te verzenden                | Start begrenzingsfunctie;<br /> klik opnieuw om te stoppen       |

### **3.Stroomschema**

![img](media/A328.png)

### **4.Aansluitschema**

![](media/A329.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-bord zijn verbonden met G (GND), V (VCC), A4 en A5 van het uitbreidingsbord.
    
2). De RXD, TXD, GND en VCC van de Bluetooth-module zijn respectievelijk verbonden met TX, RX, G en 5V op het 8833 motor driver uitbreidingsbord, terwijl de STATE- en BRK-pinnen van de Bluetooth-module niet hoeven te worden aangesloten.
    
3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad is aangesloten op 5V (V) en de oranje draad is aangesloten op A3.
    
4). De voeding is aangesloten op de BAT-poort
    

### **5.Testcode**

Voordat je de code schrijft, is het noodzakelijk om de bibliotheekbestanden van het 8x16 LED-bord en de servo te importeren. De specifieke stappen zijn als volgt:

Klik op ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek vervolgens naar de “**Matrix 8\*16 Aip1640**” module ![](media/A236.png) en klik erop. Op deze manier verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de “**Matrix 8\*16 Aip1640**” module succesvol is toegevoegd.

![Img](media/A237.png)  

![](media/A238.png)

Klik op ![](media/A33.png) om terug te keren naar de code-editorinterface, de instructieblok van de toegevoegde “**Matrix 8\*16 Aip1640**” module en “**Servo**” component is te zien in het modulegebied.

![](media/A330.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

**Volledige Testcode**

<span style="color: rgb(255, 76, 65);">**Opmerking:** Voordat je de testcode uploadt, moet je de Bluetooth-module verwijderen, anders zal het uploaden van de code mislukken. Verbind de Bluetooth-module pas nadat de code succesvol is geüpload.</span>

![](media/A335.png)

![](media/A336.png)

![](media/A337.png)

![](media/A338.png)

![](media/A339.png)

### **6. Testresultaat**

Nadat de code succesvol is geüpload naar de V4.0 board, verbind je de bedrading volgens het bedradingsschema, zet je de externe voeding aan en zet je de DIP-switch op ON.

Plaats de BT-module en open je telefoon om via Bluetooth verbinding te maken en de slimme auto te besturen. De auto zal vooruit, achteruit rijden, naar links en rechts draaien en stoppen. Ook zal het 8\*8 LED-bord de bijbehorende patronen tonen.