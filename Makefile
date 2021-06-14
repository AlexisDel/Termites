# Fichier makefile pour projet termite
######################################
##
# Tout ce qui est après un # sur une ligne est en commentaire.
##

# Quelques variables de configuration du compilateur
####################################################
# Le compilateur à utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -g

# Les programmes principaux
###########################
# On donne le fichier .cpp et la liste des fichiers .o qu'ils utilisent

main: main.cpp DEFINITIONS.hpp coord.o grille.o termite.o
testgrille: testgrille.cpp DEFINITIONS.hpp grille.o coord.o

#TEST
#testgrille: testgrille.cpp grille.o coord.o
#testcoord: testcoord.cpp coord.o


# Les différents composants
###########################
# on donne le fichier .cpp ainsi que la liste
# des fichiers .hpp dont ils dépendent

grille.o: grille.cpp grille.hpp DEFINITIONS.hpp
coord.o: coord.cpp coord.hpp DEFINITIONS.hpp
termite.o: termite.cpp termite.hpp DEFINITIONS.hpp


# Pour faire le ménage
clean:
	rm -f testcoord *.o
	rm -f testgrille *.o
	rm -f main *.o
# Attention dans la ligne ci-dessus il faut écrire
# un seul caractère de tabulation et pas 8 espaces.
