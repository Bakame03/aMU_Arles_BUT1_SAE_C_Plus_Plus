#ifndef LIVRE_HPP
#define LIVRE_HPP
#include "types.hpp"
#include <string>

void ajouterLivreManuel(Bibliotheque& b);
int importerCSV(Bibliotheque& b, std::string chemin);
void supprimerToutesLesReferences(Bibliotheque& b);

#endif