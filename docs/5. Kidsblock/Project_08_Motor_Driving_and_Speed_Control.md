# Projekt 8 Motorsteuerung und Geschwindigkeitsregelung

![](media/A205.png)

### **1. Beschreibung**

Es gibt viele Möglichkeiten, Motoren anzusteuern. Unser Auto verwendet den am häufigsten eingesetzten DRV8833 Motor-Treiber-Chip, der eine zweikanalige Brückenantriebslösung für Spielzeuge, Drucker und andere integrierte Motoranwendungen bietet.

Wenn wir die Treiber-Erweiterungsplatine auf das 4.0 Entwicklungsboard stecken und die BAT einschalten, und dann den DIP-Schalter auf die ON-Seite stellen, wird die externe Stromversorgung beide Platinen gleichzeitig mit Strom versorgen. Zur Erleichterung der Verkabelung verfügt die Treiber-Erweiterungsplatine über einen Verpolungsschutzanschluss (PH2.0-2P-3P-4P-5P). Sie können die Motoren, die Stromversorgung und Sensormodule direkt an die Treiber-Erweiterungsplatine anschließen.

Die Bluetooth-Schnittstelle der Treiber-Erweiterungsplatine ist vollständig kompatibel mit dem DX-BT24 5.1 Bluetooth-Modul. Beim Anschluss des Bluetooth-Moduls müssen Sie es nur in die entsprechende Schnittstelle stecken. Gleichzeitig werden 2,54 mm Stiftleisten verwendet, um einige ungenutzte digitale und analoge Ports auf der Treiber-Erweiterungsplatine herauszuführen, sodass Sie weitere Sensoren hinzufügen und Erweiterungsexperimente durchführen können.

Die Erweiterungsplatine kann an vier Gleichstrommotoren angeschlossen werden. Wenn die Jumper-Kappen standardmäßig verbunden sind, sind die Motoren der Ports A und A1 sowie B und B1 parallel geschaltet und haben das gleiche Bewegungsverhalten. 8 Jumper-Kappen können verwendet werden, um die Drehrichtung der 4 Motoranschlüsse zu steuern.

Zum Beispiel, wenn die 2 Jumper-Kappen vor B1 des M1-Motors von Quer- auf Längsverbindung geändert werden, dreht sich der M1-Motor in die entgegengesetzte Richtung zur ursprünglichen Drehrichtung.

### **2. Spezifikation**

- Eingangsspannung für Logik: DC 5V

- Eingangsspannung für Antrieb: DC 6-9 V

- Arbeitsstrom für Logik: \<36mA

- Arbeitsstrom für Antrieb: \<2A

- Maximale Verlustleistung: 25W (T=75℃)

- Eingangspegel für Steuersignal: High-Pegel ist 2,3V\<Vin\<5V, Low-Pegel ist -0,3V\<Vin\<1,5V

- Arbeitstemperatur: -25 bis +130℃

### **3. Keyestudio 8833 Motor-Treiber-Erweiterungsplatine**

![](media/A206.png)

**Funktionsprinzip**

Wir verwenden für die vier Motoren die gleiche Seiten-Parallel-Schaltung, die als zwei Motorgruppen betrachtet werden kann. Wie im Schaltplan gezeigt, sind B und B1 eine Gruppe, und A und A1 eine Gruppe.

Die Motoren in derselben Gruppe sollten sich in die gleiche Richtung drehen. Wenn sie unterschiedlich sind, passen Sie bitte die entsprechenden Jumper-Kappen neben dem Anschluss an, um die Richtung zu ändern.

Wie unten gezeigt, wenn die Richtungen von A und A1 unterschiedlich sind, justieren Sie die Richtung der Jumper-Kappen, bis die Bewegungsrichtung der Motoren in derselben Gruppe übereinstimmt.

![](media/A207.png)

Aus dem obigen Diagramm ist ersichtlich, dass der Richtungs-Pin des A-Motors D4 ist, der Geschwindigkeits-Pin D6; D2 ist der Richtungs-Pin des B-Motors; und D6 ist der Geschwindigkeits-Pin.

PWM steuert das Roboterauto. Der PWM-Wert liegt im Bereich von 0-255. Wenn wir die Richtung auf HIGH setzen, gilt: Je kleiner die PWM-Zahl, desto schneller dreht sich der Motor.

<table border="1">
<tbody>
<tr class="odd">
<td></td>
<td>D2</td>
<td>D5（PWM）</td>
<td>B Motor（links）</td>
<td>D4</td>
<td>D6（PWM）</td>
<td>A Motor（rechts）</td>
</tr>
<tr class="even">
<td>Vorwärts fahren</td>
<td>HIGH</td>
<td>255-200</td>
<td>Dreht im Uhrzeigersinn</td>
<td>HIGH</td>
<td>255-200</td>
<td>Dreht im Uhrzeigersinn</td>
</tr>
<tr class="odd">
<td>Rückwärts fahren</td>
<td>LOW</td>
<td>200</td>
<td>Dreht gegen den Uhrzeigersinn</td>
<td>LOW</td>
<td>200</td>
<td>Dreht gegen den Uhrzeigersinn</td>
</tr>
<tr class="even">
<td>Links abbiegen</td>
<td>HIGH</td>
<td>255-200</td>
<td>Dreht im Uhrzeigersinn</td>
<td>LOW</td>
<td>200</td>
<td>Dreht gegen den Uhrzeigersinn</td>
</tr>
<tr class="odd">
<td>Rechts abbiegen</td>
<td>LOW</td>
<td>200</td>
<td>Dreht gegen den Uhrzeigersinn</td>
<td>HIGH</td>
<td>255-200</td>
<td>Dreht im Uhrzeigersinn</td>
</tr>
</tbody>
</table>
### **4. Komponenten**

| Development Board *1      | 8833 Motor Driver *1      | USB-Kabel*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A208.jpg) | ![img](media/A209.jpg) | ![img](media/A210.jpg)         |
| 18650 Batteriehalter*1    | Motor*4                   | 18650 Batterie *2（selbst bereitgestellt） |
| ![img](media/A211.png) | ![img](media/A212.jpg) | ![img](media/A213.png)         |



### **5. Schaltplan**

![](media/A214.png)

Verbinden Sie die Stromversorgung mit dem BAT-Anschluss.

### **6. Testcode**

Sie können Blöcke ziehen, um sie zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz

(1).![](media/A126.png)

(2).![](media/A215.png)

(3).![](media/A216.png)

**Vollständiger Testcode**

![Img](media/A217.png)

![](media/A218.png)

### **7. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0-Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie dann die externe Stromversorgung ein und stellen Sie den DIP-Schalter auf ON. Das Auto fährt 2 Sekunden vorwärts, 2 Sekunden rückwärts, 2 Sekunden nach links, 2 Sekunden nach rechts und hält dann 2 Sekunden an.

### **8. Code-Erklärung**

Passen Sie die Geschwindigkeit an, mit der PWM den Motor steuert, schließen Sie auf die gleiche Weise an.

**Vollständiger Testcode**

![Img](media/A219.png)

![](media/A220.png)

Nachdem der Code erfolgreich auf das V4.0-Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie dann die externe Stromversorgung ein und stellen Sie den DIP-Schalter auf ON. Dann stellen Sie fest, dass die Geschwindigkeit des Motors viel langsamer ist.

<span style="color: rgb(255, 76, 65);">Hinweis: </span>Eine niedrige Batteriespannung führt zu einer langsameren Motordrehzahl.