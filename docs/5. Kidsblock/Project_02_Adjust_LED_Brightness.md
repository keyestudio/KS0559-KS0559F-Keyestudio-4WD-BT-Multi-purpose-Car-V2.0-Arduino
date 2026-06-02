# Projet 2 : Ajuster la luminosité de la LED

### **1.Description**

Dans la leçon précédente, nous avons contrôlé l’allumage et l’extinction de la LED et l’avons fait clignoter.

Dans ce projet, nous allons contrôler la luminosité de la LED via le PWM simulant un effet de respiration.

Le PWM est un moyen de contrôler la sortie analogique par des moyens numériques. Le contrôle numérique est utilisé pour générer des ondes carrées avec différents cycles de service (un signal qui alterne constamment entre des niveaux haut et bas) pour contrôler la sortie analogique. En général, les tensions d’entrée des ports sont 0V et 5V.

Que faire si 3V sont nécessaires ? Ou un commutateur entre 1V, 3V et 3,5V ? Nous ne pouvons pas changer constamment les résistances. Pour cette raison, nous utilisons le PWM.

![](media/A53.gif)

Pour la sortie de tension du port numérique Arduino, il n’y a que LOW et HIGH, qui correspondent à une sortie de tension de 0V et 5V. Vous pouvez définir LOW comme 0 et HIGH comme 1, et laisser l’Arduino émettre cinq cents signaux 0 ou 1 en 1 seconde.

Si tous les cinq cents signaux sont 1, cela correspond à 5V ; si tous sont 0, cela correspond à 0V. Si la sortie est 010101010101 de cette manière, alors la sortie du port est de 2,5V, ce qui est comme un film. Le film que nous regardons n’est pas complètement continu. Il affiche en fait 25 images par seconde. Dans ce cas, l’humain ne peut pas le voir, pas plus que le PWM. Si nous voulons une tension différente, nous devons contrôler le ratio de 0 et 1. Plus il y a de signaux 0,1 émis par unité de temps, plus le contrôle est précis.

Le PWM est une technologie qui utilise des méthodes numériques pour obtenir des quantités analogiques. Le contrôle numérique permet de former une onde carrée, le signal d’onde carrée n’a que deux états, marche et arrêt (haut et bas). Une tension allant de 0 à 5V peut être simulée en contrôlant le rapport entre la durée de marche et d’arrêt. Le temps passé en marche (appelé techniquement niveau haut) est appelé largeur d’impulsion, donc le PWM est aussi appelé modulation de largeur d’impulsion.

![](media/A54.png)

Les barres verticales vertes représentent une période de l’onde carrée. La valeur écrite dans chaque analogWrite(value) correspond à un pourcentage, appelé aussi cycle de service (Duty Cycle). Ce pourcentage fait référence au rapport du temps occupé par le niveau haut dans un cycle, c’est-à-dire cycle de service = temps niveau haut / temps du cycle.

Dans la figure, de haut en bas, le cycle de service de la première onde carrée est de 0%, et la valeur correspondante est 0, et la luminosité de la LED est la plus faible, c’est-à-dire éteinte. Plus la durée du niveau haut est longue, plus la LED sera brillante. Par conséquent, la valeur du dernier cycle de service de 100% est 255, et la LED est la plus brillante. 50% correspond à une luminosité à moitié maximale, et 25% est plus faible.

Le PWM est principalement utilisé pour ajuster la luminosité des LED ou la vitesse de rotation des moteurs, et la vitesse des roues entraînées par les moteurs peut être facilement contrôlée. Lorsqu’on joue avec certains robots Arduino, les avantages du PWM sont mieux mis en valeur.

### **2.Composants**

| Carte de développement *1 | Driver moteur 8833 *1 | Module LED rouge *1 |
| ------------------------- | --------------------- | ------------------- |
| ![img](media/A42.jpg)     | ![img](media/A43.jpg) | ![img](media/A44.jpg) |
| Câble Dupont 3P F-F *1    | Câble USB *1          |                     |
| ![img](media/A45.jpg)     | ![img](media/A46.jpg) |                     |

**3.Schéma de câblage**

Gardez le câblage inchangé.

![](media/A47.png)

### **4.Code de test**

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A55.png)

(2).![](media/A56.png)

(3).![](media/A57.png)

(4).![](media/A58.png)

(5).![](media/A59.png)

(6).![](media/A60.png)

**Code de test complet**

![](media/A61.png)

### **5.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câbles selon le schéma de câblage, et utilisez un câble USB pour connecter l’ordinateur afin d’alimenter la carte. Après la mise sous tension, vous verrez que la LED change progressivement de lumineux à sombre, comme la respiration humaine, plutôt que de s’allumer et s’éteindre immédiatement.

### **6.Pratique d’extension**

Gardez les broches de la LED inchangées, puis modifiez le code (valeurs derrière wait)

![](media/A62.png)

Téléversez le code sur la carte de développement, puis la LED clignotera plus lentement.