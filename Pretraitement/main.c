#include "MTF.h"
#include "../liste_manager.h"
#include <stdio.h>
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
	
   	ajoutEnTete( liste, 'h', 000);
	fprintf(stderr,"lol2");	
	ajoutEnTete( liste, 'g', 001);
	fprintf(stderr,"lol3");
	ajoutEnTete( liste, 'f', 010);
	fprintf(stderr,"lol4");
	ajoutEnTete( liste, 'e', 011);
	fprintf(stderr,"lol5");
	ajoutEnTete( liste, 'd', 100);
	fprintf(stderr,"lol6");
	ajoutEnTete( liste, 'c', 101);
	fprintf(stderr,"lol7");
	ajoutEnTete( liste, 'b', 110);
	fprintf(stderr,"lol8");
	ajoutEnTete( liste, 'a', 111);
	fprintf(stderr,"lol9");

    	afficherListe(liste);
 	

 
    return 0;
}


void afficherListe(maillon liste)
{
   	maillon *tmp = &liste;

    while(tmp != NULL)
    {

        printf("\n%c, %c ", tmp->lettre,tmp->autre);

        tmp = tmp->suivant;
    }

}

