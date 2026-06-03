# Project 1 LED Knipperen

### **1.Beschrijving**

![](media/A40.jpeg)

Voor beginners en enthousiastelingen is LED Knipperen een fundamenteel programma. LED, de afkorting van light emitting diodes, bestaat uit Ga, As, P, N chemische verbindingen enzovoort.

De LED kan in diverse kleuren knipperen door de vertragingstijd in de testcode te wijzigen. Bij bediening, met stroom op GND en VCC, zal de LED aan zijn als het S-eind op hoog niveau staat, anders zal deze uitgaan.

### **2.Specificatie**

- Besturingsinterface: digitale poort

- Werkspanning: DC 3.3-5V

- Pinafstand: 2.54mm

- LED weergavekleur: rood

![](media/A41.png)

### **3.Componenten**

| Development Board *1      | 8833 Motor Driver *1      | Rode LED Module*1          |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg) | ![img](media/A43.jpg) | ![img](media/A44.jpg) |
| 3P F-F Dupont Draad*1      | USB Kabel*1               |                           |
| ![img](media/A45.jpg) | ![img](media/A46.jpg) |                           |

### **4.Aansluitschema**

![](media/A47.png)

Zoals te zien is in bovenstaande afbeelding, is de Keyestudio 8833 motor driver uitbreidingskaart gestapeld op de Keyestudio 4.0 ontwikkelkaart.

De pinnen G, V en S van de LED-module zijn respectievelijk verbonden met G, 5V en D9 van de uitbreidingskaart.

### **5.Testcode**

Je kunt blokken slepen om te bewerken. Hieronder vermelde blokken zijn ter referentie.

(1).![](media/A48.png)

(2).![](media/A49.png)

(3).![](media/A50.png)

**Volledige Testcode**

![](media/A51.png)

### **6.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 kaart, verbind je de bedrading volgens het aansluitschema en gebruik je een USB-kabel om de computer aan te sluiten en de kaart van stroom te voorzien. Na het inschakelen zal de LED die verbonden is met D9 aan en uit gaan.

### **7.Uitbreidingspraktijk**

Vervolgens bekijken we het veranderen van de frequentie van het LED-knipperen door de wachttijd aan te passen.

![](media/A52.png)

Na het succesvol uploaden van de code naar de V4.0 kaart, verbind je de bedrading volgens het aansluitschema en gebruik je een USB-kabel om de computer aan te sluiten en de kaart van stroom te voorzien. Het testresultaat toont dat de LED sneller knippert.