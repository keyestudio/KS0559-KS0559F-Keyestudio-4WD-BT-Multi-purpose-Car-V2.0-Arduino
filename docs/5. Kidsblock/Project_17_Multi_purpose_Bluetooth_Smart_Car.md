# Progetto 17 Auto Smart Bluetooth Multiuso

![](media/A349.jpeg)

### **1.Descrizione**

Nei progetti precedenti, l'auto eseguiva solo una singola funzione. Tuttavia, in questa lezione, integreremo tutte le sue funzioni tramite Bluetooth.

### **2.Diagramma di Flusso**

![](media/A350.png)

### **3.Diagramma di Collegamento**

![](media/A351.png)

1). GND, VCC, SDA e SCL della scheda LED 8\*8 sono collegati a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). RXD, TXD, GND e VCC del modulo Bluetooth sono rispettivamente collegati a TX, RX, G e 5V sulla scheda di espansione driver motore 8833, mentre i pin STATE e BRK del modulo Bluetooth non devono essere collegati.

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso è collegato a 5V (V) e il filo arancione è collegato ad A3.

4). G, V, S1, S2 e S3 del sensore di tracciamento linea sono collegati a G (GND), V (VCC), D11, D7 e D8 della scheda di espansione sensori.

5). VCC, Trig, Echo e Gnd del sensore ad ultrasuoni sono collegati a 5V (V), D12 (S), D13 (S) e Gnd (G).

6). L'alimentazione è collegata alla porta BAT.

### **4.Codice di Test**

Prima di scrivere il codice, è necessario importare i file della libreria del sensore ad ultrasuoni, della scheda LED 8x16 e del servo. I passaggi specifici sono i seguenti:

Cliccare ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, quindi cercare il sensore “**Ultrasonic**” ![](media/A122.png) e cliccarlo. In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il sensore “**Ultrasonic**” è stato aggiunto con successo.

![Img](media/A300.png)

![](media/A124.png)

Cliccare ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, si possono vedere i blocchi di istruzioni del sensore “**Ultrasonic**”, del modulo “**Matrix 8\*16 Aip1640**” e del componente “**Servo**” nell'area moduli.

![](media/A285.png)

**Codice di Test Completo**

<span style="color: rgb(255, 76, 65);">**Nota:** Prima di caricare il codice di test, è necessario rimuovere il modulo Bluetooth, altrimenti il caricamento del codice fallirà. Collegare il modulo Bluetooth dopo aver caricato con successo il codice.</span>

![](media/A352.png)

### **5.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo il diagramma di collegamento, alimentare l'alimentazione esterna e quindi impostare l'interruttore DIP su ON.

Dopo che il modulo Bluetooth è stato collegato all'APP e l'APP mobile si è connessa con successo al Bluetooth, l'auto smart può essere controllata tramite l'APP mobile. Possiamo ottenere le funzioni corrispondenti premendo i pulsanti corrispondenti sull'APP mobile.