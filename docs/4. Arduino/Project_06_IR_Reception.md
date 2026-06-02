# Progetto 6 Ricezione IR

![9681c7da-a7c9-49ed-ad8c-32e00c6aeb07](media/A42.png)

### **1.Descrizione** 

Non c'è dubbio che il telecomando a infrarossi sia onnipresente nella vita quotidiana. Viene utilizzato per controllare vari elettrodomestici, come TV, stereo, videoregistratori e ricevitori di segnali satellitari. Il telecomando a infrarossi è composto da un sistema di trasmissione a infrarossi e un sistema di ricezione a infrarossi, cioè un telecomando a infrarossi e un modulo ricevitore a infrarossi e un microcontrollore in grado di decodificare.  

![image-20250509154423060](media/A43.png)

Il segnale portante a infrarossi a 38K emesso dal telecomando è codificato dal chip di codifica nel telecomando. È composto da una sezione di codice pilota, codice utente, codice utente inverso, codice dati e codice dati inverso. L'intervallo di tempo dell'impulso viene utilizzato per distinguere se è un segnale 0 o 1 e la codifica è composta da questi segnali 0, 1.

Il codice utente dello stesso telecomando è costante mentre il codice dati può distinguere il tasto.

Quando si preme un tasto del telecomando, il telecomando invia un segnale portante a infrarossi. Quando il ricevitore IR riceve il segnale, il programma decodifica il segnale portante e determina quale tasto è stato premuto. Il MCU decodifica il segnale 01 ricevuto, giudicando così quale tasto è stato premuto dal telecomando.

Il ricevitore a infrarossi che usiamo è un modulo ricevitore a infrarossi. Composto principalmente da una testa ricevente a infrarossi, che è un dispositivo che integra ricezione, amplificazione e demodulazione. Il suo IC interno ha completato la demodulazione e può realizzare dalla ricezione a infrarossi all'uscita ed è compatibile con segnali TTL.

Inoltre, è adatto per telecomandi a infrarossi e trasmissione dati a infrarossi. Il modulo ricevitore a infrarossi realizzato dal ricevitore ha solo tre pin, linea del segnale, VCC e GND. È molto comodo per comunicare con Arduino e altri microcontrollori.

### **2.Specifiche**

- Tensione di funzionamento: 3.3-5V (DC)

- Segnale di uscita: Segnale digitale

- Angolo di ricezione: 90 gradi

- Frequenza: 38kHz

- Distanza di ricezione: 10m

L'immagine mostra il prodotto reale e lo schema elettrico del ricevitore a infrarossi.

![image-20250510082651985](media/A44.png)

### **3.Componenti**

|           Scheda di Sviluppo *1           |           Driver Motore 8833 *1           |     Modulo LED Rosso*1     |
| :---------------------------------------: | :---------------------------------------: | :------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             Cavo Dupont 3P*1             |               Cavo USB*1                |                            |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                            |


Poiché la scheda 8833 integra il ricevitore IR, non necessita di cablaggio. I pin del modulo ricevitore IR sono G (GND), V (VCC) e D3.

### **4.Codice di Test**

```c
//*************************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 6.1
 IR remote
 http://www.keyestudio.com
*/ 
#include <IRremote.h>     //dichiarazione libreria IRremote  
int RECV_PIN = 3;        //definisce il pin del ricevitore IR come D3
IRrecv irrecv(RECV_PIN);   
decode_results results;   // i risultati della decodifica esistono in “results” di “decode_results”
void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Abilita il ricevitore 
}  
  
 void loop() {  
  if (irrecv.decode(&results))//decodifica con successo, riceve un set di segnali a infrarossi  
   {  
     Serial.println(results.value, HEX);//Stampa il valore in esadecimale a 16 bit e riceve il codice 
     irrecv.resume(); // Riceve il valore successivo
   }  
   delay(100);  
 } 
//*************************************************************************************
```

### **5.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico, quindi collegare il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, aprire il monitor seriale e impostare la velocità di trasmissione a 9600.

Prendere il telecomando e inviare il segnale al sensore ricevitore a infrarossi. È possibile vedere il valore del tasto corrispondente; se il tempo di pressione del tasto è troppo lungo, FFFFFFFF tende a generare caratteri illeggibili.

![image-20250510082931375](media/A45.png)

I valori dei tasti del telecomando Keyestudio sono mostrati di seguito.

![image-20250510082942450](media/A46.png)

### **6. Spiegazione del Codice**

**irrecv.enableIRIn():** Dopo aver abilitato la decodifica IR, i segnali IR verranno ricevuti,

**decode():** La funzione “decode()” controllerà continuamente per assicurarsi che la decodifica sia avvenuta con successo.

**irrecv.decode(\&results):** dopo una decodifica riuscita, questa funzione restituirà “true” e conserverà il risultato in “results”. Dopo aver decodificato i segnali IR, eseguire la funzione resume() e continuare a ricevere il segnale successivo.

### **7. Pratica Estesa**

Abbiamo decodificato il valore dei tasti del telecomando IR. Che ne dite di controllare il LED tramite il valore misurato? Potremmo progettare un esperimento.

Collegare un LED a D9, quindi premere i tasti del telecomando per accendere e spegnere il LED.

![image-20250508161123490](media/A13.png)

```c
//*************************************************************************************
/* 
keyestudio 4wd BT Car
lesson 6.2
IR remote LED
http://www.keyestudio.com
*/ 
#include <IRremote.h>
int RECV_PIN = 3;//definisce il pin del ricevitore IR come D3
int LED_PIN = 9;//definisce il pin del LED come pin 9
int a=0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{Serial.begin(9600);
  irrecv.enableIRIn(); //Inizializza il ricevitore IR
  pinMode(LED_PIN,OUTPUT);//imposta il pin 9 del LED come OUTPUT
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    if(results.value==0xFF02FD && (a==0)) //secondo il valore del tasto sopra, premendo “OK” sul telecomando, il LED sarà controllato
    {
      Serial.println("HIGH");
      digitalWrite(LED_PIN,HIGH);//il LED si accenderà
      a=1;
    }
    else if(results.value==0xFF02FD && (a==1)) //premere di nuovo
    {
      Serial.println("LOW");
      digitalWrite(LED_PIN,LOW);//il LED si spegnerà
      a=0;
    }
    irrecv.resume(); // riceve il valore successivo
  }
}
//*************************************************************************************
```

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo lo schema elettrico, quindi collegare il computer tramite un cavo USB per alimentare la scheda. Dopo l'accensione, premendo il tasto "**OK**" sul telecomando si può accendere e spegnere il LED.