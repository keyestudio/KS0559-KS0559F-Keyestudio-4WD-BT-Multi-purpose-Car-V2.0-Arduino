# Project 8 Motorbesturing en Snelheidsregeling

![image-20250510090044895](media/A77.png)

### **1.Beschrijving**

Er zijn veel manieren om motoren aan te sturen. Onze auto gebruikt de meest gebruikte DRV8833 motor driver chip, die een tweekanaals brug elektrische aandrijvingsoplossing biedt voor speelgoed, printers en andere geïntegreerde motor toepassingen.

Wanneer we de Shield op de 4.0 ontwikkelbord stapelen en de BAT inschakelen, en vervolgens de DIP-schakelaar op de ON-stand zetten, zal de externe voeding beide borden tegelijkertijd van stroom voorzien. Om het aansluiten van bedrading te vergemakkelijken, is de Shield voorzien van een anti-omkeerpoort (PH2.0-2P-3P-4P-5P). Je kunt de motoren, voeding en sensormodules direct op de Shield aansluiten.

De Bluetooth-interface van de Shield is volledig compatibel met de DX-BT24 5.1 Bluetooth-module. Bij het aansluiten van de Bluetooth-module hoef je deze alleen maar in de overeenkomstige interface te pluggen. Tegelijkertijd worden 2.54 rijpinnen gebruikt om enkele ongebruikte digitale en analoge poorten op de Shield uit te voeren, waardoor het mogelijk is om andere sensoren toe te voegen en uitbreidingsproeven uit te voeren.

De uitbreidingskaart kan worden aangesloten op vier DC-motoren. Wanneer de jumperkap standaard is aangesloten, zijn de motoren van poorten A en A1 en B en B1 parallel geschakeld en volgen ze dezelfde bewegingswet. 8 jumperkappen kunnen worden gebruikt om de draairichting van de 4 motorinterfaces te regelen.

Bijvoorbeeld, wanneer de 2 jumperkappen voor B1 van de M1-motor veranderen van dwarsverbinding naar lengteverbinding, zal de draairichting van de M1-motor tegengesteld zijn aan de oorspronkelijke draairichting.

### **2.Specificatie**

- Ingangsspanning voor logica: DC 5V

- Ingangsspanning voor aandrijving: DC 6-9 V

- Werkstroom voor logica: \<36mA

- Werkstroom voor aandrijving: \<2A

- Maximale vermogensafgifte: 25W（T=75℃）

- Ingangsniveau voor besturingssignaal: hoog niveau is 2.3V\<Vin\<5V, laag niveau is -0.3V\<Vin\<1.5V

- Werktemperatuur: -25＋130℃

**Keyestudio 8833 motor driver uitbreidingskaart**

![image-20250510090404192](media/A78.png)

### **3.Werkingsprincipe**

We gebruiken dezelfde zijde parallelle aansluitingsmodus voor de vier motoren, die kan worden beschouwd als twee groepen motoren. Zoals te zien is in het bedradingsschema, vormen B en B1 een groep, en A en A1 een groep.

De motoren in dezelfde groep moeten in dezelfde richting draaien. Als ze verschillend zijn, pas dan de overeenkomstige jumperkappen naast de terminal aan om de richting te wijzigen.

Zoals hieronder getoond, als de richtingen van A en A1 verschillend zijn, pas dan de richting van de jumperkappen aan totdat de bewegingsrichting van de motoren in dezelfde groep consistent is.

![image-20250510090532851](media/A79.png)

Uit bovenstaande afbeelding blijkt dat de richtingspin van motor A D4 is, de snelheids pin is D6; D2 is de richtingspin van motor B; en D6 is de snelheids pin.

<span style="color:red;">PWM stuurt de robotauto aan. De PWM-waarde ligt in het bereik van 0-255. Wanneer we de richting op HIGH zetten, geldt: hoe kleiner het PWM-getal, hoe sneller de motor draait.</span>

|            | D2   | D5（PWM） | B Motor（ links）     | D4   | D6（PWM） | A Motor（rechts）     |
| ---------- | ---- | --------- | -------------------- | ---- | --------- | -------------------- |
| Vooruit    | HIGH | 255-200   | Draait met de klok mee | HIGH | 255-200   | Draait met de klok mee |
| Achteruit  | LOW  | 200       | Draait tegen de klok in | LOW  | 200       | Draait tegen de klok in |
| Links af   | HIGH | 255-200   | Draait met de klok mee | LOW  | 200       | Draait tegen de klok in |
| Rechts af  | LOW  | 200       | Draait tegen de klok in | HIGH | 255-200   | Draait met de klok mee |

### **4.Componenten**

| Development Board *1      | 8833 Motor Driver *1      | USB-kabel*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A80.jpg) | ![img](media/A81.jpg) | ![img](media/A82.jpg)         |
| 18650 Batterijhouder*1    | Motor*4                   | 18650 Batterij *2 (zelf mee te brengen) |
| ![img](media/A83.png) | ![img](media/A84.jpg) | ![img](media/A85.png)         |

### **5. Aansluitschema**

![image-20250510090733191](media/A86.png)

Sluit de voeding aan op de BAT-poort.

### **6. Testcode**

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.1
 Motor driver shield
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //definieer de richtingsbesturingspinnen van motor groep B
#define ML_PWM 5   //definieer de PWM-besturingspinnen van motor groep B
#define MR_Ctrl 4    //definieer de richtingsbesturingspinnen van motor groep A
#define MR_PWM 6   //definieer de PWM-besturingspinnen van motor groep A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//zet richtingsbesturingspinnen van motor groep B als output
  pinMode(ML_PWM, OUTPUT);//zet PWM-besturingspinnen van motor groep B als output
  pinMode(MR_Ctrl, OUTPUT);//zet richtingsbesturingspinnen van motor groep A als output
  pinMode(MR_PWM, OUTPUT);//zet PWM-besturingspinnen van motor groep A als output
}
void loop()
{ 
  //vooruit
  digitalWrite(ML_Ctrl,HIGH);//zet de richtingsbesturingspinnen van motor groep B op HIGH
  analogWrite(ML_PWM,55);//zet de PWM-snelheid van motor groep B op 55
  digitalWrite(MR_Ctrl,HIGH);//zet de richtingsbesturingspinnen van motor groep A op HIGH
  analogWrite(MR_PWM,55);//zet de PWM-snelheid van motor groep A op 55
  delay(2000);//wacht 2000ms
  //achteruit
  digitalWrite(ML_Ctrl,LOW);//zet de richtingsbesturingspinnen van motor groep B op LOW
  analogWrite(ML_PWM,200);//zet de PWM-snelheid van motor groep B op 200 
  digitalWrite(MR_Ctrl,LOW);//zet de richtingsbesturingspinnen van motor groep A op LOW
  analogWrite(MR_PWM,200);//zet de PWM-snelheid van motor groep A op 200
  delay(2000);//wacht 2000ms
  //links
  digitalWrite(ML_Ctrl,LOW);//zet de richtingsbesturingspinnen van motor groep B op LOW
  analogWrite(ML_PWM,200);//zet de PWM-snelheid van motor groep B op 200 
  digitalWrite(MR_Ctrl,HIGH);//zet de richtingsbesturingspinnen van motor groep A op HIGH
  analogWrite(MR_PWM,55);//zet de PWM-snelheid van motor groep A op 55
  delay(2000);//wacht 2000ms
  //rechts
  digitalWrite(ML_Ctrl,HIGH);//zet de richtingsbesturingspinnen van motor groep B op HIGH
  analogWrite(ML_PWM,55);//zet de PWM-snelheid van motor groep B op 55 
  digitalWrite(MR_Ctrl,LOW);//zet de richtingsbesturingspinnen van motor groep A op LOW
  analogWrite(MR_PWM,200);//zet de PWM-snelheid van motor groep A op 200
  delay(2000);//wacht 2000ms
  //stop
  digitalWrite(ML_Ctrl, LOW);//zet de richtingsbesturingspinnen van motor groep B op LOW
  analogWrite(ML_PWM,0);//zet de PWM-snelheid van motor groep B op 0
  digitalWrite(MR_Ctrl, LOW);//zet de richtingsbesturingspinnen van motor groep A op LOW
  analogWrite(MR_PWM,0);//zet de PWM-snelheid van motor groep A op 0
  delay(2000);//wacht 2000ms
}
//****************************************************************************
```

### **7. Testresultaat**

Na het succesvol uploaden van de code naar de V4.0 board, verbind de bedrading volgens het aansluitschema, zet vervolgens de externe voeding aan en zet de DIP-switch op ON, de auto rijdt 2 seconden vooruit, 2 seconden achteruit, 2 seconden naar links, 2 seconden naar rechts en stopt dan 2 seconden.

### **8. Code-uitleg**

**digitalWrite(ML\_Ctrl,LOW):** De draairichting van de motor wordt bepaald door het hoge/lage niveau en de pinnen die de draairichting bepalen zijn digitale pinnen.

**analogWrite(ML\_PWM,200):** De snelheid van de motor wordt geregeld door PWM, en de pinnen die de motorsnelheid bepalen moeten PWM-pinnen zijn.

### **9. Code-uitleg**

Pas de snelheid aan waarmee PWM de motor aanstuurt, sluit op dezelfde manier aan.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
 les 8.2
 Motor driver
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //definieer de richtingsbesturingspinnen van motor groep B
#define ML_PWM 5   //definieer de PWM-besturingspinnen van motor groep B
#define MR_Ctrl 4    //definieer de richtingsbesturingspinnen van motor groep A
#define MR_PWM 6   //definieer de PWM-besturingspinnen van motor groep A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//zet richtingsbesturingspinnen van motor groep B als output
  pinMode(ML_PWM, OUTPUT);//zet PWM-besturingspinnen van motor groep B als output
  pinMode(MR_Ctrl, OUTPUT);//zet richtingsbesturingspinnen van motor groep A als output
  pinMode(MR_PWM, OUTPUT);//zet PWM-besturingspinnen van motor groep A als output
}
void loop()
{ 
  //vooruit
  digitalWrite(ML_Ctrl,HIGH);//zet de richtingsbesturingspinnen van motor groep B op HIGH
  analogWrite(ML_PWM,105);//zet de PWM-snelheid van motor groep B op 55
  digitalWrite(MR_Ctrl,HIGH);//zet de richtingsbesturingspinnen van motor groep A op HIGH
  analogWrite(MR_PWM,105);//zet de PWM-snelheid van motor groep A op 55
  delay(2000);//vertraging van 2000ms
  //achteruit
  digitalWrite(ML_Ctrl,LOW);//zet de richtingsbesturingspinnen van motor groep B op LOW
  analogWrite(ML_PWM,150);//zet de PWM-snelheid van motor groep B op 200 
  digitalWrite(MR_Ctrl,LOW);//zet de richtingsbesturingspinnen van motor groep A op LOW
  analogWrite(MR_PWM,150);//zet de PWM-snelheid van motor groep A op 200
  delay(2000);//vertraging van 2000ms
  //links
  digitalWrite(ML_Ctrl,LOW);//zet de richtingsbesturingspinnen van motor groep B op LOW
  analogWrite(ML_PWM,150);//zet de PWM-snelheid van motor groep B op 200 
  digitalWrite(MR_Ctrl,HIGH);//zet de richtingsbesturingspinnen van motor groep A op HIGH
  analogWrite(MR_PWM,105);//zet de PWM-snelheid van motor groep A op 200
  delay(2000);//vertraging van 2000ms
  //rechts
  digitalWrite(ML_Ctrl,HIGH);//zet de richtingsbesturingspinnen van motor groep B op HIGH
  analogWrite(ML_PWM,105);//zet de PWM-snelheid van motor groep B op 55 
  digitalWrite(MR_Ctrl,LOW);//zet de richtingsbesturingspinnen van motor groep A op LOW
  analogWrite(MR_PWM,150);//zet de PWM-snelheid van motor groep A op 200
  delay(2000);//vertraging van 2000ms
  //stop
  digitalWrite(ML_Ctrl, LOW);//zet de richtingsbesturingspinnen van motor groep B op LOW
  analogWrite(ML_PWM,0);//zet de PWM-snelheid van motor groep B op 0
  digitalWrite(MR_Ctrl, LOW);//zet de richtingsbesturingspinnen van motor groep A op LOW
  analogWrite(MR_PWM,0);//zet de PWM-snelheid van motor groep A op 0
  delay(2000);//vertraging van 2000ms
}
//************************************************************************
```

Nadat je de code succesvol hebt geüpload naar de V4.0 board, verbind de bedrading volgens het bedradingsschema, zet dan de externe voeding aan en zet de DIP-schakelaar op ON, dan merk je dat de snelheid van de motor veel langzamer is.

<span style="color: rgb(255, 76, 65);">Opmerking: Een lage batterij leidt tot een langzamere motorsnelheid.</span> 