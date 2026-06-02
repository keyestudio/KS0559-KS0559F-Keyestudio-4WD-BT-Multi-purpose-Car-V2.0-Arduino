# Projet 5 Capteur Ultrasonique

### **1.Description**

![](media/A109.png)

Le capteur ultrasonique HC-SR04 utilise le sonar pour déterminer la distance à un objet, comme le font les chauves-souris. Il offre une excellente détection de distance sans contact avec une grande précision et des lectures stables dans un boîtier facile à utiliser. Il est livré complet avec des modules émetteur et récepteur ultrasoniques.

![Img](media/A110.png)

Le HC-SR04 ou capteur ultrasonique est utilisé dans un large éventail de projets électroniques pour créer des applications de détection d'obstacles et de mesure de distance ainsi que diverses autres applications. Ici, nous avons présenté la méthode simple pour mesurer la distance avec Arduino et un capteur ultrasonique et comment utiliser le capteur ultrasonique avec Arduino.

### **2.Spécifications**

- Tension de fonctionnement : +5V DC

- Courant au repos : <2mA

- Courant de fonctionnement : 15mA

- Angle effectif : <15°

- Plage de distance : 2cm – 300 cm

- Précision : 0,3 cm

- Angle de mesure : 30 degrés

- Largeur d'impulsion d'entrée Trigger : 10µs

![](media/A111.png)

### **3.Composants**

| Carte de développement *1 | Driver moteur 8833 *1     | Module LED rouge *1       | Capteur ultrasonique *1   |
| ------------------------- | ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A112.jpg)    | ![img](media/A113.jpg)    | ![img](media/A114.jpg)    | ![img](media/A115.jpg)    |
| Fil Dupont 4P *1          | Câble USB *1              | Fil Dupont 3P *1          |                           |
| ![img](media/A116.jpg)    | ![img](media/A117.jpg)    | ![img](media/A118.jpg)    |                           |

### **4.Principe de fonctionnement**

Comme montré sur l'image ci-dessus, c'est comme deux yeux. L'un est l'émetteur, l'autre est le récepteur.

Le module ultrasonique émettra des ondes ultrasoniques après avoir reçu un signal de déclenchement. Lorsque les ondes ultrasoniques rencontrent un objet et sont réfléchies, le module émet un signal d'écho, ce qui permet de déterminer la distance de l'objet à partir de la différence de temps entre le signal de déclenchement et le signal d'écho.

t est le temps que le signal émis met pour rencontrer l'obstacle et revenir. La vitesse de propagation du son dans l'air est d'environ 343 m/s, et distance = vitesse \* temps. Cependant, l'onde ultrasonique émet et revient, ce qui correspond à 2 fois la distance. Par conséquent, il faut diviser par 2, la distance mesurée par l'onde ultrasonique = (vitesse \* temps)/2.

**Méthode d'utilisation et schéma du module ultrasonique :**

1). Utilisez la broche GPIO pour envoyer un signal haut d'au moins 10μs à la broche Trig du SR04, ce qui peut le déclencher pour détecter la distance.

2). Après le déclenchement, le module enverra automatiquement huit impulsions ultrasoniques à 40KHz et détectera s'il y a un retour de signal. Cette étape est réalisée automatiquement par le module.

3). Si le signal revient, la broche Echo émettra un niveau haut, et la durée de ce niveau haut correspond au temps entre l'émission de l'onde ultrasonique et son retour.

![image-20250509143833078](media/A119.png)


**Schéma de circuit du capteur ultrasonique :**

![](media/A120.jpeg)

### **5.Schéma de câblage**

![](media/A121.png)

VCC, Trig, Echo et Gnd du capteur ultrasonique sont connectés respectivement à 5V(V), D12, D13 et Gnd(G)

### **6.Code de test**

Avant d'écrire le code, il est nécessaire d'importer le fichier de bibliothèque du capteur ultrasonique. Les étapes spécifiques sont les suivantes : 

Cliquez sur ![](media/A29.png) pour entrer dans l'interface de la bibliothèque d'extensions de capteurs/modules/composants, puis recherchez le capteur "**Ultrasonic**" ![](media/A122.png) et cliquez dessus. Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le capteur "**Ultrasonic**" a été ajouté avec succès. 

![Img](media/A123.png)

![](media/A124.png)

Cliquez sur ![](media/A33.png) pour revenir à l'interface de l'éditeur de code, le bloc d'instructions du capteur "**Ultrasonic**" ajouté peut être vu dans la zone des modules. 

![](media/A125.png)

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1). ![](media/A126.png)

(2). ![](media/A127.png)

(3). ![](media/A128.png)

(4). ![](media/A129.png)

(5). ![](media/A130.png)

(6).![](media/A131.png)

(7).![](media/A132.png)

**Code de test complet**

![](media/A133.png)

### **7. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l'ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, cliquez sur ![](media/A80.png) pour régler le débit en bauds à 9600.

La distance détectée sera affichée, et l'unité est en cm et pouces. Obstruez le capteur ultrasonique avec la main, la valeur de distance affichée diminue.

![](media/A134.png)

### **8. Pratique d'extension**

Nous venons de mesurer la distance affichée par l'ultrason. Que diriez-vous de contrôler la LED avec la distance mesurée ? Essayons et connectons un module de lumière LED à la broche D9.

![](media/A135.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A136.png)

(3).![](media/A128.png)

(4).![](media/A137.png)

(5).![](media/A130.png)

(6).![](media/A138.png)

(7).![](media/A132.png)

**Code de test complet**

![](media/A139.png)

![](media/A140.png)

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l'ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, bloquez le capteur ultrasonique avec la main (la distance est entre 2-10 cm), puis vérifiez si la LED est allumée.