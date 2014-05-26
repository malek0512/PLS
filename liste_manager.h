//Liste chainee
typedef struct maillon {
    int lettre; //information contenant les info du symbole
    int autre; //information auxiliaire
    struct maillon* suivant;
}maillon;

//ce type represente la liste
typedef struct TeteListe *maillon;

//Ajoute en Tete une lettre et sa frequence
//author Quentin
maillon* ajoutEnTete(maillon* Tete, int lettre, int frequence);

//affiche la liste chainer
//author : Alexandre
void print(maillon* tete);

//renvoie la taille de la liste a partir du pointeur donée
//author : Alexandre
int size(maillon* tete);

//Verifie si la liste est vide
//author : Quentin
int estVide(maillon liste);

//libere tout les elements de la liste
//a utiliser que si la liste deviens inutile
//a utiliser impérativement avant la fin du programme pour chaque liste
//author : Alexandre
void liberer(maillon* tete);
