# Project 10 Beperkende Smart Car

![](media/A261.jpeg)

### **1. Beschrijving**

In dit project combineren we de kennis van een lijnvolgsensor en motordrivermodules om een beperkende smart car te maken. In het experiment willen we de lijnvolgsensor gebruiken om te detecteren of er een zwarte lijn rondom de smart car is, en vervolgens de rotatie van de twee motoren te regelen op basis van de detectieresultaten, zodat de smart car in een cirkel getekend met een zwarte lijn wordt vergrendeld.

### **2. Stroomschema**

![img](media/A262.png)

De specifieke logica van de beperkende 4WD smart car wordt weergegeven in de tabel.

![Img](media/A263.png)

### **3. Aansluitschema**

![](media/A264.png)

G, V, S1, S2 en S3 van de lijnvolgsensor zijn verbonden met G (GND), V (VCC), D11, D7 en D8 van de sensor uitbreidingskaart.

De voeding is aangesloten op de BAT-poort.

### **4. Testcode**

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A265.png)

(3).![](media/A266.png)

(4).![](media/A267.png)

(5).![](media/A268.png)

(6).![](media/A269.png)

**Volledige testcode**

![KidsBlock Project-1747127137354](media/A270.png)

### **5. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, sluit je de bedrading aan volgens het aansluitschema, zet je de externe voeding aan en zet je de DIP-schakelaar op ON. Plaats de smart car in de zwarte cirkel, dan zal deze uitsluitend binnen de cirkel bewegen.