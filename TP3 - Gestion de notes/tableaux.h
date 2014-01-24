//Declaration des librairies

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Déclaration des types et structures

struct Tableau
{
    int *Etudiant; // Données stockées dans le tableau
    int dernier_etudiant; // l'indice du dernier element
    int nombre_etudiant; // Taille maximale du tableau
};

typedef struct Tableau Tableau;


// Déclaration des fonctions

/*
 * Le nom de la fonction : Creer_tableau
 * Entrées :
 *     int taille_max : La taille maximale du tableau
 * Sorties :
 *     Tableau* tableau : Le tableau creé
 * Déscription :
 *     Fait l'allocation dynamique d'un tableau dont la taille maximale
 * est taille_max
 */

Tableau Creer_tableau(int nombre_etudiant)
{
    Tableau tableau ;
    tableau.Etudiant = (int*) malloc(sizeof(int) * nombre_etudiant);
    tableau.dernier_etudiant = -1; // Car le tableau est vide
    tableau.nombre_etudiant = nombre_etudiant;
    return tableau;
}

/*
 * Le nom de la fonction : Remplire_tableau
 * Entrées :
 *     Tableau* tableau : le tableau à remplire
 * Description :
 *  Remplire les éléments du tableau par l'utilisateur
 */

void Remplire_tableau(Tableau *tableau)
{
    // La taille du tableau
    printf("\nREMPLISSAGE DU TABLEAU\n");
    printf("Veuillez entrer la taille du tableau : ");
    scanf("%d", &tableau->dernier_etudiant);
    tableau->dernier_etudiant--;
    
    // Remplissage du tableau
    printf("Veuillez entrer les éléments du tableau:\n");
    int i;
    for (i=0; i<=tableau->dernier_etudiant; i++)
    {
        printf("tableau[%d]=\t", i);
        scanf("%d", &tableau->Etudiant[i]);
    }
}

/*
 * Le nom de la fonction : Afficher_tableau
 * Entrées :
 *     Tableau tableau : Le tableau A afficher
 * Description :
 *     Affiche tous les éléments du tableau
 */
void Afficher_tableau(Tableau tableau)
{
    printf("\nAFFICHAGE DU TABLEAU:\n");
    int i;
    for (i=0; i<=tableau.dernier_etudiant; i++)
        printf("tableau[%d]=\t %d\n" ,i ,tableau.Etudiant[i]);
}


/*
 * Le nom de la fonction : Detruire_tableau
 * Entrées :
 *     Tableau* tableau : Le tableau à détruire
 * Description :
 *     Supprime la mémoire allouée pour le tableau
 */

void Detruire_tableau(Tableau *tableau)
{
    free(tableau->Etudiant);
    tableau->Etudiant = NULL;
    tableau->nombre_etudiant = 0;
}

/*
 * Nom de la fonction : Decalage_tableau
 * Entrées :
 *      Tableau* tableau : Le tableau contenant la partie à décaler
 *      int position : Position du premier element de la parite du tableau
 *   à décaler
 *      char sens : Le sens du decalage du tableau soit à gauche soit
 *   à droite
 * Description :
 *      Décale une partie du tableau soit à gauche soit à droite
 */

void Decalage_tableau(Tableau *tableau, int position, char sens)
{
    assert((sens == 'g' || sens == 'd'));
    assert(position > 0 || (position == 0 && sens == 'd'));
    assert(position <= tableau->dernier_etudiant);
    if(sens == 'd')
    {
        int i;
        for (i = tableau->dernier_etudiant; i >= position ; i--)
            tableau->Etudiant[i+1] = tableau->Etudiant[i];
        tableau->dernier_etudiant++;
    }
    else
    {
        int i;
        for (i = position; i <= tableau->dernier_etudiant ; i++)
            tableau->Etudiant[i-1] = tableau->Etudiant[i];
        tableau->dernier_etudiant--;
    }
}

/*
 * Le nom de la fonction : Ajout_Tableau
 * Entrées :
 *     Tableau* tableau : Le tableau auquel on va ajouter
 *     int element : L'élément à ajouter
 *     int indice : L'indice de la case du tableau à la quelle sera ajouté
 *   l'élément
 * Description :
 *     Ajoute un élément dans un tableau
 */

void Ajout_tableau(Tableau *tableau, int element, int indice)
{
    assert(indice >= 0);
    assert(indice < tableau->nombre_etudiant);
    assert(tableau->dernier_etudiant + 1 < tableau->nombre_etudiant);
    
    // Pas de décalage lors de l'ajout à la fin du tableau.
    if(indice <= tableau->dernier_etudiant )
        Decalage_tableau(tableau, indice,'d');
    else
        // Cette  incrémentation se fait dans Decalage_tableau
        // pour les autres cas.
        tableau->dernier_etudiant = indice ;
    tableau->Etudiant[indice] = element;
}

/*
 * Le nom de la fonction : Suppression_tableau
 * Entrées :
 *     Tableau* tableau : Le tableau dont un element sera détruit
 *     int indice : L'indice de la case dont l'élément sera détruit
 * Description :
 *     Supprime un élément d'un tableau
 */

void Suppression_tableau(Tableau *tableau, int indice)
{
    assert(tableau->dernier_etudiant > -1);
    assert(indice >= 0);
    assert(indice <= tableau->dernier_etudiant);
    // Supression au milieu ou au début
    if(indice != tableau->dernier_etudiant)
        Decalage_tableau(tableau, indice + 1, 'g');
    // Supression du dernier élément
    else
        tableau->dernier_etudiant--;
}

/*
 * Le nom de la fonction : Recherche_tableau
 * Entrées :
 *     Tableau tableau : Le tableau sur le quel on va effectuer
 *   la recherche
 *     int cible : l'élément recherché
 * Sorties :
 *     Tableau* resultat : Le tableau qui contient les emplacements de
 *   l'element recherché
 * Description :
 *     Fait la recherche d'un élément dans un tableau
 */

Tableau Recherche_tableau(Tableau tableau, int cible)
{
    Tableau resultat = Creer_tableau(tableau.nombre_etudiant);
    int i;
    for (i=0; i<=tableau.nombre_etudiant; i++)
        if(tableau.Etudiant[i] == cible)
            Ajout_tableau(&resultat, i,resultat.nombre_etudiant + 1);
    return resultat;
}

/*
 * Le nom de la fonction : Recherche_tableau
 * Entrées :
 *     Tableau tableau : Le tableau sur le quel on va effectuer
 *   la recherche
 *     int cible : l'élément recherché
 *     int min : Indice de la première borne
 *     int max : Indice de la deuxième borne
 * Sorties :
 *     Tableau* resultat : Le tableau qui contient les emplacements de
 *   l'element recherché
 * Description :
 *     Recherche dichotomique dans un tableau. Le tableau doit etre
 *   trié pour utiliser cette fonction.
 */

Tableau Recherche_dichotomique_tableau(Tableau tableau, int cible, int min, int max)
{
    Tableau resultat = Creer_tableau(tableau.nombre_etudiant);
    if(min > max)
        return resultat;
    else
    {
        int milieu = (min + max) / 2;
        
        if(cible > tableau.Etudiant[milieu])
            return Recherche_dichotomique_tableau(tableau, cible,
                                                  milieu + 1, max);
        else if(cible < tableau.Etudiant[milieu])
            return Recherche_dichotomique_tableau(tableau, cible,
                                                  min, milieu - 1);
        else
        {
            // Ajouter l'indice de l'element trouvé
            Ajout_tableau(&resultat, milieu, resultat.dernier_etudiant + 1);
            // Recherche d'autre occurences
            int i;
            for (i = milieu - 1;
                 i >= 0 && tableau.Etudiant[i] == cible;
                 i--)
                Ajout_tableau(&resultat, i, 0);
            
            for(i = milieu + 1;
                i<=tableau.dernier_etudiant && tableau.Etudiant[i] == cible;
                i++)
                Ajout_tableau(&resultat, i, resultat.dernier_etudiant + 1);
            
            return resultat;
        }
    }
}
