######### Variables #########
EXECUTABLES = codage decodage testReader
#a mettre plus tard pour la forme
#EMPLACEMENT DES SOURCES
#CSRC = src/

#EMPLACEMENT DES INCLUDES
#CINC = include/

# FLAGS POUR GCC: -Idirectory cherche les fichiers des #include< >
CFLAGS = -std=c99 -Wall -Werror -O3

# NOM DU COMPILATEUR
CC = gcc

# LISTE DES SOURCES
SRCS= 

#LES FICHIERS OBJETS
OBJS = $(SRCS:.c=.o)

######### Regle générique de compilation #########
%.o: %.c %.h 
	gcc -c $< $(CFLAGS)

######### Regles de compilation #########
all: codage decodage

codage : codage.c reader.o RLE.o MTF.o huffman.o liste_manager.o
	gcc $^ $(CFLAGS) -o $@

decodage : decodage.c reader.o RLE.o MTF.o huffman.o liste_manager.o
	gcc $^ $(CFLAGS) -o $@

huffman.o : Huffman/huffman.c Huffman/huffman.h liste_manager.o 
	gcc -c $< $(CFLAGS)  

RLE.o : Pretraitement/RLE.c Pretraitement/RLE.h liste_manager.o
	gcc -c $< $(CFLAGS) 

MTF.o : Pretraitement/MTF.c Pretraitement/MTF.h liste_manager.o
	gcc -c $< -std=c99 

testReader: testReader.c reader.o liste_manager.o
	gcc  -o testReader testReader.c reader.o liste_manager.o

######### Regles de nettoyage #########
clean :
	@echo "On supprime tout les .o et les executables"
	rm -f *.o $(EXECUTABLES)
	rm -f Test/*.comp Test/*.Decompresse
	

