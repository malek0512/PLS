#include <stdio.h>
#include <stdlib.h>
#include "../includes/liste_manager.h"

//Variables globale de la fonction writeBit et readBit
static unsigned char buffer2=0;
static int windowBuffer2=-1;
static int windowBuffer3=8;
static maillon* ptMG = NULL;

// Initialise une liste vide
// Auteur : Marie
maillon* initialiser(maillon* l){
	l = malloc(sizeof(maillon));
	l = NULL; // Attention erreur possible
	return l;
}

// Insère un élément A après un élément B
// Auteur : Marie
void insererElement(maillon* A, maillon* B){
	A->suivant = B->suivant;
	B->suivant = A;
}

void ajoutEnTete(maillon** tete, maillon** queue,int lettre, int frequence){
	// On crée un nouvel élément 
	maillon* nouvelElement = malloc(sizeof(maillon));
 
	//On assigne la valeur au nouvel élément 
	nouvelElement->lettre = lettre;

	//On assigne la frequence au nouvel élément 
	nouvelElement->autre = frequence;
 
	//On assigne l'adresse de l'élément suivant au nouvel élément 
	nouvelElement->suivant = *tete;
	
	//On vérifie si la tete n'était pas assigner avant, si c'est le cas la queue est donc sur l'element ajouter
	if(*tete == NULL)
		*queue = nouvelElement;
	
	//On retourne la nouvelle liste, i.e. le pointeur sur le premier élément
	*tete = nouvelElement;
} 

void ajoutEnTete2(maillon** tete,maillon** queue, int lettre, int frequence, int autre2){
	// On crée un nouvel élément 
	maillon* nouvelElement = malloc(sizeof(maillon));
 
	//On assigne la valeur au nouvel élément 
	nouvelElement->lettre = lettre;

	//On assigne la frequence au nouvel élément 
	nouvelElement->autre = frequence;

	//On assigne la frequence au nouvel élément 
	nouvelElement->autre2 = autre2;	 

	//On assigne l'adresse de l'élément suivant au nouvel élément 
	nouvelElement->suivant = *tete;

	//On vérifie si la tete n'était pas assigner avant, si c'est le cas la queue est donc sur l'element ajouter
	if(*tete == NULL)
		*queue = nouvelElement;
 
	//On retourne la nouvelle liste, i.e. le pointeur sur le premier élément
	*tete = nouvelElement;
} 


void ajouterEnQueue(maillon** tete,maillon** queue, int lettre, int autre)
{
	maillon* nouvelElement = malloc(sizeof(maillon));  
	nouvelElement->lettre = lettre;
	nouvelElement->autre = autre;
 	// On ajoute en fin, donc aucun élément ne va suivre 
	nouvelElement->suivant = NULL;
 
	if(*tete == NULL)
	{
		// Si la liste est videé il suffit de renvoyer l'élément créé 
		*tete=nouvelElement;
		*queue = nouvelElement;
	}
	else
	{
		/* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
		indique que le dernier élément de la liste est relié au nouvel élément */
		(*queue)->suivant = nouvelElement;
		(*queue) = nouvelElement;
    	}
}


void ajouterEnQueue2(maillon** tete,maillon** queue, int lettre, int autre,int autre2)
{
	maillon* nouvelElement = malloc(sizeof(maillon));  
	nouvelElement->lettre = lettre;
	nouvelElement->autre = autre;
	nouvelElement->autre2 = autre2;
 	// On ajoute en fin, donc aucun élément ne va suivre 
	nouvelElement->suivant = NULL;
 
	if(*tete == NULL)
	{
		// Si la liste est videé il suffit de renvoyer l'élément créé 
		*tete=nouvelElement;
	}
	else
	{
		/* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
		indique que le dernier élément de la liste est relié au nouvel élément */
		(*queue)->suivant = nouvelElement;
    	}
	*queue = nouvelElement;
}

int size(maillon* tete)
{
int res = 1;
maillon* save=tete;

if (save == NULL)
	return 0;
while(save->suivant != NULL)
	{
	save = save->suivant;
	res++;
	}
	return res;
}

void liberer(maillon* tete)
{
	maillon* parcours=tete;
	while (parcours!=NULL){
        //if(tete->suivant != NULL)
          //  liberer(tete->suivant);
        free(parcours);
        parcours=parcours->suivant;
    }
}

void print(maillon* tete)
{
	maillon* save = tete;
	while(save != NULL)
	{
		if(save->autre == 0)
			// Si l'élément save indique une répétition, on affiche le nombre de répétitions associés et
			// non le caractère correspondant à l'entier save->autre
			printf("Symbole/Autre : %d / %d Nombre de répétitions\n", save->lettre, save->autre);
        else if (save->lettre == -1)
            //On signal que c'est un caractere de EOF, théoriquement non present dans la liste
            printf("Symbole/Autre : %s / %d\n","Fin de fichier\0" , save->autre);
        else if (save->lettre == '\n')
            //On signal que c'est un retour charriot
            printf("Symbole/Autre : %s / %d\n","Retour charriot\0" , save->autre);
        else if (save->lettre <128 && save->lettre>=0)
            //On affiche le caractere
            printf("Symbole/Autre : %c / %d\n", save->lettre, save->autre);
        else
            //On affiche son numero
            printf("Symbole/Autre : Caractère numero %d / %d\n", save->lettre, save->autre);
        
    	save = save->suivant;	
	}
}

void print2(maillon* tete)
{
	maillon* save = tete;
	while(save != NULL)
	{
        printf(" %02x", save->lettre);
    	save = save->suivant;	
	}
        printf("\n");
}
void print4(maillon* tete){
	maillon* save = tete;
	while(save != NULL)
	{
        if (save->lettre != '\n')
            printf(" Symbole : %c, Code : %d, Nb_bits : %d\n", save->lettre, save->autre, save->autre2);
        else
            printf(" Symbole : Retour charriot, Code : %d, Nb_bits : %d\n", save->autre, save->autre2);
    	save = save->suivant;	
	}
        printf("\n");
}

//Verifie si la liste est vide
int estVide(maillon* liste)
{
    if(liste == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

maillon* Allouer(unsigned char lettre, int autre){
    maillon* cellule = malloc(sizeof(maillon));
    cellule->lettre = lettre;
    cellule->autre = autre;
    cellule->suivant = NULL;
    return cellule;
}

//Recherche d'un élément
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
}

//Recherche du ieme element
maillon* find_indice(maillon* liste, int indice)
{
    int i;
    // On se déplace de i cases, tant que c'est possible 
    for(i=0; i<indice && liste != NULL; i++)
    {
        liste = liste->suivant;
    }
 
    // Si l'élément est NULL, c'est que la liste contient moins de i éléments 
    if(liste == NULL)
    {
        return NULL;
    }
    else
    {
        // Sinon on renvoie l'adresse de l'élément i 
        return liste;
    }
}


//Fonction inutile pour l'instant ( j'en avais pas besoin enfaite , je la laisse a disposition si jamais )
//retourne l'indice d'un element


//Effacer tous les éléments ayant une certaine valeur
maillon* supprimerElement(maillon* liste, int lettre, int autre)
{
    // Liste vide, il n'y a plus rien à supprimer 
    if(liste == NULL)
        return NULL;
 
    // Si l'élément en cours de traitement doit être supprimé 
    if((liste->lettre == lettre) && (liste->autre == autre))
    {
        /* On le supprime en prenant soin de mémoriser 
        l'adresse de l'élément suivant */
        maillon* tmp = liste->suivant;
        free(liste);
        // L'élément ayant été supprimé, la liste commencera à l'élément suivant pointant sur une liste qui ne contient plus aucun élément ayant la valeur recherchée 
        tmp = supprimerElement(tmp, lettre,autre);
        return tmp;
    }
    else
    {
        /* Si l'élement en cours de traitement ne doit pas être supprimé,
        alors la liste finale commencera par cet élément et suivra une liste ne contenant
        plus d'élément ayant la valeur recherchée */
        liste->suivant = supprimerElement(liste->suivant, lettre,autre);
        return liste;
    }
}

maillon* supprimerElement2(maillon* liste, int lettre, int autre,int autre2)
{
    // Liste vide, il n'y a plus rien à supprimer 
    if(liste == NULL)
        return NULL;
 
    // Si l'élément en cours de traitement doit être supprimé 
    if((liste->lettre == lettre) && (liste->autre == autre) &&(liste->autre2 == autre2))
    {
        /* On le supprime en prenant soin de mémoriser 
        l'adresse de l'élément suivant */
        maillon* tmp = liste->suivant;
        free(liste);
        // L'élément ayant été supprimé, la liste commencera à l'élément suivant pointant sur une liste qui ne contient plus aucun élément ayant la valeur recherchée 
        tmp = supprimerElement2(tmp, lettre,autre,autre2);
        return tmp;
    }
    else
    {
        /* Si l'élement en cours de traitement ne doit pas être supprimé,
        alors la liste finale commencera par cet élément et suivra une liste ne contenant
        plus d'élément ayant la valeur recherchée */
        liste->suivant = supprimerElement2(liste->suivant, lettre,autre,autre2);
        return liste;
    }
}

// Supprime l'élément A de la liste tete (et seulement celui là)
// S'il n'est pas présent dans la liste, on affiche un message
// Auteur : Marie
void supprimer(maillon* A, maillon* tete){
	maillon* tmp;
	tmp = tete;                                         //Ajouter un if (tete != NULL)
	while(tmp->suivant != NULL && tmp->suivant != A){   // Dans le cas où A == tete ?
		tmp = tmp->suivant;
	}
	if(tmp->suivant==NULL)
		printf("Erreur : l'élément n'est pas dans la liste");
	else
	{
		tmp->suivant = A->suivant;
		free(A);
	}
}	

void copieList(maillon** teteSrc, maillon** teteDest, maillon** queueDest)
{
maillon *save = *teteSrc;
*teteDest=NULL;
*queueDest = NULL;
while(save != NULL)
	{
	ajouterEnQueue2(teteDest,queueDest,save->lettre,save->autre,save->autre2);
	save = save->suivant;
	}
}

void afficherListe(maillon *liste)
{
   maillon *tmp = liste;
	while(tmp != NULL)
	{
		printf("%c, %d \n", tmp->lettre,tmp->autre);
		tmp = tmp->suivant;
	}
}

void afficherListe2(maillon *liste)
{
   maillon *tmp = liste;
	while(tmp != NULL)
	{
		printf("%c, %d , %d\n", tmp->lettre,tmp->autre,tmp->autre2);
		tmp = tmp->suivant;
	}
}

void writeBit(maillon **Tete, maillon **Queue, unsigned char bit)
{
if(windowBuffer2==-1)
{//le buffer est archi full, on doit donc ajouter sur un octet libre, qui na pas était crée au préalable pour eviter d'avoir un octet vide...
//il faut rajouter un octet
	ajouterEnQueue(Tete,Queue,0,0);
	windowBuffer2=7;
	buffer2=0;
}
//l'octet est ok, on peut ajouter
	//maj du buffer
	buffer2 |= (bit & 1) << windowBuffer2;
	windowBuffer2--;
	(*Queue)->autre++;
	(*Queue)->lettre= buffer2;

}

void initReadBit(maillon *Tete)
{
	ptMG = Tete;
}

int readBit()
{
	if(windowBuffer3==0)
	{
		ptMG = ptMG->suivant;
		if(ptMG == NULL)
		{
			return -1; //plus rien a lire
		}
	windowBuffer3=8;
}
		
	else if((windowBuffer3+ptMG->autre)<=8) //trouver la condition pour dire que sur l'octet actuelle on a fini de lire
	{		
		return -1;
	}
	windowBuffer3--;
	return (ptMG->lettre>>windowBuffer3)&1;
}


void copieAutre(maillon* src, maillon* dest)
{
	while((src != NULL) && (dest !=NULL))
	{
		dest->autre = src->autre;
		dest = dest->suivant;
		src = src->suivant;

	}
}

void copieAutre2(maillon* src, maillon* dest)
{
	while((src != NULL) && (dest !=NULL))
	{
		dest->autre = src->autre;
		dest->autre2 = src->autre2;
		dest = dest->suivant;
		src = src->suivant;

	}
}

maillon* getQueue(maillon* Tete){
    maillon* AC = Tete;
    if (AC != NULL){ 
        while(AC->suivant != NULL){
            AC = AC->suivant;
        }
        return AC;
    }else
        return NULL;
}
void afficherK(maillon* res){
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
