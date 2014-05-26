#include<stdio.h>
#include<stdlib.h>
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
	maillon* save = tete;
	while(save != NULL)
	{
	printf("Symbole/Autre : %c / %d\n", save->lettre+'a', save->autre);
	save = save->suivant;	
	}
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

maillon* Allouer(int lettre, int autre){
    maillon* cellule = malloc(sizeof(maillon));
    cellule->lettre = lettre;
    cellule->autre = autre;
    return cellule;
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

//Recherche du ieme element
maillon* find_indice(maillon* liste, int indice)
{
    int i;
    // On se déplace de i cases, tant que c'est possible 
    for(i=0; i<indice && liste != NULL; i++)
    {
        liste = liste->suivant;
    }
 
    // Si l'élément est NULL, c'est que la liste contient moins de i éléments 
    if(liste == NULL)
    {
        return NULL;
    }
    else
    {
        // Sinon on renvoie l'adresse de l'élément i 
        return liste;
    }
}

