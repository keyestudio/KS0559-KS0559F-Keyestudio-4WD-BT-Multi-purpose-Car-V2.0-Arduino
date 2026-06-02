# Progetto 11 Auto Intelligente con Tracciamento Linea

![eff7a15e697e8b78bde391f806ea024d](media/A112.png)

### **1.Descrizione**

Basandoci sul principio di funzionamento del sensore di tracciamento linea, realizziamo un'auto intelligente con tracciamento linea.

In questo progetto, rileviamo se c'è una linea nera sotto l'auto intelligente tramite un sensore di tracciamento linea, e poi controlliamo la rotazione dei due gruppi di motori in base ai risultati della rilevazione in modo da far muovere l'auto intelligente lungo la linea nera.

### **2.Diagramma di Flusso**

![img](media/A113.png)

![Img](media/A114.png)

### **3.Diagramma di Collegamento**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A115.png)

G, V, S1, S2 e S3 del sensore di tracciamento linea sono collegati a G (GND), V (VCC), D11, D7 e D8 della scheda di espansione sensori.

L'alimentazione è collegata alla porta BAT.

### **4.Codice di Test**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lezione 11
 Auto con Tracciamento
 http://www.keyestudio.com
*/ 
//Dati del pattern sorriso ottenuti dallo strumento touch
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //Imposta il pin dati su A4
#define SCL_Pin  A5  //Imposta il pin clock su A5

int left_ctrl = 2;//definisce i pin di controllo direzione del motore gruppo B
int left_pwm = 5;//definisce i pin di controllo PWM del motore gruppo B
int right_ctrl = 4;//definisce i pin di controllo direzione del motore gruppo A
int right_pwm = 6;//definisce i pin di controllo PWM del motore gruppo A
int sensor_L = 11;//definisce il pin del sensore di tracciamento linea sinistro
int sensor_M = 7;//definisce il pin del sensore di tracciamento linea centrale
int sensor_R = 8;//definisce il pin del sensore di tracciamento linea destro
int L_val,M_val,R_val;//definisce queste variabili

void setup() {
  Serial.begin(9600);//avvia il monitor seriale e imposta la velocità a 9600 baud
  pinMode(left_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo B come OUTPUT
  pinMode(left_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo B come OUTPUT
  pinMode(right_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo A come OUTPUT
  pinMode(right_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo A come OUTPUT
  pinMode(sensor_L,INPUT);//imposta i pin del sensore di tracciamento linea sinistro come INPUT
  pinMode(sensor_M,INPUT);//imposta i pin del sensore di tracciamento linea centrale come INPUT
  pinMode(sensor_R,INPUT);//imposta i pin del sensore di tracciamento linea destro come INPUT
  //Imposta i pin come output
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(start01);//Mostra il pattern di avvio
}

void loop() 
{
  tracking(); //esegue il programma principale
}

void tracking()
{
  L_val = digitalRead(sensor_L);//legge il valore del sensore di tracciamento linea sinistro
  M_val = digitalRead(sensor_M);//legge il valore del sensore di tracciamento linea centrale
  R_val = digitalRead(sensor_R);//legge il valore del sensore di tracciamento linea destro

  if(M_val == 1){//se lo stato del sensore centrale è 1, significa che rileva la linea nera

     if (L_val == 1 && R_val == 0) { //Se viene rilevata una linea nera a sinistra, ma non a destra, gira a sinistra
        left();
    }
     else if (L_val == 0 && R_val == 1) { //Altrimenti, se viene rilevata una linea nera a destra e non a sinistra, gira a destra
      right();
    }
     else { //Altrimenti, avanti
      front();
    }
  }
  else { //Nessuna linea nera rilevata al centro
    if (L_val == 1 && R_val == 0) { //Se viene rilevata una linea nera a sinistra, ma non a destra, gira a sinistra
      left();
    }
    else if (L_val == 0 && R_val == 1) { //Altrimenti, se viene rilevata una linea nera a destra e non a sinistra, gira a destra
      right();
    }
    else { //Altrimenti, fermati
      Stop();
    }
  }
}
void front()//definisce lo stato di avanzamento
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void back()//definisce lo stato di retromarcia
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void left()//definisce lo stato di svolta a sinistra
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//definisce lo stato di svolta a destra
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void Stop()//definisce lo stato di stop
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm,0);
}

//questa funzione è usata per il display a matrice di punti
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la funzione che richiama la condizione di inizio trasferimento dati
  IIC_send(0xc0);  //seleziona l'indirizzo

  for (int i = 0; i < 16; i++) //i dati del pattern sono 16 byte
  {
    IIC_send(matrix_value[i]); //Trasmette i dati del pattern
  }
  IIC_end();   //Termina la trasmissione dei dati del pattern
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
    digitalWrite(SCL_Pin, HIGH); //Alza il pin clock SCL_Pin per fermare la trasmissione dati
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Abbassa il pin clock SCL_Pin per cambiare il SEGNALE di SDA 
  }
}
//*************************************************************************
```

### **5. Risultati del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico, alimentare la fonte esterna e quindi impostare l'interruttore DIP su ON. A questo punto l'auto intelligente seguirà le linee.