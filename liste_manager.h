
//Liste chainee

typedef struct maillon {
    int lettre;
    unsigned int frequence;
    struct maillon* suivant;
}maillon;

//Ajoute en Tete une lettre et sa frequence
maillon* ajoutEnTete(maillon* Tete, int lettre, int frequence);

