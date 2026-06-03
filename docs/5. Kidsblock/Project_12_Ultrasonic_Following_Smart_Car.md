# Project 12 Ultrasonic Following Smart Car

![](media/A280.png)

### **1.Beschrijving**

In dit project gaan we de afstand tussen de 4WD smart car en de obstakels voor hem detecteren met een ultrasone sensor om twee motoren aan te sturen zodat de auto beweegt en het 8\*8 LED-bord een glimlachend gezichtspatroon toont.

### **2.Stroomschema**

![img](media/A281.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Detectie</td>
<td>Gemeten afstand van voorliggende obstakels</td>
<td>afstand (eenheid: cm)</td>
</tr>
<tr class="even">
<td>Instelling</td>
<td>8*16 LED-bord toont een glimlachpatroon.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Servo instellen op 90°</td>
<td></td>
</tr>
<tr class="even">
<td>Voorwaarde</td>
<td>afstand≥20 en afstand≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>Status</td>
<td>Vooruit rijden</td>
<td></td>
</tr>
<tr class="even">
<td>Voorwaarde</td>
<td>afstand＞10 en afstand＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>afstand＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Voorwaarde</td>
<td>stoppen</td>
<td></td>
</tr>
<tr class="odd">
<td>Voorwaarde</td>
<td>afstand≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Voorwaarde</td>
<td>achteruit rijden</td>
<td></td>
</tr>
</tbody>
</table>


### **3.Aansluitschema**

![](media/A282.png)

**Aansluiten:**

1). GND, VCC, SDA en SCL van het 8\*8 LED-bord zijn verbonden met G (GND), V (VCC), A4 en A5 van de uitbreidingskaart.

2). VCC, Trig, Echo en Gnd van de ultrasone sensor zijn verbonden met 5V (V), D12 (S), D13 (S) en Gnd (G).

3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad op 5V (V) en de oranje draad op A3.

4). De voeding is aangesloten op de BAT-poort.

### **4.Testcode**

Voordat je de code schrijft, is het nodig om de bibliotheekbestanden van de ultrasone sensor, het 8x16 LED-bord en de servo te importeren. De specifieke stappen zijn als volgt:

Klik op ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek dan naar “Ultrasonic” sensor ![](media/A122.png) en klik erop.

Hierdoor verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de “**Ultrasonic**” sensor succesvol is toegevoegd.

![Img](media/A283.png)

![](/media/A284.png)

De bibliotheekbestanden van het 8x16 LED-bord en de servo worden op dezelfde manier toegevoegd als die van de ultrasone sensor.

Klik op ![](media/A33.png) om terug te keren naar de code-editorinterface, de instructieblokken van de toegevoegde “**Ultrasonic**” sensor, “**Matrix 8\*16 Aip1640**” module en “**Servo**” component zijn zichtbaar in het modulegebied.

![](media/A285.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie:

(1).![](media/A126.png)

(2).![](media/A286.png)

(3).![](media/A287.png)

(4).![](media/A288.png)

(5).![](media/A268.png)

(6).![](media/A289.png)

(7).![](media/A290.png)

(8).![](media/A291.png)

(9).![](media/A292.png)

**Volledige testcode**

![](media/A293.png)

![](media/A294.png)

![](media/A295.png)

### **5.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het aansluitschema, zet de externe voeding aan en zet de DIP-switch op ON. Stel de servo in op 90°, de smart car zal bewegen met de obstakels mee en het 8X16 LED-bord zal een “glimlach” tonen.