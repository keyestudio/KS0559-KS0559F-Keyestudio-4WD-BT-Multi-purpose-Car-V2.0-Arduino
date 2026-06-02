# Projet 16 Contrôle de Vitesse Bluetooth pour Voiture Intelligente

![](media/A327.jpeg)

### **1.Description**

Dans ce projet, nous utiliserons un Bluetooth pour ajuster la vitesse de la voiture intelligente. Nous permettons de définir des vitesses variables et de les modifier pour changer la vitesse de la voiture intelligente.

### **2.Diagramme de Flux**

![image-20250513095810478](media/A340.png)

### **3.Schéma de Câblage**

![](media/A329.png)

1). GND, VCC, SDA et SCL de la carte LED 8\*8 sont connectés respectivement à G (GND), V (VCC), A4 et A5 de la carte d’extension.

2). Les broches RXD, TXD, GND et VCC du module Bluetooth sont respectivement connectées à TX, RX, G et 5V sur la carte d’extension du driver moteur 8833, tandis que les broches STATE et BRK du module Bluetooth n’ont pas besoin d’être connectées.

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge est connecté à 5V (V) et le fil orange est connecté à A3.

4). L’alimentation est connectée au port BAT.

### **4.Code de Test**

Avant d’écrire le code, il est nécessaire d’importer les fichiers de bibliothèque de la carte LED 8x16 et du servo. Les étapes spécifiques sont les suivantes :

Cliquez sur ![](media/A29.png) pour entrer dans l’interface de la bibliothèque d’extensions des capteurs/modules/composants, puis recherchez le module “Matrix 8\*16 Aip1640” ![](media/A236.png) et cliquez dessus. Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le module “**Matrix 8\*16 Aip1640**” a été ajouté avec succès.

![Img](media/A237.png)

![](media/A238.png)

Cliquez sur ![](media/A33.png) pour revenir à l’interface de l’éditeur de code, le bloc d’instructions du module “**Matrix 8\*16 Aip1640**” ajouté et du composant “**Servo**” peut être vu dans la zone des modules.

![](media/A330.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A331.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A332.png)

(7).![](media/A333.png)

(8).![](media/A268.png)

(9).![](media/A334.png)

(10).![](media/A341.png)

**Code de Test Complet**

<span style="color: rgb(255, 76, 65);">**Remarque :** Avant de téléverser le code de test, vous devez retirer le module Bluetooth, sinon le code ne pourra pas être téléversé. Reconnectez le module Bluetooth après un téléversement réussi.</span>

![](media/A342.png)

![](media/A343.png)

![](media/A344.png)

![](media/A345.png)

![](media/A346.png)

![](media/A346.png)

### **5.Résultat du Test**

Après avoir téléversé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l’alimentation externe puis mettez l’interrupteur DIP sur ON. Associez l’APP avec le Bluetooth, la voiture intelligente peut être contrôlée pour se déplacer via l’APP.

Appuyez sur ![](media/A347.png), la voiture accélérera, appuyez sur ![](media/A348.png), la voiture ralentira, et la carte LED 8\*16 affichera le motif d’état correspondant de la voiture intelligente.