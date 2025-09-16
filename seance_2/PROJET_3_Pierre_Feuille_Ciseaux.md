# Pierre–Feuille–Ciseaux 


Le club info t’a demandé un **mini‑jeu en console** pour animer une pause. Le joueur affronte l’ordinateur à *Pierre–Feuille–Ciseaux*. Pour cette activité, on vise **une seule manche** afin de se concentrer sur les **conditionnelles** :


## Objectifs

* Lire un caractère saisi au clavier et l’interpréter correctement.
* **Normaliser** puis **valider** une entrée grâce aux **structures conditionnelles** (`if / else if / else`).
* Produire un **choix aléatoire** simple (ordinateur) et le traduire en coup du jeu.
* Mettre en œuvre la **logique du jeu** en comparant deux choix et en expliquant l’issue.

## Énoncé global pour les pros

Écrire un programme en C qui joue **une manche unique** de *Pierre–Feuille–Ciseaux* contre l’ordinateur :

1. Le programme demande un **seul** caractère : `P`, `F` ou `C` (minuscules acceptées).
2. L’entrée est **normalisée** (ex. `p` devient `P`).
3. L’entrée est **validée**. Si ce n’est pas `P`, `F` ou `C`, le programme affiche un message d’erreur et se termine.
4. L’ordinateur choisit **au hasard** `P`, `F` ou `C`.
5. Les deux choix sont affichés en toutes lettres : « pierre », « feuille » ou « ciseaux ».
6. Le programme **détermine le résultat** (égalité / victoire / défaite) **uniquement** avec des conditions, et affiche une courte justification (ex. « pierre casse ciseaux »).

> ⚠️ On n’utilise ici que des **structures conditionnelles**. 

---

## Étapes de conception

### Étape 1 — Accueil & saisie

* Afficher un titre et une consigne claire.
* Lire **un caractère** saisi par l’utilisateur.
* (Idée) Autoriser minuscules et majuscules pour le confort.

**Pseudo‑code**

```
afficher "Entrez votre coup [P/F/C] :"
lire caractere
```

### Étape 2 — Normalisation (min → maj)

* Si le caractère vaut `p`, le transformer en `P`. Idem pour `f/F` et `c/C`.
* Sinon, laisser tel quel.

**Pseudo‑code**

```
si caractere == 'p' alors caractere <- 'P'
sinon si caractere == 'f' alors caractere <- 'F'
sinon si caractere == 'c' alors caractere <- 'C'
```

### Étape 3 — Validation

* Vérifier que le caractère final est **exactement** `P` **ou** `F` **ou** `C`.
* En cas d’erreur : afficher un message explicite puis **terminer** le programme.

**Pseudo‑code**

```
si caractere != 'P' ET caractere != 'F' ET caractere != 'C' alors
    afficher "Entrée invalide : utilisez P, F ou C."
    terminer le programme
```

### Étape 4 — Choix **aléatoire** de l’ordinateur

Un ordinateur ne « devine » pas : il utilise un **générateur pseudo‑aléatoire**. La suite produite dépend d’une **graine** (*seed*). Pour obtenir un tirage qui varie à chaque exécution, on **initialise** la graine avec l’heure courante, puis on tire un nombre et on le **ramène** à l’intervalle `0..2` pour représenter `P/F/C`.

**En C (exemple minimal et réutilisable)**

```c
#include <stdlib.h>  // rand, srand
#include <time.h>    // time

/* 1) Initialiser la graine UNE SEULE FOIS au démarrage */
srand((unsigned) time(NULL));

/* 2) Tirer un entier puis le réduire à 0,1,2 */
int n = rand() % 3;   // 0, 1 ou 2

/* 3) Traduire 0/1/2 en 'P'/'F'/'C' par des if/else (sans switch, sans tableau) */
char bot;
if (n == 0) {
    bot = 'P';
} else if (n == 1) {
    bot = 'F';
} else {
    bot = 'C';
}
```

* `srand(time(NULL))` fixe la **graine** à l’instant courant : exécutions différentes ⇒ suites différentes.
* `rand()` fournit un entier pseudo‑aléatoire ; `rand() % 3` le **plafonne** à `0..2`.
* On **évite** d’appeler `srand` plusieurs fois (mêmes secondes ⇒ mêmes tirages).
* Le modulo peut introduire un biais théorique ; acceptable ici pour un mini‑jeu d’initiation.

### Étape 5 — Afficher les deux choix (en toutes lettres)

Afficher les deux choix (en toutes lettres)
Afficher les deux choix (en toutes lettres)

* Pour le **joueur** : convertir la lettre (`P`/`F`/`C`) en mot ("pierre"/"feuille"/"ciseaux").
* Pour le **bot** : faire la même conversion.
* Afficher sur une même ligne pour comparer facilement.

**Pseudo‑code**

```
texte_joueur <- (si 'P' → "pierre", si 'F' → "feuille", sinon → "ciseaux")
texte_bot    <- (si 'P' → "pierre", si 'F' → "feuille", sinon → "ciseaux")
afficher "Vous : ", texte_joueur, " | Bot : ", texte_bot
```

### Étape 6 — Déterminer le **résultat**

* **Égalité** : mêmes lettres → annoncer l’égalité.
* **Victoires joueur** : trois cas à tester.

  * `P` contre `C` → victoire ("pierre casse ciseaux").
  * `F` contre `P` → victoire ("feuille couvre pierre").
  * `C` contre `F` → victoire ("ciseaux coupent feuille").
* **Défaite** : tous les autres cas.

**Pseudo‑code**

```
si joueur == bot alors afficher "égalité"
sinon si joueur == 'P' ET bot == 'C' alors afficher "vous gagnez : pierre casse ciseaux"
sinon si joueur == 'F' ET bot == 'P' alors afficher "vous gagnez : feuille couvre pierre"
sinon si joueur == 'C' ET bot == 'F' alors afficher "vous gagnez : ciseaux coupent feuille"
sinon afficher "vous perdez"
```



## Scénario de test 

* **Entrée invalide** : saisir un symbole autre que `P/F/C` → le programme doit refuser poliment et s’arrêter.
* **Égalité** : saisir `p` (après normalisation, c’est `P`) ; vérifier que si l’ordinateur joue `P`, l’égalité est annoncée.
* **Victoire** : saisir `F` ; lorsque l’ordinateur joue `P`, le message de victoire est correct **et justifié**.
* **Défaite** : saisir `C` ; lorsque l’ordinateur joue `P`, la défaite est annoncée.

> Astuce d’auto‑contrôle : relire chaque condition et expliquer à voix haute « pourquoi cette condition produit ce message ». Si l’explication hésite, la condition mérite d’être revue.
