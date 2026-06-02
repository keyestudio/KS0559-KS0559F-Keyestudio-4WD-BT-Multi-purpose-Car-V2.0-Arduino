# Projet 1 : Clignotement de LED

### **1.Description**

![image-20250508161034535](media/A6.png)

Pour les débutants et les passionnés, le clignotement de LED est un programme fondamental. LED, l'abréviation de diodes électroluminescentes, est composée de composés chimiques tels que Ga, As, P, N, etc.

La LED peut clignoter en différentes couleurs en modifiant le temps de délai dans le code de test. Lorsqu'elle est contrôlée, alimentée en GND et VCC, la LED s'allume si la broche S est à un niveau haut, sinon elle s'éteint.

### **2.Spécifications**

- Interface de contrôle : port numérique

- Tension de fonctionnement : DC 3.3-5V

- Espacement des broches : 2,54 mm

- Couleur d'affichage de la LED : rouge

![image-20250508161015086](media/A7.png)

### **3.Composants**

|           Carte de développement *1           |           Driver moteur 8833 *1           |     Module LED rouge *1     |
| :--------------------------------------------: | :---------------------------------------: | :-------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             Fil Dupont 3P *1                   |               Câble USB *1                 |                             |
|         ![img](media/A11.jpg)                   |         ![img](media/A12.jpg)              |                             |

### **4.Schéma de câblage**

![image-20250508161123490](media/A13.png)

Comme on peut le voir sur la figure ci-dessus, le Shield moteur Keyestudio 8833 est empilé sur la carte de développement Keyestudio 4.0.

Les broches G, V et S du module LED sont respectivement connectées à G, 5V et D9 de la carte d'extension.

### **5.Code de test**

```c 
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 1.1
Blink
http://www.keyestudio.com
*/
void setup()
{ 
  pinMode(9, OUTPUT);// initialise la broche numérique 9 en sortie.
}
    
void loop() // la fonction loop s'exécute en boucle indéfiniment
{  
  digitalWrite(9, HIGH); // allume la LED (HIGH est le niveau de tension)
   delay(1000); // attend une seconde
   digitalWrite(9, LOW); // éteint la LED en mettant la tension à LOW
   delay(1000); // attend une seconde
}
//****************************************************************************
```

### **6.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et utilisez un câble USB pour connecter l'ordinateur afin d'alimenter la carte. Après la mise sous tension, vous verrez la LED connectée à la broche D9 s'allumer et s'éteindre.

### **7.Explication du code**

pinMode(9，OUTPUT) - Cette fonction permet de définir si la broche est en entrée (INPUT) ou en sortie (OUTPUT)

digitalWrite(9，HIGH) - Lorsque la broche est en sortie, on peut la mettre à HIGH (sortie 5V) ou LOW (sortie 0V)

### **8.Pratique d'extension**

Nous avons réussi à faire clignoter la LED. Ensuite, observons ce qui se passe avec la LED si nous modifions le temps de délai.

```c
//****************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 1.2
 delay
 http://www.keyestudio.com
*/
void setup()
{  
  // initialise la broche numérique 9 en sortie.
  pinMode(9, OUTPUT);
}
// la fonction loop s'exécute en boucle indéfiniment
void loop()
{ 
  digitalWrite(9, HIGH); // allume la LED (HIGH est le niveau de tension)
  delay(100); // attend 0,1 seconde
  digitalWrite(9, LOW); // éteint la LED en mettant la tension à LOW
  delay(100); // attend 0,1 seconde
}
//*****************************************************************
```

Le résultat du test montre que la LED clignote plus rapidement. Par conséquent, le temps de délai influence la fréquence de clignotement de la LED.