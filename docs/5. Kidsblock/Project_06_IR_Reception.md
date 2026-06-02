# Progetto 6 Ricezione IR

![](media/A141.png)

### **1.Descrizione** 

Non c'è dubbio che il telecomando a infrarossi sia onnipresente nella vita quotidiana. Viene utilizzato per controllare vari elettrodomestici, come TV, stereo, videoregistratori e ricevitori di segnali satellitari. Il telecomando a infrarossi è composto da un sistema di trasmissione a infrarossi e da un sistema di ricezione a infrarossi, cioè un telecomando a infrarossi e un modulo ricevitore a infrarossi e un microcontrollore in grado di decodificare.  

![](media/A142.png)

Il segnale portante a infrarossi a 38K emesso dal telecomando è codificato dal chip di codifica nel telecomando. È composto da una sezione di codice pilota, codice utente, codice inverso utente, codice dati e codice inverso dati. L'intervallo di tempo dell'impulso viene utilizzato per distinguere se è un segnale 0 o 1 e la codifica è composta da questi segnali 0, 1.

Il codice utente dello stesso telecomando è costante mentre il codice dati può distinguere il tasto.

Quando si preme un tasto del telecomando, il telecomando invia un segnale portante a infrarossi. Quando il ricevitore IR riceve il segnale, il programma decodifica il segnale portante e determina quale tasto è stato premuto. L'MCU decodifica il segnale 01 ricevuto, giudicando così quale tasto è stato premuto dal telecomando.

Il ricevitore a infrarossi che utilizziamo è un modulo ricevitore a infrarossi. È composto principalmente da una testa ricevente a infrarossi, che è un dispositivo che integra ricezione, amplificazione e demodulazione. Il suo IC interno ha completato la demodulazione e può realizzare dalla ricezione a infrarossi all'uscita ed è compatibile con segnali TTL.

Inoltre, è adatto per telecomandi a infrarossi e trasmissione dati a infrarossi. Il modulo ricevitore a infrarossi realizzato dal ricevitore ha solo tre pin, linea del segnale, VCC e GND. È molto comodo per comunicare con Arduino e altri microcontrollori.

### **2.Specifiche**

- Tensione di funzionamento: 3.3-5V (DC)

- Segnale di uscita: Segnale digitale

- Angolo di ricezione: 90 gradi

- Frequenza: 38khz

- Distanza di ricezione: 10m

L'immagine mostra il prodotto reale e lo schema elettrico del ricevitore a infrarossi.

![](media/A141.png)

![](media/A143.png)

### **3.Componenti**

| Scheda di sviluppo *1      | Driver motore 8833 *1      | Modulo LED Rosso*1          |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg) | ![img](media/A43.jpg) | ![img](media/A44.jpg) |
| Cavo Dupont 3P F-F*1      | Cavo USB*1               |                           |
| ![img](media/A45.jpg) | ![img](media/A46.jpg) |                           |


Poiché la scheda 8833 integra il ricevitore IR, non è necessario effettuare collegamenti. I pin del modulo ricevitore IR sono G (GND), V (VCC) e D3.

### **4.Codice di test**

<span style="color: rgb(255, 76, 65);">Nota bene: Il modulo a infrarossi mostrato nella dimostrazione software è già integrato nella scheda di espansione e non viene fornito separatamente. Di conseguenza, non troverai il modulo raffigurato nell'immagine sottostante all'interno del prodotto.![](media/A144.png)</span>

Prima di scrivere il codice, è necessario importare il file della libreria del sensore ricevitore IR. I passaggi specifici sono i seguenti: 

Clicca su ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, quindi cerca il sensore “**ir remote**” ![](media/A144.png) e cliccaci sopra. In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il sensore “ir remote” è stato aggiunto con successo. 

![Img](media/A145.png)

![](media/A146.png)

Clicca su ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, si può vedere il blocco di istruzioni del sensore “**ir remote**” aggiunto nell'area modulo. 

![](media/A147.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A149.png)

(4).![](media/A150.png)

**Codice di test completo**

![](media/A151.png)

### **5.Risultato del test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi collega il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, clicca su ![](media/A80.png) per impostare la velocità di trasmissione a 9600 baud.

Prendi il telecomando e invia il segnale al sensore ricevitore a infrarossi. Puoi vedere il valore del tasto corrispondente; se il tempo di pressione del tasto è troppo lungo, FFFFFFFF tende a generare caratteri illeggibili.

![](media/A152.png)

I valori dei tasti del telecomando sono mostrati di seguito.

![](media/A153.jpeg)

### **6. Pratica di Estensione**

Abbiamo decodificato il valore del tasto del telecomando IR. Che ne dici di controllare il LED tramite il valore misurato? Potremmo progettare un esperimento.

Collega un LED a D9, quindi premi i tasti del telecomando per accendere e spegnere il LED.

![](media/A154.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A155.png)

(4).![](media/A150.png)

(5).![](media/A156.png)

(6).![](media/A157.png)

(7).![](media/A158.png)

(8).![](media/A159.png)

**Codice di Test Completo**

![](media/A160.png)

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi collega il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, premendo il tasto "**OK**" sul telecomando è possibile accendere e spegnere il LED.