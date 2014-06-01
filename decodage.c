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
                printf("\n**********************************************************");
                printf("\n*               DECODAGE HUFFMAN ...                     *");
                printf("\n**********************************************************\n");
                //Declarations
                maillon* AC = Tete, *tableHead=NULL, *tableTail=NULL;
                
                printf("\n Voici le contenu du fichier en Hexa \n");
                print2(Tete);

                if (AC != NULL && AC->suivant != NULL && AC->suivant->suivant !=NULL){ //Size>=3
                    //Nous lisons la table
                    //Tant que le maillon suivant AC != Queue (donc j'ai au moins 3 symbole a lire) et que ce n'est pas une succession de 3 #
                    while (AC != NULL && AC->suivant != Queue && !(AC->lettre == '#' && AC->suivant->lettre == '#' && AC->suivant->suivant->lettre == '#')){

                        ajoutEnQueue(&tableHead, &tableTail, AC->lettre, AC->suivant->lettre);
                        tableTail->autre2 = AC->suivant->suivant->lettre;

                        AC = AC->suivant->suivant->suivant;
                    }
                    if (AC !=NULL && AC->suivant != Queue) {
                        //C'est que j'ai fini de lire la table car j'ai rencontré les 3#
                        
                        //On saute les 3#
                        AC = AC->suivant->suivant->suivant;

                        //Soit il n'y a aucun symbole, donc AC==NULL 
                        if (AC == NULL){
                            printf("\nNous avons lu la table. Il n'y a aucun symbole codé\n");
                            exit(1);
                        }
                        //Soit il ne reste qu'un octet et il manque le nombre de bit significatif, donc AC == Queue
                        if (AC == Queue){
                            printf("\nNous avons lu la table. Mais il n'y a qu'un symbole de codé. Il manque donc le nombre de bit significatif du dernier octet\n");
                            exit(1);
                        }

                        //Soit il y a au moins 1 symbole et il est suivi de 1 octet indiquant le nombre de bit significatif, donc AC !=NULL et AC->suivant==Queue

                        Tete = AC;
                        AC = Tete;
                        while (AC->suivant != Queue){
                            //Tous les octets avant l'avant dernier octet, ont 8 bits significatifs
                            AC->autre = 8;
                            AC = AC->suivant;
                        }
                        // On met a jour le nombre de bit significatif de l'avant dernier octet lu
                        AC->autre = (int) Queue->lettre;

                        // Le dernier octet lu est le nombre de bit significatif de l'avant dernier octet
                        //On supprime le dernier octet
                        Queue = AC;
                        Queue->suivant = NULL;


                        printf("\n Voici la table Huffman \n");
                        print4(tableHead);
                        
                        printf("\n Voici le mot non codé en Binaire \n");
                        afficherK(Tete);
                fprintf(stderr,"Zouzou1");
                        arbre* tree = arbreFromTable(tableHead);
                        printArbre(tree);
                        //resultatTete = decodageHuffman2(Tete,tree);
                fprintf(stderr,"Zouzou2");
                        //print2(resultatTete);
                        //writeListeBytes(resultatTete,fileCompressed);
                        //liberer(resultatTete);
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
                printf("\n**********************************************************");
                printf("\n*               DECODAGE HUFFMAN FIN                     *");
                printf("\n**********************************************************\n");
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
