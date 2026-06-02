# Projekt 17 Multifunktionales Bluetooth Smart Car

![](media/A349.jpeg)

### **1. Beschreibung**

In vorherigen Projekten führt das Auto nur eine einzelne Funktion aus. In dieser Lektion werden wir jedoch alle seine Funktionen über Bluetooth integrieren.

### **2. Flussdiagramm**

![](media/A350.png)

### **3. Schaltplan**

![](media/A351.png)

1). GND, VCC, SDA und SCL des 8\*8 LED-Boards sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). RXD, TXD, GND und VCC des Bluetooth-Moduls sind jeweils mit TX, RX, G und 5V auf dem 8833 Motor-Treiber-Erweiterungsboard verbunden, während die STATE- und BRK-Pins des Bluetooth-Moduls nicht angeschlossen werden müssen.

3). Der Servo ist mit G, V und A3 verbunden. Der braune Draht ist mit Gnd (G), der rote Draht mit 5V (V) und der orange Draht mit A3 verbunden.

4). G, V, S1, S2 und S3 des Linienverfolgungssensors sind mit G (GND), V (VCC), D11, D7 und D8 des Sensor-Erweiterungsboards verbunden.

5). VCC, Trig, Echo und Gnd des Ultraschallsensors sind mit 5V (V), D12 (S), D13 (S) und Gnd (G) verbunden.

6). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

Bevor der Code geschrieben wird, müssen die Bibliotheksdateien des Ultraschallsensors, des 8x16 LED-Boards und des Servos importiert werden. Die spezifischen Schritte sind wie folgt:

Klicke auf ![](media/A29.png), um die Erweiterungsbibliotheksschnittstelle für Sensoren/Module/Komponenten zu öffnen, suche dann nach „**Ultrasonic**“ Sensor ![](media/A122.png) und klicke darauf. Dadurch ändert sich „**Not loaded**“ zu „**loaded**“, was anzeigt, dass der „**Ultrasonic**“ Sensor erfolgreich hinzugefügt wurde.

![Img](media/A300.png)![](media/A124.png)

Klicke auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Befehlsblock des hinzugefügten „**Ultrasonic**“ Sensors, des „**Matrix 8\*16 Aip1640**“ Moduls und der „**Servo**“ Komponente ist im Modulbereich sichtbar.

![](media/A285.png)

**Vollständiger Testcode**

<span style="color: rgb(255, 76, 65);">**Hinweis:** Vor dem Hochladen des Testcodes muss das Bluetooth-Modul entfernt werden, da sonst der Code nicht hochgeladen werden kann. Verbinde das Bluetooth-Modul erst nach erfolgreichem Hochladen des Codes.</span>

![](media/A352.png)

### **5. Testergebnis**

Nach dem erfolgreichen Hochladen des Codes auf das V4.0 Board, verbinde die Verkabelung gemäß dem Schaltplan, schalte die externe Stromversorgung ein und stelle den DIP-Schalter auf ON.

Nachdem das Bluetooth-Modul mit der APP verbunden ist und die mobile APP erfolgreich mit Bluetooth gekoppelt wurde, kann das Smart Car über die mobile APP gesteuert werden. Wir können die entsprechenden Funktionen durch Drücken der entsprechenden Tasten in der mobilen APP ausführen.