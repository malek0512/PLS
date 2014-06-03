#include<stdio.h>
#include<stdlib.h>
#include"../includes/liste_manager.h"
#include"../includes/huffman.h"
#include"../includes/MTF.h"
#include"../includes/RLE.h"
#include"../includes/reader.h"
#include<string.h>


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
        *(argv[1]+strlen(argv[1])-4)='\0';
        FILE* fileCompressed = CreerFichier(strcat(argv[1],"decomp"));
        maillon *Tete, *Queue, *resultatTete=NULL;
        int choix;

        readFromFileBytesInOrder(&Tete,&Queue,file);
        fclose(file);

        printf("Veuillez faire un choix de compression : \n 1 - RLE \n 2 - MTF \n 3 - Huffman \n 4 - Combinaison des 3 modes de compression \n");
        if(scanf("%d", &choix)==0)
			return -1;
		
        switch(choix){
            case 1: 
                printf("\n**********************************************************");
                printf("\n*               DECODAGE RLE ...                         *");
                printf("\n**********************************************************\n");

				Tete = predecodeRle(Tete);
				fprintf(stderr,"travail terminer\n");
				printf("On est sorti de precode\n");
				print(Tete);
				printf("Decode");
                decoderRle(Tete);
				printf("On a fini le decodage\n");
				print(Tete);
                writeListeBytes(Tete,fileCompressed);

                printf("\n**********************************************************");
                printf("\n*               DECODAGE RLE FIN                         *");
                printf("\n**********************************************************\n");
                break;
            case 2: 
                printf("\n**********************************************************");
                printf("\n*               DECODAGE MTF ...                         *");
                printf("\n**********************************************************\n");

                resultatTete = MTF2(Tete); 
                writeListeBytes(resultatTete,fileCompressed);
                liberer(resultatTete);

                printf("\n**********************************************************");
                printf("\n*               DECODAGE MTF FIN                         *");
                printf("\n**********************************************************\n");
                
                break;
            case 3:{  
                printf("\n**********************************************************");
                printf("\n*               DECODAGE HUFFMAN ...                     *");
                printf("\n**********************************************************\n");
                resultatTete = decodageHuffmanFinal(&Tete, &Queue); 
				
				#ifdef DEBUGG
                printf("\nVoici le message décodé en Hexa\n");
				print2(resultatTete);
				#endif
                
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
                printf("\n*               DECODAGE  COCKTAIL ...                    *");
                printf("\n**********************************************************\n");
				printf("Veuillez faire un choix des prétraitements à opérer :\n");
				printf("RLE?\n");
				int RLE,mtf;
				if(scanf("%d", &RLE)==0)
					return -1;
				printf("MTF?\n");
				if(scanf("%d", &mtf)==0)
					return -1;

                printf("\n**********************************************************");
                printf("\n*               DECODAGE HUFFMAN ...                     *");
                printf("\n**********************************************************\n");

                resultatTete = decodageHuffmanFinal(&Tete, &Queue); 
                liberer(Tete);
                Tete = resultatTete;

                printf("\n**********************************************************");
                printf("\n*               DECODAGE HUFFMAN FIN                     *");
                printf("\n**********************************************************\n");

                
                if (mtf){ 
                printf("\n**********************************************************");
                printf("\n*               DECODAGE MTF ...                         *");
                printf("\n**********************************************************\n");
                
                resultatTete = MTF2(Tete);
                liberer(Tete);
                Tete = resultatTete;
                
                printf("\n**********************************************************");
                printf("\n*               DECODAGE MTF FIN                         *");
                printf("\n**********************************************************\n");
                }

                if (RLE){ 
                printf("\n**********************************************************");
                printf("\n*               DECODAGE RLE ...                         *");
                printf("\n**********************************************************\n");
                
                decoderRle(Tete); 

                printf("\n**********************************************************");
                printf("\n*               DECODAGE RLE FIN                         *");
                printf("\n**********************************************************\n");
                }

#ifdef DEBUGG
                printf("\nVoici le message décodé en Hexa\n");
                print2(Tete);
#endif
                
                //Ecriture du message dans le fichier
                writeListeBytes(Tete,fileCompressed);

                printf("\n**********************************************************");
                printf("\n*               DECODAGE COCKTAIL FIN                    *");
                printf("\n**********************************************************\n");
                break;
                   }
            default: printf("Erreur de choix");
        }
	
                //liberer(Tete);
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
   // printArbre(tree);

    //Decodage du message
    return decodageHuffman(*Tete,tree);
}
