#include "MTF.h"
#include "../liste_manager.h"
#include <stdio.h>
void afficherListe();

int main (int argc, char *argv[])
{
	maillon *tmp;

	
/*
	printf("=======MTF======");

	char chaine[9]; 
	chaine[0] = 'f';
	chaine[1] = 'c';
	chaine[2] = 'b';
	chaine[3] = 'b';
	chaine[4] = 'e';
	chaine[5] = 'g';
	chaine[6] = 'h';
	chaine[7] = 'f';
	chaine[8] = '\0';
    	printf("\n%s\n\n", chaine);

	maillon* liste = NULL;
	
   	liste = ajoutEnTete( liste, 'h', 7);	
	liste = ajoutEnTete( liste, 'g', 6);
	liste = ajoutEnTete( liste, 'f', 5);
	liste = ajoutEnTete( liste, 'e', 4);
	liste = ajoutEnTete( liste, 'd', 3);
	liste = ajoutEnTete( liste, 'c', 2);
	liste = ajoutEnTete( liste, 'b', 1);
	liste = ajoutEnTete( liste, 'a', 0);

	tmp = MTF(liste,chaine);


	printf("tmp\n");
	afficherListe(tmp);
	printf("\n");*/


	printf("=======MTF2======");

	maillon* texte = NULL;

   	texte = ajoutEnTete( texte, 'f', 7/*, 10*/);	
	texte = ajoutEnTete( texte, 'h', 6/*, 11*/);
	texte = ajoutEnTete( texte, 'g', 5/*, 12*/);
	texte = ajoutEnTete( texte, 'e', 4/*, 13*/);
	texte = ajoutEnTete( texte, 'b', 3/*, 14*/);
	texte = ajoutEnTete( texte, 'b', 2/*, 15*/);
	texte = ajoutEnTete( texte, 'c', 1/*, 16*/);
	texte = ajoutEnTete( texte, 'f', 0/*, 17*/);

	printf("texte\n");
	afficherListe2(texte);
	printf("\n");

	maillon* liste2 = NULL;
	
   	liste2 = ajoutEnTete2( liste2, 'h', 7, 10);	
	liste2 = ajoutEnTete2( liste2, 'g', 6, 11);
	liste2 = ajoutEnTete2( liste2, 'f', 5, 12);
	liste2 = ajoutEnTete2( liste2, 'e', 4, 13);
	liste2 = ajoutEnTete2( liste2, 'd', 3, 14);
	liste2 = ajoutEnTete2( liste2, 'c', 2, 15);
	liste2 = ajoutEnTete2( liste2, 'b', 1, 16);
	liste2 = ajoutEnTete2( liste2, 'a', 0, 17);


	tmp = MTF2(liste2,texte);


	printf("tmp\n");
	afficherListe2(tmp);
	printf("\n");


    return 0;
}




