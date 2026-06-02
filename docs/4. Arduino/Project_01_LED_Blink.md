# Progetto 1: Lampeggio LED

### **1.Descrizione**

![image-20250508161034535](media/A6.png)

Per principianti e appassionati, il lampeggio del LED è un programma fondamentale. LED, abbreviazione di light emitting diodes, è composto da composti chimici come Ga, As, P, N e così via.

Il LED può lampeggiare in diversi colori modificando il tempo di ritardo nel codice di prova. Quando è sotto controllo, alimentando GND e VCC, il LED si accenderà se il terminale S è a livello alto, altrimenti si spegnerà.

### **2.Specifiche**

- Interfaccia di controllo: porta digitale

- Tensione di lavoro: DC 3.3-5V

- Spaziatura pin: 2.54mm

- Colore display LED: rosso

![image-20250508161015086](media/A7.png)

### **3.Componenti**

|           Scheda di Sviluppo *1           |           Driver Motore 8833 *1           |     Modulo LED Rosso*1     |
| :---------------------------------------: | :---------------------------------------: | :------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             Cavo Dupont 3P*1             |               Cavo USB*1                |                            |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                            |

### **4.Diagramma di Collegamento**

![image-20250508161123490](media/A13.png)

Come si vede dalla figura sopra, il Keyestudio 8833 motor Shield è impilato sulla scheda di sviluppo Keyestudio 4.0.

I pin G, V e S del modulo LED sono collegati rispettivamente a G, 5V e D9 della scheda di espansione.

### **5.Codice di Test**

```c 
//****************************************************************************
/*
keyestudio 4wd BT Car
lezione 1.1
Lampeggio
http://www.keyestudio.com
*/
void setup()
{ 
  pinMode(9, OUTPUT);// inizializza il pin digitale 9 come uscita.
}
    
void loop() // la funzione loop viene eseguita ripetutamente all'infinito
{  
  digitalWrite(9, HIGH); // accende il LED (HIGH è il livello di tensione)
   delay(1000); // aspetta un secondo
   digitalWrite(9, LOW); // spegne il LED portando la tensione a LOW
   delay(1000); // aspetta un secondo
}
//****************************************************************************
```

### **6.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i fili secondo il diagramma di collegamento e utilizzare un cavo USB per collegare il computer e alimentare la scheda. Dopo l'accensione, vedrai il LED collegato al D9 accendersi e spegnersi.

### **7.Spiegazione del Codice**

pinMode(9，OUTPUT) - Questa funzione indica che il pin è INPUT o OUTPUT

digitalWrite(9，HIGH) - Quando il pin è OUTPUT, possiamo impostarlo su HIGH (uscita 5V) o LOW (uscita 0V)

### **8.Esercizio di Estensione**

Abbiamo fatto lampeggiare con successo il LED. Ora, osserviamo cosa succede al LED se modifichiamo il tempo di ritardo.

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lezione 1.2
 ritardo
 http://www.keyestudio.com
*/
void setup()
{  
  // inizializza il pin digitale 11 come uscita.
  pinMode(9, OUTPUT);
}
// la funzione loop viene eseguita ripetutamente all'infinito
void loop()
{ 
  digitalWrite(9, HIGH); // accende il LED (HIGH è il livello di tensione)
  delay(100); // aspetta 0.1 secondi
  digitalWrite(9, LOW); // spegne il LED portando la tensione a LOW
  delay(100); // aspetta 0.1 secondi
}
//*****************************************************************
```

Il risultato del test mostra che il LED lampeggia più velocemente. Pertanto, il tempo di ritardo influisce sulla frequenza di lampeggio del LED.