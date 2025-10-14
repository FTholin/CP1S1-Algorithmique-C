#include <stdio.h>

int main() {
    // Tableau des scores de 5 joueurs
    int scores[5] = {120, 95, 150, 88, 200};
    
    printf("=== GESTIONNAIRE DE SCORES ===\n\n");
    
    // ========================================
    // ÉTAPE 1 : Créer un pointeur vers les scores
    // ========================================
    // 🤔 Question : Quel type de pointeur pour un tableau d'int ?
    // 💡 Indice : Si scores contient des int, le pointeur doit être...
    // 📝 Syntaxe : TYPE* nom = &tableau[0];
    
    // TODO : Déclarez un pointeur 'ptr' pointant vers le premier élément
    
    
    
    printf("ETAPE 1 - Pointeur cree\n");
    // TODO : Affichez l'adresse stockée dans ptr (utilisez %p)
    
    // TODO : Affichez la valeur pointée par ptr (utilisez %d)
    
    printf("\n");
    
    
    // ========================================
    // ÉTAPE 2 : Afficher tous les scores avec le pointeur
    // ========================================
    // 🤔 Question : Comment obtenir la valeur à l'adresse d'un pointeur ?
    // 💡 Indice 1 : L'opérateur * permet de déréférencer
    // 💡 Indice 2 : Pour avancer au prochain élément, utilisez ptr++
    // 📝 Structure : for(int i = 0; i < 5; i++) { ... }
    
    printf("ETAPE 2 - Affichage des scores\n");
    // TODO : Remettez ptr au début du tableau (pointez vers scores[0])
    
    
    // TODO : Créez une boucle qui affiche chaque score
    // Format souhaité : "Joueur 1 : 120 points"
    
    
    
    
    
    printf("\n");
    
    
    // ========================================
    // ÉTAPE 3 : Modifier un score avec un pointeur
    // ========================================
    // 🎯 Objectif : Le joueur 3 (indice 2) gagne 50 points bonus
    // 🤔 Question : Comment faire pointer ptr vers le 3ème élément ?
    // 💡 Indice 1 : Le joueur 3 est à l'indice 2 du tableau
    // 💡 Indice 2 : Pour modifier la valeur pointée, utilisez *ptr
    // 📝 Rappel : *ptr += 50 signifie "ajoute 50 à la valeur pointée"
    
    printf("ETAPE 3 - Bonus pour le joueur 3\n");
    
    // TODO : Faites pointer ptr vers scores[2]
    
    
    // TODO : Affichez le score AVANT modification
    
    
    // TODO : Ajoutez 50 points au score pointé
    
    
    // TODO : Affichez le score APRÈS modification
    
    printf("\n");
    
    
    // ========================================
    // ÉTAPE 4 : Calculer la somme avec arithmétique de pointeurs
    // ========================================
    // 🤔 Question : Comment additionner tous les scores en parcourant avec ptr ?
    // 💡 Indice 1 : Créez une variable 'somme' initialisée à 0
    // 💡 Indice 2 : Dans une boucle, faites somme += *ptr, puis ptr++
    // 💡 Indice 3 : N'oubliez pas de remettre ptr au début !
    
    printf("ETAPE 4 - Calcul de la somme\n");
    
    // TODO : Remettez ptr au début du tableau
    
    
    // TODO : Créez une variable 'somme' initialisée à 0
    
    
    // TODO : Parcourez le tableau et calculez la somme
    
    
    
    
    
    
    // TODO : Affichez la somme et la moyenne
    
    
    printf("\n");
    
    
    // ========================================
    // ÉTAPE 5 : Trouver le score maximum
    // ========================================
    // 🎯 Objectif : Trouver le meilleur score et sa position
    // 🤔 Question : Comment comparer chaque valeur à un maximum ?
    // 💡 Indice 1 : Initialisez 'max' avec la première valeur (*ptr)
    // 💡 Indice 2 : Créez aussi 'position_max' pour retenir l'indice
    // 💡 Indice 3 : Dans la boucle, testez si *ptr > max
    
    printf("ETAPE 5 - Recherche du meilleur score\n");
    // TODO : Remettez ptr au début
    
    
    // TODO : Créez une variable 'max' initialisée avec *ptr
    
    
    // TODO : Créez une variable 'position_max' initialisée à 0
    
    
    // TODO : Parcourez le tableau et trouvez le maximum
    
    
    
    
    
    
    
    // TODO : Affichez le meilleur score et sa position
    
    printf("\n");
    
    
    // ========================================
    // ÉTAPE 6 : Affichage en ordre inverse
    // ========================================
    // 🤔 Question : Comment parcourir un tableau de la fin vers le début ?
    // 💡 Indice 1 : Faites pointer ptr vers &scores[4] (dernier élément)
    // 💡 Indice 2 : Utilisez ptr-- pour reculer au lieu de ptr++
    // 💡 Indice 3 : La boucle reste identique (5 itérations)
    
    printf("ETAPE 6 - Scores en ordre inverse\n");
    
    // TODO : Faites pointer ptr vers le DERNIER élément
    
    
    // TODO : Créez une boucle qui recule dans le tableau
    
    
    
    
    
    printf("\n");
    
    
    // ========================================
    // ÉTAPE 7 : Doubler tous les scores
    // ========================================
    // 🎯 Objectif : Multiplier chaque score par 2
    // 🤔 Question : Comment modifier tous les éléments avec un pointeur ?
    // 💡 Indice : *ptr = *ptr * 2; ou plus court : *ptr *= 2;
    
    printf("ETAPE 7 - Doublement des scores (promotion speciale !)\n");
    
    // TODO : Remettez ptr au début
    
    
    // TODO : Parcourez et doublez chaque score
    
    
    
    
    
    
    // TODO : Affichez les nouveaux scores
    printf("Nouveaux scores :\n");
    
    
    
    
    
    
    return 0;
}