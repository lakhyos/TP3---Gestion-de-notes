#include "liste.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

struct Liste
{
    int taille;
    ElementListe *premier;
};

struct ElementListe
{
    Etudiant valeur;
    ElementListe *suivant;
};

Liste* Creer_liste()
{
    Liste *liste = (Liste*) malloc(sizeof(Liste));
    if(!liste)
    {
        printf("Erreur d'allocation dynamique\n");
        exit(1);
    }
    liste->taille = 0;
    return liste;
}

int Taille_liste(Liste *liste)
{
    return liste->taille;
}

void Inserer_liste(Liste *liste, Etudiant valeur, int position)
{
    assert(position <= liste->taille);
    assert(position >= 0);

    ElementListe *element = malloc(sizeof(ElementListe));
    if(!element)
    {
        printf("Erreur d'allocation dynamique\n");
        exit(1);
    }
    Copie_etudiant(valeur, &element->valeur);

    if(position == 0)
    {
        element->suivant = liste->premier;
        liste->premier = element;
    }
    else
    {
        ElementListe *courant = liste->premier;

        int i ;
        for(i = 0; i < position - 1; i++) courant = courant->suivant;

        element->suivant = courant->suivant;
        courant->suivant = element;
    }

    liste->taille++;
}

Etudiant* Acceder_liste(Liste *liste, int position)
{
    assert(position >= 0);
    assert(position < liste->taille);
    int i;
    ElementListe *actuel = liste->premier;
    for (i = 0; i < position && actuel->suivant; ++i)
        actuel = actuel->suivant;
    return &actuel->valeur;
}

void Supprimer_liste(Liste *liste, int position)
{
    assert(position >= 0);
    assert(position < liste->taille);

    ElementListe *courant = liste->premier;

    if(position == 0)
    {
        liste->premier = liste->premier->suivant;
        free(courant);
    }
    else
    {
        int i;
        for (i = 0; i < position - 1 ; ++i)
            courant = courant->suivant;
        ElementListe *cible = courant->suivant;
        courant->suivant = courant->suivant->suivant;
        free(cible);
    }

    liste->taille--;
}

void Detruire_liste(Liste *liste)
{
    while (Taille_liste(liste)) Supprimer_liste(liste, 0);
}

#include <stdio.h>
Etudiant* Localiser_etudiant(Liste *liste, char *cne)
{
    ElementListe *courant = liste->premier;
    int i;
    for (i = 0; courant ; ++i, courant = courant->suivant)
        if(!strcmp(courant->valeur.cne, cne)) return &courant->valeur;
    return NULL;
}
