# Project 14 IR Afstandsbediening Smart Car

![](media/A307.jpeg)

### **1.Beschrijving**

In dit project maken we een IR-afstandsbediening smart car en drukken we op de knop van de IR-afstandsbediening om de auto te laten bewegen.

### **2.Stroomschema**

![img](media/A308.png)

**De specifieke logica van de IR-afstandsbediening smart car wordt hieronder weergegeven:**

| Initiële setup                                             |           | LED-board toont smiley                             |
| ---------------------------------------------------------- | --------- | ------------------------------------------------- |
| Afstandsbediening                                          | Sleutelwaarde | Sleutelstatus                                     |
| ![wps6-1747037981476-25](media/A309.jpg) | FF629D    | Vooruit8*8 LED-board toont voorwaarts icoon       |
| ![wps7-1747037985784-27](media/A310.jpg) | FFA857    | Achteruit8*8 LED-board toont achterwaarts icoon   |
| ![wps8](media/A311.jpg)                  | FF22DD    | Draai naar links8*8 LED-board toont links icoon   |
| ![wps9](media/A312.jpg)                  | FFC23D    | Draai naar rechts8*8 LED-board toont rechts icoon |
| ![wps10](media/A313.jpg)                                 | FF02FD    | Stop8*8 LED-board toont “STOP”                     |



### **3.Aansluitschema**

![](media/A314.png)

1). GND, VCC, SDA en SCL van het 8\*8 LED-board module zijn verbonden met G (GND), V (VCC), A4 en A5 van de uitbreidingskaart.
    
2). Omdat de IR-ontvanger geïntegreerd is op de 8833 motor driver uitbreidingskaart, is extra bedrading niet nodig. De pinnen van de IR-ontvanger op de 8833 kaart zijn respectievelijk G (GND), V (VCC) en D3. 
    
3). De servo is verbonden met G, V en A3. De bruine draad is aangesloten op Gnd (G), de rode draad op 5V (V) en de oranje draad op A3.
    
4). De voeding is aangesloten op de BAT-poort
    

### **4.Testcode**

<span style="color: rgb(255, 76, 65);">Let op: De infraroodmodule die in de softwaredemonstratie wordt getoond, is al geïntegreerd in de uitbreidingskaart en wordt niet afzonderlijk geleverd. Daarom vindt u de module die op de afbeelding hieronder staat niet in het product.![](media/A144.png)</span>

Voordat je de code schrijft, is het noodzakelijk om de bibliotheekbestanden van de ultrasone sensor, 8x16 LED-board en de servo te importeren. De specifieke stappen zijn als volgt: 
    
Klik op ![](media/A29.png) om de extensiebibliotheekinterface van sensoren/modules/componenten te openen, zoek vervolgens naar de “ir remote” sensor ![](media/A144.png) en klik erop. Hierdoor verandert "**Not loaded**" in "**loaded**", wat aangeeft dat de “**ir remote**” sensor succesvol is toegevoegd. 

![Img](media/A315.png)

![](media/A146.png)

Klik op ![](media/A33.png) om terug te keren naar de code-editor interface, de instructieblokken van de toegevoegde “**ir remote**” sensor, “**Matrix 8\*16 Aip1640**” module en “**Servo**” component zijn zichtbaar in het modulegebied. 

![](media/A316.png)

Je kunt blokken slepen om te bewerken. Hieronder staan blokken ter referentie

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A318.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A320.png)

(7).![](media/A291.png)

(8).![](media/A321.png)

**Volledige testcode**

![](media/A322.png)

![](media/A323.png)

![](media/A324.png)

![](media/A325.png)

![](media/A326.png)

### **5.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind je de bedrading volgens het aansluitschema, zet je de externe voeding aan en zet je de DIP-switch op ON. Vervolgens kun je de IR-afstandsbediening gebruiken om de auto te laten bewegen en zal het 8X16 LED-board het overeenkomstige statuspatroon weergeven.