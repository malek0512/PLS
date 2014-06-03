######### Variables #########
EXECUTABLES = codage decodage
#a mettre plus tard pour la forme
#EMPLACEMENT DES SOURCES
CSRC = src/

#EMPLACEMENT DES INCLUDES
CINC = includes/

# FLAGS POUR GCC: -Idirectory cherche les fichiers des #include< >
CFLAGS = -Idirectory -std=c99 -Wall -Werror -O3 -g

# NOM DU COMPILATEUR
CC = gcc

# LISTE DES SOURCES
SRCS= reader.c huffman.c MTF.c RLE.c liste_manager.c

#LES FICHIERS OBJETS
OBJS = $(SRCS:.c=.o)

######### Regle générique de compilation #########
%.o: src/%.c #src/%.h 
	$(CC) -c $< $(CFLAGS)

######### Regles de compilation #########
all: codage decodage
	mv *.o objs/

codage : src/codage.c $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

decodage : src/decodage.c $(OBJS) 
	$(CC) $^ $(CFLAGS) -o $@

######### Regles de nettoyage #########
clean :
	@echo "On supprime tout les .o et les executables"
	rm -fr objs/* $(EXECUTABLES)
	rm -f Tests/*.comp Tests/*.decomp
	rm -f *.comp *.decomp
	

