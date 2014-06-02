
#include "MTF.h"
#include <stdio.h>	


maillon* MTF(maillon* liste,char *mot){
	int i=0;
	int x;
	maillon *tmp,*tmp2;
	int taille = sizeof(mot);
	maillon *liste_retour = NULL;
	maillon *liste_tmp = copieList(liste);	


	if (!estVide(liste))
	{
	
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
		for (i;i<taille;i++)
		{

			tmp=rechercherElement(liste,mot[i]);
			maillon copie;
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;
			tmp2=rechercherElement(liste_tmp,mot[i]);
			maillon copie2;
			copie2.lettre = tmp2->lettre;
			copie2.autre = tmp2->autre;
			/*printf("lettre %c\n",tmp->lettre);
			printf("autre %d\n",tmp->autre);*/
			liste_retour = ajouterEnQueue(liste_retour,copie.lettre,copie2.autre);
			liste_tmp = supprimerElement(liste_tmp,copie2.lettre,copie2.autre);
			liste_tmp = ajoutEnTete(liste_tmp,copie.lettre,copie.autre);
/*
			printf("liste\n");
			afficherListe(liste);
			printf("\n");
			printf("liste retour\n");
			afficherListe(liste_retour);
			printf("\n");
			printf("liste tmp\n");
			afficherListe(liste_tmp);
			printf("\n");*/	
	
			copieAutre(liste,liste_tmp);
/*
			printf("liste 2 \n");
			afficherListe(liste);
			printf("\n");
			printf("liste tmp 2\n");
			afficherListe(liste_tmp);
			printf("\n");*/

		}

		return liste_retour;
	}
	
}


maillon* MTF2(maillon* liste, maillon* texte){
	maillon *tmp,*tmp2;
	maillon *liste_retour = NULL;
	maillon *liste_tmp = copieList2(liste);	
    maillon* AC = texte;


	if (!estVide(liste))
	{
	
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
        while(AC != NULL)
		{

			tmp=rechercherElement(liste,AC->lettre);
			maillon copie;
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;
			copie.autre2 = tmp->autre2;
			tmp2=rechercherElement(liste_tmp,AC->lettre);
			maillon copie2;
			copie2.lettre = tmp2->lettre;
			copie2.autre = tmp2->autre;
			copie2.autre2 = tmp2->autre2;

		
			liste_retour = ajouterEnQueue3(liste_retour,copie.lettre,copie2.autre,copie2.autre2);
			liste_tmp = supprimerElement2(liste_tmp,copie2.lettre,copie2.autre,copie2.autre2);
			liste_tmp = ajoutEnTete2(liste_tmp,copie.lettre,copie.autre,copie.autre2);
			copieAutre2(liste,liste_tmp);

            AC = AC->suivant;
		}

		return liste_retour;
	}
	
}


