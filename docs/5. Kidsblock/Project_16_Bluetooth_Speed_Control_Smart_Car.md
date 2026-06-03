# Project 16 Bluetooth Snelheidsregeling Slimme Auto

![](media/A327.jpeg)

### **1. Beschrijving**

In dit project gebruiken we Bluetooth om de snelheid van de slimme auto aan te passen. We definiëren variabele snelheden en veranderen deze om de snelheid van de slimme auto te regelen.

### **2. Stroomschema**

![image-20250513095810478](media/A340.png)

### **3. Aansluitschema**

![](media/A329.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-bord zijn verbonden met G (GND), V (VCC), A4 en A5 van het uitbreidingsbord.

2). De RXD, TXD, GND en VCC van de Bluetooth-module zijn respectievelijk verbonden met TX, RX, G en 5V op het 8833 motor driver uitbreidingsbord, terwijl de STATE en BRK pinnen van de Bluetooth-module niet hoeven te worden aangesloten.

3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad op 5V (V) en de oranje draad op A3.

4). De voeding is aangesloten op de BAT-poort.

### **4. Testcode**

Voordat je de code schrijft, is het noodzakelijk om de bibliotheekbestanden van het 8x16 LED-bord en de servo te importeren. De specifieke stappen zijn als volgt:

Klik op ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek vervolgens naar de “Matrix 8\*16 Aip1640” module ![](media/A236.png) en klik erop. Hierdoor verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de “**Matrix 8\*16 Aip1640**” module succesvol is toegevoegd.

![Img](media/A237.png)

![](media/A238.png)

Klik op ![](media/A33.png) om terug te keren naar de code-editor interface, de instructieblokken van de toegevoegde “**Matrix 8\*16 Aip1640**” module en “**Servo**” component zijn zichtbaar in het modulegebied.

![](media/A330.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie:

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

(10).![](media/A341.png)

**Volledige Testcode**

<span style="color: rgb(255, 76, 65);">**Opmerking:** Verwijder de Bluetooth-module voordat je de testcode uploadt, anders kan de code niet worden geüpload. Sluit de Bluetooth-module pas aan nadat de code succesvol is geüpload.</span>

![](media/A342.png)

![](media/A343.png)

![](media/A344.png)

![](media/A345.png)

![](media/A346.png)

![](media/A346.png)

### **5. Testresultaat**

Na het succesvol uploaden van de code naar het V4.0 bord, verbind je de bedrading volgens het aansluitschema, zet je de externe voeding aan en zet je de DIP-schakelaar op ON. Koppel de APP met Bluetooth, de slimme auto kan nu via de APP worden bestuurd.

Druk op ![](media/A347.png), de auto zal versnellen, druk op ![](media/A348.png), de auto zal vertragen, en het 8\*16 LED-bord toont het overeenkomstige statuspatroon van de slimme auto.