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
    std::string isbn;          // unique pour chaque livre
    std::string titre;         
    std::string langue;        
    std::vector<std::string> auteurs;   
    Date dateParution;         
    std::string genre;         
    std::string description;   
};

// Structure des paramètres de la bibliothèque
struct Parametres {
    int livresParPage;         
    std::string logoChoisi;    
};

// la structure de la bibliothèque
struct Bibliotheque {
    std::string titre;          
    std::string description;    
    std::vector<Livre> listeDeLivres;   
    Parametres parametres;      
};

#endif