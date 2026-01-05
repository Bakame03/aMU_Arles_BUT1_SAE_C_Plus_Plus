#include "../include/recherche.hpp"
#include "../include/affichage.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <string>

void chercherParIsbn(const Bibliotheque& b) {
    std::string saisie;
    std::cout << "Entrez l'ISBN-13 a rechercher : ";
    std::cin >> saisie;

    bool trouve = false;
    for (const Livre& l : b.listeDeLivres) {
        if (l.isbn == saisie) {
            system("clear || cls");
            afficherFicheLivre(l);
            trouve = true;
            break; // on arrete la boucle, pas besoin de continuer si on a trouve le livre
        }
    }

    if (!trouve) {
        system("clear || cls");
        std::cout << "Aucun livre trouve avec l'ISBN : " << saisie << std::endl;
    }
}

void chercherParTitre(const Bibliotheque& b) {
    std::string motCle;
    std::cout << "Entrez un mot-cle pour le titre : ";
    std::cin >> std::ws; // Nettoyage au cas ou il y a des espaces
    std::getline(std::cin, motCle);

    std::cout << "\n--- Resultats de recherche ---\n";
    int compteur = 0;
    
    for (size_t i = 0; i < b.listeDeLivres.size(); i++) {
        if (contientSousChaine(b.listeDeLivres[i].titre, motCle)) {
            std::cout << "[" << i + 1 << "] " << b.listeDeLivres[i].titre << std::endl;
            compteur++;
        }
    }

    if (compteur == 0) {
        std::cout << "Aucun titre ne contient : " << motCle << std::endl;
    } else {
        std::cout << "\nTotal : " << compteur << " resultats trouves." << std::endl;
    }
}