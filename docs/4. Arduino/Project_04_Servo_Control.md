# Project 4 Controllo Servo

### **1.Descrizione**

![image-20250509084654137](media/A25.png)

Il servo motor è un attuatore rotativo a controllo di posizione. È composto principalmente da un alloggiamento, una scheda circuito, un motore core-less, un ingranaggio e un sensore di posizione. Il suo principio di funzionamento è che il servo riceve il segnale inviato da MCU o ricevitori e produce un segnale di riferimento con un periodo di 20ms e una larghezza di 1,5ms, quindi confronta la tensione di polarizzazione continua acquisita con la tensione del potenziometro e ottiene l'uscita della differenza di tensione.

![image-20250509084710719](media/A26.png)

In generale, il servo ha tre fili di colore marrone, rosso e arancione. Il filo marrone è collegato a terra, quello rosso è il polo positivo e quello arancione è il filo del segnale.

L'angolo di rotazione del servo motor è controllato regolando il duty cycle del segnale PWM (Pulse-Width Modulation). Il ciclo standard del segnale PWM è di 20ms (50Hz). Teoricamente, la larghezza è distribuita tra 1ms e 2ms, ma in realtà è tra 0,5ms e 2,5ms. La larghezza corrisponde all'angolo di rotazione da 0° a 180°. Ma si noti che per motori di marche diverse, lo stesso segnale può avere angoli di rotazione differenti.

![image-20250509084727797](media/A27.png)

Gli angoli corrispondenti del servo sono mostrati di seguito:

![image-20250509084739380](media/A28.png)

### **2.Specifiche**

- Tensione di lavoro: DC 4.8V ~ 6V

- Intervallo angolare operativo: circa 180° (a 500 → 2500 μsec)

- Intervallo larghezza impulso: 500 → 2500 μsec

- Velocità a vuoto: 0.12 ± 0.01 sec / 60 (DC 4.8V) 0.1 ± 0.01 sec / 60 (DC 6V)

- Corrente a vuoto: 200 ± 20mA (DC 4.8V) 220 ± 20mA (DC 6V)

- Coppia di arresto: 1.3 ± 0.01kg · cm (DC 4.8V) 1.5 ± 0.1kg · cm (DC 6V)

- Corrente di arresto: ≦ 850mA (DC 4.8V) ≦ 1000mA (DC 6V)

- Corrente in standby: 3 ± 1mA (DC 4.8V) 4 ± 1mA (DC 6V)

### **3.Componenti**

|                     Development Board *1                     |           8833 Motor Driver *1           |                           Servo*1                            |
| :----------------------------------------------------------: | :--------------------------------------: | :----------------------------------------------------------: |
|           ![img](media/A8.jpg)           | ![img](media/A9.jpg) | ![image-20250509084654137](media/A25.png) |
|                    Supporto Batteria 18650*1                    |               Cavo USB*1                |               Batteria 18650*2 (fornita dall'utente)               |
| ![image-20250509084950601](media/A29.png) |         ![img](media/A12.jpg)         | ![image-20250509085010348](media/A30.png) |

### **4.Diagramma di Collegamento**

![image-20250509085038006](media/A31.png)

Nota sul cablaggio: Il servo è collegato a G (GND), V (VCC) e A3, il filo marrone del servo è collegato a Gnd (G), quello rosso è collegato a 5V (V) e quello arancione è collegato ad A3.

Il servo deve essere collegato a un'alimentazione esterna a causa dell'elevata richiesta di corrente per pilotare il servo. Generalmente, la corrente della scheda di sviluppo non è sufficiente. Se non si collega l'alimentazione esterna, la scheda di sviluppo potrebbe bruciarsi.

### **5.Codice di Test**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 4.1
Servo
http://www.keyestudio.com
*/
#define servoPin A3  //Pin del servo
int pos; //variabile angolo del servo
int pulsewidth; //variabile larghezza impulso del servo

void setup() {
  pinMode(servoPin, OUTPUT);  //imposta il pin del servo come output
  procedure(0); //imposta l'angolo del servo a 0 gradi
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // va da 0 gradi a 180 gradi
    // a passi di 1 grado
    procedure(pos);              // indica al servo di andare alla posizione nella variabile 'pos'
    delay(15);                   // controlla la velocità di rotazione del servo
  }
  for (pos = 180; pos >= 0; pos -= 1) { // va da 180 gradi a 0 gradi
    procedure(pos);              // indica al servo di andare alla posizione nella variabile 'pos'
    delay(15);                    
  }
}

//funzione per controllare il servo
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  //calcola il valore della larghezza dell'impulso
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);   //La durata del livello alto è la larghezza dell'impulso
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));  //il ciclo è di 20ms, il livello basso dura per il resto del tempo
}
//****************************************************************************
```

### **6.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico e alimentare con la fonte esterna. Dopo l'accensione, portare l'interruttore dip su "ON", quindi il servo oscillerà nell'intervallo da 0° a 180°.

### **7.Prassi di Estensione**

Inoltre, è possibile controllare il servo tramite il file di libreria. Si prega di fare riferimento al link: [https://www.arduino.cc/en/Reference/Servo](https://www.arduino.cc/en/Reference/Servo).

![image-20250509085122183](media/A32.png)

```c
//***************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 4.2
 Servo
 http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo;  // crea un oggetto servo per controllare un servo
// sulla maggior parte delle schede possono essere creati dodici oggetti servo
int pos = 0;    // variabile per memorizzare la posizione del servo

void setup() {
  myservo.attach(A3);  // collega il servo al pin A3 all'oggetto servo
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // va da 0 gradi a 180 gradi
    // a passi di 1 grado
    myservo.write(pos);              // indica al servo di andare alla posizione nella variabile 'pos'
    delay(15);                       // attende 15ms affinché il servo raggiunga la posizione
  }
  for (pos = 180; pos >= 0; pos -= 1) { // va da 180 gradi a 0 gradi
    myservo.write(pos);              // indica al servo di andare alla posizione nella variabile 'pos'
    delay(15);                       // attende 15ms affinché il servo raggiunga la posizione
  }
}
//***************************************************************************
```

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico e alimentare con la fonte esterna. Dopo l'accensione, portare l'interruttore dip su "ON", quindi il servo oscillerà nell'intervallo da 0° a 180° anche in questo caso. Di solito lo controlliamo tramite file di libreria.

### **8.Spiegazione del Codice**

Arduino include **\#include \<Servo.h\>** (funzione e dichiarazioni per servo)

Di seguito alcune dichiarazioni comuni della funzione servo:

1). **attach(interfaccia)**——Imposta l'interfaccia del servo

2). **write(angolo)**——Usato per impostare l'angolo di rotazione del servo, l'intervallo dell'angolo impostato è da 0° a 180°

3). **read()**——usato per leggere l'angolo del servo, cioè leggere il valore del comando di “write()”

4). **attached()**——Verifica se il parametro del servo è stato inviato alla sua interfaccia

<span style="color: rgb(255, 76, 65);">Nota:</span> Il formato scritto sopra è “nome variabile servo, dichiarazione specifica（）”, per esempio: myservo.attach(9).