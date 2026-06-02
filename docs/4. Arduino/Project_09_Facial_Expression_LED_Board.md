# Progetto 9 Pannello LED con Espressione Facciale

![image-20250510090912741](media/A87.png)

### **1.Descrizione**

Quanto è divertente aggiungere un pannello di espressioni al robot. E il pannello LED Keyestudio 8\*16 può fare al caso vostro. Con il suo aiuto, potrete progettare espressioni facciali, immagini, motivi e altre visualizzazioni da soli.

Il pannello LED 8\*16 è dotato di 128 LED. I dati del microprocessore (Arduino) comunicano con l’AiP1640 tramite un’interfaccia bus a due fili. Pertanto, può controllare l’accensione e lo spegnimento dei 128 LED sul modulo, in modo da far visualizzare al display a matrice di punti sul modulo il motivo desiderato. È fornito un cavo HX-2.54 a 4 pin per facilitare il cablaggio.

### **2.Specifiche**

- Tensione di lavoro: DC 3.3-5V

- Perdita di potenza: 400mW

- Frequenza di oscillazione: 450KHz

- Corrente di pilotaggio: 200mA

- Temperatura di lavoro: -40\~80℃

- Modalità di comunicazione: I2C

### **3.Diagramma Circuitale**

![image-20250510091309725](media/A88.png)

### **4.Principio di Funzionamento**

Come controllare ogni LED della matrice a punti 8\*16? Si sa che ogni byte ha 8 bit e ogni bit è 0 o 1. Quando è 0, il LED è spento mentre quando è 1 il LED è acceso. Un byte può controllare una colonna di LED, e naturalmente 16 byte possono controllare 16 colonne di LED, questa è la matrice a punti 8\*16.

### **5.Descrizione dei Pin e Protocollo di Comunicazione**

I dati del microprocessore (Arduino) comunicano con l’AiP1640 tramite un cavo bus a due fili.

Il diagramma del protocollo di comunicazione è il seguente (SCLK) è SCL, (DIN) è SDA.

![image-20250510091407219](media/A89.png)

①Condizione di inizio per l’input dei dati: SCL è a livello alto e SDA cambia da alto a basso.

②Per l’impostazione del comando dati, ci sono i metodi mostrati nella figura sottostante.

Nel nostro programma di esempio, selezioniamo il modo per **aggiungere 1 all’indirizzo automaticamente**, il valore binario è 0100 0000 e il valore esadecimale corrispondente è 0x40.

![Img](media/A90.png)

③Per l’impostazione del comando indirizzo, l’indirizzo può essere selezionato come mostrato di seguito.

Nel nostro programma di esempio è selezionato il primo 00H, e il numero binario 1100 0000 corrisponde all’esadecimale 0xc0.

![Img](media/A91.png)

④La richiesta per l’input dei dati è che quando SCL è a livello alto durante l’input dei dati, il segnale su SDA deve rimanere invariato. Solo quando il segnale di clock su SCL è a livello basso, il segnale su SDA può essere cambiato. L’input dei dati avviene dal bit basso prima, e dal bit alto dopo.

⑤La condizione per la fine della trasmissione dati è che quando SCL è a livello basso, SDA a livello basso e SCL a livello alto, il livello di SDA diventa alto.

⑥Controllo del display, impostare diverse larghezze di impulso, la larghezza di impulso può essere selezionata come mostrato nella figura sottostante.

Nell’esempio, la larghezza di impulso è 4/16, e l’esadecimale corrispondente a 1000 1010 è 0x8A.

![Img](media/A92.png)

**Istruzioni per l’uso dello strumento modulo**

Lo strumento matrice a punti utilizza la versione online, e il link è: [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

①Inserire il link e la pagina appare come mostrato di seguito

![image-20250510091438524](media/A93.png)

②La matrice a punti è 8\*16, quindi regolare l’altezza a 8 e la larghezza a 16, come mostrato nella figura sottostante.

![image-20250510091446519](media/A94.png)

③Generare dati esadecimali dal motivo

Come mostrato nella figura sottostante, premere il tasto sinistro del mouse per selezionare, cliccare con il tasto destro per annullare; disegnare il motivo desiderato, cliccare su Generate, e verranno generati i dati esadecimali necessari.

![image-20250510091457463](media/A95.png)

### **6.Componenti**

| Scheda di Sviluppo *1                                         | Driver Motore 8833 *1                                         | Cavo USB*1               |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------- |
| ![img](media/A80.jpg)                                    | ![img](media/A81.jpg)                                    | ![img](media/A82.jpg) |
| Cavo USB*1                                                  | Filo Dupont HX-2.54 4P 200mm *1                              |                           |
| ![image-20250512155818434](media/A96.png) | ![image-20250512155822969](media/A97.png) |                           |

### **7.Diagramma di Collegamento**

![cec50fec4a335b6922e4c6694a133bc1](media/A98.png)

Il GND, VCC, SDA e SCL della scheda LED 8x16 sono rispettivamente collegati alla scheda di espansione sensori keyestudio - (GND), + (VCC), A4, A5 per la comunicazione seriale a due fili.

(<span style="color: rgb(255, 76, 65);">Nota:</span> Sebbene sia collegato al pin IIC di Arduino, questo modulo non è per comunicazione IIC. E la porta IO qui serve a simulare la comunicazione I2C e può essere collegata a qualsiasi due pin).

### **8.Codice di Test**  

Il codice mostrerà una faccina sorridente.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lezione 9.1
  Faccia a matrice
  http://www.keyestudio.com
*/
//Dati del pattern sorriso ottenuti dallo strumento touch
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};
#define SCL_Pin  A5  //Imposta il pin clock su A5
#define SDA_Pin  A4  //Imposta il pin dati su A4
void setup() {
  //Imposta i pin come output
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //pulisci
  //matrix_display(clear);
}
void loop() {
  matrix_display(smile);  //mostra il pattern dell'espressione sorridente
}
//questa funzione è usata per la visualizzazione a matrice di punti
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //funzione che chiama la condizione di inizio trasferimento dati
  IIC_send(0xc0);  //seleziona indirizzo

  for (int i = 0; i < 16; i++) //i dati del pattern sono 16 byte
  {
    IIC_send(matrix_value[i]); //Trasmette i dati del pattern
  }
  IIC_end();   //Termina la trasmissione dei dati del pattern
  IIC_start();
  IIC_send(0x8A);  //Controllo display, seleziona larghezza impulso 4/16
  IIC_end();
}
//Condizioni in cui inizia la trasmissione dati
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Indica la fine della trasmissione dati
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
//trasmette dati
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Ogni byte ha 8 bit e viene controllato bit per bit a partire dal meno significativo
  {
    if (send_data & mask) { //Imposta i livelli alto e basso di SDA_Pin a seconda che ogni bit del byte sia 1 o 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Alza il pin clock SCL_Pin per fermare la trasmissione dati
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Abbassa il pin clock SCL_Pin per cambiare il SEGNALE di SDA 
  }
}
//************************************************************************
```

### **9.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i fili secondo il diagramma di collegamento, quindi impostare l'interruttore DIP su ON, verrà visualizzato un pattern a forma di sorriso sulla scheda LED.

![95bb011957896b12285fc6763137bb9a](media/A99.png)

### **10.Spiegazione del Codice**

Utilizziamo lo strumento modulo che abbiamo appena imparato, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), per far visualizzare al display a matrice di punti il pattern di avvio, andare avanti, fermarsi e poi cancellare il pattern. L'intervallo di tempo è di 2000 ms.

![image-20250512155957415](media/A100.png)![image-20250512160002378](media/A101.png)![image-20250512160006841](media/A102.png)![image-20250512160010543](media/A103.png)

**Codice ottenuto dallo strumento modulo：**

**Codice per il pattern di avvio:**

0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01

**Codice per il pattern andare avanti:**

0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Codice per il pattern fare un passo indietro:**

0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Codice per il pattern girare a sinistra：**

0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00

**Codice per il pattern girare a destra：**

0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00

**Codice per il pattern stop：**

0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00

**Codice per cancellare lo schermo：**

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

![cec50fec4a335b6922e4c6694a133bc1](media/A104.png)

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lezione 9.2
  Faccia matrice
  http://www.keyestudio.com
*/
//Dati del pattern sorriso ottenuti dallo strumento touch
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char front[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x12, 0x09, 0x12, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char back[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char left[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00};
unsigned char right[] = {0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char STOP01[] = {0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00};
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define SCL_Pin  A5  //Imposta il pin clock su A5
#define SDA_Pin  A4  //Imposta il pin dati su A4
void setup() {
  //Imposta i pin come output
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //cancella
  //matrix_display(clear);
}
void loop() {
    matrix_display(start01);  //Mostra il pattern di avvio
    delay(2000);
    matrix_display(front);    //Mostra il pattern andare avanti
    delay(2000);
    matrix_display(STOP01);   //Mostra il pattern stop
    delay(2000);
    matrix_display(clear);    //Pulisce lo schermo
    delay(2000);
}
//questa funzione è usata per la visualizzazione sulla matrice di punti
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //funzione che chiama la condizione di start per il trasferimento dati
  IIC_send(0xc0);  //seleziona indirizzo

  for (int i = 0; i < 16; i++) // i dati del pattern sono 16 byte
  {
    IIC_send(matrix_value[i]); //Trasmetti i dati del pattern
  }
  IIC_end();   //Termina la trasmissione dei dati del pattern
  IIC_start();
  IIC_send(0x8A);  //Controllo display, seleziona larghezza impulso 4/16
  IIC_end();
}
//Condizioni in cui inizia la trasmissione dei dati
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Indica la fine della trasmissione dei dati
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
//trasmetti dati
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Ogni byte ha 8 bit e viene controllato bit per bit a partire dal livello più basso
  {
    if (send_data & mask) { //Imposta i livelli alto e basso di SDA_Pin a seconda che ogni bit del byte sia 1 o 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Porta alto il pin clock SCL_Pin per fermare la trasmissione dei dati
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Porta basso il pin clock SCL_Pin per cambiare il SEGNALE di SDA 
  }
}
//************************************************************************
```

Dopo aver caricato il codice di test, la scheda con espressioni facciali mostra questi pattern in ordine e ripete questa sequenza.

![image-20250512160131674](media/A105.png)![image-20250512160135717](media/A106.png)![image-20250512160139283](media/A107.png)