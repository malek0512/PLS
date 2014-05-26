
//Liste chainee

typedef struct maillon {
    int lettre;
    unsigned int frequence;
    struct maillon* suivant;
}maillon;

//Ajoute en Tete une lettre et sa frequence
maillon* ajoutEnTete(maillon* Tete, int lettre, int frequence);

//Aloue une cellule de type maillon, avec les paramètres lettre et (frequence ou Prob)
maillon* Allouer(int lettre, int autre);
