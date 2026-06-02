# Progetto 12 Auto Intelligente a Inseguimento Ultrasonico

![](media/A280.png)

### **1.Descrizione**

In questo progetto, cercheremo di rilevare la distanza tra l'auto intelligente 4WD e gli ostacoli davanti tramite un sensore ultrasonico per pilotare due motori in modo che l'auto si muova e faccia mostrare alla scheda LED 8\*8 un motivo facciale sorridente.

### **2.Diagramma di Flusso**

![img](media/A281.png)

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


### **3.Diagramma di Collegamento**

![](media/A282.png)

**Collegamenti:**

1). GND, VCC, SDA e SCL della scheda LED 8\*8 sono collegati a G (GND), V (VCC), A4 e A5 della scheda di espansione.

2). VCC, Trig, Echo e Gnd del sensore ultrasonico sono collegati a 5V (V), D12 (S), D13 (S) e Gnd (G).

3). Il servo è collegato a G, V e A3. Il filo marrone è collegato a Gnd (G), il filo rosso è collegato a 5V (V) e il filo arancione è collegato ad A3.

4). L'alimentazione è collegata alla porta BAT.

### **4.Codice di Test**

Prima di scrivere il codice, è necessario importare i file di libreria del sensore ultrasonico, della scheda LED 8x16 e del servo. I passaggi specifici sono i seguenti:

Clicca ![](media/A29.png) per entrare nell'interfaccia della libreria di estensione di sensori/moduli/componenti, poi cerca il sensore “Ultrasonic” ![](media/A122.png) e cliccalo.

In questo modo, "**Not loaded**" cambia in "**loaded**", indicando che il sensore “**Ultrasonic**” è stato aggiunto con successo.

![Img](media/A283.png)

![](/media/A284.png)

I file di libreria della scheda LED 8x16 e del servo sono aggiunti allo stesso modo del sensore ultrasonico.

Clicca ![](media/A33.png) per tornare all'interfaccia dell'editor di codice, il blocco di istruzioni del sensore “**Ultrasonic**”, del modulo “**Matrix 8\*16 Aip1640**” e del componente “**Servo**” può essere visto nell'area modulo.

![](media/A285.png)

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono per riferimento

(1).![](media/A126.png)

(2).![](media/A286.png)

(3).![](media/A287.png)

(4).![](media/A288.png)

(5).![](media/A268.png)

(6).![](media/A289.png)

(7).![](media/A290.png)

(8).![](media/A291.png)

(9).![](media/A292.png)

**Codice di Test Completo**

![](media/A293.png)

![](media/A294.png)

![](media/A295.png)

### **5.Risultato del Test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i cablaggi secondo il diagramma di collegamento, accendi l'alimentazione esterna e poi porta l'interruttore DIP su ON. Imposta il servo a 90°, l'auto intelligente si muoverà in base agli ostacoli e la scheda LED 8X16 mostrerà un “sorriso”.