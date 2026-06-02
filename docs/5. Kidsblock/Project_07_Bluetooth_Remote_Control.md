# Progetto 7 Controllo Remoto Bluetooth

![](media/A161.png)

### **1.Descrizione**

In questo kit è presente un modulo Bluetooth DX-BT24 5.1. Questo modulo Bluetooth dispone di uno spazio di 256Kb e rispetta la specifica Bluetooth V5.1BLE, che supporta i comandi AT. Gli utenti possono modificare parametri come la velocità di trasmissione (baud rate) e il nome del dispositivo della porta seriale secondo necessità.

Inoltre, supporta l'interfaccia UART e la trasmissione trasparente della porta seriale Bluetooth, che include anche i vantaggi di basso costo, dimensioni ridotte, basso consumo energetico e alta sensibilità per l'invio e la ricezione. È importante notare che necessita solo di pochi componenti periferici per realizzare le sue potenti funzioni.

### **2.Specifiche**

- Protocollo Bluetooth: Specifica Bluetooth V5.1 BLE

- Distanza di lavoro: In ambiente aperto, può raggiungere comunicazioni ultra-lunghe fino a 40m
  
- Frequenza operativa: banda ISM 2.4GHz

- Interfaccia di comunicazione: UART

- Certificazione Bluetooth: Conforme agli standard di certificazione FCC CE ROHS REACH
  
- Parametri porta seriale: 9600, 8 bit dati, 1 bit di stop, bit di parità disabilitato, nessun controllo di flusso
  
- Alimentazione: 5V DC

- Temperatura operativa: –10℃ a +65℃
  

### **3.Applicazione**

Il modulo DX-BT24 supporta anche il protocollo BT5.1 BLE, che può essere collegato direttamente a dispositivi iOS con funzione Bluetooth BLE, e supporta l'esecuzione residente di programmi in background. È principalmente utilizzato nel campo della trasmissione wireless di dati a breve distanza. Permette di evitare collegamenti via cavo ingombranti e può sostituire direttamente i cavi seriali.

**Aree di applicazione di successo dei moduli BT24:**

※ Trasmissione dati wireless Bluetooth;

※ Periferiche per telefoni cellulari e computer;

※ Dispositivi POS portatili;

※ Trasmissione dati wireless per apparecchiature mediche;

※ Controllo domotico intelligente;

※ Stampanti Bluetooth;

※ Giocattoli telecomandati Bluetooth;

※ Biciclette condivise;

**Porte**

![](media/A162.png)

①STATE：Pin di stato

②RX：Pin di ricezione

③TX：Pin di trasmissione

④GND：GND

⑤VCC：Alimentazione

⑥EN：Pin di abilitazione

Collegare il modulo BT alla scheda di sviluppo.

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


### **4.Componenti**

| Scheda di Sviluppo *1      | Driver Motore 8833 *1      | Modulo LED Rosso*1           |
| ------------------------- | ------------------------- | -------------------------- |
| ![img](media/A163.jpg) | ![img](media/A164.jpg) | ![img](media/A165.jpg)  |
| Cavo Dupont 3P F-F*1      | Cavo USB*1               | Modulo Bluetooth DX-BT24*1 |
| ![img](media/A166.jpg) | ![img](media/A167.jpg) | ![img](media/A168.jpg)  |

### **5.Diagramma di Collegamento**

![](media/A169.png)

RXD, TXD, GND e VCC del modulo BT sono collegati rispettivamente a TX, RX, G e 5V.

STATE e BRK del modulo BT non necessitano di collegamento.

<span style="color: rgb(255, 76, 65);">Nota:</span> la direzione del modulo BT quando viene inserito sulla scheda 8833. Non inserirlo prima di caricare il codice.

### **6.Codice di Test**

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono a titolo di riferimento.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A172.png)

(5).![](media/A173.png)

**Codice di Test Completo**

<span style="color: rgb(255, 76, 65);">**Nota:** Prima di caricare il codice di test, è necessario rimuovere il modulo Bluetooth, altrimenti il caricamento del codice fallirà. Collegare il modulo Bluetooth dopo aver caricato correttamente il codice.</span>

![](media/A174.png)

### **7.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i fili secondo il diagramma di collegamento, quindi collegare il computer tramite cavo USB per alimentare la scheda. Dopo l'accensione, inserire il modulo BT e il LED lampeggerà, quindi è necessario scaricare l'app BT.

### **8.Scarica l’APP Bluetooth**

**Sistema Apple**

(1).Aprire l'App Store sull'iPhone.

(2). Cerca keyes BT car e scarica l'APP sul tuo telefono.

![](media/A175.png)
    

(3). Dopo l'installazione, entra nella sua interfaccia.

![](media/A176.png)
    

(4). Clicca il pulsante "**Connect**" nell'angolo in alto a sinistra per cercare automaticamente il Bluetooth. Quando viene trovato **BT24**, clicca su "**Connect**" per connettere il Bluetooth, quindi clicca ![](media/A177.png) per entrare nell'interfaccia di controllo della smart car 4WD. 

![](media/A178.png)
    
**Sistema Android**
    

(1). Entra nel Google Play Store e cerca “**keyes 4wd**”.

![](media/A179.png)

(2). L'icona dell'app appare come mostrato dopo l'installazione.

![](media/A180.png)

(3). Clicca sull'app per entrare nella pagina seguente.

![](media/A181.png)

(4). Dopo aver connesso il Bluetooth, collega l'alimentazione e il LED indicatore del modulo Bluetooth lampeggerà. Tocca “Connect” per cercare il Bluetooth.

![](media/A182.jpeg)

(5). Quando viene trovato **BT24**, clicca su "**connect**" per connettere il Bluetooth. Quando "**connect**" diventa "**is connected**", significa che la connessione Bluetooth è avvenuta con successo. Come mostrato nell'immagine sottostante, il LED Bluetooth rimarrà acceso.

![](media/A183.jpeg)

(6). Dopo aver connesso il modulo Bluetooth, clicca ![](media/A80.png) per impostare il baud rate a 9600. Premendo il pulsante dell'APP Bluetooth, verranno visualizzati i caratteri corrispondenti, come mostrato di seguito:

![](media/A184.png)

| Tasto                                        | Funzione                          |
| -------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Associa modulo Bluetooth DX-BT24 5.1 |
| ![wps15](media/A186.jpg) | Disconnetti Bluetooth              |

|                                                              | Carattere di controllo                                            | Funzione                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Premi: F  <br />Rilascia: S                                   | Premi il pulsante, la macchina va avanti; <br />rilascia per fermare |
| ![wps17](media/A188.jpg)                 | Premi: L  <br />Rilascia: S                                   | Premi il pulsante, la macchina gira a sinistra; <br />rilascia per fermare  |
| ![wps18](media/A189.jpg)                 | Premi: R  <br />Rilascia: S                                   | Premi il pulsante, la macchina gira a destra; <br />rilascia per fermare |
| ![wps19](media/A190.jpg)                 | Premi: B  <br />Rilascia: S                                   | Premi il pulsante, la macchina va indietro; <br />rilascia per fermare   |
| ![wps20](media/A191.jpg)                 | Premi: “a”  <br />Rilascia: “S”                               | Clicca per accelerare (massimo: 255)                               |
| ![wps21](media/A192.jpg)                 | Premi: “d”  <br />Rilascia: “S”                               | Clicca per rallentare (minimo: 0)                                |
| ![wps22](media/A193.jpg)                 | Clicca per avviare la funzione di <br />rilevamento della gravità del <br />telefono: clicca di nuovo per <br />uscire dal controllo di rilevamento gravità |                                                              |
| ![wps23](media/A194.jpg)                 | Clicca per inviare “X”,<br /> clicca di nuovo per inviare “S”               | Avvia funzione di tracciamento linea; <br />clicca di nuovo per uscire      |
| ![wps24](media/A195.jpg)                 | Clicca per inviare “Y”, <br />clicca di nuovo per inviare “S”               | Avvia funzione di evitamento ad ultrasuoni;<br /> clicca di nuovo per uscire |
| ![wps25](media/A196.jpg) | Clicca per inviare “U”, <br />clicca di nuovo per inviare “S”               | Avvia funzione di inseguimento ad ultrasuoni;<br /> clicca di nuovo per uscire |
| ![wps26](media/A197.jpg)                 | Clicca per inviare “G”,<br />clicca di nuovo per inviare “S”                | Avvia funzione di restrizione;<br /> clicca di nuovo per uscire       |

### **9. Pratica di Estensione**

Qui vediamo come utilizzare il comando inviato dal telefono cellulare per accendere o spegnere una luce LED. Osservando lo schema di collegamento, un LED è collegato al pin D9.

![](media/A198.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A199.png)

(5).![](media/A173.png)

(6).![](media/A200.png)

(7).![](media/A201.png)

**Codice di Test Completo**

![](media/A202.png)

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema, quindi collega il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, clicca <td>![](media/A203.png)</td> e <td>![](media/A204.png)</td> per controllare l'accensione e lo spegnimento del LED.