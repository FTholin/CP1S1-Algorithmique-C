
## Activité : Somme et produit des nombres entiers

#### Objectif :
- Demander à l'utilisateur un nombre entier positif.
- Utiliser une boucle pour calculer la somme et le produit de tous les entiers de 1 jusqu'au nombre donné.
- Afficher les résultats.

#### Exigences :
1. L'utilisateur doit entrer un entier positif.
2. Si l'utilisateur entre un nombre négatif, le programme doit afficher un message d'erreur et demander de nouveau un nombre.
3. Utiliser des boucles pour calculer la somme et le produit.

#### Exemple de sortie attendue :
```
Entrez un nombre entier positif : 5
La somme des nombres de 1 à 5 est : 15
Le produit des nombres de 1 à 5 est : 120
```


## Parking à paliers

**Contexte.** Un parking facture 2€ l’heure pour les 3 premières heures, puis 1€ l’heure ensuite.
**Entrée.** Un entier `h` (heures, `h ≥ 0`).
**Sortie.** Une ligne `prix=<x>` (en euros).
**Règles.**

* `h ≤ 3` → `prix = 2*h`
* `h > 3` → `prix = 2*3 + 1*(h-3)`
  **Cas limites.** `h=0`, `h=3`, grand `h`.
  **Exemple.** `5` → `prix=7`.

---

## Portes ouvertes (compteur d’entrées/sorties)

**Contexte.** On compte les personnes dans une salle à partir d’ordres successifs: `1` (une personne entre), `-1` (une sort), `0` (fin).
**Entrées.** En boucle, un entier `x ∈ {-1, 0, 1}`.
**Sorties.** Après chaque `1` ou `-1`, afficher `compteur=<n>`. À la fin, `final=<n>`.
**Règles.** Ne jamais descendre sous 0 (si `compteur==0` et `x==-1` → ignorer et afficher `compteur=0`).
**Exemple.** `1 1 -1 -1 -1 0` →

```
compteur=1
compteur=2
compteur=1
compteur=0
compteur=0
final=0
```

---

##  Coupon fidélité (seuils & cumul)

**Contexte.** Un client cumule des points; à chaque achat, il entre `montant` (entier). `0` termine.
**Entrées.** En boucle: `montant ≥ 0`.
**Sorties.** Après chaque achat: `points=<p>` cumulé. À la fin: `bonus=<b>` où `b=1` si `p≥100`, sinon `0`.
**Barème points.**

* `<10€` → 0 pt
* `10..49` → +1 pt
* `50..99` → +5 pts
* `≥100` → +15 pts
  **Exemple.** `12 80 9 0` →

```
points=1
points=6
points=6
bonus=0
```

---

## Chrono cuisine (compte à rebours réglable)

**Contexte.** Chrono de `n` secondes qui affiche un message selon la zone.
**Entrée.** `n ≥ 0`.
**Sorties.** Pour chaque seconde `t` de `n` à `0` :

* `t>10` → `OK`
* `1..10` → `ATTENTION`
* `0` → `FIN` (et stop)
  Format: `t=<t> <ETAT>`.
  **Exemple.** `12` → commence à `t=12 OK` … `t=10 ATTENTION` … `t=0 FIN`.

---

## Bornes de recharge (files simples)

**Contexte.** Trois véhicules arrivent l’un après l’autre. Chacun indique la durée souhaitée (minutes, entier). Une borne ne peut servir que si le total ne dépasse pas `T` minutes.
**Entrées.** D’abord `T` (limite ≥ 0), puis trois durées `d1, d2, d3` (chacune lue séparément).
**Sorties.** Pour chaque `di`: `ACCEPTE` si `sum+di ≤ T` (et on ajoute), sinon `REFUSE`. En fin: `utilise=<sum>`.
**Exemple.** `T=60`, durées `25 30 20` →

```
ACCEPTE
ACCEPTE
REFUSE
utilise=55
```

---

##  Jeu “pile ou face” (compteur consécutif)

**Contexte.** Saisies successives de résultats codés: `1` pour pile, `2` pour face, `0` pour fin. On cherche la **plus longue série consécutive** de la même valeur.
**Entrées.** `1`, `2` ou `0` (fin).
**Sortie.** `max_serie=<k>`.
**Règles.** Réinitialiser le compteur courant dès que la valeur change; mettre à jour le maximum si besoin.
**Exemple.** `1 1 2 2 2 1 0` → `max_serie=3`.

---

##  Contrôle vitesse bus scolaire

**Contexte.** On lit des vitesses jusqu’à `-1`. Afficher des avertissements:

* `<=50` → `OK`
* `51..70` → `RAPPEL`
* `>70` → `ALERTE`
  **Entrées.** Vitesses entières; `-1` termine.
  **Sorties.** Une ligne par valeur, puis en fin: `ok=<a> rappel=<b> alerte=<c>`.
  **Exemple.** `40 55 80 51 -1` →

```
OK
RAPPEL
ALERTE
RAPPEL
ok=1 rappel=2 alerte=1
```

---

## Minuteur d’exam (pauses programmées)

**Contexte.** Un exam dure `D` minutes. Toutes les `P` minutes (strictement >0), on annonce `PAUSE COURTE`.
**Entrées.** `D ≥ 0`, puis `P > 0`.
**Sorties.** Pour `t` de `1` à `D`:

* Si `t % P == 0` → `PAUSE COURTE t=<t>`
* Sinon rien.
  En fin: `fin=D`.
  **Exemple.** `D=10, P=3` → lignes aux `t=3,6,9`, puis `fin=10`.

---

##  Contrôle d’âge cinéma (lots)

**Contexte.** On lit des âges; `0` termine la file.
**Règles.**

* `<10` → `REFUSE`
* `10..12` → `ACCOMPAGNE`
* `≥13` → `OK`
  **Entrées.** `age ≥ 0` ou `0` pour fin.
  **Sorties.** Un message par âge, puis `ok=<x> acc=<y> ref=<z>`.
  **Exemple.** `8 10 15 0` →

```
REFUSE
ACCOMPAGNE
OK
ok=1 acc=1 ref=1
```

---

##  Accès wifi (3 tentatives)

**Contexte.** Mot de passe numérique **fixé dans le code** (ex: `1234`). L’utilisateur peut tenter jusqu’à 3 fois.
**Entrées.** À chaque tentative: un entier (un seul à la fois).
**Sorties.**

* Si correct → `BIENVENUE` et fin.
* Sinon à la fin → `BLOQUE`.
  **Détail.** Après chaque tentative ratée (sauf la dernière), afficher `REESSAYEZ`.
  **Exemple.** `1111 2222 1234` →

```
REESSAYEZ
REESSAYEZ
BIENVENUE
```
