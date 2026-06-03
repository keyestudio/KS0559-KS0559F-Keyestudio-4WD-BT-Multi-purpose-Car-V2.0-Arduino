# Project 9 Gezichtsuitdrukking LED Bord

![](media/A221.png)

### **1.Beschrijving** 

Hoe leuk is het als er een expressiebord aan de robot wordt toegevoegd. En het Keyestudio 8\*16 LED bord kan dit voor elkaar krijgen. Met de hulp hiervan kun je zelf gezichtsuitdrukkingen, afbeeldingen, patronen en andere weergaven ontwerpen.

Het 8\*16 LED bord heeft 128 LEDs. De data van de microprocessor (Arduino) communiceert met de AiP1640 via een tweedraads businterface. Hierdoor kan het de aan- en uitstand van 128 LEDs op de module aansturen, zodat de dotmatrix op de module het patroon kan weergeven dat je nodig hebt. Een HX-2.54 4Pin kabel wordt meegeleverd voor het gemak bij het bedraden.

### **2.Specificaties**

- Werkspanning: DC 3.3-5V

- Vermogensverlies: 400mW

- Oscillatiefrequentie: 450KHz

- Stuurstroom: 200mA

- Werktemperatuur: -40\~80℃

- Communicatiemodus: I2C
  

### **3.Schakelschema**

![](media/A222.png)

### **4.Werkingsprincipe**

Hoe wordt elke LED van de 8\*16 dotmatrix aangestuurd? Het is bekend dat elke byte 8 bits heeft en elke bit 0 of 1 is. Wanneer het 0 is, is de LED uit, en wanneer het 1 is, is de LED aan. Eén byte kan één kolom van de LED aansturen, en natuurlijk kunnen 16 bytes 16 kolommen van LEDs aansturen, dat is de 8\*16 dotmatrix.

### **5.Pinnenbeschrijving en communicatieprotocol**

De data van de microprocessor (Arduino) communiceert met de AiP1640 via een tweedraads buskabel.

Het communicatieprotocoldiagram is als volgt (SCLK) is SCL, (DIN) is SDA.

![](media/A223.png)

①De startconditie voor datainvoer: SCL is hoog en SDA verandert van hoog naar laag.

②Voor het instellen van datacommandos zijn er methoden zoals in de onderstaande afbeelding.

In ons voorbeeldprogramma wordt gekozen voor de manier om **automatisch 1 bij het adres op te tellen**, de binaire waarde is 0100 0000 en de overeenkomstige hexadecimale waarde is 0x40.

![Img](media/A224.png)

③Voor het instellen van het adrescommando kan het adres als volgt worden gekozen.

In ons voorbeeldprogramma is het eerste 00H geselecteerd, en het binaire getal 1100 0000 komt overeen met het hexadecimale 0xc0.

![Img](media/A225.png)

④De eis voor datainvoer is dat wanneer SCL op hoog niveau is tijdens het invoeren van data, het signaal op SDA onveranderd moet blijven. Alleen wanneer het kloksignaal op SCL laag is, mag het signaal op SDA worden veranderd. De invoer van data is eerst de laagste bit, daarna de hoogste bit.

⑤De conditie voor het einde van datatransmissie is dat wanneer SCL laag is, SDA laag is en SCL hoog wordt, het niveau van SDA hoog wordt.

⑥Displaycontrole, stel verschillende pulsbreedtes in, de pulsbreedte kan worden gekozen zoals in de onderstaande afbeelding.

In het voorbeeld is de pulsbreedte 4/16, en het hexadecimale overeenkomende getal van 1000 1010 is 0x8A.

![Img](media/A226.png)

**Instructies voor het gebruik van de modulus tool**

De dotmatrix tool gebruikt de online versie, en de link is: [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

①Ga naar de link en de pagina verschijnt zoals hieronder

![](media/A227.png)

②De dotmatrix is 8\*16, dus stel de hoogte in op 8 en de breedte op 16, zoals in de afbeelding hieronder.

![](media/A228.png)

③Genereer hexadecimale data van het patroon

Zoals in de afbeelding hieronder, druk met de linkermuisknop om te selecteren, rechtsklikken om te annuleren; teken het gewenste patroon, klik op Generate, en de benodigde hexadecimale data wordt gegenereerd.

![](media/A229.png)

### **6.Componenten**

| Ontwikkelbord *1           | 8833 Motor Driver *1            | 8x16 LED Paneel*1          |
| ------------------------- | ------------------------------- | ------------------------- |
| ![img](media/A230.jpg) | ![img](media/A231.jpg)       | ![img](media/A232.jpg) |
| USB Kabel*1               | HX-2.54 4P Dupont Draad 200mm *1 |                           |
| ![img](media/A233.jpg) | ![img](media/A234.jpg)       |                           |



### **7.Aansluitschema**

![](media/A235.png)

De GND, VCC, SDA en SCL van het 8x16 LED-lichtbord zijn respectievelijk verbonden met de keyestudio sensor uitbreidingskaart-(GND), + (VCC), A4, A5 voor tweedraads seriële communicatie.

(<span style="color: rgb(255, 76, 65);">Opmerking:</span> Hoewel het is verbonden met de IIC-pin van Arduino, is deze module niet voor IIC-communicatie. En de IO-poort hier simuleert I2C-communicatie en kan worden verbonden met willekeurige twee pinnen).

### **8.Testcode**

Voordat je de code schrijft, is het noodzakelijk om het bibliotheekbestand van het 8x16 LED-bord te importeren. De specifieke stappen zijn als volgt:

Klik ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek vervolgens naar de “**Matrix 8\*16 Aip1640**” module ![](media/A236.png) en klik erop. Op deze manier verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de “**Matrix 8\*16 Aip1640**” module succesvol is toegevoegd.

![Img](media/A237.png)

![](media/A238.png)

Klik ![](media/A33.png) om terug te keren naar de code-editorinterface, het instructieblok van de toegevoegde “**Matrix 8\*16 Aip1640**” module is zichtbaar in het modulegebied.

![](media/A239.png)

Je kunt blokken slepen om te bewerken. Hieronder staan blokken ter referentie.

(1).![](media/A126.png)

(2).![](media/A240.png)

**Volledige testcode**

![](media/A241.png)

### **9.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 kaart, verbind de bedrading volgens het bedradingsschema, zet vervolgens de DIP-schakelaar op ON, er wordt een glimlachvormig patroon weergegeven op het LED-bord.

![](media/A242.png)

### **10.Code-uitleg**

We gebruiken de modulus-tool die we zojuist hebben geleerd, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), om de dotmatrix het startpatroon, vooruitgaan, stoppen en daarna het patroon wissen te laten weergeven. Het tijdsinterval is 2000 ms.

![image-20250513092102687](media/A243.png)![image-20250513092107293](media/A244.png)![image-20250513092113035](media/A245.png)![image-20250513092116952](media/A246.png)


Instructieblok voor smiley face![](media/A247.png)

Instructieblok voor expressie: ![](media/A248.png)

Instructieblok voor hart ![](media/A249.png)

Instructieblok voor vooruitgaan![](media/A250.png)

Instructieblok voor **achteruit stappen** ![](media/A251.png)

Instructieblok voor **linksaf draaien** ![](media/A252.png)

Instructieblok voor **rechtsaf draaien** ![](media/A253.png)

Instructieblok voor **stoppen**![](media/A254.png)

Instructieblok voor **scherm wissen**![](media/A255.png)

![](media/A235.png)

Je kunt blokken slepen om te bewerken. Hieronder staan blokken ter referentie.

(1).![](media/A126.png)

(2).![](media/A240.png)

(3).![](media/A256.png)

**Volledige testcode**

![](media/A257.png)

Na het uploaden van de testcode toont het gezichtsuitdrukkingbord deze patronen achtereenvolgens en herhaalt deze volgorde.

![image-20250513092222972](media/A258.png)![image-20250513092233711](media/A259.png)![image-20250513092238552](media/A260.png)