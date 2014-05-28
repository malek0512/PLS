
#include "MTF.h"
#include <stdio.h>


maillon* MTF(maillon* liste,char *mot){
	int i=0;
	int x;
	maillon *tmp,*tmp2;
	int taille = sizeof(mot);
	maillon *liste_retour = copieList(liste);
	maillon *liste_tmp = copieList(liste);	


	if (!estVide(liste_retour))
	{
	
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
		for (i;i<taille;i++)
		{

			tmp=rechercherElement(liste_retour,mot[i]);
			maillon copie;
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;
			tmp2=rechercherElement(liste_tmp,mot[i]);
			maillon copie2;
			copie2.lettre = tmp2->lettre;
			copie2.autre = tmp2->autre;
			printf("lettre %c\n",tmp->lettre);
			printf("autre %d\n",tmp->autre);
			liste_retour = supprimerElement(liste_retour,copie.lettre,copie.autre);
			liste_retour = ajoutEnTete(liste_retour,copie.lettre,copie2.autre);
			liste_tmp = supprimerElement(liste_tmp,copie2.lettre,copie2.autre);
			liste_tmp = ajoutEnTete(liste_tmp,copie.lettre,copie.autre);

			printf("liste\n");
			afficherListe(liste);
			printf("\n");
			printf("liste retour\n");
			afficherListe(liste_retour);
			printf("\n");
			printf("liste tmp\n");
			afficherListe(liste_tmp);
			printf("\n");
	
			copieAutre(liste,liste_tmp);

			printf("liste 2 \n");
			afficherListe(liste);
			printf("\n");
			printf("liste tmp 2\n");
			afficherListe(liste_tmp);
			printf("\n");

		}

		//changement des indices de la deuxieme liste chainée

		maillon *save = liste_retour;
		/*while((liste != NULL) && (liste_retour !=NULL))
		{
			liste_retour->autre = liste->autre;
			liste_retour = liste_retour->suivant;
			liste = liste->suivant;
			
		}*/
		return save;
	}
	
}







