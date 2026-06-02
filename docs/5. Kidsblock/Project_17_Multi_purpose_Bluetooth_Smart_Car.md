# Projet 17 Voiture intelligente Bluetooth polyvalente

![](media/A349.jpeg)

### **1.Description**

Dans les projets précédents, la voiture ne réalise qu'une seule fonction. Cependant, dans cette leçon, nous allons intégrer toutes ses fonctions via un Bluetooth.

### **2.Diagramme de flux**

![](media/A350.png)

### **3.Schéma de câblage**

![](media/A351.png)

1). GND, VCC, SDA et SCL de la carte LED 8\*8 sont connectés à G (GND), V (VCC), A4 et A5 de la carte d'extension.

2). Les broches RXD, TXD, GND et VCC du module Bluetooth sont respectivement connectées à TX, RX, G et 5V sur la carte d'extension du driver moteur 8833, tandis que les broches STATE et BRK du module Bluetooth n'ont pas besoin d'être connectées.

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge est connecté à 5V (V) et le fil orange est connecté à A3.

4). G, V, S1, S2 et S3 du capteur de suivi de ligne sont connectés à G (GND), V (VCC), D11, D7 et D8 de la carte d'extension capteur.

5). VCC, Trig, Echo et Gnd du capteur ultrason sont connectés à 5V (V), D12 (S), D13 (S) et Gnd (G).

6). L'alimentation est connectée au port BAT.

### **4.Code de test**

Avant d’écrire le code, il est nécessaire d’importer les fichiers de bibliothèque du capteur ultrason, de la carte LED 8x16 et du servo. Les étapes spécifiques sont les suivantes :

Cliquez sur ![](media/A29.png) pour entrer dans l’interface de la bibliothèque d’extensions des capteurs/modules/composants, puis recherchez le capteur “**Ultrasonic**” ![](media/A122.png) et cliquez dessus. Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le capteur “**Ultrasonic**” a été ajouté avec succès.

![Img](media/A300.png)

![](media/A124.png)

Cliquez sur ![](media/A33.png) pour revenir à l’interface de l’éditeur de code, le bloc d’instructions du capteur “**Ultrasonic**” ajouté, du module “**Matrix 8\*16 Aip1640**” et du composant “**Servo**” peut être vu dans la zone des modules.

![](media/A285.png)

**Code de test complet**

<span style="color: rgb(255, 76, 65);">**Remarque :** Avant de téléverser le code de test, vous devez retirer le module Bluetooth, sinon le code ne pourra pas être téléversé. Reconnectez le module Bluetooth après un téléversement réussi.</span>

![](media/A352.png)

### **5.Résultat du test**

Après avoir téléversé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l’alimentation externe puis mettez l’interrupteur DIP sur ON.

Après que le module Bluetooth soit connecté à l’APP et que l’application mobile soit connectée avec succès au Bluetooth, la voiture intelligente peut être contrôlée par l’application mobile. Nous pouvons réaliser les fonctions correspondantes en appuyant sur les boutons correspondants de l’application mobile.