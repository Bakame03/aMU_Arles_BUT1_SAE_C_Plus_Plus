#include "include/types.hpp"
#include "include/utils.hpp"
#include "include/bibliotheque.hpp"
#include "include/livre.hpp"
#include "include/affichage.hpp"
#include "include/recherche.hpp"
#include "include/export.hpp"
#include <iostream>

int main() {
    Bibliotheque maBiblio;
    initialiserParDefaut(maBiblio);

    if (!chargerDonnees(maBiblio)) {
        configurerPremierLancement(maBiblio);
    }

    int choix = 0;
    while (choix != 6) {
        afficherLogo(maBiblio);
        std::cout << "Nombre de livres : " << maBiblio.listeDeLivres.size() << "\n\n";
        std::cout << "1. Consulter les references\n";
        std::cout << "2. Gerer les references (Ajout/Import)\n";
        std::cout << "3. Chercher une reference\n";
        std::cout << "4. Exporter en HTML\n";
        std::cout << "5. Parametres\n";
        std::cout << "6. Quitter\n";
        std::cout << "\nChoix : ";
        std::cin >> choix;

        if (choix == 1) {
            system("clear || cls");
            afficherListePagination(maBiblio);
        } 
        else if (choix == 2) {
            system("clear || cls");
            int c;
            do{
                std::cout << "1. Ajouter manuellement\n2. Importer lot CSV\n3. Retourner au menu principal Choix: ";
                std::cin >> c;
                if (c != 1 && c != 2 && c != 3) {
                    system("clear || cls");
                    std::cout << "Choix invalide. Veuillez reessayer.\n";
                }
            }while(c != 1 && c != 2 && c != 3);
            if (c == 1) {
                system("clear || cls");
                ajouterLivreManuel(maBiblio);
            }
            else if (c == 2){
                system("clear || cls");
                std::string path;
                std::cout << "Chemin du fichier (ex: ./import/livres-lot-1.csv) : ";
                std::cin >> path;
                int n = importerCSV(maBiblio, path);
                std::cout << n << " livres importes !\n";
            }
            else if (c == 3) {
                system("clear || cls");
            }
        }
        else if (choix == 3) {
            system("clear || cls");
            int c;
            do{
                std::cout << "1. Par ISBN\n2. Par Titre\n3. Retourner au menu principal Choix: ";
                std::cin >> c;
                if (c != 1 && c != 2 && c != 3) {
                    system("clear || cls");
                    std::cout << "Choix invalide. Veuillez reessayer.\n";
                }
            }while(c != 1 && c != 2 && c != 3);
            if (c == 1) 
                chercherParIsbn(maBiblio);
            else if (c == 2)
                chercherParTitre(maBiblio);
            else if (c == 3) 
                system("clear || cls");
        }
        else if (choix == 4) {
            system("clear || cls");
            exporterEnHTML(maBiblio, "export/index.html");
        }
        else if (choix == 5) {
            system("clear || cls");
            std::cout << "Livres par page actuel (" << maBiblio.parametres.livresParPage << ") : ";
            std::cin >> maBiblio.parametres.livresParPage;
        }
        else if (choix == 6) {
            system("clear || cls");
            char save;
            std::cout << "Sauvegarder avant de quitter ? (o/n) : ";
            std::cin >> save;
            if (save == 'o' || save == 'O') {
                sauvegarderDonnees(maBiblio);
            }
            std::cout << "Au revoir !" << std::endl;
        }
        else {
            system("clear || cls");
            std::cout << "Choix invalide. Veuillez reessayer.\n";
        }
    }

    return 0;
}