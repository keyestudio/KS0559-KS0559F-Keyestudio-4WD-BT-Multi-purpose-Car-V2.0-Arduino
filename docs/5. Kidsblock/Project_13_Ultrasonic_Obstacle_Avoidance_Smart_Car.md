# Projekt 13 Ultraschall-Hindernisvermeidung Smart Car

![](media/A296.png)

### **1. Beschreibung**

In diesem Projekt wollen wir ein Ultraschall-Hindernisvermeidungs-Smart Car bauen. Wir verwenden den Ultraschallsensor, um den Abstand zum Hindernis zu messen, was genutzt wird, um den Servo zu steuern und das Auto zu bewegen. Gleichzeitig zeigt das 8x16 LED-Board das entsprechende Statusmuster an.

### **2. Flussdiagramm**

![img](media/A297.png)

**Die spezifische Logik des Ultraschall-Hindernisvermeidungs-Smart Cars ist unten dargestellt:**

![Img](media/A298.png)

![Img](media/A299.png)

### **3. Schaltplan**

![](media/A282.png)

1). GND, VCC, SDA und SCL des 8\*8 LED-Board-Moduls sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). VCC, Trig, Echo und GND des Ultraschallsensors sind mit 5V (V), D12 (S), D13 (S) und GND (G) verbunden.

3). Der Servo ist mit G, V und A3 verbunden. Das braune Kabel ist mit GND (G), das rote Kabel mit 5V (V) und das orange Kabel mit A3 verbunden.

4). Die Stromversorgung wird an den BAT-Anschluss angeschlossen.

### **4. Testcode**

Bevor der Code geschrieben wird, müssen die Bibliotheksdateien für den Ultraschallsensor, das 8x16 LED-Board und den Servo importiert werden. Die spezifischen Schritte sind wie folgt:

Klicke auf ![](media/A29.png), um die Erweiterungsbibliothek für Sensoren/Module/Komponenten zu öffnen, suche dann nach „Ultrasonic“ Sensor ![](media/A122.png) und klicke darauf. Dadurch ändert sich „**Not loaded**“ zu „**loaded**“, was bedeutet, dass der „**Ultrasonic**“ Sensor erfolgreich hinzugefügt wurde.

![Img](media/A300.png)

![](/media/A284.png)

Klicke auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Anweisungsblock des hinzugefügten „**Ultrasonic**“ Sensors, des „**Matrix 8\*16 Aip1640**“ Moduls und der „**Servo**“ Komponente ist im Modulbereich sichtbar.

![](media/A285.png)

Du kannst Blöcke ziehen, um zu programmieren. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A301.png)

(3).![](media/A302.png)

(4).![](media/A287.png)

(5).![](media/A288.png)

(6).![](media/A268.png)

(7).![](media/A289.png)

(8).![](media/A292.png)

(9).![](media/A290.png)

(10).![](media/A291.png)

**Vollständiger Testcode**

![](media/A303.png)

![](media/A304.png)

![](media/A305.png)

![](media/A306.png)

### **5. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board, verbinde die Verkabelung gemäß dem Schaltplan, schalte die externe Stromversorgung ein und stelle den DIP-Schalter auf ON.

Das Smart Car fährt vorwärts und weicht automatisch Hindernissen aus. Wenn kein Weg voraus ist, steuert der Servo den Ultraschallsensor, um die Abstände links, mittig und rechts zu scannen, und das Auto fährt in die offene Richtung. Gleichzeitig zeigt das 8x16 LED-Board das entsprechende Statusmuster an.