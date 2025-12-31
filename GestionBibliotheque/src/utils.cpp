#include "../include/utils.hpp"

bool estDateValide(Date d) {
    if (d.annee < 0 || d.mois < 1 || d.mois > 12) {
        return false;
    }
    int joursMax = 31;

    if (d.mois == 4 || d.mois == 6 || d.mois == 9 || d.mois == 11) {
        joursMax = 30;
    } 
    else if (d.mois == 2) {
        bool estBissextile = (d.annee % 4 == 0 && d.annee % 100 != 0) || (d.annee % 400 == 0);
        
        if (estBissextile) {
            joursMax = 29;
        } else {
            joursMax = 28;
        }
    }

    if (d.jour < 1 || d.jour > joursMax) {
        return false;
    }

    return true;
}

std::vector<std::string> split(const std::string& s, char delimiteur) {
    std::vector<std::string> morceaux;
    std::string morceauActuel = "";

    for (char c : s) {
        if (c == delimiteur) {
            morceaux.push_back(morceauActuel);
            morceauActuel = "";
        } else {
            morceauActuel += c;
        }
    }
    
    morceaux.push_back(morceauActuel);

    return morceaux;
}

bool contientSousChaine(std::string texte, std::string mot) {
    if (mot.length() > texte.length()) 
        return false;
    if (mot.length() == 0)  //dans le cas ou le user entre un mot vide
        return true;

    for (size_t i = 0; i <= texte.length() - mot.length(); i++) {
        bool match = true;
        
        for (size_t j = 0; j < mot.length(); j++) {
            if (texte[i + j] != mot[j]) {
                match = false;
                break; 
            }
        }
        
        if (match) 
            return true; 
    }
    return false;
}