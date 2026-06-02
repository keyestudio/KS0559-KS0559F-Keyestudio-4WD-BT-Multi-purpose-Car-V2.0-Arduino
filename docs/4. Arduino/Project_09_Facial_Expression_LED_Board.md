# Projet 9 Carte LED d'Expression Faciale

![image-20250510090912741](media/A87.png)

### **1.Description**

Comme ce serait amusant d'ajouter une carte d'expression à un robot. Et la carte LED Keyestudio 8\*16 peut faire l'affaire. Avec son aide, vous pouvez concevoir vous-mêmes des expressions faciales, images, motifs et autres affichages.

La carte LED 8\*16 est équipée de 128 LEDs. Les données du microprocesseur (Arduino) communiquent avec l'AiP1640 via une interface bus à deux fils. Ainsi, il peut contrôler l'allumage et l'extinction des 128 LEDs sur le module, afin de faire afficher sur la matrice de points du module le motif dont vous avez besoin. Un câble HX-2.54 4 broches est fourni pour faciliter le câblage.

### **2.Spécifications**

- Tension de fonctionnement : DC 3.3-5V

- Perte de puissance : 400mW

- Fréquence d'oscillation : 450KHz

- Courant de pilotage : 200mA

- Température de fonctionnement : -40\~80℃

- Mode de communication : I2C

### **3.Schéma de circuit**

![image-20250510091309725](media/A88.png)

### **4.Principe de fonctionnement**

Comment contrôler chaque LED de la matrice 8\*16 ? On sait que chaque octet contient 8 bits et chaque bit est 0 ou 1. Quand il est 0, la LED est éteinte, quand il est 1, la LED est allumée. Un octet peut contrôler une colonne de LEDs, et naturellement 16 octets peuvent contrôler 16 colonnes de LEDs, ce qui correspond à la matrice 8\*16.

### **5.Description des broches et protocole de communication**

Les données du microprocesseur (Arduino) communiquent avec l'AiP1640 via un câble bus à deux fils.

Le diagramme du protocole de communication est le suivant (SCLK) est SCL, (DIN) est SDA.

![image-20250510091407219](media/A89.png)

①Condition de départ pour l'entrée des données : SCL est au niveau haut et SDA passe de haut à bas.

②Pour la configuration de la commande de données, il existe les méthodes illustrées ci-dessous.

Dans notre programme exemple, sélectionnez la méthode pour **ajouter 1 à l'adresse automatiquement**, la valeur binaire est 0100 0000 et la valeur hexadécimale correspondante est 0x40.

![Img](media/A90.png)

③Pour la configuration de la commande d'adresse, l'adresse peut être sélectionnée comme indiqué ci-dessous.

Le premier 00H est sélectionné dans notre programme exemple, et le nombre binaire 1100 0000 correspond à l'hexadécimal 0xc0.

![Img](media/A91.png)

④La condition pour l'entrée des données est que lorsque SCL est au niveau haut lors de l'entrée des données, le signal sur SDA doit rester inchangé. Ce n'est que lorsque le signal d'horloge sur SCL est au niveau bas que le signal sur SDA peut être modifié. L'entrée des données se fait du bit faible en premier, puis du bit fort.

⑤La condition de fin de transmission des données est que lorsque SCL est au niveau bas, SDA au niveau bas et SCL au niveau haut, le niveau de SDA devient haut.

⑥Contrôle de l'affichage, réglage de différentes largeurs d'impulsion, la largeur d'impulsion peut être sélectionnée comme indiqué dans la figure ci-dessous.

Dans l'exemple, la largeur d'impulsion est 4/16, et l'hexadécimal correspondant à 1000 1010 est 0x8A.

![Img](media/A92.png)

**Instructions pour l'utilisation de l'outil modulus**

L'outil de matrice de points utilise la version en ligne, et le lien est :[http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#)

①Entrez le lien et la page apparaît comme ci-dessous

![image-20250510091438524](media/A93.png)

②La matrice de points est 8\*16, donc ajustez la hauteur à 8 et la largeur à 16, comme montré dans la figure ci-dessous.

![image-20250510091446519](media/A94.png)

③Générez les données hexadécimales à partir du motif

Comme montré dans la figure ci-dessous, appuyez sur le bouton gauche de la souris pour sélectionner, clic droit pour annuler ; dessinez le motif souhaité, cliquez sur Générer, et les données hexadécimales nécessaires seront générées.

![image-20250510091457463](media/A95.png)

### **6.Composants**

| Carte de développement *1                                    | Driver de moteur 8833 *1                                     | Câble USB*1               |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------- |
| ![img](media/A80.jpg)                                    | ![img](media/A81.jpg)                                    | ![img](media/A82.jpg) |
| Câble USB*1                                                  | Fil Dupont HX-2.54 4P 200mm *1                              |                           |
| ![image-20250512155818434](media/A96.png) | ![image-20250512155822969](media/A97.png) |                           |

### **7. Schéma de câblage**

![cec50fec4a335b6922e4c6694a133bc1](media/A98.png)

Les broches GND, VCC, SDA et SCL de la carte LED 8x16 sont respectivement connectées à la carte d’extension capteur keyestudio - (GND), + (VCC), A4, A5 pour la communication série à deux fils.

(<span style="color: rgb(255, 76, 65);">Remarque :</span> Bien qu’elle soit connectée à la broche IIC de l’Arduino, ce module n’est pas destiné à la communication IIC. Et le port IO ici sert à simuler la communication I2C et peut être connecté à n’importe quelles deux broches).

### **8. Code de test**  

Le code affichera un visage souriant.

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lesson 9.1
  Matrix face
  http://www.keyestudio.com
*/
//Données du motif sourire obtenues à partir de l’outil tactile
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};
#define SCL_Pin  A5  //Définir la broche d’horloge sur A5
#define SDA_Pin  A4  //Définir la broche de données sur A4
void setup() {
  //Définir la broche en sortie
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //effacer
  //matrix_display(clear);
}
void loop() {
  matrix_display(smile);  //afficher le motif d’expression souriante
}
//cette fonction est utilisée pour l’affichage sur matrice de points
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //fonction qui appelle la condition de démarrage du transfert de données
  IIC_send(0xc0);  //sélectionner l’adresse

  for (int i = 0; i < 16; i++) //les données du motif sont sur 16 octets
  {
    IIC_send(matrix_value[i]); //Transmettre les données du motif
  }
  IIC_end();   //Fin de la transmission des données du motif
  IIC_start();
  IIC_send(0x8A);  //Contrôle d’affichage, sélectionner largeur d’impulsion 4/16
  IIC_end();
}
//Conditions sous lesquelles la transmission de données commence
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Indique la fin de la transmission de données
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
//transmettre les données
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Chaque octet a 8 bits et est vérifié bit par bit en commençant par le bit de poids faible
  {
    if (send_data & mask) { //Définit les niveaux haut et bas de SDA_Pin selon que chaque bit de l’octet est un 1 ou un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Met la broche d’horloge SCL_Pin à l’état haut pour arrêter la transmission des données
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //met la broche d’horloge SCL_Pin à l’état bas pour changer le SIGNAL de SDA 
  }
}
//************************************************************************
```

### **9. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis mettez l’interrupteur DIP sur ON, un motif en forme de sourire s’affichera sur la carte LED.

![95bb011957896b12285fc6763137bb9a](media/A99.png)

### **10. Explication du code**

Nous utilisons l'outil de module que nous venons d'apprendre, [http://dotmatrixtool.com/\#](http://dotmatrixtool.com/\#), pour faire afficher à la matrice de points le motif de démarrage, avancer, s'arrêter puis effacer le motif. L'intervalle de temps est de 2000 ms.

![image-20250512155957415](media/A100.png)![image-20250512160002378](media/A101.png)![image-20250512160006841](media/A102.png)![image-20250512160010543](media/A103.png)

**Code obtenu à partir de l'outil module :**

**Code pour le motif de démarrage :**

0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01

**Code pour le motif d’avancement :**

0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Code pour le motif de recul :**

0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00

**Code pour le motif de virage à gauche :**

0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00

**Code pour le motif de virage à droite :**

0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00

**Code pour le motif d’arrêt :**

0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00

**Code pour effacer l’écran :**

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00

![cec50fec4a335b6922e4c6694a133bc1](media/A104.png)

```c
//************************************************************************
/*
 keyestudio 4wd BT Car
  lesson 9.2
  Matrix face
  http://www.keyestudio.com
*/
//Données du motif sourire obtenues depuis l'outil tactile
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char front[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x12, 0x09, 0x12, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char back[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x48, 0x90, 0x48, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char left[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x44, 0x28, 0x10, 0x00};
unsigned char right[] = {0x00, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x10, 0x28, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char STOP01[] = {0x2E, 0x2A, 0x3A, 0x00, 0x02, 0x3E, 0x02, 0x00, 0x3E, 0x22, 0x3E, 0x00, 0x3E, 0x0A, 0x0E, 0x00};
unsigned char clear[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#define SCL_Pin  A5  //Définir la broche d'horloge sur A5
#define SDA_Pin  A4  //Définir la broche de données sur A4
void setup() {
  //Définir la broche en sortie
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  //effacer
  //matrix_display(clear);
}
void loop() {
    matrix_display(start01);  //Afficher le motif de démarrage
    delay(2000);
    matrix_display(front);    //Afficher le motif d’avancement
    delay(2000);
    matrix_display(STOP01);   //Afficher le motif d’arrêt
    delay(2000);
    matrix_display(clear);    //Effacer l’écran
    delay(2000);
}
//cette fonction est utilisée pour l'affichage sur matrice de points
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //fonction qui appelle la condition de démarrage du transfert de données
  IIC_send(0xc0);  //sélectionner l'adresse

  for (int i = 0; i < 16; i++) // les données du motif sont de 16 octets
  {
    IIC_send(matrix_value[i]); // Transmettre les données du motif
  }
  IIC_end();   // Fin de la transmission des données du motif
  IIC_start();
  IIC_send(0x8A);  // Contrôle de l'affichage, sélection de la largeur d'impulsion 4/16
  IIC_end();
}
// Conditions dans lesquelles la transmission des données commence
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
// Indique la fin de la transmission des données
void IIC_end()
{
  digitalWrite(SCL_Pin, LOW);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, HIGH);
  delayMicroseconds(3);
}
// transmettre les données
void IIC_send(unsigned char send_data)
{
  for (byte mask = 0x01; mask != 0; mask <<= 1) // Chaque octet a 8 bits et est vérifié bit par bit en commençant par le bit de poids faible
  {
    if (send_data & mask) { // Définit les niveaux haut et bas de SDA_Pin selon que chaque bit de l'octet est un 1 ou un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); // Met la broche d'horloge SCL_Pin à l'état haut pour arrêter la transmission des données
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); // Met la broche d'horloge SCL_Pin à l'état bas pour changer le SIGNAL de SDA 
  }
}
//************************************************************************
```

Après avoir téléchargé le code de test, la carte d'expression faciale affiche ces motifs dans l'ordre et répète cette séquence.

![image-20250512160131674](media/A105.png)![image-20250512160135717](media/A106.png)![image-20250512160139283](media/A107.png)