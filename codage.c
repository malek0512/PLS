#include<stdio.h>
#include<stdlib.h>
#include"liste_manager.h"
#include"Huffman/huffman.h"
#include"Pretraitement/MTF.h"
#include"Pretraitement/RLE.h"
#include"reader.h"
#include<string.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("Donner un fichier en argument\n");
        exit(1);
    } else {

        FILE* file = OuvrirFichier(argv[1]);
        FILE* fileCompressed = CreerFichier("Compresser"); //strcat(argv[1],".Comp"));
        maillon *Tete, *Queue, *resultatTete=NULL;
        arbre *tab = NULL;
        int choix;

        readFromFileBytesInOrder(&Tete,&Queue,file);
        fclose(file);

        printf("Veuillez faire un choix de compression : \n 1 - RLE \n 2 - MTF \n 3 - Huffman \n 4 - Combinaison des 3 modes de compression \n");
        scanf("%d", &choix);

        switch(choix){
            case 1: 
                coderRle(Tete); 
                writeListeBytes(Tete,fileCompressed);
                break;
            case 2: 
                //resultatTete = MTF(Tete); 
                //writeListeBytes(resultatTete,fileCompressed);
                //liberer(resultatTete);
                break;
            case 3: { 
                //Calcul de la table de de Huffman
                maillon *listeFrequency=NULL;
                listeFrequency = calculateFrequency(Tete);
                tab = ArbreHufman(listeFrequency);
                //liberer(listeFrequency);

                print2(Tete);
                print2(listeFrequency);
                printArbre(tab);
                resultatTete = codageHuffman(Tete, tab);
                printf("\n Message Codé \n");
                print2(resultatTete);
                writeListeBytes(resultatTete,fileCompressed);

                //Ecriture du nombre de bit significatif du dernier octet
                writeByte( (char) getQueue(resultatTete)->autre,fileCompressed);
                liberer(resultatTete);
                break;
                    }
            case 4: 
                //coderRle(Tete);
                //resultatTete = codageHuffman(Tete, ArbreHufman(Tete));
                //writeListeBytes(resultatTete,fileCompressed);
                //liberer(resultatTete);
                break;

            default: printf("Erreur de choix");
        }

                liberer(Tete);
                fclose(fileCompressed);
    }
    return 0;
}
