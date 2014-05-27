#include <stdlib.h>
#include <stdio.h>
#include "../liste_manager.h"

//gauche zero ; droite 1
//#### TypeDef ###//
typedef struct info
{
	int proba;
	char symbole;
}info;

typedef struct arbre
{
	struct arbre *G;
	struct arbre *D;
	info i;
}arbre;


//Prend en argument une liste et ca table de huffman, crée par la fonction ArbreHuffman
//retourne la liste codé
maillon* codageHuffman(maillon *liste, arbre *tableHuffman);

//Prend en argument une liste codé par huffman et ca table de huffman, crée par la fonction ArbreHuffman
//retourne la liste décodé
maillon* decodageHuffman(maillon *liste, arbre *tableHuffman);

//Retourne la table d'huffman a partir de l'arbre
maillon* creationTableHuffman(arbre* arbreHuffman)

//Crée la table d'huffman associer a la liste donné
arbre* ArbreHufman(maillon* liste);

//affiche le tableau de huffman
void printArbre(arbre* tree);

//utiliser pour le printAbre
void printArbre_rec(arbre* tree,int value,int taille);

