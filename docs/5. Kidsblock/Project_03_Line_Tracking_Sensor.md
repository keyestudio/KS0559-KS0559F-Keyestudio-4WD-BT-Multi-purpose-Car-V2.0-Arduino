# Progetto 3: Sensore di Tracciamento Linee

![](media/A63.png)

### **1.Descrizione** 

Il sensore di tracciamento è in realtà un sensore a infrarossi. Il componente utilizzato qui è il tubo a infrarossi TCRT5000. Il suo principio di funzionamento è utilizzare la diversa riflettività della luce infrarossa sui colori, quindi convertire l'intensità del segnale riflesso in un segnale di corrente.

Durante il processo di rilevamento, il nero è attivo a livello HIGH mentre il bianco è attivo a livello LOW. L'altezza di rilevamento è 0-3 cm.

Il modulo di tracciamento lineare a 3 canali Keyestudio ha integrato 3 set di tubi a infrarossi TCRT5000 su una scheda, il che è più comodo per il cablaggio e il controllo.

Ruotando il potenziometro regolabile sul sensore, è possibile regolare la sensibilità di rilevamento del sensore.

### **2.Specifiche**

- Tensione di funzionamento: 3.3-5V (DC)

- Interfaccia: 5PIN

- Segnale di uscita: Segnale digitale

- Altezza di rilevamento: 0-3 cm

![](media/A64.jpeg)

<span style="color: rgb(255, 76, 65);">Nota:</span> Prima del test, ruotare il potenziometro sul sensore per regolare la sensibilità di rilevamento. La sensibilità è ottimale quando si regola il LED a una soglia tra ON e OFF.

### **3.Componenti**

| Scheda di Sviluppo *1     | Driver Motore 8833 *1     | Modulo LED Rosso*1         | Sensore di Tracciamento Linee*1   |
| ------------------------ | ------------------------ | ------------------------ | ------------------------ |
| ![img](media/A65.jpg) | ![img](media/A66.jpg) | ![img](media/A67.jpg) | ![img](media/A68.png) |
| Cavo Dupont 5P*1         | Cavo USB*1              | Cavo Dupont 3P*1        |                          |
| ![img](media/A69.png) | ![img](media/A70.jpg) | ![img](media/A71.jpg) |                          |

### **4.Diagramma di Collegamento**

![](media/A72.png)

G, V, S1, S2 e S3 del sensore di tracciamento linee sono collegati a G (GND), V (VCC), D11, D7 e D8 della scheda di espansione sensori.

### **5.Codice di Test**

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A75.png)

(4).![](media/A76.png)

(5).![](media/A77.png)

**Codice Completo di Test**

![](media/A78.png)

![](media/A79.png)

### **6.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo il diagramma di collegamento e usa un cavo USB per collegare il computer e alimentare la scheda.

Dopo l'accensione, clicca![](media/A80.png)per impostare la velocità di trasmissione a 9600 e vedrai lo stato dei tre sensori di tracciamento linee. Quando non vengono ricevuti segnali, il valore è 1. Se copriamo il sensore con un foglio bianco, il valore sarà 0.

![](media/A81.png)

![](media/A82.png)

### **7.Esercizio di Estensione**

Dopo aver compreso il suo principio di funzionamento, puoi collegare un LED a D9 per controllare il LED tramite il sensore.

![](media/A83.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A84.png)

(4).![](media/A85.png)

(5).![](media/A77.png)

(6).![](media/A86.png)

(7).![](media/A87.png)

**Codice Completo di Test**

![](media/A88.png)

![](media/A89.png)

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo il diagramma di collegamento e usa un cavo USB per collegare il computer e alimentare la scheda.

Dopo l'accensione, avvicina un foglio di carta al sensore, quindi noterai che il LED si accende quando copri il sensore di tracciamento linee.