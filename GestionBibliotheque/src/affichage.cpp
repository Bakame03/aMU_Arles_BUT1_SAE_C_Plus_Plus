#include "../include/affichage.hpp"
#include <iostream>
#include <vector>

void afficherFicheLivre(const Livre& l) {
    std::cout << "\n------------------------------------------\n";
    std::cout << "TITRE : " << l.titre << "\n";
    std::cout << "ISBN  : " << l.isbn << "\n";
    std::cout << "AUTEURS : ";
    for (size_t i = 0; i < l.auteurs.size(); i++) {
        std::cout << l.auteurs[i];
        if (i != l.auteurs.size() - 1) 
            std::cout << ", ";
    }
    std::cout << "\nLANGUE : " << l.langue << "\n";
    std::cout << "GENRE  : " << l.genre << "\n";
    std::cout << "DATE   : " << l.dateParution.jour << "/" << l.dateParution.mois << "/" << l.dateParution.annee << "\n";
    std::cout << "RESUME : \n";
    for (const std::string& ligne : l.description) {
        std::cout << "  " << ligne << "\n"; 
    }
    std::cout << "------------------------------------------\n";
}

void afficherListePagination(const Bibliotheque& b) {
    if (b.listeDeLivres.empty()) {
        std::cout << "La bibliotheque est vide.\n";
        return;
    }

    int total = b.listeDeLivres.size();
    int parPage = b.parametres.livresParPage;
    int pageActuelle = 0;
    bool continuer = true;

    while (continuer) {
        std::cout << "\n--- LISTE DES LIVRES (Page " << pageActuelle + 1 << ") ---\n";
        
        // Calcul des bornes de la page
        int debut = pageActuelle * parPage;
        int fin = debut + parPage;
        if (fin > total) 
            fin = total;

        for (int i = debut; i < fin; i++) {
            std::cout << "[" << i + 1 << "] " << b.listeDeLivres[i].titre << " (" << b.listeDeLivres[i].isbn << ")\n";
        }

        std::cout << "\n[N] Suivant | [P] Precedent | [V] Voir detail | [Q] Retour menu\n Choix : ";
        char choix;
        std::cin >> choix;

        if ((choix == 'N' || choix == 'n') && fin < total) {
            pageActuelle++;
            system("clear || cls");
        }
        else if ((choix == 'P' || choix == 'p') && pageActuelle > 0) {
            pageActuelle--;
            system("clear || cls");
        }
        else if (choix == 'Q' || choix == 'q') {
            continuer = false;
            system("clear || cls");
        }
        else if (choix == 'V' || choix == 'v') {
            int index;
            std::cout << "Entrez l'index du livre : ";
            std::cin >> index;
            if (index > 0 && index <= total) {
                system("clear || cls");
                afficherFicheLivre(b.listeDeLivres[index-1]);
            }
        }
        else {
            system("clear || cls");
            std::cout << "Choix invalide. Veuillez reessayer.\n";
        }
    }
}