#ifndef DEF_READER
#define DEF_READER
#include "huffman.h"	// j'ai été oubligée de rajouter cette ligne pour que ça compile chez moi
								// à enlever si jamais ça vous pose problème...

//Retourne la liste des caracteres lus dans un fichier, le champs <autre> contient le nombre d'occurence du caractère
//Attention l'ordre n'est pas pertinent
maillon* readFromFileAlphabet(FILE *data);

//Crée la liste des caracteres lus dans un fichier, le champs <autre> contient la le nombre d'occurence du caractère
//Attention l'ordre n'est pas pertinent
void readFromFileBytesWithFrequency(maillon** Tete, maillon** Queue, FILE *data);

//Crée la liste des caracteres lus dans un fichier dans l'ordre de lecture
//Les paramètres de pointeurs de Tete et Queue sont modifié.
//Attention la valeur fréquence n'est pas pertinente
void readFromFileBytesInOrder(maillon** Tete, maillon** Queue, FILE *data);

//Ecrit un octet dans un fichier
unsigned readFromFileByte(FILE *data);

//Ecrit un Integer dans un fichier, utile pour l'ecriture d'un coadage de huffman, pour preciser la taille des octets significatif du dernier octet
int readFromFileInt(FILE *data);

//Ecrit la liste d'octets passée en parametre, dans le fichier passé en paramètre
//Ne modifie pas la liste chainée
void writeListeBytes(maillon* Tete, FILE* data);

//Ecrit un octet passé en parametre, dans le fichier passé en paramètre
void writeByte(unsigned byte, FILE* data);

//Ecrit un octet passé en parametre, dans le fichier passé en paramètre
void writeInt(int Int, FILE* data);

FILE* CreerFichier(char *nom_fichier);
FILE* OuvrirFichier(char *nom_fichier);

maillon* calculateFrequency(maillon* Tete);
void writeHuffmanTable(arbre* treeHuffman, FILE* fileCompressed); 
maillon* readHuffmanTable(maillon** Tete, maillon** Queue);

// Rajoute les octets "RLE" en début d'un fichier
// Permet d'indiquer qu'un fichier a été codé en RLE
// Auteur : Marie
void writeRle(maillon** Tete);

#endif
