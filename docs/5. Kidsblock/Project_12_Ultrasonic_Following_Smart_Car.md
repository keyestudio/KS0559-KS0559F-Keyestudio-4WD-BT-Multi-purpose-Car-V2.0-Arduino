# Projekt 12 Ultraschall Folgendes Smart Car

![](media/A280.png)

### **1. Beschreibung**

In diesem Projekt werden wir den Abstand zwischen dem 4WD Smart Car und den Hindernissen davor mithilfe eines Ultraschallsensors erfassen, um zwei Motoren so zu steuern, dass das Auto sich bewegt und die 8\*8 LED-Anzeige ein lächelndes Gesichtsmuster zeigt.

### **2. Flussdiagramm**

![img](media/A281.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Erkennung</td>
<td>Gemessener Abstand der vorderen Hindernisse</td>
<td>Abstand (Einheit: cm)</td>
</tr>
<tr class="even">
<td>Einstellung</td>
<td>8*16 LED-Anzeige zeigt ein Lächelmuster.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Servo auf 90° einstellen</td>
<td></td>
</tr>
<tr class="even">
<td>Bedingung</td>
<td>Abstand≥20 und Abstand≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>Status</td>
<td>Vorwärts fahren</td>
<td></td>
</tr>
<tr class="even">
<td>Bedingung</td>
<td>Abstand＞10 und Abstand＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Abstand＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Bedingung</td>
<td>Anhalten</td>
<td></td>
</tr>
<tr class="odd">
<td>Bedingung</td>
<td>Abstand≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Bedingung</td>
<td>Rückwärts fahren</td>
<td></td>
</tr>
</tbody>
</table>


### **3. Schaltplan**

![](media/A282.png)

**Anschluss:**

1). GND, VCC, SDA und SCL der 8\*8 LED-Anzeige sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.

2). VCC, Trig, Echo und GND des Ultraschallsensors sind mit 5V (V), D12 (S), D13 (S) und GND (G) verbunden.

3). Der Servo ist mit G, V und A3 verbunden. Der braune Draht ist mit GND (G), der rote Draht mit 5V (V) und der orange Draht mit A3 verbunden.

4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.

### **4. Testcode**

Bevor der Code geschrieben wird, müssen die Bibliotheksdateien des Ultraschallsensors, der 8x16 LED-Anzeige und des Servos importiert werden. Die konkreten Schritte sind wie folgt:

Klicken Sie auf ![](media/A29.png), um die Erweiterungsbibliothek für Sensoren/Module/Komponenten zu öffnen, suchen Sie dann nach „Ultrasonic“ Sensor ![](media/A122.png) und klicken Sie darauf.

Dadurch ändert sich „**Not loaded**“ zu „**loaded**“, was anzeigt, dass der „**Ultrasonic**“ Sensor erfolgreich hinzugefügt wurde.

![Img](media/A283.png)

![](/media/A284.png)

Die Bibliotheksdateien für die 8x16 LED-Anzeige und den Servo werden auf dieselbe Weise wie der Ultraschallsensor hinzugefügt.

Klicken Sie auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Befehlsblock des hinzugefügten „**Ultrasonic**“ Sensors, des „**Matrix 8\*16 Aip1640**“ Moduls und der „**Servo**“ Komponente ist im Modulbereich sichtbar.

![](media/A285.png)

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz:

(1).![](media/A126.png)

(2).![](media/A286.png)

(3).![](media/A287.png)

(4).![](media/A288.png)

(5).![](media/A268.png)

(6).![](media/A289.png)

(7).![](media/A290.png)

(8).![](media/A291.png)

(9).![](media/A292.png)

**Vollständiger Testcode**

![](media/A293.png)

![](media/A294.png)

![](media/A295.png)

### **5. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten die externe Stromversorgung ein und stellen den DIP-Schalter auf ON. Stellen Sie den Servo auf 90°, das Smart Car bewegt sich entsprechend den Hindernissen und die 8X16 LED-Anzeige zeigt ein „Lächeln“.