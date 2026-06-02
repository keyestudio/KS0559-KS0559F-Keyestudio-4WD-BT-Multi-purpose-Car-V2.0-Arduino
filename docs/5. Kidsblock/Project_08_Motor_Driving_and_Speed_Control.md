# Progetto 8 Controllo Motore e Velocità

![](media/A205.png)

### **1. Descrizione**

Esistono molti modi per pilotare i motori. La nostra auto utilizza il chip driver motore DRV8833 più comunemente usato, che fornisce una soluzione di pilotaggio elettrico a ponte a due canali per giocattoli, stampanti e altre applicazioni integrate con motori.

Quando impiliamo la scheda di espansione driver sulla scheda di sviluppo 4.0 e accendiamo la BAT, quindi impostiamo l'interruttore DIP sull'estremità ON, l'alimentazione esterna alimenterà contemporaneamente entrambe le schede. Per facilitare le connessioni dei cavi, la scheda di espansione driver è dotata di una porta anti-inversione (PH2.0-2P-3P-4P-5P). È possibile collegare direttamente i motori, l'alimentazione e i moduli sensore alla scheda di espansione driver.

L'interfaccia Bluetooth della scheda di espansione driver è completamente compatibile con il modulo Bluetooth DX-BT24 5.1. Quando si collega il modulo Bluetooth, è sufficiente inserirlo nell'interfaccia corrispondente. Allo stesso tempo, i pin a fila da 2,54 mm sono utilizzati per estrarre alcune porte digitali e analogiche inutilizzate sulla scheda di espansione driver, rendendola accessibile per aggiungere altri sensori e realizzare esperimenti di estensione.

La scheda di espansione può essere collegata a quattro motori DC. Quando il cappuccio jumper è collegato di default, i motori delle porte A e A1 e B e B1 sono collegati in parallelo e hanno la stessa legge di movimento. 8 cappucci jumper possono essere utilizzati per controllare la direzione di rotazione delle 4 interfacce motore.

Ad esempio, quando i 2 cappucci jumper davanti a B1 del motore M1 cambiano da collegamento trasversale a collegamento longitudinale, la direzione di rotazione del motore M1 sarà opposta alla direzione di rotazione originale.

### **2. Specifiche**

- Tensione di ingresso per la logica: DC 5V

- Tensione di ingresso per il pilotaggio: DC 6-9 V

- Corrente di lavoro per la logica: \<36mA

- Corrente di lavoro per il pilotaggio: \<2A

- Massima dissipazione di potenza: 25W（T=75℃）

- Livello di ingresso per il segnale di controllo: livello alto è 2.3V\<Vin\<5V, livello basso è -0.3V\<Vin\<1.5V

- Temperatura di lavoro: -25＋130℃

### **3. Scheda di espansione driver motore Keyestudio 8833**

![](media/A206.png)

**Principio di funzionamento**

Utilizziamo la modalità di collegamento parallelo sullo stesso lato per i quattro motori, che possono essere considerati come due gruppi di motori. Come mostrato nel diagramma di cablaggio, B e B1 sono un gruppo, e A e A1 sono un gruppo.

I motori dello stesso gruppo devono ruotare nella stessa direzione. Se sono diversi, regolare i cappucci jumper corrispondenti accanto al terminale per cambiare la direzione.

Come mostrato di seguito, se le direzioni di A e A1 sono diverse, regolare la direzione dei cappucci jumper fino a quando la direzione di movimento dei motori dello stesso gruppo è coerente.

![](media/A207.png)

Dal diagramma sopra, si sa che il pin di direzione del motore A è D4, il pin di velocità è D6; D2 è il pin di direzione del motore B; e D6 è il pin di velocità.

Il PWM pilota l'auto robot. Il valore PWM è nell'intervallo 0-255. Quando impostiamo la direzione su HIGH, più piccolo è il numero PWM, più veloce è la rotazione del motore.

<table border="1">
<tbody>
<tr class="odd">
<td></td>
<td>D2</td>
<td>D5（PWM）</td>
<td>Motore B（sinistra）</td>
<td>D4</td>
<td>D6（PWM）</td>
<td>Motore A（destra）</td>
</tr>
<tr class="even">
<td>Avanti</td>
<td>HIGH</td>
<td>255-200</td>
<td>Ruota in senso orario</td>
<td>HIGH</td>
<td>255-200</td>
<td>Ruota in senso orario</td>
</tr>
<tr class="odd">
<td>Indietro</td>
<td>LOW</td>
<td>200</td>
<td>Ruota in senso antiorario</td>
<td>LOW</td>
<td>200</td>
<td>Ruota in senso antiorario</td>
</tr>
<tr class="even">
<td>Gira a sinistra</td>
<td>HIGH</td>
<td>255-200</td>
<td>Ruota in senso orario</td>
<td>LOW</td>
<td>200</td>
<td>Ruota in senso antiorario</td>
</tr>
<tr class="odd">
<td>Gira a destra</td>
<td>LOW</td>
<td>200</td>
<td>Ruota in senso antiorario</td>
<td>HIGH</td>
<td>255-200</td>
<td>Ruota in senso orario</td>
</tr>
</tbody>
</table>
### **4. Componenti**

| Scheda di Sviluppo *1      | Driver Motore 8833 *1      | Cavo USB*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A208.jpg) | ![img](media/A209.jpg) | ![img](media/A210.jpg)         |
| Supporto Batteria 18650*1    | Motore*4                   | Batteria 18650 *2（fornita dall'utente） |
| ![img](media/A211.png) | ![img](media/A212.jpg) | ![img](media/A213.png)         |



### **5.Diagramma di Collegamento**

![](media/A214.png)

Collegare l'alimentazione alla porta BAT.

### **6.Codice di Test**

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento

(1).![](media/A126.png)

(2).![](media/A215.png)

(3).![](media/A216.png)

**Codice di Test Completo**

![Img](media/A217.png)

![](media/A218.png)

### **7.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo il diagramma di collegamento, quindi accendere l'alimentazione esterna e impostare l'interruttore DIP su ON, l'auto andrà avanti per 2s, indietro per 2s, girerà a sinistra per 2s e a destra per 2s e si fermerà per 2s.

### **8.Spiegazione del Codice**

Regola la velocità con cui il PWM controlla il motore, collegare nello stesso modo.

**Codice di Test Completo**

![Img](media/A219.png)

![](media/A220.png)

Dopo aver caricato con successo il codice sulla scheda V4.0, collegare i cablaggi secondo il diagramma di collegamento, quindi accendere l'alimentazione esterna e impostare l'interruttore DIP su ON, noterai che la velocità del motore è molto più lenta.

<span style="color: rgb(255, 76, 65);">Nota: </span>La batteria scarica porterà a una velocità del motore più lenta.