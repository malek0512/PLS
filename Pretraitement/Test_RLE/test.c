#include <stdio.h>
#include <stdlib.h>
#include "../../includes/RLE.h"
#include "../../includes/liste_manager.h"
#include "../../includes/reader.h"

int main(void){

	maillon* ft;
	maillon* fq;

	ft = initialiser(ft);
	fq = initialiser(fq);

	ajouterEnQueue(&ft, &fq, 'a', 1);
	ajouterEnQueue(&ft, &fq, 'a', 1);
	ajouterEnQueue(&ft, &fq, 'c', 1);
	ajouterEnQueue(&ft, &fq, 'm', 1);
	ajouterEnQueue(&ft, &fq, 'm', 1);
	ajouterEnQueue(&ft, &fq, 'm', 1);
	ajouterEnQueue(&ft, &fq, 'm', 1);
	ajouterEnQueue(&ft, &fq, 'm', 1);
	ajouterEnQueue(&ft, &fq, 'm', 1);
	ajouterEnQueue(&ft, &fq, 'o', 1);
	ajouterEnQueue(&ft, &fq, 'o', 1);
	ajouterEnQueue(&ft, &fq, 'o', 1);

	printf("Affichage de la liste initiale\n");
	print(ft);

	printf("\nTest n°1 : Application de l'algorithme RLE sur la liste\n");
	coderRle(ft);
	print(ft);
	printf("Fin du test\n");

	printf("\nTest n°2 : Décodage de la nouvelle liste\n");
	decoderRle(ft);
	print(ft);
	printf("Fin du test\n");

	printf("\nTest n°3 : Code d'un fichier texte\n");
	char texte[]="files/texte.txt";
	char texteS[]="files/texteS.comp";
	char texteD[]="files/texteD.decomp";
	FILE* texteF = OuvrirFichier(texte);
	FILE* texteFS = CreerFichier(texteS);
	FILE* texteFD = CreerFichier(texteD);
	readFromFileBytesInOrder(&ft, &fq, texteF);
	fclose(texteF);
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
	fclose(execF);
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
	fclose(imageF);
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
	fclose(pngF);
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
	fclose(htmlF);
	coderRle(ft);
	writeListeBytes(ft, htmlFS);
	decoderRle(ft);
	writeListeBytes(ft, htmlFD);
	printf("Fin du test\n");

	printf("\nTest n°7 : Code d'un son (MP3)\n");
	char sound[] = "files/sound.mp3";
	char soundS[] = "files/soundS.mp3";
	char soundD[] = "files/soundD.mp3";
	FILE* soundF = OuvrirFichier(sound);
	FILE* soundFS = CreerFichier(soundS);
	FILE* soundFD = CreerFichier(soundD);
	readFromFileBytesInOrder(&ft, &fq, soundF);
	fclose(soundF);
	coderRle(ft);
	writeListeBytes(ft, soundFS);
	decoderRle(ft);
	writeListeBytes(ft, soundFD);
	printf("Fin du test\n");

	return 0;

}
