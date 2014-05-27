
#include "MTF.h"
#include <stdio.h>
void afficherListe2(maillon *liste);

maillon* MTF(maillon* liste,char *mot){
	int i=0;
	int x;
	maillon *tmp;
	int taille = sizeof(mot);
	maillon *liste_retour = copieList(liste);
	
	if (!estVide(liste_retour))
	{
	
		//creation d'une deuxieme liste chainée mettant dans l'orde les symbole
		for (i;i<taille;i++)
		{
			tmp=rechercherElement(liste_retour,mot[i]);
			maillon copie;
			copie.lettre = tmp->lettre;
			copie.autre = tmp->autre;
			liste_retour = supprimerElement(liste_retour,copie.lettre,copie.autre);
			liste_retour = ajoutEnTete(liste_retour,copie.lettre,copie.autre);

		}

		//changement des indices de la deuxieme liste chainée

		afficherListe(liste);
		maillon *save = liste_retour;
		while((liste != NULL) && (liste_retour !=NULL))
		{
			liste_retour->autre = liste->autre;
			liste_retour = liste_retour->suivant;
			liste = liste->suivant;
			
		}
		return save;
	}
	
}





