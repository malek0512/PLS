#include<stdio.h>
#include<stdlib.h>
#include"liste_manager.h"
#include"Huffman/huffman.h"
#include"Pretraitement/MTF.h"
#include"Pretraitement/RLE.h"
#include"reader.h"
#include<string.h>
#define DEBUGG


//Author Malek
//Selon une entree d'octets d'un fichier, effectue l'ensemble des etapes 
//de separation de la table du message coder etc
maillon* decodageHuffmanFinal(maillon** Tete, maillon** Queue); 


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
                resultatTete = decodageHuffmanFinal(&Tete, &Queue); 

                printf("\nVoici le message décodé en Hexa\n");
                print2(resultatTete);
                
                //Ecriture du message dans le fichier
                writeListeBytes(resultatTete,fileCompressed);
                liberer(resultatTete);

                printf("\n**********************************************************");
                printf("\n*               DECODAGE HUFFMAN FIN                     *");
                printf("\n**********************************************************\n");
                break;
                   }
            case 4:{  
                printf("\n**********************************************************");
                printf("\n*               DECODAGE  ...                     *");
                printf("\n**********************************************************\n");
                resultatTete = decodageHuffmanFinal(&Tete, &Queue); 

                liberer(Tete);
                Tete = resultatTete;
                
                //Calcul des occurences
                maillon *listeFrequency=NULL;
                listeFrequency = calculateFrequency(Tete);

                //Calcul de la table de de Huffman
                arbre* treeHuffman = ArbreHufman(listeFrequency);
                maillon* Table =  creationTableHuffman(treeHuffman);
                resultatTete = MTF2(Table,Tete);

                liberer(Tete);
                Tete = resultatTete;

#ifdef DEBUGG
                printf("\nVoici le message décodé en Hexa\n");
                print2(Tete);
#endif
                //decoderRle(Tete); 
                
                //Ecriture du message dans le fichier
                writeListeBytes(Tete,fileCompressed);
                liberer(Tete);

                printf("\n**********************************************************");
                printf("\n*               DECODAGE FIN                     *");
                printf("\n**********************************************************\n");
                break;
                   }
            default: printf("Erreur de choix");
        }

                liberer(Tete);
                fclose(fileCompressed);
    }
    return 0;
}

maillon* decodageHuffmanFinal(maillon** Tete, maillon** Queue){ 
    //Declarations
    maillon *tableHead=NULL;

    //Recupération de la table de Huffman
    tableHead = readHuffmanTable(Tete,Queue);

#ifdef DEBUGG
    printf("\n Voici la table Huffman \n");
    print4(tableHead);

    printf("\n Voici le mot non décodé en Binaire \n");
    afficherK(*Tete);
#endif

    //Conversion de la table de Huffman de type maillon en type arbre
    arbre* tree = arbreFromTable(tableHead);
    printArbre(tree);

    //Decodage du message
    return decodageHuffman2(*Tete,tree);
}
