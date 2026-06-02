# Progetto 5 Sensore Ultrasonico

### **1. Descrizione**

![](media/A109.png)

Il sensore ultrasonico HC-SR04 utilizza il sonar per determinare la distanza da un oggetto, proprio come fanno i pipistrelli. Offre un'eccellente rilevazione della distanza senza contatto con alta precisione e letture stabili in un pacchetto facile da usare. Include moduli trasmettitore e ricevitore ultrasonici.

![Img](media/A110.png)

L'HC-SR04 o sensore ultrasonico viene utilizzato in una vasta gamma di progetti elettronici per creare applicazioni di rilevamento ostacoli e misurazione della distanza, oltre a varie altre applicazioni. Qui abbiamo presentato un metodo semplice per misurare la distanza con Arduino e un sensore ultrasonico e come utilizzare il sensore ultrasonico con Arduino.

### **2. Specifiche**

- Tensione di funzionamento: +5V DC

- Corrente a riposo: \<2mA

- Corrente di funzionamento: 15mA

- Angolo efficace: \<15°

- Intervallo di distanza: 2cm – 300 cm

- Precisione: 0.3 cm

- Angolo di misurazione: 30 gradi

- Larghezza impulso di ingresso Trigger: 10uS

![](media/A111.png)

### **3. Componenti**

| Scheda di sviluppo *1      | Driver motore 8833 *1      | Modulo LED Rosso *1          | Sensore Ultrasonico *1       |
| ------------------------- | ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A112.jpg) | ![img](media/A113.jpg) | ![img](media/A114.jpg) | ![img](media/A115.jpg) |
| Cavo Dupont 4P *1          | Cavo USB *1               | Cavo Dupont 3P *1          |                           |
| ![img](media/A116.jpg) | ![img](media/A117.jpg) | ![img](media/A118.jpg) |                           |

### **4. Principio di funzionamento**

Come mostrato nell'immagine sopra, è come due occhi. Uno è il trasmettitore, l'altro è il ricevitore.

Il modulo ultrasonico emetterà onde ultrasoniche dopo aver ricevuto un segnale di trigger. Quando le onde ultrasoniche incontrano un oggetto e vengono riflesse, il modulo emette un segnale di eco, così può determinare la distanza dell'oggetto dal tempo trascorso tra il segnale di trigger e il segnale di eco.

t è il tempo che il segnale emesso impiega per incontrare l'ostacolo e tornare indietro. La velocità di propagazione del suono nell'aria è circa 343m/s, e distanza = velocità \* tempo. Tuttavia, l'onda ultrasonica viene emessa e ritorna, quindi percorre due volte la distanza. Pertanto, deve essere divisa per 2, la distanza misurata dall'onda ultrasonica = (velocità \* tempo)/2.

**Metodo d'uso e diagramma del modulo ultrasonico:**

1). Usa il pin GPIO per fornire un segnale alto di almeno 10μs al pin Trig dell'SR04, che può attivarlo per rilevare la distanza.

2). Dopo il trigger, il modulo invierà automaticamente otto impulsi ultrasonici a 40KHz e rileverà se c'è un segnale di ritorno. Questo passaggio viene completato automaticamente dal modulo.

3). Se il segnale ritorna, il pin Echo emetterà un livello alto, e la durata del livello alto è il tempo dal trasmissione dell'onda ultrasonica al ritorno.

![image-20250509143833078](media/A119.png)


**Schema elettrico del sensore ultrasonico:**

![](media/A120.jpeg)

### **5. Schema di collegamento**

![](media/A121.png)

VCC, Trig, Echo e Gnd del sensore ultrasonico sono collegati rispettivamente a 5V(V), D12, D13 e Gnd(G)

### **6. Codice di test**

Prima di scrivere il codice, è necessario importare il file della libreria del sensore ultrasonico. I passaggi specifici sono i seguenti: 

Clicca ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, quindi cerca il sensore "**Ultrasonic**" ![](media/A122.png) e cliccaci sopra. In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il sensore "**Ultrasonic**" è stato aggiunto con successo. 

![Img](media/A123.png)

![](media/A124.png)

Clicca ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, il blocco di istruzioni del sensore "**Ultrasonic**" aggiunto sarà visibile nell'area moduli. 

![](media/A125.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A127.png)

(3).![](media/A128.png)

(4).![](media/A129.png)

(5).![](media/A130.png)

(6).![](media/A131.png)

(7).![](media/A132.png)

**Codice di Test Completo**

![](media/A133.png)

### **7. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi collega il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, clicca su ![](media/A80.png) per impostare la velocità di trasmissione a 9600 baud.

La distanza rilevata verrà visualizzata, e l'unità è cm e pollici. Ostacola il sensore a ultrasuoni con la mano, il valore della distanza visualizzato diminuisce.

![](media/A134.png)

### **8. Pratica Estesa**

Abbiamo appena misurato la distanza visualizzata dall'ultrasuoni. Che ne dici di controllare il LED con la distanza misurata? Proviamo e colleghiamo un modulo luce LED al pin D9.

![](media/A135.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A136.png)

(3).![](media/A128.png)

(4).![](media/A137.png)

(5).![](media/A130.png)

(6).![](media/A138.png)

(7).![](media/A132.png)

**Codice di Test Completo**

![](media/A139.png)

![](media/A140.png)

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi collega il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, blocca il sensore a ultrasuoni con la mano (la distanza è tra 2-10 cm), quindi verifica se il LED si accende.