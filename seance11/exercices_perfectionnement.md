

## PARTIE 1 : Sujets de base


### Suivi de consommation d'eau

**Contexte**

Tu relèves ta consommation d'eau quotidienne (en litres) sur une semaine pour repérer les jours où tu consommes trop.

**Données fournies**

```c
int consommation[7] = {95, 120, 88, 150, 110, 135, 92};
```

Ces nombres représentent ta consommation quotidienne du lundi au dimanche.

**Fonctions à créer**

**Fonction 1 : estExcessive**

- But : Déterminer si une consommation dépasse un seuil donné.
- Signature : `int estExcessive(int litres, int seuil)`
- Retourne : 1 si la consommation dépasse le seuil, 0 sinon.

**Fonction 2 : compterJoursExcessifs**

- But : Compter le nombre de jours où la consommation dépasse le seuil.
- Signature : `int compterJoursExcessifs(int tab[], int taille, int seuil)`

**Fonction 3 : calculerMoyenne**

- But : Calculer la consommation moyenne sur la semaine.
- Signature : `float calculerMoyenne(int tab[], int taille)`

**Main fourni**

```c
int main() {
    int consommation[7] = {95, 120, 88, 150, 110, 135, 92};
    
    int excessif = estExcessive(consommation[3], 100);
    printf("Jour 3 excessif : %s\n", excessif ? "Oui" : "Non");
    
    int nb_excessifs = compterJoursExcessifs(consommation, 7, 100);
    printf("Jours excessifs : %d\n", nb_excessifs);
    
    float moyenne = calculerMoyenne(consommation, 7);
    printf("Moyenne : %.1f litres\n", moyenne);
    
    return 0;
}
```

**Résultats attendus**

```
Jour 3 excessif : Oui
Jours excessifs : 4
Moyenne : 112.9 litres
```

**Indications**

- **Fonction 1** : Une simple comparaison suffit. En C, une comparaison comme `a > b` retourne directement 1 (vrai) ou 0 (faux). Tu peux donc écrire `return litres > seuil;` directement.

- **Fonction 2** : Tu as besoin d'un compteur initialisé à 0 avant la boucle. Parcours le tableau avec une boucle `for` de 0 à `taille - 1`. Pour chaque élément, appelle la fonction `estExcessive` : si elle retourne 1, incrémente le compteur. Réutiliser une fonction existante rend le code plus lisible et évite les erreurs.

- **Fonction 3** : Deux étapes : d'abord calculer la somme de tous les éléments avec une boucle, puis diviser par le nombre d'éléments. Attention : pour obtenir un résultat décimal, tu dois convertir la somme en `float` avant la division avec `(float)somme / taille`, sinon C fera une division entière.



###  Gestion de stock de fruits

**Contexte**

Tu gères un petit commerce de fruits et tu dois surveiller ton stock pour savoir quand commander.

**Données fournies**

```c
int stock[5] = {25, 8, 42, 15, 3};
int seuil_alerte = 10;
```

Chaque case représente le nombre de kg en stock pour chaque fruit (pommes, bananes, oranges, poires, kiwis).

**Fonctions à créer**

**Fonction 1 : estEnAlerte**

- But : Déterminer si un stock est en dessous ou égal au seuil d'alerte.
- Signature : `int estEnAlerte(int quantite, int seuil)`
- Retourne : 1 si la quantité est inférieure ou égale au seuil, 0 sinon.

**Fonction 2 : compterAlertes**

- But : Compter combien de fruits sont en alerte.
- Signature : `int compterAlertes(int tab[], int taille, int seuil)`

**Fonction 3 : calculerStockTotal**

- But : Calculer la somme totale du stock.
- Signature : `int calculerStockTotal(int tab[], int taille)`

**Main fourni**

```c
int main() {
    int stock[5] = {25, 8, 42, 15, 3};
    int seuil_alerte = 10;
    
    int alerte = estEnAlerte(stock[1], seuil_alerte);
    printf("Bananes en alerte : %s\n", alerte ? "Oui" : "Non");
    
    int nb_alertes = compterAlertes(stock, 5, seuil_alerte);
    printf("Produits en alerte : %d\n", nb_alertes);
    
    int total = calculerStockTotal(stock, 5);
    printf("Stock total : %d kg\n", total);
    
    return 0;
}
```

**Résultats attendus**

```
Bananes en alerte : Oui
Produits en alerte : 2
Stock total : 93 kg
```

**Indications**

- **Fonction 1** : Attention à la différence entre `<` (strictement inférieur) et `<=` (inférieur ou égal). Ici, le seuil lui-même déclenche l'alerte, donc utilise `<=`.

- **Fonction 2** : Même structure que `compterJoursExcessifs` du sujet 7. Parcours le tableau, et pour chaque élément, utilise `estEnAlerte` pour savoir s'il faut incrémenter le compteur.

- **Fonction 3** : Algorithme d'accumulation classique. Initialise une variable `somme` à 0, puis ajoute chaque élément du tableau dans une boucle. Retourne `somme` à la fin.


### Sujet 11 : Relevé de températures corporelles

**Contexte**

Tu surveilles la température d'un patient matin et soir pendant 4 jours pour détecter une fièvre.

**Données fournies**

```c
float temperatures[8] = {36.8, 37.1, 37.4, 38.2, 38.5, 37.9, 37.3, 36.9};
```

Les mesures alternent : matin jour 1, soir jour 1, matin jour 2, soir jour 2, etc.

**Fonctions à créer**

**Fonction 1 : estFievre**

- But : Déterminer si une température indique de la fièvre (≥ 38.0°C).
- Signature : `int estFievre(float temp)`
- Retourne : 1 si fièvre, 0 sinon.

**Fonction 2 : compterEpisodesFievre**

- But : Compter le nombre de mesures avec fièvre.
- Signature : `int compterEpisodesFievre(float tab[], int taille)`

**Fonction 3 : trouverTemperatureMax**

- But : Trouver la température la plus élevée.
- Signature : `float trouverTemperatureMax(float tab[], int taille)`

**Main fourni**

```c
int main() {
    float temperatures[8] = {36.8, 37.1, 37.4, 38.2, 38.5, 37.9, 37.3, 36.9};
    
    int fievre = estFievre(temperatures[4]);
    printf("Mesure 4 avec fievre : %s\n", fievre ? "Oui" : "Non");
    
    int episodes = compterEpisodesFievre(temperatures, 8);
    printf("Episodes de fievre : %d\n", episodes);
    
    float temp_max = trouverTemperatureMax(temperatures, 8);
    printf("Temperature maximale : %.1f C\n", temp_max);
    
    return 0;
}
```

**Résultats attendus**

```
Mesure 4 avec fievre : Oui
Episodes de fievre : 2
Temperature maximale : 38.5 C
```

**Indications**

- **Fonction 1** : La comparaison fonctionne de la même façon avec les `float`. Utilise `>=` pour inclure exactement 38.0 dans les cas de fièvre.

- **Fonction 2** : Même structure que les fonctions de comptage précédentes. Réutilise `estFievre` pour tester chaque élément.

- **Fonction 3** : Recherche du maximum identique au sujet 8, mais avec un tableau de `float`. Le type de retour est `float`, et ta variable `max` doit aussi être de type `float`.

---



## PARTIE 2 : Sujets avancés


### Analyse de fréquentation d'une salle de sport

**Contexte**

Tu gères une salle de sport et tu enregistres le nombre d'entrées par heure sur une journée (de 8h à 21h, soit 14 créneaux). Tu veux analyser les pics de fréquentation et les tendances.

**Données fournies**

```c
int frequentation[14] = {12, 25, 38, 45, 32, 28, 15, 22, 48, 52, 41, 35, 28, 18};
```

Chaque case représente le nombre d'entrées sur un créneau d'une heure (indice 0 = 8h-9h, indice 1 = 9h-10h, etc.).

**Fonctions à créer**

**Fonction 1 : convertirIndiceEnHeure**

- But : Convertir un indice de tableau en heure réelle.
- Signature : `int convertirIndiceEnHeure(int indice)`
- Exemple : L'indice 0 correspond à 8h, l'indice 5 correspond à 13h.

**Fonction 2 : estCreneauPic**

- But : Déterminer si un créneau est un pic (plus fréquenté que ses deux voisins).
- Signature : `int estCreneauPic(int tab[], int taille, int indice)`
- Retourne : 1 si c'est un pic, 0 sinon.
- Attention : Le premier et le dernier créneau ne peuvent pas être des pics (ils n'ont qu'un seul voisin).

**Fonction 3 : compterPics**

- But : Compter le nombre de pics dans la journée.
- Signature : `int compterPics(int tab[], int taille)`

**Fonction 4 : trouverPlageCreuse**

- But : Trouver l'indice du début de la plage de 3 heures consécutives la moins fréquentée.
- Signature : `int trouverPlageCreuse(int tab[], int taille)`

**Fonction 5 : calculerMoyennePlage**

- But : Calculer la moyenne de fréquentation entre deux indices (inclus).
- Signature : `float calculerMoyennePlage(int tab[], int debut, int fin)`

**Main fourni**

```c
int main() {
    int frequentation[14] = {12, 25, 38, 45, 32, 28, 15, 22, 48, 52, 41, 35, 28, 18};
    
    int heure = convertirIndiceEnHeure(8);
    printf("Indice 8 correspond a : %dh\n", heure);
    
    int pic = estCreneauPic(frequentation, 14, 3);
    printf("Creneau 3 est un pic : %s\n", pic ? "Oui" : "Non");
    
    int nb_pics = compterPics(frequentation, 14);
    printf("Nombre de pics : %d\n", nb_pics);
    
    int debut_creux = trouverPlageCreuse(frequentation, 14);
    printf("Plage creuse commence a : %dh\n", convertirIndiceEnHeure(debut_creux));
    
    float moy_matin = calculerMoyennePlage(frequentation, 0, 5);
    printf("Moyenne matin (8h-13h) : %.1f entrees\n", moy_matin);
    
    return 0;
}
```

**Résultats attendus**

```
Indice 8 correspond a : 16h
Creneau 3 est un pic : Oui
Nombre de pics : 2
Plage creuse commence a : 13h
Moyenne matin (8h-13h) : 30.0 entrees
```

**Indications**

- **Fonction 1** : La relation est simple : si l'indice 0 correspond à 8h, alors l'heure = indice + 8.

- **Fonction 2** : D'abord, gère les cas particuliers : si `indice == 0` ou `indice == taille - 1`, retourne 0 immédiatement (pas de pic possible aux extrémités). Sinon, vérifie que `tab[indice]` est strictement supérieur à `tab[indice - 1]` ET à `tab[indice + 1]`. Utilise l'opérateur `&&` pour combiner les deux conditions.

- **Fonction 3** : Parcours tous les indices et utilise `estCreneauPic` pour chaque. Compte ceux qui retournent 1.

- **Fonction 4** : C'est une recherche de minimum sur une "fenêtre glissante" de 3 éléments. Calcule d'abord la somme des 3 premiers éléments (indices 0, 1, 2) et garde-la comme minimum. Ensuite, parcours les positions de 1 à `taille - 3` (pour que la fenêtre ne dépasse pas). À chaque position `i`, calcule la somme `tab[i] + tab[i+1] + tab[i+2]`. Si cette somme est plus petite que le minimum actuel, mets à jour le minimum et garde l'indice `i`. Retourne l'indice trouvé.

- **Fonction 5** : Calcule la somme des éléments entre les indices `debut` et `fin` inclus. Le nombre d'éléments est `fin - debut + 1`. Divise la somme par ce nombre (en castant en `float`).

---

###  Gestion de file d'attente

**Contexte**

Tu analyses les temps d'attente (en minutes) des clients dans une file. Tu veux détecter les anomalies et calculer des statistiques.

**Données fournies**

```c
int attente[10] = {3, 5, 4, 12, 6, 4, 8, 5, 15, 7};
```

Chaque valeur représente le temps d'attente d'un client dans l'ordre d'arrivée.

**Fonctions à créer**

**Fonction 1 : calculerMoyenne**

- But : Calculer le temps d'attente moyen.
- Signature : `float calculerMoyenne(int tab[], int taille)`

**Fonction 2 : estAnomalie**

- But : Déterminer si un temps d'attente est anormal (plus du double de la moyenne).
- Signature : `int estAnomalie(int temps, float moyenne)`
- Retourne : 1 si anomalie, 0 sinon.

**Fonction 3 : compterAnomalies**

- But : Compter le nombre de temps d'attente anormaux.
- Signature : `int compterAnomalies(int tab[], int taille)`
- Note : Cette fonction doit d'abord calculer la moyenne, puis compter les anomalies.

**Fonction 4 : calculerMoyenneSansAnomalies**

- But : Calculer la moyenne en excluant les valeurs anormales.
- Signature : `float calculerMoyenneSansAnomalies(int tab[], int taille)`

**Fonction 5 : trouverPlusLongueSequence**

- But : Trouver la plus longue séquence de clients consécutifs ayant attendu moins qu'un seuil donné.
- Signature : `int trouverPlusLongueSequence(int tab[], int taille, int seuil)`

**Main fourni**

```c
int main() {
    int attente[10] = {3, 5, 4, 12, 6, 4, 8, 5, 15, 7};
    
    float moy = calculerMoyenne(attente, 10);
    printf("Moyenne : %.1f min\n", moy);
    
    int anomalie = estAnomalie(attente[3], moy);
    printf("Client 3 est anomalie : %s\n", anomalie ? "Oui" : "Non");
    
    int nb_anomalies = compterAnomalies(attente, 10);
    printf("Nombre d'anomalies : %d\n", nb_anomalies);
    
    float moy_corrigee = calculerMoyenneSansAnomalies(attente, 10);
    printf("Moyenne corrigee : %.1f min\n", moy_corrigee);
    
    int sequence = trouverPlusLongueSequence(attente, 10, 6);
    printf("Plus longue sequence sous 6 min : %d clients\n", sequence);
    
    return 0;
}
```

**Résultats attendus**

```
Moyenne : 6.9 min
Client 3 est anomalie : Non
Nombre d'anomalies : 1
Moyenne corrigee : 6.0 min
Plus longue sequence sous 6 min : 3 clients
```

**Indications**

- **Fonction 1** : Somme des éléments divisée par la taille, avec cast en `float`.

- **Fonction 2** : Compare `temps` avec `2 * moyenne`. Attention : la moyenne est déjà un `float`, donc `2 * moyenne` sera aussi un `float`, pas besoin de cast supplémentaire.

- **Fonction 3** : Cette fonction illustre la réutilisation de fonctions. D'abord, appelle `calculerMoyenne` pour obtenir la moyenne. Ensuite, parcours le tableau et utilise `estAnomalie` pour chaque élément.

- **Fonction 4** : Similaire à `calculerMoyenne`, mais tu dois exclure les anomalies. Utilise deux variables : une pour la somme des valeurs normales, une pour compter combien de valeurs sont normales. D'abord calcule la moyenne globale, puis parcours le tableau : si `!estAnomalie(tab[i], moyenne)` (le `!` inverse le résultat), ajoute à la somme et incrémente le compteur. Divise à la fin. Attention à ne pas diviser par 0 si tous les éléments sont des anomalies.

- **Fonction 5** : Utilise deux variables : `sequence_courante` (longueur de la séquence en cours) et `sequence_max` (la plus longue trouvée). Parcours le tableau : si `tab[i] < seuil`, incrémente `sequence_courante` et mets à jour `sequence_max` si nécessaire. Sinon, la séquence est interrompue : remets `sequence_courante` à 0. Retourne `sequence_max` à la fin.

---

### Analyse de trajets en vélo

**Contexte**

Tu enregistres tes trajets en vélo sur une semaine : distance (km) et durée (minutes) pour chaque trajet.

**Données fournies**

```c
float distances[7] = {5.2, 8.5, 6.0, 12.3, 7.8, 15.0, 9.5};
int durees[7] = {18, 28, 22, 42, 25, 52, 32};
```

Chaque indice représente un jour de la semaine.

**Fonctions à créer**

**Fonction 1 : calculerVitesse**

- But : Calculer la vitesse moyenne d'un trajet (en km/h).
- Signature : `float calculerVitesse(float distance, int duree)`
- Formule : vitesse = distance / (durée en heures), donc distance / (durée / 60)

**Fonction 2 : trouverTrajetPlusRapide**

- But : Trouver l'indice du trajet avec la meilleure vitesse moyenne.
- Signature : `int trouverTrajetPlusRapide(float dist[], int dur[], int taille)`

**Fonction 3 : compterTrajetsPerformants**

- But : Compter les trajets où la vitesse dépasse un objectif.
- Signature : `int compterTrajetsPerformants(float dist[], int dur[], int taille, float objectif)`

**Fonction 4 : calculerDistanceTotale**

- But : Calculer la distance totale parcourue sur la semaine.
- Signature : `float calculerDistanceTotale(float tab[], int taille)`

**Fonction 5 : calculerVitesseMoyenneGlobale**

- But : Calculer la vitesse moyenne sur l'ensemble de la semaine.
- Signature : `float calculerVitesseMoyenneGlobale(float dist[], int dur[], int taille)`
- Attention : Ce n'est PAS la moyenne des vitesses, mais : distance totale / temps total.

**Main fourni**

```c
int main() {
    float distances[7] = {5.2, 8.5, 6.0, 12.3, 7.8, 15.0, 9.5};
    int durees[7] = {18, 28, 22, 42, 25, 52, 32};
    
    float vitesse = calculerVitesse(distances[0], durees[0]);
    printf("Vitesse jour 0 : %.1f km/h\n", vitesse);
    
    int rapide = trouverTrajetPlusRapide(distances, durees, 7);
    printf("Trajet le plus rapide : jour %d\n", rapide);
    
    int performants = compterTrajetsPerformants(distances, durees, 7, 18.0);
    printf("Trajets > 18 km/h : %d\n", performants);
    
    float total = calculerDistanceTotale(distances, 7);
    printf("Distance totale : %.1f km\n", total);
    
    float vit_glob = calculerVitesseMoyenneGlobale(distances, durees, 7);
    printf("Vitesse moyenne globale : %.1f km/h\n", vit_glob);
    
    return 0;
}
```

**Résultats attendus**

```
Vitesse jour 0 : 17.3 km/h
Trajet le plus rapide : jour 4
Trajets > 18 km/h : 2
Distance totale : 64.3 km
Vitesse moyenne globale : 17.6 km/h
```

**Indications**

- **Fonction 1** : La formule est `distance / (duree / 60.0)`. Attention : utilise `60.0` (un `float`) et non `60` (un `int`), sinon `duree / 60` sera une division entière et donnera 0 pour les durées inférieures à 60 minutes.

- **Fonction 2** : Recherche du maximum sur la vitesse, mais tu dois retourner l'indice. Utilise `calculerVitesse` pour comparer les trajets. Garde en mémoire l'indice du meilleur trajet et la vitesse correspondante.

- **Fonction 3** : Parcours les deux tableaux en parallèle avec le même indice `i`. Pour chaque trajet, calcule la vitesse avec `calculerVitesse(dist[i], dur[i])` et compare avec l'objectif.

- **Fonction 4** : Simple accumulation sur un tableau de `float`.

- **Fonction 5** : Piège classique ! La vitesse moyenne globale n'est pas la moyenne des vitesses. Tu dois calculer la somme de toutes les distances et la somme de toutes les durées, puis diviser. Utilise la même formule que `calculerVitesse` mais avec les totaux.

---

### Détection de tendances boursières

**Contexte**

Tu analyses le cours d'une action sur 10 jours pour détecter les tendances haussières et baissières.

**Données fournies**

```c
float cours[10] = {45.20, 46.10, 46.80, 45.90, 44.50, 44.20, 45.00, 46.30, 47.10, 47.80};
```

Chaque valeur représente le cours de clôture de l'action.

**Fonctions à créer**

**Fonction 1 : calculerVariation**

- But : Calculer la variation en pourcentage entre deux valeurs.
- Signature : `float calculerVariation(float avant, float apres)`
- Formule : ((après - avant) / avant) × 100

**Fonction 2 : estHausse**

- But : Déterminer si le cours monte entre deux jours.
- Signature : `int estHausse(float avant, float apres)`
- Retourne : 1 si hausse stricte, 0 sinon.

**Fonction 3 : trouverPlusLongueHausse**

- But : Trouver la longueur de la plus longue série de hausses consécutives.
- Signature : `int trouverPlusLongueHausse(float tab[], int taille)`

**Fonction 4 : calculerGainPeriode**

- But : Calculer le gain (ou perte) en pourcentage sur une période donnée.
- Signature : `float calculerGainPeriode(float tab[], int debut, int fin)`

**Fonction 5 : trouverMeilleurMomentAchat**

- But : Trouver l'indice du jour où il aurait fallu acheter pour maximiser le gain jusqu'à la fin.
- Signature : `int trouverMeilleurMomentAchat(float tab[], int taille)`

**Main fourni**

```c
int main() {
    float cours[10] = {45.20, 46.10, 46.80, 45.90, 44.50, 44.20, 45.00, 46.30, 47.10, 47.80};
    
    float var = calculerVariation(cours[0], cours[1]);
    printf("Variation jour 0-1 : %+.2f%%\n", var);
    
    int hausse = estHausse(cours[4], cours[5]);
    printf("Hausse entre jour 4 et 5 : %s\n", hausse ? "Oui" : "Non");
    
    int serie = trouverPlusLongueHausse(cours, 10);
    printf("Plus longue serie de hausses : %d jours\n", serie);
    
    float gain = calculerGainPeriode(cours, 5, 9);
    printf("Gain jours 5 a 9 : %+.2f%%\n", gain);
    
    int achat = trouverMeilleurMomentAchat(cours, 10);
    printf("Meilleur jour d'achat : %d\n", achat);
    
    return 0;
}
```

**Résultats attendus**

```
Variation jour 0-1 : +1.99%
Hausse entre jour 4 et 5 : Non
Plus longue serie de hausses : 4 jours
Gain jours 5 a 9 : +8.14%
Meilleur jour d'achat : 5
```

**Indications**

- **Fonction 1** : Applique directement la formule. Le résultat sera positif pour une hausse, négatif pour une baisse.

- **Fonction 2** : Simple comparaison : `apres > avant`.

- **Fonction 3** : Similaire à `trouverPlusLongueSequence` du sujet 15, mais tu compares des éléments consécutifs. Parcours de l'indice 1 à `taille - 1`. À chaque itération, vérifie si `tab[i] > tab[i-1]` (hausse). Si oui, incrémente la série courante. Si non, réinitialise à 0. Garde le maximum.

- **Fonction 4** : Réutilise `calculerVariation` avec `tab[debut]` et `tab[fin]`.

- **Fonction 5** : On suppose qu'on revend à la fin (jour `taille - 1`). Parcours tous les jours d'achat possibles (de 0 à `taille - 2`). Pour chaque jour `i`, calcule le gain potentiel : `tab[taille - 1] - tab[i]`. Garde l'indice qui donne le meilleur gain. C'est une recherche du maximum du gain, en retournant l'indice correspondant.

---

### Gestion d'énergie domestique

**Contexte**

Tu surveilles ta consommation électrique (en kWh) par tranche de 2 heures sur une journée (12 créneaux). Tu veux identifier les pics et optimiser ta consommation selon les tarifs heures creuses / heures pleines.

**Données fournies**

```c
float conso[12] = {0.8, 0.5, 0.3, 0.4, 1.2, 2.5, 2.8, 1.9, 1.5, 2.2, 1.8, 0.9};
float tarif_hc = 0.15;  // Heures creuses (€/kWh)
float tarif_hp = 0.22;  // Heures pleines (€/kWh)
```

Les créneaux 0-3 (0h-8h) et 10-11 (20h-24h) sont en heures creuses. Les créneaux 4-9 (8h-20h) sont en heures pleines.

**Fonctions à créer**

**Fonction 1 : estHeureCreuse**

- But : Déterminer si un créneau est en heures creuses.
- Signature : `int estHeureCreuse(int creneau)`
- Retourne : 1 si heures creuses (créneaux 0-3 ou 10-11), 0 sinon.

**Fonction 2 : calculerCoutCreneau**

- But : Calculer le coût d'un créneau selon son tarif.
- Signature : `float calculerCoutCreneau(float kwh, int creneau, float hc, float hp)`

**Fonction 3 : calculerCoutJournee**

- But : Calculer le coût total de la journée.
- Signature : `float calculerCoutJournee(float tab[], int taille, float hc, float hp)`

**Fonction 4 : trouverCreneauPic**

- But : Trouver l'indice du créneau avec la plus forte consommation.
- Signature : `int trouverCreneauPic(float tab[], int taille)`

**Fonction 5 : calculerEconomiesPotentielles**

- But : Calculer combien on économiserait si toute la consommation des heures pleines passait en heures creuses.
- Signature : `float calculerEconomiesPotentielles(float tab[], int taille, float hc, float hp)`

**Main fourni**

```c
int main() {
    float conso[12] = {0.8, 0.5, 0.3, 0.4, 1.2, 2.5, 2.8, 1.9, 1.5, 2.2, 1.8, 0.9};
    float tarif_hc = 0.15;
    float tarif_hp = 0.22;
    
    int hc = estHeureCreuse(2);
    printf("Creneau 2 en heures creuses : %s\n", hc ? "Oui" : "Non");
    
    float cout = calculerCoutCreneau(conso[6], 6, tarif_hc, tarif_hp);
    printf("Cout creneau 6 : %.2f euros\n", cout);
    
    float total = calculerCoutJournee(conso, 12, tarif_hc, tarif_hp);
    printf("Cout journee : %.2f euros\n", total);
    
    int pic = trouverCreneauPic(conso, 12);
    printf("Creneau pic : %d\n", pic);
    
    float eco = calculerEconomiesPotentielles(conso, 12, tarif_hc, tarif_hp);
    printf("Economies potentielles : %.2f euros\n", eco);
    
    return 0;
}
```

**Résultats attendus**

```
Creneau 2 en heures creuses : Oui
Cout creneau 6 : 0.62 euros
Cout journee : 3.37 euros
Creneau pic : 6
Economies potentielles : 0.85 euros
```

**Indications**

- **Fonction 1** : Utilise l'opérateur `||` (OU logique) pour combiner deux conditions : `(creneau <= 3) || (creneau >= 10)`.

- **Fonction 2** : Utilise `estHeureCreuse` pour déterminer le tarif applicable. Si heures creuses, retourne `kwh * hc`, sinon retourne `kwh * hp`.

- **Fonction 3** : Parcours le tableau et accumule le coût de chaque créneau en utilisant `calculerCoutCreneau`.

- **Fonction 4** : Recherche classique de l'indice du maximum dans un tableau de `float`.

- **Fonction 5** : L'économie, c'est la différence de coût entre le tarif HP et le tarif HC, multipliée par la consommation en heures pleines. Parcours le tableau : pour chaque créneau qui n'est PAS en heures creuses (`!estHeureCreuse(i)`), accumule la consommation. À la fin, multiplie cette consommation totale HP par `(hp - hc)` pour obtenir l'économie.