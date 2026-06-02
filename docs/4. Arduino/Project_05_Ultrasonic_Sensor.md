# Projet 5 Capteur Ultrasonique

### **1.Description**

![image-20250509085643931](media/A33.png)

Le capteur ultrasonique HC-SR04 utilise le sonar pour déterminer la distance à un objet, comme le font les chauves-souris. Il offre une excellente détection de distance sans contact avec une grande précision et des lectures stables dans un boîtier facile à utiliser. Il est livré complet avec des modules émetteur et récepteur ultrasoniques.

![Img](media/A34.png)

Le HC-SR04 ou capteur ultrasonique est utilisé dans un large éventail de projets électroniques pour créer des applications de détection d'obstacles et de mesure de distance ainsi que diverses autres applications. Ici, nous avons présenté la méthode simple pour mesurer la distance avec Arduino et un capteur ultrasonique et comment utiliser le capteur ultrasonique avec Arduino.

### **2.Spécifications**

- Tension de fonctionnement : +5V DC

- Courant au repos : \<2mA

- Courant de fonctionnement : 15mA

- Angle effectif : \<15°

- Plage de distance : 2cm – 300 cm

- Précision : 0,3 cm

- Angle de mesure : 30 degrés

- Largeur d'impulsion d'entrée Trigger : 10µs

![image-20250509085705309](media/A35.png)

### **3.Composants**

| Carte de développement *1                                   | Driver moteur 8833 *1                   | Module LED Rouge*1       | Capteur Ultrasonique*1                                      |
| ------------------------------------------------------------ | ---------------------------------------- | ------------------------ | ------------------------------------------------------------ |
| ![img](media/A8.jpg)                     | ![img](media/A9.jpg) | ![img](media/A10.jpg) | ![image-20250509085643931](media/A33.png) |
| Fil Dupont 4P*1                                             | Câble USB*1                             | Fil Dupont 3P*1          |                                                              |
| ![image-20250509143737972](media/A36.png) | ![img](media/A12.jpg)                 | ![img](media/A11.jpg) |                                                              |

### **4.Principe de fonctionnement**

Comme montré sur l'image ci-dessus, c'est comme deux yeux. L'un est l'émetteur, l'autre est le récepteur.

Le module ultrasonique émettra des ondes ultrasoniques après avoir reçu un signal de déclenchement. Lorsque les ondes ultrasoniques rencontrent un objet et sont réfléchies, le module émet un signal d'écho, ce qui permet de déterminer la distance de l'objet à partir de la différence de temps entre le signal de déclenchement et le signal d'écho.

t est le temps que le signal émis met pour rencontrer l'obstacle et revenir. La vitesse de propagation du son dans l'air est d'environ 343 m/s, et distance = vitesse \* temps. Cependant, l'onde ultrasonique est émise et revient, ce qui correspond à 2 fois la distance. Par conséquent, il faut diviser par 2, la distance mesurée par l'onde ultrasonique = (vitesse \* temps)/2.

**Méthode d'utilisation et graphique du module ultrasonique :**

1. Utilisez la broche GPIO pour envoyer un signal haut d'au moins 10μs à la broche Trig du SR04, ce qui peut déclencher la détection de distance.
2. Après le déclenchement, le module enverra automatiquement huit impulsions ultrasoniques à 40KHz et détectera s'il y a un retour de signal. Cette étape est réalisée automatiquement par le module.
3. Si le signal revient, la broche Echo émettra un niveau haut, et la durée de ce niveau haut correspond au temps entre l'émission de l'onde ultrasonique et son retour.

![image-20250509143833078](media/A37.png)

**Schéma de circuit du capteur ultrasonique :**

![image-20250509154035287](media/A38.png)

### **5.Schéma de câblage**

![image-20250509154107103](media/A39.png)

VCC, Trig, Echo et Gnd du capteur ultrasonique sont connectés respectivement à 5V(V), D12, D13 et Gnd(G)

### **6.Code de test**

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
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Le capteur est déclenché par une impulsion HIGH de 10 microsecondes ou plus.
  // Donner une courte impulsion LOW avant pour assurer une impulsion HIGH propre :
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   // Lire le signal du capteur : une impulsion HIGH dont
  // la durée est le temps (en microsecondes) entre l'envoi
  // du ping et la réception de son écho sur un objet.
  duration = pulseIn(echoPin, HIGH);
   // Convertir le temps en distance
  cm = (duration/2) / 29.1;     // Diviser par 29.1 ou multiplier par 0.0343
  inches = (duration/2) / 74;   // Diviser par 74 ou multiplier par 0.0135
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
}
//***************************************************************************
```

**7.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l'ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, ouvrez le moniteur série et réglez le débit en bauds à 9600.

La distance détectée sera affichée, et l'unité est en cm et pouces. Bloquez le capteur ultrasonique avec la main, la valeur de distance affichée diminue.

![image-20250509154147537](media/A40.png)

**8.Explication du code**

**int trigPin-** ce pin est défini pour transmettre les ondes ultrasoniques, généralement en sortie.

**int echoPin -** ce pin est défini comme la broche de réception, généralement en entrée.

**cm = (duration/2) / 29.1-**

**inches = (duration/2) / 74-**

Nous pouvons calculer la distance en utilisant la formule suivante :

distance = (temps de trajet/2) x vitesse du son

La vitesse du son est : 343m/s = 0.0343 cm/us = 1/29.1 cm/us

Ou en pouces : 13503.9in/s = 0.0135in/us = 1/74in/us

Nous devons diviser le temps de trajet par 2 car il faut prendre en compte que l'onde a été envoyée, a frappé l'objet, puis est revenue au capteur.

**9.Pratique d'extension**

Nous venons de mesurer la distance affichée par l'ultrason. Que diriez-vous de contrôler la LED avec la distance mesurée ? Essayons et connectons un module LED à la broche D9.

![image-20250509154232505](media/A41.png)

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lesson 5.2
 Ultrasonic LED
 http://www.keyestudio.com
*/ 
int trigPin = 12;    // Déclencheur
int echoPin = 13;    // Écho
long duration, cm, inches;

void setup() {
  Serial.begin (9600);  // Démarrage du port série
  pinMode(trigPin, OUTPUT);  // Définir les entrées et sorties
  pinMode(echoPin, INPUT);
}

void loop() 
{
  // Le capteur est déclenché par une impulsion HIGH de 10 microsecondes ou plus.
  // Donner une courte impulsion LOW avant pour assurer une impulsion HIGH propre :
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Lire le signal du capteur : une impulsion HIGH dont
  // la durée est le temps (en microsecondes) entre l'envoi
  // du ping et la réception de son écho sur un objet.
  duration = pulseIn(echoPin, HIGH);
  // Convertir le temps en distance
  cm = (duration/2) / 29.1;     // Diviser par 29.1 ou multiplier par 0.0343
  inches = (duration/2) / 74;   // Diviser par 74 ou multiplier par 0.0135
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

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l'ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, bloquez le capteur ultrasonique avec la main (la distance est entre 2-10 cm), puis vérifiez si la LED est allumée.