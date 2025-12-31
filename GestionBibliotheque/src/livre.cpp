#include "../include/livre.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <fstream>

void ajouterLivreManuel(Bibliotheque& b) {
    Livre nouveau;
    std::cout << "\n--- AJOUT MANUEL D'UNE REFERENCE ---\n";

    std::cout << "ISBN-13 : ";
    std::getline(std::cin >> std::ws, nouveau.isbn);

    std::cout << "Titre : ";
    std::getline(std::cin, nouveau.titre);

    std::cout << "Langue : ";
    std::getline(std::cin, nouveau.langue);

    std::cout << "Auteurs (ligne vide pour finir) :\n";
    std::string nomAuteur;
    while (std::getline(std::cin, nomAuteur) && !nomAuteur.empty()) {
        nouveau.auteurs.push_back(nomAuteur);
    }

    bool dateOk = false;
    while (!dateOk) {
        std::cout << "Date de parution (JJ MM AAAA) : ";
        std::cin >> nouveau.dateParution.jour >> nouveau.dateParution.mois >> nouveau.dateParution.annee;
        
        if (estDateValide(nouveau.dateParution)) {
            dateOk = true;
        } else {
            std::cout << "ERREUR : La date n'existe pas. Reessayez.\n";
        }
    }

    std::cout << "Description (ligne vide pour finir) :\n";
    std::string ligneDesc;
    nouveau.description = "";
    std::cin >> std::ws; 
    while (std::getline(std::cin, ligneDesc) && !ligneDesc.empty()) {
        nouveau.description += ligneDesc + "\n";
    }

    std::cout << "Genre : ";
    std::getline(std::cin, nouveau.genre);

    b.listeDeLivres.push_back(nouveau);
    std::cout << "\n[Systeme] Livre ajoute avec succes !\n";
}

int importerCSV(Bibliotheque& b, std::string chemin) {
    std::ifstream fichier(chemin);
    if (!fichier.is_open()) {
        std::cerr << "ERREUR : Impossible d'ouvrir le fichier " << chemin << std::endl;
        return 0;
    }

    std::string ligne;
    int compteur = 0;

    // pour sauter la premiere ligne qui a des noms de colonnes
    std::getline(fichier, ligne);

    // on lit le fichier ligne par ligne
    while (std::getline(fichier, ligne)) {
        std::vector<std::string> cols = split(ligne, ';');

        Livre nouveau;
        nouveau.isbn = cols[0];
        nouveau.titre = cols[1];
        nouveau.langue = cols[2];

        nouveau.auteurs = split(cols[3], ',');

        std::vector<std::string> dateMots = split(cols[4], '-');
        nouveau.dateParution.annee = std::stoi(dateMots[0]);
        nouveau.dateParution.mois  = std::stoi(dateMots[1]);
        nouveau.dateParution.jour  = std::stoi(dateMots[2]);
        
        nouveau.description = cols[5];
        nouveau.genre = cols[6];

        b.listeDeLivres.push_back(nouveau);
        compteur++;
    }

    fichier.close();
    return compteur;
}