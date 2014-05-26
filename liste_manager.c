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

void print(maillon* tete)
{
	maillon* save;
	while(save != NULL)
	{
	printf("Symbole/Autre : %d / %d\n", save->lettre, save->autre);
	save = save->suivant;	
	}


//Verifie si la liste est vide
int estVide(maillon liste)
{
    if(liste == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

maillon* Allouer(int lettre, int autre){
    maillon* cellule = malloc(sizeof(maillon));
    cellule->lettre = lettre;
    cellule->autre = autre;
    return cellule;
}
