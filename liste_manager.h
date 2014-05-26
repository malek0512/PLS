#ifndef DEF_LISTE_MANAGER
#define DEF_LISTE_MANAGER

//Liste chainee
typedef struct maillon {
    int lettre; //information contenant les info du symbole
    int autre; //information auxiliaire
    struct maillon* suivant;
}maillon;

//ce type represente la liste
typedef struct TeteListe *maillon;

//Ajoute en Tete une lettre et sa frequence
//a faire
void ajoutEnTete(maillon* Tete, int lettre, int frequence);

//renvoie la taille de la liste a partir du pointeur donée
//author : Alexandre
int size(maillon* tete);

<<<<<<< HEAD
//libere tout les elements de la liste
//a utiliser que si la liste deviens inutile
//a utiliser impérativement avant la fin du programme pour chaque liste
//author : Alexandre
void liberer(maillon* tete);
=======
#endif

>>>>>>> 1304043140192d205128257e0f6fc02c909869d3
