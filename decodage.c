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
        FILE* fileCompressed = CreerFichier("Decompresser"); //strcat(argv[1],".Decompresse"));
        maillon *Tete, *Queue, *resultatTete=NULL;
        int choix;

        readFromFileBytesInOrder(&Tete,&Queue,file);
        fclose(file);

        printf("Veuillez faire un choix de compression : \n 1 - RLE \n 2 - MTF \n 3 - Huffman \n 4 - Combinaison des 3 modes de compression \n");
        scanf("%d", &choix);

        switch(choix){
            case 1: 
                decoderRle(Tete); 
                writeListeBytes(Tete,fileCompressed);
                break;
            case 2: 
                //resultatTete = MTF(Tete); 
                //writeListeBytes(resultatTete,fileCompressed);
                //liberer(resultatTete);
                break;
            case 3:{  
                maillon* AC = Tete;
                if (AC != NULL){ 
                    while (AC->suivant != Queue){
                        //Tous les octets non, lu avant l'avant dernier octet, ont 8 bits significatifs
                        AC->autre = 8;
                        AC = AC->suivant;
                    }
                    // On met a jour le nombre de bit significatif de l'avant dernier octet lu
                    // Le dernier octet lu est le nombre de bit significatif de l'avant dernier octet
                    AC->autre = (int) Queue->lettre;

                    //On supprime le dernier octet
                    Queue = AC;
                    Queue->suivant = NULL;
                }

                resultatTete = decodageHuffman2(Tete, ArbreHufman(Tete));
                writeListeBytes(resultatTete,fileCompressed);
                liberer(resultatTete);
                break;
                   }
            case 4: 
                decoderRle(Tete);
                resultatTete = decodageHuffman2(Tete, ArbreHufman(Tete));
                writeListeBytes(resultatTete,fileCompressed);
                liberer(resultatTete);
                break;

            default: printf("Erreur de choix");
        }

                liberer(Tete);
                fclose(fileCompressed);
    }
    return 0;
}
