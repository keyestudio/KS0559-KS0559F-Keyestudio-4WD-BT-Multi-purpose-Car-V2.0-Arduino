# Progetto 10 Auto Intelligente Restrittiva

![644a1976bf17a6b64e0aed1a7240ff1e](media/A108.jpeg)

### **1. Descrizione**

In questo progetto, cerchiamo di combinare le conoscenze di un sensore di tracciamento linea e moduli driver per motori per realizzare un'auto intelligente restrittiva. Nell'esperimento, puntiamo a utilizzare il sensore di tracciamento linea per rilevare se c'è una linea nera intorno all'auto intelligente, e quindi controllare la rotazione dei due motori in base ai risultati del rilevamento in modo da bloccare l'auto intelligente in un cerchio disegnato con linea nera.

### **2. Diagramma di Flusso**

![img](media/A109.png)

La logica specifica dell'auto intelligente 4WD restrittiva è mostrata nella tabella.

![Img](media/A110.png)

### **3. Schema di Collegamento**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A111.png)

G, V, S1, S2 e S3 del sensore di tracciamento linea sono collegati a G (GND), V (VCC), D11, D7 e D8 della scheda di espansione sensori.

L'alimentazione è collegata alla porta BAT.

### **4. Codice di Test**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 10
 Restricting Smart Car
 http://www.keyestudio.com
*/ 
//Dati dal pattern sorriso ottenuti dallo strumento touch
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
  if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //quando non vengono rilevate linee nere, l'auto procede avanti
    Car_front();
  }
  else { //Altrimenti, se uno qualsiasi dei sensori rileva una linea nera, fa retromarcia e gira a sinistra
    Car_back();
    delay(500);
    Car_left();
    delay(500);
  }
}

void Car_front()
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 180);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 180);
}
void Car_back()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 80);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 80);
}
void Car_left()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 150);
}

void Car_Stop()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 0);
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

### **5. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico, accendere l'alimentazione esterna
poi impostare l'interruttore DIP su ON. Posizionare la smart car nel cerchio nero, quindi si muoverà esclusivamente nel cerchio.