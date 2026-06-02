# Projet 6 Réception IR

![9681c7da-a7c9-49ed-ad8c-32e00c6aeb07](media/A42.png)

### **1.Description** 

Il ne fait aucun doute que la télécommande infrarouge est omniprésente dans la vie quotidienne. Elle est utilisée pour contrôler divers appareils électroménagers, tels que les téléviseurs, les chaînes stéréo, les magnétoscopes et les récepteurs de signaux satellite. La télécommande infrarouge est composée d’un système d’émission infrarouge et d’un système de réception infrarouge, c’est-à-dire une télécommande infrarouge et un module de réception infrarouge ainsi qu’un microcontrôleur capable de décoder.  

![image-20250509154423060](media/A43.png)

Le signal porteur infrarouge à 38K émis par la télécommande est codé par la puce d’encodage dans la télécommande. Il est composé d’une section de code pilote, code utilisateur, code inverse utilisateur, code de données et code inverse de données. L’intervalle de temps de l’impulsion est utilisé pour distinguer s’il s’agit d’un signal 0 ou 1 et le codage est constitué de ces signaux 0, 1.

Le code utilisateur de la même télécommande est constant tandis que le code de données permet de distinguer la touche.

Lorsque le bouton de la télécommande est pressé, la télécommande envoie un signal porteur infrarouge. Lorsque le récepteur IR reçoit le signal, le programme décode le signal porteur et détermine quelle touche est pressée. Le MCU décode le signal 01 reçu, jugeant ainsi quelle touche est pressée sur la télécommande.

Le récepteur infrarouge que nous utilisons est un module récepteur infrarouge. Il est principalement composé d’une tête réceptrice infrarouge, qui est un dispositif intégrant réception, amplification et démodulation. Son circuit intégré interne a déjà effectué la démodulation, et peut réaliser la réception infrarouge jusqu’à la sortie compatible avec les signaux TTL.

De plus, il est adapté pour la télécommande infrarouge et la transmission de données infrarouges. Le module de réception infrarouge fabriqué par le récepteur ne possède que trois broches : ligne de signal, VCC et GND. Il est très pratique pour communiquer avec Arduino et d’autres microcontrôleurs.

### **2.Spécifications**

- Tension de fonctionnement : 3.3-5V (DC)

- Signal de sortie : Signal numérique

- Angle de réception : 90 degrés

- Fréquence : 38 kHz

- Distance de réception : 10 m

L’image montre le produit réel et le schéma du circuit du récepteur infrarouge.

![image-20250510082651985](media/A44.png)

### **3.Composants**

|           Carte de développement *1           |           Driver moteur 8833 *1           |     Module LED rouge *1     |
| :--------------------------------------------: | :---------------------------------------: | :-------------------------: |
| ![img](media/A8.jpg) | ![img](media/A9.jpg) | ![img](media/A10.jpg) |
|             Fil Dupont 3P *1                    |               Câble USB *1                 |                             |
|         ![img](media/A11.jpg)                   |         ![img](media/A12.jpg)              |                             |


Puisque la carte 8833 intègre le récepteur IR, il n’est pas nécessaire de faire de câblage. Les broches du module récepteur IR sont G (GND), V (VCC) et D3.

### **4.Code de test**

```c
//*************************************************************************************
/*
 keyestudio 4wd BT Car
 lesson 6.1
 IR remote
 http://www.keyestudio.com
*/ 
#include <IRremote.h>     //Bibliothèque IRremote  
int RECV_PIN = 3;        //définir la broche du récepteur IR comme D3
IRrecv irrecv(RECV_PIN);   
decode_results results;   // les résultats décodés existent dans “results” de “decode_results”
void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Activer le récepteur 
}  
  
 void loop() {  
  if (irrecv.decode(&results))//décodage réussi, réception d’un ensemble de signaux infrarouges  
   {  
     Serial.println(results.value, HEX);//Afficher le mot en HEX 16 bits et recevoir le code 
     irrecv.resume(); // Recevoir la valeur suivante
   }  
   delay(100);  
 } 
//*************************************************************************************
```

### **5.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l’ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, ouvrez le moniteur série et réglez le débit en bauds à 9600.

Sortez la télécommande et envoyez un signal au capteur récepteur infrarouge. Vous pouvez voir la valeur de la touche correspondante, si la durée d’appui sur la touche est trop longue, FFFFFFFF a tendance à afficher des caractères illisibles.

![image-20250510082931375](media/A45.png)

Les valeurs des touches de la télécommande Keyestudio sont affichées ci-dessous.

![image-20250510082942450](media/A46.png)

### **6. Explication du code**

**irrecv.enableIRIn() :** Après avoir activé le décodage IR, les signaux IR seront reçus,

**decode() :** La fonction « decode() » vérifiera en continu pour s’assurer que le décodage est réussi.

**irrecv.decode(\&results) :** après un décodage réussi, cette fonction retournera « true », et conservera le résultat dans « results ». Après avoir décodé les signaux IR, exécutez la fonction resume() et continuez à recevoir le signal suivant.

### **7. Pratique d’extension**

Nous avons décodé la valeur des touches de la télécommande IR. Que diriez-vous de contrôler une LED avec la valeur mesurée ? Nous pourrions concevoir une expérience.

Connectez une LED à D9, puis appuyez sur les touches de la télécommande pour allumer et éteindre la LED.

![image-20250508161123490](media/A13.png)

```c
//*************************************************************************************
/* 
keyestudio 4wd BT Car
lesson 6.2
IR remote LED
http://www.keyestudio.com
*/ 
#include <IRremote.h>
int RECV_PIN = 3;//définir la broche du récepteur IR comme D3
int LED_PIN = 9;//définir la broche de la LED comme broche 9
int a=0;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{Serial.begin(9600);
  irrecv.enableIRIn(); //Initialiser le récepteur IR
  pinMode(LED_PIN,OUTPUT);//définir la broche 9 de la LED en SORTIE
}

void loop() {
  if (irrecv.decode(&results)) 
  {
    if(results.value==0xFF02FD && (a==0)) //selon la valeur de la touche ci-dessus, appuyez sur « OK » sur la télécommande, la LED sera contrôlée
    {
      Serial.println("HIGH");
      digitalWrite(LED_PIN,HIGH);//la LED s’allumera
      a=1;
    }
    else if(results.value==0xFF02FD && (a==1)) //appuyez de nouveau
    {
      Serial.println("LOW");
      digitalWrite(LED_PIN,LOW);//la LED s’éteindra
      a=0;
    }
    irrecv.resume(); // recevoir la valeur suivante
  }
}
//*************************************************************************************
```

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, puis connectez l’ordinateur via un câble USB pour alimenter la carte. Après la mise sous tension, appuyer sur la touche "**OK**" de la télécommande peut allumer et éteindre la LED.