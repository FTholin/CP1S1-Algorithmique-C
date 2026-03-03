# La Gestion de la Mémoire en C

## Introduction

Jusqu'à présent, nous avons déclaré des variables et des tableaux dont la taille était connue à l'avance. Mais que se passe-t-il si vous ne savez pas combien de données votre programme devra gérer ? Imaginez un jeu multijoueur : vous ne pouvez pas prédire combien de joueurs vont se connecter !

En C, le programmeur a un **accès direct à la mémoire** de l'ordinateur. C'est un pouvoir immense, mais comme dirait un certain oncle : *avec un grand pouvoir vient une grande responsabilité*.

Sans une gestion correcte de la mémoire, vos programmes peuvent planter, se comporter de manière imprévisible, ou même devenir des passoires de sécurité.

```
┌─────────────────────────────────────────────┐
│           La mémoire en C                   │
├─────────────────────────────────────────────┤
│  🏗️  Statique    → Taille fixée à la       │
│                     compilation             │
│  🔄  Dynamique   → Taille ajustable        │
│                     pendant l'exécution     │
│  🗑️  Libération  → Rendre la mémoire       │
│                     quand on n'en a plus    │
│                     besoin                  │
└─────────────────────────────────────────────┘
```

### À vous de jouer ! 🤠

**Exercice 1.1** : Exécutez le code ci-dessous. Il illustre les différents types de données et leur taille en mémoire.

```c
#include <stdio.h>

int main(void) {
    char lettre = 'A';
    int num = 42;
    float prix = 3.99;
    double pi = 3.14159;

    printf("Taille d'un char   : %ld octet\n", sizeof(lettre));
    printf("Taille d'un int    : %ld octets\n", sizeof(num));
    printf("Taille d'un float  : %ld octets\n", sizeof(prix));
    printf("Taille d'un double : %ld octets\n", sizeof(pi));

    return 0;
}
```

**Exercice 1.2** : Réfléchissez : si un `int` occupe 4 octets, combien d'octets faut-il pour stocker un tableau de 100 entiers ? Et un tableau de 1 000 000 d'entiers ? Cela fait combien de mégaoctets ?

---

## Les zones de mémoire en C

Avant de manipuler la mémoire, il faut comprendre comment elle est organisée. En C, la mémoire est divisée en **quatre zones principales** :

```
┌──────────────────────────────┐  Adresses hautes
│         La Pile (Stack)      │  ← Variables locales,
│         ▼ grandit vers le bas│    paramètres de fonctions
├──────────────────────────────┤
│                              │
│       (espace libre)         │
│                              │
├──────────────────────────────┤
│         Le Tas (Heap)        │  ← Allocation dynamique
│         ▲ grandit vers le haut│   (malloc, calloc...)
├──────────────────────────────┤
│      Zone de données         │  ← Variables globales
│      (Data Segment)          │    et statiques
├──────────────────────────────┤
│      Zone de code            │  ← Instructions du
│      (Text Segment)          │    programme (lecture seule)
└──────────────────────────────┘  Adresses basses
```

**La pile** fonctionne comme une pile d'assiettes : la dernière posée est la première retirée. Quand vous appelez une fonction, ses variables locales sont empilées. Quand la fonction se termine, elles sont dépilées automatiquement.

**Le tas** est votre terrain de jeu pour l'allocation dynamique. Contrairement à la pile, c'est **vous** qui décidez quand allouer et quand libérer. C'est là que `malloc()`, `calloc()` et `realloc()` travaillent.

**La zone de données** stocke les variables globales et statiques, qui vivent pendant toute la durée du programme.

**La zone de code** contient les instructions de votre programme. Elle est en lecture seule.

---

## Allocation statique de mémoire

### Définition

L'allocation statique, c'est quand la taille de la mémoire est **déterminée à la compilation** et ne peut plus changer. C'est ce que vous avez fait depuis le début du cours !

```c
int tableau[5];          // 5 entiers, ni plus, ni moins
char pseudo[25];         // 25 caractères, toujours
static int compteur = 0; // Variable statique
```

C'est comme construire les murs d'une maison : une fois posés, vous ne pouvez plus changer les dimensions sans tout casser et reconstruire.

**Avantages** : simple, rapide, pas de risque de fuite de mémoire.

**Inconvénients** : la taille doit être connue à l'avance et ne peut pas changer.

```c
#include <stdio.h>

int main(void) {
    static int tableau[5];  // Allocation statique, initialisé à 0

    for (int i = 0; i < 5; i++) {
        tableau[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("tableau[%d] = %d\n", i, tableau[i]);
    }

    return 0;
}
```

### À vous de jouer ! 🤠

**Exercice 2.1** : Créez un programme qui calcule la **moyenne de 10 notes** d'étudiants en utilisant l'allocation statique.

1. Déclarez un tableau statique de 10 entiers
2. Demandez à l'utilisateur de saisir les 10 notes avec une boucle `for`
3. Calculez la somme des notes
4. Calculez et affichez la moyenne

> 💡 **Indice** : N'oubliez pas de convertir en `float` pour avoir une moyenne décimale : `float moyenne = (float)somme / 10;`
>
> ✅ **Exemple de sortie** :
> ```
> Entrez la note 1 : 15
> Entrez la note 2 : 12
> ...
> La moyenne est : 13.5
> ```

---

## Allocation dynamique avec malloc()

### Le problème

Imaginez que vous créez une application de playlist musicale. L'utilisateur peut avoir 3 chansons ou 3 000. Avec l'allocation statique, vous devriez écrire :

```c
// ❌ On gaspille de la mémoire si l'utilisateur a peu de chansons
// ❌ On manque de place s'il en a plus de 1000
char chansons[1000][50];
```

C'est là que l'allocation **dynamique** entre en jeu !

### malloc() : réserver de la mémoire à la demande

La fonction `malloc()` (Memory ALLOCation) **alloue un bloc de mémoire** de la taille demandée et **retourne un pointeur** vers le début de ce bloc.

```
malloc(taille_en_octets)
   │
   ▼
┌──────────────────────────────────────┐
│  Cherche un espace libre dans le tas │
├──────────────────────────────────────┤
│  Espace trouvé ?                     │
│    OUI → retourne un pointeur        │
│    NON → retourne NULL               │
└──────────────────────────────────────┘
```

### Syntaxe

```c
#include <stdlib.h>  // Nécessaire pour malloc() et free()

void* malloc(size_t size);
```

`malloc()` retourne un pointeur **générique** (`void*`). On le convertit (cast) vers le type souhaité.

### Exemple pas à pas

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* ptr;

    // 1. Allouer de la mémoire pour UN entier
    ptr = (int*) malloc(sizeof(int));

    // 2. TOUJOURS vérifier si l'allocation a réussi
    if (ptr == NULL) {
        printf("Echec de l'allocation !\n");
        return 1;
    }

    // 3. Utiliser la mémoire allouée
    *ptr = 42;
    printf("Valeur : %d\n", *ptr);

    // 4. Libérer la mémoire quand on n'en a plus besoin
    free(ptr);

    return 0;
}
```

### Décortiquons la ligne clé ⭐

```c
ptr = (int*) malloc(sizeof(int));
```

| Partie | Rôle |
|--------|------|
| `sizeof(int)` | Calcule la taille d'un `int` (généralement 4 octets) |
| `malloc(sizeof(int))` | Réserve 4 octets dans le tas |
| `(int*)` | Convertit le `void*` retourné en `int*` |
| `ptr = ...` | Stocke l'adresse du bloc alloué dans notre pointeur |

```
AVANT malloc :                    APRÈS malloc :
                                  
ptr → ???                         ptr → ┌──────┐
                                        │  ??  │ (4 octets réservés)
                                        └──────┘
                                        
                                  APRÈS *ptr = 42 :
                                  
                                  ptr → ┌──────┐
                                        │  42  │
                                        └──────┘
```

### Allouer un tableau dynamique

La vraie puissance de `malloc()` apparaît quand on alloue un **tableau dont la taille est déterminée à l'exécution** :

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Combien d'entiers ? ");
    scanf("%d", &n);

    // Allouer un tableau de n entiers
    int* tableau = (int*) malloc(n * sizeof(int));

    if (tableau == NULL) {
        printf("Echec de l'allocation !\n");
        return 1;
    }

    // Remplir le tableau
    for (int i = 0; i < n; i++) {
        printf("Entrez l'entier %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }

    // Afficher le tableau
    printf("Vous avez saisi : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Ne pas oublier de libérer !
    free(tableau);

    return 0;
}
```

**Important** : On utilise `n * sizeof(int)` pour allouer `n` fois la taille d'un entier. C'est comme réserver `n` chambres d'hôtel d'un coup !

### Les 4 étapes à TOUJOURS respecter ⭐

```
┌────────────────────────────────────────────────────┐
│  1️⃣  ALLOUER    →  ptr = (type*) malloc(taille);   │
│  2️⃣  VÉRIFIER   →  if (ptr == NULL) { erreur; }   │
│  3️⃣  UTILISER   →  *ptr = valeur; / ptr[i] = ...  │
│  4️⃣  LIBÉRER    →  free(ptr);                      │
└────────────────────────────────────────────────────┘
```

Oublier une seule de ces étapes, c'est s'attirer des ennuis !

### À vous de jouer ! 🤠

**Exercice 3.1** : Créez un programme qui calcule la **somme de n entiers** en utilisant `malloc()`.

1. Incluez `stdio.h` et `stdlib.h`
2. Demandez à l'utilisateur combien d'entiers il veut additionner (`n`)
3. Allouez dynamiquement un tableau de `n` entiers avec `malloc()`
4. Vérifiez que l'allocation a réussi
5. Demandez à l'utilisateur de saisir les `n` entiers
6. Calculez et affichez la somme
7. Libérez la mémoire avec `free()`

> 💡 **Indice** : La taille à allouer est `n * sizeof(int)`. N'oubliez pas le cast `(int*)` !
>
> ✅ **Exemple de sortie** :
> ```
> Combien d'entiers ? 3
> Entrez l'entier 1 : 10
> Entrez l'entier 2 : 20
> Entrez l'entier 3 : 30
> La somme est : 60
> ```

---

## Allocation dynamique avec calloc()

### La différence avec malloc()

`calloc()` fait la même chose que `malloc()`, mais avec **deux différences** :

1. Elle prend **deux arguments** au lieu d'un (nombre d'éléments + taille de chaque élément)
2. Elle **initialise la mémoire à zéro** (alors que `malloc()` laisse des valeurs aléatoires)

```
malloc(5 * sizeof(int))          calloc(5, sizeof(int))
         │                                │
         ▼                                ▼
┌───┬───┬───┬───┬───┐          ┌───┬───┬───┬───┬───┐
│ ? │ ? │ ? │ ? │ ? │          │ 0 │ 0 │ 0 │ 0 │ 0 │
└───┴───┴───┴───┴───┘          └───┴───┴───┴───┴───┘
  Valeurs aléatoires !            Tout est à zéro ✓
```

### Syntaxe

```c
void* calloc(size_t count, size_t size);
```

| Paramètre | Rôle |
|-----------|------|
| `count` | Nombre d'éléments à allouer |
| `size` | Taille en octets de chaque élément |

### Exemple comparatif

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Avec malloc : valeurs imprévisibles
    int* tab_malloc = (int*) malloc(5 * sizeof(int));

    // Avec calloc : tout est à 0
    int* tab_calloc = (int*) calloc(5, sizeof(int));

    if (tab_malloc == NULL || tab_calloc == NULL) {
        printf("Echec de l'allocation !\n");
        return 1;
    }

    printf("malloc (non initialisé) : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", tab_malloc[i]);  // Valeurs aléatoires !
    }

    printf("\ncalloc (initialisé à 0) : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", tab_calloc[i]);  // Toujours 0
    }
    printf("\n");

    free(tab_malloc);
    free(tab_calloc);

    return 0;
}
```

### Quand utiliser calloc() plutôt que malloc() ?

| Situation | Choix recommandé |
|-----------|-----------------|
| Vous allez remplir immédiatement les données | `malloc()` (plus rapide) |
| Vous avez besoin que tout soit à zéro | `calloc()` |
| Vous allouez un tableau de compteurs | `calloc()` (compteurs à 0) |
| Vous n'êtes pas sûr | `calloc()` (plus sûr) |

### À vous de jouer ! 🤠

**Exercice 4.1** : Créez un programme de **calcul du coût total d'achats** avec `calloc()`.

1. Demandez à l'utilisateur combien d'articles il a achetés
2. Allouez dynamiquement un tableau de `double` avec `calloc()` pour stocker les prix
3. Vérifiez l'allocation
4. Demandez le prix de chaque article
5. Calculez et affichez le coût total
6. Libérez la mémoire

> 💡 **Indice** : `double* couts = (double*) calloc(nombre_articles, sizeof(double));`
>
> ✅ **Exemple de sortie** :
> ```
> Combien d'articles ? 3
> Prix de l'article 1 : 9.99
> Prix de l'article 2 : 24.50
> Prix de l'article 3 : 5.00
> Coût total : 39.49 euros
> ```

---

## Libération de mémoire avec free()

### Pourquoi libérer la mémoire ?

Quand vous allouez de la mémoire avec `malloc()` ou `calloc()`, cette mémoire reste **réservée** jusqu'à ce que vous la libériez explicitement. Si vous oubliez, c'est une **fuite de mémoire** !

Pensez-y comme un tableau blanc partagé : si vous écrivez dessus et que vous ne l'effacez jamais, il n'y aura bientôt plus de place pour personne.

### Syntaxe

```c
void free(void* ptr);
```

La fonction `free()` prend un pointeur vers un bloc de mémoire **précédemment alloué** par `malloc()`, `calloc()` ou `realloc()`, et le libère.

### Exemple

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int taille_nom;

    printf("Longueur de votre nom : ");
    scanf("%d", &taille_nom);

    // Allouer
    char* nom = (char*) malloc((taille_nom + 1) * sizeof(char));

    if (nom == NULL) {
        printf("Echec de l'allocation !\n");
        return 1;
    }

    // Utiliser
    printf("Votre nom : ");
    scanf("%s", nom);
    printf("Bonjour, %s !\n", nom);

    // Libérer
    free(nom);

    return 0;
}
```

**Note** : On alloue `taille_nom + 1` pour le caractère de fin de chaîne `'\0'`.

### ⚠️ Règles d'or de free()

```
┌─────────────────────────────────────────────────────────────┐
│  ✅  Toujours libérer la mémoire allouée dynamiquement     │
│  ✅  Libérer APRÈS avoir fini d'utiliser les données        │
│  ❌  Ne JAMAIS utiliser un pointeur après l'avoir libéré    │
│  ❌  Ne JAMAIS appeler free() deux fois sur le même bloc    │
│  ❌  Ne JAMAIS appeler free() sur une variable non allouée  │
│      dynamiquement                                          │
└─────────────────────────────────────────────────────────────┘
```

### À vous de jouer ! 🤠

**Exercice 5.1** : Créez un programme qui trouve le **plus grand** et le **plus petit** nombre parmi `n` entiers saisis par l'utilisateur.

1. Demandez combien d'entiers l'utilisateur veut entrer
2. Allouez dynamiquement un tableau avec `malloc()`
3. Vérifiez l'allocation
4. Demandez les entiers et stockez-les
5. Initialisez `max` et `min` avec la première valeur du tableau
6. Parcourez le tableau pour trouver le max et le min
7. Affichez les résultats
8. Libérez la mémoire

> 💡 **Indice** : Commencez la boucle de recherche à l'indice 1 (puisque `max` et `min` sont déjà initialisés avec `tableau[0]`).
>
> ✅ **Exemple de sortie** :
> ```
> Combien d'entiers ? 5
> Entier 1 : 42
> Entier 2 : 7
> Entier 3 : 99
> Entier 4 : 3
> Entier 5 : 56
> Le plus grand : 99
> Le plus petit : 3
> ```

---

## Réallocation de mémoire avec realloc()

### Le problème

Vous avez alloué de la mémoire pour 10 éléments, mais l'utilisateur en veut 20. Faut-il tout jeter et recommencer ? Non ! C'est là que `realloc()` entre en jeu.

C'est comme agrandir une table de banquet : au lieu de remplacer la table, on ajoute une rallonge en gardant les couverts déjà posés.

### Syntaxe

```c
void* realloc(void* ptr, size_t new_size);
```

| Paramètre | Rôle |
|-----------|------|
| `ptr` | Pointeur vers le bloc de mémoire existant |
| `new_size` | Nouvelle taille souhaitée en octets |

### Comportement de realloc()

```
realloc(ptr, nouvelle_taille)
   │
   ├─ Si possible : agrandit le bloc existant sur place
   │                → retourne le même pointeur
   │
   ├─ Sinon : alloue un nouveau bloc plus grand,
   │          copie les données, libère l'ancien
   │          → retourne un NOUVEAU pointeur
   │
   └─ Si échec : retourne NULL
                  ⚠️ L'ancien bloc reste intact !
```

### Exemple : tableau redimensionnable

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int* tableau;

    // Allocation initiale
    printf("Taille initiale du tableau : ");
    scanf("%d", &n);

    tableau = (int*) malloc(n * sizeof(int));
    if (tableau == NULL) {
        printf("Echec de l'allocation !\n");
        return 1;
    }

    // Remplir le tableau initial
    for (int i = 0; i < n; i++) {
        tableau[i] = i * 2;
    }

    printf("Tableau initial : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    // Réallocation
    int ancienne_taille = n;
    printf("Nouvelle taille souhaitée : ");
    scanf("%d", &n);

    int* nouveau = (int*) realloc(tableau, n * sizeof(int));
    if (nouveau == NULL) {
        printf("Echec de la réallocation !\n");
        free(tableau);  // Libérer l'ancien bloc
        return 1;
    }
    tableau = nouveau;

    // Initialiser les nouveaux éléments (si agrandissement)
    for (int i = ancienne_taille; i < n; i++) {
        tableau[i] = i * 2;
    }

    printf("Tableau redimensionné : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    free(tableau);
    return 0;
}
```

### ⚠️ Le piège classique de realloc()

```c
// ❌ DANGEREUX : si realloc échoue, on perd l'ancien pointeur !
tableau = (int*) realloc(tableau, nouvelle_taille);
// Si realloc retourne NULL, 'tableau' vaut NULL
// et l'ancien bloc est perdu → fuite de mémoire !

// ✅ CORRECT : utiliser un pointeur temporaire
int* nouveau = (int*) realloc(tableau, nouvelle_taille);
if (nouveau == NULL) {
    printf("Echec !\n");
    free(tableau);   // L'ancien bloc est encore accessible
    return 1;
}
tableau = nouveau;   // Mise à jour seulement si ça a marché
```

### À vous de jouer ! 🤠

**Exercice 6.1** : Créez un programme avec un **tableau redimensionnable** où l'utilisateur entre des entiers un par un. Le programme s'arrête quand l'utilisateur entre **-1**.

1. Initialisez `nombre_elements` à 0 et `tableau` à `NULL`
2. Dans une boucle `while` :
   - Demandez un entier à l'utilisateur
   - Si c'est -1, sortez de la boucle (`break`)
   - Utilisez `realloc()` pour agrandir le tableau d'une case
   - Vérifiez que la réallocation a réussi
   - Stockez l'entier dans le tableau
   - Incrémentez `nombre_elements`
3. Affichez tous les entiers saisis
4. Libérez la mémoire

> 💡 **Indices** :
> - `realloc(tableau, (nombre_elements + 1) * sizeof(int))` pour agrandir d'une case
> - `realloc(NULL, taille)` se comporte comme `malloc(taille)`, donc le premier appel fonctionnera même si `tableau` est `NULL`
> - Stockez le résultat de `realloc` dans un pointeur temporaire avant de mettre à jour `tableau`
>
> ✅ **Exemple de sortie** :
> ```
> Entrez un entier (-1 pour arrêter) : 10
> Entrez un entier (-1 pour arrêter) : 20
> Entrez un entier (-1 pour arrêter) : 30
> Entrez un entier (-1 pour arrêter) : -1
> Vous avez saisi : 10 20 30
> ```

---

## Erreurs courantes dans la gestion de la mémoire

Voici les trois erreurs les plus fréquentes. Apprenez à les reconnaître, car elles sont sournoises : le programme peut sembler fonctionner... jusqu'au jour où il plante en production !

### Erreur 1 : Fuite de mémoire (Memory Leak)

Une fuite de mémoire se produit quand on alloue de la mémoire **sans jamais la libérer**.

```c
// ❌ FUITE DE MÉMOIRE
void fonction_qui_fuit(void) {
    int* ptr = (int*) malloc(10 * sizeof(int));
    // On utilise ptr...
    // Mais on ne fait JAMAIS free(ptr) !
}   // ptr disparaît, mais le bloc mémoire reste alloué !

int main(void) {
    for (int i = 0; i < 1000; i++) {
        fonction_qui_fuit();  // 1000 × 40 octets perdus !
    }
    return 0;
}
```

```
Appel 1 : ████░░░░░░░░░░░░░░░░  Mémoire utilisée
Appel 100: ████████████░░░░░░░░
Appel 500: ████████████████████
Appel 999: 💥 PLUS DE MÉMOIRE !
```

**Solution** : Chaque `malloc()` / `calloc()` doit avoir son `free()` correspondant.

```c
// ✅ CORRECT
void fonction_propre(void) {
    int* ptr = (int*) malloc(10 * sizeof(int));
    if (ptr == NULL) return;
    // Utilisation...
    free(ptr);  // On libère !
}
```

---

### Erreur 2 : Pointeur en suspension (Dangling Pointer)

Un pointeur en suspension pointe vers un bloc de mémoire **qui a déjà été libéré**.

```c
// ❌ POINTEUR EN SUSPENSION
int* ptr = (int*) malloc(sizeof(int));
*ptr = 42;
free(ptr);          // Mémoire libérée

printf("%d\n", *ptr);  // 💥 Comportement indéfini !
// ptr pointe toujours vers l'ancienne adresse,
// mais la mémoire a été rendue au système
```

**Solution** : Mettre le pointeur à `NULL` après `free()`.

```c
// ✅ CORRECT
free(ptr);
ptr = NULL;  // Maintenant on sait que ptr ne pointe plus vers rien

if (ptr != NULL) {
    printf("%d\n", *ptr);  // Cette ligne ne s'exécutera pas
}
```

---

### Erreur 3 : Mémoire non initialisée

Lire une zone mémoire avant de lui donner une valeur donne des résultats **imprévisibles**.

```c
// ❌ MÉMOIRE NON INITIALISÉE
int* ptr = (int*) malloc(5 * sizeof(int));

// On lit SANS avoir écrit de valeur
printf("%d\n", ptr[3]);  // Valeur aléatoire ! Peut être 0, 42, -987654...
```

**Solution** : Utiliser `calloc()` au lieu de `malloc()`, ou initialiser manuellement.

```c
// ✅ Solution 1 : calloc initialise à 0
int* ptr = (int*) calloc(5, sizeof(int));

// ✅ Solution 2 : initialiser manuellement après malloc
int* ptr = (int*) malloc(5 * sizeof(int));
for (int i = 0; i < 5; i++) {
    ptr[i] = 0;
}
```

---

### Tableau récapitulatif des erreurs

| Erreur | Cause | Conséquence | Solution |
|--------|-------|-------------|----------|
| Fuite de mémoire | Pas de `free()` | Mémoire qui ne cesse de croître | Toujours libérer avec `free()` |
| Pointeur en suspension | Utiliser après `free()` | Comportement indéfini, crash | Mettre à `NULL` après `free()` |
| Mémoire non initialisée | Lire avant d'écrire | Valeurs aléatoires | Utiliser `calloc()` ou initialiser |

---

## Mini-projet : Gestionnaire de playlist dynamique 🎵

Mettons tout en pratique avec un mini-projet qui combine allocation, réallocation et libération de mémoire !

### Objectif

Créer un programme qui gère une **playlist musicale** dont la taille évolue dynamiquement.

### Étape 1 : Structure de base

**Exercice 7.1** : Créez un nouveau fichier `playlist.c` avec le code de départ suivant :

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définir la structure Chanson ici

int main(void) {
    // Le code viendra ici

    return 0;
}
```

**Exercice 7.2** : Définissez une structure `Chanson` (avec `typedef`) contenant :
- `titre` : chaîne de 50 caractères
- `artiste` : chaîne de 30 caractères
- `duree_secondes` : entier

> 💡 **Indice** : Si vous avez suivi le cours sur les structures, cela devrait être familier !

---

### Étape 2 : Initialiser la playlist

**Exercice 7.3** : Dans `main()`, déclarez :
- Un pointeur `Chanson* playlist` initialisé à `NULL`
- Un entier `nb_chansons` initialisé à 0

Créez ensuite une fonction `ajouterChanson()` qui :
- Prend un **pointeur vers le pointeur** de la playlist (`Chanson** playlist`), un **pointeur vers** `nb_chansons`, et les infos de la chanson
- Utilise `realloc()` pour agrandir la playlist d'une case
- Copie les données de la nouvelle chanson dans la dernière case
- Incrémente le compteur

> 💡 **Indice** : La signature ressemblera à :
> ```c
> void ajouterChanson(Chanson** playlist, int* nb, 
>                     char* titre, char* artiste, int duree)
> ```
> On passe un `Chanson**` car on doit modifier le pointeur lui-même (qui peut changer avec `realloc`).

---

### Étape 3 : Afficher la playlist

**Exercice 7.4** : Créez une fonction `afficherPlaylist()` qui :
- Prend la playlist et le nombre de chansons
- Affiche chaque chanson avec son numéro, titre, artiste et durée formatée (mm:ss)

> 💡 **Indice** : Pour formater les secondes en minutes:secondes :
> ```c
> int min = chanson.duree_secondes / 60;
> int sec = chanson.duree_secondes % 60;
> printf("%d:%02d", min, sec);
> ```
>
> ✅ **Exemple de sortie** :
> ```
> === PLAYLIST (3 chansons) ===
> [1] "Blinding Lights" - The Weeknd (3:23)
> [2] "Flowers" - Miley Cyrus (3:20)
> [3] "Bohemian Rhapsody" - Queen (5:55)
> ============================
> ```

---

### Étape 4 : Supprimer une chanson

**Exercice 7.5** : Créez une fonction `supprimerChanson()` qui :
- Prend la playlist, le nombre de chansons et l'index à supprimer
- Décale tous les éléments suivants d'une position vers la gauche
- Utilise `realloc()` pour réduire la taille de la playlist
- Décrémente le compteur

> 💡 **Indice** : Pour décaler les éléments :
> ```c
> for (int i = index; i < *nb - 1; i++) {
>     (*playlist)[i] = (*playlist)[i + 1];
> }
> ```

---

### Étape 5 : Calculer la durée totale

**Exercice 7.6** : Créez une fonction `dureeTotale()` qui :
- Prend la playlist et le nombre de chansons
- Retourne la durée totale en secondes

---

### Étape 6 : Programme principal complet

**Exercice 7.7** : Dans `main()`, assemblez le tout :

1. Ajoutez 3 chansons de votre choix
2. Affichez la playlist
3. Affichez la durée totale
4. Supprimez la chanson à l'index 1
5. Affichez la playlist mise à jour
6. Libérez toute la mémoire allouée

> ✅ **Exemple de sortie finale** :
> ```
> === PLAYLIST (3 chansons) ===
> [1] "Blinding Lights" - The Weeknd (3:23)
> [2] "Flowers" - Miley Cyrus (3:20)
> [3] "Bohemian Rhapsody" - Queen (5:55)
> ============================
> Durée totale : 12:38
> 
> Suppression de "Flowers"...
> 
> === PLAYLIST (2 chansons) ===
> [1] "Blinding Lights" - The Weeknd (3:23)
> [2] "Bohemian Rhapsody" - Queen (5:55)
> ============================
> Durée totale : 9:18
> 
> Mémoire libérée. Au revoir !
> ```

---

### Bonus : Allez plus loin ! 🚀

Si vous avez terminé, essayez d'ajouter :

1. **Menu interactif** : un menu en boucle avec les options Ajouter / Supprimer / Afficher / Quitter
2. **Recherche** : trouver une chanson par titre ou artiste
3. **Tri** : trier la playlist par durée ou par ordre alphabétique
4. **Sauvegarde** : enregistrer la playlist dans un fichier et la recharger

---

## Résumé

### Tableau récapitulatif des fonctions

| Fonction | Rôle | Initialise à 0 ? | Header |
|----------|------|:-----------------:|--------|
| `malloc(size)` | Alloue `size` octets | ❌ Non | `<stdlib.h>` |
| `calloc(count, size)` | Alloue `count × size` octets | ✅ Oui | `<stdlib.h>` |
| `realloc(ptr, new_size)` | Redimensionne un bloc existant | ❌ Non (nouvelles zones) | `<stdlib.h>` |
| `free(ptr)` | Libère un bloc alloué | — | `<stdlib.h>` |

### Syntaxes essentielles

| Opération | Syntaxe |
|-----------|---------|
| Allouer 1 élément | `int* p = (int*) malloc(sizeof(int));` |
| Allouer n éléments | `int* p = (int*) malloc(n * sizeof(int));` |
| Allouer n éléments (à 0) | `int* p = (int*) calloc(n, sizeof(int));` |
| Agrandir un tableau | `int* tmp = (int*) realloc(p, new_n * sizeof(int));` |
| Libérer la mémoire | `free(p); p = NULL;` |
| Vérifier l'allocation | `if (p == NULL) { /* erreur */ }` |

### Zones de mémoire

| Zone | Contenu | Gestion |
|------|---------|---------|
| Pile (Stack) | Variables locales, paramètres | Automatique |
| Tas (Heap) | Allocation dynamique | Manuelle (`malloc` / `free`) |
| Zone de données | Variables globales et statiques | Automatique |
| Zone de code | Instructions du programme | Lecture seule |

### Les 3 erreurs à ne JAMAIS commettre

| Erreur | Symptôme | Prévention |
|--------|----------|------------|
| Fuite de mémoire | Programme qui consomme de plus en plus de RAM | `free()` pour chaque `malloc()` |
| Pointeur en suspension | Crash ou données corrompues | `ptr = NULL` après `free()` |
| Mémoire non initialisée | Valeurs aléatoires | `calloc()` ou initialisation manuelle |

### Points clés à retenir

1. **`malloc()`** alloue sans initialiser — rapide mais risqué
2. **`calloc()`** alloue ET initialise à 0 — plus sûr
3. **`realloc()`** redimensionne — toujours utiliser un pointeur temporaire !
4. **`free()`** libère — ne JAMAIS oublier !
5. **Toujours vérifier** le retour de `malloc()` / `calloc()` / `realloc()` contre `NULL`
6. **Toujours mettre à `NULL`** un pointeur après `free()` pour éviter les pointeurs en suspension