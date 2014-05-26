#ifndef DEF_MTF
#define DEF_MTF

//#include "blabla.h"
//#include "blabla.c"

#include <stdlib.h>
 

//Déclaration de la liste chainée
typedef struct element element;
struct element
{
	int val;
	int indice;	
	struct element *nxt;
};
 
typedef element* llist;



//Ajoute un élément en tete
llist ajouterEnTete(llist liste, int valeur);


//Affiche la liste chainée
void afficherListe(llist liste);

//Réalise le prétraitement MTF
//void MTF();

//Verifie si la liste est vide
int estVide(lliste liste);

#endif


