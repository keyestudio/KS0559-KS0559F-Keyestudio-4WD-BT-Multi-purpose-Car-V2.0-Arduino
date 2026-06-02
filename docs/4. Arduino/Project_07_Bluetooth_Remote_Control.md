# Projekt 7 Bluetooth-Fernsteuerung

### **1. Beschreibung**

![image-20250510083107283](media/A47.png)

In diesem Kit ist ein DX-BT24 5.1 Bluetooth-Modul enthalten. Dieses Bluetooth-Modul verfügt über 256Kb Speicherplatz und entspricht der V5.1BLE Bluetooth-Spezifikation, die AT-Befehle unterstützt. Benutzer können Parameter wie die Baudrate und den Gerätenamen des seriellen Ports nach Bedarf ändern.

Darüber hinaus unterstützt es die UART-Schnittstelle und die transparente Übertragung des Bluetooth-Seriellports, was auch die Vorteile von niedrigen Kosten, kleinem Formfaktor, geringem Stromverbrauch und hoher Empfindlichkeit beim Senden und Empfangen beinhaltet. Bemerkenswert ist, dass es nur wenige Peripheriekomponenten benötigt, um seine leistungsstarken Funktionen zu realisieren.  

### **2. Spezifikation**

- Bluetooth-Protokoll: Bluetooth-Spezifikation V5.1 BLE

- Arbeitsreichweite: In einer offenen Umgebung kann eine ultra-lange Distanzkommunikation von 40 m erreicht werden

- Betriebsfrequenz: 2,4 GHz ISM-Band

- Kommunikationsschnittstelle: UART

- Bluetooth-Zertifizierung: Entspricht den FCC CE ROHS REACH Zertifizierungsstandards

- Serielle Port-Parameter: 9600, 8 Datenbits, 1 Stoppbit, kein Paritätsbit, keine Flusskontrolle

- Stromversorgung: 5V DC

- Betriebstemperatur: –10℃ bis +65℃

### **3. Anwendung**

Das DX-BT24 Modul unterstützt auch das BT5.1 BLE-Protokoll, das direkt mit iOS-Geräten mit BLE-Bluetooth-Funktion verbunden werden kann und die Ausführung von Hintergrundprogrammen im Resident-Modus unterstützt. Es wird hauptsächlich im Bereich der drahtlosen Datenübertragung über kurze Distanzen eingesetzt. Es ermöglicht die Vermeidung umständlicher Kabelverbindungen und kann serielle Kabel direkt ersetzen.

**Erfolgreiche Anwendungsbereiche der BT24-Module:**

※ Bluetooth-Datenübertragung ohne Kabel;

※ Peripheriegeräte für Mobiltelefone und Computer;

※ Handheld-POS-Geräte;

※ Drahtlose Datenübertragung von medizinischen Geräten;

※ Smart-Home-Steuerung;

※ Bluetooth-Drucker;

※ Bluetooth-Fernsteuerungsspielzeug;

※ Fahrradverleihsysteme;

### **4. Anschlüsse**

![420af966-aaa4-4736-9d35-2a9ccc7215f3](media/A48.png)

①STATE：Status-Pin

②RX：Empfangspin

③TX：Sendepin

④GND：GND

⑤VCC：Stromversorgung

⑥EN： Enable-Pin

Verbinden Sie das BT-Modul mit dem Entwicklungsboard.

| Uno  | BT24 |
| :--: | :--: |
|  TX  |  RX  |
|  RX  |  TX  |
| VCC  |  5V  |
| GND  | GND  |

### **5. Komponenten**

|           Entwicklungsboard *1           |           8833 Motor Driver *1           |                       Rotes LED-Modul*1                       |
| :--------------------------------------: | :--------------------------------------: | :----------------------------------------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) |                   ![img](media/A10.jpg)                   |
|             3P Dupont-Kabel*1             |               USB-Kabel*1                |                  DX-BT24 Bluetooth-Modul*1                  |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         | ![image-20250510083534209](media/A49.png) |

### **6. Schaltplan**

![image-20250510083927915](media/A50.png)

RXD, TXD, GND und VCC des BT-Moduls sind mit TX, RX, G und 5V verbunden.

STATE und BRK des BT-Moduls benötigen keine Verbindung.

<span style="color: rgb(255, 76, 65);">Hinweis: Die Ausrichtung des BT-Moduls beim Einstecken auf das 8833-Board beachten. Und es nicht vor dem Hochladen des Codes einstecken.</span> 

### **7. Testcode**

<span style="color: rgb(255, 76, 65);">**Hinweis:** Vor dem Hochladen des Testcodes muss das Bluetooth-Modul entfernt werden, da sonst das Hochladen fehlschlägt. Verbinden Sie das Bluetooth-Modul erst nach erfolgreichem Hochladen des Codes.</span>

```c
//***********************************************************************
/*
keyestudio 4wd BT Car
lesson 7.1
Bluetooth 
http://www.keyestudio.com
*/
char ble_val; // Zeichenvariable, die den vom Bluetooth empfangenen Wert speichert 

void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0)  // sicherstellen, dass Daten im seriellen Puffer sind
  {
    ble_val = Serial.read();  // Daten aus dem seriellen Puffer lesen
    Serial.println(ble_val);  // Ausgeben
  }
}
//***********************************************************************
```

### **8. Testergebnis**

Nachdem der Code erfolgreich auf das V4.0 Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan, und schließen Sie dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten stecken Sie das BT-Modul ein und die LED blinkt, anschließend müssen wir die BT-App herunterladen.

### **9. Bluetooth APP herunterladen**

**Apple-System**

(1). Öffnen Sie den App Store auf dem iPhone.

(2). Suchen Sie nach keyes BT car und laden Sie die APP auf Ihr Telefon herunter.

![image-20250510084716811](media/A51.png)
    
(3). Nach der Installation öffnen Sie die App.

![image-20250510084812821](media/A52.png)
    
(4). Klicken Sie auf die Schaltfläche "**Connect**" oben links, um automatisch nach Bluetooth zu suchen. Wenn **BT24** gefunden wird, klicken Sie auf "**Connect**", um Bluetooth zu verbinden, und klicken Sie dann auf ![image-20250510084833837](media/A53.png), um die Steueroberfläche des 4WD Smart Cars zu öffnen.

![image-20250510084902641](media/A54.png)

**Android-System**

(1). Öffnen Sie den Google Play Store und suchen Sie nach „keyes 4wd“.

![image-20250510084916086](media/A55.png)

(2). Das App-Symbol wird nach der Installation wie unten gezeigt angezeigt.

![image-20250510084933465](media/A56.png)

(3). Klicken Sie auf die App, um die folgende Seite zu öffnen.

![image-20250510084946146](media/A57.png)

(4). Nach dem Verbinden von Bluetooth stecken Sie die Stromversorgung ein und die LED-Anzeige des Bluetooth-Moduls blinkt. Tippen Sie auf „**Connect**“, um nach Bluetooth zu suchen.

![image-20250510085007028](media/A58.png)

(5). Wenn **BT24** gefunden wird, klicken Sie auf "Connect", um Bluetooth zu verbinden. Wenn "**Connect**" zu "**is Connected**" wechselt, bedeutet dies, dass die Bluetooth-Verbindung erfolgreich ist. Wie im Bild unten gezeigt, bleibt die Bluetooth-LED dauerhaft an.

![image-20250510085026219](media/A59.png)

(6). Nach dem Verbinden des Bluetooth-Moduls öffnen Sie den seriellen Monitor und stellen die Baudrate auf 9600 ein. Drücken Sie die Taste in der Bluetooth-APP, und die entsprechenden Zeichen werden angezeigt, wie unten dargestellt:

![image-20250510085039562](media/A60.png)

| Taste                     | Funktion                          |
| ------------------------- | --------------------------------- |
| ![img](media/A61.jpg) | DX-BT24 5.1 Bluetooth-Modul koppeln |
| ![img](media/A62.jpg)   | Bluetooth trennen                 |

|                           | Steuerzeichen                                              | Steuerzeichen                                              |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Drücken: F  <br />Loslassen: S                              | Taste drücken, das Auto fährt vorwärts; <br />loslassen zum Stoppen |
| ![img](media/A64.jpg) | Drücken: L  <br />Loslassen: S                              | Taste drücken, das Auto dreht nach links; <br />loslassen zum Stoppen  |
| ![img](media/A65.jpg) | Drücken: R  <br />Loslassen: S                              | Taste drücken, das Auto dreht nach rechts; <br />loslassen zum Stoppen |
| ![img](media/A66.jpg) | Drücken: B  <br />Loslassen: S                              | Taste drücken, das Auto fährt rückwärts; <br />loslassen zum Stoppen   |
| ![img](media/A67.jpg) | Drücken: „a“  <br />Loslassen: „S“                          | Klicken zum Beschleunigen (maximal: 255)                     |
| ![img](media/A68.jpg) | Drücken: „d“  <br />Loslassen: „S“                          | Klicken zum Verlangsamen (minimal: 0)                        |
| ![img](media/A69.jpg) | Klicken, um die Schwerkraft- <br />Sensorfunktion des <br />Handys zu starten: erneut klicken, <br />um die Schwerkraftsteuerung zu beenden |                                                              |
| ![img](media/A70.jpg) | Klicken, um „X“ zu senden, <br />erneut klicken, um „S“ zu senden | Linienverfolgungsfunktion starten; <br />erneut klicken zum Beenden |
| ![img](media/A71.jpg) | Klicken, um „Y“ zu senden, <br />erneut klicken, um „S“ zu senden | Ultraschall-Hindernisvermeidung starten; <br />erneut klicken zum Beenden |
| ![img](media/A72.jpg) | Klicken, um „U“ zu senden, <br />erneut klicken, um „S“ zu senden | Ultraschall-Folgen starten; <br />erneut klicken zum Beenden    |
| ![img](media/A73.jpg) | Klicken, um „G“ zu senden, <br />erneut klicken, um „S“ zu senden | Einschränkungsfunktion starten; <br />erneut klicken zum Beenden |

### **10. Code-Erklärung**

**Serial.available()** : Gibt die Anzahl der aktuell im seriellen Puffer verbleibenden Zeichen zurück. Im Allgemeinen wird diese Funktion verwendet, um zu prüfen, ob Daten im Puffer des seriellen Ports vorhanden sind. Wenn Serial.available() > 0 ist, bedeutet dies, dass der serielle Port Daten empfangen hat und gelesen werden können;

**Serial.read() :** Bezieht sich darauf, ein Byte Daten aus dem seriellen Puffer zu entnehmen und zu lesen. Zum Beispiel, wenn ein Gerät Daten über den seriellen Port an Arduino sendet, können wir Serial.read() verwenden, um die gesendeten Daten zu lesen.

### **11. Erweiterte Übung**

Hier wollen wir den vom Handy gesendeten Befehl verwenden, um eine LED ein- oder auszuschalten. Im Schaltplan ist eine LED an den Pin D9 angeschlossen.

![image-20250510085856954](media/A74.png)

```c
//****************************************************************************
/*
 keyestudio smart turtle robot
 lesson 7.2
 Bluetooth LED
 http://www.keyestudio.com
*/ 
int ledpin=9;
char ble_val;// Eine Ganzzahlvariable, die den über Bluetooth empfangenen Wert speichert

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop()
{ 
  if (Serial.available() > 0) // Prüfen, ob Daten im seriellen Puffer vorhanden sind
  {
    ble_val = Serial.read();  // Daten aus dem seriellen Puffer lesen
    Serial.print("DATA RECEIVED:");
    Serial.println(ble_val);
    if (ble_val == 'F') {
      digitalWrite(ledpin, HIGH);
      Serial.println("led on");
    }
    if (ble_val == 'B') {
      digitalWrite(ledpin, LOW);
      Serial.println("led off");
    }
   }
}
//****************************************************************************
```

Nach dem erfolgreichen Hochladen des Codes auf das V4.0-Board verbinden Sie die Verkabelung gemäß dem Schaltplan, und schließen Sie dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten klicken Sie auf ![image-20250510085919039](media/A75.png) und ![image-20250510085931709](media/A76.png), um die LED ein- und auszuschalten.