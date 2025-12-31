#ifndef UTILS_HPP
#define UTILS_HPP
#include "types.hpp"
#include <vector>
#include <string>

bool estDateValide(Date d);
std::vector<std::string> split(const std::string& s, char delimiteur);
bool contientSousChaine(std::string texte, std::string mot);

#endif