# Projet 9 Panneau LED d'Expression Faciale

![](media/A221.png)

### **1.Description** 

Quel plaisir ce serait d'ajouter un panneau d'expression à un robot. Et le panneau LED 8\*16 de Keyestudio peut faire l'affaire. Avec son aide, vous pouvez concevoir vous-mêmes des expressions faciales, images, motifs et autres affichages.

Le panneau LED 8\*16 est équipé de 128 LEDs. Les données du microprocesseur (Arduino) communiquent avec l'AiP1640 via une interface bus à deux fils. Ainsi, il peut contrôler l'allumage et l'extinction des 128 LEDs sur le module, afin de faire afficher sur la matrice de points du module le motif souhaité. Un câble HX-2.54 4 broches est fourni pour faciliter le câblage.

### **2.Spécifications**

- Tension de fonctionnement : DC 3.3-5V

- Perte de puissance : 400mW

- Fréquence d'oscillation : 450KHz

- Courant de pilotage : 200mA

- Température de fonctionnement : -40\~80℃

- Mode de communication : I2C
  

### **3.Schéma de circuit**

![](media/A222.png)

### **4.Principe de fonctionnement**

Comment contrôler chaque LED de la matrice 8\*16 ? On sait que chaque octet contient 8 bits et que chaque bit vaut 0 ou 1. Quand il est à 0, la LED est éteinte, quand il est à 1, la LED est allumée. Un octet peut contrôler une colonne de LEDs, et naturellement 16 octets peuvent contrôler 16 colonnes de LEDs, ce qui correspond à la matrice 8\*16.

### **5.Description des broches et protocole de communication**

Les données du microprocesseur (Arduino) communiquent avec l'AiP1640 via un câble bus à deux fils.

Le diagramme du protocole de communication est le suivant (SCLK) est SCL, (DIN) est SDA.

![](media/A223.png)

①Condition de départ pour l'entrée des données : SCL est au niveau haut et SDA passe de haut à bas.

②Pour le réglage de la commande de données, il existe les méthodes illustrées dans la figure ci-dessous.

Dans notre programme exemple, on choisit la méthode pour **ajouter 1 automatiquement à l'adresse**, la valeur binaire est 0100 0000 et la valeur hexadécimale correspondante est 0x40.

![Img](media/A224.png)

③Pour le réglage de la commande d'adresse, l'adresse peut être sélectionnée comme indiqué ci-dessous.

Le premier 00H est sélectionné dans notre programme exemple, et le nombre binaire 1100 0000 correspond à l'hexadécimal 0xc0.

![Img](media/A225.png)

④La condition pour l'entrée des données est que lorsque SCL est au niveau haut lors de l'entrée des données, le signal sur SDA doit rester inchangé. Ce n'est que lorsque le signal d'horloge sur SCL est au niveau bas que le signal sur SDA peut être modifié. L'entrée des données se fait d'abord par le bit faible, puis par le bit fort.

⑤La condition de fin de transmission des données est que lorsque SCL est au niveau bas, SDA au niveau bas et SCL au niveau haut, le niveau de SDA devient haut.

⑥Contrôle de l'affichage, réglage de différentes largeurs d'impulsion, la largeur d'impulsion peut être sélectionnée comme indiqué dans la figure ci-dessous.

Dans l'exemple, la largeur d'impulsion est 4/16, et l'hexadécimal correspondant à 1000 1010 est 0x8A.

![Img](media/A226.png)

**Instructions pour l'utilisation de l'outil de matrice**

L'outil de matrice de points utilise la version en ligne, et le lien est :[http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

①Entrez le lien et la page apparaît comme ci-dessous

![](media/A227.png)

②La matrice de points est 8\*16, donc ajustez la hauteur à 8 et la largeur à 16, comme montré dans la figure ci-dessous.

![](media/A228.png)

③Générez les données hexadécimales à partir du motif

Comme montré dans la figure ci-dessous, appuyez sur le bouton gauche de la souris pour sélectionner, clic droit pour annuler ; dessinez le motif souhaité, cliquez sur Générer, et les données hexadécimales nécessaires seront générées.

![](media/A229.png)

### **6.Composants**

| Carte de développement *1 | Driver moteur 8833 *1           | Panneau LED 8x16*1         |
| ------------------------- | ------------------------------ | -------------------------- |
| ![img](media/A230.jpg)    | ![img](media/A231.jpg)          | ![img](media/A232.jpg)     |
| Câble USB*1               | Fil Dupont HX-2.54 4P 200mm *1 |                            |
| ![img](media/A233.jpg)    | ![img](media/A234.jpg)          |                            |



### **7.Schéma de câblage**

![](media/A235.png)

Le GND, VCC, SDA et SCL de la carte lumineuse LED 8x16 sont respectivement connectés à la carte d'extension de capteur keyestudio - (GND), + (VCC), A4, A5 pour la communication série à deux fils.

(<span style="color: rgb(255, 76, 65);">Remarque :</span> Bien qu'il soit connecté avec la broche IIC de l'Arduino, ce module n'est pas destiné à la communication IIC. Et le port IO ici sert à simuler la communication I2C et peut être connecté à n'importe quelles deux broches).

### **8. Code de test**

Avant d'écrire le code, il est nécessaire d'importer le fichier de bibliothèque de la carte LED 8x16. Les étapes spécifiques sont les suivantes :

Cliquez sur ![](media/A29.png) pour entrer dans l'interface de la bibliothèque d'extensions des capteurs/modules/composants, puis recherchez le module "**Matrix 8\*16 Aip1640**" ![](media/A236.png) et cliquez dessus. Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le module "**Matrix 8\*16 Aip1640**" a été ajouté avec succès.

![Img](media/A237.png)

![](media/A238.png)

Cliquez sur ![](media/A33.png) pour revenir à l'interface de l'éditeur de code, le bloc d'instruction du module ajouté "**Matrix 8\*16 Aip1640**" peut être vu dans la zone des modules.

![](media/A239.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A240.png)

**Code de test complet**

![](media/A241.png)

### **9. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis mettez l'interrupteur DIP sur ON, un motif en forme de sourire s'affichera sur la carte LED.

![](media/A242.png)

### **10. Explication du code**

Nous utilisons l'outil modulus que nous venons d'apprendre, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), pour faire afficher sur la matrice de points le motif de démarrage, avancer, s'arrêter puis effacer le motif. L'intervalle de temps est de 2000 ms.

![image-20250513092102687](media/A243.png)![image-20250513092107293](media/A244.png)![image-20250513092113035](media/A245.png)![image-20250513092116952](media/A246.png)


Bloc d'instruction pour visage souriant ![](media/A247.png)

Bloc d'instruction pour expression : ![](media/A248.png)

Bloc d'instruction pour cœur ![](media/A249.png)

Bloc d'instruction pour avancer ![](media/A250.png)

Bloc d'instruction pour **reculer** ![](media/A251.png)

Bloc d'instruction pour **tourner à gauche** ![](media/A252.png)

Bloc d'instruction pour **tourner à droite** ![](media/A253.png)

Bloc d'instruction pour **arrêter** ![](media/A254.png)

Bloc d'instruction pour **effacer l'écran** ![](media/A255.png)

![](media/A235.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A240.png)

(3).![](media/A256.png)

**Code de test complet**

![](media/A257.png)

Après avoir téléchargé le code de test, la carte d'expression faciale affiche ces motifs dans l'ordre et répète cette séquence.

![image-20250513092222972](media/A258.png)![image-20250513092233711](media/A259.png)![image-20250513092238552](media/A260.png)