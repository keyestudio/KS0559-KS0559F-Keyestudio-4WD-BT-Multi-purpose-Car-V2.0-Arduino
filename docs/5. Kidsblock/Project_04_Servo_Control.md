# Project 4 Servo Control

### **1.Beschrijving**

![](media/A90.jpeg)

Een servomotor is een positie-gestuurde roterende actuator. Het bestaat voornamelijk uit een behuizing, een printplaat, een kernloze motor, een tandwiel en een positietransducer. Het werkingsprincipe is dat de servo het signaal ontvangt dat door MCU's of ontvangers wordt verzonden en een referentiesignaal produceert met een periode van 20 ms en een breedte van 1,5 ms, vervolgens vergelijkt het de verkregen DC-voorspanning met de spanning van de potentiometer en verkrijgt het spanningsverschil als uitgang.

![](media/A91.png)

Over het algemeen heeft een servo drie draden in bruin, rood en oranje. De bruine draad is de aarde, de rode is de positieve lijn en de oranje is de signaallijn.

De rotatiehoek van de servomotor wordt geregeld door de duty cycle van het PWM (Pulse-Width Modulation) signaal aan te passen. De standaardcyclus van het PWM-signaal is 20 ms (50 Hz). Theoretisch ligt de breedte tussen 1 ms en 2 ms, maar in de praktijk is het tussen 0,5 ms en 2,5 ms. De breedte komt overeen met de rotatiehoek van 0° tot 180°. Let op dat bij verschillende merken motoren hetzelfde signaal verschillende rotatiehoeken kan veroorzaken.

![](media/A92.jpg)

De bijbehorende servohoeken worden hieronder weergegeven:

![](media/A93.png)

### **2.Specificaties**

- Werkspanning: DC 4,8V ~ 6V

- Werkingshoek bereik: ongeveer 180° (bij 500 → 2500 μsec)

- Pulsbreedte bereik: 500 → 2500 μsec

- Snelheid zonder belasting: 0,12 ± 0,01 sec / 60 (DC 4,8V) 0,1 ± 0,01 sec / 60 (DC 6V)
  
- Stroom zonder belasting: 200 ± 20mA (DC 4,8V) 220 ± 20mA (DC 6V)

- Stopkoppel: 1,3 ± 0,01 kg·cm (DC 4,8V) 1,5 ± 0,1 kg·cm (DC 6V)
  
- Stopstroom: ≦ 850mA (DC 4,8V) ≦ 1000mA (DC 6V)

- Stand-by stroom: 3 ± 1mA (DC 4,8V) 4 ± 1mA (DC 6V)

### **3.Componenten**

| Ontwikkelbord *1           | 8833 Motor Driver *1       | Servo*1                                     |
| ------------------------- | ------------------------- | ------------------------------------------- |
| ![img](media/A94.jpg)     | ![img](media/A95.jpg)     | ![img](media/A96.png)                        |
| 18650 Batterijhouder*1    | USB-kabel*1               | 18650 Batterij*2 (zelf mee te brengen)      |
| ![img](media/A97.png)     | ![img](media/A98.jpg)     | ![img](media/A99.png)                        |

### **4.Aansluitschema**

![](media/A100.png)

Aansluitnotitie: De servo is verbonden met G (GND), V (VCC) en A3, de bruine draad van de servo is verbonden met Gnd (G), de rode is verbonden met 5V (V) en de oranje is aangesloten op A3.

De servo moet worden aangesloten op een externe voeding vanwege de hoge stroomvraag voor het aansturen van de servo. Over het algemeen is de stroom van het ontwikkelbord niet groot genoeg. Zonder externe voeding kan het ontwikkelbord doorbranden.

### **5.Testcode**

Voordat je de code schrijft, is het noodzakelijk om de servo-bibliotheek te importeren. De specifieke stappen zijn als volgt:

Klik op ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek vervolgens naar "**Servo**".

![](media/A101.png)  
Selecteer de component en klik erop. Hierdoor verandert "**Not Loaded**" in "**loaded**", wat aangeeft dat de "**Servo**" component succesvol is toegevoegd.

![Img](media/A102.png)

![](media/A103.png)

Klik op ![](media/A33.png) om terug te keren naar de code-editor, en in het modules-gedeelte zie je het toegevoegde "**Servo**" component directive blok.

![](media/A104.png)

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A105.png)

(2).![](media/A106.png)

(3).![](media/A107.png)

**Volledige Testcode**

![](media/A108.png)

### **6.Testresultaat**

Na het succesvol uploaden van de code naar het V4.0 bord, verbind je de bedrading volgens het aansluitschema en zet je de externe voeding aan. Na het inschakelen zet je de dip-switch op de "ON" stand, waarna de servo zal bewegen binnen het bereik van 0° tot 180°.