
# La bonne Pizz du campus

La pizzeria du campus prépare la soirée de désintégration. La caisse affiche juste les quantités et les prix unitaires (HT). Ton rôle : concevoir la logique du ticket avant de coder, en respectant la chaîne **HT → TVA → TTC** et en intégrant un **frais de livraison** unique.

## Structure du programme

* Entrées : **nb de Margherita**, **nb de Regina** (entiers).
* Constantes : **prix\_M**, **prix\_R**, **frais\_livraison**, **TAUX\_TVA**.
* Sorties : **ticket** avec lignes, **sous-total HT**, **TVA**, **total TTC**.

---

## 1) Données & symboles

1. Choisis des **noms de constantes** clairs (en MAJUSCULES) pour :

   * prix d’une Margherita (HT)
   * prix d’une Regina (HT)
   * frais de livraison (HT)
   * taux de TVA (ex. 0,10 pour 10 %)
2. Déclare deux **variables entières** pour les quantités.
3. Écris tes **phrases de saisie** (prompts) exactes que tu veux voir à l’écran.

> Astuce : garde tout **HT** jusqu’au calcul de la TVA. On ajoute la TVA à la toute fin.

---

## 2) Des pièces au puzzle → **Formules**

Sans écrire de code au début, assemble les **pièces** ci-dessous pour obtenir les expressions demandées. Tu n’utilises que `+` et `×`.

**Banque de pièces**
`qM`, `qR`, `PRIX_M`, `PRIX_R`, `FRAIS_LIVRAISON`, `TAUX_TVA`

### Étape A — Lignes (HT)

1. Montant **Margherita** : `ligne_M =` ☐ ☐
2. Montant **Regina**     : `ligne_R =` ☐ ☐
   *(Choisis pour chaque ligne le bon couple « quantité × prix ».)*

### Étape B — Sous-total (HT)

3. **SousTotalHT** : `=` ☐ ☐ ☐
   *(Additionne ce qu’il faut. Rappelle-toi que les **frais de livraison** sont **HT** et donc entrent **avant** la TVA.)*

### Étape C — TVA (montant)

4. **TVA** : `=` ☐ ☐

### Étape D — Total (TTC)

5. **TotalTTC** : `=` ☐ ☐


## 3) Des formules au C — **Entrées & calculs sans condition**

Objectif : écrire les **lignes essentielles** du programme en t’appuyant sur ce que tu as formalisé à la partie 2.

1. **Types**

   * Quantités : `int` (`qM`, `qR`).
   * Montants : `double` (lignes, sous-total, TVA, total).

2. **Saisie utilisateur (I/O)**

   * Rédige les deux `printf` de **prompt** (une question par quantité).
   * Utilise `scanf("%d", &qM);` puis `scanf("%d", &qR);`.
   * Ajoute **immédiatement après** un `printf` d’**écho** qui réaffiche les quantités lues (utile pour vérifier les entrées).

3. **Variables intermédiaires**

   * Crée puis **initialise** par calcul : `ligne_M`, `ligne_R`, `sousTotalHT`, `tva`, `totalTTC`.
   * Chaque variable correspond **1-pour-1** à une formule du §2. Tu ne “compresses” pas tout dans un seul `printf`.

4. **Lecture rapide du formatage**

   * Pour les montants, tu utiliseras plus tard `%.2f` dans le ticket (on reste focalisé ici sur les **valeurs** correctes, pas encore la mise en page).
   * Insère un `printf` de contrôle par ligne de calcul (ex. “Ligne Margherita: …”) pour t’assurer que tes formules donnent les bons chiffres **avant** de soigner l’affichage.

> À la fin de cette étape, ton fichier compile et affiche des nombres cohérents pour `ligne_M`, `ligne_R`, `sousTotalHT`, `tva`, `totalTTC`. Tu passes ensuite au §4 pour mettre ça au propre.

---

## 4) Plan d’affichage (ticket)

Dessine le **ticket** que tu veux obtenir. Par exemple :

```
=============== T I C K E T ===============
Margherita   x2        15.00 €
Regina       x1         9.80 €
Frais livr.             2.50 €
------------------------------------------
Sous-total HT:         27.30 €
TVA (10%):              2.73 €
TOTAL TTC:             30.03 €
==========================================
```

Décide :

* Où mettre des `\n` ?
* Utiliser des **tabulations** `\t` ou des **largeurs** (`%8.2f`) pour aligner ?

  * Base (conforme à la leçon) : séparer avec `\t`.
  * Bonus (si vous vous sentez) : tester une **largeur minimale** et `%.2f` pour l’argent.

---

## 5) Rappels

* Quantités → `%d`
* Montants → `%.2f` (2 décimales)
* Saut de ligne → `\n`
* Tabulation → `\t`

---

## 6) Petit jeu de test

On fige les **constantes** pour tous :

* PRIX\_M = **7,50 €** ; PRIX\_R = **9,80 €** ; FRAIS\_LIVRAISON = **2,50 €** ; TAUX\_TVA = **0,10**

Calcule à la main (papier) :

* **Test A** : qM=2, qR=1 → lignes 15,00 + 9,80 ; sous-total HT 27,30 ; TVA 2,73 ; **Total 30,03**
* **Test B** : qM=0, qR=0 → sous-total 2,50 ; TVA 0,25 ; **Total 2,75**
* **Test C** : qM=3, qR=4 → sous-total 64,20 ; TVA 6,42 ; **Total 70,62**

> Quand ton programme tournera, **compare** les sorties à ces résultats.

---

## 7) Checklist 

* [ ] Les quatre **constantes** sont déclarées et utilisées.
* [ ] Les **deux entrées** sont lues et affichées sur le ticket.
* [ ] Les **formules** sont respectées (frais dans le HT, TVA appliquée une seule fois).
* [ ] Tous les montants sont au format `%.2f`.
* [ ] Le ticket est **lisible et aligné** (tabulations ou largeurs).
* [ ] Les **tests A, B, C** tombent exactement.

---

## 8) Petits pièges classiques (à éviter)

* Calculer la **TVA avant** d’ajouter les frais de livraison.
* Mélanger `%d` et `%f`.
* Oublier `\n` (ticket “collé”).

