# Projekt 4 Servo-Steuerung

### **1. Beschreibung**

![](media/A90.jpeg)

Ein Servomotor ist ein positionsgesteuerter Drehaktuator. Er besteht hauptsächlich aus einem Gehäuse, einer Leiterplatte, einem kernlosen Motor, einem Getriebe und einem Positionssensor. Sein Arbeitsprinzip besteht darin, dass der Servo das von MCUs oder Empfängern gesendete Signal empfängt und ein Referenzsignal mit einer Periode von 20 ms und einer Breite von 1,5 ms erzeugt, dann die erfasste Gleichstrom-Vorspannung mit der Spannung des Potentiometers vergleicht und die Spannungsdifferenz ausgibt.

![](media/A91.png)

Im Allgemeinen hat der Servo drei Leitungen in Braun, Rot und Orange. Die braune Leitung ist Masse, die rote ist die Plusleitung und die orange ist die Signalleitung.

Der Drehwinkel des Servomotors wird durch Regulierung des Tastverhältnisses des PWM-(Pulsweitenmodulation)-Signals gesteuert. Der Standardzyklus des PWM-Signals beträgt 20 ms (50 Hz). Theoretisch liegt die Pulsbreite zwischen 1 ms und 2 ms, tatsächlich jedoch zwischen 0,5 ms und 2,5 ms. Die Breite entspricht dem Drehwinkel von 0° bis 180°. Beachten Sie jedoch, dass bei verschiedenen Marken von Motoren dasselbe Signal unterschiedliche Drehwinkel bewirken kann.

![](media/A92.jpg)

Die entsprechenden Servo-Winkel sind unten dargestellt:

![](media/A93.png)

### **2. Spezifikation**

- Betriebsspannung: DC 4,8 V \~ 6 V

- Betriebswinkelbereich: ca. 180 ° (bei 500 → 2500 μs)

- Pulsweitenbereich: 500 → 2500 μs

- Leerlaufdrehzahl: 0,12 ± 0,01 s / 60 (DC 4,8 V) 0,1 ± 0,01 s / 60 (DC 6 V)
  
- Leerlaufstrom: 200 ± 20 mA (DC 4,8 V) 220 ± 20 mA (DC 6 V)

- Haltemoment: 1,3 ± 0,01 kg·cm (DC 4,8 V) 1,5 ± 0,1 kg·cm (DC 6 V)
  
- Haltestrom: ≦ 850 mA (DC 4,8 V) ≦ 1000 mA (DC 6 V)

- Standby-Strom: 3 ± 1 mA (DC 4,8 V) 4 ± 1 mA (DC 6 V)

### **3. Komponenten**

| Entwicklungsboard *1       | 8833 Motor Driver *1       | Servo*1                                     |
| -------------------------- | -------------------------- | ------------------------------------------- |
| ![img](media/A94.jpg)      | ![img](media/A95.jpg)      | ![img](media/A96.png)                       |
| 18650 Batteriehalter*1     | USB-Kabel*1                | 18650 Batterie*2 (selbst bereitgestellt)    |
| ![img](media/A97.png)      | ![img](media/A98.jpg)      | ![img](media/A99.png)                       |

### **4. Schaltplan**

![](media/A100.png)

Hinweis zur Verkabelung: Der Servo ist mit G (GND), V (VCC) und A3 verbunden, die braune Leitung des Servos ist mit GND (G) verbunden, die rote mit 5 V (V) und die orange mit A3.

Der Servo muss aufgrund seines hohen Strombedarfs für den Antrieb extern mit Strom versorgt werden. In der Regel reicht der Strom des Entwicklungsboards nicht aus. Ohne externe Stromversorgung könnte das Entwicklungsboard beschädigt werden.

### **5. Testcode**

Vor dem Schreiben des Codes muss die Servo-Bibliothek importiert werden. Die genauen Schritte sind wie folgt:

Klicken Sie auf ![](media/A29.png), um die Erweiterungsbibliothek für Sensoren/Module/Komponenten zu öffnen, und suchen Sie dann nach "**Servo**".

![](media/A101.png)

Wählen Sie die Komponente aus und klicken Sie darauf. Dadurch ändert sich "**Not Loaded**" zu "**loaded**", was anzeigt, dass die "**Servo**"-Komponente erfolgreich hinzugefügt wurde.

![Img](media/A102.png)

![](media/A103.png)

Klicken Sie auf ![](media/A33.png), um zum Code-Editor zurückzukehren. Im Modulbereich sehen Sie den hinzugefügten "**Servo**"-Komponentenblock.

![](media/A104.png)

Sie können Blöcke ziehen, um den Code zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1). ![](media/A105.png)

(2). ![](media/A106.png)

(3). ![](media/A107.png)

**Vollständiger Testcode**

![](media/A108.png)

### **6. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0-Board verbinden Sie die Verkabelung gemäß dem Schaltplan und schalten die externe Stromversorgung ein. Nach dem Einschalten stellen Sie den Dip-Schalter auf die "ON"-Position, dann schwingt der Servo im Bereich von 0° bis 180°.