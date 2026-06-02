# Projet 15 Voiture Intelligente Contrôlée par Bluetooth

![](media/A327.jpeg)

### **1.Description**

Nous avons appris les connaissances de base sur le Bluetooth. Dans cette leçon, nous allons fabriquer une voiture intelligente contrôlée par Bluetooth. Dans ce projet, nous considérons le téléphone mobile comme l’émetteur (hôte), et la voiture intelligente connectée au module Bluetooth BT24 (esclave) comme le récepteur, et utilisons l’application mobile pour contrôler la voiture intelligente via le Bluetooth.

### **2.Boutons de Contrôle de l’APP**

| Touche                                        | Fonction                          |
| --------------------------------------------- | --------------------------------- |
| ![wps14](media/A185.jpg)                       | Jumeler le module Bluetooth DX-BT24 5.1 |
| ![wps15](media/A186.jpg)                       | Déconnecter le Bluetooth          |

|                                                              | Caractère de contrôle                                         | Fonction                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ![wps16](media/A187.jpg)                                     | Appuyer : F  <br />Relâcher : S                              | Appuyer sur le bouton, la voiture avance ; <br />relâcher pour arrêter |
| ![wps17](media/A188.jpg)                                     | Appuyer : L  <br />Relâcher : S                              | Appuyer sur le bouton, la voiture tourne à gauche ; <br />relâcher pour arrêter  |
| ![wps18](media/A189.jpg)                                     | Appuyer : R  <br />Relâcher : S                              | Appuyer sur le bouton, la voiture tourne à droite ; <br />relâcher pour arrêter |
| ![wps19](media/A190.jpg)                                     | Appuyer : B  <br />Relâcher : S                              | Appuyer sur le bouton, la voiture recule ; <br />relâcher pour arrêter   |
| ![wps20](media/A191.jpg)                                     | Appuyer : “a”  <br />Relâcher : “S”                          | Cliquer pour accélérer (maximum : 255)                       |
| ![wps21](media/A192.jpg)                                     | Appuyer : “d”  <br />Relâcher : “S”                          | Cliquer pour ralentir (minimum : 0)                          |
| ![wps22](media/A193.jpg)                                     | Cliquer pour démarrer la fonction de détection de gravité du téléphone mobile : cliquer à nouveau pour quitter le contrôle par gravité |                                                              |
| ![wps23](media/A194.jpg)                                     | Cliquer pour envoyer “X”, <br />cliquer à nouveau pour envoyer “S” | Démarrer la fonction de suivi de ligne ; <br />cliquer à nouveau pour quitter |
| ![wps24](media/A195.jpg)                                     | Cliquer pour envoyer “Y”, <br />cliquer à nouveau pour envoyer “S” | Démarrer la fonction d’évitement ultrasonique ; <br />cliquer à nouveau pour quitter |
| ![wps25](media/A196.jpg)                                     | Cliquer pour envoyer “U”, <br />cliquer à nouveau pour envoyer “S” | Démarrer la fonction de suivi ultrasonique ; <br />cliquer à nouveau pour quitter |
| ![wps26](media/A197.jpg)                                     | Cliquer pour envoyer “G”, <br />cliquer à nouveau pour envoyer “S” | Démarrer la fonction de restriction ; <br />cliquer à nouveau pour quitter |

### **3.Diagramme de Flux**

![img](media/A328.png)

### **4.Schéma de Câblage**

![](media/A329.png)

1). GND, VCC, SDA et SCL de la carte LED 8\*8 sont connectés respectivement à G (GND), V (VCC), A4 et A5 de la carte d’extension.
    
2). Les broches RXD, TXD, GND et VCC du module Bluetooth sont respectivement connectées à TX, RX, G et 5V sur la carte d’extension du driver moteur 8833, tandis que les broches STATE et BRK du module Bluetooth n’ont pas besoin d’être connectées.
    
3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge est connecté à 5V (V) et le fil orange est connecté à A3.
    
4). L’alimentation est connectée au port BAT
    

### **5.Code de Test**

Avant d’écrire le code, il est nécessaire d’importer les fichiers de bibliothèque de la carte LED 8x16 et du servo. Les étapes spécifiques sont les suivantes : 
    
Cliquez sur ![](media/A29.png) pour entrer dans l’interface de la bibliothèque d’extensions des capteurs/modules/composants, puis recherchez le module “**Matrix 8\*16 Aip1640**” ![](media/A236.png) et cliquez dessus. Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le module “**Matrix 8\*16 Aip1640**” a été ajouté avec succès. 

![Img](media/A237.png)  

![](media/A238.png)

Cliquez sur ![](media/A33.png) pour revenir à l’interface de l’éditeur de code, le bloc d’instructions du module “**Matrix 8\*16 Aip1640**” ajouté et du composant “**Servo**” peut être vu dans la zone des modules. 

![](media/A330.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

**Code de test complet**

<span style="color: rgb(255, 76, 65);">**Note :** Avant de téléverser le code de test, vous devez retirer le module Bluetooth, sinon le code ne pourra pas être téléversé. Reconnectez le module Bluetooth après avoir téléversé le code avec succès.</span>

![](media/A335.png)

![](media/A336.png)

![](media/A337.png)

![](media/A338.png)

![](media/A339.png)

### **6. Résultat du test**

Après avoir téléversé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l’alimentation externe puis mettez l’interrupteur DIP sur ON.

Insérez le module BT et ouvrez votre téléphone pour connecter le Bluetooth afin de contrôler la voiture intelligente. La voiture avancera, reculera, tournera à gauche et à droite et s’arrêtera. De plus, la carte LED 8\*8 affichera les motifs correspondants.