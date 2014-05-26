#include "liste_manager.h"


maillon* ajoutEnTete(maillon* Tete, int lettre, int frequence){

	// On crée un nouvel élément 
	maillon* nouvelElement = malloc(sizeof(maillon));
 
	//On assigne la valeur au nouvel élément 
	nouvelElement->lettre = lettre;

	//On assigne la frequence au nouvel élément 
	nouvelElement->autre = frequence;
 
	//On assigne l'adresse de l'élément suivant au nouvel élément 
	nouvelElement->suivant = Tete;
 
	//On retourne la nouvelle liste, i.e. le pointeur sur le premier élément
	return nouvelElement;
    
}


int size(maillon* tete)
{
int res = 1;
maillon* save=tete;

if (save == NULL)
	return 0;
while(save->suivant != NULL)
	{
	save = save->suivant;
	res++;
	}
}

void liberer(maillon* tete)
{
	if(tete->suivant != NULL)
		liberer(tete->suivant);
	free(tete);
}


