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
void ajoutEnTete(maillon** liste, maillon** queue, int lettre, int frequence);

void ajoutEnTete2(maillon** liste, maillon** queue, int lettre, int frequence, int autre2);


//Ajout en queue
void ajouterEnQueue(maillon** tete,maillon** queue, int lettre, int autre);

//Ajout en queue avec 3 parametre
void ajouterEnQueue2(maillon** tete,maillon** queue, int lettre, int autre,int autre2);

maillon* ajouterEnQueue3(maillon* liste, int lettre, int frequence,int autre2);

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

//Sert a l'affichage d'une table de huffman de type maillon
//Author Malek
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

maillon* supprimerElement2(maillon* liste, int lettre, int autre,int autre2);

//Renvoie une copie de la liste donnée en argument
//author : Alexandre
void copieList(maillon** teteSrc, maillon** teteDest, maillon** queueDest);

//Afficher la liste
void afficherListe(maillon *liste);

void afficherListe2(maillon *liste);

//Et pouf un miracle aparrait
//author : Alex
void writeBit(maillon** Tete, maillon** Queue, unsigned char bit);

//Et pas, un second miracle aparrait
//author : Alex
int readBit(maillon* Tete);

void copieAutre(maillon* src, maillon* dest);

void copieAutre2(maillon* src, maillon* dest);

//Renvoie la queue de la liste
maillon* getQueue(maillon* Tete);
void afficherK(maillon* res);
#endif

