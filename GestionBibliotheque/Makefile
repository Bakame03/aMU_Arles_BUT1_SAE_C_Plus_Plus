# Variables globales pour centraliser les paramètres pour éviter les répétitions
CXX = g++
CXXFLAGS = -Wall -Iinclude # -Iinclude c'est pour dire au systeme de chercher les files .hpp dans le folder include
EXEC = build/GestionBiblio
# Liste des fichiers objets à produire
OBJ = build/main.o build/affichage.o build/bibliotheque.o build/export.o build/livre.o build/recherche.o build/utils.o

# But au depart c'est de faire le fichier exécutable
all: $(EXEC)

# les fichiers objets doivent d'abord etre prêts avant de faire le fichier exécutable
$(EXEC): $(OBJ)
	$(CXX) -o $@ $^

# Compilation du main.cpp
build/main.o: main.cpp include/types.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@  
#le -o $@ permet de rediriger le resultat du fichier .o dans le dossier build
#le $< est le fichier qui est a droite du : donc le fichier source a utiliser avec le -c

# pour les autres fichiers dans src/
build/%.o: src/%.cpp include/%.hpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# pour supprimer les fichiers objets et le fichier exécutable(avec la commande 'make clean')
# le -f c'est juste pour forcer la suppression des fichiers(par exemple ca ignore les messages d'erreur si le file n'existe pas)
clean:
	rm -f build/*.o $(EXEC)