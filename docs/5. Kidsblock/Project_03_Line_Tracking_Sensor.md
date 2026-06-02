# Projekt 3: Linienverfolgungssensor

![](media/A63.png)

### **1. Beschreibung**

Der Verfolgungssensor ist tatsächlich ein Infrarotsensor. Die hier verwendete Komponente ist die TCRT5000 Infrarot-Röhre. Ihr Arbeitsprinzip besteht darin, die unterschiedliche Reflexionsfähigkeit von Infrarotlicht auf Farben zu nutzen und dann die Stärke des reflektierten Signals in ein Stromsignal umzuwandeln.

Während des Erkennungsprozesses ist Schwarz auf HIGH-Pegel aktiv, während Weiß auf LOW-Pegel aktiv ist. Die Erkennungshöhe beträgt 0-3 cm.

Das Keyestudio 3-Kanal Linienverfolgungsmodul hat 3 Sätze TCRT5000 Infrarot-Röhren auf einer Platine integriert, was die Verkabelung und Steuerung bequemer macht.

Durch Drehen des einstellbaren Potentiometers am Sensor kann die Erkennungsempfindlichkeit des Sensors angepasst werden.

### **2. Spezifikation**

- Betriebsspannung: 3,3-5V (DC)

- Schnittstelle: 5PIN

- Ausgangssignal: Digitalsignal

- Erkennungshöhe: 0-3 cm

![](media/A64.jpeg)

<span style="color: rgb(255, 76, 65);">Hinweis:</span> Vor dem Testen drehen Sie das Potentiometer am Sensor, um die Erkennungsempfindlichkeit einzustellen. Die Empfindlichkeit ist am besten, wenn die LED an einer Schwelle zwischen EIN und AUS eingestellt wird.

### **3. Komponenten**

| Entwicklungsboard *1     | 8833 Motor Driver *1     | Rotes LED-Modul *1       | Linienverfolgungssensor *1 |
| ------------------------ | ------------------------ | ------------------------ | -------------------------- |
| ![img](media/A65.jpg)    | ![img](media/A66.jpg)    | ![img](media/A67.jpg)    | ![img](media/A68.png)      |
| 5P Dupont-Kabel *1       | USB-Kabel *1             | 3P Dupont-Kabel *1       |                            |
| ![img](media/A69.png)    | ![img](media/A70.jpg)    | ![img](media/A71.jpg)    |                            |

### **4. Schaltplan**

![](media/A72.png)

G, V, S1, S2 und S3 des Linienverfolgungssensors sind mit G (GND), V (VCC), D11, D7 und D8 des Sensor-Erweiterungsboards verbunden.

### **5. Testcode**

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A75.png)

(4).![](media/A76.png)

(5).![](media/A77.png)

**Vollständiger Testcode**

![](media/A78.png)

![](media/A79.png)

### **6. Testergebnis**

Nach dem erfolgreichen Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan und verwenden ein USB-Kabel, um das Board mit dem Computer zu verbinden und mit Strom zu versorgen.

Nach dem Einschalten klicken Sie auf ![](media/A80.png), um die Baudrate auf 9600 einzustellen, und Sie sehen den Status der drei Linienverfolgungssensoren. Wenn keine Signale empfangen werden, ist der Wert 1. Wenn wir den Sensor mit einem weißen Papier abdecken, wird der Wert 0.

![](media/A81.png)

![](media/A82.png)

### **7. Erweiterte Übung**

Nachdem Sie das Funktionsprinzip kennen, können Sie eine LED an D9 anschließen, um die LED darüber zu steuern.

![](media/A83.png)

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A84.png)

(4).![](media/A85.png)

(5).![](media/A77.png)

(6).![](media/A86.png)

(7).![](media/A87.png)

**Vollständiger Testcode**

![](media/A88.png)

![](media/A89.png)

Nach dem erfolgreichen Hochladen des Codes auf das V4.0 Board verbinden Sie die Verkabelung gemäß dem Schaltplan und verwenden ein USB-Kabel, um das Board mit dem Computer zu verbinden und mit Strom zu versorgen.

Nach dem Einschalten halten Sie ein Papier nahe an den Sensor, dann sehen Sie, dass die LED aufleuchtet, wenn der Linienverfolgungssensor abgedeckt wird.