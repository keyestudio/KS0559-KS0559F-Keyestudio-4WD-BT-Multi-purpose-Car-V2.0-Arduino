# Projekt 2: LED-Helligkeit anpassen

### **1. Beschreibung**

Im vorherigen Unterricht haben wir die LED ein- und ausgeschaltet und zum Blinken gebracht.

In diesem Projekt steuern wir die Helligkeit der LED über PWM, um einen Atemeffekt zu simulieren.

PWM ist ein Verfahren zur Steuerung des analogen Ausgangs mittels digitaler Methoden. Die digitale Steuerung erzeugt Rechtecksignale mit unterschiedlichen Tastverhältnissen (ein Signal, das ständig zwischen hohen und niedrigen Pegeln wechselt), um den analogen Ausgang zu steuern. Im Allgemeinen liegen die Eingangsspannungen der Ports bei 0V und 5V.

Was ist, wenn 3V benötigt werden? Oder ein Umschalten zwischen 1V, 3V und 3,5V? Wir können nicht ständig Widerstände wechseln. Aus diesem Grund greifen wir auf PWM zurück.

![](media/A53.gif)

Für die Arduino-Digitalport-Spannungsausgabe gibt es nur LOW und HIGH, die den Spannungsausgängen von 0V bzw. 5V entsprechen. Man kann LOW als 0 und HIGH als 1 definieren und den Arduino innerhalb von 1 Sekunde fünfhundert 0- oder 1-Signale ausgeben lassen.

Wenn alle fünfhundert Ausgaben 1 sind, entspricht das 5V; wenn alle 0 sind, entspricht das 0V. Wenn man auf diese Weise 010101010101 ausgibt, beträgt die Ausgangsspannung 2,5V, was einem Film ähnelt. Der Film, den wir sehen, ist nicht vollständig kontinuierlich. Tatsächlich werden 25 Bilder pro Sekunde ausgegeben. In diesem Fall kann der Mensch es nicht sehen, ebenso wenig wie PWM. Wenn wir eine andere Spannung wollen, müssen wir das Verhältnis von 0 und 1 steuern. Je mehr 0- und 1-Signale pro Zeiteinheit ausgegeben werden, desto genauer die Steuerung.

PWM ist eine Technologie, die digitale Methoden verwendet, um analoge Größen zu erhalten. Digitale Steuerung ermöglicht die Bildung eines Rechtecksignals, das nur zwei Zustände hat (hoch und niedrig). Eine Spannung von 0 bis 5V kann simuliert werden, indem das Verhältnis der Ein- zur Aus-Zeit gesteuert wird. Die Zeit, in der das Signal eingeschaltet ist (technisch als High-Pegel bezeichnet), wird Pulsbreite genannt, daher wird PWM auch Pulsweitenmodulation genannt.

![](media/A54.png)

Die grünen vertikalen Balken stellen eine Periode des Rechtecksignals dar. Der in jedem analogWrite(value) geschriebene Wert entspricht einem Prozentsatz, der auch als Duty Cycle bezeichnet wird. Dieser Prozentsatz bezieht sich auf das Verhältnis der Zeit, die der High-Pegel in einem Zyklus einnimmt, also Duty Cycle = High-Pegel-Zeit / Zykluszeit.

Im Bild beträgt der Duty Cycle von oben nach unten beim ersten Rechtecksignal 0%, der entsprechende Wert ist 0, und die LED-Helligkeit ist am niedrigsten, also ausgeschaltet. Je länger der High-Pegel anhält, desto heller wird es. Daher ist der Wert des letzten Duty Cycles von 100% 255, und die LED ist am hellsten. 50% ist halb so hell, und 25% ist dunkler.

PWM wird hauptsächlich verwendet, um die Helligkeit von LEDs oder die Drehzahl von Motoren einzustellen, und die von den Motoren angetriebenen Raddrehzahlen können leicht gesteuert werden. Beim Spielen mit einigen Arduino-Robotern kommen die Vorteile von PWM besser zur Geltung.

### **2. Komponenten**

| Entwicklungsboard *1      | 8833 Motor Driver *1      | Rotes LED-Modul *1          |
| ------------------------- | ------------------------- | --------------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg)     | ![img](media/A44.jpg)       |
| 3P F-F Dupont Kabel *1    | USB-Kabel *1              |                             |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg)     |                             |

### **3. Schaltplan**

Die Verkabelung bleibt unverändert.

![](media/A47.png)

### **4. Testcode**

Du kannst Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A55.png)

(2).![](media/A56.png)

(3).![](media/A57.png)

(4).![](media/A58.png)

(5).![](media/A59.png)

(6).![](media/A60.png)

**Vollständiger Testcode**

![](media/A61.png)

### **5. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0-Board verbinde die Verkabelung gemäß dem Schaltplan und verbinde das Board mit einem USB-Kabel mit dem Computer, um es mit Strom zu versorgen. Nach dem Einschalten siehst du, dass die LED allmählich von hell zu dunkel wechselt, ähnlich wie beim menschlichen Atmen, und nicht sofort ein- und ausgeschaltet wird.

### **6. Erweiterte Übung**

Behalte die Pins der LED unverändert und ändere dann den Code (Werte hinter wait).

![](media/A62.png)

Laden Sie den Code auf das Entwicklungsboard hoch, dann blinkt die LED langsamer.