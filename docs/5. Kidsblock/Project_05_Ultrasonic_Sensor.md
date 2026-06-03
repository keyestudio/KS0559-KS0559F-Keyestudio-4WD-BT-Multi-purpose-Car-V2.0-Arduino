# Project 5 Ultrasone Sensor

### **1.Beschrijving**

![](media/A109.png)

De HC-SR04 ultrasone sensor gebruikt sonar om de afstand tot een object te bepalen, zoals vleermuizen doen. Het biedt uitstekende contactloze afstandsdetectie met hoge nauwkeurigheid en stabiele metingen in een gebruiksvriendelijk pakket. Het wordt geleverd met een ultrasone zender- en ontvanger modules.

![Img](media/A110.png)

De HC-SR04 of ultrasone sensor wordt gebruikt in een breed scala aan elektronische projecten voor het creëren van obstakeldetectie en afstandsmeettoepassingen, evenals diverse andere toepassingen. Hier hebben we een eenvoudige methode gebracht om de afstand te meten met Arduino en een ultrasone sensor en hoe je de ultrasone sensor met Arduino gebruikt.

### **2.Specificatie**

- Werkspanning :+5V DC

- Ruststroom : \<2mA

- Werkstroom: 15mA

- Effectieve hoek: \<15°

- Afstandsbereik : 2cm – 300 cm

- Nauwkeurigheid : 0.3 cm

- Meethoek: 30 graden

- Trigger ingang pulsbreedte: 10uS

![](media/A111.png)

### **3.Componenten**

| Development Board *1      | 8833 Motor Driver *1      | Rode LED Module*1          | Ultrasone Sensor*1       |
| ------------------------- | ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A112.jpg) | ![img](media/A113.jpg) | ![img](media/A114.jpg) | ![img](media/A115.jpg) |
| 4P Dupont Draad*1          | USB Kabel*1               | 3P Dupont Draad*1          |                           |
| ![img](media/A116.jpg) | ![img](media/A117.jpg) | ![img](media/A118.jpg) |                           |

### **4.Werkingprincipe**

Zoals op de bovenstaande afbeelding te zien is, lijkt het op twee ogen. Eén is de zendkant, de ander is de ontvangkant.

De ultrasone module zal ultrasone golven uitzenden na het triggeren van een signaal. Wanneer de ultrasone golven het object tegenkomen en worden teruggekaatst, geeft de module een echo signaal af, zodat het de afstand tot het object kan bepalen aan de hand van het tijdsverschil tussen het trigger signaal en het echo signaal.

De t is de tijd dat het uitgezonden signaal het obstakel ontmoet en terugkeert. En de voortplantingssnelheid van geluid in de lucht is ongeveer 343m/s, en afstand = snelheid \* tijd. Echter, de ultrasone golf wordt uitgezonden en komt terug, wat 2 keer de afstand is. Daarom moet het gedeeld worden door 2, de afstand gemeten door ultrasone golf = (snelheid \* tijd)/2.

**Gebruiksmethode en schema van ultrasone module:**

1).Gebruik de GPIO pin om een hoog signaal van minstens 10μs aan de Trig pin van SR04 te geven, waarmee het getriggerd kan worden om afstand te detecteren.

2).Na het triggeren zal de module automatisch acht 40KHz ultrasone pulsen uitzenden en detecteren of er een signaal terugkomt. Deze stap wordt automatisch door de module uitgevoerd.

3).Als het signaal terugkomt, zal de Echo pin een hoog signaal afgeven, en de duur van het hoge signaal is de tijd vanaf het uitzenden van de ultrasone golf tot de terugkomst.

![image-20250509143833078](media/A119.png)


**Schema van ultrasone sensor:**

![](media/A120.jpeg)

### **5.Aansluitschema**

![](media/A121.png)

VCC, Trig, Echo en Gnd van de ultrasone sensor zijn verbonden met 5V(V), D12, D13 en Gnd(G)

### **6.Testcode**

Voordat je de code schrijft, is het noodzakelijk om het bibliotheekbestand van de ultrasone sensor te importeren. De specifieke stappen zijn als volgt: 

Klik ![](media/A29.png) om de extensiebibliotheek interface van sensoren/modules/componenten te openen, zoek dan naar "**Ultrasonic**" sensor ![](media/A122.png) en klik erop. Op deze manier verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de "**Ultrasonic**" sensor succesvol is toegevoegd. 

![Img](media/A123.png)

![](media/A124.png)

Klik ![](media/A33.png) om terug te keren naar de code-editor interface, het instructieblok van de toegevoegde "**Ultrasonic**" sensor is te zien in het modulegebied. 

![](media/A125.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

（1).![](media/A126.png)

(2).![](media/A127.png)

(3).![](media/A128.png)

(4).![](media/A129.png)

(5).![](media/A130.png)

(6).![](media/A131.png)

(7).![](media/A132.png)

**Volledige Testcode**

![](media/A133.png)

### **7. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om het board van stroom te voorzien. Na het inschakelen, klik op ![](media/A80.png) om de baudrate in te stellen op 9600.

De gedetecteerde afstand wordt weergegeven, en de eenheid is cm en inch. Houd de ultrasone sensor met de hand tegen, de weergegeven afstandswaarde wordt kleiner.

![](media/A134.png)

### **8. Uitbreidingspraktijk**

We hebben zojuist de afstand gemeten die door de ultrasone sensor wordt weergegeven. Wat dacht je ervan om de LED te bedienen met de gemeten afstand? Laten we het proberen en een LED-lichtmodule aansluiten op de D9-pin.

![](media/A135.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A136.png)

(3).![](media/A128.png)

(4).![](media/A137.png)

(5).![](media/A130.png)

(6).![](media/A138.png)

(7).![](media/A132.png)

**Volledige Testcode**

![](media/A139.png)

![](media/A140.png)

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om het board van stroom te voorzien. Na het inschakelen, blokkeer de ultrasone sensor met de hand (de afstand is tussen 2-10 cm), en controleer of de LED aan gaat.