# Projet 13 Voiture Intelligente à Évitement d’Obstacles Ultrasonique

![](media/A296.png)

### **1.Description**

Dans ce projet, nous visons à réaliser une voiture intelligente à évitement d’obstacles ultrasonique. Nous utiliserons l’ultrason pour détecter la distance par rapport à l’obstacle, ce qui peut être utilisé pour contrôler le servo afin de faire tourner la voiture. Parallèlement, la matrice LED 8x16 affichera le motif de statut correspondant.

### **2.Diagramme de Flux**

![img](media/A297.png)

**La logique spécifique de la voiture intelligente à évitement d’obstacles ultrasonique est montrée ci-dessous :**

![Img](media/A298.png)

![Img](media/A299.png)

### **3.Schéma de Câblage**

![](media/A282.png)

1). GND, VCC, SDA et SCL du module matrice LED 8\*8 sont connectés à G (GND), V (VCC), A4 et A5 de la carte d’extension.

2). VCC, Trig, Echo et Gnd du capteur ultrasonique sont connectés à 5V (V), D12 (S), D13 (S) et Gnd (G).

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge est connecté à 5V (V) et le fil orange est connecté à A3.

4). L’alimentation est connectée au port BAT.

### **4.Code de Test**

Avant d’écrire le code, il est nécessaire d’importer les fichiers de bibliothèque du capteur ultrasonique, de la matrice LED 8x16 et du servo. Les étapes spécifiques sont les suivantes :

Cliquez sur ![](media/A29.png) pour entrer dans l’interface de la bibliothèque d’extensions des capteurs/modules/composants, puis recherchez le capteur “Ultrasonic” ![](media/A122.png) et cliquez dessus. Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le capteur “**Ultrasonic**” a été ajouté avec succès.

![Img](media/A300.png)

![](/media/A284.png)

Cliquez sur ![](media/A33.png) pour revenir à l’interface de l’éditeur de code, le bloc d’instructions du capteur “**Ultrasonic**”, du module “**Matrix 8\*16 Aip1640**” et du composant “**Servo**” peut être vu dans la zone des modules.

![](media/A285.png)

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A301.png)

(3).![](media/A302.png)

(4).![](media/A287.png)

(5).![](media/A288.png)

(6).![](media/A268.png)

(7).![](media/A289.png)

(8).![](media/A292.png)

(9).![](media/A290.png)

(10).![](media/A291.png)

**Code de Test Complet**

![](media/A303.png)

![](media/A304.png)

![](media/A305.png)

![](media/A306.png)

### **5.Résultat du Test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez la carte avec une source externe puis mettez l’interrupteur DIP sur ON.

La voiture intelligente avance et évite automatiquement les obstacles. Lorsqu’il n’y a pas de route devant, le servo fera pivoter le capteur ultrasonique pour scanner les distances à gauche, au centre et à droite, et la voiture tournera vers le côté libre. Parallèlement, la matrice LED 8x16 affichera le motif de statut correspondant.