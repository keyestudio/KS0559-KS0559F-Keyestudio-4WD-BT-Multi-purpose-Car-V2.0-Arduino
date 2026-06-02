# Projekt 16 Bluetooth Geschwindigkeitssteuerung Smart Car

![](media/A327.jpeg)

### **1. Beschreibung**

In diesem Projekt verwenden wir Bluetooth, um die Geschwindigkeit des Smart Cars anzupassen. Wir definieren variable Geschwindigkeiten und ändern diese, um die Geschwindigkeit des Smart Cars zu steuern.

### **2. Flussdiagramm**

![image-20250513095810478](media/A340.png)

### **3. Schaltplan**

![](media/A329.png)

1). GND, VCC, SDA und SCL des 8\*8 LED-Boards sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). RXD, TXD, GND und VCC des Bluetooth-Moduls sind jeweils mit TX, RX, G und 5V auf dem 8833 Motor-Treiber-Erweiterungsboard verbunden, während die STATE- und BRK-Pins des Bluetooth-Moduls nicht angeschlossen werden müssen.

3). Das Servo ist mit G, V und A3 verbunden. Der braune Draht ist mit Gnd (G), der rote Draht mit 5V (V) und der orange Draht mit A3 verbunden.

4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

Bevor der Code geschrieben wird, müssen die Bibliotheksdateien des 8x16 LED-Boards und des Servos importiert werden. Die konkreten Schritte sind wie folgt:

Klicke auf ![](media/A29.png), um die Erweiterungsbibliothek für Sensoren/Module/Komponenten zu öffnen, suche dann nach dem Modul „Matrix 8\*16 Aip1640“ ![](media/A236.png) und klicke darauf. Dadurch ändert sich „**Not loaded**“ zu „**loaded**“, was anzeigt, dass das Modul „**Matrix 8\*16 Aip1640**“ erfolgreich hinzugefügt wurde.

![Img](media/A237.png)![](media/A238.png)

Klicke auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Anweisungsblock des hinzugefügten „**Matrix 8\*16 Aip1640**“-Moduls und der „**Servo**“-Komponente ist im Modulbereich sichtbar.

![](media/A330.png)

Du kannst Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz:

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

(10).![](media/A341.png)

**Vollständiger Testcode**

<span style="color: rgb(255, 76, 65);">**Hinweis:** Vor dem Hochladen des Testcodes muss das Bluetooth-Modul entfernt werden, da sonst das Hochladen fehlschlägt. Verbinde das Bluetooth-Modul erst nach erfolgreichem Hochladen des Codes.</span>

![](media/A342.png)

![](media/A343.png)

![](media/A344.png)

![](media/A345.png)

![](media/A346.png)

![](media/A346.png)

### **5. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board, verbinde die Verkabelung gemäß dem Schaltplan, schalte die externe Stromversorgung ein und stelle den DIP-Schalter auf ON. Koppel die APP mit Bluetooth, dann kann das Smart Car über die APP gesteuert werden.

Drücke ![](media/A347.png), das Auto beschleunigt, drücke ![](media/A348.png), das Auto verlangsamt sich, und das 8\*16 LED-Board zeigt das entsprechende Statusmuster des Smart Cars an.