# Progetto 2: Regolare la Luminosità del LED

### **1.Descrizione**

Nella lezione precedente, abbiamo controllato l'accensione e lo spegnimento del LED e lo abbiamo fatto lampeggiare.

In questo progetto, controlleremo la luminosità del LED tramite PWM simulando un effetto di respiro.

PWM è un mezzo per controllare l'uscita analogica tramite metodi digitali. Il controllo digitale viene utilizzato per generare onde quadre con diversi cicli di lavoro (un segnale che passa costantemente tra livelli alti e bassi) per controllare l'uscita analogica. In generale, le tensioni di ingresso delle porte sono 0V e 5V.

Cosa succede se è necessario 3V? O un interruttore tra 1V, 3V e 3,5V? Non possiamo cambiare continuamente le resistenze. Per questo motivo, ricorriamo al PWM.

![](media/A53.gif)

Per l'uscita di tensione della porta digitale Arduino, ci sono solo LOW e HIGH, che corrispondono all'uscita di tensione di 0V e 5V. Puoi definire LOW come 0 e HIGH come 1, e lasciare che Arduino emetta cinquecento segnali 0 o 1 in 1s.

Se tutti i cinquecento output sono 1, cioè 5V; se tutti sono 0, cioè 0V. Se l'output è 010101010101 in questo modo, allora la porta di uscita è 2,5V, che è come mostrare un film. Il film che guardiamo non è completamente continuo. In realtà emette 25 immagini al secondo. In questo caso, l'occhio umano non lo vede, né lo fa il PWM. Se vogliamo una tensione diversa, dobbiamo controllare il rapporto tra 0 e 1. Più segnali 0,1 vengono emessi per unità di tempo, più preciso sarà il controllo.

PWM è una tecnologia che utilizza metodi digitali per ottenere quantità analogiche. Il controllo digitale consente di formare un'onda quadra, il segnale a onda quadra ha solo due stati on e off (alto e basso). Una tensione che va da 0 a 5V può essere simulata controllando il rapporto tra durata on e off. Il tempo trascorso in on (tecnicamente chiamato livello alto) è chiamato larghezza dell'impulso, quindi PWM è anche chiamato modulazione della larghezza dell'impulso.

![](media/A54.png)

Le barre verticali verdi rappresentano un periodo dell'onda quadra. Il valore scritto in ogni analogWrite(value) corrisponde a una percentuale, chiamata anche Duty Cycle. Questa percentuale si riferisce al rapporto del tempo occupato dal livello alto in un ciclo, cioè duty cycle = tempo livello alto/tempo ciclo.

Nella figura, dall'alto verso il basso, il duty cycle della prima onda quadra è 0%, e il valore corrispondente è 0, e la luminosità del LED è la più bassa, cioè spento. Più a lungo dura il livello alto, più sarà luminoso. Pertanto, il valore dell'ultimo duty cycle del 100% è 255, e il LED è il più luminoso. Il 50% è metà luminoso, e il 25% è più scuro.

PWM è più usato per regolare la luminosità delle luci LED o la velocità di rotazione dei motori, e la velocità delle ruote azionate dai motori può essere facilmente controllata. Quando si gioca con alcuni robot Arduino, i vantaggi del PWM si riflettono meglio.

### **2.Componenti**

| Scheda di Sviluppo *1      | Driver Motore 8833 *1      | Modulo LED Rosso*1          |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg) | ![img](media/A43.jpg) | ![img](media/A44.jpg) |
| Cavo Dupont 3P F-F*1      | Cavo USB*1               |                           |
| ![img](media/A45.jpg) | ![img](media/A46.jpg) |                           |

### **3.Diagramma di Collegamento**

Mantieni il cablaggio invariato.

![](media/A47.png)

### **4.Codice di Test**

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A55.png)

(2).![](media/A56.png)

(3).![](media/A57.png)

(4).![](media/A58.png)

(5).![](media/A59.png)

(6).![](media/A60.png)

**Codice di Test Completo**

![](media/A61.png)

### **5.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo il diagramma di collegamento e usa un cavo USB per collegare il computer per alimentare la scheda. Dopo l'accensione, vedrai che il LED cambia gradualmente da luminoso a spento, come il respiro umano, invece di accendersi e spegnersi immediatamente.

### **6.Esercizio di Estensione**

Mantieni i pin del LED invariati, poi cambia il codice (valori dietro wait)

![](media/A62.png)

Carica il codice sulla scheda di sviluppo, quindi il LED lampeggerà più lentamente.