Parfait ! Voici l'examen complet avec cette approche :

---

## Exercice 1 : Phases de la Lune

Calculez la phase de la lune selon le nombre de jours depuis la nouvelle lune (cycle de 30 jours).

**Fonction à créer :**
```c
char obtenir_phase_lune(int jours);
// Retourne : 'N' (nouvelle), 'C' (croissant), 'Q' (quartier), 
//            'G' (gibbeuse), 'P' (pleine)
```

**Étapes :**
1. **Normaliser les jours dans le cycle**
   - Ramenez n'importe quel nombre de jours dans un cycle de 30 jours

    <details>
    <summary>💡 Indice</summary>
    <p>
    Utilisez l'opération modulo avec 30
    </p>
    </details>

2. **Diviser le cycle en phases**
   - Jours 0 à 5 : Nouvelle lune
   - Jours 6 à 11 : Premier croissant
   - Jours 12 à 16 : Premier quartier
   - Jours 17 à 21 : Gibbeuse croissante
   - Jours 22 à 29 : Pleine lune

3. **Structure conditionnelle**
   - Testez chaque tranche de jours et retournez le caractère correspondant

**Test :**
```c
int main() {
    printf("Jour 0 : %c\n", obtenir_phase_lune(0));   // N
    printf("Jour 7 : %c\n", obtenir_phase_lune(7));   // C
    printf("Jour 14 : %c\n", obtenir_phase_lune(14)); // Q
    printf("Jour 22 : %c\n", obtenir_phase_lune(22)); // P
    return 0;
}
```

---

## Exercice 2 : Système d'arrosage intelligent

Calculez la durée d'arrosage selon température, humidité du sol et type de plante.

**Fonction à créer :**
```c
int calculer_duree_arrosage(int temperature, int humidite_sol, char type_plante);
// type_plante : 'C' (cactus), 'F' (fleurs), 'L' (légumes)
// Retourne la durée en minutes
```

**Étapes :**
1. **Déterminer la durée de base selon le type de plante**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Cactus nécessite 20 minutes de base, Fleurs nécessitent 30 minutes, Légumes nécessitent 40 minutes
    </p>
    </details>

2. **Ajuster selon la température**
   - Si température supérieure à 30 degrés : ajouter 10 minutes
   - Si température inférieure à 15 degrés : retirer 10 minutes

3. **Ajuster selon l'humidité du sol**
   - Si humidité supérieure à 70% : retourner 0 (pas d'arrosage)
   - Si humidité supérieure à 40% : diviser la durée par 2

4. **Vérification finale**
   - Si la durée est négative, la ramener à 0
   - Retourner la durée calculée

**Test :**
```c
int main() {
    printf("Legumes, 35C, 30%% humidite : %d min\n", 
           calculer_duree_arrosage(35, 30, 'L'));  // 50
    printf("Fleurs, 20C, 75%% humidite : %d min\n", 
           calculer_duree_arrosage(20, 75, 'F'));  // 0
    printf("Cactus, 12C, 45%% humidite : %d min\n", 
           calculer_duree_arrosage(12, 45, 'C'));  // 5
    return 0;
}
```

---

## Exercice 3 : Calcul de matériaux construction

Calculez les quantités de matériaux pour construire un mur.

**Fonctions à créer :**
```c
void calculer_materiaux(double longueur_m, double hauteur_m, 
                       int *briques, double *ciment_kg, double *sable_m3);

double calculer_cout_total(int briques, double ciment, double sable);
```

**Étapes pour calculer_materiaux :**
1. **Calculer la surface du mur**
   - Multipliez la longueur par la hauteur pour obtenir la surface en mètres carrés

2. **Calculer le nombre de briques**
   - Comptez 60 briques par mètre carré

    <details>
    <summary>💡 Indice</summary>
    <p>
    Multipliez la surface par 60 et convertissez en entier, stockez le résultat via le pointeur briques
    </p>
    </details>

3. **Calculer la quantité de ciment**
   - Comptez 15 kilogrammes par mètre carré

    <details>
    <summary>💡 Indice</summary>
    <p>
    Multipliez la surface par 15, stockez le résultat via le pointeur ciment_kg
    </p>
    </details>

4. **Calculer la quantité de sable**
   - Comptez 0.05 mètre cube par mètre carré

    <details>
    <summary>💡 Indice</summary>
    <p>
    Multipliez la surface par 0.05, stockez le résultat via le pointeur sable_m3
    </p>
    </details>

**Étapes pour calculer_cout_total :**
1. **Calculer le prix des briques**
   - Prix unitaire : 0.50 euros par brique

2. **Calculer le prix du ciment**
   - Le ciment se vend en sacs de 25 kilogrammes à 8 euros le sac

    <details>
    <summary>💡 Indice</summary>
    <p>
    Divisez la quantité totale par 25 pour obtenir le nombre de sacs, multipliez par 8 pour obtenir le prix
    </p>
    </details>

3. **Calculer le prix du sable**
   - Prix : 50 euros par mètre cube

4. **Retourner le total**
   - Additionnez les trois prix et retournez la somme

**Test :**
```c
int main() {
    int briques;
    double ciment, sable;
    
    calculer_materiaux(5.0, 2.5, &briques, &ciment, &sable);
    
    printf("Mur de 5.0m x 2.5m\n");
    printf("Briques : %d\n", briques);
    printf("Ciment : %.1f kg\n", ciment);
    printf("Sable : %.2f m3\n", sable);
    printf("Cout total : %.2f euros\n", calculer_cout_total(briques, ciment, sable));
    return 0;
}
```
**Résultat attendu :** 750 briques, 187.5 kg, 0.62 m³, 466.00€

---

## Exercice 4 : Convertisseur de recettes

Adaptez les proportions d'une recette selon le nombre de personnes.

**Fonction à créer :**
```c
void adapter_recette(int personnes_base, int personnes_voulues,
                     double *farine, double *sucre, int *oeufs, double *beurre);
```

**Étapes :**
1. **Calculer le coefficient multiplicateur**
   - Divisez le nombre de personnes voulues par le nombre de personnes de base

<details>
<summary>💡 Indice</summary>
<p>
Convertissez en décimal pour obtenir un ratio précis
</p>
</details>

2. **Adapter les ingrédients en grammes**
   - Pour la farine : multipliez la quantité actuelle par le ratio calculé
   - Faites de même pour le sucre et le beurre
   - Modifiez les valeurs via les pointeurs

3. **Adapter les oeufs**
   - Multipliez le nombre d'oeufs par le ratio

    <details>
    <summary>💡 Indice</summary>
    <p>
    Arrondissez à l'entier le plus proche en ajoutant 0.5 avant de convertir en entier
    </p>
    </details>

**Test :**
```c
int main() {
    double farine = 250.0, sucre = 150.0, beurre = 100.0;
    int oeufs = 3;
    
    printf("Recette base (6 personnes) :\n");
    printf("  Farine : %.0fg, Oeufs : %d\n", farine, oeufs);
    
    adapter_recette(6, 10, &farine, &sucre, &oeufs, &beurre);
    
    printf("Recette adaptee (10 personnes) :\n");
    printf("  Farine : %.0fg, Oeufs : %d\n", farine, oeufs);
    return 0;
}
```
**Résultat attendu :** 250g / 3 oeufs puis 417g / 5 oeufs

---

## Exercice 5 : Mélange de solutions chimiques

Calculez la concentration finale après mélange de deux solutions.

**Fonctions à créer :**
```c
double calculer_concentration_finale(double volume1_ml, double concentration1_pct,
                                     double volume2_ml, double concentration2_pct);

void calculer_dilution(double volume_initial_ml, double concentration_initiale_pct,
                       double concentration_voulue_pct, double *eau_a_ajouter_ml);
```

**Étapes pour calculer_concentration_finale :**
1. **Calculer la quantité de produit pur dans chaque solution**
   - Pour la solution 1 : multipliez le volume par la concentration, puis divisez par 100
   - Pour la solution 2 : faites de même

    <details>
    <summary>💡 Indice</summary>
    <p>
    Ces valeurs représentent le volume de produit pur dans chaque solution
    </p>
    </details>

2. **Calculer les totaux après mélange**
   - Volume total : additionnez les deux volumes
   - Produit pur total : additionnez les deux quantités de produit pur

3. **Calculer la concentration du mélange**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Divisez le produit pur total par le volume total, multipliez par 100 pour obtenir un pourcentage
    </p>
    </details>

**Étapes pour calculer_dilution :**
1. **Calculer la quantité de produit pur présente**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Multipliez le volume initial par la concentration initiale, divisez par 100. Cette quantité reste constante lors de la dilution
    </p>
    </details>

2. **Calculer le volume final nécessaire**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Divisez la quantité de produit pur par la concentration voulue, multipliez par 100 pour corriger le pourcentage
    </p>
    </details>

3. **Calculer l'eau à ajouter**
   - Soustrayez le volume initial du volume final
   - Stockez le résultat via le pointeur

**Test :**
```c
int main() {
    double conc = calculer_concentration_finale(100, 50, 200, 20);
    printf("100ml a 50%% + 200ml a 20%% = %.1f%%\n", conc);
    
    double eau;
    calculer_dilution(50, 80, 30, &eau);
    printf("Diluer 50ml a 80%% vers 30%% : ajouter %.1f ml\n", eau);
    return 0;
}
```
**Résultat attendu :** 30.0%, 83.3 ml

---

## Exercice 6 : Migration des oiseaux

Calculez la distance et le temps de migration entre deux points géographiques.

**Fonctions à créer :**
```c
double calculer_distance_vol(double lat1, double lon1, double lat2, double lon2);

void planifier_migration(double distance_km, int vitesse_kmh, 
                        int heures_vol_par_jour, int *jours, int *heures);
```

**Étapes pour calculer_distance_vol :**
1. **Calculer les différences de coordonnées**
   - Soustrayez la latitude de départ de la latitude d'arrivée
   - Soustrayez la longitude de départ de la longitude d'arrivée

2. **Calculer la distance en degrés**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Élevez chaque différence au carré, additionnez les deux carrés, prenez la racine carrée du résultat
    </p>
    </details>

3. **Convertir en kilomètres**
   - Multipliez la distance en degrés par 111

    <details>
    <summary>💡 Indice</summary>
    <p>
    Un degré de latitude ou longitude correspond approximativement à 111 kilomètres
    </p>
    </details>

**Étapes pour planifier_migration :**
1. **Calculer le temps de vol total**
   - Divisez la distance par la vitesse pour obtenir le nombre d'heures total

2. **Convertir en jours de vol**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Divisez les heures totales par le nombre d'heures de vol par jour, gardez seulement la partie entière pour le nombre de jours
    </p>
    </details>

3. **Calculer les heures restantes**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Utilisez le modulo pour obtenir le reste d'heures après avoir retiré les jours complets, stockez les résultats via les pointeurs
    </p>
    </details>

**Test :**
```c
int main() {
    // Paris vers Dakar
    double dist = calculer_distance_vol(48.8, 2.3, 14.7, -17.4);
    printf("Distance Paris-Dakar : %.0f km\n", dist);
    
    int jours, heures;
    planifier_migration(dist, 50, 10, &jours, &heures);
    printf("A 50 km/h, 10h/jour : %d jours et %d heures\n", jours, heures);
    return 0;
}
```
**Résultat attendu :** 4073 km, 8 jours et 1 heures

---

## Exercice 7 : Altitude et pression atmosphérique

Calculez la pression atmosphérique et le temps de cuisson selon l'altitude.

**Fonctions à créer :**
```c
double calculer_pression(int altitude_m);

int calculer_temps_cuisson_eau(int altitude_m);
```

**Étapes pour calculer_pression :**
1. **Définir la pression au niveau de la mer**
   - Utilisez la valeur de référence de 1013.25 hectopascals

2. **Appliquer la formule barométrique**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Divisez l'altitude par 8000, prenez l'opposé de ce résultat, calculez l'exponentielle de cette valeur, multipliez par la pression au niveau de la mer
    </p>
    </details>

**Étapes pour calculer_temps_cuisson_eau :**
1. **Obtenir la pression à cette altitude**
   - Appelez la fonction de calcul de pression

2. **Calculer le ratio de pression**
   - Divisez la pression au niveau de la mer (1013.25) par la pression obtenue

    <details>
    <summary>💡 Indice</summary>
    <p>
    Ce ratio indique l'augmentation du temps de cuisson
    </p>
    </details>

3. **Ajuster le temps de cuisson**

    <details>
    <summary>💡 Indice</summary>
    <p>
    Multipliez 10 minutes (temps de base) par le ratio, convertissez le résultat en entier
    </p>
    </details>

**Test :**
```c
int main() {
    int altitudes[] = {0, 1500, 3000};
    
    for (int i = 0; i < 3; i++) {
        double p = calculer_pression(altitudes[i]);
        int t = calculer_temps_cuisson_eau(altitudes[i]);
        printf("Altitude %dm : %.1f hPa, cuisson %d min\n", 
               altitudes[i], p, t);
    }
    return 0;
}
```
**Résultat attendu :** 
- 0m : 1013.2 hPa, 10 min
- 1500m : 833.8 hPa, 12 min  
- 3000m : 686.0 hPa, 14 min