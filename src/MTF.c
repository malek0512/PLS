#include "../includes/MTF.h"
#include <stdio.h>	
maillon* deleteAndAdd(maillon* liste,unsigned char lettre)
{
	maillon* pred = liste;
	maillon* copie = liste;
	if(copie->lettre == lettre)
	{
		copie = copie->suivant;
		free(pred);
		return copie;
	}
	copie->autre = copie->autre + 1;
	copie = copie->suivant;
	while(copie->lettre != lettre)
	{
		copie->autre = copie->autre + 1;
		pred=copie;
		copie = copie->suivant;
	}
	pred->suivant = copie->suivant;
	free(copie);
	return liste;
}

maillon* MTF(maillon* texte){

	maillon* liste_T=NULL;
	maillon* liste_Q=NULL;
	maillon *tmp;
	maillon *liste_tmp_T=NULL;
	maillon *liste_tmp_Q=NULL;
    	maillon* AC = texte;
	maillon copie;
	//maillon copie2;
	for(int i=0; i<256; i++){
	ajouterEnQueue(&liste_T,&liste_Q,i,i);
	}

	if (!estVide(texte))
	{
        while(AC != NULL)
		{
			tmp=rechercherElement(liste_T,AC->lettre);
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;

			ajouterEnQueue(&liste_tmp_T,&liste_tmp_Q,copie.autre,copie.lettre);

			liste_T = deleteAndAdd(liste_T,copie.lettre);
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
	//maillon copie2;
	for(int i=0; i<256; i++){
	ajouterEnQueue(&liste_T,&liste_Q,i,i);
	}

	if (!estVide(texte))
	{
        while(AC != NULL)
		{
			tmp=rechercherElement2(liste_T,AC->lettre);
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;

			ajouterEnQueue(&liste_tmp_T,&liste_tmp_Q,copie.lettre,copie.autre);

			liste_T = deleteAndAdd(liste_T,copie.lettre);
			ajoutEnTete(&liste_T,&liste_Q,copie.lettre,0);
           		AC = AC->suivant;
		}
		liberer(liste_T);
		return liste_tmp_T;
	}
	return NULL;
}

