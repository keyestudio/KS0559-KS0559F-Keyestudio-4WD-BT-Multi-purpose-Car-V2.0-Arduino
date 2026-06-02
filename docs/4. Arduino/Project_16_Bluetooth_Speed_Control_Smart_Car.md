# Progetto 16 Controllo Velocità Bluetooth Smart Car

![](media/A131.jpeg)

### **1.Descrizione**

In questo progetto, utilizzeremo un modulo Bluetooth per regolare la velocità della smart car. Consentiamo di definire velocità variabili e modificarle per cambiare la velocità della smart car.

### **2.Diagramma di Flusso**

![90ab1f7fb1e16ad3c018b1c631e407c3](media/A134.png)

### **3.Diagramma di Collegamento**

![](media/A135.png)

1). GND, VCC, SDA e SCL della scheda LED 8\*8 sono collegati rispettivamente a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). RXD, TXD, GND e VCC del modulo Bluetooth sono collegati rispettivamente a TX, RX, G e 5V sullo Shield motore 8833, mentre i pin STATE e BRK del modulo Bluetooth non devono essere collegati.

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso a 5V (V) e il filo arancione a A3.

4). L'alimentazione è collegata alla porta BAT.

### **4.Codice di Test**

<span style="color: rgb(255, 76, 65);">**Nota:** Prima di caricare il codice di test, è necessario rimuovere il modulo Bluetooth, altrimenti il caricamento del codice fallirà. Collegare il modulo Bluetooth dopo aver caricato con successo il codice.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 16
Bluetooth Speed Control Car
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
unsigned char speed_a[] = 
{0x00,0x40,0x20,0x10,0x08,0x04,0x02,0xff,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00};
unsigned char speed_d[] = 
{0x00,0x02,0x04,0x08,0x10,0x20,0x40,0xff,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00};

int left_ctrl = 2;//definisce i pin di controllo direzione del motore gruppo B
int left_pwm = 5;//definisce i pin di controllo PWM del motore gruppo B
int right_ctrl = 4;//definisce i pin di controllo direzione del motore gruppo A
int right_pwm = 6;//definisce i pin di controllo PWM del motore gruppo A

int speeds = 150; //Imposta la velocità iniziale a 150

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
      case 'F' : car_front(); 
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); 
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); 
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();
      matrix_display(clear);
      matrix_display(STOP01); 
      break;

      case 'a' : speeds_a();
      matrix_display(clear);
      matrix_display(speed_a);  
      break;
     
      case 'd' : speeds_d();
      matrix_display(clear);
      matrix_display(speed_d); 
      break;
    }
}

void car_front()//definisce lo stato di avanzamento
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//definisce lo stato di retromarcia
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//imposta lo stato di svolta a sinistra
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//imposta lo stato di svolta a destra
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//definisce lo stato di stop
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //funzione di accelerazione rapida
  while (1) {
    Serial.println(speeds);  //mostra le informazioni sulla velocità
    if (speeds < 255) { //fino a 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //regola la velocità di crescita
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Riceve 'S', l'auto smette di accelerare
    break;
  }
}
void speeds_d() { //funzione di decelerazione
  while (1) {
    Serial.println(speeds);  //mostra le informazioni sulla velocità
    if (speeds > 0) { //fino a 0
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //regola la velocità di decelerazione
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Riceve 'S', l'auto smette di decelerare
    break;
}
}

void servopulse(int servopin,int myangle)//Angolo di funzionamento del servocomando
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

//questa funzione è usata per la visualizzazione a matrice di punti
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la funzione che richiama la condizione di inizio trasferimento dati
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Ogni byte ha 8 bit e viene controllato bit per bit iniziando dal livello più basso
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
//*******************************************************************************
```

### **5. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, alimenta la fonte di alimentazione esterna e poi porta l'interruttore DIP su ON. Associa l'APP tramite Bluetooth, l'auto intelligente può essere controllata dall'APP per muoversi.

Premi ![049343f587e0e7cf19fe8b665d735321](media/A136.png), l'auto accelererà, premi ![264f77cce6018584b54f46676fee4247](media/A137.png), l'auto rallenterà, e la scheda LED 8\*16 mostrerà il pattern di stato corrispondente dell'auto intelligente.