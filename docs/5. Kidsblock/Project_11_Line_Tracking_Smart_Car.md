# Progetto 11 Auto Intelligente a Inseguimento di Linea

![](media/A271.png)

### **1. Descrizione**

Basandoci sul principio di funzionamento del sensore di inseguimento linea, realizziamo un'auto intelligente a inseguimento di linea.

In questo progetto, rileviamo se c'è una linea nera sotto l'auto intelligente tramite un sensore di inseguimento linea, e poi controlliamo la rotazione dei due gruppi di motori in base ai risultati della rilevazione in modo da far muovere l'auto intelligente lungo la linea nera.

### **2. Diagramma di Flusso**

![img](media/A272.png)

![Img](media/A273.png)

### **3. Schema di Collegamento**

![](media/A264.png)

G, V, S1, S2 e S3 del sensore di inseguimento linea sono collegati a G (GND), V (VCC), D11, D7 e D8 della scheda di espansione sensori.

L'alimentazione è collegata alla porta BAT.

### **4. Codice di Test**

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A126.png)

(2).![](media/A274.png)

(3).![](media/A275.png)

(4).![](media/A268.png)

(5).![](media/A276.png)

**Codice di Test Completo**

![](media/A277.png)

![](media/A278.png)

![](media/A279.png)

### **5. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i fili secondo lo schema di collegamento, accendi l'alimentazione esterna e poi porta l'interruttore DIP su ON. A questo punto l'auto intelligente seguirà le linee.