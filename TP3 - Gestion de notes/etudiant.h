#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "date.h"
typedef struct Liste Liste;

#define PFE 36

typedef struct
{
    char cne[11];
    char nom[100];
    char prenom[100];
    Date date_naissance;
    float notes[37];
} Etudiant;

/*
 * Nom de la fonction: Copie_etudiant
 * Entrées :
 *      Etudiant e1 : variable à copier
 *      Etudiant e2 : Cible de la copie
 * Description:
 *      Copie une variable de type Etudiant dans une autre
 */
void Copie_etudiant(Etudiant e1, Etudiant *e2);

/*
 * Nom de la fonction: Moyenne_general()
 * Entrées :
 *     Etudiant e1 : L'Etudiant
 *     int annee : L'annee (1, 2 ou 3)
 * Sorties :
 *      float moyenne : La moyenne de l'annee
 * Description:
 *      Retourne la moyenne de l'annee
 */
float Moyenne_annee(Etudiant etudiant, int annee);

/*
 * Nom de la fonction: Moyenne_general()
 * Entrées :
 *     Etudiant e1 : L'Etudiant
 * Sorties :
 *      float moyenne : La moyenne generale
 * Description:
 *      Retourne la moyenne de generale d'un etudiant
 */
float Moyenne_general(Etudiant etudiant);

/*
 * Nom de la fonction: Validation_annee
 * Entrées :
 *     Etudiant e1 : L'Etudiant
 *     int annee : L'annee (1, 2 ou 3)
 * Sorties :
 *      int validation : variable boolean indiquant si l'etudiant à validé
 * Description:
 *      Retourne 1 si L'etudiant à validé sinon elle retourne 0
 */
int Validation_annee(Etudiant etudiant, int annee);

/*
 * Nom de la fonction: Reussite
 * Entrées :
 *     Etudiant e1 : L'Etudiant
 * Sorties :
 *      int reussite : variable boolean infiquant la reussite
 * Description:
 *      Indique si l'etudiant a reussit sa formation
 */
int Reussite(Etudiant etudiant);


/*
 * Nom de la fonction: Classer_etudiants
 * Entrées :
 *     Liste liste : La liste des etudiants
 * Sorties :
 *     Liste resultat : Le resultat du tri
 * Description:
 *      Tri les etudiants selon leur moyenne generale et retourne le
 * resultat dans une nouvelle liste
 */
Liste* Classer_etudiants(Liste *liste);

/*
 * Nom de la fonction: Afficher_etudiant
 * Entrées :
 *      Etudiant etudiant : L'etudiant à afficher
 * Description:
 *      Afficher un étudiant
 */
void Afficher_etudiant(Etudiant etudiant);

#endif // ETUDIANT_H
