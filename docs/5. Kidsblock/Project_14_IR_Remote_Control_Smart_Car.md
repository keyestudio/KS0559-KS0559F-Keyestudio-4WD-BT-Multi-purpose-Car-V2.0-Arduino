# Progetto 14 Auto Intelligente Controllata da Telecomando IR

![](media/A307.jpeg)

### **1. Descrizione**

In questo progetto, realizzeremo un'auto intelligente controllata da telecomando IR e premeremo il pulsante sul telecomando IR per far muovere l'auto.

### **2. Diagramma di Flusso**

![img](media/A308.png)

**La logica specifica dell'auto intelligente controllata da telecomando IR è mostrata di seguito:**

| Configurazione iniziale                                    |           | La scheda LED mostra una faccina sorridente        |
| ---------------------------------------------------------- | --------- | -------------------------------------------------- |
| Telecomando                                                | Valore tasto | Stato tasto                                       |
| ![wps6-1747037981476-25](media/A309.jpg) | FF629D    | Avanti, la scheda LED 8*8 mostra l'icona avanti    |
| ![wps7-1747037985784-27](media/A310.jpg) | FFA857    | Indietro, la scheda LED 8*8 mostra l'icona indietro|
| ![wps8](media/A311.jpg)                  | FF22DD    | Ruota a sinistra, la scheda LED 8*8 mostra l'icona verso sinistra |
| ![wps9](media/A312.jpg)                  | FFC23D    | Ruota a destra, la scheda LED 8*8 mostra l'icona verso destra   |
| ![wps10](media/A313.jpg)                                 | FF02FD    | Stop, la scheda LED 8*8 mostra “STOP”              |



### **3. Schema di Collegamento**

![](media/A314.png)

1). GND, VCC, SDA e SCL del modulo scheda LED 8\*8 sono collegati rispettivamente a G (GND), V (VCC), A4 e A5 della scheda di espansione.
    
2). Poiché il ricevitore IR è integrato sulla scheda di espansione motore 8833, non è necessario alcun cablaggio aggiuntivo. I pin del ricevitore IR sulla scheda 8833 sono rispettivamente G (GND), V (VCC) e D3.
    
3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso a 5V (V) e il filo arancione ad A3.
    
4). L'alimentazione è collegata alla porta BAT.
    

### **4. Codice di Test**

<span style="color: rgb(255, 76, 65);">Nota bene: Il modulo a infrarossi mostrato nella dimostrazione software è già integrato nella scheda di espansione e non viene fornito separatamente. Di conseguenza, non troverai il modulo raffigurato nell'immagine sottostante all'interno del prodotto.![](media/A144.png)</span>

Prima di scrivere il codice, è necessario importare i file della libreria del sensore ultrasonico, della scheda LED 8x16 e del servo. I passaggi specifici sono i seguenti: 
    
Clicca ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, quindi cerca il sensore “ir remote” ![](media/A144.png) e cliccaci sopra. In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il sensore “**ir remote**” è stato aggiunto con successo. 

![Img](media/A315.png)

![](media/A146.png)

Clicca ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, nell'area moduli potrai vedere il blocco istruzioni del sensore “**ir remote**”, del modulo “**Matrix 8\*16 Aip1640**” e del componente “**Servo**”. 

![](media/A316.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono a tua disposizione come riferimento

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A318.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A320.png)

(7).![](media/A291.png)

(8).![](media/A321.png)

**Codice di Test Completo**

![](media/A322.png)

![](media/A323.png)

![](media/A324.png)

![](media/A325.png)

![](media/A326.png)

### **5. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema di collegamento, accendi l'alimentazione esterna e poi porta l'interruttore DIP su ON. A questo punto potrai usare il telecomando IR per far muovere l'auto e la scheda LED 8X16 mostrerà il pattern di stato corrispondente.