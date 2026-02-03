# Projets de renforcement - Structures en C


## Notes importantes avant de commencer

### Tailles des chaînes de caractères

Les tailles de chaînes incluent toujours **+1 pour le caractère nul `\0`**. 

Exemples :
- `"JJ/MM/AAAA"` = 10 caractères visibles + 1 = **11 minimum** (on met 12 par sécurité)
- `"Kebab samedi soir"` = 17 caractères + 1 = **18 minimum** (on met 41 pour avoir de la marge)

### Notation pointée vs. notation fléchée

| Type de variable | Notation | Exemple |
|------------------|----------|---------|
| Structure directe | `.` | `Coloc c;` → `c.prenom` |
| Pointeur vers structure | `->` | `Coloc* p;` → `p->prenom` |

### Comparaison en C

| Type à comparer | Méthode | Exemple |
|-----------------|---------|---------|
| Entiers, flottants | `==` | `if (a == b)` |
| Pointeurs (adresses) | `==` | `if (ptr1 == ptr2)` |
| Chaînes de caractères | `strcmp()` | `if (strcmp(s1, s2) == 0)` |

### Légende de difficulté

- ⭐ Facile : définitions, affichages simples
- ⭐⭐ Moyen : calculs, filtres, boucles
- ⭐⭐⭐ Difficile : pointeurs, modifications via pointeur, logique complexe

---

## Fiche récapitulative : Les structures en C

### 1. Définition d'une structure

```c
// Methode classique
struct Personne {
    char nom[50];
    int age;
};
struct Personne p1;  // Declaration avec "struct"

// Methode avec typedef (recommandee)
typedef struct {
    char nom[50];
    int age;
} Personne;
Personne p1;  // Declaration simplifiee
```

### 2. Initialisation

```c
// A la declaration
Personne p1 = {"Alice", 25};

// Champ par champ
Personne p2;
strcpy(p2.nom, "Bob");  // Pour les chaines !
p2.age = 30;
```

### 3. Accès aux champs

| Situation | Syntaxe | Exemple |
|-----------|---------|---------|
| Variable structure | `.` | `p1.age = 25;` |
| Pointeur vers structure | `->` | `ptr->age = 25;` |

```c
Personne p = {"Alice", 25};
Personne* ptr = &p;

p.age = 26;      // Via la variable
ptr->age = 26;   // Via le pointeur (equivalent a (*ptr).age)
```

### 4. Passage en paramètre

```c
// Passage par VALEUR (copie, l'original n'est pas modifie)
void afficher(Personne p) {
    printf("%s a %d ans\n", p.nom, p.age);
    p.age = 100;  // Ne modifie PAS l'original !
}

// Passage par POINTEUR (reference, l'original EST modifie)
void anniversaire(Personne* p) {
    p->age++;  // Modifie l'original !
}

// Appel
Personne alice = {"Alice", 25};
afficher(alice);       // Passe une copie
anniversaire(&alice);  // Passe l'adresse
```

### 5. Tableaux de structures

```c
Personne classe[30];  // Tableau de 30 personnes

// Initialisation
Personne equipe[3] = {
    {"Alice", 25},
    {"Bob", 30},
    {"Charlie", 28}
};

// Acces
equipe[0].age = 26;  // Premiere personne

// Parcours
for (int i = 0; i < 3; i++) {
    printf("%s\n", equipe[i].nom);
}
```

### 6. Pointeurs dans les structures

```c
typedef struct {
    char nom[50];
    Equipe* equipe;  // Pointeur vers une autre structure
} Joueur;

Equipe psg = {"PSG", "Paris"};
Joueur mbappe = {"Mbappe", &psg};

// Acces chaine
printf("Equipe: %s\n", mbappe.equipe->nom);  // PSG
```

### 7. Comparaisons

| Type | Methode | Exemple |
|------|---------|---------|
| Entiers, pointeurs | `==` | `if (a == b)` |
| Chaines | `strcmp()` | `if (strcmp(s1, s2) == 0)` |
| Structures | Champ par champ | `if (p1.age == p2.age && strcmp(p1.nom, p2.nom) == 0)` |

### 8. Erreurs frequentes

```c
// ERREUR 1 : Oublier d'initialiser un accumulateur
float total;  // DANGER : valeur poubelle !
float total = 0;  // CORRECT

// ERREUR 2 : Utiliser = au lieu de strcpy pour les chaines
p.nom = "Alice";     // ERREUR !
strcpy(p.nom, "Alice");  // CORRECT

// ERREUR 3 : Confondre . et ->
Personne* ptr;
ptr.age = 25;   // ERREUR !
ptr->age = 25;  // CORRECT

// ERREUR 4 : Oublier & pour passer l'adresse
void modifier(Personne* p) { p->age++; }
modifier(alice);   // ERREUR : passe une copie !
modifier(&alice);  // CORRECT : passe l'adresse

// ERREUR 5 : Utiliser strcmp pour comparer des pointeurs
if (strcmp(ptr1, ptr2) == 0)  // CRASH si pas des chaines !
if (ptr1 == ptr2)  // CORRECT pour comparer des adresses

// ERREUR 6 : Division par zero
return total / count;  // DANGER si count == 0 !
if (count == 0) return 0;
return total / count;  // CORRECT
```

### 9. Retourner plusieurs valeurs

```c
// Methode 1 : Pointeurs en parametres
void stats(int tab[], int n, int* min, int* max, float* moy) {
    *min = tab[0];
    *max = tab[0];
    float somme = 0;
    for (int i = 0; i < n; i++) {
        if (tab[i] < *min) *min = tab[i];
        if (tab[i] > *max) *max = tab[i];
        somme += tab[i];
    }
    *moy = somme / n;
}

// Appel
int minimum, maximum;
float moyenne;
stats(tableau, 10, &minimum, &maximum, &moyenne);

// Methode 2 : Retourner une structure
typedef struct {
    int min, max;
    float moy;
} Stats;

Stats calculerStats(int tab[], int n) {
    Stats s;
    // ... calculs ...
    return s;
}
```

### 10. Pointeur de retour

```c
// Retourner un pointeur vers un element d'un tableau
Personne* trouverParNom(Personne tab[], int n, char* nom) {
    for (int i = 0; i < n; i++) {
        if (strcmp(tab[i].nom, nom) == 0) {
            return &tab[i];  // Retourne l'adresse
        }
    }
    return NULL;  // Non trouve
}

// Utilisation
Personne* p = trouverParNom(equipe, 10, "Alice");
if (p != NULL) {
    printf("Trouve: %s, %d ans\n", p->nom, p->age);
} else {
    printf("Non trouve\n");
}
```

---

## Projet 1 : Gestionnaire de budget étudiant

**Notions manipulées** : Définition de structure avec typedef, tableaux de structures, fonctions de calcul simples, passage par valeur

### Contexte

Gérer son budget quand on est étudiant, c'est compliqué. Tu crées une application pour suivre tes dépenses et ne pas finir à découvert le 15 du mois.

### Exercice 1.1 ⭐ : Définir la structure Depense

Crée une structure `Depense` contenant :
- Une description (chaîne de 41 caractères max, pour 40 caractères + `\0`)
- Un montant (nombre décimal)
- Une catégorie (chaîne de 16 caractères : "Bouffe", "Soiree", "Transport", "Abonnements", "Courses", "Autre")
- Une date (chaîne de 12 caractères au format "JJ/MM/AAAA")
- Un indicateur si la dépense est essentielle ou non (entier : 1 = nécessaire, 0 = plaisir)

> **Indication** : Utilise `typedef struct { ... } Depense;` pour simplifier l'écriture par la suite.

**Test dans main** :
```c
int main(void) {
    Depense d1 = {"Kebab samedi soir", 8.50, "Bouffe", "05/01/2025", 0};
    printf("Test: %s - %.2f euros\n", d1.description, d1.montant);
    return 0;
}
```

**Sortie attendue** :
```
Test: Kebab samedi soir - 8.50 euros
```

---

### Exercice 1.2 ⭐ : Créer un tableau de dépenses

Déclare un tableau de 8 dépenses et initialise-le avec les données suivantes :

| Description | Montant | Catégorie | Date | Essentiel |
|-------------|---------|-----------|------|-----------|
| Kebab samedi soir | 8.50 | Bouffe | 05/01/2025 | 0 |
| Courses Lidl | 45.20 | Courses | 03/01/2025 | 1 |
| Netflix | 13.49 | Abonnements | 01/01/2025 | 0 |
| Spotify | 5.99 | Abonnements | 01/01/2025 | 0 |
| Soiree bar | 32.00 | Soiree | 06/01/2025 | 0 |
| Pass Navigo | 86.40 | Transport | 01/01/2025 | 1 |
| Uber nuit | 18.50 | Transport | 07/01/2025 | 0 |
| Courses Carrefour | 38.90 | Courses | 10/01/2025 | 1 |

**Test dans main** :
```c
int main(void) {
    Depense depenses[8] = {
        // ... tes initialisations ici
    };
    printf("Nombre de depenses: 8\n");
    printf("Premiere depense: %s (%.2f euros)\n", depenses[0].description, depenses[0].montant);
    printf("Derniere depense: %s (%.2f euros)\n", depenses[7].description, depenses[7].montant);
    return 0;
}
```

**Sortie attendue** :
```
Nombre de depenses: 8
Premiere depense: Kebab samedi soir (8.50 euros)
Derniere depense: Courses Carrefour (38.90 euros)
```

---

### Exercice 1.3 ⭐ : Fonction d'affichage d'une dépense

Crée une fonction `void afficherDepense(Depense d)` qui affiche une dépense de manière formatée.

> **Indication** : La fonction reçoit une copie de la structure (passage par valeur). Affiche la description, le montant, la catégorie, la date, et indique si c'est une dépense "Plaisir" ou "Essentiel".

**Test dans main** :
```c
int main(void) {
    Depense d = {"Kebab samedi soir", 8.50, "Bouffe", "05/01/2025", 0};
    afficherDepense(d);
    
    Depense d2 = {"Pass Navigo", 86.40, "Transport", "01/01/2025", 1};
    afficherDepense(d2);
    return 0;
}
```

**Sortie attendue** :
```
* Kebab samedi soir - 8.50 euros
  Categorie: Bouffe | Date: 05/01/2025 | Plaisir

* Pass Navigo - 86.40 euros
  Categorie: Transport | Date: 01/01/2025 | Essentiel
```

---

### Exercice 1.4 ⭐⭐ : Calculer le total des dépenses

Crée une fonction `float totalDepenses(Depense depenses[], int taille)` qui retourne la somme de tous les montants.

> **Indication** : Parcours le tableau avec une boucle et accumule les montants.

**Test dans main** :
```c
int main(void) {
    Depense depenses[3] = {
        {"Test 1", 10.00, "Autre", "01/01/2025", 0},
        {"Test 2", 25.50, "Autre", "02/01/2025", 1},
        {"Test 3", 14.50, "Autre", "03/01/2025", 0}
    };
    float total = totalDepenses(depenses, 3);
    printf("Total: %.2f euros\n", total);
    return 0;
}
```

**Sortie attendue** :
```
Total: 50.00 euros
```

---

### Exercice 1.5 ⭐⭐ : Total par catégorie

Crée une fonction `float totalParCategorie(Depense depenses[], int taille, char* categorie)` qui retourne le total des dépenses d'une catégorie donnée.

> **Indication** : Utilise `strcmp(str1, str2) == 0` pour comparer deux chaînes (nécessite `#include <string.h>`).

**Test dans main** :
```c
int main(void) {
    Depense depenses[4] = {
        {"Kebab", 8.50, "Bouffe", "05/01/2025", 0},
        {"Courses", 45.20, "Courses", "03/01/2025", 1},
        {"Pizza", 12.00, "Bouffe", "06/01/2025", 0},
        {"Netflix", 13.49, "Abonnements", "01/01/2025", 0}
    };
    
    printf("Total Bouffe: %.2f euros\n", totalParCategorie(depenses, 4, "Bouffe"));
    printf("Total Courses: %.2f euros\n", totalParCategorie(depenses, 4, "Courses"));
    printf("Total Sport: %.2f euros\n", totalParCategorie(depenses, 4, "Sport"));
    return 0;
}
```

**Sortie attendue** :
```
Total Bouffe: 20.50 euros
Total Courses: 45.20 euros
Total Sport: 0.00 euros
```

---

### Exercice 1.6 ⭐⭐ : Pourcentage de dépenses plaisir

Crée une fonction `float pourcentagePlaisir(Depense depenses[], int taille)` qui calcule le pourcentage de dépenses non essentielles.

> **Indication** : Calcule d'abord le total des dépenses plaisir (essentiel == 0), puis divise par le total général et multiplie par 100.
>
> **Attention** : Pense à vérifier que le total n'est pas 0 avant de diviser, sinon tu auras une erreur de division par zéro !
> ```c
> if (total == 0) return 0;  // Eviter la division par zero
> ```

**Test dans main** :
```c
int main(void) {
    Depense depenses[4] = {
        {"Kebab", 10.00, "Bouffe", "05/01/2025", 0},      // plaisir
        {"Courses", 40.00, "Courses", "03/01/2025", 1},   // essentiel
        {"Bar", 30.00, "Soiree", "06/01/2025", 0},        // plaisir
        {"Transport", 20.00, "Transport", "01/01/2025", 1} // essentiel
    };
    // Total = 100, Plaisir = 40, donc 40%
    printf("Pourcentage plaisir: %.1f%%\n", pourcentagePlaisir(depenses, 4));
    return 0;
}
```

**Sortie attendue** :
```
Pourcentage plaisir: 40.0%
```

---

### Exercice 1.7 ⭐⭐ : Budget restant

Crée une fonction `void afficherBudgetRestant(float budget_mensuel, Depense depenses[], int taille)` qui affiche le budget initial, le montant dépensé, le reste, et le pourcentage utilisé.

**Test dans main** :
```c
int main(void) {
    Depense depenses[3] = {
        {"Courses", 50.00, "Courses", "01/01/2025", 1},
        {"Bar", 30.00, "Soiree", "02/01/2025", 0},
        {"Transport", 20.00, "Transport", "03/01/2025", 1}
    };
    afficherBudgetRestant(200.00, depenses, 3);
    return 0;
}
```

**Sortie attendue** :
```
=== BUDGET ===
Budget mensuel: 200.00 euros
Depense: 100.00 euros
Reste: 100.00 euros (50.0% utilise)
```

---

### Exercice 1.8 ⭐⭐ : Alerte découvert

Crée une fonction `void alerteDecouvert(float budget, Depense depenses[], int taille, float seuil_pourcent)` qui affiche un avertissement si le pourcentage du budget utilisé dépasse le seuil donné.

**Test dans main** :
```c
int main(void) {
    Depense depenses[2] = {
        {"Grosses courses", 150.00, "Courses", "01/01/2025", 1},
        {"Resto", 30.00, "Bouffe", "02/01/2025", 0}
    };
    
    printf("Test avec seuil 80%%:\n");
    alerteDecouvert(200.00, depenses, 2, 80.0);  // 180/200 = 90%, depasse 80%
    
    printf("\nTest avec seuil 95%%:\n");
    alerteDecouvert(200.00, depenses, 2, 95.0);  // 90% < 95%, OK
    return 0;
}
```

**Sortie attendue** :
```
Test avec seuil 80%:
/!\ ATTENTION: Tu as utilise 90.0% de ton budget!
    Reste seulement 20.00 euros pour le mois.

Test avec seuil 95%:
Budget OK: 90.0% utilise.
```

---

### Exercice 1.9 ⭐⭐ : Afficher toutes les dépenses

Crée une fonction `void afficherToutesDepenses(Depense depenses[], int taille)` qui affiche la liste complète avec un en-tête et un total à la fin.

**Test dans main** :
```c
int main(void) {
    Depense depenses[3] = {
        {"Kebab", 8.50, "Bouffe", "05/01/2025", 0},
        {"Courses Lidl", 45.20, "Courses", "03/01/2025", 1},
        {"Netflix", 13.49, "Abonnements", "01/01/2025", 0}
    };
    afficherToutesDepenses(depenses, 3);
    return 0;
}
```

**Sortie attendue** :
```
=== LISTE DES DEPENSES ===

* Kebab - 8.50 euros
  Categorie: Bouffe | Date: 05/01/2025 | Plaisir

* Courses Lidl - 45.20 euros
  Categorie: Courses | Date: 03/01/2025 | Essentiel

* Netflix - 13.49 euros
  Categorie: Abonnements | Date: 01/01/2025 | Plaisir

==========================
TOTAL: 67.19 euros
```

---

### Exercice 1.10 ⭐⭐ : Programme complet

Assemble toutes les fonctions dans un programme complet qui :
1. Initialise le tableau de 8 dépenses (exercice 1.2)
2. Affiche toutes les dépenses
3. Affiche le total par catégorie pour : Bouffe, Courses, Abonnements, Transport, Soiree
4. Affiche le pourcentage de dépenses plaisir
5. Affiche le budget restant (budget = 450 euros)
6. Affiche une alerte si plus de 60% du budget est utilisé

**Sortie attendue** :
```
=== BUDGET JANVIER 2025 ===

=== LISTE DES DEPENSES ===

* Kebab samedi soir - 8.50 euros
  Categorie: Bouffe | Date: 05/01/2025 | Plaisir

* Courses Lidl - 45.20 euros
  Categorie: Courses | Date: 03/01/2025 | Essentiel

... (autres depenses)

==========================
TOTAL: 248.98 euros

=== ANALYSE PAR CATEGORIE ===
Bouffe: 8.50 euros
Courses: 84.10 euros
Abonnements: 19.48 euros
Transport: 104.90 euros
Soiree: 32.00 euros

=== REPARTITION ===
Depenses plaisir: 31.5%

=== BUDGET ===
Budget mensuel: 450.00 euros
Depense: 248.98 euros
Reste: 201.02 euros (55.3% utilise)

Budget OK: 55.3% utilise.
```



---

## Projet 2 : Application de colocation

**Notions manipulées** : Structures multiples, pointeurs de structures, notation fléchée, modification via pointeur, calculs entre structures

### Contexte

Tu vis en coloc et c'est toujours le bordel pour savoir qui doit quoi à qui. Tu crées une app pour gérer les dépenses communes et les tâches ménagères.

### Schéma mémoire : Comprendre les pointeurs

Avant de commencer, voici comment fonctionnent les pointeurs dans ce projet :

```
MEMOIRE

┌─────────────────────┐         ┌─────────────────────┐
│   DepenseCommune    │         │       Coloc         │
├─────────────────────┤         ├─────────────────────┤
│ description:        │         │ prenom: "Lea"       │
│   "Courses IKEA"    │         │ solde: 30.00        │
│ montant: 85.00      │         │ taches_faites: 5    │
│ payeur: ────────────┼────────>│                     │
│ date: "15/01/2025"  │         └─────────────────────┘
└─────────────────────┘

Le champ "payeur" contient l'ADRESSE de la structure Coloc.
Avec cette adresse, on peut MODIFIER directement le solde de Lea !
```

**Règle importante** : Quand on modifie `payeur->solde`, on modifie vraiment le solde de Lea, pas une copie !

---

### Exercice 2.1 ⭐ : Définir la structure Coloc

Crée une structure `Coloc` contenant :
- Un prénom (chaîne de 21 caractères)
- Un solde (nombre décimal : positif = on lui doit de l'argent, négatif = il doit de l'argent)
- Un compteur de tâches faites ce mois-ci (entier)

> **Indication** : Un solde à 0 signifie que la personne est à jour. Un solde positif signifie que les autres lui doivent de l'argent.

**Test dans main** :
```c
int main(void) {
    Coloc c1 = {"Theo", 0.0, 3};
    Coloc c2 = {"Lea", 25.50, 5};
    
    printf("%s: solde = %.2f euros, taches = %d\n", c1.prenom, c1.solde, c1.taches_faites);
    printf("%s: solde = %.2f euros, taches = %d\n", c2.prenom, c2.solde, c2.taches_faites);
    return 0;
}
```

**Sortie attendue** :
```
Theo: solde = 0.00 euros, taches = 3
Lea: solde = 25.50 euros, taches = 5
```

---

### Exercice 2.2 ⭐⭐ : Définir la structure DepenseCommune

Crée une structure `DepenseCommune` contenant :
- Une description (chaîne de 41 caractères)
- Un montant (nombre décimal)
- Un pointeur vers le coloc qui a payé
- Une date (chaîne de 12 caractères)

> **Indication** : Le champ `payeur` est de type `Coloc*` (pointeur vers Coloc). Cela permet de savoir QUI a payé et de modifier son solde directement.

**Test dans main** :
```c
int main(void) {
    Coloc lea = {"Lea", 0.0, 5};
    DepenseCommune dep = {"Courses IKEA", 85.00, &lea, "15/01/2025"};
    
    printf("Depense: %s\n", dep.description);
    printf("Montant: %.2f euros\n", dep.montant);
    printf("Paye par: %s\n", dep.payeur->prenom);  // Notation flechee !
    return 0;
}
```

**Sortie attendue** :
```
Depense: Courses IKEA
Montant: 85.00 euros
Paye par: Lea
```

---

### Exercice 2.3 ⭐ : Créer le tableau de colocs

Crée un tableau de 4 colocataires initialisés avec solde à 0 :

| Prénom | Solde | Tâches faites |
|--------|-------|---------------|
| Theo | 0 | 3 |
| Lea | 0 | 5 |
| Hugo | 0 | 2 |
| Chloe | 0 | 4 |

**Test dans main** :
```c
int main(void) {
    Coloc colocs[4] = {
        // ... tes initialisations
    };
    
    printf("Colocation de %d personnes:\n", 4);
    for (int i = 0; i < 4; i++) {
        printf("- %s\n", colocs[i].prenom);
    }
    return 0;
}
```

**Sortie attendue** :
```
Colocation de 4 personnes:
- Theo
- Lea
- Hugo
- Chloe
```

---

### Exercice 2.4 ⭐⭐ : Fonction d'affichage d'un coloc

Crée une fonction `void afficherColoc(Coloc* c)` qui affiche les infos d'un colocataire via un pointeur.

> **Indication** : Utilise la notation fléchée `c->prenom` car `c` est un pointeur. Affiche le solde avec un signe + si positif (on lui doit), - si négatif (il doit).

**Test dans main** :
```c
int main(void) {
    Coloc c1 = {"Theo", -17.50, 3};
    Coloc c2 = {"Lea", 32.00, 5};
    Coloc c3 = {"Hugo", 0.00, 2};
    
    afficherColoc(&c1);  // On passe l'ADRESSE avec &
    afficherColoc(&c2);
    afficherColoc(&c3);
    return 0;
}
```

**Sortie attendue** :
```
* Theo | Solde: -17.50 euros (doit de l'argent) | 3 taches ce mois
* Lea | Solde: +32.00 euros (on lui doit) | 5 taches ce mois
* Hugo | Solde: 0.00 euros (a jour) | 2 taches ce mois
```

---

### Exercice 2.5 ⭐⭐⭐ : Appliquer une dépense commune

Crée une fonction `void appliquerDepense(DepenseCommune* dep, Coloc colocs[], int nb_colocs)` qui :
- Divise le montant par le nombre de colocs
- Crédite le payeur du montant total
- Débite chaque coloc de sa part (y compris le payeur)

> **Indication importante** : La logique est la suivante :
> 1. Le payeur **avance** tout l'argent → on lui ajoute le montant total à son solde
> 2. **Chaque coloc** (y compris le payeur) doit sa part → on soustrait (montant / nb_colocs) à chacun
>
> **Exemple concret** : Lea paye 40€ pour 4 colocs
> - Lea avance : +40€ à son solde
> - Chacun doit 10€ : -10€ pour Theo, Lea, Hugo, Chloe
> - Résultat : Lea = +40 - 10 = **+30€** (on lui doit), les autres = **-10€** (ils doivent)
> - Vérification : 30 + (-10) + (-10) + (-10) = **0** (les soldes s'équilibrent toujours !)
>
> **Attention** : Ne PAS exclure le payeur de la boucle de débit ! C'est une erreur fréquente.

**Test dans main** :
```c
int main(void) {
    Coloc colocs[4] = {
        {"Theo", 0.0, 3},
        {"Lea", 0.0, 5},
        {"Hugo", 0.0, 2},
        {"Chloe", 0.0, 4}
    };
    
    // Lea paye 40 euros pour tous
    DepenseCommune dep = {"Courses", 40.00, &colocs[1], "10/01/2025"};
    
    printf("Avant la depense:\n");
    for (int i = 0; i < 4; i++) {
        printf("  %s: %.2f\n", colocs[i].prenom, colocs[i].solde);
    }
    
    appliquerDepense(&dep, colocs, 4);
    
    printf("\nApres la depense de %.2f euros payee par %s:\n", dep.montant, dep.payeur->prenom);
    for (int i = 0; i < 4; i++) {
        printf("  %s: %.2f\n", colocs[i].prenom, colocs[i].solde);
    }
    return 0;
}
```

**Sortie attendue** :
```
Avant la depense:
  Theo: 0.00
  Lea: 0.00
  Hugo: 0.00
  Chloe: 0.00

Apres la depense de 40.00 euros payee par Lea:
  Theo: -10.00
  Lea: 30.00
  Hugo: -10.00
  Chloe: -10.00
```

> **Explication** : Lea avance 40 euros (+40), puis chacun doit 10 euros (-10 pour tous). Lea se retrouve à +30, les autres à -10. Total des soldes = 0 (vérifie que c'est équilibré).

---

### Exercice Bonus 2.5b ⭐⭐⭐ : Trouve le bug !

Le code suivant ne fonctionne pas correctement. Trouve l'erreur :

```c
void appliquerDepense(DepenseCommune* dep, Coloc colocs[], int nb_colocs) {
    float part = dep->montant / nb_colocs;
    dep->payeur->solde += dep->montant;
    
    for (int i = 0; i < nb_colocs; i++) {
        // On exclut le payeur car il a deja paye
        if (&colocs[i] != dep->payeur) {  // BUG !
            colocs[i].solde -= part;
        }
    }
}
```

<details>
<summary>Voir la solution</summary>

**Problème** : En excluant le payeur de la boucle, on ne lui soustrait pas sa part. Le payeur garde +40€ au lieu de +30€.

**Explication** : Le payeur doit aussi payer SA part de la dépense. Il avance l'argent (crédit), puis comme tout le monde, il doit sa part (débit).

**Solution** : Ne pas exclure le payeur :
```c
for (int i = 0; i < nb_colocs; i++) {
    colocs[i].solde -= part;  // Tout le monde, y compris le payeur
}
```

</details>

---

### Exercice 2.6 ⭐⭐ : Définir la structure Tache

Crée une structure `Tache` contenant :
- Un nom (chaîne de 31 caractères)
- Un pointeur vers le coloc responsable
- Une fréquence en jours (entier)
- La date de dernière exécution (chaîne de 12 caractères)

**Test dans main** :
```c
int main(void) {
    Coloc theo = {"Theo", 0.0, 3};
    Tache t = {"Poubelles", &theo, 3, "08/01/2025"};
    
    printf("Tache: %s\n", t.nom);
    printf("Responsable: %s\n", t.responsable->prenom);
    printf("Frequence: tous les %d jours\n", t.frequence_jours);
    printf("Derniere fois: %s\n", t.derniere_fois);
    return 0;
}
```

**Sortie attendue** :
```
Tache: Poubelles
Responsable: Theo
Frequence: tous les 3 jours
Derniere fois: 08/01/2025
```

---

### Exercice 2.7 ⭐⭐ : Afficher les soldes

Crée une fonction `void afficherSoldes(Coloc colocs[], int taille)` qui affiche un récapitulatif clair de qui doit quoi.

**Test dans main** :
```c
int main(void) {
    Coloc colocs[4] = {
        {"Theo", -17.13, 3},
        {"Lea", 32.37, 5},
        {"Hugo", 9.38, 2},
        {"Chloe", -24.62, 4}
    };
    
    afficherSoldes(colocs, 4);
    return 0;
}
```

**Sortie attendue** :
```
=== QUI DOIT QUOI ? ===
* Theo : doit 17.13 euros
* Lea : on lui doit 32.37 euros
* Hugo : on lui doit 9.38 euros
* Chloe : doit 24.62 euros
```

---

### Exercice 2.8 ⭐⭐⭐ : Marquer une tâche effectuée

Crée une fonction `void tacheEffectuee(Tache* t, char* nouvelle_date)` qui :
- Met à jour la date de dernière exécution
- Incrémente le compteur de tâches du responsable

> **Indication** : Utilise `strcpy` pour copier la nouvelle date. Le responsable est un pointeur, donc utilise `t->responsable->taches_faites` pour accéder et modifier le compteur.
>
> **Schéma mémoire** :
> ```
> ┌──────────────┐        ┌──────────────┐
> │    Tache t   │        │  Coloc chloe │
> ├──────────────┤        ├──────────────┤
> │ nom: "SdB"   │        │ prenom:      │
> │ responsable:─┼───────>│   "Chloe"    │
> │ frequence: 7 │        │ solde: 0.00  │
> │ derniere:    │        │ taches: 4 → 5│ <- On modifie ICI !
> │  "04/01"     │        └──────────────┘
> └──────────────┘
> ```

**Test dans main** :
```c
int main(void) {
    Coloc chloe = {"Chloe", 0.0, 4};
    Tache t = {"Salle de bain", &chloe, 7, "04/01/2025"};
    
    printf("Avant:\n");
    printf("  Derniere fois: %s\n", t.derniere_fois);
    printf("  Taches de %s: %d\n", chloe.prenom, chloe.taches_faites);
    
    tacheEffectuee(&t, "11/01/2025");
    
    printf("\nApres:\n");
    printf("  Derniere fois: %s\n", t.derniere_fois);
    printf("  Taches de %s: %d\n", chloe.prenom, chloe.taches_faites);
    return 0;
}
```

**Sortie attendue** :
```
Avant:
  Derniere fois: 04/01/2025
  Taches de Chloe: 4

Apres:
  Derniere fois: 11/01/2025
  Taches de Chloe: 5
```

---

### Exercice 2.9 ⭐⭐ : Afficher les tâches

Crée une fonction `void afficherTaches(Tache taches[], int taille)` qui affiche la liste des tâches.

**Test dans main** :
```c
int main(void) {
    Coloc colocs[4] = {
        {"Theo", 0.0, 3},
        {"Lea", 0.0, 5},
        {"Hugo", 0.0, 2},
        {"Chloe", 0.0, 4}
    };
    
    Tache taches[4] = {
        {"Poubelles", &colocs[0], 3, "08/01/2025"},
        {"Aspirateur", &colocs[1], 7, "05/01/2025"},
        {"Vaisselle", &colocs[2], 2, "10/01/2025"},
        {"Salle de bain", &colocs[3], 7, "04/01/2025"}
    };
    
    afficherTaches(taches, 4);
    return 0;
}
```

**Sortie attendue** :
```
=== TACHES MENAGERES ===
* Poubelles - Theo (tous les 3 jours) - Dernier: 08/01/2025
* Aspirateur - Lea (tous les 7 jours) - Dernier: 05/01/2025
* Vaisselle - Hugo (tous les 2 jours) - Dernier: 10/01/2025
* Salle de bain - Chloe (tous les 7 jours) - Dernier: 04/01/2025
```

---

### Exercice 2.10 ⭐⭐⭐ : Programme complet

Assemble le tout dans un programme qui :
1. Crée 4 colocs
2. Applique 4 dépenses communes :
   - Courses IKEA : 85.00 euros (Lea)
   - Internet janvier : 35.00 euros (Theo)
   - Produits ménage : 28.50 euros (Chloe)
   - Soirée appart : 62.00 euros (Hugo)
3. Affiche les soldes finaux
4. Crée et affiche les 4 tâches ménagères
5. Marque la tâche "Salle de bain" comme effectuée le 11/01/2025
6. Affiche les tâches mises à jour

---

## Projet 3 : Organisateur de soirées

**Notions manipulées** : Structures avec tableaux internes, compteurs, fonctions de recherche, retour de valeurs, conditions multiples

### Contexte

Tu organises des soirées et événements étudiants. Tu as besoin d'un système pour gérer les invités, les participations aux frais, et les réponses.

### Comprendre les tableaux internes avec compteur

Dans ce projet, la structure `Evenement` contient un tableau de 30 invités ET un compteur `nb_invites` :

```
┌─────────────────────────────────────────────────────────────┐
│                       Evenement                              │
├─────────────────────────────────────────────────────────────┤
│ nom: "Soiree BDE"                                           │
│ lieu: "Le Warehouse"                                        │
│ ...                                                         │
│ liste_invites[30]:                                          │
│   [0] Alice  ──┐                                            │
│   [1] Bob     │ Utilisés (nb_invites = 3)                   │
│   [2] Charlie─┘                                             │
│   [3] ???    ──┐                                            │
│   [4] ???     │ Non utilisés (données "poubelle")           │
│   ...        ─┘                                             │
│   [29] ???                                                  │
│ nb_invites: 3  <- Indique combien de cases sont UTILISÉES   │
└─────────────────────────────────────────────────────────────┘

ATTENTION : 
- Taille du tableau = 30 (capacité maximale)
- nb_invites = nombre de cases réellement utilisées
- Toujours initialiser nb_invites à 0 !
```

---

### Exercice 3.1 ⭐ : Définir la structure Invite

Crée une structure `Invite` contenant :
- Un nom (chaîne de 31 caractères)
- Un numéro de téléphone (chaîne de 16 caractères)
- Une réponse (entier : 0 = en attente, 1 = vient, 2 = ne vient pas, 3 = peut-être)
- Un indicateur de paiement (entier : 1 = a payé, 0 = pas encore)
- Un nombre d'accompagnants supplémentaires (entier : +1, +2, etc.)

**Test dans main** :
```c
int main(void) {
    Invite i1 = {"Theo Martin", "06 12 34 56 78", 1, 1, 2};
    
    printf("Invite: %s\n", i1.nom);
    printf("Tel: %s\n", i1.telephone);
    printf("Reponse: %d (1=vient)\n", i1.reponse);
    printf("A paye: %d (1=oui)\n", i1.a_paye);
    printf("Accompagnants: +%d\n", i1.nb_invites_sup);
    return 0;
}
```

**Sortie attendue** :
```
Invite: Theo Martin
Tel: 06 12 34 56 78
Reponse: 1 (1=vient)
A paye: 1 (1=oui)
Accompagnants: +2
```

---

### Exercice 3.2 ⭐⭐ : Définir la structure Evenement

Crée une structure `Evenement` contenant :
- Un nom (chaîne de 51 caractères)
- Un lieu (chaîne de 41 caractères)
- Une date (chaîne de 12 caractères)
- Une heure (chaîne de 7 caractères, format "HH:MM")
- Un prix d'entrée (nombre décimal)
- Un nombre de places maximum (entier)
- Un tableau d'invités (maximum 30)
- Un compteur du nombre d'invités actuels (entier)

> **Indication** : Le tableau d'invités est de type `Invite liste_invites[30]` et `nb_invites` compte combien de places du tableau sont utilisées.
>
> **Important** : `nb_invites` doit TOUJOURS être initialisé à 0 lors de la création d'un événement !

**Test dans main** :
```c
int main(void) {
    Evenement e;
    strcpy(e.nom, "Soiree BDE");
    strcpy(e.lieu, "Le Warehouse");
    strcpy(e.date, "18/01/2025");
    strcpy(e.heure, "23:00");
    e.prix_entree = 12.00;
    e.places_max = 150;
    e.nb_invites = 0;  // IMPORTANT : initialiser a 0 !
    
    printf("Evenement: %s\n", e.nom);
    printf("Lieu: %s\n", e.lieu);
    printf("Date: %s a %s\n", e.date, e.heure);
    printf("Prix: %.2f euros\n", e.prix_entree);
    printf("Places: %d max, %d invites\n", e.places_max, e.nb_invites);
    return 0;
}
```

**Sortie attendue** :
```
Evenement: Soiree BDE
Lieu: Le Warehouse
Date: 18/01/2025 a 23:00
Prix: 12.00 euros
Places: 150 max, 0 invites
```

---

### Exercice 3.3 ⭐⭐ : Fonction de création d'événement

Crée une fonction `Evenement creerEvenement(char* nom, char* lieu, char* date, char* heure, float prix, int places)` qui retourne un événement initialisé avec 0 invités.

> **Indication** : Utilise `strcpy` pour copier les chaînes dans la structure locale, puis retourne cette structure. N'oublie pas `e.nb_invites = 0;` !

**Test dans main** :
```c
int main(void) {
    Evenement e = creerEvenement("Soiree BDE - Back to School", "Le Warehouse", 
                                  "18/01/2025", "23:00", 12.00, 150);
    
    printf("Cree: %s au %s\n", e.nom, e.lieu);
    printf("Invites: %d\n", e.nb_invites);
    return 0;
}
```

**Sortie attendue** :
```
Cree: Soiree BDE - Back to School au Le Warehouse
Invites: 0
```

---

### Exercice 3.4 ⭐⭐ : Ajouter un invité

Crée une fonction `int inviter(Evenement* e, char* nom, char* tel)` qui :
- Ajoute un invité à la liste (en attente de réponse, non payé, 0 accompagnant)
- Retourne 1 si succès, 0 si la liste est pleine (30 max)

> **Indication** : L'invité est ajouté à l'index `e->nb_invites`, puis on incrémente ce compteur.
> ```c
> // Ajouter a la premiere case libre
> strcpy(e->liste_invites[e->nb_invites].nom, nom);
> // ... initialiser les autres champs ...
> e->nb_invites++;  // Incrementer le compteur
> ```

**Test dans main** :
```c
int main(void) {
    Evenement e = creerEvenement("Test", "Lieu", "01/01/2025", "20:00", 10.00, 150);
    
    int r1 = inviter(&e, "Alice Dupont", "06 11 11 11 11");
    int r2 = inviter(&e, "Bob Martin", "06 22 22 22 22");
    
    printf("Ajout Alice: %d (1=OK)\n", r1);
    printf("Ajout Bob: %d (1=OK)\n", r2);
    printf("Nombre d'invites: %d\n", e.nb_invites);
    printf("Premier invite: %s\n", e.liste_invites[0].nom);
    printf("Deuxieme invite: %s\n", e.liste_invites[1].nom);
    return 0;
}
```

**Sortie attendue** :
```
Ajout Alice: 1 (1=OK)
Ajout Bob: 1 (1=OK)
Nombre d'invites: 2
Premier invite: Alice Dupont
Deuxieme invite: Bob Martin
```

---

### Exercice 3.5 ⭐⭐ : Répondre à une invitation

Crée une fonction `int repondreInvitation(Evenement* e, char* nom, int reponse, int accompagnants)` qui :
- Cherche l'invité par son nom
- Met à jour sa réponse et son nombre d'accompagnants
- Retourne 1 si trouvé, 0 sinon

**Test dans main** :
```c
int main(void) {
    Evenement e = creerEvenement("Test", "Lieu", "01/01/2025", "20:00", 10.00, 150);
    inviter(&e, "Alice Dupont", "06 11 11 11 11");
    inviter(&e, "Bob Martin", "06 22 22 22 22");
    
    // Alice vient avec 2 accompagnants
    int r1 = repondreInvitation(&e, "Alice Dupont", 1, 2);
    // Bob ne vient pas
    int r2 = repondreInvitation(&e, "Bob Martin", 2, 0);
    // Charlie n'existe pas
    int r3 = repondreInvitation(&e, "Charlie Brown", 1, 0);
    
    printf("Reponse Alice: %d (1=trouve)\n", r1);
    printf("Reponse Bob: %d (1=trouve)\n", r2);
    printf("Reponse Charlie: %d (1=trouve)\n", r3);
    printf("\nAlice: reponse=%d, accompagnants=%d\n", 
           e.liste_invites[0].reponse, e.liste_invites[0].nb_invites_sup);
    return 0;
}
```

**Sortie attendue** :
```
Reponse Alice: 1 (1=trouve)
Reponse Bob: 1 (1=trouve)
Reponse Charlie: 0 (1=trouve)

Alice: reponse=1, accompagnants=2
```

---

### Exercice 3.6 ⭐⭐ : Afficher un invité

Crée une fonction `void afficherInvite(Invite i)` qui affiche les infos d'un invité de manière lisible.

> **Indication** : Affiche le statut en texte ("Vient", "Ne vient pas", "Peut-etre", "En attente") selon la valeur de `reponse`. Ajoute "(+N)" si accompagnants > 0. Affiche "Paye" ou "Non paye".

**Test dans main** :
```c
int main(void) {
    Invite i1 = {"Alice Dupont", "06 11 11 11 11", 1, 1, 2};
    Invite i2 = {"Bob Martin", "06 22 22 22 22", 2, 0, 0};
    Invite i3 = {"Charlie Brown", "06 33 33 33 33", 0, 0, 0};
    Invite i4 = {"Diana Prince", "06 44 44 44 44", 3, 0, 1};
    
    afficherInvite(i1);
    afficherInvite(i2);
    afficherInvite(i3);
    afficherInvite(i4);
    return 0;
}
```

**Sortie attendue** :
```
* Alice Dupont - 06 11 11 11 11
  Vient (+2) | Paye

* Bob Martin - 06 22 22 22 22
  Ne vient pas | Non paye

* Charlie Brown - 06 33 33 33 33
  En attente | Non paye

* Diana Prince - 06 44 44 44 44
  Peut-etre (+1) | Non paye
```

---

### Exercice 3.7 ⭐⭐⭐ : Compter par statut

Crée une fonction `void compterParStatut(Evenement* e, int* viennent, int* refus, int* peut_etre, int* attente, int* total_personnes)` qui compte :
- Le nombre d'invités qui viennent
- Le nombre de refus
- Le nombre de "peut-être"
- Le nombre en attente
- Le total de personnes attendues (invités qui viennent + leurs accompagnants)

> **Indication** : Utilise des pointeurs pour retourner plusieurs valeurs. Passe l'adresse de variables locales depuis main.

**Test dans main** :
```c
int main(void) {
    Evenement e = creerEvenement("Test", "Lieu", "01/01/2025", "20:00", 10.00, 150);
    inviter(&e, "Alice", "06 11");
    inviter(&e, "Bob", "06 22");
    inviter(&e, "Charlie", "06 33");
    inviter(&e, "Diana", "06 44");
    
    repondreInvitation(&e, "Alice", 1, 2);   // Vient +2
    repondreInvitation(&e, "Bob", 1, 0);     // Vient seul
    repondreInvitation(&e, "Charlie", 2, 0); // Ne vient pas
    // Diana reste en attente
    
    int v, r, p, a, total;
    compterParStatut(&e, &v, &r, &p, &a, &total);
    
    printf("Viennent: %d\n", v);
    printf("Refus: %d\n", r);
    printf("Peut-etre: %d\n", p);
    printf("En attente: %d\n", a);
    printf("Total personnes attendues: %d\n", total);
    return 0;
}
```

**Sortie attendue** :
```
Viennent: 2
Refus: 1
Peut-etre: 0
En attente: 1
Total personnes attendues: 4
```

---

### Exercice 3.8 ⭐⭐ : Places restantes

Crée une fonction `int placesRestantes(Evenement* e)` qui calcule le nombre de places encore disponibles.

> **Indication** : Places restantes = places_max - total personnes attendues (ceux qui viennent + leurs accompagnants).

**Test dans main** :
```c
int main(void) {
    Evenement e = creerEvenement("Test", "Lieu", "01/01/2025", "20:00", 10.00, 50);
    inviter(&e, "Alice", "06 11");
    inviter(&e, "Bob", "06 22");
    
    repondreInvitation(&e, "Alice", 1, 4);   // Vient +4 = 5 personnes
    repondreInvitation(&e, "Bob", 1, 2);     // Vient +2 = 3 personnes
    // Total = 8 personnes, places max = 50
    
    printf("Places max: %d\n", e.places_max);
    printf("Places restantes: %d\n", placesRestantes(&e));
    return 0;
}
```

**Sortie attendue** :
```
Places max: 50
Places restantes: 42
```

---

### Exercice 3.9 ⭐⭐ : Marquer comme payé

Crée une fonction `int marquerPaye(Evenement* e, char* nom)` qui :
- Cherche l'invité par son nom
- Met `a_paye` à 1
- Retourne 1 si trouvé, 0 sinon

**Test dans main** :
```c
int main(void) {
    Evenement e = creerEvenement("Test", "Lieu", "01/01/2025", "20:00", 10.00, 50);
    inviter(&e, "Alice", "06 11");
    
    printf("Avant: a_paye = %d\n", e.liste_invites[0].a_paye);
    
    int r = marquerPaye(&e, "Alice");
    
    printf("Resultat: %d (1=trouve)\n", r);
    printf("Apres: a_paye = %d\n", e.liste_invites[0].a_paye);
    return 0;
}
```

**Sortie attendue** :
```
Avant: a_paye = 0
Resultat: 1 (1=trouve)
Apres: a_paye = 1
```

---

### Exercice 3.10 ⭐⭐⭐ : Recette actuelle

Crée une fonction `float recetteActuelle(Evenement* e)` qui calcule l'argent déjà récolté (nombre de personnes ayant payé × prix).

> **Indication** : Compte uniquement les invités qui ont `a_paye == 1`. Pour chaque invité payé, compte 1 + ses accompagnants.

**Test dans main** :
```c
int main(void) {
    Evenement e = creerEvenement("Test", "Lieu", "01/01/2025", "20:00", 10.00, 50);
    inviter(&e, "Alice", "06 11");
    inviter(&e, "Bob", "06 22");
    inviter(&e, "Charlie", "06 33");
    
    repondreInvitation(&e, "Alice", 1, 2);   // Vient +2 = 3 places
    repondreInvitation(&e, "Bob", 1, 0);     // Vient seul = 1 place
    repondreInvitation(&e, "Charlie", 1, 1); // Vient +1 = 2 places
    
    marquerPaye(&e, "Alice");    // Paye pour 3
    marquerPaye(&e, "Charlie");  // Paye pour 2
    // Bob n'a pas payé
    
    printf("Prix unitaire: %.2f euros\n", e.prix_entree);
    printf("Recette actuelle: %.2f euros\n", recetteActuelle(&e));
    return 0;
}
```

**Sortie attendue** :
```
Prix unitaire: 10.00 euros
Recette actuelle: 50.00 euros
```

---

### Exercice 3.11 ⭐⭐ : Liste des relances

Crée une fonction `void relancerNonReponses(Evenement* e)` qui affiche la liste des invités en attente de réponse (reponse == 0).

**Test dans main** :
```c
int main(void) {
    Evenement e = creerEvenement("Test", "Lieu", "01/01/2025", "20:00", 10.00, 50);
    inviter(&e, "Alice", "06 11 11 11 11");
    inviter(&e, "Bob", "06 22 22 22 22");
    inviter(&e, "Charlie", "06 33 33 33 33");
    inviter(&e, "Diana", "06 44 44 44 44");
    
    repondreInvitation(&e, "Alice", 1, 0);   // A repondu
    repondreInvitation(&e, "Charlie", 2, 0); // A repondu
    // Bob et Diana n'ont pas repondu
    
    relancerNonReponses(&e);
    return 0;
}
```

**Sortie attendue** :
```
=== RELANCES A FAIRE ===
- Bob : 06 22 22 22 22
- Diana : 06 44 44 44 44

2 personne(s) a relancer.
```

---

### Exercice 3.12 ⭐⭐⭐ : Programme complet

Assemble le tout pour gérer l'événement "Soirée BDE - Back to School" avec 8 invités de ton choix.

---

## Projet 4 : Suivi de candidatures ingénieur

**Notions manipulées** : Structure avec énumération d'états, fonctions de filtrage, modification d'état, statistiques

### Contexte

La recherche de stage ou d'alternance pour un ingénieur Arts et Métiers c'est un travail à plein temps. Tu crées un tracker pour suivre tes candidatures et ne rien oublier.

### Exercice 4.1 ⭐ : Définir la structure Candidature

Crée une structure `Candidature` contenant :
- Nom de l'entreprise (chaîne de 41 caractères)
- Intitulé du poste (chaîne de 51 caractères)
- Ville (chaîne de 26 caractères)
- Salaire mensuel brut (nombre décimal, 0 si non précisé)
- Durée en mois (entier)
- Date de candidature (chaîne de 12 caractères, chaîne vide "" si pas encore envoyée)
- Statut (entier : 0 = à envoyer, 1 = envoyée, 2 = entretien prévu, 3 = refus, 4 = acceptée)
- Nom du contact/recruteur (chaîne de 41 caractères, chaîne vide "" si pas de contact)
- Email du contact (chaîne de 51 caractères, chaîne vide "" si pas d'email)
- Notes personnelles (chaîne de 101 caractères)
- Indicateur de relance effectuée (entier : 1 = oui, 0 = non)

> **Conseil** : Utilise des chaînes vides `""` pour les champs optionnels plutôt que des tirets `"-"`. Cela simplifie les vérifications avec `strlen()`.

**Test dans main** :
```c
int main(void) {
    Candidature c = {
        "Safran", 
        "Ingenieur Methodes Usinage", 
        "Villaroche", 
        1850.0, 
        6, 
        "02/01/2025", 
        2,  // entretien
        "Marie Leroy", 
        "m.leroy@safran.fr",
        "Entretien prevu le 20/01",
        0
    };
    
    printf("Entreprise: %s\n", c.entreprise);
    printf("Poste: %s\n", c.poste);
    printf("Statut: %d (2=entretien)\n", c.statut);
    return 0;
}
```

**Sortie attendue** :
```
Entreprise: Safran
Poste: Ingenieur Methodes Usinage
Statut: 2 (2=entretien)
```

---

### Exercice 4.2 ⭐ : Créer un tableau de candidatures

Crée un tableau de 6 candidatures typiques pour un élève ingénieur Arts et Métiers :

| Entreprise | Poste | Ville | Salaire | Durée | Date | Statut | Contact | Email |
|------------|-------|-------|---------|-------|------|--------|---------|-------|
| Safran | Ingenieur Methodes Usinage | Villaroche | 1850 | 6 | 02/01/2025 | 2 | Marie Leroy | m.leroy@safran.fr |
| Renault | Ingenieur Qualite Production | Flins | 1700 | 6 | 28/12/2024 | 1 | (vide) | (vide) |
| Airbus | Ingenieur Bureau Etudes | Toulouse | 1900 | 6 | 05/01/2025 | 1 | Jean Petit | j.petit@airbus.com |
| Schneider Electric | Ingenieur Industrialisation | Grenoble | 1650 | 6 | 03/01/2025 | 3 | (vide) | (vide) |
| Alstom | Ingenieur Maintenance | Saint-Ouen | 1750 | 6 | (vide) | 0 | (vide) | (vide) |
| Valeo | Ingenieur R&D Thermique | Creteil | 1800 | 6 | 06/01/2025 | 1 | Sophie Martin | s.martin@valeo.com |

> **Indication** : Pour les champs vides, utilise une chaîne vide `""`.

**Test dans main** :
```c
int main(void) {
    Candidature candidatures[6] = {
        // ... tes initialisations
    };
    
    printf("Nombre de candidatures: 6\n");
    printf("Premiere: %s - %s\n", candidatures[0].entreprise, candidatures[0].poste);
    printf("Derniere: %s - %s\n", candidatures[5].entreprise, candidatures[5].poste);
    return 0;
}
```

**Sortie attendue** :
```
Nombre de candidatures: 6
Premiere: Safran - Ingenieur Methodes Usinage
Derniere: Valeo - Ingenieur R&D Thermique
```

---

### Exercice 4.3 ⭐⭐ : Afficher une candidature

Crée une fonction `void afficherCandidature(Candidature c)` qui affiche les détails d'une candidature.

> **Indication** : Affiche le statut en texte clair. Si le salaire est 0, affiche "Non precise". Si pas de contact (chaîne vide), affiche "Pas de contact".
>
> Pour vérifier si une chaîne est vide : `if (strlen(c.contact) == 0)` ou simplement `if (c.contact[0] == '\0')`

**Test dans main** :
```c
int main(void) {
    Candidature c1 = {"Safran", "Ingenieur Methodes", "Paris", 1850.0, 6, 
                      "02/01/2025", 2, "Marie Leroy", "m.leroy@safran.fr", "", 0};
    Candidature c2 = {"Alstom", "Ingenieur Maintenance", "Lyon", 0, 6, 
                      "", 0, "", "", "A postuler cette semaine", 0};
    
    afficherCandidature(c1);
    printf("\n");
    afficherCandidature(c2);
    return 0;
}
```

**Sortie attendue** :
```
=== Safran - Ingenieur Methodes (Paris) ===
Salaire: 1850.00 euros/mois | Duree: 6 mois
Date candidature: 02/01/2025
Statut: ENTRETIEN PREVU
Contact: Marie Leroy (m.leroy@safran.fr)

=== Alstom - Ingenieur Maintenance (Lyon) ===
Salaire: Non precise | Duree: 6 mois
Date candidature: -
Statut: A ENVOYER
Contact: Pas de contact
Notes: A postuler cette semaine
```

---

### Exercice 4.4 ⭐⭐ : Statistiques des candidatures

Crée une fonction `void statistiquesCandidatures(Candidature candis[], int taille)` qui affiche le décompte par statut.

**Test dans main** :
```c
int main(void) {
    Candidature candis[6] = {
        {"E1", "P1", "V1", 1000, 6, "01/01/2025", 2, "", "", "", 0},  // entretien
        {"E2", "P2", "V2", 1000, 6, "01/01/2025", 1, "", "", "", 0},  // envoyee
        {"E3", "P3", "V3", 1000, 6, "01/01/2025", 1, "", "", "", 0},  // envoyee
        {"E4", "P4", "V4", 1000, 6, "01/01/2025", 3, "", "", "", 0},  // refus
        {"E5", "P5", "V5", 1000, 6, "", 0, "", "", "", 0},            // a envoyer
        {"E6", "P6", "V6", 1000, 6, "01/01/2025", 1, "", "", "", 0}   // envoyee
    };
    
    statistiquesCandidatures(candis, 6);
    return 0;
}
```

**Sortie attendue** :
```
=== STATISTIQUES ===
Total: 6 candidatures
  - A envoyer: 1
  - Envoyees: 3
  - Entretiens: 1
  - Refus: 1
  - Acceptees: 0
```

---

### Exercice 4.5 ⭐⭐ : Changer le statut

Crée une fonction `void changerStatut(Candidature* c, int nouveau_statut)` qui met à jour le statut et affiche un message approprié.

**Test dans main** :
```c
int main(void) {
    Candidature c = {"Safran", "Ingenieur", "Paris", 1800, 6, 
                     "01/01/2025", 1, "", "", "", 0};
    
    printf("Statut initial: %d\n", c.statut);
    
    changerStatut(&c, 2);  // Passe en entretien
    printf("Nouveau statut: %d\n", c.statut);
    
    changerStatut(&c, 4);  // Acceptee !
    printf("Nouveau statut: %d\n", c.statut);
    return 0;
}
```

**Sortie attendue** :
```
Statut initial: 1
[Safran] Statut mis a jour: ENVOYEE -> ENTRETIEN PREVU
Nouveau statut: 2
[Safran] Statut mis a jour: ENTRETIEN PREVU -> ACCEPTEE
Felicitations !
Nouveau statut: 4
```

---

### Exercice 4.6 ⭐⭐ : Filtrer par statut

Crée une fonction `void afficherParStatut(Candidature candis[], int taille, int statut)` qui affiche uniquement les candidatures ayant le statut donné.

**Test dans main** :
```c
int main(void) {
    Candidature candis[4] = {
        {"Safran", "Poste 1", "Paris", 1800, 6, "01/01/2025", 1, "", "", "", 0},
        {"Renault", "Poste 2", "Lyon", 1700, 6, "02/01/2025", 2, "", "", "", 0},
        {"Airbus", "Poste 3", "Toulouse", 1900, 6, "03/01/2025", 1, "", "", "", 0},
        {"Alstom", "Poste 4", "Nantes", 1750, 6, "", 0, "", "", "", 0}
    };
    
    printf("=== ENVOYEES (statut 1) ===\n");
    afficherParStatut(candis, 4, 1);
    
    printf("\n=== A ENVOYER (statut 0) ===\n");
    afficherParStatut(candis, 4, 0);
    return 0;
}
```

**Sortie attendue** :
```
=== ENVOYEES (statut 1) ===
- Safran - Poste 1 (Paris)
- Airbus - Poste 3 (Toulouse)

=== A ENVOYER (statut 0) ===
- Alstom - Poste 4 (Nantes)
```

---

### Exercice 4.7 ⭐⭐ : Candidatures à relancer

Crée une fonction `void candidaturesARelancer(Candidature candis[], int taille)` qui affiche les candidatures :
- Statut = 1 (envoyée)
- ET relance_faite = 0

**Test dans main** :
```c
int main(void) {
    Candidature candis[4] = {
        {"Safran", "P1", "V1", 1800, 6, "01/01/2025", 1, "", "", "", 0},    // A relancer
        {"Renault", "P2", "V2", 1700, 6, "02/01/2025", 1, "", "", "", 1},   // Deja relancee
        {"Airbus", "P3", "V3", 1900, 6, "03/01/2025", 2, "", "", "", 0},    // Entretien, pas besoin
        {"Valeo", "P4", "V4", 1750, 6, "04/01/2025", 1, "", "", "", 0}      // A relancer
    };
    
    candidaturesARelancer(candis, 4);
    return 0;
}
```

**Sortie attendue** :
```
=== CANDIDATURES A RELANCER ===
- Safran - P1
  Envoyee le: 01/01/2025
  
- Valeo - P4
  Envoyee le: 04/01/2025

2 candidature(s) a relancer.
```

---

### Exercice 4.8 ⭐⭐ : Marquer une relance

Crée une fonction `void marquerRelance(Candidature* c)` qui :
- Met `relance_faite` à 1
- Affiche un modèle d'email de relance

**Test dans main** :
```c
int main(void) {
    Candidature c = {"Renault", "Ingenieur Qualite", "Flins", 1700, 6, 
                     "28/12/2024", 1, "Pierre Durand", "p.durand@renault.fr", "", 0};
    
    printf("Avant: relance_faite = %d\n", c.relance_faite);
    marquerRelance(&c);
    printf("Apres: relance_faite = %d\n", c.relance_faite);
    return 0;
}
```

**Sortie attendue** :
```
Avant: relance_faite = 0

=== EMAIL DE RELANCE SUGGERE ===
Destinataire: p.durand@renault.fr
Objet: Relance candidature - Ingenieur Qualite

Bonjour,

Je me permets de vous relancer concernant ma candidature
au poste de Ingenieur Qualite envoyee le 28/12/2024.

Je reste a votre disposition pour tout entretien.

Cordialement.
================================

Relance marquee pour Renault.
Apres: relance_faite = 1
```

---

### Exercice 4.9 ⭐⭐ : Filtrer par ville

Crée une fonction `void filtrerParVille(Candidature candis[], int taille, char* ville)`.

**Test dans main** :
```c
int main(void) {
    Candidature candis[4] = {
        {"Safran", "P1", "Paris", 1800, 6, "", 1, "", "", "", 0},
        {"Renault", "P2", "Lyon", 1700, 6, "", 1, "", "", "", 0},
        {"Airbus", "P3", "Paris", 1900, 6, "", 1, "", "", "", 0},
        {"Alstom", "P4", "Nantes", 1750, 6, "", 1, "", "", "", 0}
    };
    
    printf("=== OFFRES A PARIS ===\n");
    filtrerParVille(candis, 4, "Paris");
    return 0;
}
```

**Sortie attendue** :
```
=== OFFRES A PARIS ===
- Safran - P1 (1800.00 euros/mois)
- Airbus - P3 (1900.00 euros/mois)

2 offre(s) a Paris.
```

---

### Exercice 4.10 ⭐⭐ : Filtrer par salaire minimum

Crée une fonction `void filtrerParSalaire(Candidature candis[], int taille, float salaire_min)`.

**Test dans main** :
```c
int main(void) {
    Candidature candis[4] = {
        {"Safran", "P1", "Paris", 1800, 6, "", 1, "", "", "", 0},
        {"Renault", "P2", "Lyon", 1650, 6, "", 1, "", "", "", 0},
        {"Airbus", "P3", "Toulouse", 1900, 6, "", 1, "", "", "", 0},
        {"Alstom", "P4", "Nantes", 1750, 6, "", 1, "", "", "", 0}
    };
    
    printf("=== OFFRES >= 1750 euros ===\n");
    filtrerParSalaire(candis, 4, 1750.0);
    return 0;
}
```

**Sortie attendue** :
```
=== OFFRES >= 1750 euros ===
- Safran - P1 (Paris) : 1800.00 euros
- Airbus - P3 (Toulouse) : 1900.00 euros
- Alstom - P4 (Nantes) : 1750.00 euros

3 offre(s) >= 1750.00 euros.
```

---

### Exercice 4.11 ⭐⭐⭐ : Trouver l'entretien à venir

Crée une fonction `Candidature* prochainEntretien(Candidature candis[], int taille)` qui retourne un pointeur vers la première candidature en statut "entretien" (statut == 2), ou NULL si aucune.

**Test dans main** :
```c
int main(void) {
    Candidature candis[3] = {
        {"Safran", "P1", "Paris", 1800, 6, "01/01/2025", 1, "", "", "", 0},
        {"Renault", "P2", "Lyon", 1700, 6, "02/01/2025", 2, "Jean Dupont", "", "RDV le 20/01", 0},
        {"Airbus", "P3", "Toulouse", 1900, 6, "03/01/2025", 1, "", "", "", 0}
    };
    
    Candidature* entretien = prochainEntretien(candis, 3);
    
    if (entretien != NULL) {
        printf("Entretien a venir:\n");
        printf("  %s - %s\n", entretien->entreprise, entretien->poste);
        printf("  Contact: %s\n", entretien->contact);
        printf("  Notes: %s\n", entretien->notes);
    } else {
        printf("Aucun entretien prevu.\n");
    }
    return 0;
}
```

**Sortie attendue** :
```
Entretien a venir:
  Renault - P2
  Contact: Jean Dupont
  Notes: RDV le 20/01
```

---

### Exercice 4.12 ⭐⭐⭐ : Programme complet

Crée un programme complet de suivi de candidatures qui :
1. Initialise les 6 candidatures de l'exercice 4.2
2. Affiche les statistiques
3. Liste les entretiens à venir
4. Liste les candidatures à relancer
5. Liste les candidatures à envoyer
6. Filtre les offres en Île-de-France (Paris, Villaroche, Flins, Creteil, Saint-Ouen)
7. Filtre les offres >= 1800 euros

---

## Projet 5 : Gestionnaire de collection de vinyles

**Notions manipulées** : Structures, tableaux, tri simple, recherche, statistiques, pointeurs

### Contexte

Tu es passionné de musique et tu commences une collection de vinyles. Tu crées une application pour gérer ta collection, suivre sa valeur, et trouver des pépites.

### Exercice 5.1 ⭐ : Définir la structure Vinyle

Crée une structure `Vinyle` contenant :
- Titre de l'album (chaîne de 51 caractères)
- Artiste (chaîne de 41 caractères)
- Année de sortie (entier)
- Genre (chaîne de 21 caractères : "Rock", "Jazz", "Electro", "Hip-Hop", "Pop", "Classique", etc.)
- État (entier : 1 = Mint, 2 = Excellent, 3 = Bon, 4 = Correct, 5 = Abimé)
- Prix d'achat (nombre décimal)
- Valeur estimée actuelle (nombre décimal)
- Édition limitée (entier : 1 = oui, 0 = non)

**Test dans main** :
```c
int main(void) {
    Vinyle v = {"Random Access Memories", "Daft Punk", 2013, "Electro", 1, 35.00, 120.00, 1};
    
    printf("Album: %s\n", v.titre);
    printf("Artiste: %s\n", v.artiste);
    printf("Annee: %d\n", v.annee);
    printf("Etat: %d (1=Mint)\n", v.etat);
    printf("Prix achat: %.2f euros\n", v.prix_achat);
    printf("Valeur actuelle: %.2f euros\n", v.valeur_estimee);
    return 0;
}
```

**Sortie attendue** :
```
Album: Random Access Memories
Artiste: Daft Punk
Annee: 2013
Etat: 1 (1=Mint)
Prix achat: 35.00 euros
Valeur actuelle: 120.00 euros
```

---

### Exercice 5.2 ⭐ : Créer une collection

Crée un tableau de 8 vinyles :

| Titre | Artiste | Année | Genre | État | Achat | Valeur | Édition |
|-------|---------|-------|-------|------|-------|--------|---------|
| Random Access Memories | Daft Punk | 2013 | Electro | 1 | 35.00 | 120.00 | 1 |
| The Dark Side of the Moon | Pink Floyd | 1973 | Rock | 3 | 25.00 | 80.00 | 0 |
| Kind of Blue | Miles Davis | 1959 | Jazz | 2 | 40.00 | 150.00 | 0 |
| OK Computer | Radiohead | 1997 | Rock | 2 | 30.00 | 95.00 | 0 |
| Homework | Daft Punk | 1997 | Electro | 4 | 15.00 | 45.00 | 0 |
| Abbey Road | The Beatles | 1969 | Rock | 3 | 28.00 | 70.00 | 0 |
| To Pimp a Butterfly | Kendrick Lamar | 2015 | Hip-Hop | 1 | 32.00 | 55.00 | 1 |
| Thriller | Michael Jackson | 1982 | Pop | 2 | 20.00 | 60.00 | 0 |

**Test dans main** :
```c
int main(void) {
    Vinyle collection[8] = {
        // ... tes initialisations
    };
    
    printf("Collection: %d vinyles\n", 8);
    printf("Premier: %s - %s\n", collection[0].titre, collection[0].artiste);
    printf("Dernier: %s - %s\n", collection[7].titre, collection[7].artiste);
    return 0;
}
```

**Sortie attendue** :
```
Collection: 8 vinyles
Premier: Random Access Memories - Daft Punk
Dernier: Thriller - Michael Jackson
```

---

### Exercice 5.3 ⭐⭐ : Afficher un vinyle

Crée une fonction `void afficherVinyle(Vinyle v)` qui affiche les détails d'un vinyle.

> **Indication** : Affiche l'état en texte (Mint, Excellent, Bon, Correct, Abime). Affiche "[Edition Limitee]" si applicable. Calcule et affiche la plus-value en pourcentage.

**Test dans main** :
```c
int main(void) {
    Vinyle v1 = {"Random Access Memories", "Daft Punk", 2013, "Electro", 1, 35.00, 120.00, 1};
    Vinyle v2 = {"Abbey Road", "The Beatles", 1969, "Rock", 3, 28.00, 70.00, 0};
    
    afficherVinyle(v1);
    printf("\n");
    afficherVinyle(v2);
    return 0;
}
```

**Sortie attendue** :
```
=== Random Access Memories ===
Artiste: Daft Punk (2013)
Genre: Electro
Etat: Mint [Edition Limitee]
Achat: 35.00 euros | Valeur: 120.00 euros (+242.9%)

=== Abbey Road ===
Artiste: The Beatles (1969)
Genre: Rock
Etat: Bon
Achat: 28.00 euros | Valeur: 70.00 euros (+150.0%)
```

---

### Exercice 5.4 ⭐⭐ : Valeur totale de la collection

Crée une fonction `float valeurTotale(Vinyle collection[], int taille)` qui retourne la somme des valeurs estimées.

Crée aussi `float investissementTotal(Vinyle collection[], int taille)` qui retourne la somme des prix d'achat.

**Test dans main** :
```c
int main(void) {
    Vinyle collection[3] = {
        {"Album 1", "Artiste 1", 2000, "Rock", 1, 30.00, 50.00, 0},
        {"Album 2", "Artiste 2", 2005, "Jazz", 2, 25.00, 40.00, 0},
        {"Album 3", "Artiste 3", 2010, "Pop", 3, 20.00, 35.00, 0}
    };
    
    printf("Investissement: %.2f euros\n", investissementTotal(collection, 3));
    printf("Valeur actuelle: %.2f euros\n", valeurTotale(collection, 3));
    return 0;
}
```

**Sortie attendue** :
```
Investissement: 75.00 euros
Valeur actuelle: 125.00 euros
```

---

### Exercice 5.5 ⭐⭐ : Plus-value de la collection

Crée une fonction `void afficherPlusValue(Vinyle collection[], int taille)` qui affiche l'investissement total, la valeur actuelle, et le gain (ou la perte) en euros et en pourcentage.

**Test dans main** :
```c
int main(void) {
    Vinyle collection[3] = {
        {"Album 1", "Artiste 1", 2000, "Rock", 1, 30.00, 50.00, 0},
        {"Album 2", "Artiste 2", 2005, "Jazz", 2, 25.00, 40.00, 0},
        {"Album 3", "Artiste 3", 2010, "Pop", 3, 20.00, 15.00, 0}  // perte !
    };
    
    afficherPlusValue(collection, 3);
    return 0;
}
```

**Sortie attendue** :
```
=== BILAN FINANCIER ===
Investissement total: 75.00 euros
Valeur actuelle: 105.00 euros
Plus-value: +30.00 euros (+40.0%)
```

---

### Exercice 5.6 ⭐⭐ : Filtrer par genre

Crée une fonction `void filtrerParGenre(Vinyle collection[], int taille, char* genre)`.

**Test dans main** :
```c
int main(void) {
    Vinyle collection[4] = {
        {"Album 1", "Artiste 1", 2000, "Rock", 1, 30.00, 50.00, 0},
        {"Album 2", "Artiste 2", 2005, "Jazz", 2, 25.00, 40.00, 0},
        {"Album 3", "Artiste 3", 2010, "Rock", 3, 20.00, 35.00, 0},
        {"Album 4", "Artiste 4", 2015, "Electro", 2, 35.00, 60.00, 0}
    };
    
    printf("=== VINYLES ROCK ===\n");
    filtrerParGenre(collection, 4, "Rock");
    return 0;
}
```

**Sortie attendue** :
```
=== VINYLES ROCK ===
- Album 1 - Artiste 1 (2000)
- Album 3 - Artiste 3 (2010)

2 vinyle(s) Rock dans la collection.
```

---

### Exercice 5.7 ⭐⭐ : Filtrer par artiste

Crée une fonction `void filtrerParArtiste(Vinyle collection[], int taille, char* artiste)`.

**Test dans main** :
```c
int main(void) {
    Vinyle collection[4] = {
        {"Random Access Memories", "Daft Punk", 2013, "Electro", 1, 35.00, 120.00, 1},
        {"Kind of Blue", "Miles Davis", 1959, "Jazz", 2, 40.00, 150.00, 0},
        {"Homework", "Daft Punk", 1997, "Electro", 4, 15.00, 45.00, 0},
        {"Abbey Road", "The Beatles", 1969, "Rock", 3, 28.00, 70.00, 0}
    };
    
    printf("=== VINYLES DE DAFT PUNK ===\n");
    filtrerParArtiste(collection, 4, "Daft Punk");
    return 0;
}
```

**Sortie attendue** :
```
=== VINYLES DE DAFT PUNK ===
- Random Access Memories (2013) - 120.00 euros
- Homework (1997) - 45.00 euros

2 vinyle(s) de Daft Punk. Valeur totale: 165.00 euros
```

---

### Exercice 5.8 ⭐⭐⭐ : Trouver le vinyle le plus précieux

Crée une fonction `Vinyle* plusPrecieux(Vinyle collection[], int taille)` qui retourne un pointeur vers le vinyle ayant la plus haute valeur estimée.

**Test dans main** :
```c
int main(void) {
    Vinyle collection[3] = {
        {"Album 1", "Artiste 1", 2000, "Rock", 1, 30.00, 80.00, 0},
        {"Album 2", "Artiste 2", 2005, "Jazz", 2, 40.00, 150.00, 0},
        {"Album 3", "Artiste 3", 2010, "Pop", 3, 20.00, 55.00, 0}
    };
    
    Vinyle* best = plusPrecieux(collection, 3);
    printf("Vinyle le plus precieux:\n");
    printf("  %s - %s\n", best->titre, best->artiste);
    printf("  Valeur: %.2f euros\n", best->valeur_estimee);
    return 0;
}
```

**Sortie attendue** :
```
Vinyle le plus precieux:
  Album 2 - Artiste 2
  Valeur: 150.00 euros
```

---

### Exercice 5.9 ⭐⭐⭐ : Meilleur investissement

Crée une fonction `Vinyle* meilleurInvestissement(Vinyle collection[], int taille)` qui retourne le vinyle avec le meilleur ratio valeur/prix d'achat.

**Test dans main** :
```c
int main(void) {
    Vinyle collection[3] = {
        {"Album 1", "Artiste 1", 2000, "Rock", 1, 10.00, 50.00, 0},   // x5
        {"Album 2", "Artiste 2", 2005, "Jazz", 2, 40.00, 150.00, 0},  // x3.75
        {"Album 3", "Artiste 3", 2010, "Pop", 3, 20.00, 55.00, 0}     // x2.75
    };
    
    Vinyle* best = meilleurInvestissement(collection, 3);
    float ratio = best->valeur_estimee / best->prix_achat;
    
    printf("Meilleur investissement:\n");
    printf("  %s - %s\n", best->titre, best->artiste);
    printf("  Achat: %.2f -> Valeur: %.2f (x%.2f)\n", 
           best->prix_achat, best->valeur_estimee, ratio);
    return 0;
}
```

**Sortie attendue** :
```
Meilleur investissement:
  Album 1 - Artiste 1
  Achat: 10.00 -> Valeur: 50.00 (x5.00)
```

---

### Exercice 5.10 ⭐⭐ : Compter les éditions limitées

Crée une fonction `int compterEditionsLimitees(Vinyle collection[], int taille)` qui compte les vinyles en édition limitée.

Crée aussi `float valeurEditionsLimitees(Vinyle collection[], int taille)` qui retourne leur valeur totale.

**Test dans main** :
```c
int main(void) {
    Vinyle collection[4] = {
        {"Album 1", "Artiste 1", 2000, "Rock", 1, 35.00, 120.00, 1},
        {"Album 2", "Artiste 2", 2005, "Jazz", 2, 25.00, 80.00, 0},
        {"Album 3", "Artiste 3", 2010, "Pop", 1, 32.00, 55.00, 1},
        {"Album 4", "Artiste 4", 2015, "Rock", 3, 28.00, 70.00, 0}
    };
    
    printf("Editions limitees: %d\n", compterEditionsLimitees(collection, 4));
    printf("Valeur editions limitees: %.2f euros\n", valeurEditionsLimitees(collection, 4));
    return 0;
}
```

**Sortie attendue** :
```
Editions limitees: 2
Valeur editions limitees: 175.00 euros
```

---

### Exercice 5.11 ⭐⭐⭐ : Statistiques par décennie

Crée une fonction `void statsParDecennie(Vinyle collection[], int taille)` qui affiche le nombre de vinyles par décennie (1950s, 1960s, 1970s, etc.).

> **Indication** : Calcule la décennie avec `decennie = (annee / 10) * 10`.
>
> **Exemple** : 1973 / 10 = 197 (division entière) → 197 * 10 = **1970**
>
> Tu peux utiliser une boucle pour parcourir les décennies de 1950 à 2020 et compter les vinyles de chaque décennie, en n'affichant que celles qui ont au moins un vinyle.

**Test dans main** :
```c
int main(void) {
    Vinyle collection[6] = {
        {"A1", "Ar1", 1969, "Rock", 1, 30, 80, 0},
        {"A2", "Ar2", 1973, "Rock", 2, 25, 70, 0},
        {"A3", "Ar3", 1959, "Jazz", 2, 40, 150, 0},
        {"A4", "Ar4", 1997, "Rock", 3, 30, 95, 0},
        {"A5", "Ar5", 2013, "Electro", 1, 35, 120, 1},
        {"A6", "Ar6", 2015, "Hip-Hop", 1, 32, 55, 1}
    };
    
    statsParDecennie(collection, 6);
    return 0;
}
```

**Sortie attendue** :
```
=== REPARTITION PAR DECENNIE ===
1950s: 1 vinyle(s)
1960s: 1 vinyle(s)
1970s: 1 vinyle(s)
1990s: 1 vinyle(s)
2010s: 2 vinyle(s)
```

---

### Exercice 5.12 ⭐⭐⭐ : Programme complet

Crée un programme qui :
1. Initialise la collection de 8 vinyles
2. Affiche toute la collection
3. Affiche le bilan financier (plus-value)
4. Affiche les vinyles Rock
5. Affiche les vinyles de Daft Punk
6. Affiche le vinyle le plus précieux
7. Affiche le meilleur investissement
8. Affiche les statistiques sur les éditions limitées
9. Affiche la répartition par décennie

---

## Projet 6 : Application de covoiturage étudiant

**Notions manipulées** : Structures avec pointeurs internes, tableaux de pointeurs, fonctions de recherche complexes, modifications multiples

### Contexte

Tu crées une application de covoiturage entre étudiants pour les trajets domicile-école ou les week-ends.

### Schéma mémoire : Pointeurs multiples

Ce projet utilise des structures qui contiennent des pointeurs vers d'autres structures. Voici comment cela fonctionne en mémoire :

```
MEMOIRE

┌─────────────────────────────────┐
│           Trajet                │
├─────────────────────────────────┤
│ depart: "Paris"                 │
│ arrivee: "Lyon"                 │
│ date: "15/01/2025"              │
│ ...                             │
│ conducteur: ────────────────────┼───────────┐
│ passagers[4]:                   │           │
│   [0]: ─────────────────────────┼───────┐   │
│   [1]: ─────────────────────────┼───┐   │   │
│   [2]: NULL                     │   │   │   │
│   [3]: NULL                     │   │   │   │
│ nb_passagers: 2                 │   │   │   │
└─────────────────────────────────┘   │   │   │
                                      │   │   │
    ┌─────────────────────────────────┘   │   │
    │   ┌─────────────────────────────────┘   │
    │   │                                     │
    ▼   ▼                                     ▼
┌───────────────┐  ┌───────────────┐  ┌───────────────┐
│  Conducteur   │  │  Conducteur   │  │  Conducteur   │
│    "Emma"     │  │   "Thomas"    │  │    "Lucas"    │
│   (passager)  │  │   (passager)  │  │  (conducteur) │
└───────────────┘  └───────────────┘  └───────────────┘

IMPORTANT : 
- conducteur est UN pointeur vers UNE structure
- passagers est un TABLEAU de pointeurs (chacun pointe vers une structure différente)
- NULL signifie "ne pointe vers rien" (case vide)
```

### Comparaison de pointeurs : Règle d'or

Pour comparer deux pointeurs (vérifier s'ils pointent vers la même structure), on utilise **`==`** directement :

```c
// CORRECT : comparer les adresses mémoire
if (passager == t->conducteur) {
    // Même personne !
}

// ERREUR : strcmp est pour les CHAINES, pas les pointeurs !
if (strcmp(passager, t->conducteur) == 0) {  // CRASH !
```

---

### Exercice 6.1 ⭐ : Définir la structure Conducteur

Crée une structure `Conducteur` contenant :
- Prénom (chaîne de 21 caractères)
- Nom (chaîne de 26 caractères)
- Téléphone (chaîne de 16 caractères)
- Note moyenne sur 5 (nombre décimal)
- Nombre d'avis reçus (entier)
- Nombre de trajets effectués (entier)

**Test dans main** :
```c
int main(void) {
    Conducteur c = {"Lucas", "Martin", "06 12 34 56 78", 4.7, 23, 45};
    
    printf("Conducteur: %s %s\n", c.prenom, c.nom);
    printf("Note: %.1f/5 (%d avis)\n", c.note_moyenne, c.nb_avis);
    printf("Trajets effectues: %d\n", c.trajets_effectues);
    return 0;
}
```

**Sortie attendue** :
```
Conducteur: Lucas Martin
Note: 4.7/5 (23 avis)
Trajets effectues: 45
```

---

### Exercice 6.2 ⭐⭐ : Définir la structure Trajet

Crée une structure `Trajet` contenant :
- Ville de départ (chaîne de 31 caractères)
- Ville d'arrivée (chaîne de 31 caractères)
- Date (chaîne de 12 caractères)
- Heure de départ (chaîne de 7 caractères)
- Nombre de places totales (entier)
- Nombre de places restantes (entier)
- Prix par passager (nombre décimal)
- Pointeur vers le conducteur
- Tableau de pointeurs vers les passagers (maximum 4)
- Nombre de passagers inscrits (entier)

> **Indication** : Les passagers sont aussi de type `Conducteur` (tout utilisateur peut être conducteur ou passager). Le tableau de passagers est `Conducteur* passagers[4]` - c'est un tableau de POINTEURS.

**Test dans main** :
```c
int main(void) {
    Conducteur c = {"Lucas", "Martin", "06 12 34 56 78", 4.7, 23, 45};
    
    Trajet t;
    strcpy(t.depart, "Paris");
    strcpy(t.arrivee, "Lyon");
    strcpy(t.date, "15/01/2025");
    strcpy(t.heure, "08:30");
    t.places_totales = 3;
    t.places_restantes = 3;
    t.prix = 35.00;
    t.conducteur = &c;
    t.nb_passagers = 0;
    
    printf("Trajet: %s -> %s\n", t.depart, t.arrivee);
    printf("Le %s a %s\n", t.date, t.heure);
    printf("Conducteur: %s %s\n", t.conducteur->prenom, t.conducteur->nom);
    printf("Prix: %.2f euros | Places: %d/%d\n", t.prix, t.places_restantes, t.places_totales);
    return 0;
}
```

**Sortie attendue** :
```
Trajet: Paris -> Lyon
Le 15/01/2025 a 08:30
Conducteur: Lucas Martin
Prix: 35.00 euros | Places: 3/3
```

---

### Exercice 6.3 ⭐ : Créer des utilisateurs

Crée un tableau de 5 utilisateurs :

| Prénom | Nom | Téléphone | Note | Avis | Trajets |
|--------|-----|-----------|------|------|---------|
| Lucas | Martin | 06 12 34 56 78 | 4.7 | 23 | 45 |
| Emma | Dubois | 07 98 76 54 32 | 4.5 | 15 | 18 |
| Thomas | Bernard | 06 11 22 33 44 | 3.9 | 8 | 6 |
| Lea | Petit | 07 55 66 77 88 | 4.9 | 42 | 67 |
| Hugo | Moreau | 06 99 88 77 66 | 4.2 | 12 | 20 |

**Test dans main** :
```c
int main(void) {
    Conducteur users[5] = {
        // ... tes initialisations
    };
    
    printf("Utilisateurs inscrits: 5\n");
    for (int i = 0; i < 5; i++) {
        printf("- %s %s (%.1f/5)\n", users[i].prenom, users[i].nom, users[i].note_moyenne);
    }
    return 0;
}
```

**Sortie attendue** :
```
Utilisateurs inscrits: 5
- Lucas Martin (4.7/5)
- Emma Dubois (4.5/5)
- Thomas Bernard (3.9/5)
- Lea Petit (4.9/5)
- Hugo Moreau (4.2/5)
```

---

### Exercice 6.4 ⭐⭐ : Afficher un conducteur

Crée une fonction `void afficherConducteur(Conducteur* c)` qui affiche les infos d'un conducteur.

**Test dans main** :
```c
int main(void) {
    Conducteur c = {"Lucas", "Martin", "06 12 34 56 78", 4.7, 23, 45};
    afficherConducteur(&c);
    return 0;
}
```

**Sortie attendue** :
```
=== Lucas Martin ===
Tel: 06 12 34 56 78
Note: 4.7/5 (23 avis)
Trajets effectues: 45
```

---

### Exercice 6.5 ⭐⭐ : Créer un trajet

Crée une fonction `Trajet creerTrajet(char* depart, char* arrivee, char* date, char* heure, int places, float prix, Conducteur* conducteur)` qui retourne un trajet initialisé sans passagers.

> **Indication** : N'oublie pas d'initialiser `nb_passagers = 0` et `places_restantes = places`. Initialise aussi les pointeurs du tableau `passagers` à NULL.

**Test dans main** :
```c
int main(void) {
    Conducteur c = {"Lucas", "Martin", "06 12 34 56 78", 4.7, 23, 45};
    
    Trajet t = creerTrajet("Paris", "Lyon", "15/01/2025", "08:30", 3, 35.00, &c);
    
    printf("Trajet cree: %s -> %s\n", t.depart, t.arrivee);
    printf("Conducteur: %s\n", t.conducteur->prenom);
    printf("Places: %d | Passagers: %d\n", t.places_restantes, t.nb_passagers);
    return 0;
}
```

**Sortie attendue** :
```
Trajet cree: Paris -> Lyon
Conducteur: Lucas
Places: 3 | Passagers: 0
```

---

### Exercice 6.6 ⭐⭐ : Afficher un trajet

Crée une fonction `void afficherTrajet(Trajet* t)` qui affiche les détails d'un trajet.

**Test dans main** :
```c
int main(void) {
    Conducteur c = {"Lucas", "Martin", "06 12 34 56 78", 4.7, 23, 45};
    Trajet t = creerTrajet("Paris", "Lyon", "15/01/2025", "08:30", 3, 35.00, &c);
    
    afficherTrajet(&t);
    return 0;
}
```

**Sortie attendue** :
```
=== TRAJET ===
Paris -> Lyon
Date: 15/01/2025 a 08:30
Conducteur: Lucas Martin (4.7/5)
Prix: 35.00 euros/personne
Places disponibles: 3/3
```

---

### Exercice 6.7 ⭐⭐⭐ : Réserver une place

Crée une fonction `int reserverPlace(Trajet* t, Conducteur* passager)` qui :
- Vérifie qu'il reste des places
- Vérifie que le passager n'est pas le conducteur
- Vérifie que le passager n'est pas déjà inscrit
- Ajoute le passager et décrémente les places
- Retourne 1 si succès, 0 sinon

> **Indication importante** : Pour comparer si deux personnes sont identiques, on compare les POINTEURS (les adresses), pas les contenus :
> ```c
> // Le passager est-il le conducteur ?
> if (passager == t->conducteur) return 0;  // Meme adresse = meme personne
>
> // Le passager est-il deja inscrit ?
> for (int i = 0; i < t->nb_passagers; i++) {
>     if (t->passagers[i] == passager) return 0;  // Deja dans la liste
> }
> ```
>
> On utilise `==` car on compare des adresses mémoire, PAS `strcmp` qui est réservé aux chaînes de caractères !

**Test dans main** :
```c
int main(void) {
    Conducteur users[3] = {
        {"Lucas", "Martin", "06 12", 4.7, 23, 45},
        {"Emma", "Dubois", "07 98", 4.5, 15, 18},
        {"Thomas", "Bernard", "06 11", 3.9, 8, 6}
    };
    
    Trajet t = creerTrajet("Paris", "Lyon", "15/01/2025", "08:30", 2, 35.00, &users[0]);
    
    printf("Places avant: %d\n", t.places_restantes);
    
    int r1 = reserverPlace(&t, &users[1]);  // Emma reserve
    printf("Emma reserve: %d (1=OK)\n", r1);
    
    int r2 = reserverPlace(&t, &users[0]);  // Lucas = conducteur
    printf("Lucas reserve: %d (1=OK)\n", r2);
    
    int r3 = reserverPlace(&t, &users[1]);  // Emma deja inscrite
    printf("Emma encore: %d (1=OK)\n", r3);
    
    int r4 = reserverPlace(&t, &users[2]);  // Thomas reserve
    printf("Thomas reserve: %d (1=OK)\n", r4);
    
    printf("Places apres: %d\n", t.places_restantes);
    printf("Passagers: %d\n", t.nb_passagers);
    return 0;
}
```

**Sortie attendue** :
```
Places avant: 2
Emma reserve: 1 (1=OK)
Lucas reserve: 0 (1=OK)
Emma encore: 0 (1=OK)
Thomas reserve: 1 (1=OK)
Places apres: 0
Passagers: 2
```

---

### Exercice Bonus 6.7b ⭐⭐⭐ : Trouve le bug !

Le code suivant ne fonctionne pas. Trouve l'erreur :

```c
int reserverPlace(Trajet* t, Conducteur* passager) {
    if (t->places_restantes <= 0) return 0;
    
    // Verifier si c'est le conducteur
    if (strcmp(passager->nom, t->conducteur->nom) == 0) {  // BUG !
        return 0;
    }
    
    // ... suite du code
}
```

<details>
<summary>Voir la solution</summary>

**Problème** : On utilise `strcmp` pour comparer des noms, mais deux personnes différentes peuvent avoir le même nom ! De plus, on compare des structures via pointeurs, pas des chaînes.

**Exemple** : Si "Thomas Martin" veut réserver un trajet conduit par "Lucas Martin", la comparaison des noms (`strcmp("Martin", "Martin") == 0`) retournerait vrai et le bloquerait à tort !

**Solution** : Comparer les adresses mémoire directement :
```c
if (passager == t->conducteur) {  // Meme ADRESSE = meme personne
    return 0;
}
```

</details>

---

### Exercice 6.8 ⭐⭐⭐ : Annuler une réservation

Crée une fonction `int annulerReservation(Trajet* t, Conducteur* passager)` qui :
- Cherche le passager dans la liste
- Le retire (décale les autres pointeurs)
- Incrémente les places restantes
- Retourne 1 si trouvé et retiré, 0 sinon

> **Indication** : Pour retirer un élément d'un tableau, il faut décaler tous les éléments suivants vers la gauche :
> ```c
> // Supprimer l'element a l'index i
> for (int j = i; j < t->nb_passagers - 1; j++) {
>     t->passagers[j] = t->passagers[j + 1];
> }
> t->passagers[t->nb_passagers - 1] = NULL;
> t->nb_passagers--;
> ```

**Test dans main** :
```c
int main(void) {
    Conducteur users[3] = {
        {"Lucas", "Martin", "06 12", 4.7, 23, 45},
        {"Emma", "Dubois", "07 98", 4.5, 15, 18},
        {"Thomas", "Bernard", "06 11", 3.9, 8, 6}
    };
    
    Trajet t = creerTrajet("Paris", "Lyon", "15/01/2025", "08:30", 3, 35.00, &users[0]);
    reserverPlace(&t, &users[1]);  // Emma
    reserverPlace(&t, &users[2]);  // Thomas
    
    printf("Passagers avant: %d, Places: %d\n", t.nb_passagers, t.places_restantes);
    
    int r = annulerReservation(&t, &users[1]);  // Emma annule
    printf("Emma annule: %d (1=OK)\n", r);
    
    printf("Passagers apres: %d, Places: %d\n", t.nb_passagers, t.places_restantes);
    printf("Passager restant: %s\n", t.passagers[0]->prenom);
    return 0;
}
```

**Sortie attendue** :
```
Passagers avant: 2, Places: 1
Emma annule: 1 (1=OK)
Passagers apres: 1, Places: 2
Passager restant: Thomas
```

---

### Exercice 6.9 ⭐⭐ : Afficher les passagers

Crée une fonction `void afficherPassagers(Trajet* t)` qui liste les passagers inscrits.

**Test dans main** :
```c
int main(void) {
    Conducteur users[3] = {
        {"Lucas", "Martin", "06 12 34 56 78", 4.7, 23, 45},
        {"Emma", "Dubois", "07 98 76 54 32", 4.5, 15, 18},
        {"Thomas", "Bernard", "06 11 22 33 44", 3.9, 8, 6}
    };
    
    Trajet t = creerTrajet("Paris", "Lyon", "15/01/2025", "08:30", 3, 35.00, &users[0]);
    reserverPlace(&t, &users[1]);
    reserverPlace(&t, &users[2]);
    
    afficherPassagers(&t);
    return 0;
}
```

**Sortie attendue** :
```
=== PASSAGERS (2/3) ===
1. Emma Dubois (4.5/5)
2. Thomas Bernard (3.9/5)

1 place(s) restante(s).
```

---

### Exercice 6.10 ⭐⭐ : Rechercher des trajets

Crée une fonction `void rechercherTrajets(Trajet trajets[], int nb_trajets, char* depart, char* arrivee)` qui affiche les trajets correspondants avec des places disponibles.

**Test dans main** :
```c
int main(void) {
    Conducteur c1 = {"Lucas", "Martin", "06 12", 4.7, 23, 45};
    Conducteur c2 = {"Emma", "Dubois", "07 98", 4.5, 15, 18};
    
    Trajet trajets[3] = {
        creerTrajet("Paris", "Lyon", "15/01/2025", "08:30", 3, 35.00, &c1),
        creerTrajet("Paris", "Marseille", "15/01/2025", "09:00", 2, 45.00, &c2),
        creerTrajet("Paris", "Lyon", "16/01/2025", "07:00", 4, 32.00, &c2)
    };
    
    printf("=== Recherche Paris -> Lyon ===\n");
    rechercherTrajets(trajets, 3, "Paris", "Lyon");
    
    printf("\n=== Recherche Paris -> Bordeaux ===\n");
    rechercherTrajets(trajets, 3, "Paris", "Bordeaux");
    return 0;
}
```

**Sortie attendue** :
```
=== Recherche Paris -> Lyon ===
- 15/01/2025 a 08:30 | Lucas Martin (4.7/5) | 35.00 euros | 3 places
- 16/01/2025 a 07:00 | Emma Dubois (4.5/5) | 32.00 euros | 4 places

2 trajet(s) trouve(s).

=== Recherche Paris -> Bordeaux ===
Aucun trajet trouve pour Paris -> Bordeaux.
```

---

### Exercice 6.11 ⭐⭐⭐ : Noter un conducteur

Crée une fonction `void noterConducteur(Conducteur* c, int note)` qui :
- Met à jour la note moyenne (moyenne pondérée)
- Incrémente le nombre d'avis

> **Indication** : Nouvelle moyenne = (ancienne_moyenne × nb_avis + nouvelle_note) / (nb_avis + 1)

**Test dans main** :
```c
int main(void) {
    Conducteur c = {"Lucas", "Martin", "06 12", 4.0, 10, 20};
    
    printf("Avant: %.2f/5 (%d avis)\n", c.note_moyenne, c.nb_avis);
    
    noterConducteur(&c, 5);  // Nouvelle note de 5
    
    printf("Apres note de 5: %.2f/5 (%d avis)\n", c.note_moyenne, c.nb_avis);
    return 0;
}
```

**Sortie attendue** :
```
Avant: 4.00/5 (10 avis)
Apres note de 5: 4.09/5 (11 avis)
```

---

### Exercice 6.12 ⭐⭐ : Filtrer par note minimum

Crée une fonction `void filtrerParNote(Trajet trajets[], int nb_trajets, float note_min)` qui affiche les trajets dont le conducteur a une note >= note_min.

**Test dans main** :
```c
int main(void) {
    Conducteur c1 = {"Lucas", "Martin", "06 12", 4.7, 23, 45};
    Conducteur c2 = {"Emma", "Dubois", "07 98", 4.2, 15, 18};
    Conducteur c3 = {"Thomas", "Bernard", "06 11", 3.8, 8, 6};
    
    Trajet trajets[3] = {
        creerTrajet("Paris", "Lyon", "15/01/2025", "08:30", 3, 35.00, &c1),
        creerTrajet("Paris", "Marseille", "15/01/2025", "09:00", 2, 45.00, &c2),
        creerTrajet("Lyon", "Nice", "16/01/2025", "10:00", 4, 40.00, &c3)
    };
    
    printf("=== Conducteurs notes >= 4.5 ===\n");
    filtrerParNote(trajets, 3, 4.5);
    return 0;
}
```

**Sortie attendue** :
```
=== Conducteurs notes >= 4.5 ===
- Paris -> Lyon | Lucas Martin (4.7/5) | 35.00 euros

1 trajet(s) avec conducteur note >= 4.5/5.
```

---

### Exercice 6.13 ⭐⭐⭐ : Programme complet

Crée un programme de covoiturage complet qui :
1. Crée 5 utilisateurs
2. Crée 4 trajets avec différents conducteurs
3. Affiche tous les trajets disponibles
4. Effectue quelques réservations
5. Affiche les passagers d'un trajet
6. Recherche des trajets Paris -> Lyon
7. Filtre les trajets avec conducteur noté >= 4.5
8. Note un conducteur après un trajet
9. Affiche les statistiques globales (nombre de trajets, places totales, etc.)

---