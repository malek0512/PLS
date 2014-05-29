#include "huffman.h"
#include <stdlib.h>
#include <stdio.h>

void afficherK(maillon* res)
{
    int i;
    maillon *tmp = res;
    while(tmp != NULL)
    {
        for (i=8;i>8-tmp->autre;i--)
            printf("%d",(tmp->lettre >>(i-1))&1);
        printf(" ");
        tmp = tmp->suivant;
    }
    printf("\n");

}

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
    maillon* res=NULL;
    arbre* tab=NULL;
    //maillon* tableHuffman = NULL;
    //init liste
    liste = ajouterEnQueue(liste,'a',1);
    liste = ajouterEnQueue(liste,'b',2);
    liste = ajouterEnQueue(liste,'c',2);
    liste = ajouterEnQueue(liste,'d',4);
    //liste = ajouterEnQueue(liste,'e',16);
    tab = ArbreHufman(liste);
    //tableHuffman = creationTableHuffman(tab);
    //print2(tableHuffman);
    printf("\n\nprint du mot NON codé : \n");
    print3(liste);

    tab = ArbreHufman(liste);
    printArbre(tab);

    res = codageHuffman(liste, tab);
    printf("\n\nprint du mot codé : \n");
    afficherK(res);
    
    //afficherK(res);
    res = decodageHuffman(res,tab);
    printf("\n\nprint du mot décodé : \n");
    print2(res);
    
    //afficherK(res);
    //liberer
    liberer(liste);

    return 0;
}
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
