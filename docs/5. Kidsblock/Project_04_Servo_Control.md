# Projet 4 Contrôle du Servo

### **1.Description**

![](media/A90.jpeg)

Le moteur servo est un actionneur rotatif à contrôle de position. Il se compose principalement d’un boîtier, d’une carte de circuit, d’un moteur sans noyau, d’un engrenage et d’un capteur de position. Son principe de fonctionnement est que le servo reçoit le signal envoyé par les MCU ou les récepteurs et produit un signal de référence avec une période de 20 ms et une largeur de 1,5 ms, puis compare la tension de polarisation continue acquise à la tension du potentiomètre et obtient la sortie de la différence de tension.

![](media/A91.png)

En général, le servo possède trois fils de couleur marron, rouge et orange. Le fil marron est la masse, le rouge est la ligne de pôle positif et l’orange est la ligne de signal.

L’angle de rotation du moteur servo est contrôlé en régulant le rapport cyclique du signal PWM (Pulse-Width Modulation). Le cycle standard du signal PWM est de 20 ms (50 Hz). Théoriquement, la largeur est comprise entre 1 ms et 2 ms, mais en réalité, elle est comprise entre 0,5 ms et 2,5 ms. La largeur correspond à l’angle de rotation de 0° à 180°. Mais notez que pour des moteurs de marques différentes, le même signal peut correspondre à des angles de rotation différents.

![](media/A92.jpg)

Les angles de servo correspondants sont indiqués ci-dessous :

![](media/A93.png)

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

| Carte de développement *1 | Driver moteur 8833 *1     | Servo*1                                     |
| ------------------------- | ------------------------- | ------------------------------------------- |
| ![img](media/A94.jpg)     | ![img](media/A95.jpg)     | ![img](media/A96.png)                       |
| Support batterie 18650*1  | Câble USB*1               | Batterie 18650*2 (fournie par l’utilisateur) |
| ![img](media/A97.png)     | ![img](media/A98.jpg)     | ![img](media/A99.png)                       |

### **4.Schéma de câblage**

![](media/A100.png)

Note de câblage : Le servo est connecté à G (GND), V (VCC) et A3, le fil marron du servo est relié à la masse (G), le rouge est connecté au 5 V (V) et l’orange est attaché à A3.

Le servo doit être connecté à une alimentation externe en raison de sa forte demande en courant de pilotage. En général, le courant de la carte de développement n’est pas suffisant. Sans alimentation externe, la carte de développement pourrait être endommagée.

### **5.Code de test**

Avant d’écrire le code, il est nécessaire d’importer la bibliothèque servo. Les étapes spécifiques sont les suivantes :

Cliquez sur ![](media/A29.png) pour entrer dans l’interface de la bibliothèque d’extensions des capteurs/modules/composants, puis recherchez "**Servo**".

![](media/A101.png)

Sélectionnez le composant et cliquez dessus. Ainsi, "**Not Loaded**" change en "**loaded**", indiquant que le composant "**Servo**" a été ajouté avec succès.

![Img](media/A102.png)

![](media/A103.png)

Cliquez sur ![](media/A33.png) pour revenir à l’éditeur de code, et dans la zone des modules vous pouvez voir le bloc de directive du composant "**Servo**" ajouté.

![](media/A104.png)

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A105.png)

(2).![](media/A106.png)

(3).![](media/A107.png)

**Code de test complet**

![](media/A108.png)

### **6.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et alimentez l’alimentation externe. Après la mise sous tension, tournez l’interrupteur DIP sur la position "ON", alors le servo oscillera dans la plage de 0° à 180°.