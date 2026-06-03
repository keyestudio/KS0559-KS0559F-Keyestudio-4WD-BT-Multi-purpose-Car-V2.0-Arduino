# Project 2: Pas de LED Helderheid aan

### **1.Beschrijving**

In de vorige les hebben we de LED aan en uit gezet en laten knipperen.

In dit project zullen we de helderheid van de LED regelen via PWM om een ademhalingseffect te simuleren.

PWM is een manier om de analoge uitgang digitaal te regelen. Digitale besturing wordt gebruikt om vierkante golven met verschillende duty cycles te genereren (een signaal dat constant wisselt tussen hoge en lage niveaus) om de analoge uitgang te regelen. Over het algemeen zijn de ingangsspanningen van poorten 0V en 5V.

Wat als 3V vereist is? Of een schakelaar tussen 1V, 3V en 3,5V? We kunnen niet constant weerstanden veranderen. Om deze reden maken we gebruik van PWM.

![](media/A53.gif)

Voor de Arduino digitale poort spanningsuitgang zijn er alleen LOW en HIGH, die overeenkomen met een spanningsuitgang van 0V en 5V. Je kunt LOW definiëren als 0 en HIGH als 1, en de Arduino vijfhonderd 0 of 1 signalen binnen 1s laten uitsturen.

Als alle vijfhonderd outputs 1 zijn, is dat 5V; als ze allemaal 0 zijn, is dat 0V. Als de output op deze manier 010101010101 is, dan is de uitgangspoort 2,5V, wat lijkt op het tonen van een film. De film die we kijken is niet volledig continu. Het geeft eigenlijk 25 beelden per seconde weer. In dit geval kan de mens het niet zien, net zoals bij PWM. Als we een andere spanning willen, moeten we de verhouding van 0 en 1 regelen. Hoe meer 0,1 signalen per tijdseenheid worden uitgezonden, hoe nauwkeuriger de regeling.

PWM is een technologie die digitale methoden gebruikt om analoge grootheden te verkrijgen. Digitale besturing maakt het mogelijk een vierkante golf te vormen, het vierkante golfsignaal heeft slechts twee toestanden: aan en uit (hoog en laag). Een spanning variërend van 0 tot 5V kan worden gesimuleerd door de verhouding van aan- tot uit-tijd te regelen. De tijd dat het aan is (technisch hoog niveau genoemd) wordt pulsbreedte genoemd, daarom wordt PWM ook pulsbreedtemodulatie genoemd.

![](media/A54.png)

De groene verticale balken vertegenwoordigen één periode van de vierkante golf. De waarde die in elke analogWrite(value) wordt geschreven, komt overeen met een percentage, dat ook Duty Cycle wordt genoemd. Dit percentage verwijst naar de verhouding van de tijd die wordt ingenomen door het hoge niveau in een cyclus, dat wil zeggen, duty cycle = hoge niveau tijd / cyclus tijd.

In de afbeelding is van boven naar beneden de duty cycle van de eerste vierkante golf 0%, en de overeenkomstige waarde is 0, en de LED helderheid is het laagst, dat wil zeggen uitgeschakeld. Hoe langer het hoge niveau duurt, hoe helderder het zal zijn. Daarom is de waarde van de laatste duty cycle van 100% 255, en is de LED het helderst. 50% is half zo helder, en 25% is donkerder.

PWM wordt vaker gebruikt om de helderheid van LED-lampen of de draaisnelheid van motoren aan te passen, en de wielsnelheid die door de motoren wordt aangedreven kan gemakkelijk worden geregeld. Bij het spelen met sommige Arduino-robots komen de voordelen van PWM beter tot uiting.

### **2.Componenten**

| Development Board *1      | 8833 Motor Driver *1      | Rode LED Module*1          |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg) | ![img](media/A43.jpg) | ![img](media/A44.jpg) |
| 3P F-F Dupont Wire*1      | USB Kabel*1               |                           |
| ![img](media/A45.jpg) | ![img](media/A46.jpg) |                           |

**3.Aansluitschema**

Houd de bedrading ongewijzigd.

![](media/A47.png)

### **4.Testcode**

Je kunt blokken slepen om te bewerken. De onderstaande blokken zijn ter referentie.

(1).![](media/A55.png)

(2).![](media/A56.png)

(3).![](media/A57.png)

(4).![](media/A58.png)

(5).![](media/A59.png)

(6).![](media/A60.png)

**Volledige Testcode**

![](media/A61.png)

### **5.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind je de bedrading volgens het aansluitschema en gebruik je een USB-kabel om de computer aan te sluiten om het board van stroom te voorzien. Na het inschakelen zul je zien dat de LED geleidelijk verandert van helder naar donker, zoals de ademhaling van een mens, in plaats van direct aan en uit te gaan.

### **6.Uitbreidingsopdracht**

Houd de pinnen van de LED ongewijzigd, verander dan de code (waarden achter wacht)

![](media/A62.png)

Upload de code naar de ontwikkelkaart, vervolgens zal de LED langzamer knipperen.