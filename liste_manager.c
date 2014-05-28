#include<stdio.h>
#include<stdlib.h>
#include "liste_manager.h"

//Variables globale de la fonction writeBit
static char buffer=0;
static int windowBuffer=7;

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

maillon* ajoutEnTete(maillon* liste, int lettre, int frequence){
	// On crée un nouvel élément 
	maillon* nouvelElement = malloc(sizeof(maillon));
 
	//On assigne la valeur au nouvel élément 
	nouvelElement->lettre = lettre;

	//On assigne la frequence au nouvel élément 
	nouvelElement->autre = frequence;
 
	//On assigne l'adresse de l'élément suivant au nouvel élément 
	nouvelElement->suivant = liste;
 
	//On retourne la nouvelle liste, i.e. le pointeur sur le premier élément
	return nouvelElement;
} 


maillon* ajouterEnQueue(maillon* liste, int lettre, int frequence)
{
	maillon* nouvelElement = malloc(sizeof(maillon));  
	nouvelElement->lettre = lettre;
	nouvelElement->autre = frequence;
 	// On ajoute en fin, donc aucun élément ne va suivre 
	nouvelElement->suivant = NULL;
 
	if(liste == NULL)
	{
		// Si la liste est videé il suffit de renvoyer l'élément créé 
		return nouvelElement;
	}
	else
	{
		/* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
		indique que le dernier élément de la liste est relié au nouvel élément */
		maillon* tmp=liste;
		while(tmp->suivant != NULL)
		{
			tmp = tmp->suivant;
		}
		tmp->suivant = nouvelElement;
		return liste;
    	}
}

void ajouterEnQueue2(maillon** liste, int lettre, int autre, int autre2)
{
	maillon* nouvelElement = malloc(sizeof(maillon));  
	nouvelElement->lettre = lettre;
	nouvelElement->autre = autre;
	nouvelElement->autre2 = autre2;
 	// On ajoute en fin, donc aucun élément ne va suivre 
	nouvelElement->suivant = NULL;
 
	if(*liste == NULL)
	{
		// Si la liste est videé il suffit de renvoyer l'élément créé 
		*liste=nouvelElement;
	}
	else
	{
		/* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
		indique que le dernier élément de la liste est relié au nouvel élément */
		maillon* tmp=*liste;
		while(tmp->suivant != NULL)
		{
			tmp = tmp->suivant;
		}
		tmp->suivant = nouvelElement;
    	}
	
}

void ajoutEnQueue(maillon** Queue, char byte, int autre){
    maillon* AC = Allouer( byte, autre );
	if (*Queue != NULL)
	    (*Queue)->suivant = AC;

    *Queue = AC;
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
	if(tete->suivant != NULL)
		liberer(tete->suivant);
	free(tete);
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
            //On affiche le carctere
            printf("Symbole/Autre : %c / %d\n", save->lettre, save->autre);
        else
            //On affiche son numero
            printf("Symbole/Autre : Caractère numero %d / %d\n", save->lettre, save->autre);
        
    	save = save->suivant;	
	}
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

maillon* Allouer(char lettre, int autre){
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

// Supprime l'élément A de la liste tete (et seulement celui là)
// S'il n'est pas présent dans la liste, on affiche un message
// Auteur : Marie
void supprimer(maillon* A, maillon* tete){
	maillon* tmp;
	tmp = tete;
	while(tmp->suivant != NULL && tmp->suivant != A){
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

maillon* copieList(maillon *liste)
{
maillon *res=NULL;
maillon *save = liste;
while(save != NULL)
	{
	res=ajouterEnQueue(res,save->lettre,save->autre);
	save = save->suivant;
	}
	return res;	
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

void writeBit(maillon** Tete, maillon** Queue, char bit){

    //maillon* cellule;

    // Masque le bit a la position windowBuffer
    //buffer &= ~(1<<windowBuffer);

    //Place le bit dans le buffer
    buffer |= (bit & 1) << windowBuffer;

    //La windowBuffer diminue
    windowBuffer--;

    // La windowBuffer == 0, il faut inserer dans le fichier les 8 bits
    if (windowBuffer==0) {  
        ajoutEnQueue(Queue, buffer, -1);

        //Reinitialisation du buffer et windows
        buffer = 0;
        windowBuffer = 7;
    }
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
