#include <stdlib.h>
#include <stdio.h>
#include "../liste_manager.h"

//#### TypeDef ###//
typedef struct info
{
	int proba;
	int symbole;
}info;

typedef struct arbre
{
	struct arbre *G;
	struct arbre *D;
	info i;
}arbre;

//Applique huffman et crée l'arbre
//la recuperation du resultat reste a decider
arbre* ArbreHufman(maillon* liste);

//affiche le tableau de huffman
void printArbre(arbre* tree);

//utiliser pour le printAbre
void printArbre_rec(arbre* tree,int value,int taille);

