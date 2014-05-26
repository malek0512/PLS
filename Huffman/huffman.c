#include "huffman.h"
#define N 6 //nombre de caractere different

static arbre* tab[N]; //tableau de pointeur sur les arbres


void hufman(arbre* tab)
{	
	//création de l'arbre a inserer
	arbre* new; //le nouvelle arbre
	int cpt;
	int min1,min2; //proba minimals, min1<=min2
	int i1,i2; //indice ou sont trouver les valeurs min
	int tailleT = taille(N);//nombre de caractere different dans notre liste

	while(tailleT>1)
	{//tant que tous les symbole sont non traité :
		//initialisation des varaible min1 et min2 au premiers indice
			//min1
		min1 = tab->i.proba;
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

void print(arbre* tree,int value,int taille)
{
	int i;
	if(tree->D == NULL && tree->G == NULL)
	{
	printf("Valeur/Symbole :");
		for (i=taille-1;i>=0;i--)
		{
		printf("%d",(value>>i)%2);
		}
	printf(" / %d\n",tree->i.symbole);
	
	}
	else
	{
		if(tree->D!=NULL)
			print(tree->D,(value<<1),taille+1);
		if(tree->G!=NULL)
			print(tree->G,(value<<1) + 1,taille+1);
	}
}

void letItGo(arbre* tree)
{
	if(tree->G != NULL)
		letItGo(tree->G);
	if(tree->D != NULL)
		letItGo(tree->D);
	free(tree);
}

void jeVoudraisUnBonhommeDeNeige()
{
	int i;
	int val,car;
	arbre *tree;
	for(i=0;i<N;i++)
	{
	printf("Choisisser la proba/symbole :");
	scanf("%d",&val);
	scanf("%d",&car);
	tree = malloc(sizeof(arbre));
	tree->i.proba =val;
	tree->i.symbole = car;
	tree->D = NULL;
	tree->G = NULL;
	tab[i]=tree;
	}

}
