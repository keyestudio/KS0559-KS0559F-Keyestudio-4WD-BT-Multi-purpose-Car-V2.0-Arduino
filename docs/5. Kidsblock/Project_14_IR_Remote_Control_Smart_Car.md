# Projet 14 Voiture intelligente télécommandée IR

![](media/A307.jpeg)

### **1.Description**

Dans ce projet, nous allons réaliser une voiture intelligente télécommandée IR et appuyer sur le bouton de la télécommande IR pour faire avancer la voiture.

### **2.Diagramme de flux**

![img](media/A308.png)

**La logique spécifique de la voiture intelligente télécommandée IR est présentée ci-dessous :**

| Configuration initiale                                      |           | La carte LED affiche un visage souriant           |
| ----------------------------------------------------------- | --------- | ------------------------------------------------- |
| Télécommande                                               | Valeur clé | État de la touche                                  |
| ![wps6-1747037981476-25](media/A309.jpg) | FF629D    | AvancerLa carte LED 8*8 affiche une icône avant    |
| ![wps7-1747037985784-27](media/A310.jpg) | FFA857    | ReculLa carte LED 8*8 affiche une icône arrière    |
| ![wps8](media/A311.jpg)                  | FF22DD    | Tourner à gaucheLa carte LED 8*8 affiche une icône vers la gauche |
| ![wps9](media/A312.jpg)                  | FFC23D    | Tourner à droiteLa carte LED 8*8 affiche une icône vers la droite |
| ![wps10](media/A313.jpg)                                 | FF02FD    | ArrêtLa carte LED 8*8 affiche “STOP”               |



### **3.Schéma de câblage**

![](media/A314.png)

1). GND, VCC, SDA et SCL du module carte LED 8\*8 sont connectés à G (GND), V (VCC), A4 et A5 de la carte d’extension.
    
2). Comme le récepteur IR est intégré sur la carte d’extension du moteur 8833, aucun câblage supplémentaire n’est nécessaire. Les broches du récepteur IR sur la carte 8833 sont respectivement G (GND), V (VCC) et D3.
    
3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge est connecté à 5V (V) et le fil orange est connecté à A3.
    
4). L’alimentation est connectée au port BAT.
    

### **4.Code de test**

<span style="color: rgb(255, 76, 65);">Veuillez noter : Le module infrarouge montré dans la démonstration logicielle est déjà intégré dans la carte d’extension et n’est pas fourni séparément. Par conséquent, vous ne trouverez pas le module représenté dans l’image ci-dessous dans le produit.![](media/A144.png)</span>

Avant d’écrire le code, il est nécessaire d’importer les fichiers de bibliothèque du capteur ultrasonique, de la carte LED 8x16 et du servo. Les étapes spécifiques sont les suivantes : 
    
Cliquez sur ![](media/A29.png) pour entrer dans l’interface de la bibliothèque d’extensions des capteurs/modules/composants, puis recherchez le capteur “ir remote” ![](media/A144.png) et cliquez dessus. Ainsi, "**Not loaded**" change en "**loaded**", indiquant que le capteur “**ir remote**” a été ajouté avec succès. 

![Img](media/A315.png)

![](media/A146.png)

Cliquez sur ![](media/A33.png) pour revenir à l’interface de l’éditeur de code, le bloc d’instruction du capteur “**ir remote**”, du module “**Matrix 8\*16 Aip1640**” et du composant “**Servo**” peut être vu dans la zone des modules. 

![](media/A316.png)

Vous pouvez faire glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence

(1).![](media/A126.png)

(2).![](media/A317.png)

(3).![](media/A318.png)

(4).![](media/A319.png)

(5).![](media/A287.png)

(6).![](media/A320.png)

(7).![](media/A291.png)

(8).![](media/A321.png)

**Code de test complet**

![](media/A322.png)

![](media/A323.png)

![](media/A324.png)

![](media/A325.png)

![](media/A326.png)

### **5.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l’alimentation externe puis mettez l’interrupteur DIP sur ON. Ensuite, nous pouvons utiliser la télécommande IR pour faire déplacer la voiture et la carte LED 8X16 affichera le motif d’état correspondant.