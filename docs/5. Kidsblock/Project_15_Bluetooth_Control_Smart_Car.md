# Project 15 Bluetooth Control Smart Car

![](media/A327.jpeg)

### **1.Descrizione**

Abbiamo appreso le conoscenze di base del Bluetooth. In questa lezione, realizzeremo un'auto intelligente controllata via Bluetooth. In questo progetto, consideriamo il telefono cellulare come trasmettitore (host) e l'auto intelligente collegata al modulo Bluetooth BT24 (slave) come ricevitore, utilizzando l'app mobile per controllare l'auto tramite Bluetooth.

### **2.Pulsanti di Controllo APP**

| Tasto                                         | Funzione                          |
| --------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Associa modulo Bluetooth DX-BT24 5.1 |
| ![wps15](media/A186.jpg) | Disconnetti Bluetooth              |

|                                                              | Carattere di controllo                                            | Funzione                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Premuto: F  <br />Rilasciato: S                                   | Premi il pulsante, l'auto va avanti; <br />rilascia per fermare |
| ![wps17](media/A188.jpg)                 | Premuto: L  <br />Rilasciato: S                                   | Premi il pulsante, l'auto gira a sinistra; <br />rilascia per fermare  |
| ![wps18](media/A189.jpg)                 | Premuto: R  <br />Rilasciato: S                                   | Premi il pulsante, l'auto gira a destra; <br />rilascia per fermare |
| ![wps19](media/A190.jpg)                 | Premuto: B  <br />Rilasciato: S                                   | Premi il pulsante, l'auto va indietro; <br />rilascia per fermare   |
| ![wps20](media/A191.jpg)                 | Premuto: “a”  <br />Rilasciato: “S”                               | Clicca per accelerare (massimo:255)                               |
| ![wps21](media/A192.jpg)                 | Premuto: “d”  <br />Rilasciato: “S”                               | Clicca per rallentare (minimo:0)                                |
| ![wps22](media/A193.jpg)                 | Clicca per avviare la funzione di <br />rilevamento della gravità del <br />telefono: clicca di nuovo per <br />uscire dal controllo di gravità |                                                              |
| ![wps23](media/A194.jpg)                 | Clicca per inviare “X”,<br /> clicca di nuovo per inviare “S”               | Avvia la funzione di tracciamento linea; <br />clicca di nuovo per uscire      |
| ![wps24](media/A195.jpg)                 | Clicca per inviare “Y”, <br />clicca di nuovo per inviare “S”               | Avvia la funzione di evitamento ad ultrasuoni;<br /> clicca di nuovo per uscire |
| ![wps25](media/A196.jpg) | Clicca per inviare “U”, <br />clicca di nuovo per inviare “S”               | Avvia la funzione di inseguimento ad ultrasuoni;<br /> clicca di nuovo per uscire |
| ![wps26](media/A197.jpg)                 | Clicca per inviare “G”,<br />clicca di nuovo per inviare “S”                | Avvia la funzione di restrizione;<br /> clicca di nuovo per uscire       |

### **3.Diagramma di Flusso**

![img](media/A328.png)

### **4.Diagramma di Collegamento**

![](media/A329.png)

1). GND, VCC, SDA e SCL della scheda LED 8\*8 sono collegati rispettivamente a G (GND), V (VCC), A4 e A5 della scheda di espansione.
    
2). RXD, TXD, GND e VCC del modulo Bluetooth sono collegati rispettivamente a TX, RX, G e 5V sulla scheda di espansione driver motore 8833, mentre i pin STATE e BRK del modulo Bluetooth non devono essere collegati.
    
3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso a 5V (V) e il filo arancione a A3.
    
4). L'alimentazione è collegata alla porta BAT
    

### **5.Codice di Test**

Prima di scrivere il codice, è necessario importare i file della libreria della scheda LED 8x16 e del servo. I passaggi specifici sono i seguenti: 
    
Clicca su ![](media/A29.png) per entrare nell'interfaccia della libreria di estensioni di sensori/moduli/componenti, quindi cerca il modulo “**Matrix 8\*16 Aip1640**” ![](media/A236.png) e cliccaci sopra. In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il modulo “**Matrix 8\*16 Aip1640**” è stato aggiunto con successo. 

![Img](media/A237.png)  

![](media/A238.png)

Clicca su ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, si possono vedere i blocchi di istruzioni del modulo “**Matrix 8\*16 Aip1640**” aggiunto e del componente “**Servo**” nell'area modulo. 

![](media/A330.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

**Codice di Test Completo**

<span style="color: rgb(255, 76, 65);">**Nota:** Prima di caricare il codice di test, è necessario rimuovere il modulo Bluetooth, altrimenti il codice non verrà caricato correttamente. Collega il modulo Bluetooth dopo aver caricato con successo il codice.</span>

![](media/A335.png)

![](media/A336.png)

![](media/A337.png)

![](media/A338.png)

![](media/A339.png)

### **6. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, accendi l'alimentazione esterna e poi porta l'interruttore DIP su ON.

Inserisci il modulo BT e apri il cellulare per connetterti al Bluetooth per controllare l'auto intelligente. L'auto si muoverà avanti, indietro, girerà a sinistra e a destra e si fermerà. Inoltre, la scheda LED 8\*8 mostrerà i pattern corrispondenti.