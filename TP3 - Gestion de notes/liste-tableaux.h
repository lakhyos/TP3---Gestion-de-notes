#include "tableaux.h"

typedef Tableau Liste;

#define Creer_liste Creer_tableau

#define Detruire_liste Detruire_tableau

#define Inserer_liste Ajout_tableau

#define Acceder_liste(liste, position) liste.Etudiant[position]

#define Supprimer_liste Suppression_tableau

#define Suivant_liste(liste, position) liste.Etudiant[position + 1]

#define Precedent_liste(liste, position) liste.Etudiant[position - 1]

#define Taille_liste Taille_tableau

