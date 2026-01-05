#include "../include/bibliotheque.hpp"
#include "../include/utils.hpp"
#include <fstream>
#include <iostream>
#include <string>

void initialiserParDefaut(Bibliotheque& b) {
    b.parametres.livresParPage = 10;
    b.parametres.logoChoisi = "  ____   ____   ____  _  __ ____ \n | __ ) / __ \\ / __ \\| |/ // ___|\n |  _ \\| |  | | |  | | ' / \\___ \\ \n | |_) | |__| | |__| | . \\  ___) |\n |____/ \\____/ \\____/|_|\\_\\|____/ \n";
    b.titre = "Ma Bibliotheque";
    b.description = "Aucune description.";
}

void afficherLogo(const Bibliotheque& b) {
    std::cout << b.parametres.logoChoisi << std::endl;
    std::cout << "====================================================" << std::endl;
    std::cout << "  " << b.titre << std::endl;
    std::cout << "====================================================" << std::endl << std::endl;
}

void configurerPremierLancement(Bibliotheque& b) {
    std::cout << "[PREMIER LANCEMENT] Configuration de la bibliotheque" << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    
    do{
        std::cout << "Entrez le titre de votre bibliotheque : ";
        std::getline(std::cin, b.titre);
        if (b.titre.empty()) 
            std::cout << "Le titre ne peut pas etre vide. Veuillez reessayer." << std::endl;
    } while (b.titre.empty());

    do{
        std::cout << "\nEntrez une description (laissez une ligne vide pour terminer) :" << std::endl;
        std::string ligne;
        std::string description = "";
        
        while (std::getline(std::cin, ligne) && !ligne.empty()) {
            description += ligne + "\n";
        }
        b.description = description;
        if(b.description.empty()) 
            std::cout << "La description ne peut pas etre vide. Veuillez reessayer." << std::endl;
    }while(b.description.empty());

    system("clear || cls");
    std::cout << std::endl << "Bibliotheque creee avec succes " << std::endl;
}

void sauvegarderDonnees(const Bibliotheque& b) {
    std::ofstream f("data/db.txt");
    if (!f.is_open()) 
        return;

    f << b.titre << "\n";
    f << b.parametres.livresParPage << "\n";
    f << b.description << "[Marque_Fin_Description]\n"; 


    for (const Livre& l : b.listeDeLivres) {
        f << l.isbn << ";" << l.titre << ";" << l.langue << ";";
        
        // Auteurs (séparés par ,)
        for (size_t i = 0; i < l.auteurs.size(); i++) {
            f << l.auteurs[i] << (i == l.auteurs.size() - 1 ? "" : ",");
        }
        f << ";" << l.dateParution.annee << "-" << l.dateParution.mois << "-" << l.dateParution.jour << ";";
        
        // DESCRIPTION (séparée par |)
        for (size_t i = 0; i < l.description.size(); i++) {
            f << l.description[i] << (i == l.description.size() - 1 ? "" : "|");
        }
        
        f << ";" << l.genre << "\n";
    }
    f.close();
}

bool chargerDonnees(Bibliotheque& b) {
    std::ifstream f("data/db.txt");
    if (!f.is_open()) 
        return false;

    std::getline(f, b.titre);
    
    std::string p;
    std::getline(f, p);
    if(!p.empty()) 
        b.parametres.livresParPage = std::stoi(p);
    
    std::string ligne, descriptionInitiale = "";
    while (std::getline(f, ligne) && !contientSousChaine(ligne, "[Marque_Fin_Description]")) {
        descriptionInitiale += ligne + "\n";
    }
    b.description = descriptionInitiale;

    while (std::getline(f, ligne)) {
        std::vector<std::string> cols = split(ligne, ';');
        Livre l;
        l.isbn = cols[0];
        l.titre = cols[1];
        l.langue = cols[2];
        l.auteurs = split(cols[3], ',');
        
        std::vector<std::string> d = split(cols[4], '-');
        l.dateParution.annee = std::stoi(d[0]);
        l.dateParution.mois = std::stoi(d[1]);
        l.dateParution.jour = std::stoi(d[2]);
        
        l.description = split(cols[5], '|');
        l.genre = cols[6];
        b.listeDeLivres.push_back(l);
    }
    
    f.close();
    return true;
}