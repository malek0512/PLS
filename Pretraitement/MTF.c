
#include "MTF.h"
#include <stdio.h>	


maillon* MTF(maillon* liste,char *mot){
	int i=0;
	int x;
	maillon* tmp = NULL;
	maillon* tmp2 = NULL;
	int taille = sizeof(mot);
	maillon *liste_retour_T = NULL;
	maillon *liste_retour_Q = NULL;

	maillon *liste_tmp_Tete = NULL;
	maillon *liste_tmp_Queue = NULL;

	copieList(&liste,&liste_tmp_Tete,&liste_tmp_Queue);	

	if (!estVide(liste))
	{
	
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
		for (i;i<taille;i++)
		{

			tmp=rechercherElement(liste,mot[i]);
			maillon copie;
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;
			tmp2=rechercherElement(liste_tmp_Tete,mot[i]);
			maillon copie2;
			copie2.lettre = tmp2->lettre;
			copie2.autre = tmp2->autre;
			/*printf("lettre %c\n",tmp->lettre);
			printf("autre %d\n",tmp->autre);*/
			ajouterEnQueue(&liste_retour_T,&liste_retour_Q,copie.lettre,copie2.autre);
			liste_tmp_Tete = supprimerElement(liste_tmp_Tete,copie2.lettre,copie2.autre);
			ajoutEnTete(&liste_tmp_Tete,&liste_tmp_Queue,copie.lettre,copie.autre);
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
	
			copieAutre(liste,liste_tmp_Tete);
/*
			printf("liste 2 \n");
			afficherListe(liste);
			printf("\n");
			printf("liste tmp 2\n");
			afficherListe(liste_tmp);
			printf("\n");*/

		}

		return liste_retour_T;
	}
	
}


maillon* MTF2(maillon* liste, maillon* texte){
	maillon *tmp,*tmp2;
	maillon *liste_retour_Q= NULL;
	maillon *liste_retour_T= NULL;
	maillon *liste_tmp_T=NULL;
	maillon *liste_tmp_Q=NULL;
    	maillon* AC = texte;

	copieList(&liste,&liste_tmp_T,&liste_tmp_Q);

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
			tmp2=rechercherElement(liste_tmp_T,AC->lettre);
			maillon copie2;
			copie2.lettre = tmp2->lettre;
			copie2.autre = tmp2->autre;
			copie2.autre2 = tmp2->autre2;

		
			ajouterEnQueue2(&liste_retour_T,&liste_retour_Q,copie.lettre,copie2.autre,copie2.autre2);
			liste_tmp_T = supprimerElement2(liste_tmp_T,copie2.lettre,copie2.autre,copie2.autre2);
			ajoutEnTete2(&liste_tmp_T,&liste_tmp_Q,copie.lettre,copie.autre,copie.autre2);
			copieAutre2(liste,liste_tmp_T);

            AC = AC->suivant;
		}

		return liste_retour_T;
	}
	
}


