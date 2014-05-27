all: test

rle.o: ../RLE.c
	gcc -o rle.o -c ../RLE.c

liste_manager.o: ../../liste_manager.c
	gcc -o liste_manager.o -c ../../liste_manager.c

test: test.o rle.o liste_manager.o
	gcc -o test test.o rle.o liste_manager.o

test.o: test.c
	gcc -o test.o -c test.c

clean:
	rm -rf *.o
	rm -rf test
