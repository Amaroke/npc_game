CC = gcc #Le compilateur utilisé
CFLAGS = -W -Wall -ansi -std=c99 #Les options de compilation
LDFLAGS = #Les options de l'édition de lien
EXEC = main #Les éxecutables à générer
SRC = addition.c main.c #Liste des fichiers sources du projet
DEPS = addition.h #Liste des fichiers d'en tête
OBJ = $(SRC:.c=.o) #Liste des fichiers

all: $(EXEC)
main: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -rf *.o *~
mrproper: clean
	rm -rf $(EXEC)