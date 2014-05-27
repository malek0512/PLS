#include<stdio.h>
#include<stdlib.h>
#include"liste_manager.h"

maillon* readFromFileAlphabet(char *nom){
    FILE *data;
    data = fopen(nom, "r");
    maillon* Tete, AC;    

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

    fclose(data);
    return Tete;
}

void readFromFileBytesWithFrequency(maillon** Tete, maillon** Queue, char *nom){
    FILE *data;
    data = fopen(nom, "r");
    maillon* AC;
    char octet = 0;
    //char c;
    int nb=0;

    // Initialisation du tableau de fréquences, indicé par 0 à 255 pour chaque octet
    int freq[256];

    for(int i=0; i<256; i++)
        freq[i]=0;

    do {
        nb = fread(&octet,sizeof(char),1,data);
        /*printf("Octet numero %d \n",(int) octet);*/
        if (octet != EOF )
            freq[(int) octet] ++;
    }
    while ( nb != 0); 

    *Tete = NULL;
    for(int i=0; i<256; i++){
        if (freq[i] != 0){ 
            if (i==0){ 
                *Queue = ajoutEnTete(*Queue, (char) i, freq[i]);
                *Tete = *Queue;
            } else
                ajoutEnQueue(Queue, (char) i, freq[i]);
        }
    }
    fclose(data);
}

void readFromFileBytesInOrder(maillon** Tete, maillon** Queue, char *nom){
    FILE *data;
    data = fopen(nom, "r");
    maillon* AC;
    char octet = 0;
    int nb=0, nb_octet=0;

    *Queue = NULL;
    *Tete = NULL;
    do { 
        nb = fread(&octet,sizeof(char),1,data);
        if (octet != EOF ){ 
            //Ajout en Queue avec fonction ajout en tete
            if (nb_octet==0){  
                *Queue = ajoutEnTete(*Queue, octet, -1);
                *Tete = *Queue;
            } else
                ajoutEnQueue(Queue, octet, -1);

            nb_octet++;
        }
    }
    while ( nb != 0); 
    fclose(data);
}

void writeListeBytes(maillon* Tete, maillon* Queue, FILE* data){
    maillon* AC = Queue;
    //Si Queue == NULL alors Tete == NULL donc la liste est vide
    if (AC != NULL){ 
        //On se trouve a la derniere cellule, on ecrit le nombre de bit significatif du dernier octet 
        fwrite(&(AC->autre), sizeof(AC->autre),1,data); //L'affichage sous hexpdumb -Cn 60 "fichier" confirme l'ecriture de l'integer. Peut etre mal interprété par l'editeur de texte
        fputc('\n', data);

        AC = Tete;
        while (AC != NULL){
            fputc(AC->lettre, data);
            AC = AC->suivant;
        }
    }
}

