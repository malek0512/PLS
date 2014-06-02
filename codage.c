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

        //Declarations 
        maillon *Tete, *Queue, *resultatTete=NULL;
        arbre *tree = NULL;
        int choix;

        //Lecture du fichier
        FILE* file = OuvrirFichier(argv[1]);
        readFromFileBytesInOrder(&Tete,&Queue,file);
        fclose(file);

        //Creation d'un fichier en ecriture
        FILE* fileCompressed = CreerFichier("Compresser.Comp"); //strcat(argv[1],".Comp"));


        printf("Veuillez faire un choix de compression : \n 1 - RLE \n 2 - MTF \n 3 - Huffman \n 4 - Combinaison des 3 modes de compression \n");
        scanf("%d", &choix);

        switch(choix){
            case 1: 
                printf("\n**********************************************************");
                printf("\n*                 CODAGE RLE ...                        *");
                printf("\n**********************************************************\n");

                coderRle(Tete);
                writeListeBytes(Tete,fileCompressed);

                printf("\n**********************************************************");
                printf("\n*                 CODAGE RLE FIN                    *");
                printf("\n**********************************************************\n");
                break;
            case 2:{ 
                printf("\n**********************************************************");
                printf("\n*                 CODAGE MTF ...                        *");
                printf("\n**********************************************************\n");

                //Calcul des occurences
                maillon *listeFrequency=NULL;
                listeFrequency = calculateFrequency(Tete);

                //Calcul de la table de de Huffman
                arbre* treeHuffman = ArbreHufman(listeFrequency);
                maillon* Table =  creationTableHuffman(treeHuffman);
                resultatTete = MTF2(Table,Tete);
#ifdef DEBUGG
                printf("\n Voici la table de Huffman \n");
                printArbre(treeHuffman);

                printf("\n Voici la table de Huffman après MTF \n");
                print4(resultatTete);
#endif
                
                liberer(resultatTete);
                liberer(listeFrequency);
                liberer(Tete);
                printf("\n**********************************************************");
                printf("\n*                 CODAGE MTF FIN                    *");
                printf("\n**********************************************************\n");
                break;
                   }
            case 3: { 
                printf("\n**********************************************************");
                printf("\n*                 CODAGE HUFFMAN ...                     *");
                printf("\n**********************************************************\n");

#ifdef DEBUGG
                printf("\n Voici le contenu du fichier en Hexa \n");
                print2(Tete);
#endif

                //Calcul des occurences
                maillon *listeFrequency=NULL;
                listeFrequency = calculateFrequency(Tete);
                
                //Calcul de la table de de Huffman
                tree = ArbreHufman(listeFrequency);
                
#ifdef DEBUGG
                printf("\n Voici la table de Huffman \n");
                printArbre(arbreFromTable(creationTableHuffman(tree)));
#endif
=======

                //Encodage du fichier
                resultatTete = codageHuffman(Tete, tree);

#ifdef DEBUGG
                printf("\n Voici le message codé en Hexa\n");
                print2(resultatTete);
                printf("\n Voici le message codé en Binaire\n");
                afficherK(resultatTete);
#endif

                //Ecriture de la table dans le fichier
                writeHuffmanTable(tree, fileCompressed);

                //Ecriture de l'encodage dans le fichier
                writeListeBytes(resultatTete,fileCompressed);

                //Ecriture du nombre de bit significatif du dernier octet
                writeByte( (unsigned char) getQueue(resultatTete)->autre,fileCompressed);

                //Restitution de la memoire allouée
                liberer(resultatTete);
                liberer(listeFrequency);
                printf("\n**********************************************************");
                printf("\n*                 CODAGE HUFFMAN FIN                     *");
                printf("\n**********************************************************\n");
                break;
                    }
            case 4: 
                printf("\n**********************************************************");
                printf("\n*                 CODAGE COCKTAIL ...                    *");
                printf("\n**********************************************************\n");

#ifdef DEBUGG
                printf("\n Voici le contenu du fichier en Hexa \n");
                print2(Tete);
#endif

                printf("\n**********************************************************");
                printf("\n*                 CODAGE RLE ...                        *");
                printf("\n**********************************************************\n");

                //coderRle(Tete);

                printf("\n**********************************************************");
                printf("\n*                 CODAGE RLE FIN                    *");
                printf("\n**********************************************************\n");

                printf("\n**********************************************************");
                printf("\n*                 CODAGE MTF ...                        *");
                printf("\n**********************************************************\n");

                //Calcul des occurences
                maillon *listeFrequency=NULL;
                listeFrequency = calculateFrequency(Tete);

                //Calcul de la table de de Huffman
                arbre* treeHuffman = ArbreHufman(listeFrequency);
                maillon* Table =  creationTableHuffman(treeHuffman);
                resultatTete = MTF2(Table,Tete);

                liberer(Tete);
                Tete = resultatTete;

                printf("\n**********************************************************");
                printf("\n*                 CODAGE MTF FIN                    *");
                printf("\n**********************************************************\n");

                printf("\n**********************************************************");
                printf("\n*                 CODAGE HUFFMAN ...                     *");
                printf("\n**********************************************************\n");

#ifdef DEBUGG
                printf("\n Voici le contenu du fichier en Hexa \n");
                print2(Tete);
#endif

                //Calcul des occurences
                //maillon *listeFrequency=NULL;
                listeFrequency = calculateFrequency(Tete);
                
                //Calcul de la table de de Huffman
                tree = ArbreHufman(listeFrequency);
                
                #ifdef DEBUGG
                printf("\n Voici la table de Huffman \n");
                printArbre(arbreFromTable(creationTableHuffman(tree)));
            	#endif

                //Encodage du fichier
                resultatTete = codageHuffman(Tete, tree);

#ifdef DEBUGG
                printf("\n Voici le message codé en Hexa\n");
                print2(resultatTete);
                printf("\n Voici le message codé en Binaire\n");
                afficherK(resultatTete);
#endif

                //Ecriture de la table dans le fichier
                writeHuffmanTable(tree, fileCompressed);

                //Ecriture de l'encodage dans le fichier
                writeListeBytes(resultatTete,fileCompressed);

                //Ecriture du nombre de bit significatif du dernier octet
                writeByte( (unsigned char) getQueue(resultatTete)->autre,fileCompressed);

                //Restitution de la memoire allouée
                liberer(resultatTete);
                liberer(listeFrequency);
                printf("\n**********************************************************");
                printf("\n*                 CODAGE HUFFMAN FIN                     *");
                printf("\n**********************************************************\n");
                printf("\n**********************************************************");
                printf("\n*                 CODAGE COCKTAIL FIN                    *");
                printf("\n**********************************************************\n");
                break;

            default: printf("Erreur de choix");
        }

                liberer(Tete);
                fclose(fileCompressed);
    }
    return 0;
}
