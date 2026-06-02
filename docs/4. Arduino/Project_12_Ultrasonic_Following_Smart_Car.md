# Progetto 12 Auto Intelligente a Inseguimento Ultrasonico

![a3beaada39eb1471b7df6d9788e2bea3](media/A116.png)

### **1. Descrizione**

In questo progetto, cercheremo di rilevare la distanza tra l'auto intelligente 4WD e gli ostacoli davanti tramite un sensore ultrasonico per azionare due motori in modo che l'auto si muova e faccia mostrare alla scheda LED 8\*8 un motivo facciale sorridente.

### **2. Diagramma di Flusso**

![img](media/A117.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Rilevamento</td>
<td>Distanza misurata degli ostacoli frontali</td>
<td>distanza (unità: cm)</td>
</tr>
<tr class="even">
<td>Impostazione</td>
<td>La scheda LED 8*16 mostra un motivo sorridente.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Imposta il servo a 90°</td>
<td></td>
</tr>
<tr class="even">
<td>Condizione</td>
<td>distanza≥20 e distanza≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>Stato</td>
<td>Avanti</td>
<td></td>
</tr>
<tr class="even">
<td>Condizione</td>
<td>distanza＞10 e distanza＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>distanza＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Condizione</td>
<td>fermo</td>
<td></td>
</tr>
<tr class="odd">
<td>Condizione</td>
<td>distanza≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Condizione</td>
<td>Indietro</td>
<td></td>
</tr>
</tbody>
</table>
### **3. Schema di Collegamento**

![568a66655a14dd34afd8cb1e6ae5951c](media/A118.png)

**Collegamenti:**

1). GND, VCC, SDA e SCL della scheda LED 8\*8 sono collegati a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). VCC, Trig, Echo e Gnd del sensore ultrasonico sono collegati a 5V (V), D12 (S), D13 (S) e Gnd (G).

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso è collegato a 5V (V) e il filo arancione è collegato ad A3.

4). L'alimentazione è collegata alla porta BAT.

### **4. Codice di Test**

```c
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 12
 Flowing Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Imposta il pin clock su A5
#define SDA_Pin  A4  //Imposta il pin dati su A4

//Array, usato per memorizzare i dati del motivo, può essere calcolato da soli o ottenuto dallo strumento modulo
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};

const int servopin = A3;//Imposta il pin del servocomando
 
#include "SR04.h" //definisce la libreria di funzioni del sensore ultrasonico
#define TRIG_PIN 12// imposta il segnale del sensore ultrasonico su D12
#define ECHO_PIN 13// imposta il segnale del sensore ultrasonico su D13
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

int left_ctrl = 2;//definisce i pin di controllo direzione del motore gruppo B
int left_pwm = 5;//definisce i pin PWM di controllo del motore gruppo B
int right_ctrl = 4;//definisce i pin di controllo direzione del motore gruppo A
int right_pwm = 6;//definisce i pin PWM di controllo del motore gruppo A

void setup() {
  pinMode(left_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo B come OUTPUT
  pinMode(left_pwm,OUTPUT);//imposta i pin PWM di controllo del motore gruppo B come OUTPUT
  pinMode(right_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo A come OUTPUT
  pinMode(right_pwm,OUTPUT);//imposta i pin PWM di controllo del motore gruppo A come OUTPUT
  pinMode(TRIG_PIN, OUTPUT); //Imposta il pin trig come output
  pinMode(ECHO_PIN, INPUT); //Imposta il pin echo come input
  pinMode(SCL_Pin,OUTPUT);//Imposta il pin clock come output
  pinMode(SDA_Pin,OUTPUT);//Imposta il pin dati come output
  servopulse(servopin,90);//Imposta l'angolo iniziale del servocomando a 90°
  delay(500); //attende 500ms
  matrix_display(smile);  //mostra il motivo dell'espressione sorridente  
}

void loop() {
  distance = sr04.Distance();//la distanza rilevata dal sensore ultrasonico
   if(distance <= 10)//se la distanza è inferiore a 10
  {
    back();//indietro
  }
  else if((distance > 10)&&(distance< 20 ))//se 10<distanza<20
  {
    Stop();//fermo
  }
  else if((distance >= 20)&&(distance <= 50))//se 20≤distanza≤50  
{
    front();//inseguimento
  }
  else//altrimenti
  {
    Stop();//fermo
  }
}

void front()//definisce lo stato di avanzamento
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,100);
}
void back()//definisce lo stato di retromarcia
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
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

//questa funzione è utilizzata per la visualizzazione su matrice di punti
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
//*******************************************************************************
```

### **5.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico, accendere l'alimentazione esterna  
quindi impostare l'interruttore DIP su ON. Impostare il servo a 90°, la smart car si muoverà evitando gli ostacoli e la scheda LED 8X16 mostrerà “smile”.