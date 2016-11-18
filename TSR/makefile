# Définition des cibles particulières
.PHONY: clean, mrproper ,val

# Désactivation des règles implicites
.SUFFIXES:

# Variables
CC = gcc 										
PROJECT = analyseur
TYPE = .out 
BIN = $(PROJECT)$(TYPE)							
DOUT = 											
OBJS = main.o ethernet.o affichage.o ip.c udp.c tcp.c arp.c
SRC =											
DEPS = include/*.h
CFLAGS = -W -Wall -lpcap								

# Création de l'executable Out
all: $(OBJS)
	$(CC) $^ -o $(BIN) $(CFLAGS) 

#Création des fichiers objets avec les fichiers c renseignés
%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

# Suppression des fichiers temporaires
clean:
	rm -rf $(OBJS)

mrproper: clean
	rm $(BIN)

valgrind:
	 valgrind --leak-check=yes ./$(PROJECT)$(TYPE)