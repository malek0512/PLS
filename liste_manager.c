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
int estVide(maillon* liste)
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


//Recherche d'un élément
maillon* rechercherElement(maillon* liste, int valeur)
{
    maillon *tmp=liste;
    //Tant que l'on n'est pas au bout de la liste 
    while(tmp != NULL)
    {
        if(tmp->lettre == valeur)
        {
            // Si l'élément a la valeur recherchée, on renvoie son adresse
            return tmp;
        }
        tmp = tmp->suivant;
    }
    return NULL;
}



