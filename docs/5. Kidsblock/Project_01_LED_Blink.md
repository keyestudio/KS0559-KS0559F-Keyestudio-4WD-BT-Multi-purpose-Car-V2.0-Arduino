# Projet 1 Clignotement LED

### **1.Description**

![](media/A40.jpeg)

Pour les débutants et les passionnés, le clignotement LED est un programme fondamental. LED, l'abréviation de diodes électroluminescentes, est composée de composés chimiques tels que Ga, As, P, N, etc.

La LED peut clignoter en différentes couleurs en modifiant le temps de délai dans le code de test. Lorsqu'elle est contrôlée, alimentée en GND et VCC, la LED s'allume si la broche S est à un niveau haut, sinon elle s'éteint.

### **2.Spécifications**

- Interface de contrôle : port numérique

- Tension de fonctionnement : DC 3.3-5V

- Espacement des broches : 2.54mm

- Couleur d'affichage LED : rouge

![](media/A41.png)

### **3.Composants**

| Carte de développement *1 | Driver moteur 8833 *1     | Module LED rouge *1       |
| ------------------------- | ------------------------- | ------------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg)     | ![img](media/A44.jpg)     |
| Câble Dupont 3P F-F *1    | Câble USB *1              |                           |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg)     |                           |

### **4.Schéma de câblage**

![](media/A47.png)

Comme on peut le voir sur la figure ci-dessus, la carte d'extension driver moteur Keyestudio 8833 est empilée sur la carte de développement Keyestudio 4.0.

Les broches G, V et S du module LED sont respectivement connectées à G, 5V et D9 de la carte d'extension.

### **5.Code de test**

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A48.png)

(2).![](media/A49.png)

(3).![](media/A50.png)

**Code de test complet**

![](media/A51.png)

### **6.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et utilisez un câble USB pour connecter l'ordinateur afin d'alimenter la carte. Après la mise sous tension, vous verrez la LED connectée à la broche D9 s'allumer et s'éteindre.

**7.Pratique d'extension**

Ensuite, nous allons modifier la fréquence de clignotement de la LED en changeant le temps d'attente.

![](media/A52.png)

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et utilisez un câble USB pour connecter l'ordinateur afin d'alimenter la carte. Le résultat du test montre que la LED clignote plus rapidement.