# Projet 3 : Capteur de Suivi de Ligne

![](media/A17.png)

### **1. Description** 

Le capteur de suivi est en fait un capteur infrarouge. Le composant utilisé ici est le tube infrarouge TCRT5000. Son principe de fonctionnement est d'utiliser la réflectivité différente de la lumière infrarouge selon les couleurs, puis de convertir la puissance du signal réfléchi en un signal courant.

Lors du processus de détection, le noir est actif au niveau HAUT tandis que le blanc est actif au niveau BAS. La hauteur de détection est de 0 à 3 cm.

Le module de suivi de ligne 3 canaux Keyestudio intègre 3 ensembles de tubes infrarouges TCRT5000 sur une carte, ce qui est plus pratique pour le câblage et le contrôle.

En tournant le potentiomètre réglable sur le capteur, on peut ajuster la sensibilité de détection du capteur.

### **2. Spécifications**

- Tension de fonctionnement : 3,3-5V (DC)

- Interface : 5PIN

- Signal de sortie : Signal numérique

- Hauteur de détection : 0-3 cm

![image-20250508163247479](media/A18.png)

<span style="color: rgb(255, 76, 65);">Remarque : Avant le test, tournez le potentiomètre sur le capteur pour ajuster la sensibilité de détection. La sensibilité est optimale lorsque la LED est réglée à un seuil entre ON et OFF.</span> 

### **3. Composants**

| Carte de développement *1               | Driver moteur 8833 *1                    | Module LED rouge *1       | Capteur de suivi de ligne *1 |
| -------------------------------------- | -------------------------------------- | ------------------------ | ---------------------------- |
| ![img](media/A8.jpg)                    | ![img](media/A9.jpg)                    | ![img](media/A10.jpg)    | ![img](media/A19.png)        |
| Fil Dupont 5P *1                       | Câble USB *1                           | Fil Dupont 3P *1         |                              |
| ![img](media/A20.png)                   | ![img](media/A12.jpg)                   | ![img](media/A11.jpg)    |                              |

### **4. Schéma de câblage**

![image-20250508164243044](media/A21.png)

G, V, S1, S2 et S3 du capteur de suivi de ligne sont connectés respectivement à G (GND), V (VCC), D11, D7 et D8 de la carte d’extension du capteur.

### **5. Code de test**

```c
//****************************************************************************
/*
keyestudio 4wd BT Car
lesson 3.1 
 Line Track sensor
 http://www.keyestudio.com
*/
int L_pin = 11;  //broches du capteur de suivi de ligne gauche
int M_pin = 7;  //broches du capteur de suivi de ligne milieu
int R_pin = 8;  //broches du capteur de suivi de ligne droite
int val_L,val_R,val_M;// définir la variable valeur des trois capteurs

void setup()
{
  Serial.begin(9600); // initialiser la communication série à 9600 bits par seconde
  pinMode(L_pin,INPUT); // définir L_pin comme entrée
  pinMode(M_pin,INPUT); // définir M_pin comme entrée
  pinMode(R_pin,INPUT); // définir R_pin comme entrée
}

void loop() 
{ 
  val_L = digitalRead(L_pin);//lire L_pin :
  val_R = digitalRead(R_pin);//lire R_pin :
  val_M = digitalRead(M_pin);//lire M_pin :
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500);// délai entre les lectures pour la stabilité
}
//****************************************************************************
```

### **6. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les fils selon le schéma de câblage, et utilisez un câble USB pour connecter l’ordinateur afin d’alimenter la carte.

Après la mise sous tension, ouvrez le moniteur série et vous verrez l’état des trois capteurs de suivi de ligne. Lorsqu’aucun signal n’est reçu, la valeur est 1. Si l’on couvre le capteur avec un papier blanc, la valeur sera 0.

![image-20250508164424571](media/A22.png)

![image-20250508164453274](media/A23.png)

### **7. Explication du code**

Serial.begin(9600) - Initialise le port série, définit la vitesse de transmission à 9600 bauds

pinMode - Définit la broche en mode entrée ou sortie

digitalRead - Lit l’état de la broche, généralement niveau HAUT ou BAS

### **8. Pratique d’extension**

Après avoir compris son principe de fonctionnement, vous pouvez connecter une LED à D9 afin de contrôler la LED avec ce capteur.

![image-20250508164527429](media/A24.png)

```c
/*
keyestudio 4wd BT Car
lesson 3.2
 Line Track Sensor LED
 http://www.keyestudio.com
*/
int L_pin = 11;  //broches du capteur de suivi de ligne gauche
int M_pin = 7;  //broches du capteur de suivi de ligne central
int R_pin = 8;  //broches du capteur de suivi de ligne droit
int val_L,val_R,val_M;// définir les variables des trois capteurs 

void setup()
{
  Serial.begin(9600); // initialiser la communication série à 9600 bits par seconde
  pinMode(L_pin,INPUT); // configurer L_pin en entrée
  pinMode(M_pin,INPUT); // configurer M_pin en entrée
  pinMode(R_pin,INPUT); // configurer R_pin en entrée
  pinMode(9, OUTPUT);
}

void loop() 
{ 
  val_L = digitalRead(L_pin);//lire L_pin :
  val_R = digitalRead(R_pin);//lire R_pin :
  val_M = digitalRead(M_pin);//lire M_pin :
  Serial.print("left:");
  Serial.print(val_L);
  Serial.print(" middle:");
  Serial.print(val_M);
  Serial.print(" right:");
  Serial.println(val_R);
  delay(500);// délai entre les lectures pour la stabilité
  if ((val_L == LOW) || (val_M == LOW) || (val_R == LOW))// si un des capteurs de suivi de ligne détecte un signal
  { 
    Serial.println("HIGH");
    digitalWrite(9, HIGH);//LED est allumée
  }
  else// si aucun capteur de suivi de ligne ne détecte de signal
  { 
    Serial.println("LOW");
    digitalWrite(9, LOW);//LED est éteinte
  }
 }
//****************************************************************************
```

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis utilisez un câble USB pour connecter l’ordinateur et alimenter la carte.

Après la mise sous tension, approchez un papier du capteur, vous verrez alors la LED s’allumer lorsque le capteur de suivi de ligne est couvert.