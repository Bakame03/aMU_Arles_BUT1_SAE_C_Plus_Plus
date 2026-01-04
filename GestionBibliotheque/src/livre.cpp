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
    std::cin >> std::ws; 
    while (std::getline(std::cin, ligneDesc) && !ligneDesc.empty()) {
        nouveau.description.push_back(ligneDesc);
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

    std::string ligne, blocLigne;
    int compteur = 0;

    // pour sauter la premiere ligne qui a des noms de colonnes
    std::getline(fichier, ligne);

    // on lit le fichier ligne par ligne
    while (std::getline(fichier, ligne)) {
        // Si la ligne a un nombre impair de guillemets, c'est qu'un champ (résumé) est ouvert
        // On continue de lire jusqu'à trouver le guillemet de fermeture
        int guillemets = 0;
        for(char c : ligne) 
            if(c == '"') 
                guillemets++;
        
        while (guillemets % 2 != 0 && std::getline(fichier, blocLigne)) {
            ligne += " " + blocLigne; // On recolle les morceaux
            for(char c : blocLigne) 
                if(c == '"') 
                    guillemets++;
        }

        std::vector<std::string> cols = split(ligne, ';');
        if (cols.size() < 7) continue;

        Livre nouveau;
        nouveau.isbn = cols[0];
        nouveau.titre = cols[1];
        nouveau.auteurs = split(cols[3], ',');
        
        // Pour le résumé, on enlève les guillemets s'ils existent
        std::string res = cols[5];
        if (!res.empty() && res[0] == '"') res.erase(0, 1);
        if (!res.empty() && res[res.length()-1] == '"') res.erase(res.length()-1, 1);
        
        // Et on utilise SPLIT pour transformer le texte en liste de lignes (par exemple sur les points)
        nouveau.description = split(res, '\n'); 

        b.listeDeLivres.push_back(nouveau);
        compteur++;
    }

    fichier.close();
    return compteur;
}