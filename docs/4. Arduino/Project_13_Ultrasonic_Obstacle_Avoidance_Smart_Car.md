# Projet 13 Voiture intelligente à évitement d'obstacles par ultrasons

![fd4044796307f709987b9d2e215e0911](media/A119.png)

### **1.Description**

Dans ce projet, nous visons à réaliser une voiture intelligente à évitement d'obstacles par ultrasons. Nous utiliserons l'ultrason pour détecter la distance par rapport à l'obstacle, ce qui peut être utilisé pour contrôler le servo afin de faire tourner la voiture. Parallèlement, la matrice LED 8X16 affichera le motif de statut correspondant.

### **2.Diagramme de flux**

![img](media/A120.png)

**La logique spécifique de la voiture intelligente à évitement d'obstacles par ultrasons est illustrée ci-dessous :**

![Img](media/A121.png)

![Img](media/A122.png)

### **3.Schéma de câblage**

![](media/A118.png)

1). GND, VCC, SDA et SCL du module matrice LED 8\*8 sont connectés respectivement à G (GND), V (VCC), A4 et A5 de la carte d'extension.

2). VCC, Trig, Echo et Gnd du capteur ultrason sont connectés à 5V (V), D12 (S), D13 (S) et Gnd (G).

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge à 5V (V) et le fil orange à A3.

4). L'alimentation est connectée au port BAT.

### **4.Code de test**

```c 
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 13
 Avoiding Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Définir la broche d'horloge sur A5
#define SDA_Pin  A4  //Définir la broche de données sur A4
//Tableau, utilisé pour stocker les données du motif, peut être calculé soi-même ou obtenu via l'outil de module
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

int left_ctrl = 2;//définir les broches de contrôle de direction du moteur groupe B
int left_pwm = 5;//définir les broches de contrôle PWM du moteur groupe B
int right_ctrl = 4;//définir les broches de contrôle de direction du moteur groupe A
int right_pwm = 6;//définir les broches de contrôle PWM du moteur groupe A

#include "SR04.h"//inclure la bibliothèque du capteur ultrason
#define TRIG_PIN 12// définir la sortie signal du capteur ultrason sur D12 
#define ECHO_PIN 13//définir l'entrée signal du capteur ultrason sur D13 
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance,a1,a2;//définir trois variables de distance
const int servopin = A3;//définir la broche du servo sur A3 

void setup() {
  pinMode(left_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur groupe B en sortie
  pinMode(left_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur groupe B en sortie
  pinMode(right_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur groupe A en sortie
  pinMode(right_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur groupe A en sortie
  pinMode(TRIG_PIN, OUTPUT); //Définir la broche trig en sortie
  pinMode(ECHO_PIN, INPUT); //Définir la broche echo en entrée
  servopulse(servopin,90);//l'angle du servo est de 90 degrés
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Définir la broche d'horloge en sortie
  pinMode(SDA_Pin,OUTPUT);//Définir la broche de données en sortie
  matrix_display(clear);
}
 
void loop()
 {
  avoid();//exécuter le programme principal
}

void avoid()
{
  distance=sr04.Distance(); //obtenir la valeur détectée par le capteur ultrason 

  if((distance < 20)&&(distance != 0))//si la distance est inférieure à 20 et différente de 0  

  {
    car_Stop();//arrêt
    matrix_display(clear);
    matrix_display(STOP01);//afficher le motif d'arrêt
    delay(1000);
    servopulse(servopin,160);//le servo tourne à 160°
    delay(500);
    a1=sr04.Distance();//mesurer la distance
    delay(100);
    servopulse(servopin,20);//tourner à 20 degrés
    delay(500);
    a2=sr04.Distance();//mesurer la distance
    delay(100);
    servopulse(servopin,90);  //Retour à la position de 90 degrés
    delay(500);
    if(a1 > a2)//comparer la distance, si la distance gauche est plus grande que la distance droite
    {
      car_left();//tourner à gauche
      matrix_display(clear);
      matrix_display(left);    //afficher le motif de virage à gauche
      servopulse(servopin,90);//le servo tourne à 90 degrés
      delay(700); //tourner à gauche pendant 700ms
      matrix_display(clear);
      matrix_display(front);  //afficher le motif avant
    }
    else//si la distance droite est plus grande que la gauche
    {
      car_right();//tourner à droite
      matrix_display(clear);
      matrix_display(right);  //afficher le motif de virage à droite
      servopulse(servopin,90);//le servo tourne à 90 degrés
      delay(700);
      matrix_display(clear);
      matrix_display(front);  //afficher le motif avant
    }
  }
  else//sinon
  {
    car_front();//avancer
    matrix_display(clear);
    matrix_display(front);  // afficher le motif avant
  }
}

void car_front()//la voiture avance
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,155);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,155);
}
void car_back()//reculer
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,100);
}
void car_left()//la voiture tourne à gauche
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//la voiture tourne à droite
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//arrêt
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void servopulse(int servopin,int myangle)//l'angle de fonctionnement du servo
{
  for(int i=0; i<20; i++)
  {
    int pulsewidth = (myangle*11)+500;
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servopin,LOW);
    delay(20-pulsewidth/1000);
  } 
}

//cette fonction est utilisée pour l'affichage sur matrice de points
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la fonction qui appelle la condition de démarrage du transfert de données
  IIC_send(0xc0);  //sélectionner l'adresse

```cpp
  for (int i = 0; i < 16; i++) //les données du motif sont de 16 octets
  {
    IIC_send(matrix_value[i]); //Transmettre les données du motif
  }
  IIC_end();   //Fin de la transmission des données du motif
  IIC_start();
  IIC_send(0x8A);  //Contrôle de l'affichage, sélection de la largeur d'impulsion 4/16
  IIC_end();
}
//Conditions dans lesquelles la transmission des données commence
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) //Chaque octet contient 8 bits et est vérifié bit par bit en commençant par le bit de poids faible
  {
    if (send_data & mask) { //Définit les niveaux haut et bas de SDA_Pin selon que chaque bit de l'octet est un 1 ou un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); //Met la broche d'horloge SCL_Pin à haut pour arrêter la transmission des données
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); //Met la broche d'horloge SCL_Pin à bas pour changer le SIGNAL de SDA 
  }
}
//*******************************************************************************
```

### **5.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l'alimentation externe puis mettez l'interrupteur DIP sur ON.

La voiture intelligente avance et évite automatiquement les obstacles. Lorsqu'il n'y a pas de route devant, le servo-moteur actionnera le capteur ultrasonique pour scanner les distances à gauche, au centre et à droite, et la voiture tournera vers le côté ouvert. Pendant ce temps, la carte LED 8X16 affichera le motif d'état correspondant.