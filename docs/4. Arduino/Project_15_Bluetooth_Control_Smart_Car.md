# Progetto 15 Auto Intelligente Controllata via Bluetooth

![8abdadfa2fc462bdcc0542df52a793e3](media/A131.jpeg)

### **1.Descrizione**

Abbiamo appreso le conoscenze di base del Bluetooth. In questa lezione, realizzeremo un'auto intelligente controllata via Bluetooth. In questo progetto, consideriamo il telefono cellulare come trasmettitore (host) e l'auto intelligente collegata al modulo Bluetooth BT24 (slave) come ricevitore, utilizzando l'APP mobile per controllare l'auto tramite Bluetooth.

### **2.Pulsanti di Controllo APP**

|                           | Carattere di controllo                                      | Carattere di controllo                                      |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Premuto: F  <br />Rilasciato: S                             | Premi il pulsante, l'auto va avanti; <br />rilascia per fermare |
| ![img](media/A64.jpg) | Premuto: L  <br />Rilasciato: S                             | Premi il pulsante, l'auto gira a sinistra; <br />rilascia per fermare  |
| ![img](media/A65.jpg) | Premuto: R  <br />Rilasciato: S                             | Premi il pulsante, l'auto gira a destra; <br />rilascia per fermare |
| ![img](media/A66.jpg) | Premuto: B  <br />Rilasciato: S                             | Premi il pulsante, l'auto va indietro; <br />rilascia per fermare   |
| ![img](media/A67.jpg) | Premuto: “a”  <br />Rilasciato: “S”                         | Clicca per accelerare (massimo: 255)                         |
| ![img](media/A68.jpg) | Premuto: “d”  <br />Rilasciato: “S”                         | Clicca per rallentare (minimo: 0)                            |
| ![img](media/A69.jpg) | Clicca per avviare la funzione di <br />sensore di gravità del <br />telefono: clicca di nuovo per <br />uscire dal controllo con sensore di gravità |                                                              |
| ![img](media/A70.jpg) | Clicca per inviare “X”, <br />clicca di nuovo per inviare “S” | Avvia la funzione di tracciamento linea; <br />clicca di nuovo per uscire      |
| ![img](media/A71.jpg) | Clicca per inviare “Y”, <br />clicca di nuovo per inviare “S” | Avvia la funzione di evitamento ad ultrasuoni; <br />clicca di nuovo per uscire |
| ![img](media/A72.jpg) | Clicca per inviare “U”, <br />clicca di nuovo per inviare “S” | Avvia la funzione di inseguimento ad ultrasuoni; <br />clicca di nuovo per uscire |
| ![img](media/A73.jpg) | Clicca per inviare “G”, <br />clicca di nuovo per inviare “S” | Avvia la funzione di restrizione; <br />clicca di nuovo per uscire       |

### **3.Diagramma di Flusso**

![img](media/A132.png)

### **4.Diagramma di Collegamento**



![61be6959693b2111639252ea45ec60fc](media/A133.png)

1). GND, VCC, SDA e SCL della scheda LED 8\*8 sono collegati rispettivamente a G (GND), V (VCC), A4 e A5 della scheda di espansione.
    
2). RXD, TXD, GND e VCC del modulo Bluetooth sono collegati rispettivamente a TX, RX, G e 5V sul motor Shield 8833, mentre i pin STATE e BRK del modulo Bluetooth non devono essere collegati.
    
3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso a 5V (V) e il filo arancione ad A3.
    
4). L'alimentazione è collegata alla porta BAT
    

### **5.Codice di Test**

<span style="color: rgb(255, 76, 65);">**Nota:** Prima di caricare il codice di test, è necessario rimuovere il modulo Bluetooth, altrimenti il codice non verrà caricato correttamente. Collegare il modulo Bluetooth dopo aver caricato con successo il codice.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lezione 15
Controllo Bluetooth dell'auto
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Imposta il pin clock su A5
#define SDA_Pin  A4  //Imposta il pin dati su A4
//Array, usato per memorizzare i dati del pattern, può essere calcolato da soli o ottenuto dallo strumento modulo
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//definisce i pin di controllo direzione del motore gruppo B
int left_pwm = 5;//definisce i pin di controllo PWM del motore gruppo B
int right_ctrl = 4;//definisce i pin di controllo direzione del motore gruppo A
int right_pwm = 6;//definisce i pin di controllo PWM del motore gruppo A

const int servopin = A3;//imposta il pin del servo su A3 

char BLE_val;

void setup() {
  Serial.begin(9600);//
  pinMode(left_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo B come OUTPUT
  pinMode(left_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo B come OUTPUT
  pinMode(right_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo A come OUTPUT
  pinMode(right_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo A come OUTPUT
  servopulse(servopin,90);//l'angolo del servo è 90 gradi
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Imposta il pin clock come output
  pinMode(SDA_Pin,OUTPUT);//Imposta il pin dati come output
  matrix_display(clear);
  matrix_display(start01); //mostra il pattern start01
}

void loop() {
   if(Serial.available()>0) {
    BLE_val = Serial.read();
    Serial.println(BLE_val);
  } 
    switch(BLE_val)
    {
      case 'F' : car_front(); //Riceve 'F', l'auto va avanti
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); //Riceve 'B', l'auto va indietro
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); //Riceve 'L', l'auto ruota a sinistra
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();//Riceve 'R', l'auto ruota a destra
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();//Riceve 'S', l'auto si ferma
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
}
}

void car_front()//definisce lo stato di andare avanti
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//definisce lo stato di andare indietro
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//imposta lo stato di sterzata a sinistra
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//imposta lo stato di sterzata a destra
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//definisce lo stato di stop
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//Angolo di rotazione del servomotore
{
  for(int i=0; i<30; i++)
  {
    int pulsewidth = (myangle*11)+500;
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servopin,LOW);
    delay(20-pulsewidth/1000);
  }  
}

//questa funzione è utilizzata per il display a matrice di punti
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la funzione che richiama la condizione di inizio trasferimento dati
  IIC_send(0xc0);  //seleziona indirizzo

  for (int i = 0; i < 16; i++) //i dati del pattern sono 16 byte
  {
    IIC_send(matrix_value[i]); //Trasmette i dati del pattern
  }
  IIC_end();   //Fine trasmissione dati pattern
  IIC_start();
  IIC_send(0x8A);  //Controllo display, seleziona larghezza impulso 4/16
  IIC_end();
}
//Condizioni sotto le quali inizia la trasmissione dati
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Ogni byte ha 8 bit e viene controllato bit per bit partendo dal livello più basso
  {
    if (send_data & mask) { //Imposta i livelli alto e basso di SDA_Pin a seconda che ogni bit del byte sia 1 o 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Porta alto il pin clock SCL_Pin per fermare la trasmissione dati
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //porta basso il pin clock SCL_Pin per cambiare il SEGNALE di SDA 
  }
}
//*******************************************************************************
```

### **6. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, alimenta la scheda con alimentazione esterna e poi porta l'interruttore DIP su ON.

Inserisci il modulo BT e apri il cellulare per connettere il Bluetooth e controllare l'auto intelligente. L'auto si muoverà avanti, indietro, girerà a sinistra e a destra e si fermerà. Inoltre, la scheda LED 8\*8 mostrerà i pattern corrispondenti.