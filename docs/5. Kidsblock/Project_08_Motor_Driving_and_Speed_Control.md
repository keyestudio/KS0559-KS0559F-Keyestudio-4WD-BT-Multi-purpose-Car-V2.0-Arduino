# Projet 8 Conduite de moteur et contrôle de vitesse

![](media/A205.png)

### **1.Description**

Il existe de nombreuses façons de piloter des moteurs. Notre voiture utilise la puce de pilote de moteur DRV8833 la plus couramment utilisée, qui fournit une solution de commande électrique à pont double canal pour les jouets, imprimantes et autres applications intégrées de moteurs.

Lorsque nous empilons la carte d'extension du pilote sur la carte de développement 4.0 et que nous alimentons le BAT, puis réglons l'interrupteur DIP sur la position ON, l'alimentation externe alimentera les deux cartes en même temps. Pour faciliter les connexions de câblage, la carte d'extension du pilote est équipée d'un port anti-inversion (PH2.0-2P-3P-4P-5P). Vous pouvez connecter directement les moteurs, l'alimentation et les modules capteurs à la carte d'extension du pilote.

L'interface Bluetooth de la carte d'extension du pilote est entièrement compatible avec le module Bluetooth DX-BT24 5.1. Lors de la connexion du module Bluetooth, il vous suffit de le brancher sur l'interface correspondante. En même temps, des broches en rangée 2.54 sont utilisées pour extraire certains ports numériques et analogiques inutilisés sur la carte d'extension du pilote, ce qui vous permet d'ajouter d'autres capteurs et de réaliser des expériences d'extension.

La carte d'extension peut être connectée à quatre moteurs DC. Lorsque le cavalier est connecté par défaut, les moteurs des ports A et A1 ainsi que B et B1 sont connectés en parallèle et ont la même loi de mouvement. 8 cavaliers peuvent être utilisés pour contrôler la direction de rotation des 4 interfaces moteur.

Par exemple, lorsque les 2 cavaliers devant B1 du moteur M1 passent d'une connexion transversale à une connexion longitudinale, la direction de rotation du moteur M1 sera opposée à la direction de rotation d'origine.

### **2.Spécifications**

- Tension d'entrée pour la logique : DC 5V

- Tension d'entrée pour la commande : DC 6-9 V

- Courant de fonctionnement pour la logique : \<36mA

- Courant de fonctionnement pour la commande : \<2A

- Dissipation maximale de puissance : 25W (T=75℃)

- Niveau d'entrée pour le signal de commande : niveau haut est 2.3V\<Vin\<5V, niveau bas est -0.3V\<Vin\<1.5V

- Température de fonctionnement : -25＋130℃

### **3.Carte d'extension pilote moteur Keyestudio 8833**

![](media/A206.png)

**Principe de fonctionnement**

Nous utilisons le mode de connexion parallèle du même côté pour les quatre moteurs, qui peut être considéré comme deux groupes de moteurs. Comme indiqué dans le schéma de câblage, B et B1 forment un groupe, et A et A1 un autre groupe.

Les moteurs du même groupe doivent tourner dans la même direction. S'ils sont différents, veuillez ajuster les cavaliers correspondants à côté de la borne pour changer la direction.

Comme montré ci-dessous, si les directions de A et A1 sont différentes, ajustez la direction des cavaliers jusqu'à ce que la direction de mouvement des moteurs du même groupe soit cohérente.

![](media/A207.png)

D'après le schéma ci-dessus, on sait que la broche de direction du moteur A est D4, la broche de vitesse est D6 ; D2 est la broche de direction du moteur B ; et D6 est la broche de vitesse.

Le PWM pilote la voiture robot. La valeur PWM est dans la plage de 0-255. Lorsque nous réglons la direction sur HIGH, plus le nombre PWM est petit, plus la rotation du moteur est rapide.

<table border="1">
<tbody>
<tr class="odd">
<td></td>
<td>D2</td>
<td>D5（PWM）</td>
<td>Moteur B (gauche)</td>
<td>D4</td>
<td>D6（PWM）</td>
<td>Moteur A (droite)</td>
</tr>
<tr class="even">
<td>Avancer</td>
<td>HIGH</td>
<td>255-200</td>
<td>Rotation horaire</td>
<td>HIGH</td>
<td>255-200</td>
<td>Rotation horaire</td>
</tr>
<tr class="odd">
<td>Reculer</td>
<td>LOW</td>
<td>200</td>
<td>Rotation antihoraire</td>
<td>LOW</td>
<td>200</td>
<td>Rotation antihoraire</td>
</tr>
<tr class="even">
<td>Tourner à gauche</td>
<td>HIGH</td>
<td>255-200</td>
<td>Rotation horaire</td>
<td>LOW</td>
<td>200</td>
<td>Rotation antihoraire</td>
</tr>
<tr class="odd">
<td>Tourner à droite</td>
<td>LOW</td>
<td>200</td>
<td>Rotation antihoraire</td>
<td>HIGH</td>
<td>255-200</td>
<td>Rotation horaire</td>
</tr>
</tbody>
</table>
### **4.Composants**

| Carte de développement *1      | Pilote de moteur 8833 *1      | Câble USB*1                       |
| ----------------------------- | ----------------------------- | --------------------------------- |
| ![img](media/A208.jpg)        | ![img](media/A209.jpg)        | ![img](media/A210.jpg)             |
| Support de batterie 18650*1   | Moteur*4                      | Batterie 18650 *2 (fournie par l'utilisateur) |
| ![img](media/A211.png)        | ![img](media/A212.jpg)        | ![img](media/A213.png)             |



### **5. Schéma de câblage**

![](media/A214.png)

Connectez l'alimentation au port BAT.

### **6. Code de test**

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence

(1).![](media/A126.png)

(2).![](media/A215.png)

(3).![](media/A216.png)

**Code de test complet**

![Img](media/A217.png)

![](media/A218.png)

### **7. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis alimentez l'alimentation externe et mettez l'interrupteur DIP sur ON, la voiture avancera pendant 2s, reculera pendant 2s, tournera à gauche pendant 2s, à droite pendant 2s et s'arrêtera pendant 2s.

### **8. Explication du code**

Ajustez la vitesse que le PWM contrôle sur le moteur, branchez de la même manière.

**Code de test complet**

![Img](media/A219.png)

![](media/A220.png)

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis alimentez l'alimentation externe et mettez l'interrupteur DIP sur ON, vous constaterez que la vitesse du moteur est beaucoup plus lente.

<span style="color: rgb(255, 76, 65);">Remarque : </span>Une batterie faible entraînera une vitesse de moteur lente.