#ifndef DEF_READER
#define DEF_READER


//Retourne la liste des caracteres lus dans un fichier, le champs <autre> contient le nombre d'occurence du caractère
//Attention l'ordre n'est pas pertinent
maillon* readFromFileAlphabet(char *nom);

//Crée la liste des caracteres lus dans un fichier, le champs <autre> contient la le nombre d'occurence du caractère
//Attention l'ordre n'est pas pertinent
void readFromFileBytesWithFrequency(maillon** Tete, maillon** Queue, char *nom);

//Crée la liste des caracteres lus dans un fichier dans l'ordre de lecture
//Les paramètres de pointeurs de Tete et Queue sont modifié.
//Attention la valeur fréquence n'est pas pertinente
void readFromFileBytesInOrder(maillon** Tete, maillon** Queue, char *nom);

//Ecrit un bit dans la liste chainée passée en parametre. N'effectue que des ajouts en queue
//Attention, NE PAS OUBLIER d'ECRIRE LE NOMBRE DE BITS SIGNIFICATIF (après encodage) DANS LA CELULLE QUEUE (champs <autre>).
//author : Malek
void writeBit(maillon** Tete, maillon** Queue, char bit);

//Ecrit la liste d'octets passée en parametre, dans le fichier passé en paramètre
//Ne modifie pas la liste chainée
void writeListeBytes(maillon* Tete, maillon* Queue, FILE* data);

//Ajoute en Queue un maillon
void ajoutEnQueue(maillon** Queue, char byte, int autre);
#endif
