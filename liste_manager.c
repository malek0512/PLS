#include<stdio.h>
#include<stdlib.h>
#include "liste_manager.h"


maillon* ajoutEnTete(maillon* liste, int lettre, int frequence){
	// On crée un nouvel élément 
	maillon* nouvelElement = malloc(sizeof(maillon));
 
	//On assigne la valeur au nouvel élément 
	nouvelElement->lettre = lettre;

	//On assigne la frequence au nouvel élément 
	nouvelElement->autre = frequence;
 
	//On assigne l'adresse de l'élément suivant au nouvel élément 
	nouvelElement->suivant = liste;
 
	//On retourne la nouvelle liste, i.e. le pointeur sur le premier élément
	return nouvelElement;
} 


maillon* ajouterEnQueue(maillon* liste, int lettre, int frequence)
{
	maillon* nouvelElement = malloc(sizeof(maillon));  
	nouvelElement->lettre = lettre;
	nouvelElement->autre = frequence;
 	// On ajoute en fin, donc aucun élément ne va suivre 
	nouvelElement->suivant = NULL;
 
	if(liste == NULL)
	{
		// Si la liste est videé il suffit de renvoyer l'élément créé 
		return nouvelElement;
	}
	else
	{
		/* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
		indique que le dernier élément de la liste est relié au nouvel élément */
		maillon* tmp=liste;
		while(tmp->suivant != NULL)
		{
			tmp = tmp->suivant;
		}
		tmp->suivant = nouvelElement;
		return liste;
    	}
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
	return res;
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
        if (save->lettre == -1)
            //On signal que c'est un caractere de EOF, théoriquement non present dans la liste
            printf("Symbole/Autre : %s / %d\n","Fin de fichier\0" , save->autre);
        else if (save->lettre == '\n')
            //On signal que c'est un retour charriot
            printf("Symbole/Autre : %s / %d\n","Retour charriot\0" , save->autre);
        else if (save->lettre <128 || save->lettre>=0)
            //On affiche le carctere
            printf("Symbole/Autre : %c / %d\n", save->lettre, save->autre);
        else
            //On affiche son numero
            printf("Symbole/Autre : Caractère numero %d / %d\n", save->lettre, save->autre);
        
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


//Fonction inutile pour l'instant ( j'en avais pas besoin enfaite , je la laisse a disposition si jamais )
//retourne l'indice d'un element
int return_indice(maillon* liste, int lettre, int autre)
{
	maillon *tmp=liste;
	int i=0;

	while(tmp != NULL)
	{
		if((tmp->lettre == lettre) && (tmp->autre == autre))
		{return i;}
		else
		{
			tmp = tmp->suivant;
			i++;
		}
	}
	printf("Erreur dans return_indice");
}

//Effacer tous les éléments ayant une certaine valeur
maillon* supprimerElement(maillon* liste, int lettre, int autre)
{
    // Liste vide, il n'y a plus rien à supprimer 
    if(liste == NULL)
        return NULL;
 
    // Si l'élément en cours de traitement doit être supprimé 
    if((liste->lettre == lettre) && (liste->autre == autre))
    {
        /* On le supprime en prenant soin de mémoriser 
        l'adresse de l'élément suivant */
        maillon* tmp = liste->suivant;
        free(liste);
        // L'élément ayant été supprimé, la liste commencera à l'élément suivant pointant sur une liste qui ne contient plus aucun élément ayant la valeur recherchée 
        tmp = supprimerElement(tmp, lettre,autre);
        return tmp;
    }
    else
    {
        /* Si l'élement en cours de traitement ne doit pas être supprimé,
        alors la liste finale commencera par cet élément et suivra une liste ne contenant
        plus d'élément ayant la valeur recherchée */
        liste->suivant = supprimerElement(liste->suivant, lettre,autre);
        return liste;
    }
}

maillon* copieList(maillon *liste)
{
maillon *res;
maillon *save = liste;
while(save != NULL)
	{
	res=ajouterEnQueue(res,save->lettre,save->autre);
	save = save->suivant;
	}
	return res;	
}


void afficherListe(maillon *liste)
{
   	maillon *tmp = liste;
    if(tmp != NULL) {
    while(tmp != NULL)
    {

        printf("\n%c, %d ", tmp->lettre,tmp->autre);

        tmp = tmp->suivant;
    }
	printf("\n");	}
}
