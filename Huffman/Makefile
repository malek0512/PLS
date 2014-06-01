CFLAGS = -Wall -Werror -std=c99 #-DDEBUG

main : main.c huffman.o liste_manager.o reader.o
	gcc -o $@ $^ $(CFLAGS)

huffman.o : huffman.c huffman.h liste_manager.o 
	gcc -c $< $(CFLAGS)

reader.o : ../reader.c ../reader.h liste_manager.o 
	gcc -c $< -Wall -Werror -std=c99

liste_manager.o : ../liste_manager.c ../liste_manager.h
	gcc -c $< $(CFLAGS)

testhaha : testhaha.c
	gcc -o $@ $< $(CFLAGS)

clean :
	rm -f *.o main
