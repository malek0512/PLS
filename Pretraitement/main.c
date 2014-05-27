#include "MTF.h"
#include "../liste_manager.h"
#include <stdio.h>
void afficherListe();

int main (int argc, char *argv[])
{
	//maillon *tmp;

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

	MTF( liste,chaine);

    return 0;
}




