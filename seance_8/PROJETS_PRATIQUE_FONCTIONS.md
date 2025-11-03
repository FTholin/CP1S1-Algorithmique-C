# Exercices Pratiques 


## 🛒 Exercice 1 : Caisse de supermarché
**Niveau : Débutant**

Vous travaillez sur un système de caisse. Créez une fonction qui calcule le prix TTC à partir du prix HT.

```c
double calculer_prix_ttc(double prix_ht, double taux_tva);

// Test dans main()
int main() {
    double prix = calculer_prix_ttc(100.0, 20.0);  // 100€ HT, TVA 20%
    printf("Prix TTC : %.2f euros\n", prix);
    return 0;
}
```

**Résultat attendu :** `Prix TTC : 120.00 euros`

---

## ⏰ Exercice 2 : Gestion du temps de travail
**Niveau : Débutant**

Créez une fonction qui convertit un nombre de minutes en heures et minutes.

```c
void convertir_minutes(int total_minutes, int *heures, int *minutes);

// Test
int main() {
    int h, m;
    convertir_minutes(195, &h, &m);  // 195 minutes
    printf("Durée : %d heures et %d minutes\n", h, m);
    return 0;
}
```

**Résultat attendu :** `Durée : 3 heures et 15 minutes`

**💡 Indications :**
- Heures : division entière par 60
- Minutes restantes : modulo (%) par 60
- Utilisez les pointeurs pour modifier les valeurs : `*heures = ...`

---

## 🚗 Exercice 3 : Calculateur de consommation d'essence
**Niveau : Débutant**

Créez une fonction qui calcule la consommation moyenne d'une voiture (litres/100km).

```c
double calculer_consommation(double litres, double kilometres);

// Exemple : 45 litres pour 600 km
```

**Résultat attendu :** `7.50 L/100km`

---

## 💰 Exercice 4 : Distributeur de billets
**Niveau : Intermédiaire**

Créez une fonction qui calcule combien de billets de chaque type sont nécessaires pour un retrait.

```c
void calculer_billets(int montant, int *billets_50, int *billets_20, int *billets_10);

// Test
int main() {
    int b50, b20, b10;
    calculer_billets(180, &b50, &b20, &b10);
    printf("Billets de 50 : %d\n", b50);
    printf("Billets de 20 : %d\n", b20);
    printf("Billets de 10 : %d\n", b10);
    return 0;
}
```

**Pour 180€ → 3 billets de 50€, 1 billet de 20€, 1 billet de 10€**

**💡 Indications :**
- Commencez par les billets de 50€ : `montant / 50`
- Calculez le reste avec le modulo (%)
- Répétez pour les billets de 20€, puis de 10€
- Stockez les résultats via pointeurs : `*billets_50 = ...`

---

## 📧 Exercice 5 : Validation d'email
**Niveau : Débutant**

Créez une fonction qui vérifie si une chaîne de caractères contient le symbole '@' (validation basique d'email).

```c
int email_valide(char email[]);
// Retourne 1 si valide, 0 sinon
```

**Tests :**
- `"user@example.com"` → 1
- `"userexample.com"` → 0

---

## 💱 Exercice 6 : Échange de devises
**Niveau : Intermédiaire**

Une agence de change doit échanger des devises entre deux clients. Créez une fonction qui échange les montants entre deux comptes.

```c
void echanger_devises(double *compte1, double *compte2);

// Test
int main() {
    double euros_client1 = 100.0;
    double euros_client2 = 250.0;
    
    printf("Avant échange : Client 1 = %.2f€, Client 2 = %.2f€\n", 
           euros_client1, euros_client2);
    
    echanger_devises(&euros_client1, &euros_client2);
    
    printf("Après échange : Client 1 = %.2f€, Client 2 = %.2f€\n", 
           euros_client1, euros_client2);
    return 0;
}
```

**Résultat attendu :** Les montants sont échangés entre les deux comptes.

**💡 Indications :**
- Utilisez une variable temporaire pour ne pas perdre de valeur
- Étapes : `temp = *compte1;` → `*compte1 = *compte2;` → `*compte2 = temp;`

---

## 🎫 Exercice 7 : Mise à jour de prix
**Niveau : Intermédiaire**

Un magasin doit augmenter le prix d'un article. Créez une fonction qui modifie directement le prix via un pointeur et applique une augmentation en pourcentage.

```c
void augmenter_prix(double *prix, double pourcentage);

// Test
int main() {
    double prix_article = 50.0;
    
    printf("Prix initial : %.2f€\n", prix_article);
    augmenter_prix(&prix_article, 15.0);  // +15%
    printf("Prix après augmentation de 15%% : %.2f€\n", prix_article);
    
    return 0;
}
```

**Résultat attendu :** `Prix après augmentation de 15% : 57.50€`

---

## 🌡️ Exercice 8 : Capteur de température
**Niveau : Intermédiaire**

Un capteur de température enregistre la température actuelle et doit la comparer avec la température minimale et maximale enregistrées. Créez une fonction qui met à jour ces valeurs si nécessaire.

```c
void mettre_a_jour_extremes(double temperature_actuelle, 
                            double *temp_min, double *temp_max);

// Test
int main() {
    double min = 15.0, max = 25.0;
    
    printf("Températures initiales : min=%.1f°C, max=%.1f°C\n", min, max);
    
    mettre_a_jour_extremes(28.5, &min, &max);
    printf("Après mesure de 28.5°C : min=%.1f°C, max=%.1f°C\n", min, max);
    
    mettre_a_jour_extremes(12.3, &min, &max);
    printf("Après mesure de 12.3°C : min=%.1f°C, max=%.1f°C\n", min, max);
    
    return 0;
}
```

**Résultat attendu :** Les valeurs min et max sont mises à jour si la nouvelle température est plus extrême.

**💡 Indications :**
- Si `temperature_actuelle < *temp_min`, mettez à jour le minimum
- Si `temperature_actuelle > *temp_max`, mettez à jour le maximum
- Utilisez des instructions `if` pour comparer

---

## 🎮 Exercice 9 : Calcul de score de jeu
**Niveau : Intermédiaire**

Dans un jeu vidéo, créez les fonctions suivantes :

```c
int calculer_score_niveau(int ennemis_tues, int temps_secondes, int bonus);
int ajouter_multiplicateur(int score_base, double multiplicateur);
```

**Logique :**
- Score de base : `ennemis_tues * 100 - temps_secondes + bonus`
- Le multiplicateur augmente le score (ex: x1.5 pour +50%)

**Test :** 10 ennemis, 45 secondes, 200 bonus, multiplicateur x2 → ?

---

## 🏋️ Exercice 10 : Calculateur d'IMC
**Niveau : Débutant**

Créez une fonction qui calcule l'Indice de Masse Corporelle et une autre qui affiche l'interprétation.

```c
double calculer_imc(double poids_kg, double taille_m);
void afficher_categorie_imc(double imc);

// Catégories :
// < 18.5 : Insuffisance pondérale
// 18.5 - 24.9 : Poids normal
// 25 - 29.9 : Surpoids
// >= 30 : Obésité
```

**Test :** Poids 70kg, taille 1.75m → IMC = 22.86 (Poids normal)

---

## 📱 Exercice 11 : Validation de code PIN
**Niveau : Intermédiaire**

Créez des fonctions pour gérer un code PIN à 4 chiffres :

```c
int valider_pin(char pin[]);  // Vérifie que c'est bien 4 chiffres
int comparer_pins(char pin1[], char pin2[]);  // Compare deux codes
int est_chiffre(char c);  // Vérifie si un caractère est un chiffre
```

**Validation :** 
- Le PIN doit faire exactement 4 caractères
- Tous les caractères doivent être des chiffres (0-9)

---

## 🔄 Exercice 12 : Rotation de valeurs
**Niveau : Intermédiaire**

Dans un système de rotation de personnel, trois employés échangent leur poste. Créez une fonction qui effectue une rotation : A → B, B → C, C → A.

```c
void rotation_trois_valeurs(int *a, int *b, int *c);

// Test
int main() {
    int poste1 = 100, poste2 = 200, poste3 = 300;
    
    printf("Avant rotation : P1=%d, P2=%d, P3=%d\n", poste1, poste2, poste3);
    rotation_trois_valeurs(&poste1, &poste2, &poste3);
    printf("Après rotation : P1=%d, P2=%d, P3=%d\n", poste1, poste2, poste3);
    
    return 0;
}
```

**Résultat attendu :** P1=300, P2=100, P3=200

**Astuce :** Utilisez une variable temporaire pour ne pas perdre de valeurs.

**💡 Indications :**
- Sauvegardez `*a` dans une variable temporaire
- Ordre des affectations : C → A, B → C, temp → B
- Dessinez un schéma pour visualiser

---

## 🏆 Exercice 13 : Podium sportif
**Niveau : Intermédiaire**

Dans une compétition sportive, trois athlètes ont obtenu des scores. Créez une fonction qui trie ces trois scores par ordre décroissant (or, argent, bronze).

```c
void trier_trois_scores(int *score1, int *score2, int *score3);
// Après l'appel : score1 >= score2 >= score3

// Test
int main() {
    int athlete1 = 250, athlete2 = 420, athlete3 = 310;
    
    printf("Scores initiaux : %d, %d, %d\n", athlete1, athlete2, athlete3);
    trier_trois_scores(&athlete1, &athlete2, &athlete3);
    printf("Podium (Or, Argent, Bronze) : %d, %d, %d\n", 
           athlete1, athlete2, athlete3);
    
    return 0;
}
```

**Résultat attendu :** `420, 310, 250`

**Astuce :** Comparez et échangez les valeurs deux à deux en utilisant une fonction auxiliaire.

**💡 Indications :**
- Créez une fonction `echanger` pour échanger deux valeurs
- Comparez et échangez : score1/score2, puis score2/score3, puis à nouveau score1/score2
- C'est une version simplifiée du tri à bulles pour 3 éléments

---

## 💳 Exercice 14 : Système de paiement
**Niveau : Intermédiaire**

Créez un système qui gère différents modes de paiement :

```c
double appliquer_frais_paiement(double montant, char mode);
// 'C' = Carte bancaire : +2% de frais
// 'E' = Espèces : pas de frais
// 'P' = PayPal : +3.5% de frais

int verifier_fonds(double solde_compte, double montant_achat);
// Retourne 1 si assez d'argent, 0 sinon
```

**Test :** Achat de 50€ par carte avec un solde de 100€ → ?

---

## 🏨 Exercice 15 : Système de réservation d'hôtel
**Niveau : Avancé**

Créez un système complet de calcul de réservation :

```c
double prix_par_nuit(int type_chambre);
// 1 = Simple (80€), 2 = Double (120€), 3 = Suite (200€)

double calculer_prix_sejour(int type_chambre, int nb_nuits);

double appliquer_reduction_fidelite(double prix, int nb_sejours_precedents);
// 0-2 séjours : pas de réduction
// 3-5 séjours : -5%
// 6+ séjours : -10%

void afficher_facture(int type_chambre, int nb_nuits, int nb_sejours_precedents);
// Affiche le détail complet de la facture
```

**Test :** Suite pour 3 nuits, client avec 7 séjours précédents
- Prix de base : 200 × 3 = 600€
- Réduction fidélité -10% : 540€

**💡 Indications :**
- Créez d'abord les 3 fonctions simples (prix, calcul séjour, réduction)
- Pour la réduction : 0-2 séjours = 0%, 3-5 = -5%, 6+ = -10%
- La fonction `afficher_facture` appelle les 3 autres et affiche le résultat

---

## 💡 Conseils pratiques

1. **Testez avec des cas réels :** Utilisez des valeurs réalistes (prix, températures, etc.)
2. **Gérez les erreurs :** Division par zéro, valeurs négatives, etc.
3. **Pensez utilisateur :** Les messages doivent être clairs et utiles
4. **Réutilisez vos fonctions :** Une bonne fonction peut servir dans plusieurs programmes
5. **Commentez :** Expliquez ce que fait chaque fonction

