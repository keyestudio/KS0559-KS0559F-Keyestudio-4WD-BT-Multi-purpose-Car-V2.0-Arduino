# Projet 12 Voiture intelligente à suivi ultrasonique

![a3beaada39eb1471b7df6d9788e2bea3](media/A116.png)

### **1.Description**

Dans ce projet, nous allons détecter la distance entre la voiture intelligente 4WD et les obstacles devant elle grâce à un capteur ultrasonique afin de piloter deux moteurs de manière à faire avancer la voiture et afficher un motif de visage souriant sur la matrice LED 8\*8.

### **2.Diagramme de flux**

![img](media/A117.png)

<table border="1">
<tbody>
<tr class="odd">
<td>Détection</td>
<td>Distance mesurée des obstacles devant</td>
<td>distance (unité : cm)</td>
</tr>
<tr class="even">
<td>Réglage</td>
<td>La matrice LED 8*16 affiche un motif souriant.</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>Positionner le servo à 90°</td>
<td></td>
</tr>
<tr class="even">
<td>Condition</td>
<td>distance≥20 et distance≤50</td>
<td></td>
</tr>
<tr class="odd">
<td>État</td>
<td>Avancer</td>
<td></td>
</tr>
<tr class="even">
<td>Condition</td>
<td>distance＞10 et distance＜20</td>
<td></td>
</tr>
<tr class="odd">
<td></td>
<td>distance＞50</td>
<td></td>
</tr>
<tr class="even">
<td>Condition</td>
<td>arrêt</td>
<td></td>
</tr>
<tr class="odd">
<td>Condition</td>
<td>distance≤10</td>
<td></td>
</tr>
<tr class="even">
<td>Condition</td>
<td>Reculer</td>
<td></td>
</tr>
</tbody>
</table>


### **3.Schéma de câblage**

![568a66655a14dd34afd8cb1e6ae5951c](media/A118.png)

**Câblage :**

1). GND, VCC, SDA et SCL de la matrice LED 8\*8 sont connectés à G (GND), V (VCC), A4 et A5 de la carte d’extension.

2). VCC, Trig, Echo et Gnd du capteur ultrasonique sont connectés à 5V (V), D12 (S), D13 (S) et Gnd (G).

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge à 5V (V) et le fil orange à A3.

4). L’alimentation est connectée au port BAT.

### **4.Code de test**

```c
//*******************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 12
 Flowing Car
 http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Définir la broche d'horloge sur A5
#define SDA_Pin  A4  //Définir la broche de données sur A4

//Tableau, utilisé pour stocker les données du motif, peut être calculé soi-même ou obtenu via l'outil de module
unsigned char smile[] = {0x00, 0x00, 0x1c, 0x02, 0x02, 0x02, 0x5c, 0x40, 0x40, 0x5c, 0x02, 0x02, 0x02, 0x1c, 0x00, 0x00};

const int servopin = A3;//Définir la broche du servo
 
#include "SR04.h" //définir la bibliothèque de fonctions du capteur ultrasonique
#define TRIG_PIN 12// définir la broche trig du capteur ultrasonique sur D12
#define ECHO_PIN 13// définir la broche echo du capteur ultrasonique sur D13
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

int left_ctrl = 2;//définir les broches de contrôle de direction du moteur groupe B
int left_pwm = 5;//définir les broches PWM du moteur groupe B
int right_ctrl = 4;//définir les broches de contrôle de direction du moteur groupe A
int right_pwm = 6;//définir les broches PWM du moteur groupe A

void setup() {
  pinMode(left_ctrl,OUTPUT);//configurer les broches de contrôle de direction du moteur groupe B en sortie
  pinMode(left_pwm,OUTPUT);//configurer les broches PWM du moteur groupe B en sortie
  pinMode(right_ctrl,OUTPUT);//configurer les broches de contrôle de direction du moteur groupe A en sortie
  pinMode(right_pwm,OUTPUT);//configurer les broches PWM du moteur groupe A en sortie
  pinMode(TRIG_PIN, OUTPUT); //Configurer la broche trig en sortie
  pinMode(ECHO_PIN, INPUT); //Configurer la broche echo en entrée
  pinMode(SCL_Pin,OUTPUT);//Configurer la broche d'horloge en sortie
  pinMode(SDA_Pin,OUTPUT);//Configurer la broche de données en sortie
  servopulse(servopin,90);//Définir l'angle initial du servo à 90°
  delay(500); //attendre 500ms
  matrix_display(smile);  //afficher le motif de sourire  
}

void loop() {
  distance = sr04.Distance();//distance détectée par le capteur ultrasonique
   if(distance <= 10)//si la distance est inférieure à 10
  {
    back();//reculer
  }
  else if((distance > 10)&&(distance< 20 ))//si 10<distance<20
  {
    Stop();//arrêter
  }
  else if((distance >= 20)&&(distance <= 50))//si 20≤distance≤50  
{
    front();//avancer
  }
  else//sinon
  {
    Stop();//arrêter
  }
}

void front()//définir l'état d'avancement vers l'avant
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,100);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,100);
}
void back()//définir l'état de recul
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void left()//définir l'état de virage à gauche
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void right()//définir l'état de virage à droite
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

void servopulse(int servopin,int myangle)//Angle de fonctionnement du servo-moteur
{
  for(int i=0; i<30; i++)
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

  for (int i = 0; i < 16; i++) //les données du motif sont de 16 octets
  {
    IIC_send(matrix_value[i]); //Transmettre les données du motif
  }
  IIC_end();   //Fin de la transmission des données du motif
  IIC_start();
  IIC_send(0x8A);  //Contrôle d'affichage, sélection de la largeur d'impulsion 4/16
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
//*******************************************************************************
```

### **5.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l'alimentation externe puis mettez le commutateur DIP sur ON. Réglez le servo à 90°, la voiture intelligente se déplacera en évitant les obstacles et la carte LED 8X16 affichera « smile ».