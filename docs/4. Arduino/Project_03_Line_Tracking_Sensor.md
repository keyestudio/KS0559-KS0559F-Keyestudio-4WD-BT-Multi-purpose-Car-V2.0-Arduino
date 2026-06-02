# Progetto 3: Sensore di Tracciamento Linea

![](media/A17.png)

### **1. Descrizione**

Il sensore di tracciamento è in realtà un sensore a infrarossi. Il componente utilizzato qui è il tubo a infrarossi TCRT5000. Il suo principio di funzionamento è utilizzare la diversa riflettività della luce infrarossa rispetto ai colori, quindi convertire l'intensità del segnale riflesso in un segnale di corrente.

Durante il processo di rilevamento, il nero è attivo a livello HIGH mentre il bianco è attivo a livello LOW. L'altezza di rilevamento è 0-3 cm.

Il modulo di tracciamento linea a 3 canali Keyestudio ha integrato 3 set di tubi a infrarossi TCRT5000 su una scheda, il che rende più comodo il cablaggio e il controllo.

Ruotando il potenziometro regolabile sul sensore, è possibile regolare la sensibilità di rilevamento del sensore.

### **2. Specifiche**

- Tensione di funzionamento: 3.3-5V (DC)

- Interfaccia: 5PIN

- Segnale di uscita: Segnale digitale

- Altezza di rilevamento: 0-3 cm

![image-20250508163247479](media/A18.png)

<span style="color: rgb(255, 76, 65);">Nota: Prima del test, ruotare il potenziometro sul sensore per regolare la sensibilità di rilevamento. La sensibilità è ottimale quando si regola il LED a una soglia tra acceso e spento.</span> 

### **3. Componenti**

| Scheda di Sviluppo *1                   | Driver Motore 8833 *1                    | Modulo LED Rosso *1       | Sensore di Tracciamento Linea *1 |
| -------------------------------------- | -------------------------------------- | ------------------------ | ------------------------------- |
| ![img](media/A8.jpg)                   | ![img](media/A9.jpg)                    | ![img](media/A10.jpg)    | ![img](media/A19.png)            |
| Cavo Dupont 5P *1                      | Cavo USB *1                            | Cavo Dupont 3P *1        |                                 |
| ![img](media/A20.png)                  | ![img](media/A12.jpg)                   | ![img](media/A11.jpg)    |                                 |

### **4. Schema di Collegamento**

![image-20250508164243044](media/A21.png)

G, V, S1, S2 e S3 del sensore di tracciamento linea sono collegati rispettivamente a G (GND), V (VCC), D11, D7 e D8 della scheda di espansione sensori.

### **5. Codice di Test**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 3.1 
 Line Track sensor
 http://www.keyestudio.com
*/
int L_pin = 11;  //pin del sensore di tracciamento linea sinistro
int M_pin = 7;   //pin del sensore di tracciamento linea centrale
int R_pin = 8;   //pin del sensore di tracciamento linea destro
int val_L,val_R,val_M; // definisci le variabili valore dei tre sensori

void setup()
{
  Serial.begin(9600); // inizializza la comunicazione seriale a 9600 bit al secondo
  pinMode(L_pin,INPUT); // imposta L_pin come ingresso
  pinMode(M_pin,INPUT); // imposta M_pin come ingresso
  pinMode(R_pin,INPUT); // imposta R_pin come ingresso
}

void loop() 
{ 
  val_L = digitalRead(L_pin); // leggi L_pin:
  val_R = digitalRead(R_pin); // leggi R_pin:
  val_M = digitalRead(M_pin); // leggi M_pin:
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500); // ritardo tra le letture per stabilità
}
//****************************************************************************
```

### **6. Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema di collegamento e utilizzare un cavo USB per collegare il computer e alimentare la scheda.

Dopo l'accensione, aprire il monitor seriale e si visualizzerà lo stato dei tre sensori di tracciamento linea. Quando non vengono ricevuti segnali, il valore è 1. Se copriamo il sensore con un foglio bianco, il valore sarà 0.

![image-20250508164424571](media/A22.png)

![image-20250508164453274](media/A23.png)

### **7. Spiegazione del Codice**

Serial.begin(9600) - Inizializza la porta seriale, imposta la velocità di trasmissione a 9600 baud

pinMode - Definisce il pin come modalità input o output

digitalRead - Legge lo stato del pin, che generalmente è livello HIGH o LOW

### **8. Pratica Estesa**

Dopo aver compreso il principio di funzionamento, puoi collegare un LED a D9 per controllare il LED tramite il sensore.

![image-20250508164527429](media/A24.png)

```c
/*
keyestudio 4wd BT Car
lesson 3.2
 Line Track Sensor LED
 http://www.keyestudio.com
*/
int L_pin = 11;  //pin del sensore di tracciamento linea sinistro
int M_pin = 7;  //pin del sensore di tracciamento linea centrale
int R_pin = 8;  //pin del sensore di tracciamento linea destro
int val_L,val_R,val_M;// definisci le variabili dei tre sensori 

void setup()
{
  Serial.begin(9600); // inizializza la comunicazione seriale a 9600 bit al secondo
  pinMode(L_pin,INPUT); // imposta L_pin come input
  pinMode(M_pin,INPUT); // imposta M_pin come input
  pinMode(R_pin,INPUT); // imposta R_pin come input
  pinMode(9, OUTPUT);
}

void loop() 
{ 
  val_L = digitalRead(L_pin);//leggi L_pin:
  val_R = digitalRead(R_pin);//leggi R_pin:
  val_M = digitalRead(M_pin);//leggi M_pin:
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500);// ritardo tra le letture per stabilità
  if ((val_L == LOW) || (val_M == LOW) || (val_R == LOW))//se il sensore di tracciamento linea sinistro rileva segnali
  { 
    Serial.println("HIGH");
    digitalWrite(9, HIGH);//LED acceso
  }
  else//se il sensore di tracciamento linea sinistro non rileva segnali
  { 
    Serial.println("LOW");
    digitalWrite(9, LOW);//LED spento
  }
 }
//****************************************************************************
```

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i fili secondo lo schema di collegamento e usa un cavo USB per collegare il computer e alimentare la scheda.

Dopo l'accensione, avvicina un foglio di carta al sensore, quindi noterai che il LED si accende quando copri il sensore di tracciamento linea.