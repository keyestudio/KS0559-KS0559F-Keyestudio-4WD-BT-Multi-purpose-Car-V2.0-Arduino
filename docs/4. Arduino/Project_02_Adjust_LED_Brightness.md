# Progetto 2: Regolare la luminosità del LED

### **1.Descrizione**

Nella lezione precedente, abbiamo controllato l'accensione e lo spegnimento del LED e lo abbiamo fatto lampeggiare.

In questo progetto, controlleremo la luminosità del LED tramite PWM simulando un effetto di respiro.

PWM è un mezzo per controllare l'uscita analogica tramite mezzi digitali. Il controllo digitale viene utilizzato per generare onde quadre con diversi cicli di lavoro (un segnale che passa costantemente tra livelli alti e bassi) per controllare l'uscita analogica. In generale, le tensioni di ingresso delle porte sono 0V e 5V.

Cosa succede se è richiesto 3V? O un interruttore tra 1V, 3V e 3,5V? Non possiamo cambiare continuamente le resistenze. Per questo motivo, ricorriamo al PWM.

![bbcfcb9ae56abb7e80ee587246fc4be9](media/A14.gif)

Per l'uscita di tensione della porta digitale di Arduino, ci sono solo LOW e HIGH, che corrispondono all'uscita di tensione di 0V e 5V. Puoi definire LOW come 0 e HIGH come 1, e lasciare che Arduino emetta cinquecento segnali 0 o 1 in 1s.

Se tutti i cinquecento output sono 1, cioè 5V; se tutti sono 0, cioè 0V. Se l'output è 010101010101 in questo modo, allora la porta di uscita è 2,5V, che è come mostrare un film. Il film che guardiamo non è completamente continuo. In realtà emette 25 immagini al secondo. In questo caso, l'uomo non può vederlo, né il PWM. Se vogliamo una tensione diversa, dobbiamo controllare il rapporto tra 0 e 1. Più segnali 0,1 vengono emessi per unità di tempo, più preciso è il controllo.

PWM è una tecnologia che utilizza metodi digitali per ottenere quantità analogiche. Il controllo digitale consente di formare un'onda quadra, il segnale dell'onda quadra ha solo due stati on e off (alto e basso). Una tensione che va da 0 a 5V può essere simulata controllando il rapporto tra la durata on e off. Il tempo trascorso in on (tecnicamente chiamato livello alto) è chiamato larghezza dell'impulso, quindi PWM è anche chiamato modulazione della larghezza dell'impulso.

Le barre verticali verdi rappresentano un periodo dell'onda quadra. Il valore scritto in ogni analogWrite(value) corrisponde a una percentuale, chiamata anche Duty Cycle. Questa percentuale si riferisce al rapporto del tempo occupato dal livello alto in un ciclo, cioè duty cycle = tempo livello alto/tempo ciclo.

Nella figura, dall'alto verso il basso, il duty cycle della prima onda quadra è 0%, e il valore corrispondente è 0, e la luminosità del LED è la più bassa, cioè spento. Più a lungo dura il livello alto, più sarà luminoso. Pertanto, il valore dell'ultimo duty cycle del 100% è 255, e il LED è il più luminoso. Il 50% è metà luminoso, e il 25% è più scuro.

PWM è più usato per regolare la luminosità delle luci LED o la velocità di rotazione dei motori, e la velocità delle ruote azionate dai motori può essere facilmente controllata. Quando si gioca con alcuni robot Arduino, i vantaggi del PWM possono essere meglio evidenziati.

### **2.Componenti**

|           Development Board *1           |           8833 Motor Driver *1           |     Red LED Module*1     |
| :--------------------------------------: | :--------------------------------------: | :----------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             3P Dupont Wire*1             |               USB Cable*1                |                          |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                          |

### **3.Diagramma di collegamento**

Mantieni il cablaggio invariato.

![image-20250508161123490](media/A13.png)

### **4.Codice di test**

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.1
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Definisci il pin LED su D9
int value;

void setup () {
  pinMode (ledPin, OUTPUT); // inizializza ledPin come uscita.
}

void loop () {
  for (value = 0; value <255; value = value + 1) 
  {
    analogWrite (ledPin, value); // Il LED si accende gradualmente
    delay (5); // ritardo di 5ms
  }
  for (value = 255; value> 0; value = value-1) 
  {
    analogWrite (ledPin, value); // Il LED si spegne gradualmente
    delay (5); // ritardo di 5ms
  }
}
//*****************************************************************
```

### **5.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico e usa un cavo USB per collegare il computer e alimentare la scheda. Dopo l'accensione, vedrai che il LED cambia gradualmente da luminoso a spento, come il respiro umano, invece di accendersi e spegnersi immediatamente.

### **6.Spiegazione del Codice**

Se abbiamo bisogno di ripetere una certa istruzione, possiamo usare l'istruzione for.

Il formato dell'istruzione for è mostrato di seguito:

![image-20250508162458776](media/A15.png)

Sequenza ciclica FOR:

Giro 1：1 → 2 → 3 → 4

Giro 2：2 → 3 → 4

…

Fino a quando il numero 2 non è stabilito, il ciclo “for” è terminato,

Dopo aver compreso questo ordine, torniamo al codice:

**for (int value = 0; value \< 255; value=value+1)**

**for (int value = 255; value \>0; value=value-1)**

Le due istruzioni “for” fanno aumentare value da 0 a 255, poi diminuirlo da 255 a 0, poi aumentare a 255.... ciclo infinito.

C'è una nuova funzione nel seguito ----- analogWrite().

Sappiamo che la porta digitale ha solo due stati, 0 e 1. Quindi come inviare un valore analogico a una porta digitale? Qui serve questa funzione. Osserviamo la scheda Arduino e troviamo 6 pin contrassegnati con “\~” che possono emettere segnali PWM.

Formato della funzione come segue:

**analogWrite(pin,value)**

analogWrite() serve per scrivere un valore analogico da 0 a 255 per la porta PWM, quindi il valore è nell'intervallo 0~255. Attenzione che puoi scrivere solo sui pin digitali con funzione PWM, come i pin 3, 5, 6, 9, 10, 11.

PWM è una tecnologia per ottenere quantità analogiche tramite metodo digitale. Il controllo digitale forma un'onda quadra, e il segnale dell'onda quadra ha solo due stati di accensione e spegnimento (cioè livelli alto o basso). Controllando il rapporto tra la durata di accensione e spegnimento, si può simulare una tensione variabile da 0 a 5V. Il tempo di accensione (accademicamente chiamato livello alto) è chiamato larghezza dell'impulso, quindi PWM è anche chiamato modulazione della larghezza dell'impulso.

Attraverso le seguenti cinque onde quadre, impariamo di più sul PWM.

![image-20250508162529349](media/A16.png)

Nella figura sopra, la linea verde rappresenta un periodo, e il valore di analogWrite() corrisponde a una percentuale chiamata anche Duty Cycle. Il duty cycle indica il rapporto del tempo occupato dal livello alto nel ciclo. Dall'alto verso il basso, il duty cycle della prima onda quadra è 0% e il suo valore corrispondente è 0.

La luminosità del LED è la più bassa, cioè spento. Più a lungo dura il livello alto, più il LED è luminoso. Pertanto, l'ultimo duty cycle è 100%, che corrisponde a 255, e il LED è al massimo della luminosità. Il 50% è metà luminosità, il 25% significa più scuro.

Il PWM è usato principalmente per regolare la luminosità del LED o la velocità di rotazione dei motori.

Ha un ruolo vitale nel controllo delle auto robot intelligenti. Credo che non vediate l'ora di imparare il prossimo progetto.

**7.Esercizio di Estensione**

Modifichiamo il valore del delay mantenendo il pin invariato, quindi osserviamo come cambia il LED.

```c
//***********************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.2
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Definisce il pin LED su D9
void setup () {
   pinMode(ledPin, OUTPUT); // inizializza ledPin come uscita.
}

void loop () {
   for (int value = 0; value <255; value = value + 1) {
     analogWrite (ledPin, value); // Il LED si accende gradualmente
     delay (30); // ritardo di 30ms
   }
   for (int value = 255; value> 0; value = value-1) {
     analogWrite (ledPin, value); // Il LED si spegne gradualmente
     delay (30); // ritardo di 30ms
   }
}
//***********************************************************
```

Carica il codice sulla scheda di sviluppo, quindi il LED lampeggerà più lentamente.