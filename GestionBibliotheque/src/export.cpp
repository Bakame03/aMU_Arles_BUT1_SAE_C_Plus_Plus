#include "../include/export.hpp"
#include <fstream>
#include <iostream>

void exporterEnHTML(const Bibliotheque& b, std::string cheminFichier) {
    std::ofstream fichier(cheminFichier);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible de créer le fichier d'export." << std::endl;
        return;
    }

    fichier << "<!DOCTYPE html>\n<html lang='fr'>\n<head>\n";
    fichier << "<meta charset='UTF-8'>\n";
    fichier << "<title>Catalogue : " << b.titre << "</title>\n";
    fichier << "<style>body{font-family:sans-serif; margin:40px;} table{width:100%; border-collapse:collapse;} th,td{border:1px solid #ddd; padding:8px; text-align:left;} th{background-color:#f2f2f2;}</style>\n";
    fichier << "</head>\n<body>\n";

    fichier << "<h1>Catalogue de la bibliotheque : " << b.titre << "</h1>\n";
    fichier << "<p>" << b.description << "</p>\n";

    fichier << "<table>\n";
    fichier << "<tr><th>ISBN-13</th><th>Titre</th><th>Auteurs</th><th>Langue</th><th>Date</th><th>Genre</th><th>Résumé</th></tr>\n";

    for (const Livre& l : b.listeDeLivres) {
        fichier << "<tr>\n";
        fichier << "  <td>" << l.isbn << "</td>\n";
        fichier << "  <td>" << l.titre << "</td>\n";
        
        fichier << "  <td>";
        for (size_t i = 0; i < l.auteurs.size(); i++) {
            fichier << l.auteurs[i] << (i == l.auteurs.size() - 1 ? "" : ", ");
        }
        fichier << "</td>\n";

        fichier << "  <td>" << l.langue << "</td>\n";
        fichier << "  <td>" << l.dateParution.jour << "/" << l.dateParution.mois << "/" << l.dateParution.annee << "</td>\n";

        fichier << "  <td>";
        for (size_t i = 0; i < l.description.size(); ++i) {
            fichier << l.description[i] << (i + 1 == l.description.size() ? "" : "<br>");
        }
        fichier << "</td>\n";

        fichier << "  <td>" << l.genre << "</td>\n";
        fichier << "</tr>\n";
    }

    fichier << "</table>\n";
    fichier << "</body>\n</html>";

    fichier.close();
    std::cout << "[Succès] Le catalogue a été exporté dans : " << cheminFichier << std::endl;
}