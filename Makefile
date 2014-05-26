######################
# Author : 
#		   
######################


######### Variables #########

#a mettre plus tard pour la forme
#EMPLACEMENT DES SOURCES
#CSRC = src/

#EMPLACEMENT DES INCLUDES
#CINC = include/

# FLAGS POUR GCC: -Idirectory cherche les fichiers des #include< >
CFLAGS = -std=c99 # -Wall -Werror

# NOM DU COMPILATEUR
CC = gcc

# LISTE DES SOURCES
SRCS= 

#LES FICHIERS OBJETS
OBJS = $(SRCS:.c=.o)

######### Regle générique de compilation #########
%.o: %.c %.h 
	gcc -c $< -std=c99


######### Regles de compilation #########

#

main : 
	gcc $^ $(CFLAGS) -o $@

testReader: testReader.c reader.o liste_manager.o
	gcc $(CFLAGS) -o testReader testReader.c reader.o liste_manager.o

All.o :
	gcc -c $< $(CFLAGS)

######### Regles de nettoyage #########
clean :
	@echo "On supprime tout les .o et les executables"
	rm -f *.o main

