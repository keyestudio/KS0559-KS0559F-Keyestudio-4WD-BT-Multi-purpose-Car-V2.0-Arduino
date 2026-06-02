# Projekt 5 Ultraschallsensor

### **1. Beschreibung**

![](media/A109.png)

Der HC-SR04 Ultraschallsensor verwendet Sonar, um die Entfernung zu einem Objekt zu bestimmen, ähnlich wie Fledermäuse es tun. Er bietet eine ausgezeichnete berührungslose Abstandserkennung mit hoher Genauigkeit und stabilen Messwerten in einem einfach zu verwendenden Paket. Er besteht aus einem Ultraschall-Sender- und Empfangsmodul.

![Img](media/A110.png)

Der HC-SR04 oder der Ultraschallsensor wird in einer Vielzahl von Elektronikprojekten verwendet, um Hinderniserkennung und Distanzmessanwendungen sowie verschiedene andere Anwendungen zu realisieren. Hier zeigen wir die einfache Methode, die Entfernung mit Arduino und einem Ultraschallsensor zu messen und wie man den Ultraschallsensor mit Arduino verwendet.

### **2. Spezifikation**

- Betriebsspannung: +5V DC

- Ruhestrom: \<2mA

- Betriebsstrom: 15mA

- Effektiver Winkel: \<15°

- Entfernungsbereich: 2cm – 300 cm

- Genauigkeit: 0,3 cm

- Messwinkel: 30 Grad

- Trigger-Eingang Impulsbreite: 10µs

![](media/A111.png)

### **3. Komponenten**

| Entwicklungsboard *1      | 8833 Motor Driver *1      | Rotes LED Modul *1        | Ultraschallsensor *1      |
| ------------------------- | ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A112.jpg)    | ![img](media/A113.jpg)    | ![img](media/A114.jpg)    | ![img](media/A115.jpg)    |
| 4P Dupont Kabel *1        | USB Kabel *1              | 3P Dupont Kabel *1        |                           |
| ![img](media/A116.jpg)    | ![img](media/A117.jpg)    | ![img](media/A118.jpg)    |                           |

### **4. Funktionsprinzip**

Wie auf dem obigen Bild gezeigt, ist es wie zwei Augen. Eines ist der Sendeteil, das andere der Empfangsteil.

Das Ultraschallmodul sendet nach Auslösen eines Signals Ultraschallwellen aus. Wenn die Ultraschallwellen auf ein Objekt treffen und reflektiert werden, gibt das Modul ein Echo-Signal aus, sodass es die Entfernung des Objekts anhand der Zeitdifferenz zwischen dem Trigger-Signal und dem Echo-Signal bestimmen kann.

t ist die Zeit, die das ausgesendete Signal benötigt, um auf ein Hindernis zu treffen und zurückzukehren. Die Ausbreitungsgeschwindigkeit des Schalls in der Luft beträgt etwa 343 m/s, und Entfernung = Geschwindigkeit \* Zeit. Da die Ultraschallwelle ausgesendet wird und zurückkommt, entspricht dies der doppelten Entfernung. Daher muss durch 2 geteilt werden, die vom Ultraschall gemessene Entfernung = (Geschwindigkeit \* Zeit)/2.

**Verwendungsmethode und Diagramm des Ultraschallmoduls:**

1). Verwenden Sie den GPIO-Pin, um ein High-Level-Signal von mindestens 10μs an den Trig-Pin des SR04 zu geben, um die Entfernungsmessung auszulösen.

2). Nach dem Auslösen sendet das Modul automatisch acht 40KHz Ultraschallimpulse aus und erkennt, ob ein Signal zurückkommt. Dieser Schritt wird automatisch vom Modul ausgeführt.

3). Wenn das Signal zurückkommt, gibt der Echo-Pin ein High-Level-Signal aus, dessen Dauer die Zeit vom Aussenden der Ultraschallwelle bis zum Empfang des Echos ist.

![image-20250509143833078](media/A119.png)


**Schaltplan des Ultraschallsensors:**

![](media/A120.jpeg)

### **5. Anschlussdiagramm**

![](media/A121.png)

VCC, Trig, Echo und Gnd des Ultraschallsensors sind mit 5V(V), D12, D13 und Gnd(G) verbunden.

### **6. Testcode**

Bevor der Code geschrieben wird, muss die Bibliotheksdatei des Ultraschallsensors importiert werden. Die konkreten Schritte sind wie folgt:

Klicken Sie auf ![](media/A29.png), um die Erweiterungsbibliothek-Schnittstelle für Sensoren/Module/Komponenten zu öffnen, suchen Sie dann nach dem "**Ultrasonic**" Sensor ![](media/A122.png) und klicken Sie darauf. Dadurch ändert sich "**Not loaded**" zu "**loaded**", was anzeigt, dass der "**Ultrasonic**" Sensor erfolgreich hinzugefügt wurde.

![Img](media/A123.png)

![](media/A124.png)

Klicken Sie auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Befehlblock des hinzugefügten "**Ultrasonic**" Sensors ist im Modulbereich sichtbar.

![](media/A125.png)

Sie können Blöcke ziehen, um zu programmieren. Die unten aufgeführten Blöcke dienen als Referenz.

(1). ![](media/A126.png)

(2). ![](media/A127.png)

(3). ![](media/A128.png)

(4). ![](media/A129.png)

(5). ![](media/A130.png)

(6).![](media/A131.png)

(7).![](media/A132.png)

**Vollständiger Testcode**

![](media/A133.png)

### **7. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0-Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan und schließen Sie dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten klicken Sie auf ![](media/A80.png), um die Baudrate auf 9600 einzustellen.

Die erkannte Entfernung wird angezeigt, und die Einheit ist cm und Zoll. Blockieren Sie den Ultraschallsensor mit der Hand, wird der angezeigte Entfernungswert kleiner.

![](media/A134.png)

### **8. Erweiterte Übung**

Wir haben gerade die vom Ultraschall angezeigte Entfernung gemessen. Wie wäre es, die LED mit der gemessenen Entfernung zu steuern? Versuchen wir es und schließen ein LED-Lichtmodul an den D9-Pin an.

![](media/A135.png)

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A136.png)

(3).![](media/A128.png)

(4).![](media/A137.png)

(5).![](media/A130.png)

(6).![](media/A138.png)

(7).![](media/A132.png)

**Vollständiger Testcode**

![](media/A139.png)

![](media/A140.png)

Nachdem der Code erfolgreich auf das V4.0-Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan und schließen Sie dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten blockieren Sie den Ultraschallsensor mit der Hand (die Entfernung liegt zwischen 2-10 cm) und prüfen Sie, ob die LED leuchtet.