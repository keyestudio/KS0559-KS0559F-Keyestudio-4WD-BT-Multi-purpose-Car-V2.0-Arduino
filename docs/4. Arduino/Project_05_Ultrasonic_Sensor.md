# Progetto 5 Sensore Ultrasonico

### **1.Descrizione**

![image-20250509085643931](media/A33.png)

Il sensore ultrasonico HC-SR04 utilizza il sonar per determinare la distanza da un oggetto, come fanno i pipistrelli. Offre un'eccellente rilevazione della distanza senza contatto con alta precisione e letture stabili in un pacchetto facile da usare. È completo di moduli trasmettitore e ricevitore ultrasonici.

![Img](media/A34.png)

L'HC-SR04 o sensore ultrasonico viene utilizzato in una vasta gamma di progetti elettronici per creare applicazioni di rilevamento ostacoli e misurazione della distanza, oltre a varie altre applicazioni. Qui abbiamo presentato un metodo semplice per misurare la distanza con Arduino e un sensore ultrasonico e come utilizzare il sensore ultrasonico con Arduino.

### **2.Specifiche**

- Tensione di funzionamento : +5V DC

- Corrente a riposo : \<2mA

- Corrente di funzionamento: 15mA

- Angolo efficace: \<15°

- Intervallo di distanza : 2cm – 300 cm

- Precisione : 0.3 cm

- Angolo di misurazione: 30 gradi

- Larghezza impulso di ingresso Trigger: 10uS

![image-20250509085705309](media/A35.png)

### **3.Componenti**

| Scheda di sviluppo *1                                         | Driver motore 8833 *1                     | Modulo LED Rosso*1         | Sensore Ultrasonico*1                                          |
| ------------------------------------------------------------ | ---------------------------------------- | ------------------------ | ------------------------------------------------------------ |
| ![img](media/A8.jpg)                     | ![img](media/A9.jpg) | ![img](media/A10.jpg) | ![image-20250509085643931](media/A33.png) |
| Cavo Dupont 4P*1                                             | Cavo USB*1                              | Cavo Dupont 3P*1         |                                                              |
| ![image-20250509143737972](media/A36.png) | ![img](media/A12.jpg)                 | ![img](media/A11.jpg) |                                                              |

### **4.Principio di funzionamento**

Come mostrato nell'immagine sopra, è come due occhi. Uno è il trasmettitore, l'altro è il ricevitore.

Il modulo ultrasonico emetterà onde ultrasoniche dopo aver ricevuto un segnale di trigger. Quando le onde ultrasoniche incontrano un oggetto e vengono riflesse, il modulo emette un segnale di eco, così può determinare la distanza dell'oggetto dal tempo di differenza tra il segnale di trigger e il segnale di eco.

t è il tempo che il segnale emesso impiega per incontrare l'ostacolo e tornare indietro. La velocità di propagazione del suono nell'aria è circa 343m/s, e distanza = velocità \* tempo. Tuttavia, l'onda ultrasonica viene emessa e torna indietro, quindi percorre 2 volte la distanza. Pertanto, deve essere divisa per 2, la distanza misurata dall'onda ultrasonica = (velocità \* tempo)/2.

**Metodo d'uso e diagramma del modulo ultrasonico:**

1. Usa il pin GPIO per fornire un segnale alto di almeno 10μs al pin Trig dell'SR04, che può attivarlo per rilevare la distanza.
2. Dopo il trigger, il modulo invierà automaticamente otto impulsi ultrasonici a 40KHz e rileverà se c'è un segnale di ritorno. Questo passaggio sarà completato automaticamente dal modulo.
3. Se il segnale ritorna, il pin Echo emetterà un livello alto, e la durata del livello alto è il tempo dal trasmissione dell'onda ultrasonica al ritorno.

![image-20250509143833078](media/A37.png)

**Schema elettrico del sensore ultrasonico:**

![image-20250509154035287](media/A38.png)

### **5.Diagramma di collegamento**

![image-20250509154107103](media/A39.png)

VCC, Trig, Echo e Gnd del sensore ultrasonico sono collegati rispettivamente a 5V(V), D12, D13 e Gnd(G)

### **6.Codice di test**

```c
//***************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 5.1
 Ultrasonic Sensor
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches;
void setup() {
  //Inizio porta seriale
  Serial.begin (9600);
  //Definisci ingressi e uscite
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

```c
void loop() {
  // Il sensore viene attivato da un impulso HIGH di 10 o più microsecondi.
  // Fornire un breve impulso LOW prima per garantire un impulso HIGH pulito:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   // Leggi il segnale dal sensore: un impulso HIGH la cui
  // durata è il tempo (in microsecondi) dal momento
  // dell'invio del ping alla ricezione del suo eco da un oggetto.
  duration = pulseIn(echoPin, HIGH);
   // Converti il tempo in una distanza
  cm = (duration/2) / 29.1;     // Dividi per 29.1 o moltiplica per 0.0343
  inches = (duration/2) / 74;   // Dividi per 74 o moltiplica per 0.0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
}
//***************************************************************************
```

### **7.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi collega il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, apri il monitor seriale e imposta la velocità di trasmissione a 9600 baud.

La distanza rilevata verrà visualizzata, e l'unità di misura è cm e pollici. Ostacola il sensore ad ultrasuoni con la mano, il valore della distanza visualizzato diminuisce.

![image-20250509154147537](media/A40.png)

### **8.Spiegazione del Codice**

**int trigPin-** questo pin è definito per trasmettere onde ultrasoniche, generalmente in output.

**int echoPin -** questo è definito come il pin di ricezione, generalmente in input.

**cm = (duration/2) / 29.1-**

**inches = (duration/2) / 74-**

Possiamo calcolare la distanza usando la seguente formula:

distanza = (tempo di percorrenza/2) x velocità del suono

La velocità del suono è: 343m/s = 0.0343 cm/us = 1/29.1 cm/us

Oppure in pollici: 13503.9in/s = 0.0135in/us = 1/74in/us

Dobbiamo dividere il tempo di percorrenza per 2 perché dobbiamo considerare che l'onda è stata inviata, ha colpito l'oggetto e poi è tornata indietro al sensore.

### **9.Esercizio di Estensione**

Abbiamo appena misurato la distanza visualizzata dall'ultrasuoni. Che ne dici di controllare il LED con la distanza misurata? Proviamo a collegare un modulo luce LED al pin D9.

![image-20250509154232505](media/A41.png)

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lezione 5.2
 Ultrasonic LED
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches;

void setup() {
  Serial.begin (9600);  //Inizio porta seriale
  pinMode(trigPin, OUTPUT);  //Definisci ingressi e uscite
  pinMode(echoPin, INPUT);
}

void loop() 
{
  // Il sensore viene attivato da un impulso HIGH di 10 o più microsecondi.
  // Fornire un breve impulso LOW prima per garantire un impulso HIGH pulito:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Leggi il segnale dal sensore: un impulso HIGH la cui
  // durata è il tempo (in microsecondi) dal momento
  // dell'invio del ping alla ricezione del suo eco da un oggetto.
  duration = pulseIn(echoPin, HIGH);
  // Converti il tempo in una distanza
  cm = (duration/2) / 29.1;     // Dividi per 29.1 o moltiplica per 0.0343
  inches = (duration/2) / 74;   // Dividi per 74 o moltiplica per 0.0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
  if (cm>=2 && cm<=10)
  {
    Serial.println("HIGH");
    digitalWrite(9, HIGH);
  }
  else
  {
    Serial.println("LOW");
    digitalWrite(9, LOW);
  }
}
//*****************************************************************
```

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi collega il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, blocca il sensore ad ultrasuoni con la mano (la distanza è tra 2-10 cm), quindi verifica se il LED si accende.