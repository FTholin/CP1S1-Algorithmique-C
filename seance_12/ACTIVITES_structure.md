# Les Structures en C

## Introduction

Tout au long de ce cours, nous avons défini de nombreux types de variables, tels que `int` et `char`. Ces types sont connus sous le nom de **types de base** et sont intégrés au langage C.

Nous avons également défini des types de données tels que les tableaux et les pointeurs, connus sous le nom de **types dérivés**. Les types dérivés ont tendance à être une collection de types de base pour créer un nouveau type de données plus puissant. Nous allons maintenant explorer un autre type dérivé : **la structure**.

En C, les structures permettent aux programmeurs de créer des types de données définis par l'utilisateur. Les structures, comme les tableaux, permettent de rassembler de nombreux types de données en un seul type de données. Mais contrairement aux tableaux, les structures peuvent être une collection de **plusieurs types de données différents**.

```
┌─────────────────────────────────────┐
│             Joueur                  │
├─────────────────────────────────────┤
│  char pseudo[25]    → "DarkNinja42" │
│  int niveau         → 47            │
│  int pv             → 850           │
│  float ratio_kd     → 2.3           │
└─────────────────────────────────────┘
```

Ce type d'« emballage » est bénéfique car il permet de construire et de transmettre des données logiquement liées dans un seul type de données défini par l'utilisateur. Imaginez devoir gérer 100 joueurs dans un jeu : sans structures, ce serait un cauchemar !

### À vous de jouer ! 🤠

**Exercice 1.1** : Examinez et exécutez le code ci-dessous. Remarquez toutes les variables qui sont définies séparément. Réfléchissez à la manière dont vous pourriez utiliser des structures pour organiser ces données.

```c
#include <stdio.h>

int main(void) {
    char pseudo[] = "DarkNinja42";
    int niveau = 47;
    int pv = 850;
    float ratio_kd = 2.3;

    printf("Joueur: %s | Niveau %d | PV: %d | K/D: %.1f\n", 
           pseudo, niveau, pv, ratio_kd);
    
    return 0;
}
```

---

## Définition des structures

Pour nous aider à comprendre comment inclure des structures (également appelées `structs`) dans notre code, voyons comment les définir :

```c
struct Joueur {
    char pseudo[25];
    int niveau;
    int pv;
    float ratio_kd;
};
```

Dans l'exemple ci-dessus :

- Le mot-clé `struct` initie la définition du type de structure
- `Joueur` est le nom du nouveau type de structure
- Un ensemble d'accolades `{` `}` entoure les variables membres de la structure
- À l'intérieur des accolades, les variables membres sont « emballées » ensemble
- Un point-virgule `;` termine la définition

Les variables membres peuvent être de n'importe quel type de base (`int`, `char`, `float`, etc.). Elles peuvent également être des types dérivés tels que des tableaux, des pointeurs et même d'autres structures.

**Important** : Les variables membres ne doivent être que **déclarées** et non initialisées dans la définition de la structure. Tenter de donner des valeurs aux variables membres dans la définition conduira à une erreur.

```c
// ❌ INCORRECT - Ne pas initialiser dans la définition
struct Joueur {
    char pseudo[25] = "xXx_Killer";  // ERREUR !
    int niveau = 1;                   // ERREUR !
};

// ✅ CORRECT - Seulement déclarer
struct Joueur {
    char pseudo[25];
    int niveau;
};
```

---

## Le mot-clé typedef : simplifier l'écriture

Vous avez peut-être remarqué que pour déclarer une variable de type structure, on doit écrire `struct Joueur` à chaque fois :

```c
struct Joueur player1;
struct Joueur player2;
struct Joueur* playerPtr;
```

C'est un peu lourd, non ? Heureusement, le C nous offre le mot-clé **`typedef`** qui permet de créer un **alias** (un raccourci) pour un type existant.

### Syntaxe de typedef

```c
typedef type_existant nouveau_nom;
```

Par exemple :
```c
typedef int Entier;      // "Entier" devient un alias pour "int"
typedef float Decimal;   // "Decimal" devient un alias pour "float"

Entier age = 18;         // Équivalent à : int age = 18;
Decimal prix = 9.99;     // Équivalent à : float prix = 9.99;
```

### Combiner typedef avec struct ⭐

La vraie puissance de `typedef` apparaît avec les structures. Voici comment l'utiliser :

```c
// AVANT : sans typedef (syntaxe lourde)
struct Joueur {
    char pseudo[25];
    int niveau;
    int pv;
};

struct Joueur player1;           // On doit écrire "struct" à chaque fois
struct Joueur* playerPtr;        // Encore "struct"...

// ──────────────────────────────────────────

// APRÈS : avec typedef (syntaxe légère) ⭐
typedef struct {
    char pseudo[25];
    int niveau;
    int pv;
} Joueur;

Joueur player1;                  // Plus besoin de "struct" !
Joueur* playerPtr;               // Beaucoup plus propre !
```

### Pourquoi utiliser typedef ?

| Sans typedef | Avec typedef |
|--------------|--------------|
| `struct Joueur player1;` | `Joueur player1;` |
| `struct Joueur* ptr;` | `Joueur* ptr;` |
| `void func(struct Joueur j)` | `void func(Joueur j)` |

Avantages de `typedef` :
- **Code plus lisible** : moins de mots-clés répétitifs
- **Syntaxe proche du C++/Java** : si vous apprenez d'autres langages plus tard
- **Standard dans l'industrie** : la plupart des projets C professionnels l'utilisent
- **Moins d'erreurs** : on ne peut pas oublier le mot `struct`

À partir de maintenant, nous utiliserons **systématiquement `typedef`** dans ce cours !

### À vous de jouer ! 🤠

**Exercice 2.1** : Créez un fichier `structures.c` avec le code de base suivant :

```c
#include <stdio.h>

// Définir la structure ici avec typedef

int main(void) {
    
    return 0;
}
```

**Exercice 2.2** : À l'extérieur de la fonction `main()`, déclarez une structure nommée `Smartphone` **en utilisant typedef** avec les variables membres suivantes :
- `marque` : chaîne de caractères de longueur 20
- `modele` : chaîne de caractères de longueur 30
- `stockage_go` : entier (stockage en Go)
- `batterie_pourcent` : entier (pourcentage de batterie)

> 💡 **Indice** : Votre structure doit contenir 4 membres (2 tableaux de `char` et 2 `int`). Après cet exercice, vous devriez pouvoir déclarer une variable avec simplement `Smartphone monTel;` sans le mot-clé `struct`.

---

## Initialisation des structures

Maintenant que nous savons comment définir des structures avec `typedef`, voyons comment les utiliser dans notre code.

### Notation ordonnée

```c
typedef struct {
    char marque[20];
    char modele[30];
    int stockage_go;
    int batterie_pourcent;
} Smartphone;

Smartphone monTel = {"Apple", "iPhone 15 Pro", 256, 87};
```

L'exemple ci-dessus définit la structure `Smartphone` puis initialise une variable de structure en utilisant une **notation ordonnée** :

- Le type de structure : `Smartphone` (grâce à typedef, plus besoin de `struct` !)
- Le nom de la variable de structure : `monTel`
- L'affectation des valeurs à l'intérieur d'un ensemble d'accolades `{}`

**L'ordre des valeurs attribuées aux variables membres doit correspondre à l'ordre dans lequel les variables ont été définies dans la structure.**

### Notation non ordonnée (désignateurs)

Si vous souhaitez être plus explicite et ne pas vous soucier de l'ordre, vous pouvez utiliser une **notation non ordonnée** avec des désignateurs :

```c
Smartphone monTel = {
    .batterie_pourcent = 87,
    .marque = "Apple",
    .stockage_go = 256,
    .modele = "iPhone 15 Pro"
};
```

Cette notation utilise le point `.` suivi du nom de la variable membre pour indiquer quelle valeur va où. C'est plus lisible quand on a beaucoup de champs !

### À vous de jouer ! 🤠

**Exercice 3.1** : Reprenez votre code de l'exercice précédent.

**Exercice 3.2** : Dans la fonction `main()`, initialisez une structure `Smartphone` nommée `tel1` avec les données suivantes en utilisant la **notation ordonnée** :

| Champ             | Valeur         |
|-------------------|----------------|
| Marque            | Samsung        |
| Modèle            | Galaxy S24     |
| Stockage (Go)     | 128            |
| Batterie (%)      | 100            |

**Exercice 3.3** : Initialisez une deuxième structure `Smartphone` nommée `tel2` avec les données suivantes en utilisant la **notation non ordonnée** :

| Champ             | Valeur         |
|-------------------|----------------|
| Marque            | Xiaomi         |
| Modèle            | Redmi Note 13  |
| Stockage (Go)     | 64             |
| Batterie (%)      | 23             |

> 💡 **Indice** : Pour `tel1`, les valeurs doivent être dans le même ordre que la définition de la structure. Pour `tel2`, utilisez la syntaxe `.nomMembre = valeur` — l'ordre n'a pas d'importance.
>
> ⚠️ **Note** : Si vous avez un warning `unused variable`, c'est normal pour l'instant.

---

## Pourquoi utiliser des structures ?

Prenons un exemple de programme qui gère des comptes de streaming **sans structures** :

```c
char pseudo_compte1[] = "music_lover_92";
int abonnement_mensuel1 = 10;
int playlists1 = 23;
int heures_ecoute1 = 156;

char pseudo_compte2[] = "rap_fr_fan";
int abonnement_mensuel2 = 15;
int playlists2 = 8;
int heures_ecoute2 = 312;
```

Problèmes de cette approche :
- Nous devons suivre **huit variables** pour seulement deux comptes
- Si on ajoute des comptes, le nombre de variables explose (+4 par compte)
- Cette approche devient rapidement un enfer à maintenir
- Les variables ne sont pas logiquement regroupées
- Bonne chance pour ne pas se tromper de numéro !

**Avec une structure (et typedef) :**

```c
typedef struct {
    char pseudo[30];
    int abonnement_mensuel;
    int playlists;
    int heures_ecoute;
} CompteStreaming;

CompteStreaming compte1 = {"music_lover_92", 10, 23, 156};
CompteStreaming compte2 = {"rap_fr_fan", 15, 8, 312};
```

En utilisant une structure pour encapsuler tous les membres qui représentent un compte, nous pouvons :

- **Réduire la complexité** en représentant un ensemble de données avec une seule variable
- **Regrouper des données** différentes mais logiquement liées
- **Mieux représenter les « objets »** du monde réel en types de données
- **Faciliter la maintenance** du code (et votre santé mentale)

### À vous de jouer ! 🤠

**Exercice 4.1** : Copiez-collez le code ci-dessous dans un nouveau fichier. Ce code gère des pizzas pour une appli de livraison, mais c'est le bordel total !

```c
#include <stdio.h>

// Définir la structure ici avec typedef

int main(void) {
    char nom_pizza1[30] = "Margherita";
    float prix_pizza1 = 9.90;
    int taille_pizza1 = 30;
    int temps_cuisson1 = 12;

    char nom_pizza2[30] = "4 Fromages";
    float prix_pizza2 = 12.50;
    int taille_pizza2 = 35;
    int temps_cuisson2 = 15;
    
    return 0;
}
```

**Exercice 4.2** : Au-dessus de la fonction `main()`, créez une structure `Pizza` **avec typedef** contenant les variables membres suivantes :
- `nom` : chaîne de caractères de longueur 30
- `prix` : nombre décimal (`float`)
- `taille_cm` : entier (diamètre en cm)
- `temps_cuisson` : entier (en minutes)

**Exercice 4.3** : Dans la fonction `main()`, remplacez les variables individuelles par :
- `pizza1` initialisée avec les données de la Margherita
- `pizza2` initialisée avec les données de la 4 Fromages

> 💡 **Indice** : À la fin de cet exercice, vous devriez passer de 8 variables à seulement 2 variables de type `Pizza`. Votre `main()` ne devrait contenir que 2 lignes de déclaration/initialisation (plus le `return`).

---

## Notation par points

Maintenant que nous avons exploité la puissance des structures pour regrouper les variables, nous pouvons discuter de la manière d'**accéder à chaque variable membre individuellement** à l'aide de la **notation par points**.

La notation par points est un opérateur C (`.`) qui permet d'accéder à une variable membre d'une structure et de la modifier.

```c
typedef struct {
    char pseudo[25];
    int niveau;
    int pv;
    int xp;
} Joueur;

Joueur player1 = {"N00bMaster", 1, 100, 0};

// Le joueur gagne de l'XP et monte de niveau !
player1.xp = 500;
player1.niveau = 2;
player1.pv = 150;

printf("%s est maintenant niveau %d avec %d PV!\n", 
       player1.pseudo, player1.niveau, player1.pv);
```

Dans l'exemple ci-dessus :

- Une structure `Joueur` est définie et initialisée avec la variable `player1`
- Les variables membres sont modifiées via la notation par points : `player1.xp = 500;`
- On accède aux valeurs pour les afficher avec `printf()`

### Initialisation différée avec l'opérateur point

Vous pouvez également utiliser l'opérateur point pour initialiser une structure si vous souhaitez d'abord la déclarer sans l'initialiser immédiatement :

```c
Joueur player1;
strcpy(player1.pseudo, "N00bMaster");  // Pour les chaînes, utiliser strcpy()
player1.niveau = 1;
player1.pv = 100;
player1.xp = 0;
```

**Note** : Pour les chaînes de caractères déclarées comme tableaux (`char pseudo[25]`), vous devez utiliser `strcpy()` pour copier une chaîne (nécessite `#include <string.h>`).

### À vous de jouer ! 🤠

**Exercice 5.1** : Copiez-collez le code suivant :

```c
#include <stdio.h>

typedef struct {
    char username[30];
    int followers;
    int following;
    int posts;
} ProfilInsta;

int main(void) {
    ProfilInsta profil1 = {"music_addict", 1240, 890, 0};
    ProfilInsta profil2 = {"photo_passion", 15600, 234, 0};
  
    // Écrire le code ici

    printf("@%s : %d followers | %d posts\n", 
           profil1.username, profil1.followers, profil1.posts);
    printf("@%s : %d followers | %d posts\n", 
           profil2.username, profil2.followers, profil2.posts);
    
    return 0;
}
```

Les deux profils ont été créés mais n'ont pas encore de posts !

**Exercice 5.2** : En utilisant la notation par points, fixez le nombre de posts de `profil1` à **47**.

**Exercice 5.3** : En utilisant la notation par points, fixez le nombre de posts de `profil2` à **203**.

> 💡 **Indice** : Vous devez ajouter 2 lignes de code utilisant l'opérateur `.`
>
> ✅ **Sortie attendue** :
> ```
> @music_addict : 1240 followers | 47 posts
> @photo_passion : 15600 followers | 203 posts
> ```

---

## Pointeurs de structure

Comme d'autres types dérivés (tableaux, chaînes de caractères), les structures peuvent utiliser beaucoup de mémoire. Imaginez une structure représentant un personnage de jeu avec son inventaire, ses stats, son historique de quêtes...

L'une des façons de gérer la mémoire efficacement est d'**utiliser des pointeurs**. Pour rappel, un pointeur est une variable qui contient l'adresse mémoire d'une autre variable.

### Définition d'un pointeur de structure

```c
typedef struct {
    char pseudo[25];
    int niveau;
    int pv;
    int xp;
} Joueur;

Joueur player1 = {"ShadowKnight", 45, 920, 12500};
Joueur* playerPtr = &player1;
```

Dans l'exemple ci-dessus, `playerPtr` contient l'adresse mémoire pointant vers `player1`.

Remarquez comme c'est plus propre avec `typedef` : on écrit simplement `Joueur*` au lieu de `struct Joueur*` !

### Accès aux membres avec un pointeur

**Méthode 1 : Déréférencement avec parenthèses et notation par points**

```c
(*playerPtr).pseudo;
(*playerPtr).niveau;
(*playerPtr).pv;
```

Les parenthèses sont **obligatoires** car l'opérateur point `.` a une priorité plus élevée que l'opérateur de déréférencement `*`. Sans parenthèses, `*playerPtr.niveau` serait interprété comme `*(playerPtr.niveau)`, ce qui causerait une erreur.

**Méthode 2 : Notation fléchée (recommandée) ⭐**

```c
playerPtr->pseudo;
playerPtr->niveau;
playerPtr->pv;
```

La **notation fléchée** (`->`) effectue implicitement le déréférencement. Elle est plus lisible et c'est celle que tout le monde utilise en pratique !

---

### ⚠️ Erreurs courantes avec les pointeurs de structures

Voici les erreurs que vous rencontrerez probablement et comment les comprendre :

#### Erreur 1 : Oublier les parenthèses avec `*`

```c
Joueur* ptr = &player1;
*ptr.pv = 100;  // ❌ ERREUR !
```

**Message du compilateur (GCC) :**
```
error: request for member 'pv' in something not a structure or union
   *ptr.pv = 100;
       ^
```

**Explication** : Le compilateur essaie d'abord d'accéder à `ptr.pv` (comme si `ptr` était une structure), puis de déréférencer le résultat. Mais `ptr` est un pointeur, pas une structure !

**Solution** : Ajouter les parenthèses `(*ptr).pv = 100;` ou utiliser la flèche `ptr->pv = 100;`

---

#### Erreur 2 : Utiliser `.` au lieu de `->` avec un pointeur

```c
Joueur* ptr = &player1;
ptr.pv = 100;  // ❌ ERREUR !
```

**Message du compilateur :**
```
error: request for member 'pv' in 'ptr', which is of pointer type 'Joueur *'
   ptr.pv = 100;
      ^
note: perhaps you meant to use '->' ?
```

**Explication** : Vous essayez d'utiliser `.` sur un pointeur. Le compilateur est sympa et vous suggère d'utiliser `->` !

**Solution** : `ptr->pv = 100;`

---

#### Erreur 3 : Utiliser `->` sur une variable (non-pointeur)

```c
Joueur player1 = {"Test", 1, 100, 0};
player1->pv = 200;  // ❌ ERREUR !
```

**Message du compilateur :**
```
error: invalid type argument of '->' (have 'Joueur')
   player1->pv = 200;
          ^~
```

**Explication** : `player1` n'est pas un pointeur, c'est une structure directe. On ne peut pas utiliser `->` dessus.

**Solution** : `player1.pv = 200;`

---

#### Mémo : Quelle notation utiliser ?

| Type de variable | Notation | Exemple |
|------------------|----------|---------|
| Structure directe (`Joueur j`) | Point `.` | `j.pv` |
| Pointeur (`Joueur* ptr`) | Flèche `->` | `ptr->pv` |
| Pointeur déréférencé | Point `.` avec `()` | `(*ptr).pv` |

---

### À vous de jouer ! 🤠

**Exercice 6.1** : Copiez-collez le code suivant :

```c
#include <stdio.h>

typedef struct {
    char pseudo[25];
    int niveau;
    int pv;
    int xp;
} Joueur;

int main(void) {
    Joueur player1 = {"FireMage", 10, 250, 4500};
    Joueur player2 = {"IceWarrior", 8, 320, 3200};
  
    // Écrire le code ici

    printf("[%s] Niveau %d | PV: %d | XP: %d\n", 
           player1.pseudo, player1.niveau, player1.pv, player1.xp);
    printf("[%s] Niveau %d | PV: %d | XP: %d\n", 
           player2.pseudo, player2.niveau, player2.pv, player2.xp);
    
    return 0;
}
```

**Exercice 6.2** : Dans la fonction `main()` :
- Créez un pointeur `player1Ptr` qui pointe vers `player1`
- Créez un pointeur `player2Ptr` qui pointe vers `player2`

**Exercice 6.3** : `player1` vient de subir une attaque ! En utilisant le **déréférencement et la notation par points** `(*pointeur).membre`, enlevez **50 PV** à `player1`.

**Exercice 6.4** : `player2` a terminé une quête ! En utilisant la **notation fléchée** `pointeur->membre`, ajoutez **1000 XP** à `player2`.

> 💡 **Indice** : 
> - Pour 6.2 : utilisez `Joueur*` pour déclarer vos pointeurs et `&` pour obtenir l'adresse
> - Pour 6.3 : n'oubliez pas les parenthèses autour de `*player1Ptr`
> - Pour 6.4 : utilisez l'opérateur `->` suivi de `+=`
>
> ✅ **Sortie attendue** :
> ```
> [FireMage] Niveau 10 | PV: 200 | XP: 4500
> [IceWarrior] Niveau 8 | PV: 320 | XP: 4200
> ```

---

## Exercice intermédiaire : Modifier plusieurs champs via pointeur

Avant de passer aux fonctions, pratiquons davantage les pointeurs avec un exercice plus complet.

### À vous de jouer ! 🤠

**Exercice 6.5** : Copiez-collez le code suivant :

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char titre[50];
    char artiste[30];
    int duree_secondes;
    int nb_lectures;
} Chanson;

int main(void) {
    Chanson maChanson = {"Blinding Lights", "The Weeknd", 203, 1500000};
    
    printf("=== AVANT ===\n");
    printf("Titre: %s\n", maChanson.titre);
    printf("Artiste: %s\n", maChanson.artiste);
    printf("Duree: %d secondes\n", maChanson.duree_secondes);
    printf("Lectures: %d\n\n", maChanson.nb_lectures);
    
    // Créer un pointeur vers maChanson
    
    // Utiliser le pointeur pour :
    // 1. Ajouter 50000 lectures
    // 2. Changer le titre en "Blinding Lights (Remix)"
    
    printf("=== APRES ===\n");
    printf("Titre: %s\n", maChanson.titre);
    printf("Artiste: %s\n", maChanson.artiste);
    printf("Duree: %d secondes\n", maChanson.duree_secondes);
    printf("Lectures: %d\n", maChanson.nb_lectures);
    
    return 0;
}
```

**Exercice 6.6** : 
1. Créez un pointeur `chansonPtr` qui pointe vers `maChanson`
2. Via le pointeur (notation fléchée), ajoutez **50000** au nombre de lectures
3. Via le pointeur, changez le titre en **"Blinding Lights (Remix)"**

> 💡 **Indices** :
> - Pour modifier un `int` via pointeur : `ptr->nb_lectures += 50000;`
> - Pour modifier une chaîne via pointeur : `strcpy(ptr->titre, "nouveau titre");`
> - On ne peut pas faire `ptr->titre = "..."` car `titre` est un tableau, pas un pointeur !
>
> ✅ **Sortie attendue** :
> ```
> === AVANT ===
> Titre: Blinding Lights
> Artiste: The Weeknd
> Duree: 203 secondes
> Lectures: 1500000
> 
> === APRES ===
> Titre: Blinding Lights (Remix)
> Artiste: The Weeknd
> Duree: 203 secondes
> Lectures: 1550000
> ```

---

**Exercice 6.7** : Debugging ! Le code suivant contient des erreurs. Essayez de le compiler et corrigez les erreurs une par une.

```c
#include <stdio.h>

typedef struct {
    char nom[30];
    int score;
} Joueur;

int main(void) {
    Joueur j = {"Pro_Gamer", 9500};
    Joueur* ptr = &j;
    
    // Ligne 1 : Erreur !
    *ptr.score = 10000;
    
    // Ligne 2 : Erreur !
    j->nom;
    
    // Ligne 3 : Erreur !
    ptr.score += 500;
    
    printf("%s : %d points\n", j.nom, j.score);
    return 0;
}
```

> 💡 **Indice** : Il y a 3 erreurs correspondant aux 3 erreurs courantes expliquées plus haut. Compilez, lisez les messages d'erreur, et corrigez !

---

## Structures dans les fonctions

Terminons par l'utilisation des structures dans les fonctions. C'est là que ça devient vraiment utile !

### Structures comme paramètres

Nous pouvons spécifier des structures et des pointeurs vers des structures en tant que paramètres de fonctions :

```c
void afficherJoueur(Joueur j, Joueur* jPtr) {
    // ...
}
```

Remarquez comme c'est plus propre avec `typedef` ! On écrit simplement `Joueur` et `Joueur*` au lieu de `struct Joueur` et `struct Joueur*`.

**Passage par valeur (copie) :**

Lorsqu'une structure est transmise directement à une fonction :
- Une **copie** de la structure est effectuée (consomme de la mémoire)
- Toute modification apportée à la structure **n'affectera pas** la structure originale

**Passage par pointeur (référence) :**

Lors du passage d'un pointeur vers une structure :
- Seule l'adresse est copiée (économise de la mémoire)
- Toute modification apportée aux variables membres **affectera** la structure originale

### Exemple : Système de combat simplifié

```c
#include <stdio.h>

typedef struct {
    char pseudo[25];
    int pv;
    int attaque;
} Joueur;

void attaquer(Joueur attaquant, Joueur* cible) {
    // attaquant est une COPIE (modifications sans effet sur l'original)
    // cible est un POINTEUR (modifications affectent l'original)
    
    int degats = attaquant.attaque;
    cible->pv -= degats;
    
    printf("%s inflige %d degats a %s!\n", 
           attaquant.pseudo, degats, cible->pseudo);
}

int main(void) {
    Joueur hero = {"DragonSlayer", 500, 75};
    Joueur boss = {"DarkLord", 1000, 100};
    
    printf("Avant combat - %s: %d PV\n", boss.pseudo, boss.pv);
    
    attaquer(hero, &boss);  // Le héros attaque le boss
    
    printf("Apres combat - %s: %d PV\n", boss.pseudo, boss.pv);
    
    return 0;
}
```

**Sortie :**
```
Avant combat - DarkLord: 1000 PV
DragonSlayer inflige 75 degats a DarkLord!
Apres combat - DarkLord: 925 PV
```

Remarquez que le boss a bien perdu des PV car on a passé un **pointeur** vers sa structure !

### Retourner une structure

Nous pouvons également retourner des structures depuis une fonction :

```c
Joueur creerJoueur(char* pseudo) {
    Joueur nouveau;
    strcpy(nouveau.pseudo, pseudo);
    nouveau.pv = 100;
    nouveau.attaque = 10;
    return nouveau;
}
```

Grâce à `typedef`, le type de retour est simplement `Joueur` — beaucoup plus lisible que `struct Joueur` !

---

### 🔍 Comprendre le passage par valeur vs retour

C'est un point crucial qui pose souvent problème. Prenons le temps de bien comprendre.

#### Le problème : la copie temporaire

```c
void levelUp(Joueur j) {
    j.niveau += 1;        // On modifie la COPIE
    j.pv += 50;           // Toujours la COPIE
    printf("Dans la fonction: niveau = %d\n", j.niveau);
}   // ⚠️ Ici, la copie 'j' est DÉTRUITE ! Les modifications sont perdues !

int main(void) {
    Joueur hero = {"Link", 5, 100, 0};
    
    levelUp(hero);  // On passe une COPIE de hero
    
    printf("Dans main: niveau = %d\n", hero.niveau);  // Toujours 5 !
    return 0;
}
```

**Sortie :**
```
Dans la fonction: niveau = 6
Dans main: niveau = 5
```

**Que s'est-il passé ?**

```
┌─────────────────────────────────────────────────────────────────┐
│  main()                                                         │
│  ┌─────────────────┐                                            │
│  │ hero            │                                            │
│  │ niveau = 5      │──── COPIE ────┐                            │
│  │ pv = 100        │               │                            │
│  └─────────────────┘               ▼                            │
│                           ┌─────────────────┐                   │
│                           │ j (copie)       │ ← levelUp()       │
│                           │ niveau = 5 → 6  │                   │
│                           │ pv = 100 → 150  │                   │
│                           └─────────────────┘                   │
│                                    │                            │
│                                    ▼                            │
│                              💥 DÉTRUIT à la                    │
│                                 fin de levelUp()                │
│                                                                 │
│  hero est INCHANGÉ : niveau = 5, pv = 100                       │
└─────────────────────────────────────────────────────────────────┘
```

#### Solution 1 : Utiliser un pointeur (modifie directement)

```c
void levelUp(Joueur* j) {
    j->niveau += 1;       // Modifie l'ORIGINAL
    j->pv += 50;
}

int main(void) {
    Joueur hero = {"Link", 5, 100, 0};
    levelUp(&hero);       // On passe l'ADRESSE
    printf("niveau = %d\n", hero.niveau);  // 6 ✓
    return 0;
}
```

#### Solution 2 : Retourner la structure modifiée

```c
Joueur levelUp(Joueur j) {
    j.niveau += 1;        // Modifie la copie
    j.pv += 50;
    return j;             // Retourne la copie modifiée
}

int main(void) {
    Joueur hero = {"Link", 5, 100, 0};
    hero = levelUp(hero); // ⚠️ CRUCIAL : on récupère le retour !
    printf("niveau = %d\n", hero.niveau);  // 6 ✓
    return 0;
}
```

**Pourquoi `hero = levelUp(hero);` est obligatoire ?**

Sans l'assignation, la copie modifiée retournée par `levelUp()` serait simplement ignorée et perdue. C'est comme commander une pizza et ne pas aller la chercher !

#### Quelle solution choisir ?

| Situation | Solution recommandée |
|-----------|---------------------|
| Modifier une seule structure | Pointeur (`void func(Joueur* j)`) |
| Créer une nouvelle structure | Retour (`Joueur creer()`) |
| Modifier ET signaler succès/échec | Pointeur + retour int |
| Ne pas modifier (lecture seule) | Valeur (`void afficher(Joueur j)`) |

---

### À vous de jouer ! 🤠

**Exercice 7.1** : Copiez-collez le code suivant :

```c
#include <stdio.h>

typedef struct {
    char pseudo[25];
    int niveau;
    int xp;
} Joueur;

// Définir la fonction gagnerXP() ici

int main(void) {
    Joueur player1 = {"SpeedRunner", 5, 2300};
    Joueur player2 = {"CasualGamer", 3, 800};

    // Appeler la fonction ici

    printf("[%s] Niveau %d | XP: %d\n", 
           player1.pseudo, player1.niveau, player1.xp);
    printf("[%s] Niveau %d | XP: %d\n", 
           player2.pseudo, player2.niveau, player2.xp);
    
    return 0;
}
```

**Exercice 7.2** : Définissez une fonction `gagnerXP()` avec :
- Type de retour : `Joueur`
- Premier paramètre : `joueur` de type `Joueur` (passage par valeur)
- Deuxième paramètre : `joueurPtr` de type `Joueur*` (passage par pointeur)

**Exercice 7.3** : À l'intérieur de la fonction `gagnerXP()` :
- Ajoutez **500 XP** au paramètre `joueur` (la copie)
- En utilisant la notation fléchée, ajoutez **500 XP** à la structure pointée par `joueurPtr`
- Retournez la structure `joueur`

**Exercice 7.4** : Dans la fonction `main()` :
- Appelez `gagnerXP()` avec `player1` comme premier argument et l'adresse de `player2` comme deuxième argument
- **CRUCIAL** : Assignez la valeur de retour à `player1` !

> 💡 **Indices** :
> - La signature de votre fonction : `Joueur gagnerXP(Joueur joueur, Joueur* joueurPtr)`
> - Pour `joueurPtr` : utilisez `joueurPtr->xp += 500;`
> - Dans `main()` : `player1 = gagnerXP(player1, &player2);`
>
> ⚠️ **Rappel** : Si vous oubliez `player1 = `, les modifications sur `player1` seront perdues car `joueur` dans la fonction est une copie temporaire qui disparaît après le `return` !
>
> ✅ **Sortie attendue** :
> ```
> [SpeedRunner] Niveau 5 | XP: 2800
> [CasualGamer] Niveau 3 | XP: 1300
> ```

---

## Mini-projet : Gestion d'une équipe de joueurs 🎮

Maintenant que vous maîtrisez les structures, mettons tout en pratique avec un mini-projet qui combine tout ce que vous avez appris !

### Objectif

Créer un programme qui gère une **équipe de 4 joueurs** en utilisant un **tableau de structures**.

### Étape 1 : Structure de base

**Exercice 8.1** : Créez un nouveau fichier `equipe.c` avec le code de départ suivant :

```c
#include <stdio.h>
#include <string.h>

#define TAILLE_EQUIPE 4

// Définir la structure Joueur ici

int main(void) {
    // Le code viendra ici
    
    return 0;
}
```

**Exercice 8.2** : Définissez une structure `Joueur` avec :
- `pseudo` : chaîne de 25 caractères
- `classe` : chaîne de 15 caractères (ex: "Mage", "Guerrier", "Archer")
- `niveau` : entier
- `pv` : entier (points de vie)
- `attaque` : entier

> 💡 **Indice** : N'oubliez pas `typedef` !

---

### Étape 2 : Créer l'équipe

**Exercice 8.3** : Dans `main()`, déclarez un tableau de 4 `Joueur` appelé `equipe` et initialisez-le avec ces données :

| Pseudo | Classe | Niveau | PV | Attaque |
|--------|--------|--------|-----|---------|
| ShadowBlade | Assassin | 12 | 180 | 95 |
| HolyLight | Pretre | 10 | 150 | 30 |
| IronFist | Guerrier | 15 | 320 | 75 |
| FrostArrow | Archer | 11 | 160 | 85 |

> 💡 **Indice** : Un tableau de structures s'initialise comme ceci :
> ```c
> Joueur equipe[TAILLE_EQUIPE] = {
>     {"pseudo1", "classe1", niveau1, pv1, attaque1},
>     {"pseudo2", "classe2", niveau2, pv2, attaque2},
>     // ...
> };
> ```

---

### Étape 3 : Fonction d'affichage

**Exercice 8.4** : Créez une fonction `afficherEquipe()` qui :
- Prend en paramètre un tableau de `Joueur` et sa taille
- Affiche les infos de chaque joueur de façon formatée

> 💡 **Indice** : 
> - Signature : `void afficherEquipe(Joueur equipe[], int taille)`
> - Utilisez une boucle `for` pour parcourir le tableau
> - Accédez aux membres avec `equipe[i].pseudo`, etc.
>
> ✅ **Sortie attendue** :
> ```
> ====== ÉQUIPE ======
> [1] ShadowBlade (Assassin) - Niv.12 | PV: 180 | ATK: 95
> [2] HolyLight (Pretre) - Niv.10 | PV: 150 | ATK: 30
> [3] IronFist (Guerrier) - Niv.15 | PV: 320 | ATK: 75
> [4] FrostArrow (Archer) - Niv.11 | PV: 160 | ATK: 85
> ====================
> ```

---

### Étape 4 : Soigner un joueur

**Exercice 8.5** : Créez une fonction `soigner()` qui :
- Prend un **pointeur** vers un `Joueur`
- Ajoute 50 PV au joueur
- Affiche un message de soin

> 💡 **Indice** : 
> - Signature : `void soigner(Joueur* j)`
> - Pour accéder à un élément du tableau par pointeur : `&equipe[index]`
>
> ✅ **Exemple d'utilisation** :
> ```c
> soigner(&equipe[0]);  // Soigne ShadowBlade
> ```
> **Sortie** : `ShadowBlade a été soigné ! PV: 180 -> 230`

---

### Étape 5 : Trouver le joueur le plus fort

**Exercice 8.6** : Créez une fonction `trouverPlusFort()` qui :
- Prend un tableau de `Joueur` et sa taille
- Retourne un **pointeur** vers le joueur avec la plus haute attaque

> 💡 **Indice** :
> - Signature : `Joueur* trouverPlusFort(Joueur equipe[], int taille)`
> - Gardez une trace de l'index du plus fort
> - Retournez `&equipe[indexPlusFort]`
>
> ✅ **Exemple d'utilisation** :
> ```c
> Joueur* champion = trouverPlusFort(equipe, TAILLE_EQUIPE);
> printf("Le plus fort : %s avec %d ATK\n", champion->pseudo, champion->attaque);
> ```

---

### Étape 6 : Calculer les stats de l'équipe

**Exercice 8.7** : Créez une fonction `afficherStatsEquipe()` qui :
- Prend un tableau de `Joueur` et sa taille
- Calcule et affiche :
  - Le niveau moyen de l'équipe
  - Le total de PV de l'équipe
  - Le total d'attaque de l'équipe

> ✅ **Sortie attendue** :
> ```
> === STATS ÉQUIPE ===
> Niveau moyen : 12
> PV total : 810
> Attaque totale : 285
> ```

---

### Étape 7 : Programme principal complet

**Exercice 8.8** : Dans `main()`, assemblez le tout :

1. Affichez l'équipe initiale
2. Soignez le joueur avec le moins de PV (HolyLight)
3. Affichez l'équipe après le soin
4. Trouvez et affichez le joueur le plus fort
5. Affichez les stats de l'équipe

> ✅ **Exemple de sortie finale** :
> ```
> ====== ÉQUIPE ======
> [1] ShadowBlade (Assassin) - Niv.12 | PV: 180 | ATK: 95
> [2] HolyLight (Pretre) - Niv.10 | PV: 150 | ATK: 30
> [3] IronFist (Guerrier) - Niv.15 | PV: 320 | ATK: 75
> [4] FrostArrow (Archer) - Niv.11 | PV: 160 | ATK: 85
> ====================
> 
> HolyLight a été soigné ! PV: 150 -> 200
> 
> ====== ÉQUIPE ======
> [1] ShadowBlade (Assassin) - Niv.12 | PV: 180 | ATK: 95
> [2] HolyLight (Pretre) - Niv.10 | PV: 200 | ATK: 30
> [3] IronFist (Guerrier) - Niv.15 | PV: 320 | ATK: 75
> [4] FrostArrow (Archer) - Niv.11 | PV: 160 | ATK: 85
> ====================
> 
> Le champion de l'équipe : ShadowBlade avec 95 ATK !
> 
> === STATS ÉQUIPE ===
> Niveau moyen : 12
> PV total : 860
> Attaque totale : 285
> ```

---

### Bonus : Allez plus loin ! 🚀

Si vous avez terminé, essayez d'ajouter :

1. **Fonction de combat** : Faites combattre deux joueurs et diminuez leurs PV
2. **Niveau up** : Une fonction qui augmente le niveau et les stats d'un joueur
3. **Sauvegarde** : Enregistrez l'équipe dans un fichier texte
4. **Chargement** : Chargez une équipe depuis un fichier

---

## Résumé

### Définition avec typedef (méthode recommandée ⭐)

```c
typedef struct {
    // variables membres
} NomDuType;
```

### Tableau récapitulatif

| Concept | Syntaxe avec typedef | Description |
|---------|----------------------|-------------|
| Définition | `typedef struct { ... } Nom;` | Crée un nouveau type avec alias |
| Déclaration de variable | `Nom variable;` | Plus besoin de `struct` ! |
| Initialisation ordonnée | `Nom var = {val1, val2};` | Dans l'ordre de définition |
| Initialisation non ordonnée | `Nom var = {.membre = val};` | Avec désignateurs |
| Accès par point | `variable.membre` | Accède directement |
| Pointeur | `Nom* ptr = &var;` | Crée un pointeur |
| Accès par flèche | `pointeur->membre` | Via pointeur ⭐ |
| Accès par déréférencement | `(*pointeur).membre` | Alternative |
| Tableau de structures | `Nom tableau[N];` | Plusieurs structures |

### Erreurs courantes à éviter

| Erreur | Message compilateur | Solution |
|--------|--------------------| ---------|
| `*ptr.membre` | "request for member in something not a structure" | `(*ptr).membre` ou `ptr->membre` |
| `ptr.membre` | "request for member in pointer type" | `ptr->membre` |
| `var->membre` | "invalid type argument of '->'" | `var.membre` |

### Passage en fonction

| Type de passage | Syntaxe | Modifie l'original ? |
|-----------------|---------|---------------------|
| Par valeur | `void f(Joueur j)` | ❌ Non (copie) |
| Par pointeur | `void f(Joueur* j)` | ✅ Oui |
| Retour | `Joueur f()` | ✅ Si assigné ! |

### Points clés à retenir

1. **`typedef`** crée un alias — utilisez-le systématiquement !
2. **Notation par points** (`.`) pour les variables directes
3. **Notation fléchée** (`->`) pour les pointeurs — c'est la méthode préférée !
4. **Passage par pointeur** = modification de l'original
5. **Passage par valeur** = copie temporaire (perdue à la fin de la fonction)
6. **Retour de structure** = récupérer avec `var = fonction();`