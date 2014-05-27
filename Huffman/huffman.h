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

//tranfere les info contenu sous forme de liste chainé
//en une liste d'arbre utiliser pour le codage d'huffman :D
void transfert(maillon* liste,arbre **tab, int taille);
