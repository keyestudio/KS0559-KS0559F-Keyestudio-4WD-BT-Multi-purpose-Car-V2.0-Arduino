# Progetto 9 Pannello LED con Espressione Facciale

![](media/A221.png)

### **1. Descrizione**

Quanto è divertente aggiungere un pannello di espressioni al robot. E il pannello LED 8\*16 di Keyestudio può fare al caso vostro. Con il suo aiuto, potrete progettare espressioni facciali, immagini, motivi e altre visualizzazioni da soli.

Il pannello LED 8\*16 è composto da 128 LED. I dati del microprocessore (Arduino) comunicano con l’AiP1640 tramite un’interfaccia bus a due fili. Pertanto, può controllare l’accensione e lo spegnimento dei 128 LED sul modulo, in modo da far visualizzare al display a matrice di punti sul modulo il motivo desiderato. È fornito un cavo HX-2.54 4Pin per facilitare il cablaggio.

### **2. Specifiche**

- Tensione di lavoro: DC 3.3-5V

- Perdita di potenza: 400mW

- Frequenza di oscillazione: 450KHz

- Corrente di pilotaggio: 200mA

- Temperatura di lavoro: -40\~80℃

- Modalità di comunicazione: I2C
  

### **3. Schema Elettrico**

![](media/A222.png)

### **4. Principio di Funzionamento**

Come controllare ogni LED della matrice a punti 8\*16? Si sa che ogni byte ha 8 bit e ogni bit è 0 o 1. Quando è 0, il LED è spento mentre quando è 1 il LED è acceso. Un byte può controllare una colonna di LED, e naturalmente 16 byte possono controllare 16 colonne di LED, questa è la matrice a punti 8\*16.

### **5. Descrizione dei Pin e Protocollo di Comunicazione**

I dati del microprocessore (Arduino) comunicano con l’AiP1640 tramite un cavo bus a due fili.

Il diagramma del protocollo di comunicazione è il seguente (SCLK) è SCL, (DIN) è SDA.

![](media/A223.png)

① Condizione di inizio per l’input dei dati: SCL è ad alto livello e SDA cambia da alto a basso.

② Per l’impostazione del comando dati, ci sono i metodi mostrati nella figura sottostante.

Nel nostro programma di esempio, selezioniamo il modo per **aggiungere 1 all’indirizzo automaticamente**, il valore binario è 0100 0000 e il valore esadecimale corrispondente è 0x40.

![Img](media/A224.png)

③ Per l’impostazione del comando indirizzo, l’indirizzo può essere selezionato come mostrato di seguito.

Nel nostro programma di esempio è selezionato il primo 00H, e il numero binario 1100 0000 corrisponde all’esadecimale 0xc0.

![Img](media/A225.png)

④ Il requisito per l’input dei dati è che quando SCL è ad alto livello durante l’input dei dati, il segnale su SDA deve rimanere invariato. Solo quando il segnale di clock su SCL è a basso livello, il segnale su SDA può essere cambiato. L’input dei dati avviene prima con il bit basso, e poi con il bit alto.

⑤ La condizione per la fine della trasmissione dati è che quando SCL è a basso livello, SDA a basso livello e SCL ad alto livello, il livello di SDA diventa alto.

⑥ Controllo del display, impostare diverse larghezze di impulso, la larghezza di impulso può essere selezionata come mostrato nella figura sottostante.

Nell’esempio, la larghezza di impulso è 4/16, e l’esadecimale corrispondente a 1000 1010 è 0x8A.

![Img](media/A226.png)

**Istruzioni per l’uso dello strumento modulo**

Lo strumento matrice a punti utilizza la versione online, e il link è: [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

① Inserire il link e la pagina appare come mostrato di seguito

![](media/A227.png)

② La matrice a punti è 8\*16, quindi regolare l’altezza a 8 e la larghezza a 16, come mostrato nella figura sottostante.

![](media/A228.png)

③ Generare dati esadecimali dal motivo

Come mostrato nella figura sottostante, premere il tasto sinistro del mouse per selezionare, cliccare con il tasto destro per annullare; disegnare il motivo desiderato, cliccare su Generate, e verranno generati i dati esadecimali necessari.

![](media/A229.png)

### **6. Componenti**

| Scheda di Sviluppo *1      | Driver Motore 8833 *1            | Pannello LED 8x16*1          |
| ------------------------- | ------------------------------- | ------------------------- |
| ![img](media/A230.jpg) | ![img](media/A231.jpg)       | ![img](media/A232.jpg) |
| Cavo USB*1               | Cavo Dupont HX-2.54 4P 200mm *1 |                           |
| ![img](media/A233.jpg) | ![img](media/A234.jpg)       |                           |



### **7. Schema di Collegamento**

![](media/A235.png)

Il GND, VCC, SDA e SCL della scheda LED 8x16 sono rispettivamente collegati alla scheda di espansione sensori keyestudio - (GND), + (VCC), A4, A5 per la comunicazione seriale a due fili.

(<span style="color: rgb(255, 76, 65);">Nota:</span> Sebbene sia collegato al pin IIC di Arduino, questo modulo non è per la comunicazione IIC. E la porta IO qui serve a simulare la comunicazione I2C e può essere collegata a qualsiasi due pin).

### **8. Codice di Test**

Prima di scrivere il codice, è necessario importare il file della libreria della scheda LED 8x16. I passaggi specifici sono i seguenti:

Clicca su ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, quindi cerca il modulo “**Matrix 8\*16 Aip1640**” ![](media/A236.png) e cliccaci sopra. In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il modulo “**Matrix 8\*16 Aip1640**” è stato aggiunto con successo.

![Img](media/A237.png)

![](media/A238.png)

Clicca su ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, si può vedere il blocco di istruzioni del modulo “**Matrix 8\*16 Aip1640**” aggiunto nell'area moduli.

![](media/A239.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A240.png)

**Codice di Test Completo**

![](media/A241.png)

### **9. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi porta l'interruttore DIP su ON, verrà visualizzato un motivo a forma di sorriso sulla scheda LED.

![](media/A242.png)

### **10. Spiegazione del Codice**

Usiamo lo strumento modulus che abbiamo appena imparato, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), per far visualizzare alla matrice di punti il motivo di start, andare avanti, fermarsi e poi cancellare il motivo. L'intervallo di tempo è di 2000 ms.

![image-20250513092102687](media/A243.png)![image-20250513092107293](media/A244.png)![image-20250513092113035](media/A245.png)![image-20250513092116952](media/A246.png)


Blocco di istruzioni per faccina sorridente ![](media/A247.png)

Blocco di istruzioni per espressione: ![](media/A248.png)

Blocco di istruzioni per cuore ![](media/A249.png)

Blocco di istruzioni per andare avanti ![](media/A250.png)

Blocco di istruzioni per **fare un passo indietro** ![](media/A251.png)

Blocco di istruzioni per **girare a sinistra** ![](media/A252.png)

Blocco di istruzioni per **girare a destra** ![](media/A253.png)

Blocco di istruzioni per **fermare** ![](media/A254.png)

Blocco di istruzioni per **pulire lo schermo** ![](media/A255.png)

![](media/A235.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A240.png)

(3).![](media/A256.png)

**Codice di Test Completo**

![](media/A257.png)

Dopo aver caricato il codice di test, la scheda delle espressioni facciali mostra questi motivi in ordine e ripete questa sequenza.

![image-20250513092222972](media/A258.png)![image-20250513092233711](media/A259.png)![image-20250513092238552](media/A260.png)