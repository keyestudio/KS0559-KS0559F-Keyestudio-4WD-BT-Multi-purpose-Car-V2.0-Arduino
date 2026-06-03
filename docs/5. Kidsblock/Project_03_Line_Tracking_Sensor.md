# Project 3: Lijnvolgsensor

![](media/A63.png)

### **1.Beschrijving** 

De lijnvolgsensor is eigenlijk een infraroodsensor. De component die hier wordt gebruikt is de TCRT5000 infraroodbuis. Het werkingsprincipe is het gebruik van verschillende reflectiviteit van infraroodlicht op kleuren, en vervolgens de sterkte van het gereflecteerde signaal omzetten in een stroomsignaal.

Tijdens het detectieproces is zwart actief op HOOG niveau terwijl wit actief is op LAAG niveau. De detectiehoogte is 0-3 cm.

De Keyestudio 3-kanaals lijnvolgmodule heeft 3 sets TCRT5000 infraroodbuizen geïntegreerd op een bord, wat het bedraden en besturen gemakkelijker maakt.

Door de instelbare potentiometer op de sensor te draaien, kan de detectiegevoeligheid van de sensor worden aangepast.

### **2.Specificatie**

- Werkspanning: 3.3-5V (DC)

- Interface: 5PIN

- Uitgangssignaal: Digitaal signaal

- Detectiehoogte: 0-3 cm

![](media/A64.jpeg)

<span style="color: rgb(255, 76, 65);">Opmerking:</span> Draai voor het testen de potentiometer op de sensor om de detectiegevoeligheid aan te passen. De gevoeligheid is het beste wanneer de LED wordt afgesteld op een drempel tussen AAN en UIT.

### **3.Componenten**

| Ontwikkelbord *1          | 8833 Motor Driver *1      | Rode LED Module*1        | Lijnvolgsensor*1         |
| ------------------------ | ------------------------ | ------------------------ | ------------------------ |
| ![img](media/A65.jpg)    | ![img](media/A66.jpg)    | ![img](media/A67.jpg)    | ![img](media/A68.png)    |
| 5P Dupont Draad*1         | USB Kabel*1              | 3P Dupont Draad*1        |                          |
| ![img](media/A69.png)    | ![img](media/A70.jpg)    | ![img](media/A71.jpg)    |                          |

### **4.Aansluitschema**

![](media/A72.png)

G, V, S1, S2 en S3 van de lijnvolgsensor zijn verbonden met G (GND), V (VCC), D11, D7 en D8 van het sensor uitbreidingsbord.

### **5.Testcode**

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A75.png)

(4).![](media/A76.png)

(5).![](media/A77.png)

**Volledige Testcode**

![](media/A78.png)

![](media/A79.png)

### **6.Testresultaat**

Na het succesvol uploaden van de code naar het V4.0 bord, verbind je de bedrading volgens het aansluitschema en gebruik je een USB-kabel om het bord van stroom te voorzien via de computer.

Na het inschakelen klik je op ![](media/A80.png) om de baudrate in te stellen op 9600 en je ziet de status van de drie lijnvolgsensoren. Wanneer er geen signalen worden ontvangen, is de waarde 1. Als we de sensor bedekken met een wit papier, wordt de waarde 0.

![](media/A81.png)

![](media/A82.png)

### **7.Uitbreidingspraktijk**

Na het begrijpen van het werkingsprincipe, kun je een LED aansluiten op D9 om de LED ermee te besturen.

![](media/A83.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A84.png)

(4).![](media/A85.png)

(5).![](media/A77.png)

(6).![](media/A86.png)

(7).![](media/A87.png)

**Volledige Testcode**

![](media/A88.png)

![](media/A89.png)

Na het succesvol uploaden van de code naar het V4.0 bord, verbind je de bedrading volgens het aansluitschema en gebruik je een USB-kabel om het bord van stroom te voorzien via de computer.

Na het inschakelen houd je een papier dicht bij de sensor, dan zie je dat de LED oplicht wanneer de lijnvolgsensor wordt bedekt.