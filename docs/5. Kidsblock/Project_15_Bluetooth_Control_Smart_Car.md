# Projekt 15 Bluetooth-gesteuertes Smart Car

![](media/A327.jpeg)

### **1. Beschreibung**

Wir haben die Grundlagen von Bluetooth gelernt. In dieser Lektion werden wir ein Bluetooth-gesteuertes Smart Car bauen. In diesem Projekt betrachten wir das Mobiltelefon als Sender (Host) und das Smart Car, das mit dem BT24 Bluetooth-Modul (Slave) verbunden ist, als Empfänger. Die Steuerung des Smart Cars erfolgt über die mobile APP via Bluetooth.

### **2. APP-Steuertasten**

| Taste                                         | Funktion                          |
| --------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Koppeln des DX-BT24 5.1 Bluetooth-Moduls |
| ![wps15](media/A186.jpg) | Bluetooth trennen              |

|                                                              | Steuerzeichen                                            | Funktion                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Drücken: F  <br />Loslassen: S                                   | Taste drücken, das Auto fährt vorwärts; <br />loslassen zum Stoppen |
| ![wps17](media/A188.jpg)                 | Drücken: L  <br />Loslassen: S                                   | Taste drücken, das Auto dreht nach links; <br />loslassen zum Stoppen  |
| ![wps18](media/A189.jpg)                 | Drücken: R  <br />Loslassen: S                                   | Taste drücken, das Auto dreht nach rechts; <br />loslassen zum Stoppen |
| ![wps19](media/A190.jpg)                 | Drücken: B  <br />Loslassen: S                                   | Taste drücken, das Auto fährt rückwärts; <br />loslassen zum Stoppen   |
| ![wps20](media/A191.jpg)                 | Drücken: „a“  <br />Loslassen: „S“                               | Klicken zum Beschleunigen (maximal: 255)                               |
| ![wps21](media/A192.jpg)                 | Drücken: „d“  <br />Loslassen: „S“                               | Klicken zum Verlangsamen (minimal: 0)                                |
| ![wps22](media/A193.jpg)                 | Klicken zum Starten der Schwerkraft- <br />Sensorfunktion des <br />Mobiltelefons: erneut klicken zum <br />Beenden der Schwerkraftsteuerung |                                                              |
| ![wps23](media/A194.jpg)                 | Klicken zum Senden von „X“,<br /> erneut klicken zum Senden von „S“               | Linienverfolgungsfunktion starten; <br />erneut klicken zum Beenden      |
| ![wps24](media/A195.jpg)                 | Klicken zum Senden von „Y“, <br />erneut klicken zum Senden von „S“               | Ultraschall-Hindernisvermeidung starten;<br /> erneut klicken zum Beenden |
| ![wps25](media/A196.jpg) | Klicken zum Senden von „U“, <br />erneut klicken zum Senden von „S“               | Ultraschall-Folgefunktion starten;<br /> erneut klicken zum Beenden |
| ![wps26](media/A197.jpg)                 | Klicken zum Senden von „G“,<br /> erneut klicken zum Senden von „S“                | Begrenzungsfunktion starten;<br /> erneut klicken zum Beenden       |

### **3. Flussdiagramm**

![img](media/A328.png)

### **4. Schaltplan**

![](media/A329.png)

1). GND, VCC, SDA und SCL der 8\*8 LED-Anzeige sind mit G (GND), V (VCC), A4 und A5 des Erweiterungsboards verbunden.
    
2). RXD, TXD, GND und VCC des Bluetooth-Moduls sind jeweils mit TX, RX, G und 5V auf dem 8833 Motor-Treiber-Erweiterungsboard verbunden, während die STATE- und BRK-Pins des Bluetooth-Moduls nicht angeschlossen werden müssen.
    
3). Der Servo ist mit G, V und A3 verbunden. Das braune Kabel ist mit Gnd (G), das rote Kabel mit 5V (V) und das orange Kabel mit A3 verbunden.
    
4). Die Stromversorgung ist mit dem BAT-Anschluss verbunden.
    

### **5. Testcode**

Bevor der Code geschrieben wird, ist es notwendig, die Bibliotheksdateien des 8x16 LED-Boards und des Servos zu importieren. Die konkreten Schritte sind wie folgt:

Klicken Sie auf ![](media/A29.png), um die Erweiterungsbibliothek-Schnittstelle für Sensoren/Module/Komponenten zu öffnen, suchen Sie dann nach dem „**Matrix 8\*16 Aip1640**“-Modul ![](media/A236.png) und klicken Sie darauf. Dadurch ändert sich „**Not loaded**“ zu „**loaded**“, was anzeigt, dass das „**Matrix 8\*16 Aip1640**“-Modul erfolgreich hinzugefügt wurde.

![Img](media/A237.png)![](media/A238.png)

Klicken Sie auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Anweisungsblock des hinzugefügten „**Matrix 8\*16 Aip1640**“-Moduls und der „**Servo**“-Komponente ist im Modulbereich sichtbar.

![](media/A330.png)

Sie können Blöcke ziehen, um sie zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

**Vollständiger Testcode**

<span style="color: rgb(255, 76, 65);">**Hinweis:** Vor dem Hochladen des Testcodes müssen Sie das Bluetooth-Modul entfernen, da sonst der Code nicht hochgeladen werden kann. Verbinden Sie das Bluetooth-Modul erst nach erfolgreichem Hochladen des Codes wieder.</span>

![](media/A335.png)

![](media/A336.png)

![](media/A337.png)

![](media/A338.png)

![](media/A339.png)

### **6. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0-Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, schalten Sie die externe Stromversorgung ein und stellen Sie den DIP-Schalter auf ON.

Setzen Sie das BT-Modul ein und öffnen Sie Ihr Handy, um die Bluetooth-Verbindung herzustellen und das Smart Car zu steuern. Das Auto wird vorwärts, rückwärts fahren, nach links und rechts abbiegen und anhalten. Außerdem zeigt das 8\*8 LED-Board die entsprechenden Muster an.