# Projekt 2: LED-Helligkeit anpassen

### **1. Beschreibung**

Im vorherigen Unterricht haben wir die LED ein- und ausgeschaltet und zum Blinken gebracht.

In diesem Projekt steuern wir die Helligkeit der LED über PWM, um einen Atemeffekt zu simulieren.

PWM ist ein Mittel, um den analogen Ausgang digital zu steuern. Die digitale Steuerung wird verwendet, um Rechteckwellen mit unterschiedlichen Tastverhältnissen zu erzeugen (ein Signal, das ständig zwischen hohen und niedrigen Pegeln wechselt), um den analogen Ausgang zu steuern. Im Allgemeinen liegen die Eingangsspannungen der Ports bei 0V und 5V.

Was ist, wenn 3V benötigt werden? Oder ein Umschalten zwischen 1V, 3V und 3,5V? Wir können nicht ständig Widerstände wechseln. Aus diesem Grund greifen wir auf PWM zurück.

![bbcfcb9ae56abb7e80ee587246fc4be9](media/A14.gif)

Für die Arduino-Digitalport-Spannungsausgabe gibt es nur LOW und HIGH, die den Spannungsausgängen von 0V und 5V entsprechen. Man kann LOW als 0 und HIGH als 1 definieren und den Arduino innerhalb von 1s fünfhundert 0- oder 1-Signale ausgeben lassen.

Wenn alle fünfhundert Ausgaben 1 sind, entspricht das 5V; wenn alle 0 sind, entspricht das 0V. Wenn auf diese Weise 010101010101 ausgegeben wird, beträgt die Ausgangsspannung 2,5V, was einem Film ähnelt. Der Film, den wir sehen, ist nicht vollständig kontinuierlich. Tatsächlich werden 25 Bilder pro Sekunde ausgegeben. In diesem Fall kann der Mensch es nicht sehen, ebenso wenig wie PWM. Wenn wir eine andere Spannung wollen, müssen wir das Verhältnis von 0 und 1 steuern. Je mehr 0- und 1-Signale pro Zeiteinheit ausgegeben werden, desto genauer die Steuerung.

PWM ist eine Technologie, die digitale Methoden verwendet, um analoge Größen zu erhalten. Die digitale Steuerung ermöglicht die Bildung einer Rechteckwelle, das Rechteckwellensignal hat nur zwei Zustände: an und aus (hoch und niedrig). Eine Spannung von 0 bis 5V kann simuliert werden, indem das Verhältnis der Dauer von an zu aus gesteuert wird. Die Zeit, die an ist (technisch als High-Level bezeichnet), wird Pulsbreite genannt, daher wird PWM auch Pulsbreitenmodulation genannt.

Die grünen vertikalen Balken stellen eine Periode der Rechteckwelle dar. Der in jedem analogWrite(value) geschriebene Wert entspricht einem Prozentsatz, der auch als Tastverhältnis bezeichnet wird. Dieser Prozentsatz bezieht sich auf das Verhältnis der vom High-Level eingenommenen Zeit in einem Zyklus, also Tastverhältnis = High-Level-Zeit / Zykluszeit.

Im Bild ist von oben nach unten das Tastverhältnis der ersten Rechteckwelle 0%, und der entsprechende Wert ist 0, und die LED-Helligkeit ist am niedrigsten, also aus. Je länger der High-Level anhält, desto heller wird es. Daher ist der Wert des letzten Tastverhältnisses von 100% 255, und die LED ist am hellsten. 50% ist halb so hell, und 25% ist dunkler.

PWM wird hauptsächlich verwendet, um die Helligkeit von LED-Leuchten oder die Drehzahl von Motoren einzustellen, und die von den Motoren angetriebenen Raddrehzahlen können leicht gesteuert werden. Beim Spielen mit einigen Arduino-Robotern kommen die Vorteile von PWM besser zur Geltung.

### **2. Komponenten**

|           Entwicklungsboard *1           |           8833 Motor Driver *1           |     Rotes LED-Modul *1     |
| :--------------------------------------: | :--------------------------------------: | :------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             3P Dupont Kabel *1             |               USB-Kabel *1                |                            |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                            |

### **3. Schaltplan**

Die Verkabelung bleibt unverändert.

![image-20250508161123490](media/A13.png)

### **4. Testcode**

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.1
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Definiere den LED-Pin an D9
int value;

void setup () {
  pinMode (ledPin, OUTPUT); // initialisiere ledPin als Ausgang.
}
void loop () {
  for (value = 0; value <255; value = value + 1) 
  {
    analogWrite (ledPin, value); // LED leuchtet allmählich auf
    delay (5); // Verzögerung 5ms
  }
  for (value = 255; value> 0; value = value-1) 
  {
    analogWrite (ledPin, value); // LED geht allmählich aus
    delay (5); // Verzögerung 5ms
  }
}
//*****************************************************************
```

### **5. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan und verwenden Sie ein USB-Kabel, um den Computer mit Strom für das Board zu versorgen. Nach dem Einschalten sehen Sie, dass die LED allmählich von hell zu dunkel wechselt, ähnlich wie der menschliche Atem, anstatt sofort ein- und auszuschalten.

### **6. Code-Erklärung**

Wenn wir eine bestimmte Anweisung wiederholen müssen, können wir die for-Anweisung verwenden.

Das Format der for-Anweisung ist wie folgt dargestellt:

![image-20250508162458776](media/A15.png)

FOR-Zyklusfolge:

Runde 1：1 → 2 → 3 → 4

Runde 2：2 → 3 → 4

…

Bis die Zahl 2 nicht mehr erfüllt ist, ist die „for“-Schleife beendet.

Nachdem wir diese Reihenfolge kennen, kehren wir zum Code zurück:

**for (int value = 0; value < 255; value=value+1)**

**for (int value = 255; value > 0; value=value-1)**

Die beiden „for“-Anweisungen lassen value von 0 auf 255 steigen, dann von 255 auf 0 sinken und dann wieder auf 255 steigen... eine unendliche Schleife.

Im Folgenden gibt es eine neue Funktion ----- analogWrite().

Wir wissen, dass der digitale Port nur zwei Zustände hat: 0 und 1. Wie kann man also einen analogen Wert an einen digitalen Wert senden? Hier wird diese Funktion benötigt. Schauen wir uns das Arduino-Board an und finden 6 Pins mit der Markierung „~“, die PWM-Signale ausgeben können.

Funktionsformat wie folgt:

**analogWrite(pin,value)**

analogWrite() wird verwendet, um einen analogen Wert von 0~255 für PWM-Ports zu schreiben, daher liegt der Wert im Bereich von 0~255. Beachten Sie, dass Sie nur die digitalen Pins mit PWM-Funktion beschreiben können, wie z.B. Pin 3, 5, 6, 9, 10, 11.

PWM ist eine Technologie, um analoge Größen durch digitale Methoden zu erhalten. Die digitale Steuerung bildet eine Rechteckwelle, und das Rechteckwellensignal hat nur zwei Zustände: Ein und Aus (also High- oder Low-Pegel). Durch Steuerung des Verhältnisses der Ein- und Aus-Zeit kann eine Spannung simuliert werden, die von 0 bis 5V variiert. Die Einschaltzeit (fachlich als High-Pegel bezeichnet) wird Pulsbreite genannt, daher wird PWM auch Pulsweitenmodulation genannt.

Anhand der folgenden fünf Rechteckwellen lernen wir mehr über PWM.

![image-20250508162529349](media/A16.png)

In der obigen Abbildung stellt die grüne Linie eine Periode dar, und der Wert von analogWrite() entspricht einem Prozentsatz, der auch Duty Cycle genannt wird. Der Duty Cycle gibt das Verhältnis der Zeit an, die der High-Pegel im Zyklus einnimmt. Von oben nach unten beträgt der Duty Cycle der ersten Rechteckwelle 0% und der entsprechende Wert ist 0.

Die LED-Helligkeit ist am niedrigsten, also aus. Je länger der High-Pegel anhält, desto heller leuchtet die LED. Daher beträgt der letzte Duty Cycle 100%, was 255 entspricht, und die LED ist am hellsten. 50% ist halb so hell, 25% bedeutet dunkler.

PWM wird hauptsächlich verwendet, um die Helligkeit von LEDs oder die Drehzahl von Motoren einzustellen.

Es spielt eine wichtige Rolle bei der Steuerung von intelligenten Roboterautos. Ich glaube, Sie können es kaum erwarten, das nächste Projekt zu lernen.

### **7. Erweiterte Übung**

Ändern wir den Wert der Verzögerung und lassen den Pin unverändert, und beobachten, wie sich die LED verändert.

### **8. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan und verwenden Sie ein USB-Kabel, um den Computer mit Strom für das Board zu versorgen. Nach dem Einschalten sehen Sie, dass die LED allmählich von hell zu dunkel wechselt, ähnlich wie der menschliche Atem, anstatt sofort ein- und auszuschalten.

### **9. Code-Erklärung**

Wenn wir eine bestimmte Anweisung wiederholen müssen, können wir die for-Anweisung verwenden.

Das Format der for-Anweisung ist wie folgt dargestellt:

![image-20250508162458776](media/A15.png)

FOR-Zyklusfolge:

Runde 1：1 → 2 → 3 → 4

Runde 2：2 → 3 → 4

…

Bis die Zahl 2 nicht mehr erfüllt ist, ist die „for“-Schleife beendet.

Nachdem wir diese Reihenfolge kennen, kehren wir zum Code zurück:

**for (int value = 0; value < 255; value=value+1)**

**for (int value = 255; value > 0; value=value-1)**

Die beiden „for“-Anweisungen lassen value von 0 auf 255 steigen, dann von 255 auf 0 sinken und dann wieder auf 255 steigen... eine unendliche Schleife.

Im Folgenden gibt es eine neue Funktion ----- analogWrite().

Wir wissen, dass der digitale Port nur zwei Zustände hat: 0 und 1. Wie kann man also einen analogen Wert an einen digitalen Wert senden? Hier wird diese Funktion benötigt. Schauen wir uns das Arduino-Board an und finden 6 Pins mit der Markierung „~“, die PWM-Signale ausgeben können.

Funktionsformat wie folgt:

**analogWrite(pin,value)**

analogWrite() wird verwendet, um einen analogen Wert von 0~255 für PWM-Ports zu schreiben, daher liegt der Wert im Bereich von 0~255. Beachten Sie, dass Sie nur die digitalen Pins mit PWM-Funktion beschreiben können, wie z.B. Pin 3, 5, 6, 9, 10, 11.

PWM ist eine Technologie, um analoge Größen durch digitale Methoden zu erhalten. Die digitale Steuerung bildet eine Rechteckwelle, und das Rechteckwellensignal hat nur zwei Zustände: Ein und Aus (also High- oder Low-Pegel). Durch Steuerung des Verhältnisses der Ein- und Aus-Zeit kann eine Spannung simuliert werden, die von 0 bis 5V variiert. Die Einschaltzeit (fachlich als High-Pegel bezeichnet) wird Pulsbreite genannt, daher wird PWM auch Pulsweitenmodulation genannt.

Anhand der folgenden fünf Rechteckwellen lernen wir mehr über PWM.

![image-20250508162529349](media/A16.png)

In der obigen Abbildung stellt die grüne Linie eine Periode dar, und der Wert von analogWrite() entspricht einem Prozentsatz, der auch Duty Cycle genannt wird. Der Duty Cycle gibt das Verhältnis der Zeit an, die der High-Pegel im Zyklus einnimmt. Von oben nach unten beträgt der Duty Cycle der ersten Rechteckwelle 0% und der entsprechende Wert ist 0.

Die LED-Helligkeit ist am niedrigsten, also aus. Je länger der High-Pegel anhält, desto heller leuchtet die LED. Daher beträgt der letzte Duty Cycle 100%, was 255 entspricht, und die LED ist am hellsten. 50% ist halb so hell, 25% bedeutet dunkler.

PWM wird hauptsächlich verwendet, um die Helligkeit von LEDs oder die Drehzahl von Motoren einzustellen.

Es spielt eine wichtige Rolle bei der Steuerung von intelligenten Roboterautos. Ich glaube, Sie können es kaum erwarten, das nächste Projekt zu lernen.

### **10. Erweiterte Übung**

Ändern wir den Wert der Verzögerung und lassen den Pin unverändert, und beobachten, wie sich die LED verändert.

```c
//***********************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.2
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Definiere den LED-Pin an D9
void setup () {
   pinMode(ledPin, OUTPUT); // initialisiere ledPin als Ausgang.
}

void loop () {
   for (int value = 0; value <255; value = value + 1) {
     analogWrite (ledPin, value); // LED leuchtet allmählich auf
     delay (30); // Verzögerung 30ms
   }
   for (int value = 255; value> 0; value = value-1) {
     analogWrite (ledPin, value); // LED geht allmählich aus
     delay (30); // Verzögerung 30ms
   }
}
//***********************************************************
```

Laden Sie den Code auf das Entwicklungsboard hoch, dann blinkt die LED langsamer.