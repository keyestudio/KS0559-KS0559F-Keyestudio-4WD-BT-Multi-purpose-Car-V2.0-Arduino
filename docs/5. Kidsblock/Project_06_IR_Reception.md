# Projekt 6 IR-Empfang

![](media/A141.png)

### **1. Beschreibung**

Es besteht kein Zweifel, dass Infrarot-Fernbedienungen im täglichen Leben allgegenwärtig sind. Sie werden zur Steuerung verschiedener Haushaltsgeräte verwendet, wie Fernseher, Stereoanlagen, Videorekorder und Satellitensignalempfänger. Die Infrarot-Fernbedienung besteht aus einem Infrarot-Sendesystem und einem Infrarot-Empfangssystem, das heißt einer Infrarot-Fernbedienung und einem Infrarot-Empfangsmodul sowie einem Mikrocontroller, der in der Lage ist, die Signale zu decodieren.

![](media/A142.png)

Das 38K-Infrarot-Trägersignal, das vom Fernbediener ausgesendet wird, wird vom Codierchip im Fernbediener kodiert. Es besteht aus einem Abschnitt Pilotcode, Benutzer-Code, Benutzer-Inverscode, Daten-Code und Daten-Inverscode. Das Zeitintervall des Pulses wird verwendet, um zu unterscheiden, ob es sich um ein 0- oder 1-Signal handelt, und die Kodierung besteht aus diesen 0- und 1-Signalen.

Der Benutzer-Code derselben Fernbedienung ist konstant, während der Daten-Code die Taste unterscheidet.

Wenn die Fernbedienungstaste gedrückt wird, sendet die Fernbedienung ein Infrarot-Trägersignal aus. Wenn der IR-Empfänger das Signal empfängt, dekodiert das Programm das Trägersignal und bestimmt, welche Taste gedrückt wurde. Der MCU dekodiert das empfangene 0-1-Signal und erkennt so, welche Taste der Fernbedienung gedrückt wurde.

Der von uns verwendete Infrarot-Empfänger ist ein Infrarot-Empfangsmodul. Es besteht hauptsächlich aus einem Infrarot-Empfängerkopf, einem Gerät, das Empfang, Verstärkung und Demodulation integriert. Sein interner IC hat die Demodulation abgeschlossen und kann vom Infrarot-Empfang bis zur Ausgabe arbeiten und ist TTL-kompatibel.

Außerdem ist es geeignet für Infrarot-Fernbedienungen und Infrarot-Datenübertragung. Das vom Empfänger hergestellte Infrarot-Empfangsmodul hat nur drei Pins: Signalleitung, VCC und GND. Es ist sehr bequem, mit Arduino und anderen Mikrocontrollern zu kommunizieren.

### **2. Spezifikation**

- Betriebsspannung: 3,3-5V (DC)

- Ausgangssignal: Digitalsignal

- Empfangswinkel: 90 Grad

- Frequenz: 38 kHz

- Empfangsreichweite: 10 m

Das Bild zeigt das reale Produkt und das Schaltbild des Infrarot-Empfängers.

![](media/A141.png)

![](media/A143.png)

### **3. Komponenten**

| Entwicklungsboard *1      | 8833 Motor Driver *1      | Rotes LED-Modul *1          |
| ------------------------- | ------------------------- | --------------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg)     | ![img](media/A44.jpg)       |
| 3P F-F Dupont-Kabel *1    | USB-Kabel *1              |                             |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg)     |                             |

Da das 8833-Board den IR-Empfänger integriert hat, ist keine Verkabelung erforderlich. Die Pins des IR-Empfängermoduls sind G (GND), V (VCC) und D3.

### **4. Testcode**

<span style="color: rgb(255, 76, 65);">Bitte beachten: Das im Software-Demonstrationsbild gezeigte Infrarotmodul ist bereits in die Erweiterungsplatine integriert und wird nicht separat geliefert. Folglich finden Sie das im Bild unten dargestellte Modul nicht im Produkt.![](media/A144.png)</span>

Bevor Sie den Code schreiben, muss die Bibliotheksdatei des IR-Empfängersensors importiert werden. Die konkreten Schritte sind wie folgt:

Klicken Sie auf ![](media/A29.png), um die Erweiterungsbibliothek für Sensoren/Module/Komponenten zu öffnen, suchen Sie dann nach dem „**ir remote**“-Sensor ![](media/A144.png) und klicken Sie darauf. Dadurch ändert sich „**Not loaded**“ zu „**loaded**“, was anzeigt, dass der „ir remote“-Sensor erfolgreich hinzugefügt wurde.

![Img](media/A145.png)

![](media/A146.png)

Klicken Sie auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Block mit den Befehlen des hinzugefügten „**ir remote**“-Sensors ist im Modulbereich sichtbar.

![](media/A147.png)

Sie können Blöcke ziehen, um zu programmieren. Die unten aufgeführten Blöcke dienen als Referenz.

(1). ![](media/A126.png)

(2). ![](media/A148.png)

(3). ![](media/A149.png)

(4). ![](media/A150.png)

**Vollständiger Testcode**

![](media/A151.png)

### **5. Testergebnis**

Nach dem erfolgreichen Hochladen des Codes auf das V4.0-Board verbinden Sie die Verkabelung gemäß dem Schaltplan, und schließen Sie dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten klicken Sie auf ![](media/A80.png), um die Baudrate auf 9600 einzustellen.

Nehmen Sie die Fernbedienung heraus und senden Sie ein Signal an den Infrarot-Empfängersensor. Sie können den Tastwert der entsprechenden Taste sehen. Wenn die Tastzeit zu lang ist, neigt FFFFFFFF zu fehlerhaften Zeichen.

![](media/A152.png)

Die Tastwerte der Fernbedienung sind unten dargestellt.

![](media/A153.jpeg)

### **6. Erweiterte Übung**

Wir haben den Tastwert der IR-Fernbedienung decodiert. Wie wäre es, die LED mit dem gemessenen Wert zu steuern? Wir könnten ein Experiment entwerfen.

Schließen Sie eine LED an D9 an, und drücken Sie dann die Tasten der Fernbedienung, um die LED ein- und auszuschalten.

![](media/A154.png)

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A155.png)

(4).![](media/A150.png)

(5).![](media/A156.png)

(6).![](media/A157.png)

(7).![](media/A158.png)

(8).![](media/A159.png)

**Vollständiger Testcode**

![](media/A160.png)

Nach dem erfolgreichen Hochladen des Codes auf das V4.0-Board verbinden Sie die Verkabelung gemäß dem Schaltplan, und schließen Sie dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten kann durch Drücken der "**OK**"-Taste auf der Fernbedienung die LED ein- und ausgeschaltet werden.