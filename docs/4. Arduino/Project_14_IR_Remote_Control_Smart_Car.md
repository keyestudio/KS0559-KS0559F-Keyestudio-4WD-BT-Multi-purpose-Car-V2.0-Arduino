# Progetto 14 Auto Intelligente Controllata da Telecomando IR

![ff2fec813f8765e1bcd593b37b9c0a4f](media/A123.jpeg)

### **1.Descrizione**

In questo progetto, realizzeremo un'auto intelligente controllata da telecomando IR e premeremo il pulsante sul telecomando IR per far muovere l'auto.

### **2.Diagramma di Flusso**

![img](media/A124.png)

**La logica specifica dell'auto intelligente controllata da telecomando IR è mostrata di seguito:**

| Configurazione iniziale                   |           | La scheda LED mostra una faccina sorridente      |
| ----------------------------------------- | --------- | ------------------------------------------------- |
| Telecomando                              | Valore tasto | Stato tasto                                       |
| ![img](media/A125.jpg) | FF629D    | Avanti La scheda LED 8*8 mostra l'icona avanti    |
| ![img](media/A126.jpg) | FFA857    | Indietro La scheda LED 8*8 mostra l'icona indietro|
| ![img](media/A127.jpg)                  | FF22DD    | Ruota a sinistra La scheda LED 8*8 mostra l'icona verso sinistra |
| ![img](media/A128.jpg)                  | FFC23D    | Ruota a destra La scheda LED 8*8 mostra l'icona verso destra |
| ![img](media/A129.jpg)                 | FF02FD    | Stop La scheda LED 8*8 mostra “STOP”              |

### **3.Diagramma dei Collegamenti**

![9d8b58dff14fe22b5c87514db944530c](media/A130.png)

1). GND, VCC, SDA e SCL del modulo scheda LED 8\*8 sono collegati rispettivamente a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). Poiché il ricevitore IR è integrato sulla Shield motore 8833, non è necessario alcun cablaggio aggiuntivo. I pin del ricevitore IR sulla scheda 8833 sono rispettivamente G (GND), V (VCC) e D3.

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso è collegato a 5V (V) e il filo arancione è collegato ad A3.

4). L'alimentazione è collegata alla porta BAT
    

### **4.Codice di Test**

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 14
IR remote Control Car
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

#include <Arduino.h>
#include <IRremote.h>//libreria per il controllo remoto IR
int RECV_PIN = 3;//imposta il pin del ricevitore IR su D3
IRrecv irrecv(RECV_PIN);
long irr_val;
decode_results results;

int left_ctrl = 2;//definisce i pin di controllo direzione del motore gruppo B
int left_pwm = 5;//definisce i pin di controllo PWM del motore gruppo B
int right_ctrl = 4;//definisce i pin di controllo direzione del motore gruppo A
int right_pwm = 6;//definisce i pin di controllo PWM del motore gruppo A

#include <Servo.h>
Servo servo_A3;//imposta il pin del servo su A3 

unsigned char data_line = 0;
unsigned char delay_count = 0;

void setup() {
  Serial.begin(9600);//
  // Nel caso in cui il driver di interrupt si blocchi all'avvio, fornire un indizio
  // all'utente su cosa sta succedendo.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Avvia il ricevitore
  Serial.println("Enabled IRin");
  pinMode(left_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo B come OUTPUT
  pinMode(left_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo B come OUTPUT
  pinMode(right_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo A come OUTPUT
  pinMode(right_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo A come OUTPUT
  servo_A3.attach(A3);
  servo_A3.write(90);//l'angolo del servo è 90 gradi
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Imposta il pin clock come output
  pinMode(SDA_Pin,OUTPUT);//Imposta il pin dati come output
  matrix_display(clear);
  matrix_display(start01); //mostra il pattern di espressione start01
}

void loop()
 {
  if (irrecv.decode(&results)) 
 {
    irr_val = results.value;
    Serial.println(irr_val, HEX);//stampa seriale i segnali IR remoti letti 
    switch(irr_val)
    {
      case 0xFF629D : car_front(); //Riceve 0xFF629D, la macchina va avanti
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 0xFFA857 : car_back(); //Riceve 0xFFA857, la macchina va indietro
      matrix_display(clear);
      matrix_display(back); 
      break;
    
      case 0xFF22DD : car_left(); //Riceve 0xFF22DD, la macchina ruota a sinistra
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 0xFFC23D : car_right();//Riceve 0xFFC23D, la macchina ruota a destra
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 0xFF02FD : car_Stop();//Riceve 0xFF02FD, la macchina si ferma
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
    }
        irrecv.resume(); // Riceve il valore successivo
  }
}

void car_front()//definisce lo stato di avanzamento
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,105);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,105);
}
void car_back()//definisce lo stato di retromarcia
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void car_left()//imposta lo stato di svolta a sinistra
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//imposta lo stato di svolta a destra
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

//questa funzione è usata per la visualizzazione su matrice di punti
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la funzione che chiama la condizione di inizio trasferimento dati
  IIC_send(0xc0);  //seleziona l'indirizzo

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
    digitalWrite(SCL_Pin, LOW); //porta basso il pin clock SCL_Pin per cambiare il SEGNALE di SDA 
  }
}
//*******************************************************************************
```

### **5. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico, alimentare la fonte esterna e quindi impostare l'interruttore DIP su ON. Successivamente è possibile utilizzare il telecomando IR per guidare l'auto a muoversi e la scheda LED 8X16 mostrerà il pattern di stato corrispondente.