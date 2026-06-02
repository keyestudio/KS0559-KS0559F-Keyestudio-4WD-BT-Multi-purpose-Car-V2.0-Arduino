# Projekt 1: LED Blink

### **1. Beschreibung**

![image-20250508161034535](media/A6.png)

Für Anfänger und Enthusiasten ist LED Blink ein grundlegendes Programm. LED, die Abkürzung für Light Emitting Diodes, besteht aus chemischen Verbindungen wie Ga, As, P, N usw.

Die LED kann durch Ändern der Verzögerungszeit im Testcode in verschiedenen Farben blinken. Bei Steuerung und Anschluss an GND und VCC leuchtet die LED, wenn der S-Anschluss auf High-Pegel ist, andernfalls erlischt sie.

### **2. Spezifikation**

- Steuerinterface: digitaler Port

- Betriebsspannung: DC 3,3-5V

- Pin-Abstand: 2,54 mm

- LED-Anzeigefarbe: rot

![image-20250508161015086](media/A7.png)

### **3. Komponenten**

|           Entwicklungsboard *1           |           8833 Motor Driver *1           |     Rotes LED Modul *1     |
| :--------------------------------------: | :--------------------------------------: | :------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             3P Dupont Kabel *1             |               USB-Kabel *1                |                            |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                            |

### **4. Schaltplan**

![image-20250508161123490](media/A13.png)

Wie aus der obigen Abbildung ersichtlich ist, ist das Keyestudio 8833 Motor Shield auf das Keyestudio 4.0 Entwicklungsboard aufgesteckt.

Die Pins G, V und S des LED-Moduls sind jeweils mit G, 5V und D9 des Erweiterungsboards verbunden.

### **5. Testcode**

```c 
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 1.1
Blink
http://www.keyestudio.com
*/
void setup()
{ 
  pinMode(9, OUTPUT);// initialisiert digitalen Pin 9 als Ausgang.
}
    
void loop() // die loop-Funktion läuft endlos immer wieder
{  
  digitalWrite(9, HIGH); // schaltet die LED ein (HIGH ist die Spannungsebene)
   delay(1000); // wartet eine Sekunde
   digitalWrite(9, LOW); // schaltet die LED aus, indem die Spannung auf LOW gesetzt wird
   delay(1000); // wartet eine Sekunde
}
//****************************************************************************
```

### **6. Testergebnis**

Nach erfolgreichem Hochladen des Codes auf das V4.0 Board, verbinden Sie die Kabel gemäß dem Schaltplan und verwenden Sie ein USB-Kabel, um den Computer mit Strom zu versorgen. Nach dem Einschalten sehen Sie, dass die an D9 angeschlossene LED an- und ausgeht.

### **7. Code-Erklärung**

pinMode(9，OUTPUT) - Diese Funktion legt fest, ob der Pin als INPUT oder OUTPUT verwendet wird.

digitalWrite(9，HIGH) - Wenn der Pin als OUTPUT definiert ist, kann er auf HIGH (5V ausgeben) oder LOW (0V ausgeben) gesetzt werden.

### **8. Erweiterte Übung**

Wir haben es geschafft, die LED blinken zu lassen. Als Nächstes beobachten wir, was passiert, wenn wir die Verzögerungszeit ändern.

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 1.2
 delay
 http://www.keyestudio.com
*/
void setup()
{  
  // initialisiert digitalen Pin 9 als Ausgang.
  pinMode(9, OUTPUT);
}
// die loop-Funktion läuft endlos immer wieder
void loop()
{ 
  digitalWrite(9, HIGH); // schaltet die LED ein (HIGH ist die Spannungsebene)
  delay(100); // wartet 0,1 Sekunden
  digitalWrite(9, LOW); // schaltet die LED aus, indem die Spannung auf LOW gesetzt wird
  delay(100); // wartet 0,1 Sekunden
}
//*****************************************************************
```

Das Testergebnis zeigt, dass die LED schneller blinkt. Daher beeinflusst die Verzögerungszeit die Blinkfrequenz der LED.