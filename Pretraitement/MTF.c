
#include "MTF.h"
#include <stdio.h>	

maillon* MTF(maillon* texte){
void incrementerAfter(unsigned char lettre,maillon* liste_T)
{
	maillon* tmp = liste_T;
	while(tmp->lettre != lettre)
	{
		tmp->autre++;
		tmp = tmp -> suivant;
	}
}
	maillon* liste_T=NULL;
	maillon* liste_Q=NULL;
	maillon *tmp;
	maillon *liste_tmp_T=NULL;
	maillon *liste_tmp_Q=NULL;
    	maillon* AC = texte;
	maillon copie;
	maillon copie2;
	for(int i=0; i<256; i++){
	ajouterEnQueue(&liste_T,&liste_Q,i,i);
	}
	
	if (!estVide(texte))
	{
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
        while(AC != NULL)
		{
			tmp=rechercherElement(liste_T,AC->lettre);
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;

			ajouterEnQueue(&liste_tmp_T,&liste_tmp_Q,copie.autre,copie.lettre);
			
			incrementerAfter(tmp->lettre,liste_T);
			liste_T = supprimerElement(liste_T,copie.lettre,copie.autre-1);
			ajoutEnTete(&liste_T,&liste_Q,copie.lettre,0);
           		AC = AC->suivant;
		}
		liberer(liste_T);
		return liste_tmp_T;
	}
	return NULL;
}

maillon* MTF2(maillon* texte){
void incrementerAfter(unsigned char lettre,maillon* liste_T)
{
	maillon* tmp = liste_T;
	while(tmp->lettre != lettre)
	{
		tmp->autre++;
		tmp = tmp -> suivant;
	}
}

maillon* rechercherElement2(maillon* liste,int value)
{
	maillon* tmp = liste;
	while(tmp != NULL)
	{	
		if(tmp->autre == value)
			 return tmp;
		tmp = tmp->suivant;
	}
	return NULL;
}

	maillon* liste_T=NULL;
	maillon* liste_Q=NULL;
	maillon *tmp;
	maillon *liste_tmp_T=NULL;
	maillon *liste_tmp_Q=NULL;
    	maillon* AC = texte;
	maillon copie;
	maillon copie2;
	for(int i=0; i<256; i++){
	ajouterEnQueue(&liste_T,&liste_Q,i,i);
	}

	if (!estVide(texte))
	{
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
        while(AC != NULL)
		{
fprintf(stderr,"Bug ? RLy ?\n");
			tmp=rechercherElement2(liste_T,AC->lettre);
fprintf(stderr,"\nBug pas !\n");
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;

			ajouterEnQueue(&liste_tmp_T,&liste_tmp_Q,copie.lettre,copie.autre);
			
			incrementerAfter(tmp->lettre,liste_T);
			liste_T = supprimerElement(liste_T,copie.lettre,copie.autre-1);
			ajoutEnTete(&liste_T,&liste_Q,copie.lettre,0);
           		AC = AC->suivant;
		}
		liberer(liste_T);
		return liste_tmp_T;
	}
	return NULL;
}

