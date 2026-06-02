# Projekt 9 Gesichtsausdruck LED-Board

![](media/A221.png)

### **1. Beschreibung** 

Wie lustig ist es, wenn ein Ausdrucksboard zum Roboter hinzugefügt wird. Und das Keyestudio 8\*16 LED-Board kann das ermöglichen. Mit seiner Hilfe könnt ihr Gesichtsausdrücke, Bilder, Muster und andere Anzeigen selbst gestalten.

Das 8\*16 LED-Board verfügt über 128 LEDs. Die Daten des Mikroprozessors (Arduino) kommunizieren über eine Zwei-Draht-Busschnittstelle mit dem AiP1640. Dadurch kann es das Ein- und Ausschalten der 128 LEDs auf dem Modul steuern, um die Punktmatrix auf dem Modul so anzuzeigen, dass das gewünschte Muster dargestellt wird. Ein HX-2.54 4Pin-Kabel wird für eine bequeme Verkabelung mitgeliefert.

### **2. Spezifikation**

- Betriebsspannung: DC 3,3-5V

- Leistungsverlust: 400mW

- Oszillationsfrequenz: 450KHz

- Ansteuerstrom: 200mA

- Betriebstemperatur: -40\~80℃

- Kommunikationsmodus: I2C
  

### **3. Schaltplan**

![](media/A222.png)

### **4. Funktionsprinzip**

Wie steuert man jede LED der 8\*16 Punktmatrix? Es ist bekannt, dass jedes Byte 8 Bits hat und jedes Bit 0 oder 1 ist. Wenn es 0 ist, ist die LED aus, wenn es 1 ist, ist die LED an. Ein Byte kann eine Spalte der LEDs steuern, und natürlich können 16 Bytes 16 Spalten von LEDs steuern, das ist die 8\*16 Punktmatrix.

### **5. Pin-Beschreibung und Kommunikationsprotokoll**

Die Daten des Mikroprozessors (Arduino) kommunizieren über ein Zwei-Draht-Buskabel mit dem AiP1640.

Das Kommunikationsprotokoll-Diagramm ist wie folgt (SCLK) ist SCL, (DIN) ist SDA.

![](media/A223.png)

① Die Startbedingung für die Dateneingabe: SCL ist auf hohem Pegel und SDA wechselt von hoch zu niedrig.

② Für die Einstellung des Datenbefehls gibt es die im folgenden Bild gezeigten Methoden.

In unserem Beispielprogramm wählen wir die Methode, **automatisch 1 zur Adresse hinzuzufügen**, der Binärwert ist 0100 0000 und der entsprechende Hexadezimalwert ist 0x40.

![Img](media/A224.png)

③ Für die Einstellung des Adressbefehls kann die Adresse wie unten gezeigt ausgewählt werden.

Im Beispielprogramm wird die erste 00H ausgewählt, und die Binärzahl 1100 0000 entspricht dem Hexadezimalwert 0xc0.

![Img](media/A225.png)

④ Die Anforderung für die Dateneingabe ist, dass wenn SCL auf hohem Pegel ist, während Daten eingegeben werden, das Signal auf SDA unverändert bleiben muss. Nur wenn das Taktsignal auf SCL auf niedrigem Pegel ist, darf das Signal auf SDA geändert werden. Die Eingabe der Daten erfolgt zuerst mit dem niederwertigen Bit, dann mit dem höherwertigen Bit.

⑤ Die Bedingung für das Ende der Datenübertragung ist, dass wenn SCL auf niedrigem Pegel ist, SDA auf niedrigem Pegel und SCL auf hohem Pegel, der Pegel von SDA auf hoch wechselt.

⑥ Anzeige-Steuerung, unterschiedliche Pulsbreiten einstellen, die Pulsbreite kann wie im Bild unten ausgewählt werden.

Im Beispiel beträgt die Pulsbreite 4/16, und der Hexadezimalwert, der 1000 1010 entspricht, ist 0x8A.

![Img](media/A226.png)

**Anleitung zur Verwendung des Modulus-Tools**

Das Punktmatrix-Tool verwendet die Online-Version, und der Link ist: [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

① Gebt den Link ein und die Seite erscheint wie unten gezeigt

![](media/A227.png)

② Die Punktmatrix ist 8\*16, also stellt die Höhe auf 8 und die Breite auf 16 ein, wie im Bild unten gezeigt.

![](media/A228.png)

③ Hexadezimale Daten aus dem Muster generieren

Wie im Bild unten gezeigt, mit der linken Maustaste auswählen, mit Rechtsklick abwählen; zeichnet das gewünschte Muster, klickt auf Generate, und die benötigten hexadezimalen Daten werden generiert.

![](media/A229.png)

### **6. Komponenten**

| Entwicklungsboard *1       | 8833 Motor Driver *1            | 8x16 LED Panel*1          |
| ------------------------- | ------------------------------- | ------------------------- |
| ![img](media/A230.jpg) | ![img](media/A231.jpg)       | ![img](media/A232.jpg) |
| USB-Kabel*1               | HX-2.54 4P Dupont Kabel 200mm *1 |                           |
| ![img](media/A233.jpg) | ![img](media/A234.jpg)       |                           |



### **7. Verdrahtungsdiagramm**

![](media/A235.png)

Die GND-, VCC-, SDA- und SCL-Pins der 8x16 LED-Leuchtplatine sind jeweils mit der Keyestudio Sensor-Erweiterungsplatine verbunden – (GND), + (VCC), A4, A5 für die Zwei-Draht-Serielle Kommunikation.

(<span style="color: rgb(255, 76, 65);">Hinweis:</span> Obwohl sie mit dem IIC-Pin des Arduino verbunden ist, ist dieses Modul nicht für die IIC-Kommunikation gedacht. Und der IO-Port hier simuliert die I2C-Kommunikation und kann mit beliebigen zwei Pins verbunden werden).

### **8. Testcode**

Bevor der Code geschrieben wird, muss die Bibliotheksdatei der 8x16 LED-Platine importiert werden. Die konkreten Schritte sind wie folgt:

Klicke auf ![](media/A29.png), um die Erweiterungsbibliothek-Schnittstelle für Sensoren/Module/Komponenten zu öffnen, suche dann nach dem „**Matrix 8\*16 Aip1640**“-Modul ![](media/A236.png) und klicke darauf. Dadurch ändert sich „**Nicht geladen**“ zu „**geladen**“, was anzeigt, dass das „**Matrix 8\*16 Aip1640**“-Modul erfolgreich hinzugefügt wurde.

![Img](media/A237.png)

![](media/A238.png)

Klicke auf ![](media/A33.png), um zur Code-Editor-Oberfläche zurückzukehren. Der Anweisungsblock des hinzugefügten „**Matrix 8\*16 Aip1640**“-Moduls ist im Modulbereich sichtbar.

![](media/A239.png)

Du kannst Blöcke ziehen, um sie zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A240.png)

**Vollständiger Testcode**

![](media/A241.png)

### **9. Testergebnis**

Nachdem der Code erfolgreich auf die V4.0-Platine hochgeladen wurde, verbinde die Verkabelung gemäß dem Schaltplan, dann schalte den DIP-Schalter auf ON. Ein lächelndes Muster wird auf der LED-Platine angezeigt.

![](media/A242.png)

### **10. Code-Erklärung**

Wir verwenden das gerade gelernte Modultool, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), um auf der Punktmatrix das Startmuster, Vorwärtsgehen, Stoppen und anschließend das Löschen des Musters anzuzeigen. Das Zeitintervall beträgt 2000 ms.

![image-20250513092102687](media/A243.png)![image-20250513092107293](media/A244.png)![image-20250513092113035](media/A245.png)![image-20250513092116952](media/A246.png)


Anweisungsblock für das Smiley-Gesicht![](media/A247.png)

Anweisungsblock für den Ausdruck: ![](media/A248.png)

Anweisungsblock für Herz ![](media/A249.png)

Anweisungsblock für Vorwärtsgehen![](media/A250.png)

Anweisungsblock für **Rückwärtsgehen** ![](media/A251.png)

Anweisungsblock für **Linksabbiegen** ![](media/A252.png)

Anweisungsblock für **Rechtsabbiegen** ![](media/A253.png)

Anweisungsblock für **Stoppen**![](media/A254.png)

Anweisungsblock für **Bildschirm löschen**![](media/A255.png)

![](media/A235.png)

Du kannst Blöcke ziehen, um sie zu bearbeiten. Die unten aufgeführten Blöcke dienen als Referenz.

(1).![](media/A126.png)

(2).![](media/A240.png)

(3).![](media/A256.png)

**Vollständiger Testcode**

![](media/A257.png)

Nach dem Hochladen des Testcodes zeigt die Gesichtsausdrucksplatine diese Muster der Reihe nach an und wiederholt diese Sequenz.

![image-20250513092222972](media/A258.png)![image-20250513092233711](media/A259.png)![image-20250513092238552](media/A260.png)