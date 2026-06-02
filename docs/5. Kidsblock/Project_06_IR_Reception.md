# Projet 6 Réception IR

![](media/A141.png)

### **1.Description** 

Il ne fait aucun doute que la télécommande infrarouge est omniprésente dans la vie quotidienne. Elle est utilisée pour contrôler divers appareils électroménagers, tels que les téléviseurs, les chaînes stéréo, les magnétoscopes et les récepteurs de signaux satellites. La télécommande infrarouge est composée d’un système d’émission infrarouge et d’un système de réception infrarouge, c’est-à-dire d’une télécommande infrarouge, d’un module de réception infrarouge et d’un microcontrôleur capable de décoder.  

![](media/A142.png)

Le signal porteur infrarouge à 38K émis par la télécommande est codé par la puce d’encodage dans la télécommande. Il est composé d’une section de code pilote, code utilisateur, code inverse utilisateur, code de données et code inverse de données. L’intervalle de temps des impulsions est utilisé pour distinguer s’il s’agit d’un signal 0 ou 1 et le codage est constitué de ces signaux 0 et 1.

Le code utilisateur de la même télécommande est constant tandis que le code de données permet de distinguer la touche.

Lorsque le bouton de la télécommande est pressé, la télécommande envoie un signal porteur infrarouge. Lorsque le récepteur IR reçoit le signal, le programme décode le signal porteur et détermine quelle touche est pressée. Le MCU décode le signal 01 reçu, permettant ainsi de juger quelle touche est pressée sur la télécommande.

Le récepteur infrarouge que nous utilisons est un module récepteur infrarouge. Il est principalement composé d’une tête réceptrice infrarouge, qui est un dispositif intégrant réception, amplification et démodulation. Son circuit intégré interne a déjà effectué la démodulation, et peut réaliser la réception infrarouge jusqu’à la sortie compatible avec les signaux TTL.

De plus, il est adapté pour la télécommande infrarouge et la transmission de données infrarouges. Le module de réception infrarouge fabriqué par le récepteur ne possède que trois broches : ligne de signal, VCC et GND. Il est très pratique pour communiquer avec Arduino et d’autres microcontrôleurs.

### **2.Spécifications**

- Tension de fonctionnement : 3.3-5V (DC)

- Signal de sortie : Signal numérique

- Angle de réception : 90 degrés

- Fréquence : 38 kHz

- Distance de réception : 10 m

L’image montre le produit réel et le schéma du circuit du récepteur infrarouge.

![](media/A141.png)

![](media/A143.png)

### **3.Composants**

| Carte de développement *1 | Driver moteur 8833 *1 | Module LED rouge *1 |
| ------------------------- | -------------------- | ------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg) | ![img](media/A44.jpg) |
| Câble Dupont 3P F-F *1    | Câble USB *1          |                     |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg) |                     |

Puisque la carte 8833 intègre le récepteur IR, il n’est pas nécessaire de faire de câblage. Les broches du module récepteur IR sont G (GND), V (VCC) et D3.

### **4.Code de test**

<span style="color: rgb(255, 76, 65);">Veuillez noter : Le module infrarouge montré dans la démonstration logicielle est déjà intégré dans la carte d’extension et n’est pas fourni séparément. Par conséquent, vous ne trouverez pas le module représenté dans l’image ci-dessous dans le produit.![](media/A144.png)</span>

Avant d’écrire le code, il est nécessaire d’importer le fichier de bibliothèque du capteur récepteur IR. Les étapes spécifiques sont les suivantes : 

Cliquez sur ![](media/A29.png) pour entrer dans l’interface de la bibliothèque d’extensions des capteurs/modules/composants, puis recherchez le capteur “**ir remote**” ![](media/A144.png) et cliquez dessus. Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le capteur “ir remote” a été ajouté avec succès. 

![Img](media/A145.png)

![](media/A146.png)

Cliquez sur ![](media/A33.png) pour revenir à l’interface de l’éditeur de code, le bloc d’instruction du capteur “**ir remote**” ajouté peut être vu dans la zone des modules. 

![](media/A147.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A149.png)

(4).![](media/A150.png)

**Code de test complet**

![](media/A151.png)

### **5.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l'ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, cliquez sur ![](media/A80.png) pour régler le débit en bauds à 9600.

Sortez la télécommande et envoyez un signal au capteur récepteur infrarouge. Vous pouvez voir la valeur de la touche correspondante, si la durée d'appui sur la touche est trop longue, FFFFFFFF a tendance à afficher des caractères corrompus.

![](media/A152.png)

Les valeurs des touches de la télécommande sont affichées ci-dessous.

![](media/A153.jpeg)

### **6. Pratique d'extension**

Nous avons décodé la valeur des touches de la télécommande IR. Que diriez-vous de contrôler la LED avec la valeur mesurée ? Nous pourrions concevoir une expérience.

Fixez une LED sur D9, puis appuyez sur les touches de la télécommande pour allumer et éteindre la LED.

![](media/A154.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A148.png)

(3).![](media/A155.png)

(4).![](media/A150.png)

(5).![](media/A156.png)

(6).![](media/A157.png)

(7).![](media/A158.png)

(8).![](media/A159.png)

**Code de test complet**

![](media/A160.png)

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l'ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, appuyer sur la touche "**OK**" de la télécommande permet d'allumer et d'éteindre la LED.