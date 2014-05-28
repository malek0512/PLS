#include <stdio.h>
#include <stdlib.h>
#include "../RLE.h"
#include "../../liste_manager.h"

int main(void){

	maillon* l;

	l = initialiser(l);

	l = ajoutEnTete(l, 'a', 1);
	l = ajoutEnTete(l, 'a', 1);	
	l = ajoutEnTete(l, 'a', 1);
	l = ajoutEnTete(l, 'a', 1);
	l = ajoutEnTete(l, 'a', 1);
	l = ajoutEnTete(l, 'c', 1);
	l = ajoutEnTete(l, 'm', 1);
	l = ajoutEnTete(l, 'm', 1);
	l = ajoutEnTete(l, 'm', 1);
	l = ajoutEnTete(l, 'm', 1);
	l = ajoutEnTete(l, 'm', 1);
	l = ajoutEnTete(l, 'm', 1);
	l = ajoutEnTete(l, 'o', 1);
	l = ajoutEnTete(l, 'o', 1);
	l = ajoutEnTete(l, 'o', 1);

	printf("Affichage de la liste initiale\n");
	print(l);

	printf("\nTest n°1 : Application de l'algorithme RLE sur la liste\n");
	coderRle(l);
	print(l);

	printf("\nTest n°2 : coder une liste déjà codée\n");
	coderRle(l);
	print(l);

	printf("\nTest n°3 : Décodage de la nouvelle liste\n");
	decoderRle(l);
	print(l);

	liberer(l);

	return 0;

}