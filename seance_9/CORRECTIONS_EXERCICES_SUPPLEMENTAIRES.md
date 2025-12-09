
```c
#include <stdio.h>
#include <math.h>  // Pour sqrt() et pow()

// ============================================================================
// EXERCICE 1 : Phases de la Lune
// ============================================================================

char obtenir_phase_lune(int jours) {
    // Étape 1 : Normaliser les jours dans un cycle de 30 jours
    int jour_normalise = jours % 30;
    
    // Gérer les nombres négatifs
    if (jour_normalise < 0) {
        jour_normalise = jour_normalise + 30;
    }
    
    // Étape 2 : Déterminer la phase selon le jour
    if (jour_normalise >= 0 && jour_normalise <= 5) {
        return 'N';  // Nouvelle lune
    }
    else if (jour_normalise >= 6 && jour_normalise <= 11) {
        return 'C';  // Premier croissant
    }
    else if (jour_normalise >= 12 && jour_normalise <= 16) {
        return 'Q';  // Premier quartier
    }
    else if (jour_normalise >= 17 && jour_normalise <= 21) {
        return 'G';  // Gibbeuse croissante
    }
    else {
        return 'P';  // Pleine lune (jours 22 à 29)
    }
}

// ============================================================================
// EXERCICE 2 : Système d'arrosage intelligent
// ============================================================================

int calculer_duree_arrosage(int temperature, int humidite_sol, char type_plante) {
    int duree;
    
    // Étape 1 : Déterminer la durée de base selon le type de plante
    if (type_plante == 'C') {
        duree = 20;  // Cactus : peu d'eau
    }
    else if (type_plante == 'F') {
        duree = 30;  // Fleurs : eau moyenne
    }
    else if (type_plante == 'L') {
        duree = 40;  // Légumes : beaucoup d'eau
    }
    else {
        duree = 30;  // Valeur par défaut
    }
    
    // Étape 2 : Ajuster selon la température
    if (temperature > 30) {
        duree = duree + 10;
    }
    else if (temperature < 15) {
        duree = duree - 10;
    }
    
    // Étape 3 : Ajuster selon l'humidité du sol
    if (humidite_sol > 70) {
        return 0;  // Pas d'arrosage
    }
    else if (humidite_sol > 40) {
        duree = duree / 2;
    }
    
    // Étape 4 : Vérifier que la durée n'est pas négative
    if (duree < 0) {
        duree = 0;
    }
    
    return duree;
}

// ============================================================================
// EXERCICE 3 : Calcul de matériaux construction
// ============================================================================

void calculer_materiaux(double longueur_m, double hauteur_m, 
                        int *briques, double *ciment_kg, double *sable_m3) {
    // Étape 1 : Calculer la surface du mur
    double surface = longueur_m * hauteur_m;
    
    // Étape 2 : Calculer le nombre de briques (60 par m²)
    *briques = (int)(surface * 60);
    
    // Étape 3 : Calculer la quantité de ciment (15 kg par m²)
    *ciment_kg = surface * 15.0;
    
    // Étape 4 : Calculer la quantité de sable (0.05 m³ par m²)
    *sable_m3 = surface * 0.05;
}

double calculer_cout_total(int briques, double ciment, double sable) {
    double prix_briques;
    double prix_ciment;
    double prix_sable;
    int nombre_sacs;
    
    // Étape 1 : Prix des briques (0.50€ par brique)
    prix_briques = briques * 0.50;
    
    // Étape 2 : Prix du ciment (sacs de 25kg à 8€)
    // On arrondit au sac supérieur (on ne peut pas acheter un demi-sac)
    nombre_sacs = (int)(ciment / 25.0);
    if (ciment > nombre_sacs * 25.0) {
        nombre_sacs = nombre_sacs + 1;
    }
    prix_ciment = nombre_sacs * 8.0;
    
    // Étape 3 : Prix du sable (50€ par m³)
    prix_sable = sable * 50.0;
    
    return prix_briques + prix_ciment + prix_sable;
}

// ============================================================================
// EXERCICE 4 : Convertisseur de recettes
// ============================================================================

void adapter_recette(int personnes_base, int personnes_voulues,
                     double *farine, double *sucre, int *oeufs, double *beurre) {
    // Étape 1 : Calculer le coefficient multiplicateur
    double ratio = (double)personnes_voulues / (double)personnes_base;
    
    // Étape 2 : Adapter les ingrédients en grammes
    *farine = *farine * ratio;
    *sucre = *sucre * ratio;
    *beurre = *beurre * ratio;
    
    // Étape 3 : Adapter les oeufs (arrondir au plus proche)
    double oeufs_calcules = (*oeufs) * ratio;
    *oeufs = (int)(oeufs_calcules + 0.5);
}

// ============================================================================
// EXERCICE 5 : Mélange de solutions chimiques
// ============================================================================

double calculer_concentration_finale(double volume1_ml, double concentration1_pct,
                                     double volume2_ml, double concentration2_pct) {
    // Étape 1 : Calculer la quantité de produit pur dans chaque solution
    double produit_pur1 = volume1_ml * concentration1_pct / 100.0;
    double produit_pur2 = volume2_ml * concentration2_pct / 100.0;
    
    // Étape 2 : Calculer les totaux après mélange
    double volume_total = volume1_ml + volume2_ml;
    double produit_pur_total = produit_pur1 + produit_pur2;
    
    // Étape 3 : Calculer la concentration du mélange
    double concentration_finale = (produit_pur_total / volume_total) * 100.0;
    
    return concentration_finale;
}

void calculer_dilution(double volume_initial_ml, double concentration_initiale_pct,
                       double concentration_voulue_pct, double *eau_a_ajouter_ml) {
    // Étape 1 : Calculer la quantité de produit pur présente
    double produit_pur = volume_initial_ml * concentration_initiale_pct / 100.0;
    
    // Étape 2 : Calculer le volume final nécessaire
    double volume_final = produit_pur * 100.0 / concentration_voulue_pct;
    
    // Étape 3 : Calculer l'eau à ajouter
    *eau_a_ajouter_ml = volume_final - volume_initial_ml;
}

// ============================================================================
// EXERCICE 6 : Migration des oiseaux
// ============================================================================

double calculer_distance_vol(double lat1, double lon1, double lat2, double lon2) {
    // Étape 1 : Calculer les différences de coordonnées
    double diff_lat = lat2 - lat1;
    double diff_lon = lon2 - lon1;
    
    // Étape 2 : Calculer la distance en degrés (Pythagore)
    double distance_degres = sqrt(diff_lat * diff_lat + diff_lon * diff_lon);
    
    // Étape 3 : Convertir en kilomètres (1 degré = 111 km)
    double distance_km = distance_degres * 111.0;
    
    return distance_km;
}

void planifier_migration(double distance_km, int vitesse_kmh, 
                         int heures_vol_par_jour, int *jours, int *heures) {
    // Étape 1 : Calculer le temps de vol total en heures
    double temps_total_heures = distance_km / vitesse_kmh;
    
    // Étape 2 : Convertir en jours de vol complets
    *jours = (int)(temps_total_heures / heures_vol_par_jour);
    
    // Étape 3 : Calculer les heures restantes
    double heures_utilisees = (*jours) * heures_vol_par_jour;
    double heures_restantes = temps_total_heures - heures_utilisees;
    *heures = (int)(heures_restantes + 0.5);
}

// ============================================================================
// EXERCICE 7 : Altitude et pression atmosphérique
// ============================================================================

double calculer_pression(int altitude_m) {
    // Pression au niveau de la mer
    double pression_mer = 1013.25;
    
    // Formule barométrique simplifiée :
    // P = P0 * (1 - altitude/44330)^5.255
    double ratio = 1.0 - (altitude_m / 44330.0);
    double pression = pression_mer * pow(ratio, 5.255);
    
    return pression;
}

int calculer_temps_cuisson_eau(int altitude_m) {
    // Temps de cuisson de base au niveau de la mer : 10 minutes
    int temps_base = 10;
    
    // Étape 1 : Obtenir la pression à cette altitude
    double pression = calculer_pression(altitude_m);
    
    // Étape 2 : Calculer le ratio de pression
    double ratio_pression = 1013.25 / pression;
    
    // Étape 3 : Ajuster le temps de cuisson
    double temps_ajuste = temps_base * ratio_pression;
    
    // Arrondir au nombre entier le plus proche
    int temps_final = (int)(temps_ajuste + 0.5);
    
    return temps_final;
}

// ============================================================================
// FONCTION MAIN - Tests de tous les exercices
// ============================================================================

int main() {
    printf("========================================\n");
    printf("EXERCICE 1 : Phases de la Lune\n");
    printf("========================================\n");
    printf("Jour 0 : %c\n", obtenir_phase_lune(0));
    printf("Jour 7 : %c\n", obtenir_phase_lune(7));
    printf("Jour 14 : %c\n", obtenir_phase_lune(14));
    printf("Jour 22 : %c\n", obtenir_phase_lune(22));
    
    printf("\n========================================\n");
    printf("EXERCICE 2 : Systeme d'arrosage\n");
    printf("========================================\n");
    printf("Legumes, 35C, 30%% humidite : %d min\n", 
           calculer_duree_arrosage(35, 30, 'L'));
    printf("Fleurs, 20C, 75%% humidite : %d min\n", 
           calculer_duree_arrosage(20, 75, 'F'));
    printf("Cactus, 12C, 45%% humidite : %d min\n", 
           calculer_duree_arrosage(12, 45, 'C'));
    
    printf("\n========================================\n");
    printf("EXERCICE 3 : Materiaux construction\n");
    printf("========================================\n");
    int briques;
    double ciment, sable;
    calculer_materiaux(5.0, 2.5, &briques, &ciment, &sable);
    printf("Mur de 5.0m x 2.5m\n");
    printf("Briques : %d\n", briques);
    printf("Ciment : %.1f kg\n", ciment);
    printf("Sable : %.2f m3\n", sable);
    printf("Cout total : %.2f euros\n", calculer_cout_total(briques, ciment, sable));
    
    printf("\n========================================\n");
    printf("EXERCICE 4 : Convertisseur de recettes\n");
    printf("========================================\n");
    double farine = 250.0, sucre = 150.0, beurre = 100.0;
    int oeufs = 3;
    printf("Recette base (6 personnes) :\n");
    printf("  Farine : %.0fg, Oeufs : %d\n", farine, oeufs);
    adapter_recette(6, 10, &farine, &sucre, &oeufs, &beurre);
    printf("Recette adaptee (10 personnes) :\n");
    printf("  Farine : %.0fg, Oeufs : %d\n", farine, oeufs);
    
    printf("\n========================================\n");
    printf("EXERCICE 5 : Melange solutions chimiques\n");
    printf("========================================\n");
    double conc = calculer_concentration_finale(100, 50, 200, 20);
    printf("100ml a 50%% + 200ml a 20%% = %.1f%%\n", conc);
    double eau;
    calculer_dilution(50, 80, 30, &eau);
    printf("Diluer 50ml a 80%% vers 30%% : ajouter %.1f ml\n", eau);
    
    printf("\n========================================\n");
    printf("EXERCICE 6 : Migration des oiseaux\n");
    printf("========================================\n");
    double dist = calculer_distance_vol(48.8, 2.3, 14.7, -17.4);
    printf("Distance Paris-Dakar : %.0f km\n", dist);
    int jours, heures;
    planifier_migration(dist, 50, 10, &jours, &heures);
    printf("A 50 km/h, 10h/jour : %d jours et %d heures\n", jours, heures);
    
    printf("\n========================================\n");
    printf("EXERCICE 7 : Altitude et pression\n");
    printf("========================================\n");
    int altitudes[] = {0, 1500, 3000};
    int i;
    for (i = 0; i < 3; i++) {
        double p = calculer_pression(altitudes[i]);
        int t = calculer_temps_cuisson_eau(altitudes[i]);
        printf("Altitude %dm : %.1f hPa, cuisson %d min\n", altitudes[i], p, t);
    }
    
    return 0;

}```
