all: test

rle.o: ../RLE.c
	gcc -std=c99 -g -o rle.o -c ../RLE.c -std=c99

huffman.o: ../../Huffman/huffman.c
	gcc -g -o huffman.o -c ../../Huffman/huffman.c -std=c99

reader.o: ../../reader.c
	gcc -g -o reader.o -c ../../reader.c -std=c99

liste_manager.o: ../../liste_manager.c
	gcc -g -o liste_manager.o -c ../../liste_manager.c -std=c99

test: huffman.o rle.o liste_manager.o reader.o test.o
	gcc -g -o test test.o huffman.o rle.o reader.o liste_manager.o -std=c99

test.o: test.c
	gcc -g -o test.o -c test.c -std=c99

clean:
## On supprime les .o, l'exécutable ainsi que tous les fichiers générés pendant les tests
	rm -rf *.o test files/*S* files/*D*
