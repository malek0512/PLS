#include <stdlib.h>
#include <stdio.h>

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

void hufman();//Applique huffman et crée l'arbre
void jeVoudraisUnBonhommeDeNeige(); //init le tableau
void print();//affiche la table d'huffman
void letItGo();//libere le tableau
