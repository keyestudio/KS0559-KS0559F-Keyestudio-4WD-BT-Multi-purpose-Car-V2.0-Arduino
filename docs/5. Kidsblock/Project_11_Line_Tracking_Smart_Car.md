# Projekt 11 Linienverfolgungs-Smartcar

![](media/A271.png)

### **1. Beschreibung**

Basierend auf dem Arbeitsprinzip des Linienverfolgungssensors ermöglichen wir die Herstellung eines Linienverfolgungs-Smartcars.

In diesem Projekt erkennen wir durch einen Linienverfolgungssensor, ob sich unter dem Smartcar eine schwarze Linie befindet, und steuern dann die Drehung der beiden Motorgruppen entsprechend den Erkennungsergebnissen, um das Smartcar entlang der schwarzen Linie fahren zu lassen.

### **2. Flussdiagramm**

![img](media/A272.png)

![Img](media/A273.png)

### **3. Schaltplan**

![](media/A264.png)

G, V, S1, S2 und S3 des Linienverfolgungssensors sind mit G (GND), V (VCC), D11, D7 und D8 des Sensor-Erweiterungsboards verbunden.

Die Stromversorgung wird an den BAT-Anschluss angeschlossen.

### **4. Testcode**

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A274.png)

(3).![](media/A275.png)

(4).![](media/A268.png)

(5).![](media/A276.png)

**Vollständiger Testcode**

![](media/A277.png)

![](media/A278.png)

![](media/A279.png)

### **5. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0-Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie die externe Stromversorgung ein und stellen Sie dann den DIP-Schalter auf ON. Das Smartcar fährt dann entlang der Linien.