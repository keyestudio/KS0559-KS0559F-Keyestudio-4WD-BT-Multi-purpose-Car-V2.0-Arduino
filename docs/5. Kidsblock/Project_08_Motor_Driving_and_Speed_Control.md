# Project 8 Motorbesturing en Snelheidsregeling

![](media/A205.png)

### **1. Beschrijving**

Er zijn veel manieren om motoren aan te sturen. Onze auto gebruikt de meest gebruikte DRV8833 motor driver chip, die een tweekanaals brug elektrische aandrijvingsoplossing biedt voor speelgoed, printers en andere geïntegreerde motor toepassingen.

Wanneer we de driver uitbreidingskaart op de 4.0 ontwikkelkaart stapelen en de BAT inschakelen, en vervolgens de DIP-schakelaar op de ON-stand zetten, zal de externe voeding beide kaarten tegelijkertijd van stroom voorzien. Om het aansluiten van bedrading te vergemakkelijken, is de driver uitbreidingskaart voorzien van een anti-omkeerpoort (PH2.0-2P-3P-4P-5P). Je kunt de motoren, voeding en sensormodules direct op de driver uitbreidingskaart aansluiten.

De Bluetooth-interface van de driver uitbreidingskaart is volledig compatibel met de DX-BT24 5.1 Bluetooth-module. Bij het aansluiten van de Bluetooth-module hoef je deze alleen maar in de overeenkomstige interface te pluggen. Tegelijkertijd worden 2.54 rijpinnen gebruikt om enkele ongebruikte digitale en analoge poorten op de driver uitbreidingskaart uit te voeren, zodat je andere sensoren kunt toevoegen en uitbreidingsproeven kunt uitvoeren.

De uitbreidingskaart kan worden aangesloten op vier DC-motoren. Wanneer de jumperkap standaard is aangesloten, zijn de motoren van poorten A en A1 en B en B1 parallel geschakeld en volgen ze dezelfde bewegingswet. 8 jumperkappen kunnen worden gebruikt om de draairichting van de 4 motorinterfaces te regelen.

Bijvoorbeeld, wanneer de 2 jumperkappen vóór B1 van de M1-motor veranderen van dwarsverbinding naar lengteverbinding, zal de draairichting van de M1-motor tegengesteld zijn aan de oorspronkelijke draairichting.

### **2. Specificaties**

- Ingangsspanning voor logica: DC 5V

- Ingangsspanning voor aandrijving: DC 6-9 V

- Werkstroom voor logica: \<36mA

- Werkstroom voor aandrijving: \<2A

- Maximale vermogensafgifte: 25W (T=75℃)

- Ingangsniveau voor besturingssignaal: hoog niveau is 2.3V\<Vin\<5V, laag niveau is -0.3V\<Vin\<1.5V

- Werkingstemperatuur: -25＋130℃

### **3. Keyestudio 8833 motor driver uitbreidingskaart**

![](media/A206.png)

**Werkingsprincipe**

We gebruiken dezelfde zijde parallelle aansluitingsmodus voor de vier motoren, die kunnen worden beschouwd als twee groepen motoren. Zoals te zien is in het bedradingsschema, vormen B en B1 een groep, en A en A1 een groep.

De motoren in dezelfde groep moeten in dezelfde richting draaien. Als ze verschillend zijn, pas dan de overeenkomstige jumperkappen naast de terminal aan om de richting te wijzigen.

Zoals hieronder weergegeven, als de richtingen van A en A1 verschillend zijn, pas dan de richting van de jumperkappen aan totdat de bewegingsrichting van de motoren in dezelfde groep consistent is.

![](media/A207.png)

Uit bovenstaande afbeelding blijkt dat de richtingspin van motor A D4 is, de snelheids-pin is D6; D2 is de richtingspin van motor B; en D6 is de snelheids-pin.

PWM stuurt de robotauto aan. De PWM-waarde ligt in het bereik van 0-255. Wanneer we de richting op HIGH zetten, geldt: hoe kleiner het PWM-getal, hoe sneller de motor draait.

<table border="1">
<tbody>
<tr class="odd">
<td></td>
<td>D2</td>
<td>D5（PWM）</td>
<td>B Motor（links）</td>
<td>D4</td>
<td>D6（PWM）</td>
<td>A Motor（rechts）</td>
</tr>
<tr class="even">
<td>Vooruit rijden</td>
<td>HIGH</td>
<td>255-200</td>
<td>Draait met de klok mee</td>
<td>HIGH</td>
<td>255-200</td>
<td>Draait met de klok mee</td>
</tr>
<tr class="odd">
<td>Achteruit rijden</td>
<td>LOW</td>
<td>200</td>
<td>Draait tegen de klok in</td>
<td>LOW</td>
<td>200</td>
<td>Draait tegen de klok in</td>
</tr>
<tr class="even">
<td>Linksaf slaan</td>
<td>HIGH</td>
<td>255-200</td>
<td>Draait met de klok mee</td>
<td>LOW</td>
<td>200</td>
<td>Draait tegen de klok in</td>
</tr>
<tr class="odd">
<td>Rechtsaf slaan</td>
<td>LOW</td>
<td>200</td>
<td>Draait tegen de klok in</td>
<td>HIGH</td>
<td>255-200</td>
<td>Draait met de klok mee</td>
</tr>
</tbody>
</table>
### **4. Componenten**

| Development Board *1      | 8833 Motor Driver *1      | USB-kabel *1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A208.jpg) | ![img](media/A209.jpg) | ![img](media/A210.jpg)         |
| 18650 Batterijhouder *1    | Motor *4                   | 18650 Batterij *2 (zelf mee te brengen) |
| ![img](media/A211.png) | ![img](media/A212.jpg) | ![img](media/A213.png)         |



### **5. Bedradingsschema**

![](media/A214.png)

Sluit de voeding aan op de BAT-poort.

### **6. Testcode**

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A126.png)

(2).![](media/A215.png)

(3).![](media/A216.png)

**Volledige testcode**

![Img](media/A217.png)

![](media/A218.png)

### **7. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet vervolgens de externe voeding aan en zet de DIP-schakelaar op ON, de auto rijdt 2 seconden vooruit, 2 seconden achteruit, 2 seconden naar links, 2 seconden naar rechts en stopt 2 seconden.

### **8. Code-uitleg**

Pas de snelheid aan waarmee PWM de motor aanstuurt, sluit op dezelfde manier aan.

**Volledige testcode**

![Img](media/A219.png)

![](media/A220.png)

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet vervolgens de externe voeding aan en zet de DIP-schakelaar op ON, dan merk je dat de snelheid van de motor veel langzamer is.

<span style="color: rgb(255, 76, 65);">Opmerking: </span>Een lage batterij leidt tot een lagere motorsnelheid.