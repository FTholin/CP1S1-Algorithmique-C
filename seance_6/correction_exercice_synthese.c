#include <stdio.h>

int main() {
    // Tableau des scores de 5 joueurs
    int scores[5] = {120, 95, 150, 88, 200};
    
    printf("=== GESTIONNAIRE DE SCORES ===\n\n");
    
    
    // ========================================
    // ÉTAPE 1 : Créer un pointeur vers les scores
    // ========================================
    
    // CORRECTION :
    int* ptr = &scores[0];
    
    /* EXPLICATION DÉTAILLÉE :
     * - int*      : Type du pointeur (pointeur vers un entier)
     * - ptr       : Nom de notre pointeur
     * - &scores[0]: Adresse du premier élément du tableau
     * 
     * Pourquoi int* ? Car le tableau contient des int
     * Le symbole & signifie "adresse de"
     * scores[0] est le premier élément (valeur 120)
     * &scores[0] est l'adresse mémoire où est stocké 120
     */
    
    printf("ETAPE 1 - Pointeur cree\n");
    printf("Adresse du premier score : %p\n", ptr);
    // %p est le format pour afficher une adresse (pointer)
    
    printf("Valeur du premier score : %d\n\n", *ptr);
    // *ptr déréférence le pointeur = donne la valeur à cette adresse
    // Ici *ptr vaut 120
    
    
    // ========================================
    // ÉTAPE 2 : Afficher tous les scores avec le pointeur
    // ========================================
    
    printf("ETAPE 2 - Affichage des scores\n");
    
    // CORRECTION :
    ptr = &scores[0];  // On remet ptr au début (important !)
    
    for(int i = 0; i < 5; i++) {
        printf("Joueur %d : %d points\n", i+1, *ptr);
        ptr++;  // Avance au score suivant
    }
    
    /* EXPLICATION DÉTAILLÉE DE LA BOUCLE :
     * 
     * Itération 1 (i=0):
     *   - ptr pointe vers scores[0] (120)
     *   - *ptr vaut 120
     *   - Affiche "Joueur 1 : 120 points"
     *   - ptr++ fait que ptr pointe maintenant vers scores[1]
     * 
     * Itération 2 (i=1):
     *   - ptr pointe vers scores[1] (95)
     *   - *ptr vaut 95
     *   - Affiche "Joueur 2 : 95 points"
     *   - ptr++ fait que ptr pointe maintenant vers scores[2]
     * 
     * Et ainsi de suite...
     * 
     * IMPORTANT : ptr++ ne fait pas +1 à l'adresse !
     * Il avance de sizeof(int) octets (généralement 4 octets)
     * pour pointer vers le prochain int du tableau
     */
    
    printf("\n");
    
    
    // ========================================
    // ÉTAPE 3 : Modifier un score avec un pointeur
    // ========================================
    
    printf("ETAPE 3 - Bonus pour le joueur 3\n");
    
    // CORRECTION :
    ptr = &scores[2];  // Pointe vers le joueur 3 (indice 2)
    
    /* EXPLICATION :
     * Joueur 1 = scores[0]
     * Joueur 2 = scores[1]
     * Joueur 3 = scores[2] ← C'est celui-ci !
     */
    
    printf("Score avant bonus : %d\n", *ptr);
    // Affiche 150 (la valeur actuelle de scores[2])
    
    *ptr += 50;  // Ajoute 50 à la valeur pointée
    
    /* EXPLICATION DE *ptr += 50 :
     * *ptr        : valeur à l'adresse ptr (150)
     * *ptr += 50  : équivaut à *ptr = *ptr + 50
     *             : donc *ptr = 150 + 50 = 200
     * 
     * IMPORTANT : On modifie la valeur dans le tableau !
     * scores[2] vaut maintenant 200 au lieu de 150
     */
    
    printf("Score apres bonus : %d\n\n", *ptr);
    // Affiche 200
    
    
    // ========================================
    // ÉTAPE 4 : Calculer la somme avec arithmétique de pointeurs
    // ========================================
    
    printf("ETAPE 4 - Calcul de la somme\n");
    
    // CORRECTION :
    ptr = &scores[0];  // Remet ptr au début
    int somme = 0;     // Variable pour accumuler la somme
    
    for(int i = 0; i < 5; i++) {
        somme += *ptr;  // Ajoute la valeur pointée à somme
        ptr++;          // Avance au suivant
    }
    
    /* EXPLICATION DU CALCUL :
     * 
     * Avant la boucle : somme = 0
     * 
     * i=0 :