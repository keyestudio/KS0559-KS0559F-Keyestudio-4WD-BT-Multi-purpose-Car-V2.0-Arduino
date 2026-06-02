# Progetto 10 Auto Intelligente Limitata

![](media/A261.jpeg)

### **1. Descrizione**

In questo progetto, vogliamo combinare le conoscenze di un sensore di tracciamento linea e moduli driver per motori per realizzare un'auto intelligente limitata. Nell'esperimento, l'obiettivo è utilizzare il sensore di tracciamento linea per rilevare se c'è una linea nera intorno all'auto intelligente, e quindi controllare la rotazione dei due motori in base ai risultati del rilevamento in modo da bloccare l'auto intelligente in un cerchio disegnato con linea nera.

### **2. Diagramma di Flusso**

![img](media/A262.png)

La logica specifica dell'auto intelligente 4WD limitata è mostrata nella tabella.

![Img](media/A263.png)

### **3. Schema di Collegamento**

![](media/A264.png)

G, V, S1, S2 e S3 del sensore di tracciamento linea sono collegati a G (GND), V (VCC), D11, D7 e D8 della scheda di espansione sensori.

L'alimentazione è collegata alla porta BAT.

### **4. Codice di Test**

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono a titolo di riferimento.

(1).![](media/A126.png)

(2).![](media/A265.png)

(3).![](media/A266.png)

(4).![](media/A267.png)

(5).![](media/A268.png)

(6).![](media/A269.png)

**Codice di Test Completo**

![KidsBlock Project-1747127137354](media/A270.png)

### **5. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema di collegamento, accendi l'alimentazione esterna e poi porta l'interruttore DIP su ON. Metti l'auto intelligente nel cerchio nero, quindi si muoverà esclusivamente all'interno del cerchio.