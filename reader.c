#include<stdio.h>
#include<stdlib.h>
#include"liste_manager.h"

maillon* readFromFile(char *nom){
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
        if (c>'a' && c<'z')
        { 
            freq[c-'a'] ++;
            c = fgetc(data);
        }
        else if (c>'A' && c<'Z')
        {
            freq[c-'A'] ++;
            c = fgetc(data);
        }
        printf("waza");
    }
    while (c != EOF);
      
    //}

    Tete = NULL;
    for(int i=0; i<26; i++){
        if (freq[i] != 0)
            Tete = ajoutEnTete(Tete, i, freq[i]);
    }

    return Tete;
}

