#ifndef DEF_HUFFMAN
#define DEF_HUFFMAN

#include <stdlib.h>
#include <stdio.h>
#include "liste_manager.h"

//gauche zero ; droite 1
//#### TypeDef ###//
typedef struct info
{
	int proba;
	unsigned char symbole;
}info;

typedef struct arbre
{
	struct arbre *G;
	struct arbre *D;
	info i;
}arbre;


//retourne la table de Huffman,
//prend un arbre de Huffman
//author : Alex
maillon* creationTableHuffman(arbre* arbreHuffman);

//author : Alex
//maillon -> lettre == symbole sans codage
//la liste de retour sera de la forme (octect / nb Significatif (effectif que pour le dernier bit))
maillon* codageHuffman(maillon *liste, arbre *arbreHuffman);

//Prend en argument une liste et ca table de huffman, crée par la fonction ArbreHuffman
//retourne la liste codé
//Et paf, un autre miracle apparait !
//Author Alex
maillon* decodageHuffman(maillon *liste, arbre *tableHuffman);

//Retourne la table d'huffman a partir de l'arbre
maillon* creationTableHuffman(arbre* arbreHuffman);

//Crée la table d'huffman associer a la liste donné
arbre* ArbreHufman(maillon* liste);

//affiche le tableau de huffman
void printArbre(arbre* tree);

//retourne l'arbre associé a une table huffman
arbre* arbreFromTable(maillon *table);

//utiliser pour le printAbre
void printArbre_rec(arbre* tree,int value,int taille);


#endif
