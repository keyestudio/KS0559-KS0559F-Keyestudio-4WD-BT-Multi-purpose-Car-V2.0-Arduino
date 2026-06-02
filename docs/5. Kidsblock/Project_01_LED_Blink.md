# Projekt 1 LED Blink

### **1. Beschreibung**

![](media/A40.jpeg)

Für Anfänger und Enthusiasten ist LED Blink ein grundlegendes Programm. LED, die Abkürzung für Light Emitting Diodes, besteht aus chemischen Verbindungen wie Ga, As, P, N und so weiter.

Die LED kann durch Ändern der Verzögerungszeit im Testcode in verschiedenen Farben blinken. Bei Steuerung und Anschluss an GND und VCC leuchtet die LED, wenn der S-Anschluss auf High-Pegel ist, andernfalls geht sie aus.

### **2. Spezifikation**

- Steuerinterface: digitaler Port

- Betriebsspannung: DC 3,3-5V

- Pin-Abstand: 2,54 mm

- LED-Anzeigefarbe: rot

![](media/A41.png)

### **3. Komponenten**

| Entwicklungsboard *1      | 8833 Motor Driver *1      | Rotes LED-Modul *1          |
| ------------------------- | ------------------------- | --------------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg)     | ![img](media/A44.jpg)       |
| 3P F-F Dupont Kabel *1    | USB-Kabel *1              |                             |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg)     |                             |

### **4. Schaltplan**

![](media/A47.png)

Wie aus der obigen Abbildung ersichtlich ist, ist das Keyestudio 8833 Motor Driver Erweiterungsboard auf das Keyestudio 4.0 Entwicklungsboard gesteckt.

Die Pins G, V und S des LED-Moduls sind jeweils mit G, 5V und D9 des Erweiterungsboards verbunden.

### **5. Testcode**

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A48.png)

(2).![](media/A49.png)

(3).![](media/A50.png)

**Vollständiger Testcode**

![](media/A51.png)

### **6. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board verbinden Sie die Kabel gemäß dem Schaltplan und verwenden ein USB-Kabel, um das Board mit dem Computer zu verbinden und mit Strom zu versorgen. Nach dem Einschalten sehen Sie, dass die an D9 angeschlossene LED ein- und ausgeschaltet wird.

### **7. Erweiterte Übung**

Als nächstes wollen wir die Frequenz des LED-Flackerns durch Ändern der Wartezeit verändern.

![](media/A52.png)

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board verbinden Sie die Kabel gemäß dem Schaltplan und verwenden ein USB-Kabel, um das Board mit dem Computer zu verbinden und mit Strom zu versorgen. Das Testergebnis zeigt, dass die LED schneller blinkt.