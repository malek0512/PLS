
#include "MTF.h"
#include <stdio.h>	
static maillon* liste;

void initList(){
    maillon* Queue;
    for(unsigned char i=0; i<256; i++){
        ajouterEnQueue(&liste,&Queue,i,i);
    }
}

maillon* MTF(maillon* texte){
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


