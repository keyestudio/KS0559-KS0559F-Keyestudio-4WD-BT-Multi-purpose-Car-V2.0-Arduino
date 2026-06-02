# Projet 10 Voiture Intelligente Limitée

![](media/A261.jpeg)

### **1.Description**

Dans ce projet, nous cherchons à combiner les connaissances d'un capteur de suivi de ligne et des modules de pilote de moteur pour fabriquer une voiture intelligente limitée. Lors de l'expérience, nous visons à utiliser le capteur de suivi de ligne pour détecter s'il y a une ligne noire autour de la voiture intelligente, puis contrôler la rotation des deux moteurs selon les résultats de détection de manière à verrouiller la voiture intelligente dans un cercle tracé en ligne noire.

### **2.Diagramme de Flux**

![img](media/A262.png)

La logique spécifique de la voiture intelligente 4WD limitée est montrée dans le tableau.

![Img](media/A263.png)

### **3.Schéma de Câblage**

![](media/A264.png)

G, V, S1, S2 et S3 du capteur de suivi de ligne sont connectés à G (GND), V (VCC), D11, D7 et D8 de la carte d'extension du capteur.

L'alimentation est connectée au port BAT.

### **4.Code de Test**

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A265.png)

(3).![](media/A266.png)

(4).![](media/A267.png)

(5).![](media/A268.png)

(6).![](media/A269.png)

**Code de Test Complet**

![KidsBlock Project-1747127137354](media/A270.png)



### **5.Résultat du Test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câblages selon le schéma de câblage, alimentez l'alimentation externe puis mettez l'interrupteur DIP sur ON. Placez la voiture intelligente dans le cercle noir, elle se déplacera alors uniquement dans le cercle.