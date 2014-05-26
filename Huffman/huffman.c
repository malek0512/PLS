#include "huffman.h"

//static arbre* tab[N]; //tableau de pointeur sur les arbres

void transfert(maillon* liste,arbre *tab, int taille)
{
	int i;
	maillon* save = liste;
	for (i=0;i<taille;i++)
	{
		tab[i] = malloc(sizeof(arbre));//on alloue le nouvelle arbre
		tab[i] -> G= NULL; //on maj les valeurs du tableau
		tab[i] -> D= NULL;
		tab[i] -> i.proba= save-> autre;
		tab[i] -> i.symbole= save-> lettre;
		save = save->suivant;//avancement
	}
}

void hufman(maillon* liste)
{	
	//création de l'arbre a inserer
	arbre* tab[size(liste)]; 
	arbre* new; //le nouvelle arbre
	maillon* save;
	int cpt;
	int min1,min2; //proba minimals, min1<=min2
	int i1,i2; //indice ou sont trouver les valeurs min
	int tailleT = size(liste);//nombre de caractere different dans notre liste

	transfert(liste,tab,tailleT); //transfert les information de la liste maillon dans la liste d'arbre qu'elle crée au passage	

	while(tailleT>1)
	{//tant que tous les symbole sont non traité (au moins deux arbre a fusionner) :
		//initialisation des varaible min1 et min2 au premiers indice
			//min1
		min1 = tab[0]->i.proba;
		i1=0;
			//min2
		if (tab[1]->i.proba<min1)
		{
			min2=min1; 
			i2=0;
			min1=tab[1]->i.proba; i1=1;		
		}
		else
		{
			min2=tab[1]->i.proba; i2=1;
		}
		//recherche des vrais valeurs de min1 et min2
		for(cpt=2;cpt<tailleT;cpt++)
		{
			if(tab[cpt]->i.proba<min1)
			{
				min2 = min1;  //maj du min2
				i2 = i1;
				min1 = tab[cpt]->i.proba; //maj du min1
				i1 = cpt;
			}
		}
		new = malloc(sizeof(arbre)); //le nouvelle arbre
		new->i.proba= tab[i1]->i.proba + tab[i2]->i.proba;
		new->G = tab[i1];
		new->D = tab[i2];
	
		//maj de tailleT et du tableau
			//on met  a la fin les indice traité
		tab[i1] =tab[tailleT-1]; 
		tab[i2] =tab[tailleT-2];
			//on ajoute a la fin futur du tableau la somme des deux ancien
		tab[tailleT-2] = new;
			//on maj le tableau
		tailleT --;
	}	
}

