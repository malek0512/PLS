
#include "MTF.h"
#include <stdio.h>
void afficherListe2(maillon *liste);

void MTF(maillon* liste,char *mot){
	int i=0;
	int x;
	maillon *tmp;
	int taille = sizeof(mot);
	//maillon *liste_retour = liste
	maillon *liste_retour = copieList(liste);

	if (!estVide(liste_retour))
	{
	
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
		for (i;i<taille;i++)
		{
			tmp=rechercherElement(liste_retour,mot[i]);
			maillon copie;
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;
			liste_retour = supprimerElement(liste_retour,copie.lettre,copie.autre);
			liste_retour = ajoutEnTete(liste_retour,copie.lettre,copie.autre);

		}
		afficherListe(liste);
		afficherListe(liste_retour);
		//changement des indices de la deuxieme liste chainée

		afficherListe(liste);
		while((liste != NULL) && (liste_retour !=NULL))
		{
			printf("test1\n");
			afficherListe2(liste_retour);
			afficherListe2(liste);

			liste_retour->autre = liste->autre;
			printf("test2\n");
			afficherListe2(liste_retour);
			afficherListe2(liste);

			liste_retour = liste_retour->suivant;
			printf("test3\n");
			afficherListe2(liste_retour);
			afficherListe2(liste);
		
			liste = liste->suivant;
			printf("test4\n");
			afficherListe2(liste_retour);
			afficherListe2(liste);			
		}

	}
}

void afficherListe2(maillon *liste)
{
   	maillon *tmp = liste;

    while(tmp != NULL)
    {

        printf("\n%c, %d ", tmp->lettre,tmp->autre);

        tmp = tmp->suivant;
    }
	printf("\n");	
}





