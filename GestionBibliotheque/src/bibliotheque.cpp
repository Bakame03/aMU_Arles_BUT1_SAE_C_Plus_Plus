#include "../include/bibliotheque.hpp"
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
    
    std::cout << "Entrez le titre de votre bibliotheque : ";
    std::getline(std::cin, b.titre);

    std::cout << "Entrez une description (laissez une ligne vide pour terminer) :" << std::endl;
    std::string ligne;
    std::string description = "";
    
    while (std::getline(std::cin, ligne) && !ligne.empty()) {
        description += ligne + "\n";
    }
    b.description = description;

    std::cout << std::endl << "Bibliotheque creee avec succes " << std::endl;
}