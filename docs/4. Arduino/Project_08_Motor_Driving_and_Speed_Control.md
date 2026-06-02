# Projet 8 Conduite de moteur et contrôle de vitesse

![image-20250510090044895](media/A77.png)

### **1.Description**

Il existe de nombreuses façons de piloter des moteurs. Notre voiture utilise la puce de pilote de moteur DRV8833 la plus couramment utilisée, qui fournit une solution de commande électrique à pont double canal pour les jouets, les imprimantes et autres applications intégrées de moteurs.

Lorsque nous empilons le Shield sur la carte de développement 4.0 et que nous alimentons le BAT, puis que nous réglons l'interrupteur DIP sur la position ON, l'alimentation externe alimentera les deux cartes en même temps. Pour faciliter les connexions de câblage, le Shield est équipé d'un port anti-inversion (PH2.0-2P-3P-4P-5P). Vous pouvez connecter directement les moteurs, l'alimentation et les modules capteurs au Shield.

L'interface Bluetooth du Shield est entièrement compatible avec le module Bluetooth DX-BT24 5.1. Lors de la connexion du module Bluetooth, il vous suffit de le brancher sur l'interface correspondante. En même temps, des broches en rangée 2.54 sont utilisées pour sortir certains ports numériques et analogiques inutilisés sur le Shield, ce qui vous permet d'ajouter d'autres capteurs et de réaliser des expériences d'extension.

La carte d'extension peut être connectée à quatre moteurs à courant continu. Lorsque le cavalier est connecté par défaut, les moteurs des ports A et A1 ainsi que B et B1 sont connectés en parallèle et ont la même loi de mouvement. 8 cavaliers peuvent être utilisés pour contrôler la direction de rotation des 4 interfaces moteur.

Par exemple, lorsque les 2 cavaliers devant B1 du moteur M1 passent d'une connexion transversale à une connexion longitudinale, la direction de rotation du moteur M1 sera opposée à la direction de rotation d'origine.

### **2.Spécifications**

- Tension d'entrée pour la logique : DC 5V

- Tension d'entrée pour la commande : DC 6-9 V

- Courant de fonctionnement pour la logique : \<36mA

- Courant de fonctionnement pour la commande : \<2A

- Dissipation maximale de puissance : 25W（T=75℃）

- Niveau d'entrée pour le signal de commande : niveau haut est 2.3V\<Vin\<5V, niveau bas est -0.3V\<Vin\<1.5V

- Température de fonctionnement : -25＋130℃

**Carte d'extension pilote moteur Keyestudio 8833**

![image-20250510090404192](media/A78.png)

### **3.Principe de fonctionnement**

Nous utilisons le mode de connexion parallèle du même côté pour les quatre moteurs, qui peut être considéré comme deux groupes de moteurs. Comme indiqué dans le schéma de câblage, B et B1 forment un groupe, et A et A1 un autre groupe.

Les moteurs du même groupe doivent tourner dans la même direction. S'ils sont différents, veuillez ajuster les cavaliers correspondants à côté de la borne pour changer la direction.

Comme montré ci-dessous, si les directions de A et A1 sont différentes, ajustez la direction des cavaliers jusqu'à ce que la direction de mouvement des moteurs du même groupe soit cohérente.

![image-20250510090532851](media/A79.png)

D'après le schéma ci-dessus, on sait que la broche de direction du moteur A est D4, la broche de vitesse est D6 ; D2 est la broche de direction du moteur B ; et D6 est la broche de vitesse.

<span style="color:red;">Le PWM pilote la voiture robot. La valeur PWM est dans la plage de 0 à 255. Lorsque nous réglons la direction sur HIGH, plus le nombre PWM est petit, plus la rotation du moteur est rapide.</span>

|            | D2   | D5（PWM） | Moteur B（gauche）     | D4   | D6（PWM） | Moteur A（droite）     |
| ---------- | ---- | --------- | --------------------- | ---- | --------- | --------------------- |
| Avancer    | HIGH | 255-200   | Rotation horaire       | HIGH | 255-200   | Rotation horaire       |
| Reculer    | LOW  | 200       | Rotation antihoraire   | LOW  | 200       | Rotation antihoraire   |
| Tourner à gauche | HIGH | 255-200   | Rotation horaire       | LOW  | 200       | Rotation antihoraire   |
| Tourner à droite | LOW  | 200       | Rotation antihoraire   | HIGH | 255-200   | Rotation horaire       |

### **4.Composants**

| Development Board *1      | 8833 Motor Driver *1      | USB Cable*1                       |
| ------------------------- | ------------------------- | --------------------------------- |
| ![img](media/A80.jpg) | ![img](media/A81.jpg) | ![img](media/A82.jpg)         |
| 18650 Battery Holder*1    | Motor*4                   | 18650 Battery *2（self-provided） |
| ![img](media/A83.png) | ![img](media/A84.jpg) | ![img](media/A85.png)         |

### **5.Schéma de câblage**

![image-20250510090733191](media/A86.png)

Connectez l'alimentation au port BAT.

### **6.Code de test**

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.1
 Motor driver shield
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //définir les broches de contrôle de direction du moteur du groupe B
#define ML_PWM 5   //définir les broches de contrôle PWM du moteur du groupe B
#define MR_Ctrl 4    //définir les broches de contrôle de direction du moteur du groupe A
#define MR_PWM 6   //définir les broches de contrôle PWM du moteur du groupe A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//configurer les broches de contrôle de direction du moteur du groupe B en sortie
  pinMode(ML_PWM, OUTPUT);//configurer les broches de contrôle PWM du moteur du groupe B en sortie
  pinMode(MR_Ctrl, OUTPUT);//configurer les broches de contrôle de direction du moteur du groupe A en sortie
  pinMode(MR_PWM, OUTPUT);//configurer les broches de contrôle PWM du moteur du groupe A en sortie
}
void loop()
{ 
  //avant
  digitalWrite(ML_Ctrl,HIGH);//mettre les broches de contrôle de direction du moteur du groupe B à HIGH
  analogWrite(ML_PWM,55);//régler la vitesse PWM du moteur du groupe B à 55
  digitalWrite(MR_Ctrl,HIGH);//mettre les broches de contrôle de direction du moteur du groupe A à HIGH
  analogWrite(MR_PWM,55);//régler la vitesse PWM du moteur du groupe A à 55
  delay(2000);//pause de 2000ms
  //arrière
  digitalWrite(ML_Ctrl,LOW);//mettre les broches de contrôle de direction du moteur du groupe B à LOW
  analogWrite(ML_PWM,200);//régler la vitesse PWM du moteur du groupe B à 200 
  digitalWrite(MR_Ctrl,LOW);//mettre les broches de contrôle de direction du moteur du groupe A à LOW
  analogWrite(MR_PWM,200);//régler la vitesse PWM du moteur du groupe A à 200
  delay(2000);//pause de 2000ms
  //gauche
  digitalWrite(ML_Ctrl,LOW);//mettre les broches de contrôle de direction du moteur du groupe B à LOW
  analogWrite(ML_PWM,200);//régler la vitesse PWM du moteur du groupe B à 200 
  digitalWrite(MR_Ctrl,HIGH);//mettre les broches de contrôle de direction du moteur du groupe A à HIGH
  analogWrite(MR_PWM,55);//régler la vitesse PWM du moteur du groupe A à 55
  delay(2000);//pause de 2000ms
  //droite
  digitalWrite(ML_Ctrl,HIGH);//mettre les broches de contrôle de direction du moteur du groupe B à HIGH
  analogWrite(ML_PWM,55);//régler la vitesse PWM du moteur du groupe B à 55 
  digitalWrite(MR_Ctrl,LOW);//mettre les broches de contrôle de direction du moteur du groupe A à LOW
  analogWrite(MR_PWM,200);//régler la vitesse PWM du moteur du groupe A à 200
  delay(2000);//pause de 2000ms
  //arrêt
  digitalWrite(ML_Ctrl, LOW);//mettre les broches de contrôle de direction du moteur du groupe B à LOW
  analogWrite(ML_PWM,0);//régler la vitesse PWM du moteur du groupe B à 0
  digitalWrite(MR_Ctrl, LOW);//mettre les broches de contrôle de direction du moteur du groupe A à LOW
  analogWrite(MR_PWM,0);//régler la vitesse PWM du moteur du groupe A à 0
  delay(2000);//pause de 2000ms
}
//****************************************************************************
```

### **7.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis alimentez la source externe et mettez l'interrupteur DIP sur ON, la voiture avancera pendant 2s, reculera pendant 2s, tournera à gauche pendant 2s, à droite pendant 2s et s'arrêtera pendant 2s.

### **8.Explication du code**

**digitalWrite(ML\_Ctrl,LOW) :** La direction de rotation du moteur est déterminée par le niveau haut/bas et les broches qui décident de la direction de rotation sont des broches digitales.

**analogWrite(ML\_PWM,200) :** La vitesse du moteur est régulée par PWM, et les broches qui déterminent la vitesse du moteur doivent être des broches PWM.

### **9.Explication du code**

Ajustez la vitesse à laquelle le PWM contrôle le moteur, branchez de la même manière.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 8.2
 Motor driver
 http://www.keyestudio.com
*/ 
#define ML_Ctrl 2     //définir les broches de contrôle de direction du moteur du groupe B
#define ML_PWM 5   //définir les broches de contrôle PWM du moteur du groupe B
#define MR_Ctrl 4    //définir les broches de contrôle de direction du moteur du groupe A
#define MR_PWM 6   //définir les broches de contrôle PWM du moteur du groupe A

void setup()
{
  pinMode(ML_Ctrl, OUTPUT);//configurer les broches de contrôle de direction du moteur du groupe B en sortie
  pinMode(ML_PWM, OUTPUT);//configurer les broches de contrôle PWM du moteur du groupe B en sortie
  pinMode(MR_Ctrl, OUTPUT);//configurer les broches de contrôle de direction du moteur du groupe A en sortie
  pinMode(MR_PWM, OUTPUT);//configurer les broches de contrôle PWM du moteur du groupe A en sortie
}
void loop()
{ 
  //avant
  digitalWrite(ML_Ctrl,HIGH);//mettre les broches de contrôle de direction du moteur du groupe B à HIGH
  analogWrite(ML_PWM,105);//régler la vitesse PWM du moteur du groupe B à 55
  digitalWrite(MR_Ctrl,HIGH);//mettre les broches de contrôle de direction du moteur du groupe A à HIGH
  analogWrite(MR_PWM,105);// régler la vitesse PWM du moteur du groupe A à 55
  delay(2000);//délai de 2000ms
  //arrière
  digitalWrite(ML_Ctrl,LOW);//mettre les broches de contrôle de direction du moteur du groupe B à LOW
  analogWrite(ML_PWM,150);// régler la vitesse PWM du moteur du groupe B à 200 
  digitalWrite(MR_Ctrl,LOW);//mettre les broches de contrôle de direction du moteur du groupe A à LOW
  analogWrite(MR_PWM,150);//régler la vitesse PWM du moteur du groupe A à 200
  delay(2000);//délai de 2000ms
  //gauche
  digitalWrite(ML_Ctrl,LOW);//mettre les broches de contrôle de direction du moteur du groupe B à LOW
  analogWrite(ML_PWM,150);//régler la vitesse PWM du moteur du groupe B à 200 
  digitalWrite(MR_Ctrl,HIGH);//mettre les broches de contrôle de direction du moteur du groupe A à HIGH
  analogWrite(MR_PWM,105);//régler la vitesse PWM du moteur du groupe A à 200
  delay(2000);//délai de 2000ms
  //droite
  digitalWrite(ML_Ctrl,HIGH);//mettre les broches de contrôle de direction du moteur du groupe B à HIGH
  analogWrite(ML_PWM,105);//régler la vitesse PWM du moteur du groupe B à 55 
  digitalWrite(MR_Ctrl,LOW);// mettre les broches de contrôle de direction du moteur du groupe A à LOW
  analogWrite(MR_PWM,150);//régler la vitesse PWM du moteur du groupe A à 200
  delay(2000);//délai de 2000ms
  //arrêt
  digitalWrite(ML_Ctrl, LOW);// mettre les broches de contrôle de direction du moteur du groupe B à LOW
  analogWrite(ML_PWM,0);//régler la vitesse PWM du moteur du groupe B à 0
  digitalWrite(MR_Ctrl, LOW);// mettre les broches de contrôle de direction du moteur du groupe A à LOW
  analogWrite(MR_PWM,0);//régler la vitesse PWM du moteur du groupe A à 0
  delay(2000);// délai de 2000ms
}
//************************************************************************
```

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis alimentez l'alimentation externe et mettez l'interrupteur DIP sur ON, vous constaterez alors que la vitesse du moteur est beaucoup plus lente.

<span style="color: rgb(255, 76, 65);">Remarque : Une batterie faible entraînera une vitesse de moteur lente.</span>