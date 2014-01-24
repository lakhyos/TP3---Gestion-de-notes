#ifndef LISTE_H
#define LISTE_H

#include "etudiant.h"

typedef struct Liste Liste;

typedef struct ElementListe ElementListe;

/*
 * Nom de la fonction: Creer_liste
 * Sorties :
 *      Liste liste : La liste créee
 * Description:
 *      Crée une liste et la retourne
 */
Liste* Creer_liste();

/*
 * Nom de la fonction: Taille_liste
 * Entrées :
 *      Liste liste : La liste
 * Sorties :
 *      int taille
 * Description:
 *      Retourne la taille de la liste
 */
int Taille_liste(Liste*);

/*
 * Nom de la fonction: Inserer_liste
 * Entrées :
 *      Liste liste  : La liste
 *      Etudiant valeur : La valeur a inserer
 *      int position : La position ou inserer
 * Description:
 *      Insere un element dans la liste à la position indiquée
 */
void Inserer_liste(Liste *liste, Etudiant valeur, int position);

/*
 * Nom de la fonction: Acceder_liste
 * Entrées :
 *      Liste liste : La liste
 *      int position : La position de l'element
 * Description:
 *      Retourne l'element a la position indiquée
 */
Etudiant *Acceder_liste(Liste *liste, int position);

/*
 * Nom de la fonction: Supprimer_liste
 * Entrées :
 *      Liste liste : La liste
 *      int position :La position indiquee
 * Description:
 *      Supprimer un élément à la posisition indiquée
 */
void Supprimer_liste(Liste *liste, int position);

/*
 * Nom de la fonction: Detruire_liste
 * Entrées :
 *      Liste liste : La liste
 * Description:
 *      Detruit une liste
 */
void Detruire_liste(Liste *liste);

/*
 * Nom de la fonction: Localiser_etudinat
 * Entrées :
 *      Liste *liste : La liste d'étudiant
 *      char *cne : Le CNE de l'étudiant
 * Sorties :
 *      Etudiant* etudiant : L'étudiant recherché
 * Description:
 *      Retoune l'étudiant avec le cne donné comme argument, ou NULL
 * si il n'existe pas
 */
Etudiant* Localiser_etudiant(Liste *liste, char *cne);

#endif // LISTE_H
