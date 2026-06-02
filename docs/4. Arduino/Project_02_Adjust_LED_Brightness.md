# Projet 2 : Ajuster la luminosité de la LED

### **1.Description**

Dans la leçon précédente, nous avons contrôlé l’allumage et l’extinction de la LED et fait clignoter celle-ci.

Dans ce projet, nous allons contrôler la luminosité de la LED via le PWM simulant un effet de respiration.

Le PWM est un moyen de contrôler la sortie analogique par des moyens numériques. Le contrôle numérique est utilisé pour générer des ondes carrées avec différents cycles de service (un signal qui bascule constamment entre des niveaux haut et bas) pour contrôler la sortie analogique. En général, les tensions d’entrée des ports sont 0V et 5V.

Que faire si 3V sont nécessaires ? Ou un commutateur entre 1V, 3V et 3,5V ? Nous ne pouvons pas changer constamment les résistances. Pour cette raison, nous recourons au PWM.

![bbcfcb9ae56abb7e80ee587246fc4be9](media/A14.gif)

Pour la sortie de tension du port numérique Arduino, il n’y a que LOW et HIGH, qui correspondent à une sortie de tension de 0V et 5V. Vous pouvez définir LOW comme 0 et HIGH comme 1, et laisser l’Arduino émettre cinq cents signaux 0 ou 1 en 1 seconde.

Si tous les cinq cents signaux sont 1, cela correspond à 5V ; si tous sont 0, cela correspond à 0V. Si la sortie est 010101010101 de cette manière, alors la sortie du port est de 2,5V, ce qui est comme montrer un film. Le film que nous regardons n’est pas complètement continu. Il affiche en fait 25 images par seconde. Dans ce cas, l’humain ne peut pas le voir, ni le PWM. Si nous voulons une tension différente, nous devons contrôler le ratio de 0 et 1. Plus il y a de signaux 0,1 émis par unité de temps, plus le contrôle est précis.

Le PWM est une technologie qui utilise des méthodes numériques pour obtenir des quantités analogiques. Le contrôle numérique permet de former une onde carrée, le signal d’onde carrée n’a que deux états, marche et arrêt (haut et bas). Une tension allant de 0 à 5V peut être simulée en contrôlant le rapport de la durée de marche sur la durée d’arrêt. Le temps passé en marche (appelé techniquement niveau haut) est appelé largeur d’impulsion, donc le PWM est aussi appelé modulation de largeur d’impulsion.

Les barres verticales vertes représentent une période de l’onde carrée. La valeur écrite dans chaque analogWrite(value) correspond à un pourcentage, appelé aussi cycle de service. Ce pourcentage fait référence au rapport du temps occupé par le niveau haut dans un cycle, c’est-à-dire cycle de service = temps niveau haut / temps du cycle.

Dans la figure, de haut en bas, le cycle de service de la première onde carrée est de 0%, et la valeur correspondante est 0, et la luminosité de la LED est la plus faible, c’est-à-dire l’état éteint. Plus le niveau haut dure longtemps, plus la LED sera brillante. Par conséquent, la valeur du dernier cycle de service de 100% est 255, et la LED est la plus brillante. 50% correspond à la moitié de la luminosité maximale, et 25% est plus faible.

Le PWM est surtout utilisé pour ajuster la luminosité des LED ou la vitesse de rotation des moteurs, et la vitesse des roues entraînées par les moteurs peut être facilement contrôlée. Lorsqu’on joue avec certains robots Arduino, les avantages du PWM sont mieux mis en évidence.

### **2.Composants**

|           Carte de développement *1           |           Driver moteur 8833 *1           |     Module LED rouge *1     |
| :--------------------------------------------: | :---------------------------------------: | :-------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             Fil Dupont 3P *1                   |               Câble USB *1                 |                             |
|         ![img](media/A11.jpg)                   |         ![img](media/A12.jpg)              |                             |

### **3.Schéma de câblage**

Gardez le câblage inchangé.

![image-20250508161123490](media/A13.png)

### **4.Code de test**

```c
//*****************************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.1
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Définir la broche LED sur D9
int value;

void setup () {
  pinMode (ledPin, OUTPUT); // initialiser ledPin comme une sortie.
}

void loop () {
  for (value = 0; value <255; value = value + 1) 
  {
    analogWrite (ledPin, value); // La LED s'allume progressivement
    delay (5); // délai de 5 ms
  }
  for (value = 255; value> 0; value = value-1) 
  {
    analogWrite (ledPin, value); // La LED s'éteint progressivement
    delay (5); // délai de 5 ms
  }
}
//*****************************************************************
```

**5. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et utilisez un câble USB pour connecter l'ordinateur afin d'alimenter la carte. Après la mise sous tension, vous verrez que la LED change progressivement de lumineux à sombre, comme la respiration humaine, plutôt que de s'allumer et s'éteindre immédiatement.

**6. Explication du code**

Si nous devons répéter une certaine instruction, nous pouvons utiliser l'instruction for.

Le format de l'instruction for est présenté ci-dessous :

![image-20250508162458776](media/A15.png)

Séquence cyclique FOR :

Tour 1 : 1 → 2 → 3 → 4

Tour 2 : 2 → 3 → 4

…

Jusqu'à ce que le nombre 2 ne soit plus établi, la boucle "for" est terminée,

Après avoir compris cet ordre, revenons au code :

**for (int value = 0; value \< 255; value=value+1)**

**for (int value = 255; value \>0; value=value-1)**

Les deux instructions “for” font augmenter la valeur de 0 à 255, puis la réduire de 255 à 0, puis augmenter à 255... en boucle infinie.

Il y a une nouvelle fonction dans ce qui suit ----- analogWrite().

Nous savons que le port numérique n'a que deux états, 0 et 1. Alors comment envoyer une valeur analogique à une valeur numérique ? Ici, cette fonction est nécessaire. Observons la carte Arduino et trouvons 6 broches marquées “\~” qui peuvent émettre des signaux PWM.

Le format de la fonction est le suivant :

**analogWrite(pin,value)**

analogWrite() est utilisée pour écrire une valeur analogique de 0 à 255 pour un port PWM, donc la valeur est dans la plage de 0 à 255. Attention, vous ne pouvez écrire que sur les broches numériques avec fonction PWM, telles que les broches 3, 5, 6, 9, 10, 11.

Le PWM est une technologie pour obtenir une grandeur analogique par méthode numérique. Le contrôle numérique forme une onde carrée, et le signal d'onde carrée n'a que deux états, allumé et éteint (c'est-à-dire niveaux haut ou bas). En contrôlant le rapport de la durée d'allumage et d'extinction, une tension variant de 0 à 5V peut être simulée. Le temps d'allumage (appelé académiquement niveau haut) est appelé largeur d'impulsion, donc PWM est aussi appelé modulation de largeur d'impulsion.

À travers les cinq ondes carrées suivantes, apprenons-en plus sur le PWM.

![image-20250508162529349](media/A16.png)

Dans la figure ci-dessus, la ligne verte représente une période, et la valeur de analogWrite() correspond à un pourcentage appelé aussi cycle de service (Duty Cycle). Le cycle de service implique le rapport du temps occupé par le niveau haut dans le cycle. De haut en bas, le cycle de service de la première onde carrée est de 0 % et sa valeur correspondante est 0.

La luminosité de la LED est la plus faible, c'est-à-dire éteinte. Plus le temps de niveau haut dure, plus la LED est brillante. Par conséquent, le dernier cycle de service est de 100 %, ce qui correspond à 255, et la LED est la plus brillante. Et 50 % est la moitié la plus brillante, 25 % signifie plus sombre.

Le PWM est principalement utilisé pour ajuster la luminosité des LED ou la vitesse de rotation des moteurs.

Il joue un rôle vital dans le contrôle des voitures robots intelligentes. Je suis sûr que vous avez hâte d'apprendre le prochain projet.

**7. Pratique d'extension**

Modifions la valeur du délai tout en laissant la broche inchangée, puis observons comment la LED change.

```c
//***********************************************************
/*
 keyestudio 4wd BT Car
 lesson 2.2
 pwm
 http://www.keyestudio.com
*/
int ledPin = 9; // Définir la broche LED sur D9
void setup () {
   pinMode(ledPin, OUTPUT); // initialiser ledPin comme sortie.
}

void loop () {
   for (int value = 0; value <255; value = value + 1) {
     analogWrite (ledPin, value); // La LED s'allume progressivement
     delay (30); // délai de 30 ms
   }
   for (int value = 255; value> 0; value = value-1) {
     analogWrite (ledPin, value); // La LED s'éteint progressivement
     delay (30); // délai de 30 ms
   }
}
//***********************************************************
```

Téléchargez le code sur la carte de développement, puis la LED clignotera plus lentement.