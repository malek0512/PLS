#include<stdio.h>
#include<stdlib.h>
#include"liste_manager.h"
#include"Huffman/huffman.h"

maillon* readFromFileAlphabet(FILE *data){
    maillon* Tete;    

    // Initialisation du tableau de fréquences, indicé par lettre de 0 a 25
    int freq[26];

    for(int i=0; i<26; i++)
        freq[i]=0;

    char c=fgetc(data);
    //freq[c-'a'] ++;
    //if (c != EOF){ 
    if (c != EOF){ 
        do { 
            if (c>='a' && c<='z'){  
                freq[c-'a'] ++;
            }
            else if (c>='A' && c<='Z'){
                freq[c-'A'] ++;
            }
            c = fgetc(data);
        }
        while (c != EOF);
    }
    Tete = NULL;
    for(int i=0; i<26; i++){
        if (freq[i] != 0)
            Tete = ajoutEnTete(Tete, (char) i, freq[i]);
    }

    return Tete;
}

void readFromFileBytesWithFrequency(maillon** Tete, maillon** Queue, FILE *data){
    char octet = 0;
    int nb=0;

    // Initialisation du tableau de fréquences, indicé par 0 à 255 pour chaque octet
    int freq[256];

    for(int i=0; i<256; i++)
        freq[i]=0;

    do {
        nb = fread(&octet,sizeof(char),1,data);

        //Dans le cas où le premier octet est la fin de fichier
        if (octet != EOF )
            freq[(int) octet] ++;
    }
    while ( nb != 0); 

    *Tete = NULL;
    for(int i=0; i<256; i++){
        if (freq[i] != 0){ 
            ajoutEnQueue(Tete, Queue, (char) i, freq[i]);
        }
    }
}

void readFromFileBytesInOrder(maillon** Tete, maillon** Queue, FILE *data){
    int octet = 0;
//    int nb=0;

    *Queue = NULL;
    *Tete = NULL;
//    do { 
//        nb = fread(&octet,sizeof(char),1,data);
//        if (octet != EOF ){ 
//            //Ajout en Queue avec fonction ajout en tete
//            ajoutEnQueue(Tete,Queue, octet, -1);
//
//        }
//    }
//    while ( nb != 0); 
      while((octet = fgetc(data)) != EOF){
            ajoutEnQueue(Tete,Queue,(char) octet, -1);
      }
}

char readFromFileByte(FILE *data){
    return fgetc(data);
}


int readFromFileInt(FILE *data){
    int integer;
    fread(&integer,sizeof(int),1,data);
    return integer;
}

void writeListeBytes(maillon* Tete, FILE* data){
    maillon* AC;
    AC = Tete;
    while (AC != NULL){
        fputc(AC->lettre, data);
        AC = AC->suivant;
    }
}

void writeByte(char byte, FILE* data){
    fputc(byte, data);
}

FILE* CreerFichier(char *nom_fichier){
    return fopen(nom_fichier,"w");
}

FILE* OuvrirFichier(char *nom_fichier){
    FILE* f = fopen(nom_fichier,"r");
    if (f == NULL){ 
        printf("Erreur d'ouverture de fichier");
        exit(1);
    } else
        return f;
}
maillon* calculateFrequency(maillon* Tete){
    maillon* AC = Tete;

    // Initialisation du tableau de fréquences, indicé par 0 à 255 pour chaque octet
    int freq[256];

    for(int i=0; i<256; i++)
        freq[i]=0;

    while (AC != NULL){ 
        freq[(int) AC->lettre] ++;
        AC = AC->suivant;
    }

    maillon *resTete = NULL, *resQueue=NULL;
    for(int i=0; i<256; i++){
        if (freq[i] != 0){ 
            ajoutEnQueue(&resTete, &resQueue, (char) i, freq[i]);
        }
    }
    return resTete;
}
void writeHuffmanTable(arbre* treeHuffman, FILE* fileCompressed){ 
    maillon* Table =  creationTableHuffman(treeHuffman);
    maillon* AC = Table;
    while(AC != NULL){
        writeByte(AC->lettre, fileCompressed);
        writeByte((char) AC->autre, fileCompressed); //Le codage du symbole ne depasse pas 1 octet
        writeByte((char) AC->autre2, fileCompressed); //Le nombre de bit significatif d'un octet est de toute façon limité a 0 < bit < 8 < 255.
        AC = AC->suivant;
    }
    writeByte('#', fileCompressed);
    writeByte('#', fileCompressed);
    writeByte('#', fileCompressed);
}


maillon* readHuffmanTable(maillon** Tete, maillon** Queue){ 
    //Declarations
    maillon* AC = *Tete, *tableHead=NULL; 

    if (AC != NULL && AC->suivant != NULL && AC->suivant->suivant !=NULL){ //Size>=3
        //Nous lisons la table
        //Tant que le maillon suivant AC != Queue (donc j'ai au moins 3 symbole a lire) et que ce n'est pas une succession de 3 #
        while (AC != NULL && AC->suivant != *Queue && !(AC->lettre == '#' && AC->suivant->lettre == '#' && AC->suivant->suivant->lettre == '#')){

            ajouterEnQueue2(&tableHead, AC->lettre, AC->suivant->lettre, AC->suivant->suivant->lettre);
            AC = AC->suivant->suivant->suivant;
        }
        if (AC !=NULL && AC->suivant != *Queue) {
            //C'est que j'ai fini de lire la table car j'ai rencontré les 3#

            //On saute les 3#
            AC = AC->suivant->suivant->suivant;

            //Soit il n'y a aucun symbole, donc AC==NULL 
            if (AC == NULL){
                printf("\nNous avons lu la table. Il n'y a aucun symbole codé\n");
                exit(1);
            }
            //Soit il ne reste qu'un octet et il manque le nombre de bit significatif, donc AC == Queue
            if (AC == *Queue){
                printf("\nNous avons lu la table. Mais il n'y a qu'un symbole de codé. Il manque donc le nombre de bit significatif du dernier octet\n");
                exit(1);
            }

            //Soit il y a au moins 1 symbole et il est suivi de 1 octet indiquant le nombre de bit significatif, donc AC !=NULL et AC->suivant==Queue

            *Tete = AC;
            AC = *Tete;
            while (AC->suivant != (*Queue)){
                //Tous les octets avant l'avant dernier octet, ont 8 bits significatifs
                AC->autre = 8;
                AC = AC->suivant;
            }
            // On met a jour le nombre de bit significatif de l'avant dernier octet lu
            AC->autre = (int) (*Queue)->lettre;

            // Le dernier octet lu est le nombre de bit significatif de l'avant dernier octet
            //On supprime le dernier octet
            (*Queue) = AC;
            (*Queue)->suivant = NULL;


            return tableHead;
        } else {
            if(AC == NULL)
                printf("Nous n'avons pas pu lire la table, AC==NULL");
            else
                printf("Nous n'avons pas pu lire la table, AC->suivant == Queue ");
            exit(1);
        }
    } else { 
        printf("Erreur de lecture de la table : Size(fichier)<3");
        exit(1);
    }
}
