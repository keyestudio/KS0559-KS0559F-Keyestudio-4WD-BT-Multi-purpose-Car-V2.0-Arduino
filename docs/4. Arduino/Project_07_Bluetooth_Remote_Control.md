# Projet 7 Contrôle à distance Bluetooth

### **1.Description**

![image-20250510083107283](media/A47.png)

Ce kit contient un module Bluetooth DX-BT24 5.1. Ce module Bluetooth dispose d’un espace de 256Kb et est conforme à la spécification Bluetooth V5.1BLE, qui prend en charge les commandes AT. Les utilisateurs peuvent modifier des paramètres tels que le débit en bauds et le nom de l’appareil du port série selon leurs besoins.

De plus, il prend en charge l’interface UART et la transmission transparente du port série Bluetooth, ce qui inclut également les avantages d’un faible coût, d’une petite taille, d’une faible consommation d’énergie et d’une haute sensibilité pour l’envoi et la réception. Notamment, il nécessite seulement quelques composants périphériques pour réaliser ses fonctions puissantes.

### **2.Spécifications**

- Protocole Bluetooth : Spécification Bluetooth V5.1 BLE

- Distance de fonctionnement : En environnement ouvert, il peut atteindre une communication ultra-longue distance de 40m

- Fréquence de fonctionnement : bande ISM 2,4 GHz

- Interface de communication : UART

- Certification Bluetooth : Conforme aux normes de certification FCC CE ROHS REACH

- Paramètres du port série : 9600, 8 bits de données, 1 bit de stop, bit invalide, pas de contrôle de flux

- Alimentation : 5V DC

- Température de fonctionnement : –10℃ à +65℃

### **3.Application**

Le module DX-BT24 prend également en charge le protocole BT5.1 BLE, qui peut être directement connecté aux appareils iOS avec fonction Bluetooth BLE, et prend en charge l’exécution résidente des programmes en arrière-plan. Il est principalement utilisé dans le domaine de la transmission de données sans fil à courte distance. Il permet d’éviter les connexions câblées encombrantes et peut remplacer directement les câbles série.

**Domaines d’application réussis des modules BT24 :**

※ Transmission de données sans fil Bluetooth ;

※ Téléphone mobile, périphériques informatiques ;

※ Équipement POS portable ;

※ Transmission de données sans fil d’équipements médicaux ;

※ Contrôle domotique intelligent ;

※ Imprimante Bluetooth ;

※ Jouets télécommandés Bluetooth ;

※ Vélos en libre-service ;

### **4.Ports**

![420af966-aaa4-4736-9d35-2a9ccc7215f3](media/A48.png)

①STATE : Broche d’état

②RX : Broche de réception

③TX : Broche d’envoi

④GND : Masse

⑤VCC : Alimentation

⑥EN : Broche d’activation

Connectez le module BT à la carte de développement.

| Uno  | BT24 |
| :--: | :--: |
|  TX  |  RX  |
|  RX  |  TX  |
| VCC  |  5V  |
| GND  | GND  |

### **5.Composants**

|           Carte de développement *1           |           Driver moteur 8833 *1           |                       Module LED rouge *1                       |
| :--------------------------------------------: | :---------------------------------------: | :-------------------------------------------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) |                   ![img](media/A10.jpg)                   |
|             Fil Dupont 3P *1             |               Câble USB *1                |                  Module Bluetooth DX-BT24 *1                  |
|         ![img](media/A11.jpg)         |         ![img](media/A12.jpg)         | ![image-20250510083534209](media/A49.png) |

### **6.Schéma de câblage**

![image-20250510083927915](media/A50.png)

RXD, TXD, GND et VCC du module BT sont connectés respectivement à TX, RX, G et 5V.

STATE et BRK du module BT n’ont pas besoin d’être connectés.

<span style="color: rgb(255, 76, 65);">Note : faites attention à la direction du module BT lors de son insertion sur la carte 8833. Ne l’insérez pas avant d’avoir téléversé le code.</span> 

### **7.Code de test**

<span style="color: rgb(255, 76, 65);">**Note :** Avant de téléverser le code de test, vous devez retirer le module Bluetooth, sinon le code ne pourra pas être téléversé. Reconnectez le module Bluetooth après un téléversement réussi.</span>

```c
//***********************************************************************
/*
keyestudio 4wd BT Car
lesson 7.1
Bluetooth 
http://www.keyestudio.com
*/
char ble_val; //variable caractère, utilisée pour stocker la valeur reçue par Bluetooth 

void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available() > 0)  // s'assurer qu'il y a des données dans le tampon série
  {
    ble_val = Serial.read();  // Lire les données du tampon série
    Serial.println(ble_val);  // Afficher
  }
}
//***********************************************************************
```

### **8. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l'ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, insérez le module BT et la LED clignotera, puis nous devons télécharger l'application BT.

### **9. Télécharger l'application Bluetooth**

**Système Apple**

(1). Ouvrez l'App Store sur l'iPhone.

(2). Recherchez keyes BT car et téléchargez l'application sur votre téléphone.



![image-20250510084716811](media/A51.png)
    

(3). Après l'installation, entrez dans son interface.

![image-20250510084812821](media/A52.png)
    

(4). Cliquez sur le bouton "**Connect**" en haut à gauche pour rechercher automatiquement le Bluetooth. Lorsque **BT24** est trouvé, cliquez sur "**Connect**" pour connecter le Bluetooth, puis cliquez sur ![image-20250510084833837](media/A53.png) pour entrer dans l'interface de contrôle de la voiture intelligente 4WD. 

![image-20250510084902641](media/A54.png)
    **Système Android**
    

(1). Entrez dans le Google Play Store pour rechercher “keyes 4wd”.

![image-20250510084916086](media/A55.png)

(2). L'icône de l'application s'affiche ci-dessous après l'installation.

![image-20250510084933465](media/A56.png)

(3). Cliquez sur l'application pour entrer dans la page suivante.

![image-20250510084946146](media/A57.png)

(4). Après avoir connecté le Bluetooth, branchez l'alimentation et le témoin LED du module Bluetooth clignotera. Appuyez sur “**Connect**” pour rechercher le Bluetooth.

![image-20250510085007028](media/A58.png)

(5). Lorsque **BT24** est trouvé, cliquez sur "Connect" pour connecter le Bluetooth. Lorsque "**Connect**" devient "**is Connected**", cela indique que la connexion Bluetooth est réussie. Comme montré sur l'image ci-dessous, la LED Bluetooth restera allumée.

![image-20250510085026219](media/A59.png)

(6). Après avoir connecté le module Bluetooth, ouvrez le moniteur série pour régler le débit en bauds à 9600. En appuyant sur le bouton de l'application Bluetooth, les caractères correspondants s'afficheront, comme montré ci-dessous :

![image-20250510085039562](media/A60.png)

| Touche                    | Fonction                          |
| ------------------------- | --------------------------------- |
| ![img](./media/A61.jpg) | Jumeler le module Bluetooth DX-BT24 5.1 |
| ![img](./media/A62.jpg) | Déconnecter le Bluetooth              |

|                           | Caractère de contrôle                                        | Caractère de contrôle                                        |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![img](media/A63.jpg) | Appuyer : F  <br />Relâcher : S                              | Appuyez sur le bouton, la voiture avance ; <br />relâchez pour arrêter |
| ![img](media/A64.jpg) | Appuyer : L  <br />Relâcher : S                              | Appuyez sur le bouton, la voiture tourne à gauche ; <br />relâchez pour arrêter  |
| ![img](media/A65.jpg) | Appuyer : R  <br />Relâcher : S                              | Appuyez sur le bouton, la voiture tourne à droite ; <br />relâchez pour arrêter |
| ![img](media/A66.jpg) | Appuyer : B  <br />Relâcher : S                              | Appuyez sur le bouton, la voiture recule ; <br />relâchez pour arrêter   |
| ![img](media/A67.jpg) | Appuyer : “a”  <br />Relâcher : “S”                          | Cliquez pour accélérer (maximum : 255)                        |
| ![img](media/A68.jpg) | Appuyer : “d”  <br />Relâcher : “S”                          | Cliquez pour ralentir (minimum : 0)                           |
| ![img](media/A69.jpg) | Cliquez pour démarrer la fonction de détection <br />de gravité du <br />téléphone mobile : cliquez de nouveau pour <br />quitter le contrôle par détection de gravité |                                                              |
| ![img](media/A70.jpg) | Cliquez pour envoyer “X”, <br />cliquez de nouveau pour envoyer “S” | Démarrer la fonction de suivi de ligne ; <br />cliquez de nouveau pour quitter      |
| ![img](media/A71.jpg) | Cliquez pour envoyer “Y”, <br />cliquez de nouveau pour envoyer “S” | Démarrer la fonction d’évitement ultrasonique ; <br />cliquez de nouveau pour quitter |
| ![img](media/A72.jpg) | Cliquez pour envoyer “U”, <br />cliquez de nouveau pour envoyer “S” | Démarrer la fonction de suivi ultrasonique ; <br />cliquez de nouveau pour quitter |
| ![img](media/A73.jpg) | Cliquez pour envoyer “G”, <br />cliquez de nouveau pour envoyer “S” | Démarrer la fonction de restriction ;<br /> cliquez de nouveau pour quitter       |

### **10. Explication du code**

**Serial.available()** : Retourne le nombre de caractères actuellement présents dans le tampon du port série. Généralement, cette fonction est utilisée pour vérifier s’il y a des données dans le tampon du port série. Lorsque Serial.available() > 0, cela signifie que le port série a reçu des données et peut être lu ;

**Serial.read() :** Fait référence à la lecture et à la récupération d’un octet de données depuis le tampon du port série. Par exemple, si un appareil envoie des données à Arduino via le port série, on peut utiliser Serial.read() pour lire les données envoyées.

### **11. Pratique d’extension**

Ici, nous cherchons à utiliser la commande envoyée par le téléphone mobile pour allumer ou éteindre une LED. En regardant le schéma de câblage, une LED est connectée à la broche D9.

![image-20250510085856954](media/A74.png)

```c
//****************************************************************************
/*
 keyestudio smart turtle robot
 lesson 7.2
 Bluetooth LED
 http://www.keyestudio.com
*/ 
int ledpin=9;
char ble_val;// Une variable entière utilisée pour stocker la valeur reçue par Bluetooth

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop()
{ 
  if (Serial.available() > 0) //Vérifie s’il y a des données dans le cache du port série
  {
    ble_val = Serial.read();  //Lit les données du cache du port série
    Serial.print("DATA RECEIVED:");
    Serial.println(ble_val);
    if (ble_val == 'F') {
      digitalWrite(ledpin, HIGH);
      Serial.println("led on");
    }
    if (ble_val == 'B') {
      digitalWrite(ledpin, LOW);
      Serial.println("led off");
    }
   }
}
//****************************************************************************
```

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l'ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, cliquez sur ![image-20250510085919039](media/A75.png) et ![image-20250510085931709](media/A76.png) pour contrôler l'allumage et l'extinction de la LED.