#include <stdio.h>
#include <stdlib.h>  // rand, srand
#include <time.h>    // time

// Pierre–Feuille–Ciseaux — une seule manche, sans boucles, sans tableaux, sans fonctions perso.
int main(void) {
    char joueur;
    char bot;

    printf("Bienvenue dans Pierre–Feuille–Ciseaux !\n");
    printf("Entrez votre coup [P/F/C] : ");

    if (scanf(" %c", &joueur) != 1) {
        printf("Lecture impossible.\n");
        return 1;
    }

    // Normalisation min -> maj (sans toupper, juste des if/else)
    if (joueur == 'p') joueur = 'P';
    else if (joueur == 'f') joueur = 'F';
    else if (joueur == 'c') joueur = 'C';

    // Validation
    if (joueur != 'P' && joueur != 'F' && joueur != 'C') {
        printf("Entrée invalide : utilisez P, F ou C.\n");
        return 1;
    }

    // =====================
    // Partie ALÉATOIRE (expliquée)
    // =====================
    // 1) On "sème" (seed) le générateur pseudo-aléatoire avec l'heure courante.
    //    Même graine => même suite; graine différente => suite différente.
    //    On le fait UNE SEULE FOIS au lancement du programme.
    srand((unsigned) time(NULL));

    // 2) On tire un entier pseudo-aléatoire quelconque puis on le réduit à 0, 1 ou 2
    //    grâce à l'opérateur modulo.
    int n = rand() % 3; // valeurs possibles : 0, 1, 2

    // 3) On traduit 0/1/2 en 'P'/'F'/'C' avec des if/else (pas de tableau, pas de switch)
    if (n == 0) bot = 'P';
    else if (n == 1) bot = 'F';
    else bot = 'C';

    // (Note) Le modulo peut introduire un léger biais théorique quand RAND_MAX+1 n'est pas multiple de 3;
    //        pour un mini‑jeu d'initiation, c'est acceptable.

    // Affichage des coups en toutes lettres (sans fonction)
    printf("Vous : ");
    if (joueur == 'P') printf("pierre");
    else if (joueur == 'F') printf("feuille");
    else printf("ciseaux");

    printf(" | Bot : ");
    if (bot == 'P') printf("pierre");
    else if (bot == 'F') printf("feuille");
    else printf("ciseaux");
    printf("\n");

    // Détermination du résultat (uniquement avec des if/else)
    if (joueur == bot) {
        printf("Résultat : égalité.\n");
    } else if (joueur == 'P' && bot == 'C') {
        printf("Résultat : vous gagnez (pierre casse ciseaux).\n");
    } else if (joueur == 'F' && bot == 'P') {
        printf("Résultat : vous gagnez (feuille couvre pierre).\n");
    } else if (joueur == 'C' && bot == 'F') {
        printf("Résultat : vous gagnez (ciseaux coupent feuille).\n");
    } else {
        printf("Résultat : vous perdez.\n");
    }

    return 0;
}