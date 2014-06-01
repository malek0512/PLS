#ifndef DEF_READER
#define DEF_READER

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
char readFromFileByte(FILE *data);

//Ecrit un Integer dans un fichier, utile pour l'ecriture d'un coadage de huffman, pour preciser la taille des octets significatif du dernier octet
int readFromFileInt(FILE *data);

//Ecrit la liste d'octets passée en parametre, dans le fichier passé en paramètre
//Ne modifie pas la liste chainée
void writeListeBytes(maillon* Tete, FILE* data);

//Ecrit un octet passé en parametre, dans le fichier passé en paramètre
void writeByte(char byte, FILE* data);

FILE* CreerFichier(char *nom_fichier);
FILE* OuvrirFichier(char *nom_fichier);

maillon* calculateFrequency(maillon* Tete);
void writeHuffmanTable(arbre* treeHuffman, FILE* fileCompressed); 
#endif
