# Projet 17 Voiture intelligente Bluetooth polyvalente

![2c1198e0ebd7c31622b7438469fb572c](media/A138.jpeg)

### **1.Description**

Dans les projets précédents, la voiture ne réalise qu'une seule fonction. Cependant, dans cette leçon, nous allons intégrer toutes ses fonctions via un Bluetooth.

### **2.Diagramme de flux**

![73f4da1e321bc29282d3b2f5cb3168dd](media/A139.png)

### **3.Schéma de câblage**

![fce8edd349ddbcfe02e6f27feb73e90f](media/A140.png)

1). GND, VCC, SDA et SCL de la carte LED 8\*8 sont connectés respectivement à G (GND), V (VCC), A4 et A5 de la carte d'extension.

2). Les broches RXD, TXD, GND et VCC du module Bluetooth sont respectivement connectées à TX, RX, G et 5V sur le Shield moteur 8833, tandis que les broches STATE et BRK du module Bluetooth n'ont pas besoin d'être connectées.

3). Le servo est connecté à G, V et A3. Le fil marron est connecté à Gnd (G), le fil rouge est connecté à 5V (V) et le fil orange est connecté à A3.

4). G, V, S1, S2 et S3 du capteur de suivi de ligne sont connectés respectivement à G (GND), V (VCC), D11, D7 et D8 de la carte d'extension capteur.

5). VCC, Trig, Echo et Gnd du capteur ultrason sont connectés respectivement à 5V (V), D12 (S), D13 (S) et Gnd (G).

6). L'alimentation est connectée au port BAT.

### **4.Code de test**

<span style="color: rgb(255, 76, 65);">**Remarque :** Avant de téléverser le code de test, vous devez retirer le module Bluetooth, sinon le code ne pourra pas être téléversé. Reconnectez le module Bluetooth après avoir téléversé le code avec succès.</span>

```c
//*******************************************************************************
/*
keyestudio 4wd BT Car 
lesson 17
Bluetooth Multifunctional Car
http://www.keyestudio.com
*/ 
#define SCL_Pin  A5  //Définir la broche d'horloge sur A5
#define SDA_Pin  A4  //Définir la broche de données sur A4
//Tableau, utilisé pour stocker les données du motif, peut être calculé soi-même ou obtenu à partir de l'outil de module
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

int left_ctrl = 2;//définir les broches de contrôle de direction du moteur du groupe B
int left_pwm = 5;//définir les broches de contrôle PWM du moteur du groupe B
int right_ctrl = 4;//définir les broches de contrôle de direction du moteur du groupe A
int right_pwm = 6;//définir les broches de contrôle PWM du moteur du groupe A
int speeds = 150; //Définir la vitesse initiale à 150

const int servopin = A3;//définir la broche du servo sur A3 

int L_pin = 11; //définir la broche du capteur de suivi gauche comme D11
int M_pin = 7; //définir la broche du capteur de suivi milieu comme D7
int R_pin = 8; //définir la broche du capteur de suivi droite comme D8
int L_val, M_val, R_val;

int trigPin = 12; //Broche TRIG connectée à D12
int echoPin = 13; //Broche ECHO connectée à D13
int distance, distance_l, distance_r;

char BLE_val;

void setup() {
  Serial.begin(9600);//Définir le débit en bauds à 9600
  pinMode(left_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur du groupe B en SORTIE
  pinMode(left_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur du groupe B en SORTIE
  pinMode(right_ctrl,OUTPUT);//définir les broches de contrôle de direction du moteur du groupe A en SORTIE
  pinMode(right_pwm,OUTPUT);//définir les broches de contrôle PWM du moteur du groupe A en SORTIE
  servopulse(servopin,90);//l'angle du servo est de 90 degrés
  delay(300);
  pinMode(L_pin, INPUT); //Les broches du capteur de suivi sont configurées en mode entrée
  pinMode(M_pin, INPUT);
  pinMode(R_pin, INPUT);
  pinMode(trigPin, OUTPUT); //définir TRIG en mode sortie
  pinMode(echoPin, INPUT); //définir ECHO en mode entrée
  pinMode(SCL_Pin,OUTPUT);// Définir la broche d'horloge en sortie
  pinMode(SDA_Pin,OUTPUT);//Définir la broche de données en sortie
  matrix_display(clear);
  matrix_display(start01); //afficher le motif d'expression start01
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
    
      case  'U':  follow();  //Réception de ‘U’, entrer en mode suivi
      break; 
      case  'Y':  avoid(); //Réception de ‘Y’, entrer en mode évitement d'obstacle  
      break;  
      case  'G':  confinement(); //Réception de ‘G’, entrer en mode confinement
      break;  
      case  'X':  tracking(); //Réception de ‘X’, entrer en mode suivi de ligne
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
    if (speeds < 255) { //Jusqu'à 255
      matrix_display(clear);
      matrix_display(speed_a);
      speeds++;
      delay(10);  //ajuster la vitesse de croissance
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') //Réception de 'S', la voiture arrête d'accélérer
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
    if (BLE_val == 'S') //Réception de 'S', la voiture arrête de décélérer
    break;
}
}

int get_distance() {
  int distance = 0;
  digitalWrite(trigPin, LOW);     // envoyer une impulsion via Trig/Pin, déclencher la mesure HC-SR04, pour que l'interface du signal ultrasonore soit à un niveau bas pendant 2μs
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);    // mettre l'interface du signal ultrasonore à un niveau haut pendant 10μs, ici au moins 10μs
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);     // maintenir l'interface du signal ultrasonore à un niveau bas
  distance = pulseIn(echoPin, HIGH) / 58; // lire la durée de l'impulsion et convertir cette durée en distance (unité : cm)
  Serial.println(distance);        // afficher la valeur de la distance
  return distance;
}

void follow() {
  servopulse(servopin,90);
  delay(200);
  int follow_flag = 1;
  while (follow_flag) {
    distance = get_distance(); // appeler la fonction de mesure de distance
    if (distance < 8 ) {// Si la distance est inférieure à 8
      car_back();// la voiture recule
      matrix_display(clear);
      matrix_display(back); 
    }
    else if (distance >= 8 && distance < 13) { // Si la distance est supérieure ou égale à 8 et inférieure à 13
      car_Stop();// arrêt
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    else if (distance >= 13 && distance <= 35 ) { // Si la distance est supérieure ou égale à 13 et inférieure ou égale à 35
      car_front();// la voiture avance
      matrix_display(clear);
      matrix_display(front);
    }
    else {// Sinon
      car_Stop();// arrêt
      matrix_display(clear);
      matrix_display(STOP01); 
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // Lorsque 'S' est reçu, la voiture s'arrête
      follow_flag = 0;
      car_Stop();
    }
  }
}

void avoid() {
  int avoid_flag = 1;
  while (avoid_flag) {
    distance = get_distance(); // Appeler la fonction de mesure de distance
    if (distance > 0 && distance < 20) { // Si la distance est inférieure à 20 et supérieure à 0
      car_Stop();// arrêt
      matrix_display(clear);
      matrix_display(STOP01);   // la matrice de points affiche un motif d'arrêt
      delay(1000);
      servopulse(servopin,160); // amener le servo à plus de 180 degrés
      delay(500);
      distance_l = get_distance(); // obtenir la distance à gauche
      delay(100);
      servopulse(servopin,20); // tourner le servo à 0 degré
      delay(500);
      distance_r = get_distance(); // obtenir la distance à droite
      delay(100);
      if (distance_l > distance_r) { // comparer les distances, si la gauche est plus grande que la droite
        car_left();  // la voiture tourne à gauche
        matrix_display(clear);
        matrix_display(left);   // la matrice de points affiche un motif gauche
        servopulse(servopin,90);// le servo revient à 90 degrés
        delay(700);
        matrix_display(clear);
        matrix_display(front);   // la matrice de points affiche un motif avant
      } 
      else { // Sinon si la droite est plus grande que la gauche
        car_right();// la voiture tourne à droite
        matrix_display(clear);
        matrix_display(right);   // la matrice de points affiche un motif droite
        servopulse(servopin,90);// le servo revient à 90 degrés
        delay(700);
        matrix_display(clear);
        matrix_display(front);   // la matrice de points affiche un motif avant
      }
    }
    else { // Lorsque la distance devant est supérieure ou égale à 20 cm
      car_front();// la voiture avance
      matrix_display(clear);
      matrix_display(front);   // la matrice de points affiche un motif avant

    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') {// Lorsque 'S' est reçu, la voiture s'arrête
      avoid_flag = 0;
      car_Stop();
    }
  }
}

void confinement() {
  int confinement_flag = 1;
  while (confinement_flag) {
    L_val = digitalRead(L_pin); // lire la valeur du capteur gauche
    M_val = digitalRead(M_pin); // lire la valeur du capteur du milieu
    R_val = digitalRead(R_pin); // lire la valeur du capteur droit
    if ( L_val == 0 && M_val == 0 && R_val == 0 ) { // la voiture avance lorsqu'aucune ligne noire n'est détectée
      car_front();
    }
    else { // Sinon, si l'un des capteurs de suivi détecte une ligne noire, la voiture recule puis tourne à gauche
      car_back();
      delay(500);
      car_left();
      delay(800);
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // Lorsque 'S' est reçu, la voiture s'arrête
      confinement_flag = 0;
      car_Stop();
    }
  }
}

void tracking() {
  int track_flag = 1;
  while (track_flag) {
    L_val = digitalRead(L_pin); // lire la valeur du capteur gauche
    M_val = digitalRead(M_pin); // lire la valeur du capteur du milieu
    R_val = digitalRead(R_pin); // lire la valeur du capteur droit
    if (M_val == 1) { // Ligne noire détectée au milieu
      if (L_val == 1 && R_val == 0) { // Si une ligne noire est détectée à gauche, mais pas à droite, tourner à gauche
        car_left();
      }
      else if (L_val == 0 && R_val == 1) { // Sinon, si une ligne noire est détectée à droite et pas à gauche, tourner à droite
        car_right();
      }
      else { // Sinon, la voiture avance
        car_front();
      }
    }
    else { // aucune ligne noire détectée au milieu
      if (L_val == 1 && R_val == 0) { // Si une ligne noire est détectée à gauche, mais pas à droite, tourner à gauche
        car_right();
      }
      else if (L_val == 0 && R_val == 1) { // Sinon, si une ligne noire est détectée à droite et pas à gauche, tourner à droite
        car_right();;
      }
      else { // Sinon, s'arrêter
        car_Stop();
      }
    }
    BLE_val = Serial.read();
    if (BLE_val == 'S') { // Lorsque 'S' est reçu, la voiture s'arrête
      track_flag = 0;
      car_Stop();
    }
  }
}

void servopulse(int servopin,int myangle)// Angle de fonctionnement du servo
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

// cette fonction est utilisée pour l'affichage matriciel
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();  // la fonction qui appelle la condition de démarrage du transfert de données
  IIC_send(0xc0);  // sélectionner l'adresse

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

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l'alimentation externe puis mettez l'interrupteur DIP sur ON.

Après que le module Bluetooth est connecté à l'APP et que l'application mobile est connectée avec succès au Bluetooth, la voiture intelligente peut être contrôlée par l'application mobile. Nous pouvons réaliser les fonctions correspondantes en appuyant sur les boutons correspondants de l'application mobile. 