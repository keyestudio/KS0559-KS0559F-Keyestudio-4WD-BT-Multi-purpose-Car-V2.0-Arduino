# Progetto 1 LED Blink

### **1.Descrizione**

![](media/A40.jpeg)

Per principianti e appassionati, LED Blink è un programma fondamentale. LED, abbreviazione di light emitting diodes, è composto da composti chimici come Ga, As, P, N e così via.

Il LED può lampeggiare in diversi colori modificando il tempo di ritardo nel codice di prova. Quando è sotto controllo, alimentando GND e VCC, il LED si accenderà se il terminale S è a livello alto, altrimenti si spegnerà.

### **2.Specifiche**

- Interfaccia di controllo: porta digitale

- Tensione di lavoro: DC 3.3-5V

- Spaziatura pin: 2.54mm

- Colore display LED: rosso

![](media/A41.png)

### **3.Componenti**

| Scheda di sviluppo *1      | Driver motore 8833 *1      | Modulo LED rosso*1          |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg) | ![img](media/A43.jpg) | ![img](media/A44.jpg) |
| Cavo Dupont 3P F-F*1      | Cavo USB*1               |                           |
| ![img](media/A45.jpg) | ![img](media/A46.jpg) |                           |

### **4.Diagramma di collegamento**

![](media/A47.png)

Come si vede dalla figura sopra, la scheda di espansione driver motore Keyestudio 8833 è impilata sulla scheda di sviluppo Keyestudio 4.0.

I pin G, V e S del modulo LED sono collegati rispettivamente a G, 5V e D9 della scheda di espansione.

### **5.Codice di prova**

Puoi trascinare i blocchi per modificare. I blocchi elencati di seguito sono a titolo di riferimento.

(1).![](media/A48.png)

(2).![](media/A49.png)

(3).![](media/A50.png)

**Codice di prova completo**

![](media/A51.png)

### **6.Risultato del test**

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i fili secondo il diagramma di collegamento e usa un cavo USB per collegare il computer e alimentare la scheda. Dopo l'accensione, vedrai il LED collegato al D9 accendersi e spegnersi.

### **7.Prassi di estensione**

Successivamente, vediamo come cambiare la frequenza del lampeggio del LED modificando il tempo di attesa.

![](media/A52.png)

Dopo aver caricato con successo il codice sulla scheda V4.0, collega i fili secondo il diagramma di collegamento e usa un cavo USB per collegare il computer e alimentare la scheda. Il risultato del test mostra che il LED lampeggia più velocemente.