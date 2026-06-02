# Projet 12 Voiture Intelligente Suiveuse Ultrasonique

![](media/A280.png)

### **1.Description**

Dans ce projet, nous allons détecter la distance entre la voiture intelligente 4WD et les obstacles devant elle grâce à un capteur ultrasonique afin de piloter deux moteurs de manière à faire avancer la voiture et afficher un motif de visage souriant sur la matrice LED 8\*8.

### **2.Diagramme de Flux**

![img](media/A281.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Détection</td>
<td>Distance mesurée des obstacles devant</td>
<td>distance (unité : cm)</td>
</tr>
<tr class="even">
<td>Paramétrage</td>
<td>La matrice LED 8*16 affiche un motif souriant.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Positionner le servo à 90°</td>
<td></td>
</tr>
<tr class="even">
<td>Condition</td>
<td>distance≥20 et distance≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>État</td>
<td>Avancer</td>
<td></td>
</tr>
<tr class="even">
<td>Condition</td>
<td>distance＞10 et distance＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>distance＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Condition</td>
<td>arrêt</td>
<td></td>
</tr>
<tr class="odd">
<td>Condition</td>
<td>distance≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Condition</td>
<td>Reculer</td>
<td></td>
</tr>
</tbody>
</table>


### **3.Schéma de Câblage**

![](media/A282.png)

**Câblage :**

1). GND, VCC, SDA et SCL de la matrice LED 8\*8 sont connectés à G (GND), V (VCC), A4 et A5 de la carte d’extension.

2). VCC, Trig, Echo et Gnd du capteur ultrasonique sont connectés à 5V (V), D12 (S), D13 (S) et Gnd (G).

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge à 5V (V) et le fil orange à A3.

4). L’alimentation est connectée au port BAT.

### **4.Code de Test**

Avant d’écrire le code, il est nécessaire d’importer les fichiers de bibliothèque du capteur ultrasonique, de la matrice LED 8x16 et du servo. Les étapes spécifiques sont les suivantes :

Cliquez sur ![](media/A29.png) pour entrer dans l’interface de la bibliothèque d’extensions des capteurs/modules/composants, puis recherchez le capteur “Ultrasonic” ![](media/A122.png) et cliquez dessus.

Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le capteur “**Ultrasonic**” a été ajouté avec succès.

![Img](media/A283.png)

![](/media/A284.png)

Les fichiers de bibliothèque de la matrice LED 8x16 et du servo sont ajoutés de la même manière que pour le capteur ultrasonique.

Cliquez sur ![](media/A33.png) pour revenir à l’interface de l’éditeur de code, le bloc d’instructions du capteur “**Ultrasonic**”, du module “**Matrix 8\*16 Aip1640**” et du composant “**Servo**” peut être vu dans la zone des modules.

![](media/A285.png)

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence

(1).![](media/A126.png)

(2).![](media/A286.png)

(3).![](media/A287.png)

(4).![](media/A288.png)

(5).![](media/A268.png)

(6).![](media/A289.png)

(7).![](media/A290.png)

(8).![](media/A291.png)

(9).![](media/A292.png)

**Code de Test Complet**

![](media/A293.png)

![](media/A294.png)

![](media/A295.png)

### **5.Résultat du Test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma, alimentez la carte externe puis mettez l’interrupteur DIP sur ON. Positionnez le servo à 90°, la voiture intelligente se déplacera en fonction des obstacles et la matrice LED 8X16 affichera un “sourire”.