#include "huffman.h"
#ifdef HUFDEBUG
	#ifndef HUFDEBUG_CODAGE
		#define HUFDEBUG_CODAGE //fonction de codage
	#endif
	#ifndef HUFDEBUG_DECODAGE
		#define HUFDEBUG_DECODAGE //fonction de decodage
	#endif
	#ifndef HUFDEBUG_ARBRE
		#define HUFDEBUG_ARBRE //fonction arbre -> table
	#endif
	#ifndef HUFDEBUG_TABLE
		#define HUFDEBUG_TABLE //fonctino table -> arbre
	#endif
#endif

//author : Alex
maillon* creationTableHuffman(arbre* arbreHuffman)
{
	void creationTableHuffmanRec(arbre* arbreHuffman,int code, int taille,maillon** res_T,maillon** res_Q)
	{
        if (arbreHuffman != NULL){   
            if(arbreHuffman->G == NULL && arbreHuffman->D == NULL)
            {
                ajouterEnQueue2(res_T,res_Q,arbreHuffman->i.symbole,code,taille);
            }
            else
            {
                if(arbreHuffman->D!=NULL)
                    creationTableHuffmanRec(arbreHuffman->D,(code<<1)+1,taille+1,res_T,res_Q);
                if(arbreHuffman->G!=NULL)
                    creationTableHuffmanRec(arbreHuffman->G,(code<<1),taille+1,res_T,res_Q);
            }
        }
	}
	
	maillon *res_T = NULL;
	maillon *res_Q = NULL;
	if(arbreHuffman == 0)
		fprintf(stderr,"   # # # Error # # #\nhuffman.c // creationTableHuffman() \nL'arbre d'huffman donnée est vide\n");
		
	creationTableHuffmanRec(arbreHuffman,0,0,&res_T,&res_Q);
	return res_T;
}

//author : Alex
//maillon -> lettre == symbole sans codage
//la liste de retour sera de la forme (octect / nb Significatif (effectif que pour le dernier bit))
maillon* codageHuffman(maillon *liste, arbre *arbreHuffman)
{
	#ifdef HUFDEBUG_CODAGE
	void afficherK(maillon* res)
	{
		    int i;
		    maillon *tmp = res;
		    while(tmp != NULL)
		    {
			for (i=8;i>8-tmp->autre;i--)
			    printf("%d",(tmp->lettre >>(i-1))&1);
			printf(" ");
			tmp = tmp->suivant;
		    }
		    printf("\n");

	}
	#endif
	maillon *tete=NULL;
	maillon *queue=NULL;
	maillon *saveListe = liste;
	int i;
	#ifdef HUFDEBUG_CODAGE
	fprintf(stderr,"   ### Debut : codageHuffman ### \n");
	#endif
	//création de la table dictionnaire a partir de l'arbre d'huffman
	maillon *tableHuffman = creationTableHuffman(arbreHuffman);
	maillon *saveArbre = tableHuffman;

	//Parcour de la liste
	while(saveListe != NULL)
	{	
		//lecture d'un octet
		while (saveArbre->lettre != saveListe->lettre)
		{//le symbole apartient a l'arbre comme il doit appartenir a la liste
			saveArbre= saveArbre->suivant;
			#ifdef HUFDEBUG_CODAGE
			if(saveArbre==NULL)
			{
				fprintf(stderr,"\n   # # # Error # # #\n");
				fprintf(stderr,"hufman.c  // codageHuffman() \n");
				fprintf(stderr,"Le caractere \"%c\" de la liste de caractere devant etre codé n'a pas était trouver dans l'arbre \n",saveListe->lettre);
				fprintf(stderr,"Segmentation fault en approche\n");
			}
			#endif
		}
		for(i=saveArbre->autre2-1;i>=0;i--)
		{
			writeBit(&tete, &queue, ( (saveArbre->autre)>>i)&1);
		}
		saveArbre = tableHuffman;
		saveListe = saveListe->suivant;	
	}
	liberer(tableHuffman);
	#ifdef HUFDEBUG_CODAGE
	printf("\nMot codé : \n");
	afficherK(tete);
	fprintf(stderr,"   ### Fin : codageHuffman ### \n\n\n");
	#endif
	return tete;
}


maillon* decodageHuffman(maillon *liste, arbre *tableHuffman)
{
    //Version Misterious Guy
	#ifdef HUFDEBUG_DECODAGE
	void printDebug(maillon* liste)
	{
		int lulu=0;
	   maillon *tmp = liste;
		while(tmp != NULL)
		{
			if(lulu ==4)
			{
			lulu = 0;
			printf(" ");
			}
			printf("%c", tmp->lettre);
			tmp = tmp->suivant;
			lulu++;
		}
	    printf("\n");
	}
	#endif
    maillon* resultatTete = NULL;
    maillon* resultatQueue = NULL;
    maillon* Tete = liste;
    arbre* AvC = tableHuffman;

    int bit = readBit(Tete);

	#ifdef HUFDEBUG_DECODAGE
	fprintf(stderr,"   ### Fin : decodageHuffman ###\n");
	#endif
	while( bit != -1 )
	{
        	if (AvC->G !=NULL && (bit==0))
			AvC = AvC->G;
		else if (AvC->D !=NULL && (bit == 1))
			AvC = AvC->D;
		if (AvC->D == NULL && AvC->G == NULL)
		{ 
	    		ajouterEnQueue(&resultatTete,&resultatQueue, AvC->i.symbole, -1 );
	    		AvC = tableHuffman;
		}
	        bit = readBit(Tete);
	}
	#ifdef HUFDEBUG_DECODAGE
	printf("\nMot décodé : \n");
	printDebug(resultatTete);
	fprintf(stderr,"   ### Fin : decodageHuffman ### \n\n\n");
	#endif
    return resultatTete;
}

//author : Alex
arbre* ArbreHufman(maillon* liste)
{
	#ifdef HUFDEBUG_ARBRE
	void debugAbrePrinter(arbre* tree)
	{
		if(tree == NULL)
			fprintf(stderr,"..");
		else if(tree->D == NULL && tree->G == NULL)
			fprintf(stderr," %c ",tree->i.symbole);
		else
		{
			fprintf(stderr,"(");
			debugAbrePrinter(tree->G);
			fprintf(stderr,",");
			debugAbrePrinter(tree->D);
			fprintf(stderr,")");
		}
	}
	#endif

	arbre* tab[size(liste)];	//création de l'arbre de codage
	arbre* new=NULL; //le nouvelle arbre
	maillon* save=liste;
	int i,cpt; //cpt de for
	int min1,min2; //proba minimals, min1<=min2
	int i1,i2; //indice ou sont trouver les valeurs min
	int tailleT = size(liste);//nombre de caractere different dans notre liste
	#ifdef HUFDEBUG_ARBRE
	fprintf(stderr,"   ### Debut : ArbreHuffman ### \n");
	fprintf(stderr,"\nPour la lecture des noeuds fusioné, (a,b) signifie que l'on fusionne le noeud dont les fils sont a et b (respectviement a gauche et a droite)\nle symbole \"..\" signifie qu'il n'y a pas de fils de ce cote de l'arbre\n\n");
	#endif
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
	#ifdef HUFDEBUG_ARBRE
	fprintf(stderr,"Liste des noeuds fusionner :\n");
	#endif
	if(tailleT == 1)
	{
	#ifdef HUFDEBUG_ARBRE
	fprintf(stderr,"Aucun noeud fusionner, liste à symbole unique\n");
	#endif
	tab[0] -> D = malloc(sizeof(arbre));
	(tab[0] -> D) -> i.proba=liste->autre;
	(tab[0] -> D) -> i.symbole=liste->lettre;
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
		#ifdef HUFDEBUG_ARBRE
		debugAbrePrinter(tab[i1]);
		fprintf(stderr," // ");
		debugAbrePrinter(tab[i2]);
		fprintf(stderr,"\n");
		#endif
		//maj de tailleT et du tableau
		//on prévoit de réduire la taille du tableau de 1 cran
		//les deux arbre fusionner doivent devenir innaccessible
		//la fusion des deux arbres doit deveni r accessible
			//on prépare supprime les deux arbre qui on substituer la fusion

		if(i1<tailleT-2)
		{
			if(i2==tailleT-2)
				tab[i1] =tab[tailleT-1];
			else
			{		
				tab[i1] =tab[tailleT-2];
				tab[i2] =tab[tailleT-1];
			}
		}
		else
		{
			if(i1==tailleT-2)
				tab[i2] =tab[tailleT-1];
			else
			{		
				tab[i2] =tab[tailleT-2];
				tab[i1] =tab[tailleT-1];
			}
		}
		tab[tailleT-2]=new;
			//on ajoute a la fin futur du tableau la somme des deux anciens
			//on maj le tableau
		tailleT --;
	}
	#ifdef HUFDEBUG_ARBRE
	printArbre(*tab);
	fprintf(stderr,"   ### Fin : ArbreHuffman ### \n\n\n\n");
	#endif
	return *tab;
}

//author : Alex
// maillon -> lettre == symbole sans codage
// maillon -> autre == symbole codé par huffman
// maillon -> autre2 == nombre de bit significatif
arbre* arbreFromTable(maillon *table)
{
	void ajouterDansArbre(arbre* tree, int code,char symb,int taille)
	{
		if(taille>1) //il y a encore des bits a lire
		{
			if( ( (code>>(taille-1)) &1) == 0)
			{
				if (tree -> G == NULL)
				{
					tree->G = malloc(sizeof(arbre));
					(tree->G)->D = NULL;
					(tree->G)->G = NULL;
				}
				ajouterDansArbre(tree->G,code,symb,taille-1);
			}
			else
			{
				if (tree -> D == NULL)
				{
					tree->D = malloc(sizeof(arbre));
					(tree->D)->D = NULL;
					(tree->D)->G = NULL;
				}
				ajouterDansArbre(tree->D,code,symb,taille-1);
			}
		}
		else	
		{	

			if( ((code>>(taille-1)) & 1)== 0)
			{
				tree->G = malloc(sizeof(arbre));
				tree = tree->G;
			}
			else//(code>>(taille-1))&1 == 1
			{
				tree->D = malloc(sizeof(arbre));
				tree = tree->D;
			}
			tree->G = NULL;
			tree->D = NULL;
			tree->i.symbole = symb;
		}
	}
	arbre* res = malloc(sizeof(arbre));
	#ifdef HUFDEBUG_TABLE
	fprintf(stderr,"\n   # # Debut : arbreFromTable() # #\n");
	#endif
	res->G = NULL;
	res->D = NULL;
	while(table != NULL)
	{
		ajouterDansArbre(res,table->autre,table->lettre,table->autre2);
		table = table->suivant;
	}
	#ifdef HUFDEBUG_TABLE
	fprintf(stderr,"arbre obtenu : \n");
	printArbre(res);
	fprintf(stderr,"\n   # # Fin : arbreFromTable() # #\n");		
	#endif

return res;
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
				fprintf(stderr,"Symbole/Valeur : %c / ",tree->i.symbole);
				for (i=taille-1;i>=0;i--)
					fprintf(stderr,"%d",(value>>i)&1);
				fprintf(stderr,"\n");
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
	
	fprintf(stderr,"\n\nAffichage de l'arbre d'huffman : \n");
	printArbre_rec(tree,0,0); 
}
