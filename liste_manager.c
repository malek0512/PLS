
maillon* ajoutEnTete(maillon* Tete, int lettre, int frequence){
//    maillon* Tetebis = Allouer(lettre, frequence);
//    Tetebis->suivant = Tetebis;
//    return Tetebis;
}


maillon* Allouer(int lettre, int autre){
    maillon* cellule = malloc(sizeof(maillon));
    cellule->lettre = lettre;
    cellule->autre = autre;
    return cellule;
}
