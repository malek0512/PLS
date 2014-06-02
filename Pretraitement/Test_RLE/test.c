#include <stdio.h>
#include <stdlib.h>
#include "../RLE.h"
#include "../../liste_manager.h"
#include "../../reader.h"

int main(void){

	maillon* l;
	maillon* ft;
	maillon* fq;

	l = initialiser(l);
	ft = initialiser(ft);
	fq = initialiser(fq);

	l = ajouterEnQueue(l, 'a', 1);
	l = ajouterEnQueue(l, 'a', 1);
	l = ajouterEnQueue(l, 'c', 1);
	l = ajouterEnQueue(l, 'm', 1);
	l = ajouterEnQueue(l, 'm', 1);
	l = ajouterEnQueue(l, 'm', 1);
	l = ajouterEnQueue(l, 'm', 1);
	l = ajouterEnQueue(l, 'm', 1);
	l = ajouterEnQueue(l, 'm', 1);
	l = ajouterEnQueue(l, 'o', 1);
	l = ajouterEnQueue(l, 'o', 1);
	l = ajouterEnQueue(l, 'o', 1);

	printf("Affichage de la liste initiale\n");
	print(l);

	printf("\nTest n°1 : Application de l'algorithme RLE sur la liste\n");
	coderRle(l);
	print(l);
	printf("Fin du test\n");

	printf("\nTest n°2 : Décodage de la nouvelle liste\n");
	decoderRle(l);
	print(l);
	printf("Fin du test\n");

	printf("\nTest n°3 : Code d'un fichier texte\n");
	char texte[]="files/texte.txt";
	char texteS[]="files/texteS.txt";
	char texteD[]="files/texteD.txt";
	FILE* texteF = OuvrirFichier(texte);
	FILE* texteFS = CreerFichier(texteS);
	FILE* texteFD = CreerFichier(texteD);
	readFromFileBytesInOrder(&ft, &fq, texteF);
	coderRle(ft);
	writeListeBytes(ft, texteFS);
	decoderRle(ft);
	writeListeBytes(ft, texteFD);
	printf("Fin du test\n");

	printf("\nTest n°4 : Code d'un exécutable\n");
	char exec[]="files/exec";
	char execS[]="files/execS";
	char execD[]="files/execD";
	FILE* execF = OuvrirFichier(exec);
	FILE* execFS = CreerFichier(execS);
	FILE* execFD = CreerFichier(execD);
	readFromFileBytesInOrder(&ft, &fq, execF);
	coderRle(ft);
	writeListeBytes(ft, execFS);
	decoderRle(ft);
	writeListeBytes(ft, execFD);
	printf("Fin du test\n");

	printf("\nTest n°5 : Code d'une image gif\n");
	char image[]="files/edit.gif";
	char imageS[]="files/editS.gif";
	char imageD[]="files/editD.gif";
	FILE* imageF = OuvrirFichier(image);
	FILE* imageFS = CreerFichier(imageS);
	FILE* imageFD = CreerFichier(imageD);
	readFromFileBytesInOrder(&ft, &fq, imageF);
	coderRle(ft);
	writeListeBytes(ft, imageFS);
	decoderRle(ft);
	writeListeBytes(ft, imageFD);
	printf("Fin du test\n");

	printf("\nTest n°5bis : Code d'une image png\n");
	char png[]="files/pikachu.png";
	char pngS[]="files/pikachuS.png";
	char pngD[]="files/pikachuD.png";
	FILE* pngF = OuvrirFichier(png);
	FILE* pngFS = CreerFichier(pngS);
	FILE* pngFD = CreerFichier(pngD);
	readFromFileBytesInOrder(&ft, &fq, pngF);
	coderRle(ft);
	writeListeBytes(ft, pngFS);
	decoderRle(ft);
	writeListeBytes(ft, pngFD);
	printf("Fin du test\n");

	printf("\nTest n°6 : Code d'une page HTML\n");
	char html[] = "files/commits.html";
	char htmlS[] = "files/commitsS.txt";
	char htmlD[] = "files/commitsD.txt";
	FILE* htmlF = OuvrirFichier(html);
	FILE* htmlFS = CreerFichier(htmlS);
	FILE* htmlFD = CreerFichier(htmlD);
	readFromFileBytesInOrder(&ft, &fq, htmlF);
	coderRle(ft);
	writeListeBytes(ft, htmlFS);
	decoderRle(ft);
	writeListeBytes(ft, htmlFD);
	printf("Fin du test\n");

	liberer(l);
	liberer(ft);
	liberer(fq);

	return 0;

}
