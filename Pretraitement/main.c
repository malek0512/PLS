#include "MTF.h"
#include "../liste_manager.h"
#include <stdio.h>
void afficherListe();

int main (int argc, char *argv[])
{
	
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
	    	printf("lol1");
	
   	liste = ajoutEnTete(liste, 'h', 111);
	printf("lol2");	
	liste =  ajoutEnTete( liste, 'g', 110);
	printf("lol3");
	liste = ajoutEnTete( liste, 'f', 101);
	printf("lol4");
	liste = ajoutEnTete( liste, 'e', 100);
	printf("lol5");
	liste = ajoutEnTete( liste, 'd', 011);
	printf("lol6");
	liste = ajoutEnTete( liste, 'c', 010);
	printf("lol7");
	liste = ajoutEnTete( liste, 'b', 001);
	printf("lol8");
	liste = ajoutEnTete( liste, 'a', 000);
	printf("lol9");

    	afficherListe(liste);
 	

 
    return 0;
}


void afficherListe(maillon *liste)
{
   	maillon *tmp = liste;

    while(tmp != NULL)
    {

        printf("\n%c, %c ", tmp->lettre,tmp->autre);

        tmp = tmp->suivant;
    }

}

