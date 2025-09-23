{\rtf1\ansi\ansicpg1252\cocoartf2639
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <stdio.h>\
\
int main(void) \{\
    /* === Constantes (HT) === */\
    const double PRIX_M = 7.50;\
    const double PRIX_R = 9.80;\
    const double FRAIS_LIVRAISON = 2.50;\
    const double TAUX_TVA = 0.10;\
\
    /* === Entr\'e9es === */\
    int qM, qR;\
\
    printf("Quantite Margherita : \\n");\
    scanf("%d", &qM);\
    printf("Quantite Regina     : \\n");\
    scanf("%d", &qR);\
\
    /* === Calculs === */\
    double ligne_M = qM * PRIX_M;\
    double ligne_R = qR * PRIX_R;\
    double sousTotalHT = ligne_M + ligne_R + FRAIS_LIVRAISON;  /* frais dans le HT */\
    double tva = sousTotalHT * TAUX_TVA;\
    double totalTTC = sousTotalHT + tva;\
\
    /* Pour l'intitule de la TVA */\
    int tva_pct = (int)(TAUX_TVA * 100 + 0.5);\
\
    /* === Ticket === */\
    printf("\\n");\
    printf("=============== T I C K E T ===============\\n");\
    printf("%-14s x%-2d %12.2f \'80\\n", "Margherita", qM, ligne_M);\
    printf("%-14s x%-2d %12.2f \'80\\n", "Regina",     qR, ligne_R);\
    printf("%-14s      %12.2f \'80\\n", "Frais livr.",      FRAIS_LIVRAISON);\
    printf("------------------------------------------\\n");\
    printf("%-14s: %12.2f \'80\\n", "Sous-total HT", sousTotalHT);\
    printf("TVA (%d%%):      %12.2f \'80\\n", tva_pct, tva);\
    printf("%-14s: %12.2f \'80\\n", "TOTAL TTC", totalTTC);\
    printf("==========================================\\n");\
\
    return 0;\
\}\
}