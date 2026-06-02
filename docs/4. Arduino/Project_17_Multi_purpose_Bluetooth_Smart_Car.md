# Progetto 17 Auto Smart Bluetooth Multiuso

![2c1198e0ebd7c31622b7438469fb572c](media/A138.jpeg)

### **1.Descrizione**

Nei progetti precedenti, l'auto eseguiva solo una singola funzione. Tuttavia, in questa lezione, integreremo tutte le sue funzioni tramite Bluetooth.

### **2.Diagramma di Flusso**

![73f4da1e321bc29282d3b2f5cb3168dd](media/A139.png)

### **3.Diagramma di Collegamento**

![fce8edd349ddbcfe02e6f27feb73e90f](media/A140.png)

1). GND, VCC, SDA e SCL della scheda LED 8\*8 sono collegati rispettivamente a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). RXD, TXD, GND e VCC del modulo Bluetooth sono collegati rispettivamente a TX, RX, G e 5V sullo Shield motore 8833, mentre i pin STATE e BRK del modulo Bluetooth non devono essere collegati.

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso a 5V (V) e il filo arancione a A3.

4). G, V, S1, S2 e S3 del sensore di tracciamento linea sono collegati rispettivamente a G (GND), V (VCC), D11, D7 e D8 della scheda di espansione sensori.

5). VCC, Trig, Echo e Gnd del sensore ad ultrasuoni sono collegati a 5V (V), D12 (S), D13 (S) e Gnd (G).

6). L'alimentazione è collegata alla porta BAT.

### **4.Codice di Test**

<span style="color: rgb(255, 76, 65);">**Nota:** Prima di caricare il codice di test, è necessario rimuovere il modulo Bluetooth, altrimenti il caricamento del codice fallirà. Collegare il modulo Bluetooth dopo aver caricato con successo il codice.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lezione 17
Auto Multifunzionale Bluetooth
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

int L_pin = 11; //definisce il pin del sensore di tracciamento sinistro come D11
int M_pin = 7; //definisce il pin del sensore di tracciamento centrale come D7
int R_pin = 8; //definisce il pin del sensore di tracciamento destro come D8
int L_val, M_val, R_val;

int trigPin = 12; //Pin TRIG collegato a D12
int echoPin = 13; //Pin ECHO collegato a D13
int distance, distance_l, distance_r;

char BLE_val;

void setup() {
  Serial.begin(9600);//Imposta la velocità di trasmissione a 9600
  pinMode(left_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo B come OUTPUT
  pinMode(left_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo B come OUTPUT
  pinMode(right_ctrl,OUTPUT);//imposta i pin di controllo direzione del motore gruppo A come OUTPUT
  pinMode(right_pwm,OUTPUT);//imposta i pin di controllo PWM del motore gruppo A come OUTPUT
  servopulse(servopin,90);//l'angolo del servo è 90 gradi
  delay(300);
  pinMode(L_pin, INPUT); //I pin del sensore di tracciamento sono configurati in modalità input
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(trigPin, OUTPUT); //definisce TRIG come modalità output
  pinMode(echoPin, INPUT); //definisce ECHO come modalità input
  pinMode(SCL_Pin,OUTPUT);// Imposta il pin clock come output
  pinMode(SDA_Pin,OUTPUT);//Imposta il pin dati come output
  matrix_display(clear);
  matrix_display(start01); //visualizza il pattern di espressione start01
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
    
      case  'U':  follow();  //Ricevuto ‘U’, entra in modalità follow
      break; 
      case  'Y':  avoid(); //Ricevuto ‘Y’, entra in modalità evitamento ostacoli  
      break;  
      case  'G':  confinement(); //Ricevuto ‘G’, entra in modalità confinamento
      break;  
      case  'X':  tracking(); //Ricevuto ‘X’, entra in modalità tracciamento
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
    Serial.println(speeds);  //visualizza le informazioni sulla velocità 
    if (speeds < 255) { //fino a 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //regola la velocità di crescita 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Ricevuto 'S', l'auto smette di accelerare
    break;
  }
}
void speeds_d() { //funzione di decelerazione
  while (1) {
    Serial.println(speeds);  //visualizza le informazioni sulla velocità
    if (speeds > 0) { //fino a 0
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //regola la velocità di decelerazione
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Ricevuto 'S', l'auto smette di decelerare
    break;
}
}

int get_distance() {
  int distance = 0;
  digitalWrite(trigPin, LOW);     // invia impulso tramite Trig/Pin, attiva il rilevamento HC-SR04, così da inviare il segnale ultrasonico a livello basso per 2μs
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);    // imposta il segnale ultrasonico a livello alto per 10μs, qui almeno 10μs
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);     // mantiene il segnale ultrasonico a livello basso
  distance = pulseIn(echoPin, HIGH) / 58; // legge il tempo dell'impulso e converte il tempo in distanza (unità: cm)
  Serial.println(distance);        // output valore distanza
  return distance;
}

void follow() {
  servopulse(servopin,90);
  delay(200);
  int follow_flag = 1;
  while (follow_flag) {
    distance = get_distance(); //chiama la funzione di rilevamento
    if (distance < 8 ) {//Se la distanza è inferiore a 8
      car_back();//la macchina va indietro
      matrix_display(clear);
      matrix_display(back); 
    }
    else if (distance >= 8 && distance < 13) { //Se la distanza è maggiore o uguale a 8, ma inferiore a 13
      car_Stop();//ferma
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    else if (distance >= 13 && distance <= 35 ) { //Se la distanza è maggiore o uguale a 13, ma inferiore o uguale a 35
      car_front();//la macchina va avanti
      matrix_display(clear);
      matrix_display(front);
    }
    else {//Se nessuna delle condizioni precedenti
      car_Stop();//ferma
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { //Quando viene ricevuta la S, la macchina si ferma
      follow_flag = 0;
      car_Stop();
    }
  }
}

void avoid() {
  int avoid_flag = 1;
  while (avoid_flag) {
    distance = get_distance(); //Chiama la funzione di rilevamento
    if (distance > 0 && distance < 20) { //Se la distanza è inferiore a 20 e maggiore di 0
      car_Stop();//si ferma
      matrix_display(clear);
      matrix_display(STOP01);   //la matrice a punti mostra un pattern di stop
      delay(1000);
      servopulse(servopin,160); //porta il servocomando oltre 180 gradi
      delay(500);
      distance_l = get_distance(); //ottiene la distanza a sinistra 
      delay(100);
      servopulse(servopin,20); //gira il servocomando a 0 gradi
      delay(500);
      distance_r = get_distance(); //ottiene la distanza a destra
      delay(100);
      if (distance_l > distance_r) { //confronta le distanze, se la sinistra è maggiore della destra
        car_left();  //la macchina gira a sinistra
        matrix_display(clear);
        matrix_display(left);   //la matrice a punti mostra un pattern a sinistra
        servopulse(servopin,90);//il servocomando ritorna a 90 gradi
        delay(700);
        matrix_display(clear);
        matrix_display(front);   //la matrice a punti mostra un pattern avanti
      } 
      else { //Altrimenti se la destra è maggiore della sinistra
        car_right();//la macchina gira a destra
        matrix_display(clear);
        matrix_display(right);   //la matrice a punti mostra un pattern a destra
        servopulse(servopin,90);//il servocomando ritorna a 90 gradi
        delay(700);
        matrix_display(clear);
        matrix_display(front);   //la matrice a punti mostra un pattern avanti
      }
    }
    else { //Quando la distanza frontale è maggiore o uguale a 20cm
      car_front();//la macchina va avanti
      matrix_display(clear);
      matrix_display(front);   //la matrice a punti mostra un pattern avanti

    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') {//Quando viene ricevuta la S, la macchina si ferma
      avoid_flag = 0;
      car_Stop();
    }
  }
}

void confinement() {
  int confinement_flag = 1;
  while (confinement_flag) {
    L_val = digitalRead(L_pin); //leggi il valore del sensore sinistro
    M_val = digitalRead(M_pin); //leggi il valore del sensore centrale
    R_val = digitalRead(R_pin); //leggi il valore del sensore destro
    if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //la macchina va avanti quando non viene rilevata alcuna linea nera
      car_front();
    }
    else { //Altrimenti, se uno qualsiasi dei sensori di tracciamento rileva una linea nera, la macchina va indietro e poi gira a sinistra
      car_back();
      delay(500);
      car_left();
      delay(800);
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { //Quando viene ricevuta la S, la macchina si ferma
      confinement_flag = 0;
      car_Stop();
    }
  }
}

void tracking() {
  int track_flag = 1;
  while (track_flag) {
    L_val = digitalRead(L_pin); //leggi il valore del sensore sinistro
    M_val = digitalRead(M_pin); //leggi il valore del sensore centrale
    R_val = digitalRead(R_pin); //leggi il valore del sensore destro
    if (M_val == 1) { //Linea nera rilevata al centro
      if (L_val == 1 && R_val == 0) { //Se una linea nera è rilevata a sinistra, ma non a destra, gira a sinistra
        car_left();
      }
      else if (L_val == 0 && R_val == 1) { //Altrimenti, se una linea nera è rilevata a destra e non a sinistra, gira a destra
        car_right();
      }
      else { //Altrimenti, la macchina va avanti
        car_front();
      }
    }
    else { //nessuna linea nera rilevata al centro
      if (L_val == 1 && R_val == 0) { //Se una linea nera è rilevata a sinistra, ma non a destra, gira a sinistra
        car_right();
      }
      else if (L_val == 0 && R_val == 1) { //Altrimenti, se una linea nera è rilevata a destra e non a sinistra, gira a destra
        car_right();;
      }
      else { //Altrimenti, ferma la macchina
        car_Stop();
      }
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { //Quando viene ricevuta la S, la macchina si ferma
      track_flag = 0;
      car_Stop();
    }
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

//questa funzione è usata per il display a matrice di punti
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la funzione che chiama la condizione di inizio trasferimento dati
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
//*******************************************************************************
```

### **5. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo lo schema elettrico, alimenta la fonte esterna e poi porta l'interruttore DIP su ON.

Dopo che il modulo Bluetooth è stato collegato all'APP e l'APP mobile si è connessa con successo al Bluetooth, l'auto intelligente può essere controllata tramite l'APP mobile. Possiamo ottenere le funzioni corrispondenti premendo i pulsanti corrispondenti sull'APP mobile.