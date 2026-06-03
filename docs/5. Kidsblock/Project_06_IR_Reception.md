# Project 6 IR Ontvangst

![](media/A141.png)

### **1.Beschrijving** 

Er is geen twijfel dat infrarood afstandsbediening alomtegenwoordig is in het dagelijks leven. Het wordt gebruikt om verschillende huishoudelijke apparaten te bedienen, zoals tv's, stereosystemen, videorecorders en satellietsignaalontvangers. Infrarood afstandsbediening bestaat uit een infrarood zend- en ontvangstsysteem, dat wil zeggen een infrarood afstandsbediening en infrarood ontvangermodule en een microcontroller die kan decoderen.  

![](media/A142.png)

Het 38K infrarood draaggolfsignaal dat door de afstandsbediening wordt uitgezonden, wordt gecodeerd door de encoderchip in de afstandsbediening. Het bestaat uit een sectie pilotcode, gebruikerscode, gebruikers inverse code, datacode en data inverse code. Het tijdsinterval van de puls wordt gebruikt om te onderscheiden of het een 0- of 1-signaal is en de codering bestaat uit deze 0- en 1-signalen.

De gebruikerscode van dezelfde afstandsbediening is constant terwijl de datacode de toets kan onderscheiden.

Wanneer de afstandsbedieningknop wordt ingedrukt, zendt de afstandsbediening een infrarood draaggolfsignaal uit. Wanneer de IR-ontvanger het signaal ontvangt, decodeert het programma het draaggolfsignaal en bepaalt welke toets is ingedrukt. De MCU decodeert het ontvangen 01-signaal en bepaalt zo welke toets op de afstandsbediening is ingedrukt.

De infraroodontvanger die we gebruiken is een infrarood ontvanger module. Deze bestaat voornamelijk uit een infrarood ontvangerkop, een apparaat dat ontvangst, versterking en demodulatie integreert. De interne IC heeft de demodulatie voltooid en kan van infraroodontvangst naar uitgang gaan en is compatibel met TTL-signalen.

Daarnaast is het geschikt voor infrarood afstandsbediening en infrarood gegevensoverdracht. De infrarood ontvangermodule gemaakt door de ontvanger heeft slechts drie pinnen: signaallijn, VCC en GND. Het is zeer handig om te communiceren met Arduino en andere microcontrollers.

### **2.Specificatie**

- Werkspanning: 3.3-5V (DC)

- Uitgangssignaal: Digitaal signaal

- Ontvangshoek: 90 graden

- Frequentie: 38kHz

- Ontvangstafstand: 10m

De afbeelding toont het echte product en het circuitdiagram van de infraroodontvanger.

![](media/A141.png)

![](media/A143.png)

### **3.Componenten**

| Ontwikkelbord *1          | 8833 Motor Driver *1       | Rode LED Module *1         |
| ------------------------- | -------------------------- | -------------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg)      | ![img](media/A44.jpg)      |
| 3P F-F Dupont Kabel *1    | USB Kabel *1               |                            |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg)      |                            |

Aangezien het 8833 bord geïntegreerd is met de IR-ontvanger, is bedrading niet nodig. De pinnen van de IR-ontvangermodule zijn G (GND), V (VCC) en D3.

### **4.Testcode**

<span style="color: rgb(255, 76, 65);">Let op: De infraroodmodule die in de software demonstratie wordt getoond, is al geïntegreerd in het uitbreidingsbord en wordt niet apart geleverd. Daarom zult u de module die op de onderstaande afbeelding staat niet in het product vinden.![](media/A144.png)</span>

Voordat je de code schrijft, is het noodzakelijk om het bibliotheekbestand van de IR-ontvangersensor te importeren. De specifieke stappen zijn als volgt: 

Klik op ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek dan naar de “**ir remote**” sensor ![](media/A144.png) en klik erop. Hierdoor verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de “ir remote” sensor succesvol is toegevoegd. 

![Img](media/A145.png)

![](media/A146.png)

Klik op ![](media/A33.png) om terug te keren naar de code-editor interface, de instructieblok van de toegevoegde “**ir remote**” sensor is zichtbaar in het modulegebied. 

![](media/A147.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A149.png)

(4).![](media/A150.png)

**Volledige Testcode**

![](media/A151.png)

### **5.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om de board van stroom te voorzien. Na het inschakelen, klik op ![](media/A80.png) om de baudrate in te stellen op 9600.

Pak de afstandsbediening en stuur een signaal naar de infraroodontvanger sensor. Je kunt de toetswaarde van de overeenkomstige toets zien; als de toets te lang wordt ingedrukt, is FFFFFFFF geneigd tot corrupte tekens.

![](media/A152.png)

De toetswaarden van de afstandsbediening worden hieronder weergegeven.

![](media/A153.jpeg)

### **6. Uitbreidingspraktijk**

We hebben de toetswaarde van de IR-afstandsbediening gedecodeerd. Wat dacht je ervan om de LED te bedienen met de gemeten waarde? We kunnen een experiment ontwerpen.

Sluit een LED aan op D9, druk vervolgens op de toetsen van de afstandsbediening om de LED aan en uit te zetten.

![](media/A154.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A155.png)

(4).![](media/A150.png)

(5).![](media/A156.png)

(6).![](media/A157.png)

(7).![](media/A158.png)

(8).![](media/A159.png)

**Volledige testcode**

![](media/A160.png)

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om de board van stroom te voorzien. Na het inschakelen, kan het indrukken van de "**OK**" toets op de afstandsbediening de LED aan en uit zetten.