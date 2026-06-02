# Projekt 14 IR-Fernbedienung Smart Car

![](media/A307.jpeg)

### **1. Beschreibung**

In diesem Projekt bauen wir ein IR-Fernbedienungs-Smart-Car und drücken die Taste auf der IR-Fernbedienung, um das Auto zu bewegen.

### **2. Flussdiagramm**

![img](media/A308.png)

**Die spezifische Logik des IR-Fernbedienungs-Smart-Cars ist unten dargestellt:**

| Anfangskonfiguration                                       |           | LED-Board zeigt ein Smiley                         |
| ---------------------------------------------------------- | --------- | ------------------------------------------------- |
| Fernbedienung                                              | Tastencode| Tastenzustand                                     |
| ![wps6-1747037981476-25](media/A309.jpg) | FF629D    | Vorwärts 8*8 LED-Board zeigt Vorwärtssymbol       |
| ![wps7-1747037985784-27](media/A310.jpg) | FFA857    | Rückwärts 8*8 LED-Board zeigt Rückwärtssymbol     |
| ![wps8](media/A311.jpg)                  | FF22DD    | Nach links drehen 8*8 LED-Board zeigt Links-Symbol|
| ![wps9](media/A312.jpg)                  | FFC23D    | Nach rechts drehen 8*8 LED-Board zeigt Rechts-Symbol|
| ![wps10](media/A313.jpg)                                 | FF02FD    | Stopp 8*8 LED-Board zeigt „STOP“                   |



### **3. Schaltplan**

![](media/A314.png)

1). GND, VCC, SDA und SCL des 8\*8 LED-Board-Moduls sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.
    
2). Da der IR-Empfänger im 8833 Motor-Treiber-Erweiterungsboard integriert ist, ist keine zusätzliche Verkabelung erforderlich. Die Pins des IR-Empfängers auf dem 8833-Board sind jeweils G (GND), V (VCC) und D3.
    
3). Der Servo ist mit G, V und A3 verbunden. Der braune Draht ist mit Gnd (G) verbunden, der rote Draht mit 5V (V) und der orange Draht mit A3.
    
4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.
    

### **4. Testcode**

<span style="color: rgb(255, 76, 65);">Bitte beachten: Das im Software-Demonstrationsbild gezeigte Infrarotmodul ist bereits in das Erweiterungsboard integriert und wird nicht separat geliefert. Folglich finden Sie das im Bild unten dargestellte Modul nicht im Produkt.![](media/A144.png)</span>

Vor dem Schreiben des Codes müssen die Bibliotheksdateien des Ultraschallsensors, des 8x16 LED-Boards und des Servos importiert werden. Die spezifischen Schritte sind wie folgt: 
    
Klicken Sie auf ![](media/A29.png), um die Erweiterungsbibliothek für Sensoren/Module/Komponenten zu öffnen, suchen Sie dann nach „ir remote“ Sensor ![](media/A144.png) und klicken Sie darauf. Dadurch ändert sich „**Not loaded**“ zu „**loaded**“, was anzeigt, dass der „**ir remote**“ Sensor erfolgreich hinzugefügt wurde. 

![Img](media/A315.png)

![](media/A146.png)

Klicken Sie auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Anweisungsblock des hinzugefügten „**ir remote**“ Sensors, des „**Matrix 8\*16 Aip1640**“ Moduls und der „**Servo**“ Komponente ist im Modulbereich sichtbar. 

![](media/A316.png)

Sie können Blöcke ziehen, um zu programmieren. Die unten aufgeführten Blöcke dienen als Referenz:

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A318.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A320.png)

(7).![](media/A291.png)

(8).![](media/A321.png)

**Vollständiger Testcode**

![](media/A322.png)

![](media/A323.png)

![](media/A324.png)

![](media/A325.png)

![](media/A326.png)

### **5. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten die externe Stromversorgung ein und stellen den DIP-Schalter auf ON. Dann können Sie mit der IR-Fernbedienung das Auto steuern und das 8X16 LED-Board zeigt das entsprechende Statusmuster an.