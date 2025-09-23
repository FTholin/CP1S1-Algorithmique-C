{\rtf1\ansi\ansicpg1252\cocoartf2639
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <stdio.h>\
\
int main(void) \{\
    int heures;\
    double tarif, frais;\
    double sous_total, total;\
\
    printf("ORDI > ====== PARKING PARC RELAI ======\\n");\
    printf("ORDI > Heures : \\n");\
    scanf("%d", &heures);\
\
    printf("ORDI > Tarif horaire (\'80) : \\n");\
    scanf("%f", &tarif);\
\
    printf("ORDI > Frais fixe (\'80) : \\n");\
    scanf("%f", &frais);\
\
    printf("\\n");\
    sous_total = heures * tarif;\
    total = sous_total + frais;\
\
    printf("ORDI > --------- RECU ----------\\n");\
    printf("ORDI > Heures       : %d\\n", heures);\
    printf("ORDI > Tarif horaire: %.2f \'80\\n", tarif);\
    printf("ORDI > Frais fixe   : %.2f \'80\\n", frais);\
    printf("ORDI > Sous-total   : %.2f \'80\\n", sous_total);\
    printf("ORDI > TOTAL        : %.2f \'80\\n", total);\
    printf("ORDI > ===========================\\n");\
\
    return 0;\
\}\
}