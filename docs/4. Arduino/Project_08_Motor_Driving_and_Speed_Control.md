# Progetto 8 Guida del Motore e Controllo della Velocità

![image-20250510090044895](media/A77.png)

### **1.Descrizione**

Esistono molti modi per pilotare i motori. La nostra auto utilizza il chip driver per motori DRV8833 più comunemente usato, che fornisce una soluzione di guida elettrica a ponte a due canali per giocattoli, stampanti e altre applicazioni integrate con motori.

Quando impiliamo lo Shield sulla scheda di sviluppo 4.0 e accendiamo il BAT, quindi impostiamo l'interruttore DIP sull'estremità ON, l'alimentazione esterna alimenterà contemporaneamente le due schede. Per facilitare le connessioni dei cavi, lo Shield è dotato di una porta anti-inversione (PH2.0-2P-3P-4P-5P). Puoi collegare direttamente i motori, l'alimentazione e i moduli sensore allo Shield.

L'interfaccia Bluetooth dello Shield è completamente compatibile con il modulo Bluetooth DX-BT24 5.1. Quando colleghi il modulo Bluetooth, devi solo inserirlo nell'interfaccia corrispondente. Allo stesso tempo, i pin a fila da 2,54 mm sono utilizzati per estrarre alcune porte digitali e analogiche inutilizzate sullo Shield, rendendolo accessibile per aggiungere altri sensori e realizzare esperimenti di estensione.

La scheda di espansione può essere collegata a quattro motori DC. Quando il cappuccio jumper è collegato di default, i motori delle porte A e A1 e B e B1 sono collegati in parallelo e hanno la stessa legge di movimento. 8 cappucci jumper possono essere usati per controllare la direzione di rotazione delle 4 interfacce motore.

Ad esempio, quando i 2 cappucci jumper davanti a B1 del motore M1 cambiano da collegamento trasversale a collegamento longitudinale, la direzione di rotazione del motore M1 sarà opposta alla direzione di rotazione originale.

### **2.Specifiche**

- Tensione di ingresso per la logica: DC 5V

- Tensione di ingresso per la guida: DC 6-9 V

- Corrente di lavoro per la logica: \<36mA

- Corrente di lavoro per la guida: \<2A

- Massima dissipazione di potenza: 25W（T=75℃）

- Livello di ingresso per il segnale di controllo: livello alto è 2.3V\<Vin\<5V, livello basso è -0.3V\<Vin\<1.5V

- Temperatura di lavoro: -25＋130℃

**Scheda di espansione driver motore Keyestudio 8833**

![image-20250510090404192](media/A78.png)

### **3.Principio di Funzionamento**

Utilizziamo la modalità di collegamento parallelo sullo stesso lato per i quattro motori, che possono essere considerati come due gruppi di motori. Come mostrato nel diagramma di cablaggio, B e B1 sono un gruppo, e A e A1 sono un gruppo.

I motori dello stesso gruppo devono ruotare nella stessa direzione. Se sono diversi, regola i cappucci jumper corrispondenti accanto al terminale per cambiare la direzione.

Come mostrato di seguito, se le direzioni di A e A1 sono diverse, regola la direzione dei cappucci jumper finché la direzione di movimento dei motori dello stesso gruppo non è coerente.

![image-20250510090532851](media/A79.png)

Dal diagramma sopra si evince che il pin di direzione del motore A è D4, il pin di velocità è D6; D2 è il pin di direzione del motore B; e D6 è il pin di velocità.

<span style="color:red;">Il PWM guida l'auto robot. Il valore PWM è nell'intervallo 0-255. Quando impostiamo la direzione su HIGH, più piccolo è il numero PWM, più veloce è la rotazione del motore.</span>

|            | D2   | D5（PWM） | Motore B（sinistro） | D4   | D6（PWM） | Motore A（destro）   |
| ---------- | ---- | --------- | -------------------- | ---- | --------- | -------------------- |
| Avanti     | HIGH | 255-200   | Ruota in senso orario | HIGH | 255-200   | Ruota in senso orario |
| Indietro   | LOW  | 200       | Ruota in senso antiorario | LOW  | 200       | Ruota in senso antiorario |
| Svolta a sinistra | HIGH | 255-200   | Ruota in senso orario | LOW  | 200       | Ruota in senso antiorario |
| Svolta a destra | LOW  | 200       | Ruota in senso antiorario | HIGH | 255-200   | Ruota in senso orario |

### **4.Componenti**

| Development Board *1      | 8833 Motor Driver *1      | USB Cable*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A80.jpg) | ![img](media/A81.jpg) | ![img](media/A82.jpg)         |
| 18650 Battery Holder*1    | Motor*4                   | 18650 Battery *2（self-provided） |
| ![img](media/A83.png) | ![img](media/A84.jpg) | ![img](media/A85.png)         |

### **5.Diagramma di Collegamento**

![image-20250510090733191](media/A86.png)

Collegare l'alimentazione alla porta BAT.

### **6.Codice di Test**

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.1
 Motor driver shield
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //definisce i pin di controllo direzione del motore gruppo B
#define ML_PWM 5   //definisce i pin di controllo PWM del motore gruppo B
#define MR_Ctrl 4    //definisce i pin di controllo direzione del motore gruppo A
#define MR_PWM 6   //definisce i pin di controllo PWM del motore gruppo A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//imposta i pin di controllo direzione del motore gruppo B come output
  pinMode(ML_PWM, OUTPUT);//imposta i pin di controllo PWM del motore gruppo B come output
  pinMode(MR_Ctrl, OUTPUT);//imposta i pin di controllo direzione del motore gruppo A come output
  pinMode(MR_PWM, OUTPUT);//imposta i pin di controllo PWM del motore gruppo A come output
}
void loop()
{ 
  //avanti
  digitalWrite(ML_Ctrl,HIGH);//imposta i pin di controllo direzione del motore gruppo B a HIGH
  analogWrite(ML_PWM,55);//imposta la velocità PWM del motore gruppo B a 55
  digitalWrite(MR_Ctrl,HIGH);//imposta i pin di controllo direzione del motore gruppo A a HIGH
  analogWrite(MR_PWM,55);//imposta la velocità PWM del motore gruppo A a 55
  delay(2000);//ritardo di 2000ms
  //indietro
  digitalWrite(ML_Ctrl,LOW);//imposta i pin di controllo direzione del motore gruppo B a livello LOW
  analogWrite(ML_PWM,200);//imposta la velocità PWM del motore gruppo B a 200 
  digitalWrite(MR_Ctrl,LOW);//imposta i pin di controllo direzione del motore gruppo A a livello LOW
  analogWrite(MR_PWM,200);//imposta la velocità PWM del motore gruppo A a 200
  delay(2000);//ritardo di 2000ms
  //sinistra
  digitalWrite(ML_Ctrl,LOW);//imposta i pin di controllo direzione del motore gruppo B a livello LOW
  analogWrite(ML_PWM,200);//imposta la velocità PWM del motore gruppo B a 200 
  digitalWrite(MR_Ctrl,HIGH);//imposta i pin di controllo direzione del motore gruppo A a livello HIGH
  analogWrite(MR_PWM,55);//imposta la velocità PWM del motore gruppo A a 55
  delay(2000);//ritardo di 2000ms
  //destra
  digitalWrite(ML_Ctrl,HIGH);//imposta i pin di controllo direzione del motore gruppo B a livello HIGH
  analogWrite(ML_PWM,55);//imposta la velocità PWM del motore gruppo B a 55 
  digitalWrite(MR_Ctrl,LOW);//imposta i pin di controllo direzione del motore gruppo A a livello LOW
  analogWrite(MR_PWM,200);//imposta la velocità PWM del motore gruppo A a 200
  delay(2000);//ritardo di 2000ms
  //fermo
  digitalWrite(ML_Ctrl, LOW);//imposta i pin di controllo direzione del motore gruppo B a livello LOW
  analogWrite(ML_PWM,0);//imposta la velocità PWM del motore gruppo B a 0
  digitalWrite(MR_Ctrl, LOW);//imposta i pin di controllo direzione del motore gruppo A a livello LOW
  analogWrite(MR_PWM,0);//imposta la velocità PWM del motore gruppo A a 0
  delay(2000);//ritardo di 2000ms
}
//****************************************************************************
```

### **7.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i fili secondo il diagramma di collegamento, quindi accendere l'alimentazione esterna e impostare l'interruttore DIP su ON, la macchina si muoverà in avanti per 2s, indietro per 2s, girerà a sinistra per 2s, a destra per 2s e si fermerà per 2s.

### **8.Spiegazione del Codice**

**digitalWrite(ML\_Ctrl,LOW):** La direzione di rotazione del motore è decisa dal livello alto/basso e i pin che decidono la direzione di rotazione sono pin digitali.

**analogWrite(ML\_PWM,200):** La velocità del motore è regolata tramite PWM, e i pin che decidono la velocità del motore devono essere pin PWM.

### **9.Spiegazione del Codice**

Regola la velocità con cui il PWM controlla il motore, collegalo nello stesso modo.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.2
 Motor driver
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //definisci i pin di controllo della direzione del motore del gruppo B
#define ML_PWM 5   //definisci i pin di controllo PWM del motore del gruppo B
#define MR_Ctrl 4    //definisci i pin di controllo della direzione del motore del gruppo A
#define MR_PWM 6   //definisci i pin di controllo PWM del motore del gruppo A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//imposta i pin di controllo della direzione del motore del gruppo B come output
  pinMode(ML_PWM, OUTPUT);//imposta i pin di controllo PWM del motore del gruppo B come output
  pinMode(MR_Ctrl, OUTPUT);//imposta i pin di controllo della direzione del motore del gruppo A come output
  pinMode(MR_PWM, OUTPUT);//imposta i pin di controllo PWM del motore del gruppo A come output
}
void loop()
{ 
  //avanti
  digitalWrite(ML_Ctrl,HIGH);//imposta i pin di controllo della direzione del motore del gruppo B su HIGH
  analogWrite(ML_PWM,105);//imposta la velocità di controllo PWM del motore del gruppo B a 55
  digitalWrite(MR_Ctrl,HIGH);//imposta i pin di controllo della direzione del motore del gruppo A su HIGH
  analogWrite(MR_PWM,105);//imposta la velocità di controllo PWM del motore del gruppo A a 55
  delay(2000);//ritardo di 2000ms
  //indietro
  digitalWrite(ML_Ctrl,LOW);//imposta i pin di controllo della direzione del motore del gruppo B su livello LOW
  analogWrite(ML_PWM,150);//imposta la velocità di controllo PWM del motore del gruppo B a 200 
  digitalWrite(MR_Ctrl,LOW);//imposta i pin di controllo della direzione del motore del gruppo A su livello LOW
  analogWrite(MR_PWM,150);//imposta la velocità di controllo PWM del motore del gruppo A a 200
  delay(2000);//ritardo di 2000ms
  //sinistra
  digitalWrite(ML_Ctrl,LOW);//imposta i pin di controllo della direzione del motore del gruppo B su livello LOW
  analogWrite(ML_PWM,150);//imposta la velocità di controllo PWM del motore del gruppo B a 200 
  digitalWrite(MR_Ctrl,HIGH);//imposta i pin di controllo della direzione del motore del gruppo A su livello HIGH
  analogWrite(MR_PWM,105);//imposta la velocità di controllo PWM del motore del gruppo A a 200
  delay(2000);//ritardo di 2000ms
  //destra
  digitalWrite(ML_Ctrl,HIGH);//imposta i pin di controllo della direzione del motore del gruppo B su livello HIGH
  analogWrite(ML_PWM,105);//imposta la velocità di controllo PWM del motore del gruppo B a 55 
  digitalWrite(MR_Ctrl,LOW);//imposta i pin di controllo della direzione del motore del gruppo A su livello LOW
  analogWrite(MR_PWM,150);//imposta la velocità di controllo PWM del motore del gruppo A a 200
  delay(2000);//ritardo di 2000ms
  //stop
  digitalWrite(ML_Ctrl, LOW);//imposta i pin di controllo della direzione del motore del gruppo B su livello LOW
  analogWrite(ML_PWM,0);//imposta la velocità di controllo PWM del motore del gruppo B a 0
  digitalWrite(MR_Ctrl, LOW);//imposta i pin di controllo della direzione del motore del gruppo A su livello LOW
  analogWrite(MR_PWM,0);//imposta la velocità di controllo PWM del motore del gruppo A a 0
  delay(2000);//ritardo di 2000ms
}
//************************************************************************
```

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, quindi accendi l'alimentazione esterna e porta l'interruttore DIP su ON, noterai che la velocità del motore è molto più lenta.

<span style="color: rgb(255, 76, 65);">Nota: Una batteria scarica porterà a una velocità del motore più lenta.</span> 