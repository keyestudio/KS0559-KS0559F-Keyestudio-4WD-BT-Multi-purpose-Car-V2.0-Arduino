# Progetto 13 Auto Intelligente con Evitamento Ostacoli a Ultrasuoni

![fd4044796307f709987b9d2e215e0911](media/A119.png)

### **1. Descrizione**

In questo progetto, l'obiettivo è realizzare un'auto intelligente con evitamento ostacoli a ultrasuoni. Utilizzeremo l'ultrasuono per rilevare la distanza dall'ostacolo, che può essere usata per controllare il servo per ruotare e far muovere l'auto. Nel frattempo, la scheda LED 8X16 mostrerà il corrispondente schema di stato.

### **2. Diagramma di Flusso**

![img](media/A120.png)

**La logica specifica dell'auto intelligente con evitamento ostacoli a ultrasuoni è mostrata di seguito:**

![Img](media/A121.png)

![Img](media/A122.png)

### **3. Schema di Collegamento**

![](media/A118.png)

1). GND, VCC, SDA e SCL del modulo scheda LED 8\*8 sono collegati a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). VCC, Trig, Echo e Gnd del sensore a ultrasuoni sono collegati a 5V (V), D12 (S), D13 (S) e Gnd (G).

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso è collegato a 5V (V) e il filo arancione è collegato a A3.

4). L'alimentazione è collegata alla porta BAT.

### **4. Codice di Test**

```c 
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 13
 Avoiding Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Imposta il pin clock su A5
#define SDA_Pin  A4  //Imposta il pin dati su A4
//Array, usato per memorizzare i dati del pattern, può essere calcolato da soli o ottenuto dallo strumento modulo
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//definisce i pin di controllo direzione del motore gruppo B
int left_pwm = 5;//definisce i pin di controllo PWM del motore gruppo B
int right_ctrl = 4;//definisce i pin di controllo direzione del motore gruppo A
int right_pwm = 6;//definisce i pin di controllo PWM del motore gruppo A

#include "SR04.h"//definisce la libreria del sensore a ultrasuoni
#define TRIG_PIN 12// imposta il pin di uscita segnale del sensore a ultrasuoni su D12 
#define ECHO_PIN 13//imposta il pin di ingresso segnale del sensore a ultrasuoni su D13 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance,a1,a2;//definisce tre variabili distanza
const int servopin = A3;//imposta il pin del servo su A3 

void setup() {
  pinMode(left_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo B come OUTPUT
  pinMode(left_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo B come OUTPUT
  pinMode(right_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo A come OUTPUT
  pinMode(right_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo A come OUTPUT
  pinMode(TRIG_PIN, OUTPUT); //Imposta il pin trig come output
  pinMode(ECHO_PIN, INPUT); //Imposta il pin echo come input
  servopulse(servopin,90);//l'angolo del servo è 90 gradi
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Imposta il pin clock come output
  pinMode(SDA_Pin,OUTPUT);//Imposta il pin dati come output
  matrix_display(clear);
}
 
void loop()
 {
  avoid();//esegue il programma principale
}

void avoid()
{
  distance=sr04.Distance(); //ottiene il valore rilevato dal sensore a ultrasuoni 

  if((distance < 20)&&(distance != 0))//se la distanza è maggiore di 0 e minore di 10  

  {
    car_Stop();//ferma
    matrix_display(clear);
    matrix_display(STOP01);//mostra il pattern di stop
    delay(1000);
    servopulse(servopin,160);//il servo ruota a 160°
    delay(500);
    a1=sr04.Distance();//misura la distanza
    delay(100);
    servopulse(servopin,20);//ruota a 20 gradi
    delay(500);
    a2=sr04.Distance();//misura la distanza
    delay(100);
    servopulse(servopin,90);  //Ritorna alla posizione di 90 gradi
    delay(500);
    if(a1 > a2)//confronta la distanza, se la distanza a sinistra è maggiore di quella a destra
    {
      car_left();//gira a sinistra
      matrix_display(clear);
      matrix_display(left);    //mostra il pattern di svolta a sinistra
      servopulse(servopin,90);//il servo ruota a 90 gradi
      delay(700); //gira a sinistra per 700ms
      matrix_display(clear);
      matrix_display(front);  //mostra il pattern avanti
    }
    else//se la distanza a destra è maggiore di quella a sinistra
    {
      car_right();//gira a destra
      matrix_display(clear);
      matrix_display(right);  //mostra il pattern di svolta a destra
      servopulse(servopin,90);//il servo ruota a 90 gradi
      delay(700);
      matrix_display(clear);
      matrix_display(front);  //mostra il pattern avanti
    }
  }
  else//altrimenti
  {
    car_front();//avanza
    matrix_display(clear);
    matrix_display(front);  // mostra il pattern avanti
  }
}

void car_front()//la macchina avanza
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//va indietro
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//la macchina gira a sinistra
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//la macchina gira a destra
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//ferma
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//l'angolo di rotazione del servo
{
  for(int i=0; i<20; i++)
  {
    int pulsewidth = (myangle*11)+500;
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servopin,LOW);
    delay(20-pulsewidth/1000);
  } 
}

//questa funzione è usata per la visualizzazione sulla matrice di punti
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la funzione che chiama la condizione di inizio trasferimento dati
  IIC_send(0xc0);  //seleziona l'indirizzo

  for (int i = 0; i < 16; i++) //i dati del pattern sono 16 byte
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
    digitalWrite(SCL_Pin, HIGH); //Porta alto il pin clock SCL_Pin per fermare la trasmissione dati
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Porta basso il pin clock SCL_Pin per cambiare il SEGNALE di SDA 
  }
}
//*******************************************************************************
```

### **5. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, alimenta la scheda con alimentazione esterna e poi porta l'interruttore DIP su ON.

L'auto intelligente si muove in avanti ed evita automaticamente gli ostacoli. Quando non c'è strada davanti, il servo aziona il sensore ad ultrasuoni per scansionare le distanze a sinistra, centro e destra, e l'auto sterza verso il lato libero. Nel frattempo, la scheda LED 8X16 mostrerà il pattern di stato corrispondente.