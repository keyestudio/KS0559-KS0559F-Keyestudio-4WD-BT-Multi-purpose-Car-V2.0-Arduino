# Project 5 Ultrasone Sensor

### **1.Beschrijving**

![image-20250509085643931](media/A33.png)

De HC-SR04 ultrasone sensor gebruikt sonar om de afstand tot een object te bepalen, zoals vleermuizen dat doen. Het biedt uitstekende contactloze afstandsdetectie met hoge nauwkeurigheid en stabiele metingen in een gebruiksvriendelijk pakket. Het wordt geleverd met een ultrasone zender- en ontvangermodules.

![Img](media/A34.png)

De HC-SR04 of ultrasone sensor wordt gebruikt in een breed scala aan elektronica projecten voor het creëren van obstakeldetectie en afstandsmeettoepassingen, evenals diverse andere toepassingen. Hier hebben we een eenvoudige methode gebracht om de afstand te meten met Arduino en een ultrasone sensor en hoe je de ultrasone sensor met Arduino gebruikt.

### **2.Specificatie**

- Werkspanning :+5V DC

- Ruststroom : \<2mA

- Werkstroom: 15mA

- Effectieve hoek: \<15°

- Afstandsbereik : 2cm – 300 cm

- Nauwkeurigheid : 0.3 cm

- Meethoek: 30 graden

- Trigger ingang pulsbreedte: 10uS

![image-20250509085705309](media/A35.png)

### **3.Componenten**

| Development Board *1                                         | 8833 Motor Driver *1                     | Rode LED Module*1         | Ultrasone Sensor*1                                          |
| ------------------------------------------------------------ | ---------------------------------------- | ------------------------ | ------------------------------------------------------------ |
| ![img](media/A8.jpg)                     | ![img](media/A9.jpg) | ![img](media/A10.jpg) | ![image-20250509085643931](media/A33.png) |
| 4P Dupont Draad*1                                             | USB Kabel*1                              | 3P Dupont Draad*1         |                                                              |
| ![image-20250509143737972](media/A36.png) | ![img](media/A12.jpg)                 | ![img](media/A11.jpg) |                                                              |

### **4.Werkingprincipe**

Zoals op de bovenstaande afbeelding te zien is, lijkt het op twee ogen. Eén is de zendkant, de ander is de ontvangkant.

De ultrasone module zal ultrasone golven uitzenden na het triggeren van een signaal. Wanneer de ultrasone golven het object tegenkomen en worden teruggekaatst, geeft de module een echo signaal af, zodat het de afstand tot het object kan bepalen aan de hand van het tijdsverschil tussen het trigger signaal en het echo signaal.

De t is de tijd dat het uitgezonden signaal het obstakel ontmoet en terugkeert. En de voortplantingssnelheid van geluid in de lucht is ongeveer 343m/s, en afstand = snelheid \* tijd. Echter, de ultrasone golf wordt uitgezonden en komt terug, wat 2 keer de afstand is. Daarom moet het gedeeld worden door 2, de afstand gemeten door ultrasone golf = (snelheid \* tijd)/2.

**Gebruiksmethode en schema van ultrasone module:**

1. Gebruik de GPIO pin om een hoog signaal van minstens 10μs te geven aan de Trig pin van SR04, waarmee het getriggerd kan worden om afstand te detecteren.
2. Na het triggeren zal de module automatisch acht 40KHz ultrasone pulsen uitzenden en detecteren of er een signaal terugkomt. Deze stap wordt automatisch door de module uitgevoerd.
3. Als het signaal terugkomt, zal de Echo pin een hoog niveau afgeven, en de duur van het hoge niveau is de tijd vanaf het uitzenden van de ultrasone golf tot de terugkeer.

![image-20250509143833078](media/A37.png)

**Schema van ultrasone sensor:**

![image-20250509154035287](media/A38.png)

### **5.Aansluitschema**

![image-20250509154107103](media/A39.png)

VCC, Trig, Echo en Gnd van de ultrasone sensor zijn verbonden met 5V(V), D12, D13 en Gnd(G)

### **6.Testcode**

```c
//***************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 5.1
 Ultrasonic Sensor
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches;
void setup() {
  //Seriële poort starten
  Serial.begin (9600);
  //Definieer ingangen en uitgangen
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // De sensor wordt geactiveerd door een HIGH-puls van 10 microseconden of langer.
  // Geef vooraf een korte LOW-puls om een schone HIGH-puls te garanderen:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   // Lees het signaal van de sensor: een HIGH-puls waarvan de
  // duur de tijd is (in microseconden) vanaf het verzenden
  // van de ping tot de ontvangst van de echo van een object.
  duration = pulseIn(echoPin, HIGH);
   // Zet de tijd om in een afstand
  cm = (duration/2) / 29.1;     // Delen door 29.1 of vermenigvuldigen met 0.0343
  inches = (duration/2) / 74;   // Delen door 74 of vermenigvuldigen met 0.0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
}
//***************************************************************************
```

**7.Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om de board van stroom te voorzien. Na het inschakelen, open de seriële monitor en stel de baudrate in op 9600.

De gedetecteerde afstand wordt weergegeven, en de eenheden zijn cm en inch. Houd de ultrasonic sensor met de hand tegen, dan wordt de weergegeven afstand kleiner.

![image-20250509154147537](media/A40.png)

**8.Codeuitleg**

**int trigPin-** deze pin is gedefinieerd om ultrasone golven te verzenden, meestal output.

**int echoPin -** deze is gedefinieerd als de pin voor ontvangst, meestal input.

**cm = (duration/2) / 29.1-**

**inches = (duration/2) / 74-**

We kunnen de afstand berekenen met de volgende formule:

afstand = (reistijd/2) x geluidssnelheid

De geluidssnelheid is: 343m/s = 0.0343 cm/us = 1/29.1 cm/us

Of in inches: 13503.9in/s = 0.0135in/us = 1/74in/us

We moeten de reistijd delen door 2 omdat we rekening moeten houden met het feit dat de golf werd verzonden, het object raakte en vervolgens terugkeerde naar de sensor.

**9.Uitbreidingspraktijk**

We hebben zojuist de afstand gemeten die door de ultrasonic wordt weergegeven. Wat dacht je ervan om de LED te besturen met de gemeten afstand? Laten we het proberen en een LED-lichtmodule aansluiten op pin D9.

![image-20250509154232505](media/A41.png)

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 les 5.2
 Ultrasonic LED
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches;

void setup() {
  Serial.begin (9600);  // Seriële poort starten
  pinMode(trigPin, OUTPUT);  // Definieer inputs en outputs
  pinMode(echoPin, INPUT);
}

void loop() 
{
  // De sensor wordt geactiveerd door een HIGH-puls van 10 microseconden of langer.
  // Geef vooraf een korte LOW-puls om een schone HIGH-puls te garanderen:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Lees het signaal van de sensor: een HIGH-puls waarvan de
  // duur de tijd is (in microseconden) vanaf het verzenden
  // van de ping tot de ontvangst van de echo van een object.
  duration = pulseIn(echoPin, HIGH);
  // Zet de tijd om in een afstand
  cm = (duration/2) / 29.1;     // Delen door 29.1 of vermenigvuldigen met 0.0343
  inches = (duration/2) / 74;   // Delen door 74 of vermenigvuldigen met 0.0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
  if (cm>=2 && cm<=10)
  {
    Serial.println("HIGH");
    digitalWrite(9, HIGH);
  }
  else
  {
    Serial.println("LOW");
    digitalWrite(9, LOW);
  }
}
//*****************************************************************
```

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, en sluit vervolgens de computer via een USB-kabel aan om de board van stroom te voorzien. Na het inschakelen, blokkeer de ultrasonic sensor met de hand (de afstand is tussen 2-10cm), en controleer of de LED aan gaat.