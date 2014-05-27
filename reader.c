#include<stdio.h>
#include<stdlib.h>
#include"liste_manager.h"

maillon* readFromFileAlphabet(char *nom){
    FILE *data;
    data = fopen(nom, "r+");
    maillon* Tete, AC;
    
    // Initialisation du tableau de fréquences, indicé par lettre de 0 a 25
    int freq[26];

    for(int i=0; i<26; i++)
        freq[i]=0;

    char c=fgetc(data);
    //freq[c-'a'] ++;
    //if (c != EOF){ 
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
      
    //}

    Tete = NULL;
    for(int i=0; i<26; i++){
        if (freq[i] != 0)
            Tete = ajoutEnTete(Tete, (char) i, freq[i]);
    }

    return Tete;
}

maillon* readFromFileBytes(char *nom){
    FILE *data;
    data = fopen(nom, "r+");
    maillon* Tete, AC;
    char octet = 0;
    char c;
    int nb=0;
    
    // Initialisation du tableau de fréquences, indicé par 0 à 255 pour chaque octet
    int freq[256];

    for(int i=0; i<256; i++)
        freq[i]=0;

    //char c=fgetc(data);
    //nb = fread(&octet,sizeof(char),1,data);
    do { 
        c = fgetc(data);
        //nb = fread(&octet,sizeof(char),1,data);
        printf("Octet numero %d \n",(int) c);
        if (octet != EOF )
            freq[(int) c] ++;
    }
    while ( c != EOF ); //nb !=0);
      
    Tete = NULL;
    for(int i=0; i<256; i++){
        if (freq[i] != 0)
            Tete = ajoutEnTete(Tete, (char) i, freq[i]);
    }

    return Tete;
}

