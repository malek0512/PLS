#include "huffman.h"

bool readBit(char source, int numero)
{
	return (source > numero)&1;
}

//la liste de retour sera de la forme (octect / nb Significatif (effectif que pour le dernier bit))
maillon* codageHuffman(maillon *liste, arbre *tableHuffman)
{
maillon *tete;
maillon *queue;
char

//création de la table dictionnaire a partir de l'arbre d'huffman

//Parcour de la liste
	//lecture d'un octet
	
	//ajout de l'information a l'octet en cours de création

	//si octet en cours de création full, ajout en queue

	//avancement dans la liste

//ajout de l'octet en cours de préparation

//retourner le resultat
return NULL;
}

/*
Argument : 
	-liste : chaque cellule contient ( un octet , le nombre de bits significatif (uniquement valable pour la toute derniere cellule !!!))
	-tableHuffman, un arbre binaire de la table binaire

resultat :
	maillon* : contient une liste d'octet tout simplement
*/
maillon* decodageHuffman(maillon *liste, arbre *tableHuffman)
{
	maillon *res = NULL;
	maillon *tmp= liste;
	int i = 7;
	while(tmp != NULL)
	{
		for(i;i>0;i--)
		{	
			while((tableHuffman->G != NULL) && (tableHuffman->D != NULL))	
			{
				if(!(reabBit((tmp->lettre),i))
				{tableHuffman = (tableHuffman->D);}
				else
				{tableHuffman = (tableHuffman->G);}
			}
		}

	}

	
	return NULL;
}
/*		
maillon* rechercherElement(maillon* liste, int valeur)
{
    maillon *tmp=liste;
    //Tant que l'on n'est pas au bout de la liste 
    while(tmp != NULL)
    {
        if(tmp->lettre == valeur)
        {
            // Si l'élément a la valeur recherchée, on renvoie son adresse
            return tmp;
        }
        tmp = tmp->suivant;
    }
    return NULL;
}*/

arbre* ArbreHufman(maillon* liste)
{	
	arbre* tab[size(liste)];	//création de l'arbre de codage
	arbre* new; //le nouvelle arbre
	maillon* save=liste;
	int i,cpt; //cpt de for
	int min1,min2; //proba minimals, min1<=min2
	int i1,i2; //indice ou sont trouver les valeurs min
	int tailleT = size(liste);//nombre de caractere different dans notre liste
	//on copie les information contenu dans la liste maillon
	//dans une liste d'arbre
	for (i=0;i<tailleT;i++)
	{
		tab[i] = malloc(sizeof(arbre));
		tab[i] -> G= NULL; //on maj les valeurs du tableau
		tab[i] -> D= NULL;
		tab[i] -> i.proba= save-> autre;
		tab[i] -> i.symbole= save-> lettre;
		save = save->suivant;//avancement
	}

	while(tailleT>=2)
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
			
			else if(tab[cpt]->i.proba<min2)
			{
				min2 = tab[cpt]->i.proba;  //maj du min2
				i2 = cpt;
			}
			
		}
		new = malloc(sizeof(arbre)); //le nouvelle arbre
		new->i.proba= min1 + min2;
		new->G = tab[i1];
		new->D = tab[i2];
	
		//maj de tailleT et du tableau
		//on prévoit de réduire la taille du tableau de 1 cran
		//les deux arbre fusionner doivent devenir innaccessible
		//la fusion des deux arbres doit deveni r accessible
			//on prépare supprime les deux arbre qui on substituer la fusion
		tab[i1] =tab[tailleT-1]; 
		tab[i2] =tab[tailleT-2];
			//on ajoute a la fin futur du tableau la somme des deux anciens
		tab[tailleT-2] = new;
			//on maj le tableau
		tailleT --;
	}
	return *tab;
}

void printArbre(arbre* tree)
{
printf("\n\nAffichage de l'arbre d'huffman : \n");
printArbre_rec(tree,0,0); //peut etre mettre taille a 1, a voir...
}

void printArbre_rec(arbre* tree,int value,int taille)
{
	int i;
	if (tree!=NULL)
{
	if(tree->D == NULL && tree->G == NULL)
	{
		printf("Symbole/Valeur : %c / ",tree->i.symbole);
		for (i=taille-1;i>=0;i--)
			printf("%d",(value>>i)&1);
		printf("\n");
	}
	else
	{
		if(tree->D!=NULL)
			printArbre_rec(tree->D,(value<<1)+1,taille+1);
		if(tree->G!=NULL)
			printArbre_rec(tree->G,(value<<1),taille+1);
	}
}
}
