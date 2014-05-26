typedef struct cellule
{
	int value;
}cellule;

//abre binaire
typedef struct arbre
{
	struct arbre *G;
	struct arbre *D;
	cellule i;
}arbre;

//liste chainée

typedef struct liste
{
	struct liste *Suite;
	cellule i;
}liste;
