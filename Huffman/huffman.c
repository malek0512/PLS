#include "huffman.h"

<<<<<<< HEAD

=======
//author : Alex
>>>>>>> 7d45b622c60eaf2da03c3181103770698f6c812f
int readBit(char source, int numero)
{
	return ((source > numero)&1);


//author : Alex
maillon* creationTableHuffman(arbre* arbreHuffman)
{
	void creationTableHuffmanRec(arbre* arbreHuffman,int code, int taille,maillon** res)
	{
		if(arbreHuffman->G == NULL && arbreHuffman->D == NULL)
		{
			ajouterEnQueue2(res,arbreHuffman->i.symbole,code,taille);
		}
		else
		{
			if(arbreHuffman->D!=NULL)
				creationTableHuffmanRec(arbreHuffman->D,(code<<1)+1,taille+1,res);
			if(arbreHuffman->G!=NULL)
				creationTableHuffmanRec(arbreHuffman->G,(code<<1),taille+1,res);
		}
	}

	maillon *res = NULL;
	creationTableHuffmanRec(arbreHuffman,0,0,&res);
	return res;
}

//author : Alex
//la liste de retour sera de la forme (octect / nb Significatif (effectif que pour le dernier bit))
maillon* codageHuffman(maillon *liste, arbre *arbreHuffman)
{
	maillon *tete=NULL;
	maillon *queue=NULL;
	maillon *saveListe = liste;
	int i;

	//création de la table dictionnaire a partir de l'arbre d'huffman
	maillon *tableHuffman = creationTableHuffman(arbreHuffman);
	maillon *saveArbre = tableHuffman;

	//Parcour de la liste
	while(saveListe != NULL)
	{	
		
		//lecture d'un octet
i=0;
fprintf(stderr,"%d\n",i);
		saveArbre = tableHuffman;
		while (saveArbre->lettre != saveListe->lettre)
		{//le symbole apartient donc wdec de check la valeur du i
			saveArbre= saveArbre->suivant;
i++;
fprintf(stderr,"%d\n",i);
		}
fprintf(stderr,"he\n");
		for(i=saveArbre->autre2;i>=0;i--)
		{
			fprintf(stderr,"%d\n",i);
			fprintf(stderr,"valeur ajouté :%d\n",( (saveArbre->lettre)>>i)&1);
			if(tete ==NULL && queue != NULL) //a supprimer quand on aura regler les fonctions
				tete = queue;
			writeBit(&tete, &queue, ( (saveArbre->lettre)>>i)&1);
		}
fprintf(stderr,"re\n");
		saveListe = saveListe->suivant;	
	}
	liberer(tableHuffman);
	return tete;
}

/*
Argument : 
	-liste : chaque cellule contient ( un octet , le nombre de bits significatif (uniquement valable pour la toute derniere cellule !!!))
	-tableHuffman, un arbre binaire de la table binaire

resultat :
	maillon* : contient une liste d'octet tout simplement
*/
/*
maillon* decodageHuffman(maillon *liste, arbre *tableHuffman)
{
	maillon *res = NULL;
	maillon *tmp= liste;
	int i = 7;
	while(tmp != NULL && (tmp->suivant != NULL))
	{
		for(i=7;i>0;i--)
		{	

<<<<<<< HEAD
<<<<<<< HEAD
			if(!(reabBit((tmp->lettre),i)) && (tableHuffman->G != NULL))		
			{tableHuffman = (tableHuffman->D);}
			else if((reabBit((tmp->lettre),i) && (tableHuffman->D != NULL))
			{tableHuffman = (tableHuffman->G);}
=======
			if( ! (reabBit((tmp->lettre),i)) && (tableHuffman->G != NULL) )
				tableHuffman = (tableHuffman->D);
			else if((reabBit((tmp->lettre),i) && (tableHuffman->D != NULL)
				tableHuffman = (tableHuffman->G);
>>>>>>> 7d45b622c60eaf2da03c3181103770698f6c812f
=======
			if( (!(reabBit((tmp->lettre),i))) && (tableHuffman->G != NULL) )
				tableHuffman = tableHuffman->D;
			else if (   reabBit((tmp->lettre),i) && (tableHuffman->D != NULL))
				tableHuffman = tableHuffman->G;
>>>>>>> 891e6ec2fbedfe47c68dd6c267873c9ab1852998
			else 
				res = ajouterenQueue(res,tableHuffman->i.symbole,0);
		}
		tmp = tmp->suivant;
	}
	if(tmp != NULL) 
	{
		tmp = tmp-> suivant;
		i = tmp->autre;
		for(i;i>0;i--)
		{	

			if(!(reabBit((tmp->lettre),i) && (tableHuffman->G != NULL))
				tableHuffman = (tableHuffman->D);
			else if((reabBit((tmp->lettre),i) && (tableHuffman->D != NULL)
				tableHuffman = (tableHuffman->G);
			else 
				res = ajouterenQueue(res,tableHuffman->info.symbole,0);
		}
	
	return res;
}
*/


//author : Alex
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

//author : Alex
void printArbre(arbre* tree)
{
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

	printf("\n\nAffichage de l'arbre d'huffman : \n");
	printArbre_rec(tree,0,0); //peut etre mettre taille a 1, a voir...
}


