# Progetto 4 Controllo Servo

### **1. Descrizione**

![](media/A90.jpeg)

Il servo motore è un attuatore rotativo a controllo di posizione. È composto principalmente da un alloggiamento, una scheda circuito, un motore core-less, un ingranaggio e un sensore di posizione. Il suo principio di funzionamento è che il servo riceve il segnale inviato da MCU o ricevitori e produce un segnale di riferimento con un periodo di 20ms e una larghezza di 1,5ms, quindi confronta la tensione di polarizzazione continua acquisita con la tensione del potenziometro e ottiene l'uscita della differenza di tensione.

![](media/A91.png)

In generale, il servo ha tre fili di colore marrone, rosso e arancione. Il filo marrone è collegato a massa, quello rosso è il polo positivo e quello arancione è il filo del segnale.

L'angolo di rotazione del servo motore è controllato regolando il duty cycle del segnale PWM (Pulse-Width Modulation). Il ciclo standard del segnale PWM è di 20ms (50Hz). Teoricamente, la larghezza è distribuita tra 1ms e 2ms, ma in realtà è tra 0,5ms e 2,5ms. La larghezza corrisponde all'angolo di rotazione da 0° a 180°. Ma si noti che per motori di marche diverse, lo stesso segnale può avere angoli di rotazione differenti.

![](media/A92.jpg)

Gli angoli corrispondenti del servo sono mostrati di seguito:

![](media/A93.png)

### **2. Specifiche**

- Tensione di lavoro: DC 4.8V ~ 6V

- Gamma angolare operativa: circa 180° (a 500 → 2500 μsec)

- Gamma di larghezza impulso: 500 → 2500 μsec

- Velocità a vuoto: 0.12 ± 0.01 sec / 60 (DC 4.8V) 0.1 ± 0.01 sec / 60 (DC 6V)
  
- Corrente a vuoto: 200 ± 20mA (DC 4.8V) 220 ± 20mA (DC 6V)

- Coppia di arresto: 1.3 ± 0.01kg · cm (DC 4.8V) 1.5 ± 0.1kg · cm (DC 6V)
  
- Corrente di arresto: ≦ 850mA (DC 4.8V) ≦ 1000mA (DC 6V)

- Corrente in standby: 3 ± 1mA (DC 4.8V) 4 ± 1mA (DC 6V)

### **3. Componenti**

| Scheda di Sviluppo *1      | Driver Motore 8833 *1      | Servo*1                                     |
| ------------------------- | ------------------------- | ------------------------------------------- |
| ![img](media/A94.jpg)  | ![img](media/A95.jpg)  | ![img](media/A96.png)                   |
| Porta batteria 18650*1    | Cavo USB*1               | Batteria 18650*2 (fornita dall'utente)            |
| ![img](media/A97.png) | ![img](media/A98.jpg) | ![img](media/A99.png) |

### **4. Schema di Collegamento**

![](media/A100.png)

Nota sul cablaggio: Il servo è collegato a G (GND), V (VCC) e A3, il filo marrone del servo è collegato a Gnd (G), quello rosso è collegato a 5V (V) e quello arancione è collegato ad A3.

Il servo deve essere collegato a un'alimentazione esterna a causa dell'elevata richiesta di corrente per la guida del servo. Generalmente, la corrente della scheda di sviluppo non è sufficiente. Se non si collega l'alimentazione esterna, la scheda di sviluppo potrebbe bruciarsi.

### **5. Codice di Test**

Prima di scrivere il codice, è necessario importare il file della libreria servo. I passaggi specifici sono i seguenti:

Cliccare ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, quindi cercare "**Servo**".

![](media/A101.png)

Selezionare il componente e cliccarlo. In questo modo, "**Not Loaded**" cambia in "**loaded**", indicando che il componente "**Servo**" è stato aggiunto con successo.

![Img](media/A102.png)

![](media/A103.png)

Cliccare ![](media/A33.png) per tornare all'editor di codice, e nell'area moduli si può vedere il blocco direttiva del componente "**Servo**" aggiunto.

![](media/A104.png)

È possibile trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A105.png)

(2).![](media/A106.png)

(3).![](media/A107.png)

**Codice di Test Completo**

![](media/A108.png)

### **6. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema di collegamento e alimentare l'alimentazione esterna. Dopo l'accensione, spostare l'interruttore dip su "ON", quindi il servo oscillerà nell'intervallo da 0° a 180°.