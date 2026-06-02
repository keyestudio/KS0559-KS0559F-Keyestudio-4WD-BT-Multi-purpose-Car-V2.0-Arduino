# Projet 10 Voiture Intelligente Restreinte

![644a1976bf17a6b64e0aed1a7240ff1e](media/A108.jpeg)

### **1.Description**

Dans ce projet, nous cherchons à combiner les connaissances d'un capteur de suivi de ligne et des modules de pilote de moteur pour fabriquer une voiture intelligente restreinte. Lors de l'expérience, nous visons à utiliser le capteur de suivi de ligne pour détecter s'il y a une ligne noire autour de la voiture intelligente, puis contrôler la rotation des deux moteurs selon les résultats de détection de manière à verrouiller la voiture intelligente dans un cercle tracé en ligne noire.

### **2.Diagramme de Flux**

![img](media/A109.png)

La logique spécifique de la voiture intelligente 4WD restreinte est montrée dans le tableau.

![Img](media/A110.png)

### **3.Schéma de Câblage**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A111.png)

G, V, S1, S2 et S3 du capteur de suivi de ligne sont connectés à G (GND), V (VCC), D11, D7 et D8 de la carte d'extension du capteur.

L'alimentation est connectée au port BAT.

### **4.Code de Test**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 10
 Voiture Intelligente Restreinte
 http://www.keyestudio.com
*/ 
//Données du motif sourire obtenues à partir de l'outil tactile
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //Définir la broche de données sur A4
#define SCL_Pin  A5  //Définir la broche d'horloge sur A5

int left_ctrl = 2;//définir les broches de contrôle de direction du moteur du groupe B
int left_pwm = 5;//définir les broches de contrôle PWM du moteur du groupe B
int right_ctrl = 4;//définir les broches de contrôle de direction du moteur du groupe A
int right_pwm = 6;//définir les broches de contrôle PWM du moteur du groupe A
int sensor_L = 11;//définir la broche du capteur de suivi de ligne gauche
int sensor_M = 7;//définir la broche du capteur de suivi de ligne milieu
int sensor_R = 8;//définir la broche du capteur de suivi de ligne droite
int L_val,M_val,R_val;//définir ces variables

void setup() {
  Serial.begin(9600);//démarrer le moniteur série et définir le débit en bauds à 9600
  pinMode(left_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur du groupe B en SORTIE
  pinMode(left_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur du groupe B en SORTIE
  pinMode(right_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur du groupe A en SORTIE
  pinMode(right_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur du groupe A en SORTIE
  pinMode(sensor_L,INPUT);//définir les broches du capteur de suivi de ligne gauche en ENTRÉE
  pinMode(sensor_M,INPUT);//définir les broches du capteur de suivi de ligne milieu en ENTRÉE
  pinMode(sensor_R,INPUT);//définir les broches du capteur de suivi de ligne droite en ENTRÉE
 //Définir la broche en sortie
  pinMode(SCL_Pin, OUTPUT);
  pinMode(SDA_Pin, OUTPUT);
  matrix_display(start01);//Afficher le motif de démarrage
}

void loop() 
{
  tracking(); //exécuter le programme principal
}

void tracking()
{
  L_val = digitalRead(sensor_L);//lire la valeur du capteur de suivi de ligne gauche
  M_val = digitalRead(sensor_M);//lire la valeur du capteur de suivi de ligne milieu
  R_val = digitalRead(sensor_R);//lire la valeur du capteur de suivi de ligne droite
  if ( L_val == 0 && M_val == 0 && R_val == 0 ) { //quand aucune ligne noire n'est détectée, la voiture avance
    Car_front();
  }
  else { //Sinon, si un des capteurs de patrouille détecte une ligne noire, reculer et tourner à gauche
    Car_back();
    delay(500);
    Car_left();
    delay(500);
  }
}

void Car_front()
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 180);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 180);
}
void Car_back()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 80);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 80);
}
void Car_left()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 150);
}

void Car_Stop()
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 0);
}

//cette fonction est utilisée pour l'affichage sur matrice de points
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la fonction qui appelle la condition de démarrage du transfert de données
  IIC_send(0xc0);  //sélectionner l'adresse

  for (int i = 0; i < 16; i++) //les données du motif sont de 16 octets
  {
    IIC_send(matrix_value[i]); //Transmettre les données du motif
  }
  IIC_end();   //Fin de la transmission des données du motif
  IIC_start();
  IIC_send(0x8A);  //Contrôle d'affichage, sélectionner une largeur d'impulsion de 4/16
  IIC_end();
}
//Conditions sous lesquelles la transmission des données commence
void IIC_start()
{
  digitalWrite(SDA_Pin, HIGH);
  digitalWrite(SCL_Pin, HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin, LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin, LOW);
}
//Indique la fin de la transmission des données
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Chaque octet a 8 bits et est vérifié bit par bit en commençant par le niveau le plus bas
  {
    if (send_data & mask) { //Définit les niveaux haut et bas de SDA_Pin selon que chaque bit de l'octet est un 1 ou un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Met la broche d'horloge SCL_Pin à haut pour arrêter la transmission des données
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //met la broche d'horloge SCL_Pin à bas pour changer le SIGNAL de SDA 
  }
}
//*************************************************************************
```

###  **5.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l'alimentation externe
puis mettez l'interrupteur DIP sur ON. Placez la voiture intelligente dans le cercle noir, elle se déplacera alors uniquement dans le cercle.