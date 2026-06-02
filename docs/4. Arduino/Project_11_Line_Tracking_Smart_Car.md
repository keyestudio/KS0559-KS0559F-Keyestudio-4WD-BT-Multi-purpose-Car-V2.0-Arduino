# Projet 11 Voiture Intelligente Suiveuse de Ligne

![eff7a15e697e8b78bde391f806ea024d](media/A112.png)

### **1.Description**

Basé sur le principe de fonctionnement du capteur suiveur de ligne, nous réalisons une voiture intelligente suiveuse de ligne.

Dans ce projet, nous détectons s'il y a une ligne noire sous la voiture intelligente grâce à un capteur suiveur de ligne, puis contrôlons la rotation des deux groupes de moteurs selon les résultats de détection de manière à faire suivre à la voiture intelligente la ligne noire.

### **2.Diagramme de Flux**

![img](media/A113.png)

![Img](media/A114.png)

### **3.Schéma de Câblage**

![88422b5f1464ad447e28ccbb8c39a8d4](media/A115.png)

G, V, S1, S2 et S3 du capteur suiveur de ligne sont connectés respectivement à G (GND), V (VCC), D11, D7 et D8 de la carte d'extension capteur.

L'alimentation est connectée au port BAT.

### **4.Code de Test**

```c
//*************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 11
 Tracking Car
 http://www.keyestudio.com
*/ 
//Données du motif sourire obtenues depuis l'outil tactile
unsigned char start01[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define SDA_Pin  A4  //Définir la broche de données sur A4
#define SCL_Pin  A5  //Définir la broche d'horloge sur A5

int left_ctrl = 2;//définir les broches de contrôle de direction du moteur groupe B
int left_pwm = 5;//définir les broches de contrôle PWM du moteur groupe B
int right_ctrl = 4;//définir les broches de contrôle de direction du moteur groupe A
int right_pwm = 6;//définir les broches de contrôle PWM du moteur groupe A
int sensor_L = 11;//définir la broche du capteur suiveur de ligne gauche
int sensor_M = 7;//définir la broche du capteur suiveur de ligne milieu
int sensor_R = 8;//définir la broche du capteur suiveur de ligne droite
int L_val,M_val,R_val;//définir ces variables

void setup() {
  Serial.begin(9600);//démarrer le moniteur série et définir le débit à 9600
  pinMode(left_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur groupe B en sortie
  pinMode(left_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur groupe B en sortie
  pinMode(right_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur groupe A en sortie
  pinMode(right_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur groupe A en sortie
  pinMode(sensor_L,INPUT);//définir les broches du capteur suiveur de ligne gauche en entrée
  pinMode(sensor_M,INPUT);//définir les broches du capteur suiveur de ligne milieu en entrée
  pinMode(sensor_R,INPUT);//définir les broches du capteur suiveur de ligne droite en entrée
  //Définir les broches en sortie
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
  L_val = digitalRead(sensor_L);//lire la valeur du capteur suiveur de ligne gauche
  M_val = digitalRead(sensor_M);//lire la valeur du capteur suiveur de ligne milieu
  R_val = digitalRead(sensor_R);//lire la valeur du capteur suiveur de ligne droite

  if(M_val == 1){//si l'état du capteur du milieu est 1, ce qui signifie détection de la ligne noire

     if (L_val == 1 && R_val == 0) { //Si une ligne noire est détectée à gauche, mais pas à droite, tourner à gauche
        left();
    }
     else if (L_val == 0 && R_val == 1) { //Sinon, si une ligne noire est détectée à droite et pas à gauche, tourner à droite
      right();
    }
     else { //Sinon, avancer
      front();
    }
  }
  else { //Aucune ligne noire détectée au milieu
    if (L_val == 1 && R_val == 0) { //Si une ligne noire est détectée à gauche, mais pas à droite, tourner à gauche
      left();
    }
    else if (L_val == 0 && R_val == 1) { //Sinon, si une ligne noire est détectée à droite et pas à gauche, tourner à droite
      right();
    }
    else { //Sinon, arrêter
      Stop();
    }
  }
}
void front()//définir l'état d'avancer
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void back()//définir l'état de reculer
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void left()//définir l'état de tourner à gauche
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//définir l'état de tourner à droite
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void Stop()//définir l'état d'arrêt
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm,0);
}

//cette fonction est utilisée pour l'affichage matriciel
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la fonction qui appelle la condition de début de transfert de données
  IIC_send(0xc0);  //sélectionner l'adresse

  for (int i = 0; i < 16; i++) //les données du motif sont 16 octets
  {
    IIC_send(matrix_value[i]); //Transmettre les données du motif
  }
  IIC_end();   //Fin de la transmission des données du motif
  IIC_start();
  IIC_send(0x8A);  //Contrôle d'affichage, sélectionner une largeur d'impulsion 4/16
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Chaque octet a 8 bits et est vérifié bit par bit en commençant par le niveau le plus bas
  {
    if (send_data & mask) { //Définit les niveaux haut et bas de SDA_Pin selon que chaque bit de l'octet est un 1 ou un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Met le pin d'horloge SCL_Pin à haut pour arrêter la transmission des données
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //met le pin d'horloge SCL_Pin à bas pour changer le SIGNAL de SDA 
  }
}
//*************************************************************************
```

### **5. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l'alimentation externe puis mettez l'interrupteur DIP sur ON. Ensuite, la voiture intelligente suivra les lignes.