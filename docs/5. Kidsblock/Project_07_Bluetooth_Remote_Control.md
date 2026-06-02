# Projekt 7 Bluetooth-Fernsteuerung

![](media/A161.png)

### **1. Beschreibung**

In diesem Kit befindet sich ein DX-BT24 5.1 Bluetooth-Modul. Dieses Bluetooth-Modul verfügt über 256Kb Speicherplatz und entspricht der Bluetooth-Spezifikation V5.1BLE, die AT-Befehle unterstützt. Benutzer können Parameter wie die Baudrate und den Gerätenamen des seriellen Ports nach Bedarf ändern.

Darüber hinaus unterstützt es die UART-Schnittstelle und die transparente Übertragung des Bluetooth-Seriellports, was auch die Vorteile von niedrigen Kosten, kleinem Format, geringem Stromverbrauch und hoher Empfindlichkeit beim Senden und Empfangen beinhaltet. Bemerkenswert ist, dass es nur wenige Peripheriekomponenten benötigt, um seine leistungsstarken Funktionen zu realisieren.

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

Das DX-BT24-Modul unterstützt auch das BT5.1 BLE-Protokoll, das direkt mit iOS-Geräten mit BLE-Bluetooth-Funktion verbunden werden kann und die Ausführung von Hintergrundprogrammen im Resident-Modus unterstützt. Es wird hauptsächlich im Bereich der drahtlosen Datenübertragung über kurze Entfernungen eingesetzt. Es ermöglicht die Vermeidung umständlicher Kabelverbindungen und kann serielle Kabel direkt ersetzen.

**Erfolgreiche Anwendungsbereiche der BT24-Module:**

※ Bluetooth-Datenübertragung ohne Kabel;

※ Peripheriegeräte für Mobiltelefone und Computer;

※ Handheld-POS-Geräte;

※ Drahtlose Datenübertragung von medizinischen Geräten;

※ Smart-Home-Steuerung;

※ Bluetooth-Drucker;

※ Bluetooth-Fernsteuerungsspielzeuge;

※ Fahrräder zum Teilen;

**Anschlüsse**

![](media/A162.png)

①STATE: Status-Pin

②RX: Empfangspin

③TX: Sendepin

④GND: Masse

⑤VCC: Stromversorgung

⑥EN: Enable-Pin

Verbinden Sie das BT-Modul mit dem Entwicklungsboard.

<table border="1">
<tbody>
<tr class="odd">
<td>Uno</td>
<td>BT24</td>
</tr>
<tr class="even">
<td>TX</td>
<td>RX</td>
</tr>
<tr class="odd">
<td>RX</td>
<td>TX</td>
</tr>
<tr class="even">
<td>VCC</td>
<td>5V</td>
</tr>
<tr class="odd">
<td>GND</td>
<td>GND</td>
</tr>
</tbody>
</table>
### **4. Komponenten**

| Entwicklungsboard *1       | 8833 Motor Driver *1       | Rotes LED-Modul *1          |
| -------------------------- | -------------------------- | --------------------------- |
| ![img](media/A163.jpg)     | ![img](media/A164.jpg)     | ![img](media/A165.jpg)      |
| 3P F-F Dupont-Kabel *1     | USB-Kabel *1               | DX-BT24 Bluetooth-Modul *1  |
| ![img](media/A166.jpg)     | ![img](media/A167.jpg)     | ![img](media/A168.jpg)      |

### **5. Schaltplan**

![](media/A169.png)

RXD, TXD, GND und VCC des BT-Moduls sind mit TX, RX, G und 5V verbunden.

STATE und BRK des BT-Moduls benötigen keine Verbindung.

<span style="color: rgb(255, 76, 65);">Hinweis:</span> Achten Sie auf die Einbaurichtung des BT-Moduls beim Einstecken auf das 8833-Board. Und stecken Sie es nicht ein, bevor der Code hochgeladen wurde.

### **6. Testcode**

Sie können Blöcke ziehen, um zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A172.png)

(5).![](media/A173.png)

**Vollständiger Testcode**

<span style="color: rgb(255, 76, 65);">**Hinweis:** Entfernen Sie vor dem Hochladen des Testcodes das Bluetooth-Modul, da sonst der Code nicht hochgeladen werden kann. Verbinden Sie das Bluetooth-Modul erst nach erfolgreichem Hochladen des Codes.</span>

![](media/A174.png)

### **7. Testergebnis**

Nach dem erfolgreichen Hochladen des Codes auf das V4.0-Board verbinden Sie die Verkabelung gemäß dem Schaltplan und schließen dann den Computer über ein USB-Kabel an, um das Board mit Strom zu versorgen. Nach dem Einschalten stecken Sie das BT-Modul ein und die LED blinkt, dann müssen wir die BT-App herunterladen.

### **8. Bluetooth-APP herunterladen**

**Apple-System**

(1). Öffnen Sie den App Store auf dem iPhone.

(2). Suche nach keyes BT car und lade die APP auf dein Handy herunter.

![](media/A175.png)
    

(3). Nach der Installation die Oberfläche öffnen.

![](media/A176.png)
    

(4). Klicke auf die Schaltfläche "**Connect**" oben links, um automatisch nach Bluetooth zu suchen. Wenn **BT24** gefunden wird, klicke auf "**Connect**", um Bluetooth zu verbinden, und dann auf ![](media/A177.png), um in die Steueroberfläche des 4WD Smart Cars zu gelangen.

![](media/A178.png)
    
**Android System**
    

(1). Öffne den Google Play Store und suche nach „**keyes 4wd**“.

![](media/A179.png)

(2). Das App-Symbol wird nach der Installation wie unten gezeigt angezeigt.

![](media/A180.png)

(3). Klicke auf die App, um die folgende Seite zu öffnen.

![](media/A181.png)

(4). Nach dem Verbinden mit Bluetooth Strom anschließen, und die LED-Anzeige des Bluetooth-Moduls blinkt. Tippe auf „Connect“, um nach Bluetooth zu suchen.

![](media/A182.jpeg)

(5). Wenn **BT24** gefunden wird, klicke auf "**connect**", um Bluetooth zu verbinden. Wenn "**connect**" zu "**is connected**" wechselt, zeigt dies an, dass die Bluetooth-Verbindung erfolgreich ist. Wie im Bild unten gezeigt, bleibt die Bluetooth-LED dauerhaft an.

![](media/A183.jpeg)

(6). Nach dem Verbinden mit dem Bluetooth-Modul klicke auf ![](media/A80.png), um die Baudrate auf 9600 einzustellen. Wenn die Taste der Bluetooth-APP gedrückt wird, werden die entsprechenden Zeichen angezeigt, wie unten dargestellt:

![](media/A184.png)

| Taste                                         | Funktion                          |
| --------------------------------------------- | -------------------------------- |
| ![wps14](media/A185.jpg)                       | Paaren des DX-BT24 5.1 Bluetooth-Moduls |
| ![wps15](media/A186.jpg)                       | Bluetooth trennen                |

|                                                              | Steuerzeichen                                            | Funktion                                                     |
| ------------------------------------------------------------ | -------------------------------------------------------- | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                                     | Drücken: F  <br />Loslassen: S                            | Taste drücken, das Auto fährt vorwärts; <br />loslassen zum Stoppen |
| ![wps17](media/A188.jpg)                                     | Drücken: L  <br />Loslassen: S                            | Taste drücken, das Auto fährt nach links; <br />loslassen zum Stoppen  |
| ![wps18](media/A189.jpg)                                     | Drücken: R  <br />Loslassen: S                            | Taste drücken, das Auto fährt nach rechts; <br />loslassen zum Stoppen |
| ![wps19](media/A190.jpg)                                     | Drücken: B  <br />Loslassen: S                            | Taste drücken, das Auto fährt rückwärts; <br />loslassen zum Stoppen   |
| ![wps20](media/A191.jpg)                                     | Drücken: „a“  <br />Loslassen: „S“                        | Klicken zum Beschleunigen (maximal: 255)                      |
| ![wps21](media/A192.jpg)                                     | Drücken: „d“  <br />Loslassen: „S“                        | Klicken zum Verlangsamen (minimal: 0)                         |
| ![wps22](media/A193.jpg)                                     | Klicken, um die Schwerkraft- <br />Sensorfunktion des <br />Handys zu starten: erneut klicken, um <br />die Steuerung zu beenden |                                                              |
| ![wps23](media/A194.jpg)                                     | Klicken, um „X“ zu senden, <br />erneut klicken, um „S“ zu senden | Linienverfolgungsfunktion starten; <br />erneut klicken zum Beenden |
| ![wps24](media/A195.jpg)                                     | Klicken, um „Y“ zu senden, <br />erneut klicken, um „S“ zu senden | Ultraschall-Vermeidungsfunktion starten; <br />erneut klicken zum Beenden |
| ![wps25](media/A196.jpg)                                     | Klicken, um „U“ zu senden, <br />erneut klicken, um „S“ zu senden | Ultraschall-Folgefunktion starten; <br />erneut klicken zum Beenden |
| ![wps26](media/A197.jpg)                                     | Klicken, um „G“ zu senden, <br />erneut klicken, um „S“ zu senden | Einschränkungsfunktion starten; <br />erneut klicken zum Beenden |

### **9. Erweiterte Übung**

Hier verwenden wir den vom Mobiltelefon gesendeten Befehl, um eine LED ein- oder auszuschalten. Im Schaltplan ist eine LED an den D9-Pin angeschlossen.

![](media/A198.png)

Sie können Blöcke ziehen, um sie zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A199.png)

(5).![](media/A173.png)

(6).![](media/A200.png)

(7).![](media/A201.png)

**Vollständiger Testcode**

![](media/A202.png)

Nachdem der Code erfolgreich auf das V4.0-Board hochgeladen wurde, verbinden Sie die Verkabelung gemäß dem Schaltplan und schließen Sie dann das Board über ein USB-Kabel an den Computer an, um es mit Strom zu versorgen. Nach dem Einschalten klicken Sie auf<td>![](media/A203.png)</td> und <td>![](media/A204.png)</td>, um die LED ein- und auszuschalten.