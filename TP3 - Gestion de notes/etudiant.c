#include "etudiant.h"
#include "liste.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void Copie_etudiant(Etudiant e1, Etudiant *e2)
{
    strcpy(e2->cne, e1.cne);
    strcpy(e2->nom, e1.nom);
    strcpy(e2->prenom, e1.prenom);
    memcpy(e2->notes, e1.notes, sizeof(e1.notes));
    e2->date_naissance = e1.date_naissance;
}

float Moyenne_annee(Etudiant etudiant, int annee)
{
    assert(annee == 1 || annee == 2 || annee == 3);
    int debut, fin;
    switch (annee) {
    case 1: debut = 0, fin = 16; break;
    case 2: debut = 16, fin = 28; break;
    case 3: debut = 28, fin = 36; break;
    }

    int i, somme = 0;
    for(i = debut; i < fin; i++)  somme += etudiant.notes[i];
    return somme / fin - debut;
}

float Moyenne_general(Etudiant etudiant)
{
    return Moyenne_annee(etudiant, 1) * 0.3 +
           Moyenne_annee(etudiant, 2) * 0.3 +
           Moyenne_annee(etudiant, 3) * 0.25 +
           etudiant.notes[PFE] * 0.15 ;
}

int Validation_annee(Etudiant etudiant, int annee)
{
    assert(annee == 1 || annee == 2 || annee == 3);
    int debut, fin;
    switch (annee) {
    case 1: debut = 0, fin = 16; break;
    case 2: debut = 16, fin = 29; break;
    case 3: debut = 29, fin = 36; break;
    }

    int i,j;
    for(i = debut; i < fin; i++)
        if(etudiant.notes[i] < 12 || etudiant.notes[i] <= 10) j++;
    if(j < 5 && Moyenne_annee(etudiant, annee) >= 12) return 1;
    else return 0;
}

int Reussite(Etudiant etudiant)
{
    return Moyenne_general(etudiant) >= 12;
}

typedef struct{
    Etudiant *etudiant;
    float moyenne;
} Moyenne;

int Comparer_moyenne(const void* p1, const void* p2)
{
    float m1 = ((Moyenne*)p1)->moyenne, m2 = ((Moyenne*)p2)->moyenne;
    return (m1 < m2)? -1 : ((m1 > m2)? 1:0);
}

Liste* Classer_etudiants(Liste *liste)
{
    // Stocker les moyennes pour ne pas les recalculez à chaque fois
    Moyenne *moys = malloc(sizeof(Moyenne) * Taille_liste(liste));
    int i;
    for (i = 0; i < Taille_liste(liste); ++i)
    {
        moys[i].etudiant = Acceder_liste(liste, i);
        moys[i].moyenne = Moyenne_general(*moys[i].etudiant);
    }

    // Trier
    qsort(moys, Taille_liste(liste), sizeof(Moyenne), Comparer_moyenne);

    // reconstruire la liste
    Liste *resultat = Creer_liste();
    for (i = 0; i < Taille_liste(liste); ++i)
        Inserer_liste(resultat, *moys[i].etudiant, Taille_liste(resultat));

    free(moys);
    return resultat;
}

void Afficher_etudiant(Etudiant etudiant)
{
    printf("CNE : %s\nNom : %s\nPrénom : %s\nDate de naissance : %d/%d/%d"
           "\nNOTES____________________________________________________\n",
           etudiant.cne, etudiant.nom, etudiant.prenom,
           etudiant.date_naissance.jour, etudiant.date_naissance.mois,
           etudiant.date_naissance.annee);
    int i;
    printf(" -- 1ère année : ");
    for (i = 0; i < 16; ++i) printf("%.2f ", etudiant.notes[i]);
    printf("\n -- 2ème année : ");
    for (i = 16; i < 28; ++i) printf("%.2f ", etudiant.notes[i]);
    printf("\n -- 3ème année : ");
    for (i = 28; i < 36; ++i) printf("%.2f ", etudiant.notes[i]);
    printf("\n");
}
