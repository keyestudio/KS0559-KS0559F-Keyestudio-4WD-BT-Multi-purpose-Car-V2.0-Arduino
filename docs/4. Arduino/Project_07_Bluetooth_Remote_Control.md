# Progetto 7 Controllo Remoto Bluetooth

### **1.Descrizione**

![image-20250510083107283](media/A47.png)

In questo kit è presente un modulo Bluetooth DX-BT24 5.1. Questo modulo bluetooth dispone di uno spazio di 256Kb e rispetta la specifica Bluetooth V5.1BLE, che supporta i comandi AT. Gli utenti possono modificare parametri come la velocità di trasmissione (baud rate) e il nome del dispositivo della porta seriale secondo necessità.

Inoltre, supporta l'interfaccia UART e la trasmissione trasparente della porta seriale bluetooth, che include anche i vantaggi di basso costo, dimensioni ridotte, basso consumo energetico e alta sensibilità per l'invio e la ricezione. Notevolmente, necessita solo di pochi componenti periferici per realizzare le sue potenti funzioni.

### **2.Specifiche**

- Protocollo Bluetooth: Bluetooth Specification V5.1 BLE

- Distanza di lavoro: In ambiente aperto, può raggiungere una comunicazione a ultra lunga distanza di 40m

- Frequenza operativa: banda ISM a 2.4GHz

- Interfaccia di comunicazione: UART

- Certificazione Bluetooth: Conforme agli standard di certificazione FCC CE ROHS REACH

- Parametri porta seriale: 9600, 8 bit dati, 1 bit di stop, bit di parità disabilitato, nessun controllo di flusso

- Alimentazione: 5V DC

- Temperatura di esercizio: –10℃ a +65℃

### **3.Applicazione**

Il modulo DX-BT24 supporta anche il protocollo BT5.1 BLE, che può essere collegato direttamente a dispositivi iOS con funzione Bluetooth BLE, e supporta l'esecuzione residente di programmi in background. È principalmente utilizzato nel campo della trasmissione wireless di dati a breve distanza. Permette di evitare collegamenti via cavo ingombranti e può sostituire direttamente i cavi seriali.

**Aree di applicazione di successo dei moduli BT24:**

※ Trasmissione dati wireless Bluetooth;

※ Periferiche per telefoni cellulari e computer;

※ Dispositivi POS portatili;

※ Trasmissione dati wireless di apparecchiature mediche;

※ Controllo domotico intelligente;

※ Stampanti Bluetooth;

※ Giocattoli telecomandati Bluetooth;

※ Biciclette condivise;

### **4.Porte**

![420af966-aaa4-4736-9d35-2a9ccc7215f3](media/A48.png)

①STATE：Pin di stato

②RX：Pin di ricezione

③TX：Pin di trasmissione

④GND：GND

⑤VCC：Alimentazione

⑥EN：Pin di abilitazione

Collegare il modulo BT alla scheda di sviluppo.

| Uno  | BT24 |
| :--: | :--: |
|  TX  |  RX  |
|  RX  |  TX  |
| VCC  |  5V  |
| GND  | GND  |

### **5.Componenti**

|           Scheda di sviluppo *1           |           Driver motore 8833 *1           |                       Modulo LED Rosso *1                       |
| :--------------------------------------: | :--------------------------------------: | :-------------------------------------------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) |                   ![img](media/A10.jpg)                   |
|             Cavo Dupont 3P *1             |               Cavo USB *1                |                  Modulo Bluetooth DX-BT24 *1                  |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         | ![image-20250510083534209](media/A49.png) |

### **6.Diagramma di collegamento**

![image-20250510083927915](media/A50.png)

RXD, TXD, GND e VCC del modulo BT sono collegati rispettivamente a TX, RX, G e 5V.

STATE e BRK del modulo BT non necessitano di collegamento.

<span style="color: rgb(255, 76, 65);">Nota: la direzione del modulo BT quando viene inserito sulla scheda 8833. E non inserirlo prima di caricare il codice.</span> 

### **7.Codice di test**

<span style="color: rgb(255, 76, 65);">**Nota:** Prima di caricare il codice di test, è necessario rimuovere il modulo Bluetooth, altrimenti il caricamento del codice fallirà. Collegare il modulo Bluetooth dopo aver caricato correttamente il codice.</span>

```c
//***********************************************************************
/*
keyestudio 4wd BT Car
lesson 7.1
Bluetooth 
http://www.keyestudio.com
*/
char ble_val; //variabile carattere, usata per memorizzare il valore ricevuto dal Bluetooth 

```cpp
void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0)  // assicurarsi che ci siano dati nel buffer seriale
  {
    ble_val = Serial.read();  // Leggi i dati dal buffer seriale
    Serial.println(ble_val);  // Stampa
  }
}
//***********************************************************************
```

### **8. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico, quindi collegare il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, inserire il modulo BT e il LED lampeggerà, quindi è necessario scaricare l'app BT.

### **9. Scarica l'APP Bluetooth**

**Sistema Apple**

(1). Aprire l'App Store sull'iPhone.

(2). Cercare keyes BT car e scaricare l'APP sul telefono.

![image-20250510084716811](media/A51.png)
    
(3). Dopo l'installazione, entrare nella sua interfaccia.

![image-20250510084812821](media/A52.png)
    
(4). Cliccare il pulsante "**Connect**" nell'angolo in alto a sinistra per cercare automaticamente il Bluetooth. Quando viene trovato **BT24**, cliccare "**Connect**" per connettere il Bluetooth, quindi cliccare ![image-20250510084833837](media/A53.png) per entrare nell'interfaccia di controllo dell'auto smart 4WD.

![image-20250510084902641](media/A54.png)

**Sistema Android**

(1). Entrare nel Google Play Store e cercare “keyes 4wd”.

![image-20250510084916086](media/A55.png)

(2). L'icona dell'app appare come mostrato dopo l'installazione.

![image-20250510084933465](media/A56.png)

(3). Cliccare sull'app per entrare nella pagina seguente.

![image-20250510084946146](media/A57.png)

(4). Dopo aver connesso il Bluetooth, collegare l'alimentazione e l'indicatore LED del modulo Bluetooth lampeggerà. Toccare “**Connect**” per cercare il Bluetooth.

![image-20250510085007028](media/A58.png)

(5). Quando viene trovato **BT24**, cliccare "Connect" per connettere il Bluetooth. Quando "**Connect**" diventa "**is Connected**", significa che la connessione Bluetooth è avvenuta con successo. Come mostrato nell'immagine sottostante, il LED Bluetooth rimane acceso.

![image-20250510085026219](media/A59.png)

(6). Dopo aver connesso il modulo Bluetooth, aprire il monitor seriale e impostare la velocità di trasmissione a 9600 baud. Premendo il pulsante dell'APP Bluetooth, verranno visualizzati i caratteri corrispondenti, come mostrato di seguito:

![image-20250510085039562](media/A60.png)

| Tasto                     | Funzione                          |
| ------------------------- | --------------------------------- |
| ![img](./media/A61.jpg)   | Associa modulo Bluetooth DX-BT24 5.1 |
| ![img](./media/A62.jpg)   | Disconnetti Bluetooth              |

|                           | Carattere di controllo                                      | Carattere di controllo                                      |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Premere: F  <br />Rilasciare: S                             | Premere il pulsante, l'auto va avanti; <br />rilasciare per fermarsi |
| ![img](media/A64.jpg) | Premere: L  <br />Rilasciare: S                             | Premere il pulsante, l'auto gira a sinistra; <br />rilasciare per fermarsi  |
| ![img](media/A65.jpg) | Premere: R  <br />Rilasciare: S                             | Premere il pulsante, l'auto gira a destra; <br />rilasciare per fermarsi |
| ![img](media/A66.jpg) | Premere: B  <br />Rilasciare: S                             | Premere il pulsante, l'auto va indietro; <br />rilasciare per fermarsi   |
| ![img](media/A67.jpg) | Premere: “a”  <br />Rilasciare: “S”                         | Clicca per accelerare (massimo:255)                          |
| ![img](media/A68.jpg) | Premere: “d”  <br />Rilasciare: “S”                         | Clicca per rallentare (minimo:0)                             |
| ![img](media/A69.jpg) | Clicca per avviare la funzione di <br />rilevamento della gravità del <br />telefono cellulare: clicca di nuovo per <br />uscire dal controllo di rilevamento della gravità |                                                              |
| ![img](media/A70.jpg) | Clicca per inviare “X”, <br />clicca di nuovo per inviare “S” | Avvia la funzione di tracciamento della linea; <br />clicca di nuovo per uscire      |
| ![img](media/A71.jpg) | Clicca per inviare “Y”, <br />clicca di nuovo per inviare “S” | Avvia la funzione di evitamento ad ultrasuoni; <br />clicca di nuovo per uscire |
| ![img](media/A72.jpg) | Clicca per inviare “U”, <br />clicca di nuovo per inviare “S” | Avvia la funzione di inseguimento ad ultrasuoni; <br />clicca di nuovo per uscire |
| ![img](media/A73.jpg) | Clicca per inviare “G”, <br />clicca di nuovo per inviare “S” | Avvia la funzione di restrizione; <br />clicca di nuovo per uscire       |

### **10. Spiegazione del Codice**

**Serial.available()** : Restituisce il numero di caratteri attualmente presenti nel buffer della porta seriale. Generalmente, questa funzione viene utilizzata per verificare se ci sono dati nel buffer della porta seriale. Quando Serial.available() > 0, significa che la porta seriale ha ricevuto dati e possono essere letti;

**Serial.read() :** Si riferisce all'estrazione e alla lettura di un Byte di dati dal buffer della porta seriale. Ad esempio, se un dispositivo invia dati ad Arduino tramite la porta seriale, possiamo usare Serial.read() per leggere i dati inviati.

### **11. Pratica Estesa**

Qui vediamo come utilizzare il comando inviato dal telefono cellulare per accendere o spegnere un LED. Guardando lo schema di collegamento, un LED è collegato al pin D9.

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
char ble_val;// Una variabile intera usata per memorizzare il valore ricevuto via Bluetooth

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop()
{ 
  if (Serial.available() > 0) //Controlla se ci sono dati nella cache della porta seriale
  {
    ble_val = Serial.read();  //Legge i dati dalla cache della porta seriale
    Serial.print("DATI RICEVUTI:");
    Serial.println(ble_val);
    if (ble_val == 'F') {
      digitalWrite(ledpin, HIGH);
      Serial.println("led acceso");
    }
    if (ble_val == 'B') {
      digitalWrite(ledpin, LOW);
      Serial.println("led spento");
    }
   }
}
//****************************************************************************
```

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi collega il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, clicca su ![image-20250510085919039](media/A75.png) e ![image-20250510085931709](media/A76.png) per controllare l'accensione e lo spegnimento del LED.