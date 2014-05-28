#include "huffman.h"
#include <stdlib.h>
#include <stdio.h>

void afficherK(maillon* res)
{
	int i;
   maillon *tmp = res;
	while(tmp != NULL)
	{
		for (i=tmp->autre;i>=0;i--)
			printf("%d",(tmp->lettre >>i)&1);
		printf(" ");
		tmp = tmp->suivant;
	}
	printf("\n");

}


int main()
{
maillon* liste = NULL;
maillon* res=NULL;
arbre* tab=NULL;
maillon* tableHuffman = NULL;
//init liste
liste = ajouterEnQueue(liste,'a',1);
liste = ajouterEnQueue(liste,'b',2);
liste = ajouterEnQueue(liste,'c',2);
liste = ajouterEnQueue(liste,'d',4);
//liste = ajouterEnQueue(liste,'e',16);
tab = ArbreHufman(liste);
tableHuffman = creationTableHuffman(tab);
print(tableHuffman);
printf("\n\nprint du mot NON codé : \n");
print(liste);

tab = ArbreHufman(liste);
printArbre(tab);

res = codageHuffman(liste, tab);
printf("\n\nprint du mot codé : \n");
afficherK(res);
res = decodageHuffman(res,tab);
afficherK(res);
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
