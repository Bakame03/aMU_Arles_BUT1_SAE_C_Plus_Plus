#include "../include/livre.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <fstream>

void ajouterLivreManuel(Bibliotheque& b) {
    Livre nouveau;
    std::cout << "\n--- AJOUT MANUEL D'UNE REFERENCE ---\n";

    do{
        std::cout << "ISBN-13 : ";
        std::getline(std::cin >> std::ws, nouveau.isbn);
        if (nouveau.isbn.empty()) 
            std::cout << "L'ISBN ne peut pas etre vide. Veuillez reessayer.\n";
    } while (nouveau.isbn.empty());

    do{
        std::cout << "Titre : ";
        std::getline(std::cin, nouveau.titre);
        if (nouveau.titre.empty()) 
            std::cout << "Le titre ne peut pas etre vide. Veuillez reessayer.\n";
    } while (nouveau.titre.empty());

    do{
        std::cout << "Langue : ";
        std::getline(std::cin, nouveau.langue);
        if (nouveau.langue.empty()) 
            std::cout << "La langue ne peut pas etre vide. Veuillez reessayer.\n";
    } while (nouveau.langue.empty());

    do{
        std::cout << "Auteurs (ligne vide pour finir) :\n";
        std::string nomAuteur;
        while (std::getline(std::cin, nomAuteur) && !nomAuteur.empty()) {
            nouveau.auteurs.push_back(nomAuteur);
        }
        if (nouveau.auteurs.empty()) 
            std::cout << "Il doit y avoir au moins un auteur. Veuillez reessayer.\n";
    } while (nouveau.auteurs.empty());

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

    do{
        std::cout << "Description (ligne vide pour finir) :\n";
        std::string ligneDesc;
        std::cin >> std::ws; 
        while (std::getline(std::cin, ligneDesc) && !ligneDesc.empty()) {
            nouveau.description.push_back(ligneDesc);
        }
        if (nouveau.description.empty()) 
            std::cout << "La description ne peut pas etre vide. Veuillez reessayer.\n";
    } while (nouveau.description.empty());

    do{
        std::cout << "Genre : ";
        std::getline(std::cin, nouveau.genre);
        if (nouveau.genre.empty()) 
            std::cout << "Le genre ne peut pas etre vide. Veuillez reessayer.\n";
    } while (nouveau.genre.empty());

    b.listeDeLivres.push_back(nouveau);
    system("clear || cls");
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
        // Gérer les champs entre guillemets qui peuvent contenir des sauts de ligne
        int guillemets = 0;
        for (char c : ligne) 
            if (c == '"') 
                guillemets++;
        while (guillemets % 2 != 0 && std::getline(fichier, blocLigne)) {
            ligne += "\n" + blocLigne;
            for (char c : blocLigne) 
                if (c == '"') 
                    guillemets++;
        }

        std::vector<std::string> cols = split(ligne, ';');
        if (cols.size() < 7) {
            // Ligne malformee, on l'ignore
            continue;
        }

        Livre nouveau;
        nouveau.isbn = cols[0];

        nouveau.titre = cols[1];

        nouveau.langue = cols[2];

        nouveau.auteurs = split(cols[3], ',');
        
        std::vector<std::string> d = split(cols[4], '-');
        if (d.size() >= 3) {
            nouveau.dateParution.annee = std::stoi(d[0]);
            nouveau.dateParution.mois = std::stoi(d[1]);
            nouveau.dateParution.jour = std::stoi(d[2]);
        }
        
        std::string res = cols[5];
        nouveau.description = split(res, '\n'); 

        if (cols.size() > 6) {
            nouveau.genre = cols[6];
        }

        b.listeDeLivres.push_back(nouveau);
        compteur++;
    }

    fichier.close();
    return compteur;
}

void supprimerToutesLesReferences(Bibliotheque& b) {
    b.listeDeLivres.clear();
    std::cout << "[Systeme] Toutes les references ont ete supprimees.\n";
}