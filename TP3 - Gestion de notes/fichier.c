#include "fichier.h"

Liste* Lire_fichier(char *nom_fichier)
{
    Liste *liste = Creer_liste();
    FILE *fichier = fopen(nom_fichier, "r");
    if(fichier)
    {
        while(!feof(fichier))
        {
            Etudiant etudiant;
            if(fscanf(fichier, "%[^,],%[^,],%[^,],%d/%d/%d", etudiant.cne,
                   etudiant.nom, etudiant.prenom,
                   &etudiant.date_naissance.jour,
                   &etudiant.date_naissance.mois,
                   &etudiant.date_naissance.annee) == EOF) break;
            int i;
            for (i = 0; i < 37; ++i)
            fscanf(fichier, ",%f", &etudiant.notes[i]);
            fgetc(fichier);
            Inserer_liste(liste, etudiant, Taille_liste(liste));
        }
        return liste;
    }
    else return NULL;
}


int Ecrire_fichier(Liste *liste, char *nom_fichier)
{
    FILE *fichier = fopen(nom_fichier, "w+");
    if(fichier)
    {
        int i,j;
        for (i = 0; i < Taille_liste(liste); ++i) {
            Etudiant *etudiant = Acceder_liste(liste, i);
            fprintf(fichier, "%s,%s,%s,%d/%d/%d", etudiant->cne,
                    etudiant->nom, etudiant->prenom,
                    etudiant->date_naissance.jour,
                    etudiant->date_naissance.mois,
                    etudiant->date_naissance.annee);
            for (j = 0; j < 36; ++j)
                fprintf(fichier, ",%.2f", etudiant->notes[j]);
            fprintf(fichier, "\n");
        }
        fclose(fichier);
        return 1;
    }
    else return 0;
}
