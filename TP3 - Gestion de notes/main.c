#include <stdio.h>
#include "liste.h"
#include "fichier.h"

void Afficher_liste(Liste *liste)
{
    int i;
    printf("#\tCNE\t\tNom\tPrénom\tDate de naissance"
           "\tMoyenne\tValidé\n");
    for (i = 0; i < Taille_liste(liste); ++i)
    {
        Etudiant *etudiant = Acceder_liste(liste, i);
        printf("%d\t%s\t%s\t\%s\t%d/%d/%d\t\t%.2f\t%s\n",
               i + 1,
               etudiant->cne,
               etudiant->nom,
               etudiant->prenom,
               etudiant->date_naissance.jour,
               etudiant->date_naissance.mois,
               etudiant->date_naissance.annee,
               Moyenne_general(*etudiant),
               Reussite(*etudiant)? "oui":"non");
    }
}

int main(void)
{
    Liste *liste = NULL; // Liste des etudiants
    int reponse = 1; // reponse de l'utilisateur

    while(!liste)
    {
        printf("\n\n====================================================\n"
               "    1 - Ouvrir un fichier\n"
               "    2 - Créer une nouvelle liste\n"
               "autre - Quitter\nChoix : ");
        scanf("%d%*c", &reponse);
        printf("====================================================\n\n");

        switch (reponse) {
            case 1: // A partir d'un fichier
            {
                char nom_fichier[100];
                printf("Nom du fichier à ouvrir : ");
                scanf("%[^\n]", nom_fichier);
                liste = Lire_fichier(nom_fichier);
                if(!liste) printf("Impossible d'ouvrir le fichier\n");
                break;
            }
            case 2: // Nouvelle liste vide
                liste = Creer_liste();
                break;
            default: return 0;
        }
    }

    while(reponse >= 1 && reponse <= 5)
    {
        printf("\n======================================================\n"
               "    1 - Afficher tous les étudiants\n"
               "    2 - Afficher 1 étudiant\n"
               "    3 - Ajouter un étudiants\n"
               "    4 - Supprimer un étudiants\n"
               "    5 - Enregistrer dans un fichier\n"
               "autre - Quitter\n"
               "Choix : ");
        scanf("%d%*c", &reponse);
        printf("====================================================\n\n");

        switch (reponse) {
            case 1:
            {
                Liste *resultat = Classer_etudiants(liste);
                printf("AFFICHAGE DES ETUDIANTS (CLASSES)\n");
                Afficher_liste(resultat);
                Detruire_liste(resultat);
                break;
            }
            case 2 :
            {
                char cne[11];
                printf("Entrez un CNE : ");
                scanf("%s", cne);
                Etudiant *etudiant = Localiser_etudiant(liste, cne);
                if(etudiant) Afficher_etudiant(*etudiant);
                else printf("Etudiant inexistant");
                break;
            }
            case 3:
                printf("AJOUT D'UN ETUDIANT\n");
                Etudiant etudiant;
                printf("CNE : ");
                scanf("%s", etudiant.cne);
                printf("Nom : ");
                scanf("%s", etudiant.nom);
                printf("Prénom : ");
                scanf("%s", etudiant.prenom);
                printf("Date de naissance(JJ/MM/AAAA) : ");
                scanf("%d/%d/%d",
                      &etudiant.date_naissance.jour,
                      &etudiant.date_naissance.mois,
                      &etudiant.date_naissance.annee);
                printf("LES NOTES : \n");
                int i;
                for (i = 0; i < 36; ++i)
                {
                    printf("note %d : ", i);
                    scanf("%f", &etudiant.notes[i]);
                }
                Inserer_liste(liste, etudiant, Taille_liste(liste));
                break;
            case 4:
            {
                printf("LISTE DES ETUDIANTS\n");
                Afficher_liste(liste);
                int indice = 0;
                printf("Entrez le classement : ");
                scanf("%d", &indice);
                if(indice - 1 < 0 || indice - 1 >= Taille_liste(liste))
                    printf("Indice invalid\n");
                else Supprimer_liste(liste, indice - 1);
                break;
            }
            case 5:
            {
                char nom_fichier_sauvegarde[100];
                printf("Entrez le nom du fichier : ");
                scanf("%[^\n]", nom_fichier_sauvegarde);
                if(Ecrire_fichier(liste, nom_fichier_sauvegarde))
                    printf("Fichier enregistré avec succé\n");
                else
                    printf("Impossible d'enregistrer le fichier\n");
                break;
            }
        }
    }
    return 0;
}

