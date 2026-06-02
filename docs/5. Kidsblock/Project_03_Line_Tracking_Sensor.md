# Projet 3 : Capteur de Suivi de Ligne

![](media/A63.png)

### **1.Description** 

Le capteur de suivi est en réalité un capteur infrarouge. Le composant utilisé ici est le tube infrarouge TCRT5000. Son principe de fonctionnement est d'utiliser la réflectivité différente de la lumière infrarouge selon les couleurs, puis de convertir la puissance du signal réfléchi en un signal courant.

Lors du processus de détection, le noir est actif au niveau HAUT tandis que le blanc est actif au niveau BAS. La hauteur de détection est de 0-3 cm.

Le module de suivi de ligne 3 canaux Keyestudio intègre 3 ensembles de tubes infrarouges TCRT5000 sur une carte, ce qui est plus pratique pour le câblage et le contrôle.

En tournant le potentiomètre réglable sur le capteur, on peut ajuster la sensibilité de détection du capteur.

### **2.Spécifications**

- Tension de fonctionnement : 3,3-5V (DC)

- Interface : 5PIN

- Signal de sortie : Signal numérique

- Hauteur de détection : 0-3 cm

![](media/A64.jpeg)

<span style="color: rgb(255, 76, 65);">Note :</span> Avant le test, tournez le potentiomètre sur le capteur pour ajuster la sensibilité de détection. La sensibilité est optimale lorsque la LED est réglée à un seuil entre ON et OFF.

### **3.Composants**

| Carte de développement *1 | Driver moteur 8833 *1 | Module LED rouge *1 | Capteur de suivi de ligne *1 |
| ------------------------- | --------------------- | ------------------- | ---------------------------- |
| ![img](media/A65.jpg)     | ![img](media/A66.jpg) | ![img](media/A67.jpg) | ![img](media/A68.png)         |
| Fil Dupont 5P *1          | Câble USB *1          | Fil Dupont 3P *1    |                              |
| ![img](media/A69.png)     | ![img](media/A70.jpg) | ![img](media/A71.jpg) |                              |

### **4.Schéma de câblage**

![](media/A72.png)

G, V, S1, S2 et S3 du capteur de suivi de ligne sont connectés respectivement à G (GND), V (VCC), D11, D7 et D8 de la carte d’extension du capteur.

### **5.Code de test**

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A75.png)

(4).![](media/A76.png)

(5).![](media/A77.png)

**Code de test complet**

![](media/A78.png)

![](media/A79.png)

### **6.Résultat du test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et utilisez un câble USB pour connecter l’ordinateur afin d’alimenter la carte.

Après la mise sous tension, cliquez sur ![](media/A80.png) pour régler le débit en bauds à 9600 et vous verrez l’état des trois capteurs de suivi de ligne. Lorsqu’aucun signal n’est reçu, la valeur est 1. Si nous couvrons le capteur avec un papier blanc, la valeur sera 0.

![](media/A81.png)

![](media/A82.png)

### **7.Pratique d’extension**

Après avoir compris son principe de fonctionnement, vous pouvez connecter une LED à D9 afin de contrôler la LED avec ce capteur.

![](media/A83.png)

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A73.png)

(2).![](media/A74.png)

(3).![](media/A84.png)

(4).![](media/A85.png)

(5).![](media/A77.png)

(6).![](media/A86.png)

(7).![](media/A87.png)

**Code de test complet**

![](media/A88.png)

![](media/A89.png)

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, et utilisez un câble USB pour connecter l’ordinateur afin d’alimenter la carte.

Après la mise sous tension, approchez un papier du capteur, puis vous verrez la LED s’allumer lorsque le capteur de suivi de ligne est couvert.