# Projet 16 Contrôle de Vitesse Bluetooth Voiture Intelligente

![](media/A131.jpeg)

### **1.Description**

Dans ce projet, nous utiliserons un Bluetooth pour ajuster la vitesse de la voiture intelligente. Nous permettons de définir des vitesses variables et de les changer pour modifier la vitesse de la voiture intelligente.

### **2.Diagramme de Flux**

![90ab1f7fb1e16ad3c018b1c631e407c3](media/A134.png)

### **3.Schéma de Câblage**

![](media/A135.png)

1). GND, VCC, SDA et SCL de la carte LED 8\*8 sont connectés à G (GND), V (VCC), A4 et A5 de la carte d’extension.

2). Les broches RXD, TXD, GND et VCC du module Bluetooth sont respectivement connectées à TX, RX, G et 5V sur le Shield moteur 8833, tandis que les broches STATE et BRK du module Bluetooth n’ont pas besoin d’être connectées.

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge est connecté à 5V (V) et le fil orange est connecté à A3.

4). L’alimentation est connectée au port BAT.

### **4.Code de Test**

<span style="color: rgb(255, 76, 65);">**Note :** Avant de téléverser le code de test, vous devez retirer le module Bluetooth, sinon le code ne pourra pas être téléversé. Reconnectez le module Bluetooth après avoir téléversé le code avec succès.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 16
Bluetooth Speed Control Car
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Définir la broche d’horloge sur A5
#define SDA_Pin  A4  //Définir la broche de données sur A4
//Tableau, utilisé pour stocker les données du motif, peut être calculé par vous-même ou obtenu à partir de l’outil de module
unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char speed_a[] = 
{0x00,0x40,0x20,0x10,0x08,0x04,0x02,0xff,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00};
unsigned char speed_d[] = 
{0x00,0x02,0x04,0x08,0x10,0x20,0x40,0xff,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00};

int left_ctrl = 2;//définir les broches de contrôle de direction du moteur groupe B
int left_pwm = 5;//définir les broches de contrôle PWM du moteur groupe B
int right_ctrl = 4;//définir les broches de contrôle de direction du moteur groupe A
int right_pwm = 6;//définir les broches de contrôle PWM du moteur groupe A

int speeds = 150; //Définir la vitesse initiale à 150

const int servopin = A3;//définir la broche du servo sur A3 

char BLE_val;

void setup() {
  Serial.begin(9600);//
  pinMode(left_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur groupe B en sortie
  pinMode(left_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur groupe B en sortie
  pinMode(right_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur groupe A en sortie
  pinMode(right_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur groupe A en sortie
  servopulse(servopin,90);//l’angle du servo est de 90 degrés
  delay(300);
  pinMode(SCL_Pin,OUTPUT);// Définir la broche d’horloge en sortie
  pinMode(SDA_Pin,OUTPUT);//Définir la broche de données en sortie
  matrix_display(clear);
  matrix_display(start01); //afficher le motif start01
}

void loop() {
   if(Serial.available()>0) {
    BLE_val = Serial.read();
    Serial.println(BLE_val);
  } 
    switch(BLE_val)
    {
      case 'F' : car_front(); 
      matrix_display(clear);
      matrix_display(front);   
      break;
      
      case 'B' : car_back(); 
      matrix_display(clear);
      matrix_display(back); 
      break;

      case 'L' : car_left(); 
      matrix_display(clear);
      matrix_display(left); 
      break;
     
      case 'R' : car_right();
      matrix_display(clear);
      matrix_display(right);  
      break;
     
      case 'S' : car_Stop();
      matrix_display(clear);
      matrix_display(STOP01); 
      break;

      case 'a' : speeds_a();
      matrix_display(clear);
      matrix_display(speed_a);  
      break;
     
      case 'd' : speeds_d();
      matrix_display(clear);
      matrix_display(speed_d); 
      break;
    }
}

void car_front()//définir l'état d'avancer
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,(255-speeds));
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,(255-speeds));
}
void car_back()//définir l'état de recul
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,speeds);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,speeds);
}
void car_left()//définir l'état de virage à gauche
{
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, speeds);  
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, (255-speeds));
}
void car_right()//définir l'état de virage à droite
{
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, (255-speeds));
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, speeds);
}
void car_Stop()//définir l'état d'arrêt
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,0);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,0);
}

void speeds_a() { //fonction d'accélération rapide
  while (1) {
    Serial.println(speeds);  //afficher les informations de vitesse 
    if (speeds < 255) { //jusqu'à 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //ajuster la vitesse de croissance
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Reçoit 'S', la voiture arrête d'accélérer
    break;
  }
}
void speeds_d() { //fonction de réduction de vitesse
  while (1) {
    Serial.println(speeds);  //afficher les informations de vitesse
    if (speeds > 0) { //jusqu'à 0
      matrix_display(clear);
      matrix_display(speed_d);
      speeds--;
      delay(10);    //ajuster la vitesse de décélération
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Reçoit 'S', la voiture arrête de décélérer
    break;
}
}

void servopulse(int servopin,int myangle)//angle de fonctionnement du servo
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
  IIC_start();  //la fonction qui appelle la condition de début de transfert de données
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
  for (byte mask = 0x01; mask != 0; mask <<= 1) // Chaque octet a 8 bits et est vérifié bit par bit en commençant par le bit de poids faible
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

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l'alimentation externe puis mettez l'interrupteur DIP sur ON. En appariant l'APP avec le Bluetooth, la voiture intelligente peut être contrôlée pour se déplacer via l'APP.

Appuyez sur ![049343f587e0e7cf19fe8b665d735321](media/A136.png), la voiture accélérera, appuyez sur ![264f77cce6018584b54f46676fee4247](media/A137.png), la voiture ralentira, et la carte LED 8\*16 affichera le motif d'état correspondant de la voiture intelligente.