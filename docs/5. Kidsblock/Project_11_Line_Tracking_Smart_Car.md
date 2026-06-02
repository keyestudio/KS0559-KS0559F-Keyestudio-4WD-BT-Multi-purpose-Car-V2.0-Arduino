# Projet 11 Voiture Intelligente Suiveuse de Ligne

![](media/A271.png)

### **1.Description**

Basé sur le principe de fonctionnement du capteur suiveur de ligne, nous réalisons une voiture intelligente suiveuse de ligne.

Dans ce projet, nous détectons s'il y a une ligne noire sous la voiture intelligente grâce à un capteur suiveur de ligne, puis contrôlons la rotation des deux groupes de moteurs selon les résultats de détection afin de faire avancer la voiture intelligente le long de la ligne noire.

### **2.Diagramme de Flux**

![img](media/A272.png)

![Img](media/A273.png)

### **3.Schéma de Câblage**

![](media/A264.png)

G, V, S1, S2 et S3 du capteur suiveur de ligne sont connectés respectivement à G (GND), V (VCC), D11, D7 et D8 de la carte d'extension capteur.

L'alimentation est connectée au port BAT.

### **4.Code de Test**

Vous pouvez glisser les blocs pour éditer. Les blocs listés ci-dessous sont pour votre référence.

(1).![](media/A126.png)

(2).![](media/A274.png)

(3).![](media/A275.png)

(4).![](media/A268.png)

(5).![](media/A276.png)

**Code de Test Complet**

![](media/A277.png)

![](media/A278.png)

![](media/A279.png)

### **5.Résultat du Test**

Après avoir téléchargé avec succès le code sur la carte V4.0, connectez les câbles selon le schéma de câblage, alimentez la carte avec une source externe puis mettez l'interrupteur DIP sur ON. La voiture intelligente suivra alors la ligne.