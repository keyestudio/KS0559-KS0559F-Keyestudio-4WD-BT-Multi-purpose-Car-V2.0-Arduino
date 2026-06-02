# Projekt 10 Einschränkendes Smart Car

![](media/A261.jpeg)

### **1. Beschreibung**

In diesem Projekt kombinieren wir das Wissen über einen Linienverfolgungssensor und Motortreiber-Module, um ein einschränkendes Smart Car zu bauen. Im Experiment wollen wir den Linienverfolgungssensor verwenden, um zu erkennen, ob sich eine schwarze Linie um das Smart Car befindet, und dann die Drehung der beiden Motoren entsprechend den Erkennungsergebnissen so steuern, dass das Smart Car in einem im Kreis gezogenen schwarzen Linien eingeschlossen wird.

### **2. Flussdiagramm**

![img](media/A262.png)

Die spezifische Logik des einschränkenden 4WD Smart Cars ist in der Tabelle dargestellt.

![Img](media/A263.png)

### **3. Schaltplan**

![](media/A264.png)

G, V, S1, S2 und S3 des Linienverfolgungssensors sind mit G (GND), V (VCC), D11, D7 und D8 des Sensor-Erweiterungsboards verbunden.

Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A265.png)

(3).![](media/A266.png)

(4).![](media/A267.png)

(5).![](media/A268.png)

(6).![](media/A269.png)

**Vollständiger Testcode**

![KidsBlock Project-1747127137354](media/A270.png)

### **5. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie die externe Stromversorgung ein und stellen Sie den DIP-Schalter auf ON. Stellen Sie das Smart Car in den schwarzen Kreis, dann bewegt es sich ausschließlich im Kreis.