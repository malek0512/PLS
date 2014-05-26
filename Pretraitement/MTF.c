
#include "MTF.h"




void MTF(llist liste, )
{

}



//Ajoute un élément en tete
llist ajouterEnTete(llist liste, int valeur)
{
    // On crée un nouvel élément 
    element* nouvelElement = malloc(sizeof(element));
 
    //On assigne la valeur au nouvel élément 
    nouvelElement->val = valeur;
 
    //On assigne l'adresse de l'élément suivant au nouvel élément 
    nouvelElement->nxt = liste;
 
    //On retourne la nouvelle liste, i.e. le pointeur sur le premier élément
    return nouvelElement;
}

//Affiche la liste chainée
void afficherListe(llist liste)
{
    element *tmp = liste;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        printf("%d ", tmp->val);
        /* On avance d'une case */
        tmp = tmp->nxt;
    }
}


//Verifie si la liste est vide
int estVide(lliste liste)
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



