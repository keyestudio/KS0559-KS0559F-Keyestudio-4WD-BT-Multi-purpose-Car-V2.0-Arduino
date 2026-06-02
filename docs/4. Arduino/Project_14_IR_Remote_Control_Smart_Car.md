# Projet 14 Voiture intelligente télécommandée IR

![ff2fec813f8765e1bcd593b37b9c0a4f](media/A123.jpeg)

### **1.Description**

Dans ce projet, nous allons réaliser une voiture intelligente télécommandée par IR et appuyer sur le bouton de la télécommande IR pour faire avancer la voiture.

### **2.Diagramme de flux**

![img](media/A124.png)

**La logique spécifique de la voiture intelligente télécommandée IR est présentée ci-dessous :**

| Configuration initiale                     |           | La carte LED affiche un visage souriant          |
| ----------------------------------------- | --------- | ------------------------------------------------- |
| Télécommande                             | Valeur clé | État de la touche                                  |
| ![img](media/A125.jpg) | FF629D    | AvantLa carte LED 8*8 affiche l'icône avant       |
| ![img](media/A126.jpg) | FFA857    | ArrièreLa carte LED 8*8 affiche l'icône arrière    |
| ![img](media/A127.jpg)                  | FF22DD    | Tourner à gaucheLa carte LED 8*8 affiche l'icône vers la gauche |
| ![img](media/A128.jpg)                  | FFC23D    | Tourner à droiteLa carte LED 8*8 affiche l'icône vers la droite |
| ![img](media/A129.jpg)                 | FF02FD    | ArrêtLa carte LED 8*8 affiche “STOP”               |

### **3.Schéma de câblage**

![9d8b58dff14fe22b5c87514db944530c](media/A130.png)

1). GND, VCC, SDA et SCL du module carte LED 8\*8 sont connectés respectivement à G (GND), V (VCC), A4 et A5 de la carte d'extension.

2). Comme le récepteur IR est intégré sur le Shield moteur 8833, aucun câblage supplémentaire n'est nécessaire. Les broches du récepteur IR sur la carte 8833 sont respectivement G (GND), V (VCC) et D3.

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge à 5V (V) et le fil orange à A3.

4). L'alimentation est connectée au port BAT
    

### **4.Code de test**

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 14
IR remote Control Car
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Définir la broche d'horloge sur A5
#define SDA_Pin  A4  //Définir la broche de données sur A4
//Tableau, utilisé pour stocker les données du motif, peut être calculé par vous-même ou obtenu à partir de l'outil de module
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#include <Arduino.h>
#include <IRremote.h>//bibliothèque de fonctions de la télécommande IR
int RECV_PIN = 3;//définir la broche du récepteur IR sur D3
IRrecv irrecv(RECV_PIN);
long irr_val;
decode_results results;

int left_ctrl = 2;//définir les broches de contrôle de direction du moteur du groupe B
int left_pwm = 5;//définir les broches de contrôle PWM du moteur du groupe B
int right_ctrl = 4;//définir les broches de contrôle de direction du moteur du groupe A
int right_pwm = 6;//définir les broches de contrôle PWM du moteur du groupe A

#include <Servo.h>
Servo servo_A3;//définir la broche du servo sur A3 

unsigned char data_line = 0;
unsigned char delay_count = 0;

void setup() {
  Serial.begin(9600);//
  // Au cas où le pilote d'interruption plante lors de la configuration, donner un indice
  // à l'utilisateur sur ce qui se passe.
  Serial.println("Activation de IRin");
  irrecv.enableIRIn(); // Démarrer le récepteur
  Serial.println("IRin activé");
  pinMode(left_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur du groupe B en OUTPUT
  pinMode(left_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur du groupe B en OUTPUT
  pinMode(right_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur du groupe A en OUTPUT
  pinMode(right_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur du groupe A en OUTPUT
  servo_A3.attach(A3);
  servo_A3.write(90);//l'angle du servo est de 90 degrés
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Définir la broche d'horloge en sortie
  pinMode(SDA_Pin,OUTPUT);//Définir la broche de données en sortie
  matrix_display(clear);
  matrix_display(start01); //afficher le motif d'expression start01
}

void loop()
 {
  if (irrecv.decode(&results)) 
 {
    irr_val = results.value;
    Serial.println(irr_val, HEX);//affiche en série les signaux IR télécommandés lus 
    switch(irr_val)
    {
      case 0xFF629D : car_front(); //Reçoit 0xFF629D, la voiture avance
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 0xFFA857 : car_back(); //Reçoit 0xFFA857, la voiture recule
      matrix_display(clear);
      matrix_display(back); 
      break;
    
      case 0xFF22DD : car_left(); //Reçoit 0xFF22DD, la voiture tourne à gauche
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 0xFFC23D : car_right();//Reçoit 0xFFC23D, la voiture tourne à droite
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 0xFF02FD : car_Stop();//Reçoit 0xFF02FD, la voiture s'arrête
      matrix_display(clear);
      matrix_display(STOP01); 
      break;
    }
        irrecv.resume(); // Recevoir la valeur suivante
  }
}

void car_front()//définir l'état d'avancement
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,105);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,105);
}
void car_back()//définir l'état de recul
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,150);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,150);
}
void car_left()//définir l'état de rotation à gauche
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 100);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 155);
}
void car_right()//définir l'état de rotation à droite
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 100);
}
void car_Stop()//définir l'état d'arrêt
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

//cette fonction est utilisée pour l'affichage sur matrice de points
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  //la fonction qui appelle la condition de démarrage du transfert de données
  IIC_send(0xc0);  //sélectionner l'adresse

  for (int i = 0; i < 16; i++) // les données du motif sont sur 16 octets
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) // Chaque octet contient 8 bits et est vérifié bit par bit en commençant par le bit de poids faible
  {
    if (send_data & mask) { // Définit les niveaux haut et bas de SDA_Pin selon que chaque bit de l'octet est un 1 ou un 0
      digitalWrite(SDA_Pin, HIGH);
    } else {
      digitalWrite(SDA_Pin, LOW);
    }
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, HIGH); // Met la broche d'horloge SCL_Pin à haut pour arrêter la transmission des données
    delayMicroseconds(3);
    digitalWrite(SCL_Pin, LOW); // Met la broche d'horloge SCL_Pin à bas pour changer le SIGNAL de SDA 
  }
}
//*******************************************************************************
```

### **5. Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l'alimentation externe puis mettez l'interrupteur DIP sur ON. Ensuite, nous pouvons utiliser la télécommande IR pour piloter la voiture et la carte LED 8X16 affichera le motif d'état correspondant.