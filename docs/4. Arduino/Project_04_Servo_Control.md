# Project 4 Servo Control

### **1.Beschrijving**

![image-20250509084654137](media/A25.png)

Een servomotor is een positioneringsbesturingsrotatie-actuator. Het bestaat voornamelijk uit een behuizing, een printplaat, een kernloze motor, een tandwiel en een positieresensor. Het werkingsprincipe is dat de servo het signaal ontvangt dat door MCU's of ontvangers wordt verzonden en een referentiesignaal produceert met een periode van 20 ms en een breedte van 1,5 ms, vervolgens vergelijkt het de verkregen DC-voorspanningsspanning met de spanning van de potentiometer en verkrijgt het spanningsverschil als uitgang.

![image-20250509084710719](media/A26.png)

Over het algemeen heeft een servo drie draden in bruin, rood en oranje. De bruine draad is de aarde, de rode is de positieve poollijn en de oranje is een signaallijn.

De rotatiehoek van de servomotor wordt geregeld door de duty cycle van het PWM (Pulse-Width Modulation) signaal aan te passen. De standaardcyclus van het PWM-signaal is 20 ms (50 Hz). Theoretisch ligt de breedte tussen 1 ms en 2 ms, maar in de praktijk is het tussen 0,5 ms en 2,5 ms. De breedte komt overeen met de rotatiehoek van 0° tot 180°. Let er echter op dat bij motoren van verschillende merken hetzelfde signaal verschillende rotatiehoeken kan veroorzaken.

![image-20250509084727797](media/A27.png)

De bijbehorende servohoeken worden hieronder weergegeven:

![image-20250509084739380](media/A28.png)

### **2.Specificaties**

- Werkspanning: DC 4,8V ~ 6V

- Werkingshoekbereik: ongeveer 180° (bij 500 → 2500 μsec)

- Pulsbreedtebereik: 500 → 2500 μsec

- Snelheid zonder belasting: 0,12 ± 0,01 sec / 60 (DC 4,8V) 0,1 ± 0,01 sec / 60 (DC 6V)

- Stroom zonder belasting: 200 ± 20mA (DC 4,8V) 220 ± 20mA (DC 6V)

- Stopkoppel: 1,3 ± 0,01 kg·cm (DC 4,8V) 1,5 ± 0,1 kg·cm (DC 6V)

- Stopstroom: ≦ 850mA (DC 4,8V) ≦ 1000mA (DC 6V)

- Stand-by stroom: 3 ± 1mA (DC 4,8V) 4 ± 1mA (DC 6V)

### **3.Componenten**

|                     Development Board *1                     |           8833 Motor Driver *1           |                           Servo*1                            |
| :----------------------------------------------------------: | :--------------------------------------: | :----------------------------------------------------------: |
|           ![img](media/A8.jpg)           | ![img](media/A9.jpg) | ![image-20250509084654137](media/A25.png) |
|                    18650 Battery Holder*1                    |               USB Cable*1                |               18650 Battery*2（zelf geleverd）               |
| ![image-20250509084950601](media/A29.png) |         ![img](media/A12.jpg)         | ![image-20250509085010348](media/A30.png) |

### **4.Aansluitschema**

![image-20250509085038006](media/A31.png)

Aansluitnotitie: De servo is verbonden met G (GND), V (VCC) en A3, de bruine draad van de servo is verbonden met Gnd (G), de rode is verbonden met 5V (V) en de oranje is aangesloten op A3.

De servo moet worden aangesloten op een externe voeding vanwege de hoge stroomvraag voor het aansturen van de servo. Over het algemeen is de stroom van het development board niet groot genoeg. Zonder aansluiting op externe voeding kan het development board doorbranden.

### **5.Testcode**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
les 4.1
Servo
http://www.keyestudio.com
*/
#define servoPin A3  //servo Pin
int pos; //de hoekvariabele van de servo
int pulsewidth; //pulsbreedtevariabele van de servo

void setup() {
  pinMode(servoPin, OUTPUT);  //zet de pinnen van de servo op output
  procedure(0); //zet de hoek van de servo op 0 graden
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // gaat van 0 graden tot 180 graden
    // in stappen van 1 graad
    procedure(pos);              // vertel de servo om naar positie in variabele 'pos' te gaan
    delay(15);                   // controleer de rotatiesnelheid van de servo
  }
  for (pos = 180; pos >= 0; pos -= 1) { // gaat van 180 graden tot 0 graden
    procedure(pos);              // vertel de servo om naar positie in variabele 'pos' te gaan
    delay(15);                    
  }
}

//functie om servo te besturen
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  //bereken de waarde van pulsbreedte
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);   //De duur van het hoge niveau is pulsbreedte
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));  //de cyclus is 20ms, het lage niveau duurt de rest van de tijd
}
//****************************************************************************
```

### **6. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema en zet de externe voeding aan. Na het inschakelen, zet de dip switch op de "ON" stand, dan zal de servo zwaaien in het bereik van 0° tot 180°.

### **7. Uitbreidingspraktijk**

Bovendien kunnen we de servo besturen via een bibliotheekbestand. Raadpleeg de link: [https://www.arduino.cc/en/Reference/Servo](https://www.arduino.cc/en/Reference/Servo).

![image-20250509085122183](media/A32.png)

```c
//***************************************************************************
/*
 keyestudio 4wd BT Car
 les 4.2
 Servo
 http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo;  // maak een servo-object aan om een servo te besturen
// op de meeste boards kunnen twaalf servo-objecten worden aangemaakt
int pos = 0;    // variabele om de servo-positie op te slaan

void setup() {
  myservo.attach(A3);  // koppelt de servo op pin A3 aan het servo-object
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // gaat van 0 graden tot 180 graden
    // in stappen van 1 graad
    myservo.write(pos);              // vertel de servo om naar positie in variabele 'pos' te gaan
    delay(15);                       // wacht 15ms tot de servo de positie bereikt
  }
  for (pos = 180; pos >= 0; pos -= 1) { // gaat van 180 graden tot 0 graden
    myservo.write(pos);              // vertel de servo om naar positie in variabele 'pos' te gaan
    delay(15);                       // wacht 15ms tot de servo de positie bereikt
  }
}
//***************************************************************************
```

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het bedradingsschema en zet de externe voeding aan. Na het inschakelen, zet de dip switch op de "ON" stand, dan zal de servo ook zwaaien in het bereik van 0° tot 180°. We besturen het meestal via een bibliotheekbestand.

### **8. Code-uitleg**

Arduino wordt geleverd met **\#include \<Servo.h\>** (servo functie en instructie)

De volgende zijn enkele veelvoorkomende instructies van de servo functie:

1). **attach(interface)**——Stel de interface van de servo in

2). **write(angle)**——Wordt gebruikt om de rotatiehoek van de servo in te stellen, en het ingestelde hoekbereik is van 0° tot 180°

3). **read()**——wordt gebruikt om de hoek van de servo te lezen, namelijk het uitlezen van de opdrachtwaarde van “write()”

4). **attached()**——Bepaalt of de parameter van de servo naar zijn interface is gestuurd

<span style="color: rgb(255, 76, 65);">Opmerking:</span> Het bovenstaande schrijfformaat is “servo variabelenaam, specifieke instructie()”, bijvoorbeeld: myservo.attach(9).