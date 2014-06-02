#ifndef DEF_LISTE_MANAGER
#define DEF_LISTE_MANAGER

//Liste chainee
typedef struct maillon {
    unsigned char lettre; //information contenant les info du symbole
        //(Huffman: symbole) 
        //(Reader: Un octet lu)
    
    int autre; //information auxiliaire, 
        //(Huffman: code du symbole) dans la table de Huffman 
        //(Reader:Frequence)
    
    int autre2; //information axiliaire 2, 
        //(Huffman: nb_bit_significatif du champs autre)
        //Sert a lecture bit a bit d'un message encodé par Huffman
    
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

//Ajout en queue avec 3 parametre
void ajouterEnQueue2(maillon** liste, int lettre, int autre, int autre2);

//Ajoute en Queue un maillon
//Author : Malek
void ajoutEnQueue(maillon** Tete, maillon** Queue, unsigned char byte, int autre);

//affiche la liste chainer
//author : Alexandre
void print(maillon* tete);

//Quasi copie du print ci dessus. Fonction destiner aux affichage pour Huffman
//Car la champs <autre> peut être egale a 0
//author : Alexandre
void print2(maillon* tete);
void print4(maillon* tete);

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
maillon* Allouer(unsigned char lettre, int autre);

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



//Et pouf un miracle aparrait
//author : Alex
void writeBit2(maillon** Tete, maillon** Queue, unsigned char bit);

//Et pas, un second miracle aparrait
//author : Alex
int readBit2(maillon* Tete);

// Ecrit un bit dans la liste chainée passée en parametre. 
// N'effectue que des ajouts en queue. 
// Si Tete == Queue == NULL alors la Tete est mise a jour, par ajoutEnQueue
// Met a jour, le nombre de bit significatif
//Ecrit un bit dans la liste chainée passée en parametre. N'effectue que des ajouts en queue
//Attention, NE PAS OUBLIER d'ECRIRE LE NOMBRE DE BITS SIGNIFICATIF (après encodage) DANS LA CELULLE QUEUE (champs <autre>).
//author : Malek
void writeBit(maillon** Tete, maillon** Queue, char bit);

// ********************************************************************************
// *INVARIANT 
// * Pré condition : Si windowBuffer != -1 alors il pointe sur le bit lu
// *                 Sinon C'est qu'il n'y a plus rien a lire
// * Post condition : Si windowBuffer != -1 alors windowBuffer pointe sur le bit suivant
// *                  Sinon C'est qu'il n'y a plus rien a lire

// * Au 2eme appel de la fonction, s'il ne s'agit pas d'une nouvelle liste, 
// * donc pointeurDeListeTete == Tete 
// * Lit un bit dans la liste chainée passée en parametre. 
// * Le bit lu est mis dans la variable *bit en paramtre.
// * @return: 0 s'il a lu un bit, sinon renvoie 1.
// * Ne modifie pas la liste et n'utilise pas la Queue 
//_ATTENTION ! FONCTION A NE PAS UTILISER SUR DEUX LISTES DIFFERENTE EN SIMULTANÉ, 
// OU EN MÊME TEMPS QUE writeBit
//_ATTENTION ! TANT QU'UNE LISTE N'EST PAS LU JUSQUA LA FIN, LE BUFFER N'EST PAS VIDE.
// *********************************************************************************
//author : Malek
int readBit(maillon* Tete, maillon* Queue, char* bit);

void copieAutre(maillon* src, maillon* dest);

//Renvoie la queue de la liste
maillon* getQueue(maillon* Tete);
void afficherK(maillon* res);
#endif

