#include "huffman.h"
//#define DEBUG
//author : Alex

#ifdef DEBUG
static int cpt=0;
#endif

maillon* creationTableHuffman(arbre* arbreHuffman)
{
	void creationTableHuffmanRec(arbre* arbreHuffman,int code, int taille,maillon** res)
	{
        if (arbreHuffman != NULL){   
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
	}
	
	maillon *res = NULL;
	if(arbreHuffman == 0)
		fprintf(stderr,"   # # # Error # # #\nhuffman.c // creationTableHuffman() \nL'arbre d'huffman donnée est vide\n");
		
	creationTableHuffmanRec(arbreHuffman,0,0,&res);
	return res;
}

//author : Alex
//maillon -> lettre == symbole sans codage
//la liste de retour sera de la forme (octect / nb Significatif (effectif que pour le dernier bit))
maillon* codageHuffman(maillon *liste, arbre *arbreHuffman)
{
	#ifdef DEBUG
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
	#ifdef DEBUG
	fprintf(stderr,"   ### Debut : codageHuffman ### \n");
	#endif
	//création de la table dictionnaire a partir de l'arbre d'huffman
	maillon *tableHuffman = creationTableHuffman(arbreHuffman);
	maillon *saveArbre = tableHuffman;

	//Parcour de la liste
	#ifdef DEBUG
	fprintf(stderr,"Liste des mots lu : \n");
	#endif
	while(saveListe != NULL)
	{	
		
		//lecture d'un octet
		while (saveArbre->lettre != saveListe->lettre)
		{//le symbole apartient a l'arbre comme il doit appartenir a la liste
			saveArbre= saveArbre->suivant;
			#ifdef DEBUG
			if(saveArbre==NULL)
			{
				fprintf(stderr,"\n   # # # Error # # #\n");
				fprintf(stderr,"hufman.c  // codageHuffman() \n");
				fprintf(stderr,"Le caractere \"%c\" de la liste de caractere devant etre codé n'a pas était trouver dans l'arbre \n",saveListe->lettre);
				fprintf(stderr,"Segmentation fault en approche\n");
			}
			#endif
		}
		#ifdef DEBUG
		/*
		fprintf(stderr,"%c -> ",saveArbre->lettre);
		cpt=0;
		*/
		#endif
		for(i=saveArbre->autre2-1;i>=0;i--)
		{
			#ifdef DEBUG
			/*
			if(cpt == 4)
				{
				cpt=0;
				printf(" ");
				}
			fprintf(stderr,"%d",( (saveArbre->autre)>>i)&1);
			*/
			#endif
			writeBit2(&tete, &queue, ( (saveArbre->autre)>>i)&1);
		}
		#ifdef DEBUG
		fprintf(stderr,"\n");
		#endif
		saveArbre = tableHuffman;
		saveListe = saveListe->suivant;	
	}
	liberer(tableHuffman);
	#ifdef DEBUG
	printf("\nMot codé : \n");
	afficherK(tete);
	fprintf(stderr,"   ### Fin : codageHuffman ### \n\n\n");
	#endif
	return tete;
}


maillon* decodageHuffman2(maillon *liste, arbre *tableHuffman)
{
    //Version Misterious Guy
	#ifdef DEBUG
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

    int bit = readBit2(Tete);

	#ifdef DEBUG
	fprintf(stderr,"   ### Fin : decodageHuffman ###\n");
	fprintf(stderr,"Liste des bits lu : \n");
	#endif
	while( bit != -1 )
	{
		#ifdef DEBUG
		fprintf(stderr,"%i",bit);
		#endif
        	if (AvC->G !=NULL && (bit==0))
			AvC = AvC->G;
		else if (AvC->D !=NULL && (bit == 1))
			AvC = AvC->D;
		if (AvC->D == NULL && AvC->G == NULL)
		{ 
		#ifdef DEBUG
		 fprintf(stderr," -> %c\n",AvC->i.symbole);
		#endif
	    		ajoutEnQueue(&resultatTete,&resultatQueue, AvC->i.symbole, -1 );
	    		AvC = tableHuffman;
		}
	        bit = readBit2(Tete);
	}
	#ifdef DEBUG
	printf("\nMot décodé : \n");
	printDebug(resultatTete);
	fprintf(stderr,"   ### Fin : decodageHuffman ### \n\n\n");
	#endif
    return resultatTete;
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
	
    //Version Malek
    maillon* resultatTete = NULL;
    maillon* resultatQueue = NULL;
    maillon* Tete = liste;
    maillon* Queue = NULL; //Cette variable ne sert a rien !!!
    arbre* AvC = tableHuffman;
    char bit;
    int OK = readBit(Tete, Queue, &bit); //read bit n'utilise pas Queue...
    fprintf(stderr,"\n%d", OK);
    while( OK ){ //si readBit retourne une sorte de bool, pourquoi pas mettre directement la fonction dans la condition, et pas OK ?
        if (AvC->G !=NULL && (bit & 1))
            AvC = AvC->G;
        else if (AvC->D !=NULL && !(bit & 1))
            AvC = AvC->D;
        else { 
            //Nous somme arrivé dans une feuille de l'arbre
            ajoutEnQueue(&resultatTete,&resultatQueue, AvC->i.symbole, -1 );
            AvC = tableHuffman;
        }
        OK = readBit(Tete, Queue, &bit);  //read bit n'utilise pas Queue... (bis)
    }

    return resultatTete;
}



//author : Alex
arbre* ArbreHufman(maillon* liste)
{
	#ifdef DEBUG
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
	#ifdef DEBUG
	fprintf(stderr,"   ### Debut : ArbreHuffman ### \n");
//	fprintf(stderr,"\nPour la lecture des noeuds fusioné, (a,b) signifie que l'on fusionne le noeud dont les fils sont a et b (respectviement a gauche et a droite)\nle symbole \"..\" signifie qu'il n'y a pas de fils de ce cote de l'arbre\n\n");
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
	#ifdef DEBUG
	fprintf(stderr,"Liste des noeuds fusionner :\n");
	#endif
	if(tailleT == 1)
	{
	#ifdef DEBUG
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
		#ifdef DEBUG
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
	#ifdef DEBUG
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
		#ifdef DEBUG
		fprintf(stderr,"\nIN FUN :: Symbole/Valeur/taille en cours de traitement : %c / %i / %i \n",symb,code,taille);
		fprintf(stderr,"bit lu == %i\n",(code>>(taille-1)) &1);
		#endif
		if(taille>1) //il y a encore des bits a lire
		{
			if( ( (code>>(taille-1)) &1) == 0)
			{
				#ifdef DEBUG
				fprintf(stderr,"G");
				#endif
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
				#ifdef DEBUG
				fprintf(stderr,"D");
				#endif
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
				#ifdef DEBUG
				fprintf(stderr,"G // fin");
				#endif
				tree->G = malloc(sizeof(arbre));
				tree = tree->G;
			}
			else//(code>>(taille-1))&1 == 1
			{
				#ifdef DEBUG
				 fprintf(stderr,"D // fin");
				#endif
				tree->D = malloc(sizeof(arbre));
				tree = tree->D;
			}
			tree->G = NULL;
			tree->D = NULL;
			tree->i.symbole = symb;
		}
	}
	arbre* res = malloc(sizeof(arbre));
	res->G = NULL;
	res->D = NULL;
	#ifdef DEBUG
	fprintf(stderr,"\n   # # Debut : arbreFromTable() # # #\n");		
	#endif
	while(table != NULL)
	{
		#ifdef DEBUG
		//fprintf(stderr,"\n #Avant apelle FUN\n");		
		//printArbre(res);
		//fprintf(stderr,"\nSymbole/Valeur/taille en cours de traitement : %c / %i / %i \n",table->lettre,table->autre,table->autre2);
		#endif
		ajouterDansArbre(res,table->autre,table->lettre,table->autre2);
		#ifdef DEBUG
		//fprintf(stderr,"\n # # Apres apelle FUN\n");		
		#endif
		table = table->suivant;
	}
	#ifdef DEBUG
	fprintf(stderr,"arbre obtenu : \n");
	printArbre(res);
	fprintf(stderr,"\n   # # Fin : arbreFromTable() # # #\n");		
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
	printArbre_rec(tree,0,0); //peut etre mettre taille a 1, a voir...
}
