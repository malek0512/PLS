#include <stdlib.h>
#include <stdio.h>
#include "../includes/RLE.h"

// On traite la liste tete en suivant l'algorithme RLE
// Auteur : Marie
void coderRle(maillon* tete){

	// On vérifie que la liste courante comporte au moins deux éléments
	if(tete != NULL && tete->suivant != NULL){
		maillon* tmp;
		int cmp;
		tmp = tete;

		// Tant qu'on a un élément auquel comparer l'élément courant, on continue le traitement
		while(tmp->suivant != NULL){

			// Si deux éléments qui se suivent ont les mêmes lettres, on commence à compter le
			// nombre d'éléments comportant la même lettre après les deux premiers
			if(tmp->lettre == tmp->suivant->lettre){

				cmp = 0;
				tmp = tmp->suivant;

				// Tant que l'élément suivant est identique à l'élément courant et qu'on ne dépasse pas 255
				// répétitions (puisqu'on code le nombre de répétitions sur un octet), on le supprime et on
				// compte
				while(tmp->suivant != NULL && tmp->lettre == tmp->suivant->lettre && cmp<255){

					cmp++;
					supprimer(tmp->suivant, &tete);
				}

				// On donne comme lettre au nouvel élément le nombre d'itérations qu'on a compté
				maillon* new = malloc(sizeof(maillon));
				new->lettre = cmp;

				// On applique une fréquence nulle au nouvel élément pour pouvoir le différencier
				// facilement lors du décode de la liste
				new->autre = 0;
				insererElement(new, tmp);
			}
			if(tmp->suivant != NULL)
				tmp = tmp->suivant;
		}
	}
}

// Permet de décoder une liste à laquelle on a appliqué l'algorithme RLE
// Auteur : Marie
void decoderRle(maillon* tete){
	if(tete != NULL && tete->suivant != NULL){
		maillon* tmp;
		tmp = tete;
		int nb;
		int i;
		while(tmp->suivant != NULL){

			// Un élément de fréquence nulle indique combien de fois l'élément précédent est répété dans
			// le code initial (convention) : on répète donc l'élément précédent le nombre de fois
			// indiqué par cet élément
			if(tmp->suivant->autre == 0){

				// On récupère le code de la lettre, qui correspond au nombre de fois où l'on doit
				// répéter tmp
				nb = tmp->suivant->lettre;

				// On supprime l'élément qui nous indiquait la répétition
				supprimer(tmp->suivant, &tete);

				// Si le nombre d'itérations est supérieur ou égal à 1, on répète nb fois l'élément tmp
				for(i=1; i<=nb; i++){
					maillon* new = malloc(sizeof(maillon));
					new->lettre = tmp->lettre;
					new->autre = tmp->autre;
					insererElement(new, tmp);
				}
			}
			if(tmp->suivant != NULL)
				tmp = tmp->suivant;
		}
	}
}

// Fonction à utiliser avant le décode si on lit un fichier déjà codé en RLE
// Auteur : Marie
maillon* predecodeRle(maillon* tete){
	maillon* tmp;
	int i;
	tmp = tete;
	if(tmp->lettre == 'R' && (tmp->suivant)->lettre == 'L' && ((tmp->suivant)->suivant)->lettre == 'E'){
		for(i=0; i<=2; i++){
			supprimer(tete, &tete);
		}
	tmp = tete;
		while(tmp->suivant != NULL){
			if(tmp->lettre == (tmp->suivant)->lettre){
				tmp = (tmp->suivant)->suivant;
				tmp->autre = 0;
			}
			tmp = tmp->suivant;
		}
	}
	return tete;
}
