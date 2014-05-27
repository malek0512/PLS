#ifndef DEF_LISTE_MANAGER
#define DEF_LISTE_MANAGER

//Liste chainee
typedef struct maillon {
    char lettre; //information contenant les info du symbole
    int autre; //information auxiliaire
    struct maillon* suivant;
}maillon;

//ce type represente la liste
//typedef struct TeteListe *maillon;

// Initialise une liste vide
// Auteur : Marie
maillon* initialiser(maillon* l);

// Insère un élément A après un élément B
// Auteur : Marie
void insererElement(maillon* A, maillon* B);

//Ajoute en Tete une lettre et sa frequence
//author Quentin
maillon* ajoutEnTete(maillon* Tete, int lettre, int frequence);

//Ajout en queue
maillon* ajouterEnQueue(maillon* liste, int lettre, int frequence);

//Ajoute en Queue un maillon
//Author : Malek
void ajoutEnQueue(maillon** Queue, char byte, int autre);

//affiche la liste chainer
//author : Alexandre
void print(maillon* tete);

//renvoie la taille de la liste a partir du pointeur donée
//author : Alexandre
int size(maillon* tete);

//Verifie si la liste est vide
//author : Quentin
int estVide(maillon* liste);

//libere tout les elements de la liste
//a utiliser que si la liste deviens inutile
//a utiliser impérativement avant la fin du programme pour chaque liste
//author : Alexandre
void liberer(maillon* tete);

//Aloue une cellule de type maillon, avec les paramètres lettre et (frequence ou Prob)
maillon* Allouer(char lettre, int autre);

//Recherche d'un élément
//author : Quentin
maillon* rechercherElement(maillon* liste, int valeur);

//Recherche du ieme element
//author : Quentin
maillon* find_indice(maillon* liste, int indice);

//Fonction inutile pour l'instant ( j'en avais pas besoin enfaite , je la laisse a disposition si jamais )
//retourne l'indice d'un element
//author : Quentin
int return_indice(maillon* liste, int lettre, int autre);

//Effacer tous les éléments ayant une certaine valeur
//author : Quentin
maillon* supprimerElement(maillon* liste, int lettre, int autre);

// Supprime l'élément A de la liste tete (et seulement celui là)
// S'il n'est pas présent dans la liste, on affiche un message
// Auteur : Marie
void supprimer(maillon* A, maillon* tete);

//Renvoie une copie de la liste donnée en argument
//author : Alexandre
maillon* copieList(maillon *liste);

//Afficher la liste
void afficherListe(maillon *liste);

//Ecrit un bit dans la liste chainée passée en parametre. N'effectue que des ajouts en queue
//Attention, NE PAS OUBLIER d'ECRIRE LE NOMBRE DE BITS SIGNIFICATIF (après encodage) DANS LA CELULLE QUEUE (champs <autre>).
//author : Malek
void writeBit(maillon** Tete, maillon** Queue, char bit);

#endif

