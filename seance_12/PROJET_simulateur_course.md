# Simulateur de Course 🏎️

À vos marques, prêts, partez ! En utilisant les structures et vos connaissances en C, nous allons créer un simulateur de course.

**Objectifs du projet :**
- Définir des types de données complexes avec des structures et `typedef`
- Créer des fonctions d'affichage pour informer le public
- Implémenter la logique de course avec des pointeurs de structures
- Utiliser la génération de nombres aléatoires

---

## Partie 1 : Préparation de la course

### Mise en place du projet

**Exercice 1.1** : Créez un nouveau fichier `simulateur_course.c` et copiez-collez le code de départ suivant :

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ============ STRUCTURES ============


// ============ FONCTIONS D'AFFICHAGE ============


// ============ FONCTIONS LOGIQUES ============


// ============ MAIN ============
int main(void) {
    // Initialisation du générateur aléatoire (à faire UNE SEULE FOIS)
    srand(time(0));

    return 0;
}
```

### Création des structures

**Exercice 1.2** : Dans la section `STRUCTURES`, créez une structure `Course` **avec typedef** contenant les variables membres suivantes :

| Variable | Type | Description |
|----------|------|-------------|
| `nombre_tours` | `int` | Nombre total de tours dans la course |
| `tour_courant` | `int` | Numéro du tour en cours |
| `nom_pilote_premier` | `char[50]` | Nom du pilote en tête |
| `couleur_voiture_premier` | `char[20]` | Couleur de la voiture en tête |

> 💡 **Indice** : Utilisez la syntaxe `typedef struct { ... } Course;` pour pouvoir ensuite déclarer des variables avec simplement `Course maCourse;`

---

**Exercice 1.3** : Toujours dans la section `STRUCTURES`, créez une structure `VoitureCourse` **avec typedef** contenant :

| Variable | Type | Description |
|----------|------|-------------|
| `nom_pilote` | `char[50]` | Nom du pilote |
| `couleur_voiture` | `char[20]` | Couleur de la voiture |
| `temps_total` | `int` | Temps total cumulé (en secondes) |

> 💡 **Indice** : Cette structure représente une voiture et son pilote. Le `temps_total` s'accumulera au fil des tours — le pilote avec le temps le plus bas sera en tête !

---

## Partie 2 : Fonctions d'affichage

Chaque course a besoin d'une bonne ambiance ! Créons les fonctions qui vont informer et divertir notre public.

### Introduction de la course

**Exercice 2.1** : Dans la section `FONCTIONS D'AFFICHAGE`, créez une fonction `afficher_intro()` qui ne prend aucun paramètre et ne retourne rien.

Cette fonction doit afficher un message d'introduction fun pour la course.

> 💡 **Indice** : Utilisez plusieurs `printf()` pour créer une intro stylée. Soyez créatifs !
>
> ✅ **Exemple de sortie possible** :
> ```
> ╔════════════════════════════════════════╗
> ║   BIENVENUE AU GRAND PRIX SIMULATEUR  ║
> ╚════════════════════════════════════════╝
> Attachez vos ceintures, ça va décoiffer !
> ```

**Exercice 2.2** : Appelez `afficher_intro()` dans `main()` pour tester votre fonction.

---

### Compte à rebours

**Exercice 2.3** : Créez une fonction `afficher_compte_a_rebours()` qui affiche un compte à rebours dramatique avant le départ.

> 💡 **Indice** : Utilisez une boucle `for` pour compter de 5 à 1, puis affichez "GO !"
>
> ✅ **Sortie attendue** :
> ```
> Les pilotes sont prêts...
> 5...
> 4...
> 3...
> 2...
> 1...
> 🏁 GO GO GO ! 🏁
> ```

**Exercice 2.4** : Appelez cette fonction dans `main()` après l'intro pour tester.

---

### Annonce du leader

**Exercice 2.5** : Créez une fonction `afficher_leader_tour()` qui prend en paramètres :
- `course` : une `Course` (passage par valeur)
- `temps1` : un `int` représentant le temps total de la voiture 1
- `temps2` : un `int` représentant le temps total de la voiture 2

La fonction doit afficher :
- Le numéro du tour courant
- Les temps totaux des deux voitures
- Le nom du pilote en première place et la couleur de sa voiture

> 💡 **Indice** : Accédez aux membres de la structure avec la notation par points (`.`) puisque c'est un passage par valeur.
>
> ✅ **Exemple de sortie** :
> ```
> 📍 Fin du tour 3
>    Max: 245s | Lewis: 251s
>    En tête : Max dans la voiture ROUGE !
> ```

---

### Félicitations au vainqueur

**Exercice 2.6** : Créez une fonction `afficher_vainqueur()` qui prend en paramètres :
- `course` : une `Course` (passage par valeur)
- `temps1` : temps final de la voiture 1
- `temps2` : temps final de la voiture 2

La fonction affiche un message de félicitations avec le temps final du gagnant.

> 💡 **Indice** : Cette fonction sera appelée à la fin de la course. Faites quelque chose de mémorable !
>
> ✅ **Exemple de sortie** :
> ```
> 🏆🏆🏆 COURSE TERMINÉE ! 🏆🏆🏆
> 
> Le grand vainqueur est : Lewis
> Au volant de la voiture NOIRE !
> Temps final : 487 secondes
> 
> Merci à tous et à la prochaine !
> ```

---

### Exercice intermédiaire : Tester l'affichage du leader

Avant de passer à la logique de course, testons notre fonction `afficher_leader_tour()`.

**Exercice 2.7** : Dans `main()`, après le compte à rebours :

1. Créez une variable `Course` temporaire nommée `testCourse` avec :
   - 5 tours
   - Tour courant = 2
   - Pilote premier = "TestPilote"
   - Couleur premier = "BLEU"

2. Appelez `afficher_leader_tour(testCourse, 180, 195)` pour simuler un affichage

> 💡 **Indice** : Cet exercice vous permet de vérifier que votre fonction d'affichage fonctionne correctement AVANT de l'intégrer dans la logique de course.
>
> ✅ **Sortie attendue** :
> ```
> 📍 Fin du tour 2
>    TestPilote: 180s | (autre): 195s
>    En tête : TestPilote dans la voiture BLEU !
> ```
>
> ⚠️ **Note** : Vous pouvez supprimer ou commenter ce test une fois qu'il fonctionne.

---

## Partie 3 : Logique de la course

C'est ici que la magie opère ! Nous allons créer les fonctions qui gèrent le déroulement de la course.

---

### 📌 Rappel : rand() et nombres aléatoires

Avant de continuer, un petit rappel sur la génération de nombres aléatoires en C :

```c
// rand() génère un entier "aléatoire" entre 0 et RAND_MAX

// Pour obtenir un nombre entre min et max (inclus) :
int nombre = rand() % (max - min + 1) + min;

// Exemple : nombre entre 60 et 120
int temps = rand() % (120 - 60 + 1) + 60;  // ou simplement : rand() % 61 + 60

// IMPORTANT : srand(time(0)) initialise le générateur
// À faire UNE SEULE FOIS au début de main() !
```

**Pourquoi `srand(time(0))` ?**
- Sans cette initialisation, `rand()` génère toujours la même séquence de nombres
- `time(0)` donne le temps actuel en secondes, donc une "graine" différente à chaque exécution
- Résultat : des valeurs vraiment différentes à chaque fois qu'on lance le programme

---

### Calcul du temps au tour

**Exercice 3.1** : Créez une fonction `calculer_temps_tour()` qui ne prend aucun paramètre et retourne un `int`.

Cette fonction doit générer un temps aléatoire entre **60 et 120 secondes** représentant le temps pour compléter un tour.

> 💡 **Indice** : Utilisez la formule `rand() % (max - min + 1) + min` avec min=60 et max=120

---

### Mise à jour d'une voiture

**Exercice 3.2** : Créez une fonction `maj_voiture()` qui prend un **pointeur** vers une `VoitureCourse` en paramètre et ne retourne rien.

Cette fonction doit :
1. Appeler `calculer_temps_tour()` pour obtenir le temps du tour
2. Ajouter ce temps au `temps_total` de la voiture

> 💡 **Indice** : Utilisez la notation fléchée (`->`) pour accéder aux membres via le pointeur. Par exemple : `voiture->temps_total`
>
> ⚠️ **Question à se poser** : Pourquoi utilise-t-on un pointeur ici plutôt qu'un passage par valeur ?

---

### Exercice intermédiaire : Tester la mise à jour

**Exercice 3.3** : Avant de créer `lancer_course()`, testons `maj_voiture()` :

Dans `main()`, créez une `VoitureCourse` temporaire et testez :

```c
VoitureCourse test = {"Pilote Test", "VERT", 0};
printf("Temps avant: %d\n", test.temps_total);
maj_voiture(&test);  // N'oubliez pas le & !
printf("Temps apres: %d\n", test.temps_total);
```

> ✅ **Sortie attendue** (les valeurs varieront) :
> ```
> Temps avant: 0
> Temps apres: 87
> ```
>
> ⚠️ Commentez ou supprimez ce test une fois validé.

---

### Fonction principale de course

**Exercice 3.4** : Créez une fonction `lancer_course()` avec les paramètres suivants :
- `course` : pointeur vers une `Course`
- `voiture1` : pointeur vers une `VoitureCourse`
- `voiture2` : pointeur vers une `VoitureCourse`

Cette fonction doit :

1. **Boucler** sur chaque tour (de 1 jusqu'à `nombre_tours`)
2. **À chaque tour** :
   - Mettre à jour le `tour_courant` de la course
   - Appeler `maj_voiture()` pour chaque voiture
   - Comparer les `temps_total` des deux voitures (⚠️ gérer l'égalité !)
   - Copier le nom et la couleur du leader dans la structure `Course`
   - Appeler `afficher_leader_tour()` pour annoncer le résultat

> 💡 **Indices** :
> - Pour la boucle : `for (course->tour_courant = 1; course->tour_courant <= course->nombre_tours; course->tour_courant++)`
> - Pour comparer : celui qui a le **plus petit** temps total est en tête
> - **En cas d'égalité** : vous pouvez garder le leader actuel ou choisir arbitrairement
> - Pour copier des chaînes : utilisez `strcpy(destination, source)`
> - Pour passer la structure à `afficher_leader_tour()` : **déréférencez avec `*course`**
>
> 📝 **Structure du code** :
> ```
> pour chaque tour:
>     mettre à jour voiture1
>     mettre à jour voiture2
>     
>     si temps_voiture1 < temps_voiture2:
>         copier infos de voiture1 dans course
>     sinon si temps_voiture2 < temps_voiture1:
>         copier infos de voiture2 dans course
>     sinon:
>         // Égalité ! On peut garder le leader actuel
>         // ou afficher un message spécial
>     
>     afficher le leader du tour (avec les temps !)
> ```

---

### ⚠️ Erreurs courantes dans cette partie

Voici les erreurs que vous risquez de rencontrer et comment les corriger :

#### Erreur 1 : Utiliser `.` au lieu de `->` avec un pointeur

```c
// ❌ INCORRECT
course.tour_courant = 1;

// ✅ CORRECT (course est un pointeur)
course->tour_courant = 1;
```

**Message du compilateur :**
```
error: request for member 'tour_courant' in 'course', which is of pointer type 'Course *'
note: perhaps you meant to use '->' ?
```

---

#### Erreur 2 : Oublier de déréférencer pour passer par valeur

```c
// ❌ INCORRECT (afficher_leader_tour attend une Course, pas un Course*)
afficher_leader_tour(course, temps1, temps2);

// ✅ CORRECT (on déréférence le pointeur)
afficher_leader_tour(*course, temps1, temps2);
```

**Message du compilateur :**
```
error: incompatible type for argument 1 of 'afficher_leader_tour'
note: expected 'Course' but argument is of type 'Course *'
```

---

#### Erreur 3 : Oublier le `&` dans l'appel de fonction

```c
// ❌ INCORRECT (maj_voiture attend un pointeur)
maj_voiture(voiture1);

// ✅ CORRECT quand voiture1 est une variable directe
maj_voiture(&voiture1);

// ✅ CORRECT quand voiture1 est DÉJÀ un pointeur
maj_voiture(voiture1);  // Pas de & car c'est déjà une adresse
```

**Message du compilateur :**
```
error: incompatible type for argument 1 of 'maj_voiture'
note: expected 'VoitureCourse *' but argument is of type 'VoitureCourse'
```

---

#### Erreur 4 : Copier des chaînes avec `=`

```c
// ❌ INCORRECT (on ne peut pas copier un tableau avec =)
course->nom_pilote_premier = voiture1->nom_pilote;

// ✅ CORRECT (utiliser strcpy)
strcpy(course->nom_pilote_premier, voiture1->nom_pilote);
```

**Message du compilateur :**
```
error: assignment to expression with array type
```

---

#### Mémo rapide

| Situation | Code correct |
|-----------|--------------|
| Accéder via pointeur | `ptr->membre` |
| Accéder via variable | `var.membre` |
| Passer pointeur à fonction (var directe) | `fonction(&var)` |
| Passer pointeur à fonction (déjà pointeur) | `fonction(ptr)` |
| Passer valeur depuis pointeur | `fonction(*ptr)` |
| Copier une chaîne | `strcpy(dest, src)` |

---

## Partie 4 : Lancement de la simulation

Il est temps d'assembler tous les morceaux !

**Exercice 4.1** : Dans la fonction `main()`, après l'initialisation du générateur aléatoire :

1. **Créez une variable `Course`** initialisée avec :
   - 5 tours
   - Tour courant à 0
   - Chaînes vides pour le leader (utilisez `""`)

2. **Créez deux variables `VoitureCourse`** :

   | Voiture | Pilote | Couleur | Temps initial |
   |---------|--------|---------|---------------|
   | `voiture1` | Un nom de votre choix | Une couleur | 0 |
   | `voiture2` | Un autre nom | Une autre couleur | 0 |

> 💡 **Indice** : Utilisez la notation ordonnée pour initialiser. Exemple :
> ```c
> VoitureCourse voiture1 = {"Max", "ROUGE", 0};
> ```

---

**Exercice 4.2** : Toujours dans `main()`, orchestrez la course en appelant les fonctions dans l'ordre :

1. Afficher l'introduction
2. Afficher le compte à rebours
3. Lancer la course (n'oubliez pas de passer des **pointeurs** avec `&` !)
4. Afficher le vainqueur (avec les temps finaux)

> 💡 **Indice** : Pour passer des pointeurs, utilisez l'opérateur `&` devant vos variables :
> ```c
> lancer_course(&course, &voiture1, &voiture2);
> ```
>
> ⚠️ N'oubliez pas de passer les temps finaux à `afficher_vainqueur()` !

---

> ✅ **Exemple de déroulement complet** :
> ```
> ╔════════════════════════════════════════╗
> ║   BIENVENUE AU GRAND PRIX SIMULATEUR  ║
> ╚════════════════════════════════════════╝
> Attachez vos ceintures, ça va décoiffer !
> 
> Les pilotes sont prêts...
> 5...
> 4...
> 3...
> 2...
> 1...
> 🏁 GO GO GO ! 🏁
> 
> 📍 Fin du tour 1
>    Max: 78s | Lewis: 95s
>    En tête : Max dans la voiture ROUGE !
> 
> 📍 Fin du tour 2
>    Max: 167s | Lewis: 158s
>    En tête : Lewis dans la voiture NOIRE !
> 
> 📍 Fin du tour 3
>    Max: 228s | Lewis: 239s
>    En tête : Max dans la voiture ROUGE !
> 
> 📍 Fin du tour 4
>    Max: 312s | Lewis: 305s
>    En tête : Lewis dans la voiture NOIRE !
> 
> 📍 Fin du tour 5
>    Max: 389s | Lewis: 378s
>    En tête : Lewis dans la voiture NOIRE !
> 
> 🏆🏆🏆 COURSE TERMINÉE ! 🏆🏆🏆
> 
> Le grand vainqueur est : Lewis
> Au volant de la voiture NOIRE !
> Temps final : 378 secondes
> 
> Merci à tous et à la prochaine !
> ```

---

## Bonus : Améliorations possibles 🚀

Si vous avez terminé et qu'il vous reste du temps, voici quelques idées pour améliorer votre simulateur :

### Niveau 1 : Facile
1. **Affichage de l'écart** : Montrez la différence de temps entre les deux voitures à chaque tour
2. **Message d'égalité** : Affichez un message spécial si les deux voitures ont exactement le même temps

### Niveau 2 : Intermédiaire
3. **Plus de voitures** : Modifiez le code pour gérer 4 voitures ou plus (utilisez un tableau de `VoitureCourse`)
4. **Incidents de course** : Ajoutez une chance aléatoire (10%) qu'une voiture ait un problème mécanique (+30 secondes)

### Niveau 3 : Avancé
5. **Météo** : Créez une structure `Meteo` qui change aléatoirement et affecte les temps
6. **Classement complet** : À la fin de la course, affichez le classement de toutes les voitures avec leurs temps
7. **Sauvegarde** : Enregistrez les résultats dans un fichier texte

### Niveau 4 : Expert
8. **Mode championnat** : Plusieurs courses avec un système de points
9. **Pit stops** : Possibilité de faire un arrêt au stand qui prend du temps mais réduit les temps des tours suivants

---

## Récapitulatif des fonctions à créer

| Fonction | Paramètres | Retour | Description |
|----------|------------|--------|-------------|
| `afficher_intro` | aucun | `void` | Affiche l'intro de la course |
| `afficher_compte_a_rebours` | aucun | `void` | Compte à rebours 5-4-3-2-1-GO |
| `afficher_leader_tour` | `Course`, `int`, `int` | `void` | Annonce le leader avec les temps |
| `afficher_vainqueur` | `Course`, `int`, `int` | `void` | Félicite le gagnant avec temps final |
| `calculer_temps_tour` | aucun | `int` | Retourne un temps aléatoire (60-120s) |
| `maj_voiture` | `VoitureCourse*` | `void` | Met à jour le temps total |
| `lancer_course` | `Course*`, `VoitureCourse*`, `VoitureCourse*` | `void` | Gère le déroulement de la course |

---

## Résumé des concepts utilisés

| Concept | Utilisation dans ce TP |
|---------|----------------------|
| `typedef struct` | Définition de `Course` et `VoitureCourse` |
| Notation par points `.` | Accès aux membres (passage par valeur) |
| Notation fléchée `->` | Accès aux membres via pointeur |
| Passage par pointeur | `maj_voiture()`, `lancer_course()` |
| Déréférencement `*` | Passer `*course` à une fonction attendant une valeur |
| `strcpy()` | Copier le nom/couleur du leader |
| `rand()` et `srand()` | Générer des temps aléatoires |

Bonne course ! 🏁