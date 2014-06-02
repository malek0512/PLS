all: test

rle.o: ../../src/RLE.c
	gcc -std=c99 -g -o rle.o -c ../../src/RLE.c -std=c99

huffman.o: ../../src/huffman.c
	gcc -g -o huffman.o -c ../../src/huffman.c -std=c99

reader.o: ../../src/reader.c
	gcc -g -o reader.o -c ../../src/reader.c -std=c99

liste_manager.o: ../../src/liste_manager.c
	gcc -g -o liste_manager.o -c ../../src/liste_manager.c -std=c99

test: huffman.o rle.o liste_manager.o reader.o test.o
	gcc -g -o test test.o huffman.o rle.o reader.o liste_manager.o -std=c99

test.o: test.c
	gcc -g -o test.o -c test.c -std=c99

clean:
## On supprime les .o, l'exécutable ainsi que tous les fichiers générés pendant les tests
	rm -rf *.o test files/*S* files/*D*
