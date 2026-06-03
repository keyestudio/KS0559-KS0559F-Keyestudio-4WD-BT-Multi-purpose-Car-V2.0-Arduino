# Project 13 Ultrasonic Obstakel Vermijdende Slimme Auto

![](media/A296.png)

### **1. Beschrijving**

In dit project willen we een ultrasone obstakel vermijdende slimme auto maken. We gebruiken de ultrasone sensor om de afstand tot het obstakel te detecteren, wat gebruikt kan worden om de servo te besturen zodat deze draait en de auto kan bewegen. Tegelijkertijd zal het 8X16 LED-bord het bijbehorende statuspatroon weergeven.

### **2. Stroomschema**

![img](media/A297.png)

**De specifieke logica van de ultrasone obstakel vermijdende slimme auto wordt hieronder weergegeven:**

![Img](media/A298.png)

![Img](media/A299.png)

### **3. Aansluitschema**

![](media/A282.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-bordmodule zijn verbonden met G (GND), V (VCC), A4 en A5 van de uitbreidingskaart.

2). VCC, Trig, Echo en Gnd van de ultrasone sensor zijn verbonden met 5V (V), D12 (S), D13 (S) en Gnd (G).

3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad op 5V (V) en de oranje draad op A3.

4). De voeding is aangesloten op de BAT-poort.

### **4. Testcode**

Voordat je de code schrijft, is het noodzakelijk om de bibliotheekbestanden van de ultrasone sensor, het 8x16 LED-bord en de servo te importeren. De specifieke stappen zijn als volgt:

Klik op ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek vervolgens naar de “Ultrasonic” sensor ![](media/A122.png) en klik erop. Hierdoor verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de “**Ultrasonic**” sensor succesvol is toegevoegd.

![Img](media/A300.png)

![](/media/A284.png)

Klik op ![](media/A33.png) om terug te keren naar de code-editorinterface. De instructieblokken van de toegevoegde “**Ultrasonic” sensor**, “**Matrix 8\*16 Aip1640**” module en “**Servo**” component zijn zichtbaar in het modulegebied.

![](media/A285.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A301.png)

(3).![](media/A302.png)

(4).![](media/A287.png)

(5).![](media/A288.png)

(6).![](media/A268.png)

(7).![](media/A289.png)

(8).![](media/A292.png)

(9).![](media/A290.png)

(10).![](media/A291.png)

**Volledige Testcode**

![](media/A303.png)

![](media/A304.png)

![](media/A305.png)

![](media/A306.png)

### **5. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind je de bedrading volgens het aansluitschema, zet je de voeding aan en zet je de DIP-switch op ON.

De slimme auto rijdt vooruit en ontwijkt automatisch obstakels. Wanneer er geen weg vooruit is, zal de servo de ultrasone sensor aansturen om de afstanden links, midden en rechts te scannen, en zal de auto naar de open zijde draaien. Tegelijkertijd zal het 8X16 LED-bord het bijbehorende statuspatroon weergeven.