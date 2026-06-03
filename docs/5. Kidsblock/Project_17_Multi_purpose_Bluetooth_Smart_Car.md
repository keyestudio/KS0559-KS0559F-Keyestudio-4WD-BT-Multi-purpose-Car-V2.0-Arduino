# Project 17 Multi-purpose Bluetooth Smart Car

![](media/A349.jpeg)

### **1.Beschrijving**

In eerdere projecten voert de auto slechts één enkele functie uit. In deze les zullen we echter al zijn functies integreren via Bluetooth.

### **2.Stroomschema**

![](media/A350.png)

### **3.Aansluitschema**

![](media/A351.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-bord zijn verbonden met G (GND), V (VCC), A4 en A5 van het uitbreidingsbord.

2). De RXD, TXD, GND en VCC van de Bluetooth-module zijn respectievelijk verbonden met TX, RX, G en 5V op het 8833 motor driver uitbreidingsbord, terwijl de STATE- en BRK-pinnen van de Bluetooth-module niet hoeven te worden aangesloten.

3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad op 5V (V) en de oranje draad op A3.

4). G, V, S1, S2 en S3 van de lijnvolgsensor zijn verbonden met G (GND), V (VCC), D11, D7 en D8 van het sensor uitbreidingsbord.

5). VCC, Trig, Echo en Gnd van de ultrasone sensor zijn verbonden met 5V (V), D12 (S), D13 (S) en Gnd (G).

6). De voeding is verbonden met de BAT-poort.

### **4.Testcode**

Voordat je de code schrijft, is het noodzakelijk om de bibliotheekbestanden van de ultrasone sensor, het 8x16 LED-bord en de servo te importeren. De specifieke stappen zijn als volgt:

Klik op ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek vervolgens naar de “**Ultrasonic**” sensor ![](media/A122.png) en klik erop. Hierdoor verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de “**Ultrasonic**” sensor succesvol is toegevoegd.

![Img](media/A300.png)

![](media/A124.png)

Klik op ![](media/A33.png) om terug te keren naar de code-editorinterface. Het instructieblok van de toegevoegde “**Ultrasonic**” sensor, “**Matrix 8\*16 Aip1640**” module en “**Servo**” component is zichtbaar in het modulegebied.

![](media/A285.png)

**Volledige testcode**

<span style="color: rgb(255, 76, 65);">**Opmerking:** Verwijder de Bluetooth-module voordat je de testcode uploadt, anders kan de code niet worden geüpload. Sluit de Bluetooth-module pas aan nadat de code succesvol is geüpload.</span>

![](media/A352.png)

### **5.Testresultaat**

Nadat de code succesvol is geüpload naar de V4.0 board, verbind je de bedrading volgens het aansluitschema, zet je de externe voeding aan en zet je de DIP-schakelaar op ON.

Nadat de Bluetooth-module is aangesloten op de APP en de mobiele APP succesvol is verbonden met Bluetooth, kan de smart car worden bestuurd via de mobiele APP. We kunnen de bijbehorende functies bereiken door op de overeenkomstige knoppen in de mobiele APP te drukken.