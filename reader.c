#include<stdio.h>
#include<stdlib.h>

maillon* readFromFile(char *nom){
    FILE data;
    data = fopen(nom, "r+");
    maillon* Tete, AC;
    // Initialisation du tableau de fréquences, indicé par lettre de 0 a 25
    unsigned int freq[26];
    for(int i=0; i<25; i++)
        freq[i]=0;

    char c;
    do while (c != EOF){
        c = getchar(data);
        freq[c-'a'] ++;
    }

    for(int i=0; i<25; i++){
        Tete = AjouterEnTete(i, freq[i], Tete);
    }

    return Tete;
}

