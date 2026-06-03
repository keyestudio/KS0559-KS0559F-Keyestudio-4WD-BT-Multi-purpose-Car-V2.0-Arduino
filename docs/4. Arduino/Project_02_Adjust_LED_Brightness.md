# Project 2: Pas LED Helderheid Aan

### **1.Beschrijving**

In de vorige les hebben we de LED aan en uit gezet en laten knipperen.

In dit project zullen we de helderheid van de LED regelen via PWM om een ademhalingseffect te simuleren.

PWM is een manier om de analoge uitgang via digitale middelen te regelen. Digitale besturing wordt gebruikt om vierkante golven met verschillende duty cycles te genereren (een signaal dat constant wisselt tussen hoge en lage niveaus) om de analoge uitgang te regelen. Over het algemeen zijn de ingangsspanningen van poorten 0V en 5V.

Wat als 3V vereist is? Of een schakelaar tussen 1V, 3V en 3,5V? We kunnen niet constant weerstanden veranderen. Om deze reden maken we gebruik van PWM.

![bbcfcb9ae56abb7e80ee587246fc4be9](media/A14.gif)

Voor de Arduino digitale poort spanningsuitgang zijn er alleen LOW en HIGH, die overeenkomen met de spanningsuitgang van 0V en 5V. Je kunt LOW definiëren als 0 en HIGH als 1, en de Arduino vijfhonderd 0 of 1 signalen binnen 1s laten uitsturen.

Als alle vijfhonderd outputs 1 zijn, is dat 5V; als ze allemaal 0 zijn, is dat 0V. Als je op deze manier 010101010101 uitstuurt, dan is de uitgangspoort 2,5V, wat lijkt op het tonen van een film. De film die we kijken is niet volledig continu. Het geeft eigenlijk 25 beelden per seconde weer. In dit geval kan de mens het niet zien, net zoals bij PWM. Als we een andere spanning willen, moeten we de verhouding van 0 en 1 regelen. Hoe meer 0,1 signalen per tijdseenheid worden uitgezonden, hoe nauwkeuriger de regeling.

PWM is een technologie die digitale methoden gebruikt om analoge grootheden te verkrijgen. Digitale besturing maakt het mogelijk een vierkante golf te vormen, het vierkante golfsignaal heeft slechts twee toestanden: aan en uit (hoog en laag). Een spanning variërend van 0 tot 5V kan worden gesimuleerd door de verhouding van aan- tot uit-tijd te regelen. De tijd dat het aan is (technisch hoog niveau genoemd) wordt pulsbreedte genoemd, daarom wordt PWM ook pulsbreedtemodulatie genoemd.

De groene verticale balken vertegenwoordigen één periode van de vierkante golf. De waarde die in elke analogWrite(value) wordt geschreven, komt overeen met een percentage, ook wel Duty Cycle genoemd. Dit percentage verwijst naar de verhouding van de tijd die wordt ingenomen door het hoge niveau in een cyclus, dat wil zeggen duty cycle = hoge niveau tijd / cyclus tijd.

In de afbeelding is van boven naar beneden de duty cycle van de eerste vierkante golf 0%, en de bijbehorende waarde is 0, en de LED helderheid is het laagst, dat wil zeggen uitgeschakeld. Hoe langer het hoge niveau duurt, hoe helderder het zal zijn. Daarom is de waarde van de laatste duty cycle van 100% 255, en is de LED het helderst. 50% is half zo helder, en 25% is donkerder.

PWM wordt vaker gebruikt om de helderheid van LED-lampen of de rotatiesnelheid van motoren aan te passen, en de wielsnelheid die door de motoren wordt aangedreven kan gemakkelijk worden geregeld. Bij het spelen met sommige Arduino-robots komen de voordelen van PWM beter tot uiting.

### **2.Componenten**

|           Development Board *1           |           8833 Motor Driver *1           |     Rode LED Module*1     |
| :--------------------------------------: | :--------------------------------------: | :----------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             3P Dupont Draad*1             |               USB Kabel*1                |                          |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         |                          |

### **3.Aansluitschema**

Houd de bedrading ongewijzigd.

![image-20250508161123490](media/A13.png)

### **4.Testcode**

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.1
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Definieer de LED pin op D9
int value;

void setup () {
  pinMode (ledPin, OUTPUT); // initialiseer ledPin als uitgang.
}

void loop () {
  for (value = 0; value <255; value = value + 1) 
  {
    analogWrite (ledPin, value); // LED licht geleidelijk op
    delay (5); // vertraging 5ms
  }
  for (value = 255; value> 0; value = value-1) 
  {
    analogWrite (ledPin, value); // LED gaat geleidelijk uit
    delay (5); // vertraging 5ms
  }
}
//*****************************************************************
```

### **5. Testresultaat**

Nadat de code succesvol is geüpload naar de V4.0 board, verbind je de bedrading volgens het bedradingsschema en gebruik je een USB-kabel om de computer aan te sluiten om de board van stroom te voorzien. Na het inschakelen zul je zien dat de LED geleidelijk verandert van helder naar donker, zoals de ademhaling van een mens, in plaats van direct aan en uit te gaan.

### **6. Code-uitleg**

Als we een bepaalde instructie willen herhalen, kunnen we de for-instructie gebruiken.

Het formaat van de for-instructie wordt hieronder weergegeven:

![image-20250508162458776](media/A15.png)

FOR cyclische volgorde:

Ronde 1: 1 → 2 → 3 → 4

Ronde 2: 2 → 3 → 4

…

Totdat nummer 2 niet meer geldt, is de “for” lus voorbij,

Na het begrijpen van deze volgorde, gaan we terug naar de code:

**for (int value = 0; value \< 255; value=value+1)**

**for (int value = 255; value \>0; value=value-1)**

De twee “for” instructies zorgen ervoor dat value toeneemt van 0 tot 255, daarna afneemt van 255 tot 0, dan weer toeneemt tot 255... oneindig doorgaat.

Er is een nieuwe functie in het volgende ----- analogWrite().

We weten dat een digitale poort slechts twee toestanden heeft: 0 en 1. Dus hoe stuur je een analoge waarde naar een digitale waarde? Hier is deze functie nodig. Laten we het Arduino board bekijken en 6 pinnen vinden die gemarkeerd zijn met “\~” en PWM-signalen kunnen uitsturen.

Functieformaat als volgt:

**analogWrite(pin,value)**

analogWrite() wordt gebruikt om een analoge waarde van 0~255 te schrijven voor een PWM-poort, dus de waarde ligt in het bereik van 0~255. Let op dat je alleen digitale pinnen met PWM-functie kunt schrijven, zoals pin 3, 5, 6, 9, 10, 11.

PWM is een technologie om analoge grootheden te verkrijgen via digitale methode. Digitale besturing vormt een vierkante golf, en het vierkante golfsignaal heeft slechts twee toestanden: aan en uit (dat wil zeggen, hoog of laag niveau). Door de verhouding van de duur van aan en uit te regelen, kan een spanning van 0 tot 5V worden gesimuleerd. De tijd dat het aan is (in academische termen hoog niveau genoemd) wordt pulsbreedte genoemd, dus PWM wordt ook pulsbreedtemodulatie genoemd.

Aan de hand van de volgende vijf vierkante golven leren we meer over PWM.

![image-20250508162529349](media/A16.png)

In bovenstaande afbeelding stelt de groene lijn een periode voor, en de waarde van analogWrite() komt overeen met een percentage dat ook Duty Cycle wordt genoemd. Duty cycle geeft de verhouding aan van de tijd dat het hoge niveau aanwezig is in de cyclus. Van boven naar beneden is de duty cycle van de eerste vierkante golf 0% en de bijbehorende waarde is 0.

De helderheid van de LED is het laagst, dat wil zeggen uit. Hoe langer het hoge niveau duurt, hoe helderder de LED. Daarom is de laatste duty cycle 100%, wat overeenkomt met 255, en is de LED het helderst. En 50% is half zo helder, 25% betekent donkerder.

PWM wordt vaker gebruikt voor het aanpassen van de helderheid van LED’s of de draaisnelheid van motoren.

Het speelt een cruciale rol bij het besturen van slimme robotauto’s. Ik geloof dat je niet kunt wachten om het volgende project te leren.

### **7. Uitbreidingsopdracht**

Laten we de waarde van delay aanpassen en de pin ongewijzigd laten, en vervolgens observeren hoe de LED verandert.

```c
//***********************************************************
/*
 keyestudio 4wd BT Car
 les 2.2
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Definieer de LED-pin op D9
void setup () {
   pinMode(ledPin, OUTPUT); // initialiseer ledPin als uitgang.
}

void loop () {
   for (int value = 0; value <255; value = value + 1) {
     analogWrite (ledPin, value); // LED licht geleidelijk op
     delay (30); // vertraging 30ms
   }
   for (int value = 255; value> 0; value = value-1) {
     analogWrite (ledPin, value); // LED gaat geleidelijk uit
     delay (30); // vertraging 30ms
   }
}
//***********************************************************
```

Upload de code naar de ontwikkelkaart, vervolgens zal de LED langzamer knipperen.