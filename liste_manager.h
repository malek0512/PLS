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


