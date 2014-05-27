main : main.c MTF.o liste_manager.o
	gcc -o $@ $^

MTF.o : MTF.c MTF.h
	gcc -c $<

liste_manager.o : ../liste_manager.c ../liste_manager.h
	gcc -c $<
