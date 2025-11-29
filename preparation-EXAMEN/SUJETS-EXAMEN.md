

# SUJET 1 : Optimisation de livraisons de pizzas

## Contexte

Tu travailles pour une pizzeria et tu dois optimiser les trajets de livraison. Les adresses sont représentées par des numéros de rue. Tu dois analyser les distances entre les livraisons consécutives.

## Données fournies

```c
int adresses[6] = {3, 12, 15, 7, 18, 20};
```

Ces nombres représentent les numéros de rue des 6 livraisons dans l'ordre.

## Fonctions à créer

### Fonction 1 : calculerDistance

**But :** Calculer la distance entre deux adresses (en valeur absolue).

**Signature :** `int calculerDistance(int depart, int arrivee)`

**Exemple :** La distance entre l'adresse 3 et l'adresse 12 est de 9.

---

### Fonction 2 : trouverPlusLongTrajet

**But :** Trouver la plus grande distance entre deux livraisons consécutives.

**Signature :** `int trouverPlusLongTrajet(int tab[], int taille)`

**Exemple :** Entre les adresses {3, 12, 15, 7, 18, 20}, les trajets sont :
- 3 → 12 = 9
- 12 → 15 = 3
- 15 → 7 = 8
- 7 → 18 = 11 ← le plus long
- 18 → 20 = 2

---

### Fonction 3 : compterTrajetsCourts

**But :** Compter combien de trajets sont inférieurs à un seuil donné.

**Signature :** `int compterTrajetsCourts(int tab[], int taille, int seuil)`

**Exemple :** Avec un seuil de 5, seuls les trajets de distance < 5 sont comptés (ici : 3 et 2, donc 2 trajets... mais attention, le seuil est 5 et on compte ceux strictement inférieurs).

---

## Main fourni

```c
int main() {
    int adresses[6] = {3, 12, 15, 7, 18, 20};
    
    int dist = calculerDistance(adresses[0], adresses[1]);
    printf("Distance entre livraison 0 et 1 : %d\n", dist);
    
    int plus_long = trouverPlusLongTrajet(adresses, 6);
    printf("Plus long trajet : %d\n", plus_long);
    
    int nb_courts = compterTrajetsCourts(adresses, 6, 5);
    printf("Nombre de trajets courts : %d\n", nb_courts);
    
    return 0;
}
```

## Résultats attendus

```
Distance entre livraison 0 et 1 : 9
Plus long trajet : 11
Nombre de trajets courts : 1
```



### Points clés à retenir

1. **abs()** permet d'obtenir la valeur absolue (toujours positive)
2. Pour parcourir des **paires consécutives**, la boucle va de 0 à `taille - 1`
3. On peut **réutiliser** une fonction déjà créée (calculerDistance)
4. Le **compteur** doit toujours être initialisé à 0

---

# SUJET 2 : Analyse d'évolution médicale

## Contexte

Tu travailles dans un cabinet médical et tu dois analyser l'évolution de la glycémie d'un patient sur 6 mesures. Une glycémie qui baisse est une amélioration (le patient va mieux).

## Données fournies

```c
int glycemie[6] = {140, 135, 138, 130, 128, 125};
```

Ces nombres représentent les mesures de glycémie (en mg/dL) prises à intervalles réguliers.

## Fonctions à créer

### Fonction 1 : determinerTendance

**But :** Comparer deux mesures et déterminer la tendance.

**Signature :** `char determinerTendance(int mesure_avant, int mesure_apres)`

**Retourne :**
- 'A' si amélioration (la mesure baisse)
- 'D' si détérioration (la mesure monte)
- 'S' si stable (même valeur)

---

### Fonction 2 : compterAmeliorations

**But :** Compter le nombre de fois où la glycémie a baissé entre deux mesures consécutives.

**Signature :** `int compterAmeliorations(int tab[], int taille)`

---

### Fonction 3 : calculerBaisseGlobale

**But :** Calculer la différence entre la première et la dernière mesure.

**Signature :** `int calculerBaisseGlobale(int tab[], int taille)`

---

## Main fourni

```c
int main() {
    int glycemie[6] = {140, 135, 138, 130, 128, 125};
    
    char tendance = determinerTendance(glycemie[0], glycemie[1]);
    printf("Tendance entre mesure 0 et 1 : %c\n", tendance);
    
    int ameliorations = compterAmeliorations(glycemie, 6);
    printf("Nombre d'ameliorations : %d\n", ameliorations);
    
    int baisse = calculerBaisseGlobale(glycemie, 6);
    printf("Baisse globale : %d mg/dL\n", baisse);
    
    return 0;
}
```

## Résultats attendus

```
Tendance entre mesure 0 et 1 : A
Nombre d'ameliorations : 4
Baisse globale : 15 mg/dL
```


### Points clés à retenir

1. Une fonction peut retourner un **caractère** (type `char`) avec des guillemets simples : `'A'`
2. Pour comparer des éléments **consécutifs**, on utilise `tab[i]` et `tab[i-1]`
3. Le **dernier élément** d'un tableau de taille N est à l'indice `N-1`
4. Structure **if / else if / else** pour gérer plusieurs cas

---

# SUJET 3 : Cycles de température dans une serre

## Contexte

Tu gères une serre agricole et tu enregistres la température toutes les 3 heures. Tu veux analyser les cycles de montée et descente de température pour optimiser l'arrosage.

## Données fournies

```c
float temperature[8] = {18.5, 21.2, 24.8, 22.3, 25.1, 27.5, 24.0, 21.5};
```

Ces nombres représentent 8 mesures de température en degrés Celsius.

## Fonctions à créer

### Fonction 1 : estMontee

**But :** Déterminer si la température monte entre deux mesures.

**Signature :** `int estMontee(float temp_avant, float temp_apres)`

**Retourne :** 1 si la température monte, 0 sinon.

---

### Fonction 2 : compterChangementsDirection

**But :** Compter le nombre de fois où la tendance change (de montée à descente ou inversement).

**Signature :** `int compterChangementsDirection(float tab[], int taille)`

---

### Fonction 3 : calculerVariationMax

**But :** Trouver la plus grande variation de température entre deux mesures consécutives.

**Signature :** `float calculerVariationMax(float tab[], int taille)`

---

## Main fourni

```c
int main() {
    float temperature[8] = {18.5, 21.2, 24.8, 22.3, 25.1, 27.5, 24.0, 21.5};
    
    int montee = estMontee(temperature[0], temperature[1]);
    printf("Montee entre mesure 0 et 1 : %s\n", montee ? "Oui" : "Non");
    
    int changements = compterChangementsDirection(temperature, 8);
    printf("Changements de direction : %d\n", changements);
    
    float var_max = calculerVariationMax(temperature, 8);
    printf("Variation maximale : %.1f°C\n", var_max);
    
    return 0;
}
```

## Résultats attendus

```
Montee entre mesure 0 et 1 : Oui
Changements de direction : 3
Variation maximale : 3.6°C
```



### Points clés à retenir

1. **fabs()** est la valeur absolue pour les `float` (contrairement à `abs()` pour les `int`)
2. On peut **stocker une tendance** (montée/descente) dans une variable pour la comparer ensuite
3. Pour détecter un **changement**, on compare la valeur actuelle avec la précédente
4. Les nombres à virgule utilisent le type **float**

---

# SUJET 4 : Analyse de densité du trafic routier

## Contexte

Tu analyses le trafic sur une route pendant 5 périodes de la journée. Tu comptes séparément les voitures et les motos pour calculer des statistiques.

## Données fournies

```c
int voitures[5] = {45, 52, 38, 67, 54};
int motos[5] = {15, 13, 19, 18, 10};
```

Chaque case représente une période (matin, mi-journée, après-midi, soir, nuit).

## Fonctions à créer

### Fonction 1 : calculerTotalPeriode

**But :** Calculer le total de véhicules (voitures + motos) pour une période donnée.

**Signature :** `int calculerTotalPeriode(int v, int m)`

---

### Fonction 2 : trouverPeriodePlusChargee

**But :** Trouver l'indice de la période avec le plus de véhicules au total.

**Signature :** `int trouverPeriodePlusChargee(int v[], int m[], int taille)`

---

### Fonction 3 : calculerPourcentageMotos

**But :** Calculer le pourcentage de motos par rapport au total de véhicules.

**Signature :** `float calculerPourcentageMotos(int total_v, int total_m)`

---

## Main fourni

```c
int main() {
    int voitures[5] = {45, 52, 38, 67, 54};
    int motos[5] = {15, 13, 19, 18, 10};
    
    int total = calculerTotalPeriode(voitures[0], motos[0]);
    printf("Total periode 0 : %d vehicules\n", total);
    
    int periode_max = trouverPeriodePlusChargee(voitures, motos, 5);
    printf("Periode la plus chargee : %d\n", periode_max);
    
    // Calcul des totaux pour le pourcentage
    int total_v = 0, total_m = 0;
    for (int i = 0; i < 5; i++) {
        total_v = total_v + voitures[i];
        total_m = total_m + motos[i];
    }
    float pct = calculerPourcentageMotos(total_v, total_m);
    printf("Pourcentage de motos : %.1f%%\n", pct);
    
    return 0;
}
```

## Résultats attendus

```
Total periode 0 : 60 vehicules
Periode la plus chargee : 3
Pourcentage de motos : 22.6%
```



### Points clés à retenir

1. Différence entre **retourner l'indice** et **retourner la valeur** du maximum
2. Pour un calcul avec des décimales, utiliser **100.0** au lieu de 100
3. On peut **passer deux tableaux** en paramètres d'une fonction
4. Réutiliser `calculerTotalPeriode` évite de répéter du code

---

# SUJET 5 : Allure de course progressive

## Contexte

Tu t'entraînes pour un 10 km et tu enregistres ton temps par kilomètre (en secondes). Tu veux vérifier si tu as réussi à maintenir une allure progressive (temps qui diminue ou reste stable).

## Données fournies

```c
int temps_km[6] = {330, 325, 320, 322, 318, 315};
```

Ces nombres représentent le temps en secondes pour chaque kilomètre.

## Fonctions à créer

### Fonction 1 : convertirEnMinutes

**But :** Convertir un temps en secondes vers un temps en minutes (arrondi).

**Signature :** `int convertirEnMinutes(int secondes)`

**Astuce :** Pour arrondir, on ajoute 30 secondes avant de diviser par 60.

---

### Fonction 2 : verifierProgression

**But :** Vérifier si tous les temps diminuent ou restent stables (jamais d'augmentation).

**Signature :** `int verifierProgression(int tab[], int taille)`

**Retourne :** 1 si progression constante, 0 sinon.

---

### Fonction 3 : calculerGainTotal

**But :** Calculer le gain de temps entre le premier et le dernier kilomètre.

**Signature :** `int calculerGainTotal(int tab[], int taille)`

---

## Main fourni

```c
int main() {
    int temps_km[6] = {330, 325, 320, 322, 318, 315};
    
    int minutes = convertirEnMinutes(temps_km[0]);
    printf("Premier km en minutes : %d min\n", minutes);
    
    int progression = verifierProgression(temps_km, 6);
    printf("Progression constante : %s\n", progression ? "Oui" : "Non");
    
    int gain = calculerGainTotal(temps_km, 6);
    printf("Gain total : %d secondes\n", gain);
    
    return 0;
}
```

## Résultats attendus

```
Premier km en minutes : 6 min
Progression constante : Non
Gain total : 15 secondes
```



### Points clés à retenir

1. **Arrondi** : ajouter la moitié du diviseur avant de diviser (astuce classique)
2. On peut **retourner immédiatement** dès qu'on trouve ce qu'on cherche
3. Le **return** dans une boucle **arrête** la fonction immédiatement
4. Vérifier une propriété "pour tous" = chercher un contre-exemple

---

# SUJET 6 : Catégorisation de dépenses

## Contexte

Tu gères ton budget et tu veux catégoriser tes dépenses de la semaine en trois catégories selon leur montant : Faible, Moyen, Élevé.

## Données fournies

```c
float depenses[7] = {8.50, 15.20, 22.80, 12.00, 25.40, 9.30, 18.50};
```

Ces nombres représentent tes 7 dépenses de la semaine en euros.

## Fonctions à créer

### Fonction 1 : categoriserDepense

**But :** Attribuer une catégorie à une dépense selon son montant.

**Signature :** `char categoriserDepense(float montant)`

**Retourne :**
- 'F' (Faible) si montant < 12€
- 'M' (Moyen) si montant entre 12€ et 20€ inclus
- 'E' (Élevé) si montant > 20€

---

### Fonction 2 : compterCategorie

**But :** Compter combien de dépenses appartiennent à une catégorie donnée.

**Signature :** `int compterCategorie(float tab[], int taille, char categorie)`

---

### Fonction 3 : calculerMoyenneCategorie

**But :** Calculer la moyenne des dépenses d'une catégorie donnée.

**Signature :** `float calculerMoyenneCategorie(float tab[], int taille, char categorie)`

---

## Main fourni

```c
int main() {
    float depenses[7] = {8.50, 15.20, 22.80, 12.00, 25.40, 9.30, 18.50};
    
    char cat = categoriserDepense(depenses[0]);
    printf("Categorie depense 0 : %c\n", cat);
    
    int nb_elevees = compterCategorie(depenses, 7, 'E');
    printf("Nombre de depenses elevees : %d\n", nb_elevees);
    
    float moy = calculerMoyenneCategorie(depenses, 7, 'M');
    printf("Moyenne des depenses moyennes : %.2f euros\n", moy);
    
    return 0;
}
```

## Résultats attendus

```
Categorie depense 0 : F
Nombre de depenses elevees : 2
Moyenne des depenses moyennes : 15.23 euros
```



### Points clés à retenir

1. On peut **passer un caractère** en paramètre et l'utiliser pour filtrer
2. **Réutiliser** `categoriserDepense` dans les autres fonctions évite les erreurs
3. Toujours **vérifier division par 0** avant de diviser !
4. Pour une **moyenne** : accumuler la somme ET compter le nombre d'éléments

