#include "huffman.h"
#include <stdlib.h>
#include <stdio.h>
#include"../reader.h"

	void printDebug(maillon* liste)
	{
		int lulu=0;
	   maillon *tmp = liste;
		while(tmp != NULL)
		{
			if(lulu ==4)
			{
			lulu = 0;
			printf(" ");
			}
			printf("%c", tmp->lettre);
			tmp = tmp->suivant;
			lulu++;
		}
	    printf("\n");
	}

//Transferé dans list_manager
//void afficherK(maillon* res)
//{
//    int i;
//    maillon *tmp = res;
//    while(tmp != NULL)
//    {
//        for (i=8;i>8-tmp->autre;i--)
//            printf("%d",(tmp->lettre >>(i-1))&1);
//        printf(" ");
//        tmp = tmp->suivant;
//    }
//    printf("\n");
//
//}
void print3(maillon* liste)
{

   maillon *tmp = liste;
	printf("Liste : \n");
	while(tmp != NULL)
	{
		printf("%c\n", tmp->lettre);
		tmp = tmp->suivant;
	}
}


int main()
{
    maillon* liste = NULL;
//    maillon* res=NULL;
    maillon* listeR = NULL;
    arbre* tab=NULL;
    //maillon* tableHuffman = NULL;
    liste = ajouterEnQueue(liste,'a',1);
//    liste = ajouterEnQueue(liste,'b',2);
//    liste = ajouterEnQueue(liste,'c',1);
//    liste = ajouterEnQueue(liste,'d',2);
//    liste = ajouterEnQueue(liste,'e',1);

    listeR = ajouterEnQueue(listeR,'a',1);
//    listeR = ajouterEnQueue(listeR,'b',1);
//    listeR = ajouterEnQueue(listeR,'c',1);
//    listeR = ajouterEnQueue(listeR,'c',1);
//    listeR = ajouterEnQueue(listeR,'d',1);
//    listeR = ajouterEnQueue(listeR,'d',1);
//    listeR = ajouterEnQueue(listeR,'e',1);


	printf("print du mot NON codé : \n");
	printDebug(listeR);

    tab = ArbreHufman(liste);
   printArbre(tab);
return 0;
}
/*
//    liste = ajouterEnQueue(liste,'a',1);
//    liste = ajouterEnQueue(liste,'b',2);
//    liste = ajouterEnQueue(liste,'c',2);
//    liste = ajouterEnQueue(liste,'d',4);
//    liste = ajouterEnQueue(liste,'e',16);
    tab = ArbreHufman(listeFrequency);
    //tableHuffman = creationTableHuffman(tab);
    //print2(tableHuffman);
    printf("print du mot NON codé : \n");
    print3(liste);

    //tab = ArbreHufman(liste);
    printArbre(tab);

    res = codageHuffman(listeR, tab);
    //printf("\n\nprint du mot codé : \n");
    //afficherK(res);

    //afficherK(res);
    res = decodageHuffman2(res,tab);

    printf("\n\nprint du mot décodé : \n");
    printDebug(res);
    
    //afficherK(res);
    //liberer
    liberer(liste);
    liberer(listeR);
    return 0;
}
*/
/*creationTableHuffman
  test 
  arbre* tab = NULL;
  maillon *tableHuffman = NULL;
  maillon* liste = NULL;

  liste = ajouterEnQueue(liste,'a',1);
  liste = ajouterEnQueue(liste,'b',1);
  liste = ajouterEnQueue(liste,'c',2);
  liste = ajouterEnQueue(liste,'d',4);
  liste = ajouterEnQueue(liste,'e',16);



  return 0;
  }

*/
