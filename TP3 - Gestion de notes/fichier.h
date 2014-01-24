#ifndef FICHIER_H
#define FICHIER_H

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/*
 * Nom de la fonction: Lire_fichier
 * Entrées :
 *      char nom_fichier : Le nom du fichier
 * Sorties :
 *      Liste liste : La liste contenu dans le fichier
 * Description:
 *      Lit un fichier et retourne la liste contenue dedans, si le fichier
 * n'existe pas il est creé.
 */
Liste* Lire_fichier(char *nom_fichier);

/*
 * Nom de la fonction: Ecrire_fichier
 * Entrées :
 *      Liste liste : La liste à enregistrer
 *      char* nom_fichier : Le nom du fichier
 * Sorties :
 *      int succes : indique le succes de l'enregistrement
 * Description:
 *      Enregistre la liste dans un fichier
 */
int Ecrire_fichier(Liste *liste, char *nom_fichier);


#endif // FICHIER_H
