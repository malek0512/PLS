main : main.c huffman.o liste_manager.o reader.o
	gcc -o $@ $^ -Wall -Werror

huffman.o : huffman.c huffman.h liste_manager.o 
	gcc -c $< -Wall -Werror

reader.o : ../reader.c ../reader.h liste_manager.o 
	gcc -c $< -Wall -Werror -std=c99

liste_manager.o : ../liste_manager.c ../liste_manager.h
	gcc -c $< -Wall -Werror

testhaha : testhaha.c
	gcc -o $@ $< -Wall -Werror

clean :
	rm -f *.o main
