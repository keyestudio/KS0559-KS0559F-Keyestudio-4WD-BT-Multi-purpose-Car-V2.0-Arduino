# Projet 7 Contrôle à Distance Bluetooth

![](media/A161.png)

### **1.Description**

Ce kit contient un module Bluetooth DX-BT24 5.1. Ce module Bluetooth dispose d’un espace de 256Kb et est conforme à la spécification Bluetooth V5.1BLE, qui supporte les commandes AT. Les utilisateurs peuvent modifier des paramètres tels que le débit en bauds et le nom de l’appareil du port série selon leurs besoins.

De plus, il supporte une interface UART et la transmission transparente du port série Bluetooth, ce qui inclut également les avantages d’un faible coût, d’une petite taille, d’une faible consommation d’énergie et d’une haute sensibilité pour l’envoi et la réception. Notamment, il nécessite seulement quelques composants périphériques pour réaliser ses fonctions puissantes.

### **2.Spécifications**

- Protocole Bluetooth : Spécification Bluetooth V5.1 BLE

- Distance de fonctionnement : En environnement ouvert, il peut atteindre une communication ultra longue distance de 40m

- Fréquence de fonctionnement : Bande ISM 2.4GHz

- Interface de communication : UART

- Certification Bluetooth : Conforme aux normes FCC CE ROHS REACH

- Paramètres du port série : 9600, 8 bits de données, 1 bit de stop, bit invalide, pas de contrôle de flux

- Alimentation : 5V DC

- Température de fonctionnement : –10℃ à +65℃

### **3.Application**

Le module DX-BT24 supporte également le protocole BT5.1 BLE, qui peut être connecté directement aux appareils iOS avec fonction Bluetooth BLE, et supporte l’exécution résidente des programmes en arrière-plan. Il est principalement utilisé dans le domaine de la transmission sans fil de données à courte distance. Il permet d’éviter les connexions câblées encombrantes et peut remplacer directement les câbles série.

**Domaines d’application réussis des modules BT24 :**

※ Transmission de données sans fil Bluetooth ;

※ Périphériques mobiles et informatiques ;

※ Équipements POS portables ;

※ Transmission sans fil de données pour équipements médicaux ;

※ Contrôle domotique intelligent ;

※ Imprimante Bluetooth ;

※ Jouets télécommandés Bluetooth ;

※ Vélos en libre-service ;

**Ports**

![](media/A162.png)

①STATE : Broche d’état

②RX : Broche de réception

③TX : Broche d’émission

④GND : Masse

⑤VCC : Alimentation

⑥EN : Broche d’activation

Connectez le module BT à la carte de développement.

<table border="1">
<tbody>
<tr class="odd">
<td>Uno</td>
<td>BT24</td>
</tr>
<tr class="even">
<td>TX</td>
<td>RX</td>
</tr>
<tr class="odd">
<td>RX</td>
<td>TX</td>
</tr>
<tr class="even">
<td>VCC</td>
<td>5V</td>
</tr>
<tr class="odd">
<td>GND</td>
<td>GND</td>
</tr>
</tbody>
</table>
### **4.Composants**

| Carte de développement *1 | Driver moteur 8833 *1 | Module LED rouge *1       |
| ------------------------- | -------------------- | ------------------------ |
| ![img](media/A163.jpg)    | ![img](media/A164.jpg) | ![img](media/A165.jpg)  |
| Câble Dupont 3P F-F *1    | Câble USB *1         | Module Bluetooth DX-BT24 *1 |
| ![img](media/A166.jpg)    | ![img](media/A167.jpg) | ![img](media/A168.jpg)  |

### **5.Schéma de câblage**

![](media/A169.png)

RXD, TXD, GND et VCC du module BT sont connectés respectivement à TX, RX, G et 5V.

STATE et BRK du module BT n’ont pas besoin d’être connectés.

<span style="color: rgb(255, 76, 65);">Note :</span> faites attention à la direction du module BT lors de son insertion sur la carte 8833. Ne l’insérez pas avant d’avoir téléversé le code.

### **6.Code de test**

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour référence.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A172.png)

(5).![](media/A173.png)

**Code de test complet**

<span style="color: rgb(255, 76, 65);">**Note :** Avant de téléverser le code de test, vous devez retirer le module Bluetooth, sinon le code ne pourra pas être téléversé. Reconnectez le module Bluetooth après un téléversement réussi.</span>

![](media/A174.png)

### **7.Résultat du test**

Après avoir téléversé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma, puis connectez l’ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, insérez le module BT et la LED clignotera, ensuite il faudra télécharger l’application BT.

### **8.Télécharger l’application Bluetooth**

**Système Apple**

(1).Ouvrez l’App Store sur l’iPhone.

(2). Recherchez keyes BT car et téléchargez l'APP sur votre téléphone.

![](media/A175.png)
    

(3). Après l'installation, entrez dans son interface.

![](media/A176.png)
    

(4). Cliquez sur le bouton "**Connect**" en haut à gauche pour rechercher automatiquement le Bluetooth. Lorsque **BT24** est trouvé, cliquez sur "**Connect**" pour connecter le Bluetooth, puis cliquez sur ![](media/A177.png) pour entrer dans l'interface de contrôle de la voiture intelligente 4WD. 

![](media/A178.png)
    
**Système Android**
    

(1). Entrez dans le Google Play Store pour rechercher “**keyes 4wd**”.

![](media/A179.png)

(2). L'icône de l'application s'affiche ci-dessous après l'installation.

![](media/A180.png)

(3). Cliquez sur l'application pour entrer dans la page suivante.

![](media/A181.png)

(4). Après avoir connecté le Bluetooth, branchez l'alimentation et l'indicateur LED du module Bluetooth clignotera. Appuyez sur “Connect” pour rechercher le Bluetooth.

![](media/A182.jpeg)

(5). Lorsque **BT24** est trouvé, cliquez sur "**connect**" pour connecter le Bluetooth. Lorsque "**connect**" devient "**is connected**", cela indique que la connexion Bluetooth est réussie. Comme montré sur l'image ci-dessous, la LED Bluetooth restera allumée.

![](media/A183.jpeg)

(6). Après avoir connecté le module Bluetooth, cliquez sur ![](media/A80.png) pour régler le débit en bauds à 9600. En appuyant sur le bouton de l'APP Bluetooth, les caractères correspondants s'afficheront, comme indiqué ci-dessous :

![](media/A184.png)

| Touche                                        | Fonction                          |
| --------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                  | Jumeler le module Bluetooth DX-BT24 5.1 |
| ![wps15](media/A186.jpg) | Déconnecter le Bluetooth              |

|                                                              | Caractère de contrôle                                            | Fonction                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                 | Appuyer : F  <br />Relâcher : S                                   | Appuyez sur le bouton, la voiture avance ; <br />relâchez pour arrêter |
| ![wps17](media/A188.jpg)                 | Appuyer : L  <br />Relâcher : S                                   | Appuyez sur le bouton, la voiture tourne à gauche ; <br />relâchez pour arrêter  |
| ![wps18](media/A189.jpg)                 | Appuyer : R  <br />Relâcher : S                                   | Appuyez sur le bouton, la voiture tourne à droite ; <br />relâchez pour arrêter |
| ![wps19](media/A190.jpg)                 | Appuyer : B  <br />Relâcher : S                                   | Appuyez sur le bouton, la voiture recule ; <br />relâchez pour arrêter   |
| ![wps20](media/A191.jpg)                 | Appuyer : “a”  <br />Relâcher : “S”                               | Cliquez pour accélérer (maximum : 255)                               |
| ![wps21](media/A192.jpg)                 | Appuyer : “d”  <br />Relâcher : “S”                               | Cliquez pour ralentir (minimum : 0)                                |
| ![wps22](media/A193.jpg)                 | Cliquez pour démarrer la fonction <br />de détection de gravité du <br />téléphone mobile : cliquez de nouveau pour <br />quitter le contrôle par détection de gravité |                                                              |
| ![wps23](media/A194.jpg)                 | Cliquez pour envoyer “X”,<br /> cliquez de nouveau pour envoyer “S”               | Démarrer la fonction de suivi de ligne ; <br />cliquez de nouveau pour quitter      |
| ![wps24](media/A195.jpg)                 | Cliquez pour envoyer “Y”, <br />cliquez de nouveau pour envoyer “S”               | Démarrer la fonction d'évitement ultrasonique ;<br /> cliquez de nouveau pour quitter |
| ![wps25](media/A196.jpg) | Cliquez pour envoyer “U”, <br />cliquez de nouveau pour envoyer “S”               | Démarrer la fonction de suivi ultrasonique ;<br /> cliquez de nouveau pour quitter |
| ![wps26](media/A197.jpg)                 | Cliquez pour envoyer “G”,<br />cliquez de nouveau pour envoyer “S”                | Démarrer la fonction de restriction ;<br /> cliquez de nouveau pour quitter       |

### **9. Pratique d'extension**

Ici, nous cherchons à utiliser la commande envoyée par le téléphone mobile pour allumer ou éteindre une LED. En regardant le schéma de câblage, une LED est connectée à la broche D9.

![](media/A198.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A170.png)

(3).![](media/A171.png)

(4).![](media/A199.png)

(5).![](media/A173.png)

(6).![](media/A200.png)

(7).![](media/A201.png)

**Code de test complet**

![](media/A202.png)

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l’ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, cliquez sur <td>![](media/A203.png)</td> et <td>![](media/A204.png)</td> pour contrôler l’allumage et l’extinction de la LED.