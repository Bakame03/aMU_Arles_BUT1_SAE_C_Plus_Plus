#ifndef TYPES_HPP
#define TYPES_HPP
#include <string>
#include <vector>

// la structure des dates
struct Date {
    int jour;
    int mois;
    int annee;
};

// la structure des livres
struct Livre {
    std::string isbn;          // ISBN-13 unique
    std::string titre;         // Titre de l'ouvrage
    std::string langue;        // Langue (ex: Français, Anglais)
    std::vector<std::string> auteurs; // Liste des auteurs (plusieurs possibles)
    Date dateParution;         // Date via notre structure personnalisée
    std::string genre;         // Catégorie ou genre littéraire
    std::string description;   // Résumé ou descriptif complet
};

// la structure de la bibliothèque
struct Bibliotheque {
    std::string nom;           // Nom de l'établissement
    std::string description;   // Philosophie ou bio de la médiathèque
    std::vector<Livre> stock;  // Notre "base de données" en mémoire vive
    int livresParPage;         // Paramètre de pagination (défaut 10)
    std::string logoAscii;     // Le logo choisi par l'utilisateur
};

#endif