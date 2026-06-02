# Projet 4 Contrôle du Servo

### **1.Description**

![image-20250509084654137](media/A25.png)

Le moteur servo est un actionneur rotatif à contrôle de position. Il se compose principalement d’un boîtier, d’une carte de circuit, d’un moteur sans noyau, d’un engrenage et d’un capteur de position. Son principe de fonctionnement est que le servo reçoit le signal envoyé par les MCU ou les récepteurs et produit un signal de référence avec une période de 20 ms et une largeur de 1,5 ms, puis compare la tension de polarisation continue acquise à la tension du potentiomètre et obtient la sortie de la différence de tension.

![image-20250509084710719](media/A26.png)

En général, le servo possède trois fils de couleur marron, rouge et orange. Le fil marron est la masse, le rouge est la ligne de pôle positif et l’orange est la ligne de signal.

L’angle de rotation du moteur servo est contrôlé en régulant le cycle de service du signal PWM (modulation de largeur d’impulsion). Le cycle standard du signal PWM est de 20 ms (50 Hz). Théoriquement, la largeur est répartie entre 1 ms et 2 ms, mais en pratique, elle est comprise entre 0,5 ms et 2,5 ms. La largeur correspond à l’angle de rotation de 0° à 180°. Mais notez que pour des moteurs de marques différentes, le même signal peut correspondre à des angles de rotation différents.

![image-20250509084727797](media/A27.png)

Les angles de servo correspondants sont indiqués ci-dessous :

![image-20250509084739380](media/A28.png)

### **2.Spécifications**

- Tension de fonctionnement : DC 4,8 V \~ 6 V

- Plage d’angle de fonctionnement : environ 180 ° (à 500 → 2500 μsec)

- Plage de largeur d’impulsion : 500 → 2500 μsec

- Vitesse à vide : 0,12 ± 0,01 s / 60 (DC 4,8 V) 0,1 ± 0,01 s / 60 (DC 6 V)

- Courant à vide : 200 ± 20 mA (DC 4,8 V) 220 ± 20 mA (DC 6 V)

- Couple d’arrêt : 1,3 ± 0,01 kg · cm (DC 4,8 V) 1,5 ± 0,1 kg · cm (DC 6 V)

- Courant d’arrêt : ≦ 850 mA (DC 4,8 V) ≦ 1000 mA (DC 6 V)

- Courant en veille : 3 ± 1 mA (DC 4,8 V) 4 ± 1 mA (DC 6 V)

### **3.Composants**

|                     Carte de développement *1                     |           Driver moteur 8833 *1           |                           Servo*1                            |
| :----------------------------------------------------------: | :--------------------------------------: | :----------------------------------------------------------: |
|           ![img](media/A8.jpg)           | ![img](media/A9.jpg) | ![image-20250509084654137](media/A25.png) |
|                    Support batterie 18650*1                    |               Câble USB*1                |               Batterie 18650*2 (fournie par l’utilisateur)               |
| ![image-20250509084950601](media/A29.png) |         ![img](media/A12.jpg)         | ![image-20250509085010348](media/A30.png) |

### **4.Schéma de câblage**

![image-20250509085038006](media/A31.png)

Note de câblage : Le servo est connecté à G (GND), V (VCC) et A3, le fil marron du servo est relié à la masse (G), le rouge est connecté au 5 V (V) et l’orange est attaché à A3.

Le servo doit être connecté à une alimentation externe en raison de sa forte demande en courant de pilotage. Généralement, le courant de la carte de développement n’est pas suffisant. Sans connexion à une alimentation externe, la carte de développement pourrait être endommagée.

### **5.Code de test**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 4.1
Servo
http://www.keyestudio.com
*/
#define servoPin A3  //Broche du servo
int pos; //variable d’angle du servo
int pulsewidth; //variable de largeur d’impulsion du servo

void setup() {
  pinMode(servoPin, OUTPUT);  //définir les broches du servo en sortie
  procedure(0); //définir l’angle du servo à 0 degré
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // va de 0 degrés à 180 degrés
    // par pas de 1 degré
    procedure(pos);              // demande au servo d'aller à la position dans la variable 'pos'
    delay(15);                   // contrôle la vitesse de rotation du servo
  }
  for (pos = 180; pos >= 0; pos -= 1) { // va de 180 degrés à 0 degrés
    procedure(pos);              // demande au servo d'aller à la position dans la variable 'pos'
    delay(15);                    
  }
}

//fonction pour contrôler le servo
void procedure(int myangle) {
  pulsewidth = myangle * 11 + 500;  // calcule la valeur de la largeur d'impulsion
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);   // la durée du niveau haut est la largeur d'impulsion
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));  // le cycle est de 20ms, le niveau bas dure le reste du temps
}
//****************************************************************************
```

**6.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et alimentez l'alimentation externe. Après la mise sous tension, tournez l'interrupteur DIP vers la position "ON", alors le servo oscillera dans la plage de 0° à 180°.

**7.Pratique d'extension**

De plus, nous permettons de contrôler le servo via un fichier de bibliothèque. Veuillez vous référer au lien : [https://www.arduino.cc/en/Reference/Servo](https://www.arduino.cc/en/Reference/Servo).

![image-20250509085122183](media/A32.png)

```c
//***************************************************************************
/*
 keyestudio 4wd BT Car
 leçon 4.2
 Servo
 http://www.keyestudio.com
*/
#include <Servo.h>
Servo myservo;  // crée un objet servo pour contrôler un servo
// douze objets servo peuvent être créés sur la plupart des cartes
int pos = 0;    // variable pour stocker la position du servo

void setup() {
  myservo.attach(A3);  // attache le servo sur la broche A3 à l'objet servo
}
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // va de 0 degrés à 180 degrés
    // par pas de 1 degré
    myservo.write(pos);              // demande au servo d'aller à la position dans la variable 'pos'
    delay(15);                       // attend 15ms pour que le servo atteigne la position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // va de 180 degrés à 0 degrés
    myservo.write(pos);              // demande au servo d'aller à la position dans la variable 'pos'
    delay(15);                       // attend 15ms pour que le servo atteigne la position
  }
}
//***************************************************************************
```

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et alimentez l'alimentation externe. Après la mise sous tension, tournez l'interrupteur DIP vers la position "ON", alors le servo oscillera également dans la plage de 0° à 180°. Nous le contrôlons généralement via un fichier de bibliothèque.

### **8.Explication du code**

Arduino est livré avec **\#include \<Servo.h\>** (fonction et instructions servo)

Voici quelques instructions courantes de la fonction servo :

1). **attach(interface)**——Définit l'interface du servo

2). **write(angle)**——Utilisé pour définir l'angle de rotation du servo, et la plage d'angle définie est de 0° à 180°

3). **read()**——utilisé pour lire l'angle du servo, c'est-à-dire lire la valeur de commande de “write()”

4). **attached()**——Détermine si le paramètre du servo est envoyé à son interface

<span style="color: rgb(255, 76, 65);">Note :</span> Le format écrit ci-dessus est “nom de la variable servo, instruction spécifique()”, par exemple : myservo.attach(9).