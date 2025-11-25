# 📚 **EXERCICES A à Q**


## **📘 EXERCICE A : Accès aux éléments d'un tableau**
*Pour ceux qui ont raté Q1, Q2 ou Q5*

### **Rappel**
```
int tab[5] → indices : 0, 1, 2, 3, 4
Premier = tab[0], Dernier = tab[4]
```

### **Mission**
Avec le tableau `{12, 15, 8, 17, 14, 11}` :
1. Afficher le 1er, 3ème et dernier élément
2. Calculer la somme du 1er et dernier

### **Sortie attendue**
```
Premier : 12
Troisième : 8
Dernier : 11
Somme : 23
```

---

## **📕 EXERCICE B : Sécurité - Éviter les débordements**
*Pour ceux qui ont raté Q3 ou Q6*

### **Mission**
Créer `int verifier_acces(int tab[], int taille, int indice)` :
- Si indice valide → retourner `tab[indice]`
- Si indice invalide → retourner `-999` et afficher "Erreur"

### **Tests**
```
Tableau [10,20,30,40,50]
verifier_acces(tab, 5, 3) → 40
verifier_acces(tab, 5, 5) → -999 + "Erreur"
verifier_acces(tab, 5, -1) → -999 + "Erreur"
```

---

## **📗 EXERCICE C : Parcours simple avec boucle for**
*Pour ceux qui ont raté Q4*

### **Mission**
Trois fonctions pour afficher `[10, 20, 30, 40, 50]` :
1. Normal : `10 20 30 40 50`
2. Inverse : `50 40 30 20 10`
3. Un sur deux : `10 30 50`

### **Indices**
- Normal : `for(i=0; i<taille; i++)`
- Inverse : `for(i=taille-1; i>=0; i--)`
- Un sur deux : `for(i=0; i<taille; i+=2)`

---

## **📙 EXERCICE D : Parcours pour éléments consécutifs**
*Pour ceux qui ont raté Q7, Q8 ou Q10*

### **Rappel crucial**
```
Pour comparer tab[i] et tab[i+1] :
→ i doit aller jusqu'à taille-2
→ for(i=0; i<taille-1; i++)
```

### **Mission**
Analyser `[10, 15, 15, 12, 18]` et compter :
- Montées (suivant > actuel)
- Descentes (suivant < actuel)
- Stables (suivant == actuel)

### **Sortie attendue**
```
0→1 : montée
1→2 : stable
2→3 : descente
3→4 : montée
Total : 2 montées, 1 descente, 1 stable
```

---

## **📘 EXERCICE E : Calcul de distance et variations**
*Pour ceux qui ont raté Q9 ou Q11*

### **Mission**
Pour `[10, 15, 12, 20, 14]`, trouver :
1. Plus petite variation entre consécutifs
2. Plus grande variation
3. Variation moyenne

### **Calculs**
```
Variations : |15-10|=5, |12-15|=3, |20-12|=8, |14-20|=6
Min : 3, Max : 8, Moyenne : 5.5
```

---

## **📕 EXERCICE F : Comparaisons et conditions**
*Pour ceux qui ont raté Q12, Q13 ou Q14*

### **Rappel AND/OR**
```
✅ Dans [10,20] : if(x >= 10 && x <= 20)
❌ FAUX :        if(x >= 10 || x <= 20) // Toujours vrai !
```

### **Mission**
Classer `[5, 15, 25, 10, 8, 22, 18]` en :
- Petit : < 10
- Moyen : 10-20 inclus
- Grand : > 20

### **Résultat**
```
Petits : 2
Moyens : 3
Grands : 2
```

---

## **📗 EXERCICE G : Types de retour (char, int)**
*Pour ceux qui ont raté Q15 ou Q16*

### **Mission**
Fonction `char obtenir_mention(int note)` :
- ≥16 → 'E' (Excellent)
- 14-15 → 'B' (Bien)
- 12-13 → 'A' (Assez bien)
- 10-11 → 'P' (Passable)
- <10 → 'I' (Insuffisant)

### **Test**
```
18 → E
15 → B
13 → A
11 → P
8 → I
```

---

## **📙 EXERCICE H : Calculs (abs, somme, moyenne)**
*Pour ceux qui ont raté Q17, Q18 ou Q19*

### **Mission**
Pour `[5, -3, 8, -2, 10]`, calculer :
1. Somme des positifs
2. Somme des valeurs absolues
3. Max - Min

### **Résultats**
```
Positifs : 23 (5+8+10)
Absolues : 28 (5+3+8+2+10)
Amplitude : 13 (10-(-3))
```

---

## **📘 EXERCICE I : Pourcentages**
*Pour ceux qui ont raté Q20*

### **Rappel**
```
Pourcentage = (partie * 100) / total
Attention : (3/4)*100 = 0 (division entière)
            (3*100)/4 = 75 ✓
```

### **Mission**
Pour `[1, 1, 0, 1, 1, 1, 0, 1]` (réponses QCM) :
1. Taux de réussite (% de 1)
2. Plus longue série de 1 consécutifs

### **Résultat**
```
Taux : 75% (6 sur 8)
Plus longue série : 3
```

---

## **📕 EXERCICE J : Initialisation des compteurs**
*Pour ceux qui ont raté Q21 ou Q22*

### **Rappel**
```c
int compteur;     // ❌ Valeur aléatoire !
int compteur = 0; // ✅ Toujours initialiser
```

### **Mission**
Dans `[0, 4, 7, 9, 0, 11, 16, 2]`, compter :
1. Les zéros
2. Les nombres premiers
3. Les carrés parfaits (4, 9, 16...)

### **Résultat**
```
Zéros : 2
Premiers : 3 (7, 11, 2)
Carrés : 3 (4, 9, 16)
```

---

## **📗 EXERCICE K : Comptage avec conditions**
*Pour ceux qui ont raté Q23, Q24 ou Q25*

### **Mission**
Pour les températures `[-2, 3, 15, 18, 26, 22, 8]` :
1. Jours de gel (< 0°C)
2. Jours doux (10-20°C)
3. Jours chauds (> 25°C)

### **Résultat**
```
Gel : 1 jour
Doux : 2 jours (15, 18)
Chauds : 1 jour
```

---

## **📙 EXERCICE L : Fonctions booléennes**
*Pour ceux qui ont raté Q26 ou Q27*

### **Mission**
Créer 3 fonctions (retour 1 ou 0) :
1. `est_palindrome()` : tableau symétrique
2. `contient_doublon()` : valeur répétée
3. `est_croissant()` : chaque élément ≥ précédent

### **Tests**
```
[1,2,3,2,1] → palindrome: OUI
[1,2,3,4,5] → doublon: NON
[1,3,3,5,7] → croissant: OUI
```

---

## **📘 EXERCICE M : Return et conversions**
*Pour ceux qui ont raté Q28 ou Q29*

### **Mission**
Convertir des secondes en minutes :
```
150 secondes → 2 min 30 sec
330 secondes → 5 min 30 sec
```

### **Formules**
```c
minutes = secondes / 60
reste = secondes % 60
```

---

## **📕 EXERCICE N : Vérification de propriétés**
*Pour ceux qui ont raté Q30*

### **Mission**
Vérifier si des temps de course sont en "progression" :
- Chaque temps < précédent
- Différence ≥ 2 secondes

### **Tests**
```
[350,345,340,335] → OUI (écarts de 5)
[350,348,340,335] → NON (écart de 2 seulement)
[350,345,350,335] → NON (345 à 350 augmente)
```

---

## **📗 EXERCICE O : Double boucle et pièges OR**
*Pour ceux qui ont raté Q31 ou Q32*

### **Mission**
Dans `[2, 7, 3, 6, 1, 8]`, trouver les paires qui font 9 :

### **Structure**
```c
for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
        if(tab[i]+tab[j] == 9)
```

### **Résultat**
```
(0,1): 2+7=9
(2,3): 3+6=9
(4,5): 1+8=9
Total: 3 paires
```

---

## **📙 EXERCICE P : Return anticipé et accumulation**
*Pour ceux qui ont raté Q33, Q34 ou Q35*

### **Mission**
1. Trouver le premier nombre premier
2. Calculer la somme AVANT lui
3. Retourner -1 si aucun premier

### **Tests**
```
[4,6,8,7,10] → Premier: 7, Somme avant: 18
[4,6,8,10] → Pas de premier: -1
[2,4,6] → Premier: 2, Somme avant: 0
```

---

## **📘 EXERCICE Q : Validation globale**
*Pour ceux qui ont raté Q36*

### **Mission complète**
Programme qui calcule pour un tableau :
1. Min, Max, Moyenne
2. Nombre d'éléments > moyenne
3. Vérifier si trié croissant
4. Plus grande montée entre consécutifs

### **Test avec** `[3, 8, 5, 12, 9, 15, 11]`
```
=== ANALYSE ===
Min : 3
Max : 15
Moyenne : 9.0
> Moyenne : 3 éléments
Trié : NON
Plus grande montée : 7 (de 5 à 12)
```

---

## **✅ AUTO-ÉVALUATION**

Pour chaque exercice :
- **0 pt** : Ne compile pas
- **1 pt** : Compile mais faux
- **2 pts** : Partiellement correct
- **3 pts** : Tout fonctionne

**Objectif minimum** : 2 points par exercice de vos questions ratées