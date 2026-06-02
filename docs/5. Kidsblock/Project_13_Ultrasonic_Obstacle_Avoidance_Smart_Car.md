# Progetto 13 Auto Intelligente con Evitamento Ostacoli a Ultrasuoni

![](media/A296.png)

### **1.Descrizione**

In questo progetto, miriamo a realizzare un'auto intelligente con evitamento ostacoli a ultrasuoni. Utilizzeremo l'ultrasuono per rilevare la distanza dall'ostacolo, che può essere usata per controllare il servo per ruotare e far muovere l'auto. Nel frattempo, la scheda LED 8X16 mostrerà il corrispondente schema di stato.

### **2.Diagramma di Flusso**

![img](media/A297.png)

**La logica specifica dell'auto intelligente con evitamento ostacoli a ultrasuoni è mostrata di seguito:**

![Img](media/A298.png)

![Img](media/A299.png)

### **3.Diagramma di Collegamento**

![](media/A282.png)

1). GND, VCC, SDA e SCL del modulo scheda LED 8\*8 sono collegati a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). VCC, Trig, Echo e Gnd del sensore a ultrasuoni sono collegati a 5V (V), D12 (S), D13 (S) e Gnd (G).

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso è collegato a 5V (V) e il filo arancione è collegato ad A3.

4). L'alimentazione è collegata alla porta BAT.

### **4.Codice di Test**

Prima di scrivere il codice, è necessario importare i file di libreria del sensore a ultrasuoni, della scheda LED 8x16 e del servo. I passaggi specifici sono i seguenti:

Clicca ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, poi cerca il sensore “Ultrasonic” ![](media/A122.png) e cliccaci sopra. In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il sensore “**Ultrasonic**” è stato aggiunto con successo.

![Img](media/A300.png)

![](/media/A284.png)

Clicca ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, si possono vedere i blocchi di istruzioni del sensore “**Ultrasonic**”, del modulo “**Matrix 8\*16 Aip1640**” e del componente “**Servo**” nell'area moduli.

![](media/A285.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A301.png)

(3).![](media/A302.png)

(4).![](media/A287.png)

(5).![](media/A288.png)

(6).![](media/A268.png)

(7).![](media/A289.png)

(8).![](media/A292.png)

(9).![](media/A290.png)

(10).![](media/A291.png)

**Codice di Test Completo**

![](media/A303.png)

![](media/A304.png)

![](media/A305.png)

![](media/A306.png)

### **5.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo il diagramma di collegamento, accendi l'alimentazione esterna e poi porta l'interruttore DIP su ON.

L'auto intelligente si muove in avanti ed evita automaticamente gli ostacoli. Quando non c'è strada davanti, il servo guiderà il sensore a ultrasuoni a scansionare le distanze a sinistra, al centro e a destra, e l'auto girerà verso il lato aperto. Nel frattempo, la scheda LED 8X16 mostrerà il corrispondente schema di stato.