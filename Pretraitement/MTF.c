
#include "MTF.h"
#include <stdio.h>	
static maillon* liste_T=NULL;
static maillon* liste_Q=NULL;

void initList(){
    for(int i=0; i<256; i++){
        ajouterEnQueue(&liste_T,&liste_Q,i,i);
    }
}

maillon* MTF(maillon* texte){
void incrementerAfter()
{
	maillon* tmp = liste_T;
	while(tmp != NULL)
	{
		tmp->autre++;
		tmp = tmp -> suivant;
	}
}
	maillon *tmp;
	maillon *liste_tmp_T=NULL;
	maillon *liste_tmp_Q=NULL;
    	maillon* AC = texte;
	maillon copie;
	maillon copie2;
	initList();
	
	if (!estVide(texte))
	{
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
        while(AC != NULL)
		{
			tmp=rechercherElement(liste_T,AC->lettre);
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;

			ajouterEnQueue(&liste_tmp_T,&liste_tmp_Q,copie.autre,copie.lettre);
			
			incrementerAfter();
			liste_T = supprimerElement(liste_T,copie.lettre,copie.autre-1);
			ajoutEnTete(&liste_T,&liste_Q,copie.lettre,0);
           		AC = AC->suivant;
		}

		return liste_tmp_T;
	}
	return NULL;
}



