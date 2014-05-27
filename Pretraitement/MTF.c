
#include "MTF.h"


void MTF(maillon* liste,char *alphabet){
	int i=0;
	int x;
	maillon *tmp;
	int taille = strlen(alphabet);
	maillon *liste_retour = liste;
	
	if (!estVide(liste))
	{
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
		for (i;i<taille;i++)
		{
			tmp=rechercherElement(liste_retour,alphabet[i]);
			liste_retour = supprimerElement(liste_retour,tmp->lettre,tmp->autre);
			liste_retour = ajoutEnTete(liste_retour,tmp->lettre,tmp->autre);
		}
		
		//changement des indices de la deuxieme liste chainée

		
		while((liste != NULL) && (liste_retour !=NULL))
		{
			liste_retour->autre == liste->autre;
			liste_retour = liste_retour->suivant;
			liste = liste->suivant;
		}
	}
}






