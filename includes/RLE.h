#ifndef DEF_RLE
#define DEF_RLE
#include <stdlib.h>
#include <stdio.h>
#include "liste_manager.h"
#include "reader.h"
#include "huffman.h"

// On traite la liste tete en suivant l'algorithme RLE
// Auteur : Marie
void coderRle(maillon* tete);

// Permet de décoder une liste à laquelle on a appliqué l'algorithme RLE
// Auteur : Marie
void decoderRle(maillon* tete);

#endif
