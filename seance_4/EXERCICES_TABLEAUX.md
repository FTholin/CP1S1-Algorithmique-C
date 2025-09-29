## 1) Budget de courses

**Objectif**
Lire `n` prix, calculer total, moyenne, et repérer l’article le plus cher (et son index).

**Plan de données**

* Un entier pour `n`.
* Un tableau de `double` pour les prix (taille max raisonnable définie à 100 par exemple).
* Trois variables de travail : `somme`, `max`, `indiceMax`.

**Étapes**

1. Demande `n`. Valide que `1 ≤ n ≤ capacité`.
2. Boucle de saisie : pour chaque `i`, demande un prix.

   * Option : refuse les prix négatifs, redemande.
3. Initialisation au premier élément (après la saisie du tableau) :

   * `somme` = premier prix.
   * `max` = premier prix.
   * `indiceMax` = 0.
     (Ça évite les valeurs  foireuses.)
4. Parcours du tableau à partir de l’index 1 :

   * Ajoute le prix à `somme`.
   * Si prix courant > `max`, mets à jour `max` et `indiceMax`.
5. Calcule `moyenne = somme / n`.
6. Affiche : `total`, `moyenne` (format 2 décimales), `indiceMax` et `max`.

**Cas limites à tester**

* Tous les prix identiques.
* Prix = 0 possible.
* `n = 1`.

**Bonus**

* Afficher aussi l’**indice du premier** élément ≥ moyenne.
* Arrondir l’affichage à 2 décimales (affichage, pas calcul).

**Jeux de tests**

1. `n=1`, prix = `[12.50]`
   → total = **12.50**, moyenne = **12.50**, `indiceMax` = **0**, `max` = **12.50**, **1er ≥ moyenne** = **0**

2. Tous identiques
   `n=5`, prix = `[3, 3, 3, 3, 3]`
   → total = **15.00**, moyenne = **3.00**, `indiceMax` = **0**, `max` = **3.00**, **1er ≥ moyenne** = **0**

3. Zéros possibles
   `n=4`, prix = `[0, 2.99, 0, 10]`
   → total = **12.99**, moyenne = **3.25**, `indiceMax` = **3**, `max` = **10.00**, **1er ≥ moyenne** = **3**

4. Cas « courant »
   `n=5`, prix = `[1.99, 5.49, 2.50, 12.30, 4.00]`
   → total = **26.28**, moyenne = **5.26**, `indiceMax` = **3**, `max` = **12.30**, **1er ≥ moyenne** = **1**

5. Max en dernière position
   `n=6`, prix = `[1, 1, 1, 1, 1, 100]`
   → total = **105.00**, moyenne = **17.50**, `indiceMax` = **5**, `max` = **100.00**, **1er ≥ moyenne** = **5**

## 2) Suivi de température sur 7 jours

**Objectif**
Min, max, amplitude (max − min), nombre de jours au-dessus de la moyenne.

**Plan de données**

* Tableau de 7 réels.
* `somme`, `min`, `max`, `auDessus` (compteur).

**Étapes**

1. Saisie des 7 valeurs (jour 1 à 7).
2. Initialise `min` et `max` avec la première valeur, `somme` idem.
3. Parcours de 1 à 6 :

   * Ajoute à `somme`.
   * Met à jour `min`/`max` si besoin.
4. `moyenne = somme / 7`.
5. Second parcours : si valeur > moyenne, incrémente `auDessus`.
6. Affiche `min`, `max`, `max - min`, `moyenne`, `auDessus`.



**Bonus**

* Afficher le premier jour du max .


**Jeux de tests**

Chaque ligne : `valeurs[7]` → `min`, `max`, `amplitude`, `moyenne`, `auDessus`, **1er jour du max**

1. `[-2, 0, 3, 5, 1, -1, 4]`
   → **-2**, **5**, **7**, **1.43**, **3**, **4**

2. `[10, 10, 10, 10, 10, 10, 10]`
   → **10**, **10**, **0**, **10.00**, **0**, **1**

3. `[5, 7, 7, 3, 7, 0, 2]`
   → **0**, **7**, **7**, **4.43**, **4**, **2**

4. `[1, 2, 3, 4, 5, 6, 7]`
   → **1**, **7**, **6**, **4.00**, **3**, **7**



## 3) Carnet de notes avec seuil d’admission

**Objectif**
Compter admis (≥10) et mentions (≥14), afficher meilleure note et son index.

**Plan de données**

* `n`, tableau d’entiers (0..20).
* `admis`, `mentions`, `meilleure`, `indiceMeilleure`.

**Étapes**

1. Lis `n`, valide (limite raisonnable).
2. Pour chaque note :

   * Tant que note pas dans [0;20], redemander.
   * Mets à jour `admis` si ≥10, `mentions` si ≥14.
   * Mets à jour meilleur/indice si stricte supériorité.
3. Affiche les trois résultats.

**Cas limites**

* `n=1`.
* Tout le monde ajourné.

**Bonus**

* Calculer aussi la moyenne générale (en réel).

**Jeux de tests**

* `n=1`, notes = `[9]`
  → admis = **0**, mentions = **0**, meilleure = **9**, `indice` = **0**, moyenne = **9.00**

* Tout le monde ajourné
  `n=4`, notes = `[3, 5, 0, 9]`
  → admis = **0**, mentions = **0**, meilleure = **9**, `indice` = **3**, moyenne = **4.25**

* Égalités sur le max (garde le **premier** car « stricte supériorité » pour maj)
  `n=5`, notes = `[14, 14, 20, 20, 13]`
  → admis = **5**, mentions = **4**, meilleure = **20**, `indice` = **2**, moyenne = **16.20**

* Tous 20
  `n=3`, notes = `[20, 20, 20]`
  → admis = **3**, mentions = **3**, meilleure = **20**, `indice` = **0**, moyenne = **20.00**

* Mélangé
  `n=8`, notes = `[0, 10, 13, 14, 19, 20, 7, 8]`
  → admis = **5**, mentions = **3**, meilleure = **20**, `indice` = **5**, moyenne = **11.38**



