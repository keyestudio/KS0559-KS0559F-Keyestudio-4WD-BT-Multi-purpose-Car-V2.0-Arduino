# Progetto 16 Controllo Velocità Auto Intelligente Bluetooth

![](media/A327.jpeg)

### **1.Descrizione**

In questo progetto, utilizzeremo un modulo Bluetooth per regolare la velocità dell'auto intelligente. Consentiamo di definire velocità variabili e modificarle per cambiare la velocità dell'auto intelligente.

### **2.Diagramma di Flusso**

![image-20250513095810478](media/A340.png)

### **3.Diagramma di Collegamento**

![](media/A329.png)

1). GND, VCC, SDA e SCL della scheda LED 8\*8 sono collegati rispettivamente a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). RXD, TXD, GND e VCC del modulo Bluetooth sono collegati rispettivamente a TX, RX, G e 5V sulla scheda di espansione driver motore 8833, mentre i pin STATE e BRK del modulo Bluetooth non devono essere collegati.

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso è collegato a 5V (V) e il filo arancione è collegato ad A3.

4). L'alimentazione è collegata alla porta BAT.

### **4.Codice di Test**

Prima di scrivere il codice, è necessario importare i file di libreria della scheda LED 8x16 e del servo. I passaggi specifici sono i seguenti:

Clicca ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, quindi cerca il modulo “Matrix 8\*16 Aip1640” ![](media/A236.png) e cliccaci sopra. In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il modulo “**Matrix 8\*16 Aip1640**” è stato aggiunto con successo.

![Img](media/A237.png)

![](media/A238.png)

Clicca ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, si possono vedere i blocchi di istruzioni del modulo “**Matrix 8\*16 Aip1640**” e del componente “**Servo**” nell'area moduli.

![](media/A330.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

(10).![](media/A341.png)

**Codice di Test Completo**

<span style="color: rgb(255, 76, 65);">**Nota:** Prima di caricare il codice di test, è necessario rimuovere il modulo Bluetooth, altrimenti il caricamento del codice fallirà. Collega il modulo Bluetooth dopo aver caricato con successo il codice.</span>

![](media/A342.png)

![](media/A343.png)

![](media/A344.png)

![](media/A345.png)

![](media/A346.png)

![](media/A346.png)

### **5.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo il diagramma di collegamento, alimenta con la fonte esterna e poi porta l'interruttore DIP su ON. Associa l'APP con il Bluetooth, l'auto intelligente potrà essere controllata tramite l'APP.

Premi ![](media/A347.png), l'auto accelererà, premi ![](media/A348.png), l'auto rallenterà, e la scheda LED 8\*16 mostrerà il corrispondente schema di stato dell'auto intelligente.