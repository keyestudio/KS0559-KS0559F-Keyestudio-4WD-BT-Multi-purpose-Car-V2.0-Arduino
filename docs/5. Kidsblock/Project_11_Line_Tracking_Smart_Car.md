# Project 11 Lijnvolgende Slimme Auto

![](media/A271.png)

### **1. Beschrijving**

Gebaseerd op het werkingsprincipe van de lijnvolgsensor, maken we een lijnvolgende slimme auto.

In dit project detecteren we of er een zwarte lijn onder de slimme auto ligt via een lijnvolgsensor, en vervolgens besturen we de rotatie van de twee groepen motoren op basis van de detectieresultaten, zodat de slimme auto langs de zwarte lijn rijdt.

### **2. Stroomschema**

![img](media/A272.png)

![Img](media/A273.png)

### **3. Aansluitschema**

![](media/A264.png)

G, V, S1, S2 en S3 van de lijnvolgsensor zijn verbonden met G (GND), V (VCC), D11, D7 en D8 van de sensor uitbreidingskaart.

De voeding is aangesloten op de BAT-poort.

### **4. Testcode**

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A274.png)

(3).![](media/A275.png)

(4).![](media/A268.png)

(5).![](media/A276.png)

**Volledige Testcode**

![](media/A277.png)

![](media/A278.png)

![](media/A279.png)

### **5. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind je de bedrading volgens het aansluitschema, zet je de voeding aan en zet je de DIP-schakelaar op ON. Vervolgens zal de slimme auto langs de lijnen rijden.