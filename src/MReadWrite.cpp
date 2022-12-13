#include <fstream>
#include "MReadWrite.h"
#include "Graphe.h"
#include "iostream"
#include <sstream>

unsigned int intLenght(int n) {

    unsigned int number_of_digits = 0;

    do {
        ++number_of_digits;
        n /= 10;
    } while (n != 0);

    return number_of_digits;
}

int extractInt(std::string str) {

    int i = 0;

    std::string temp;

    while (str[i] != ')') {
        temp = temp + str[i];
        ++i;
    }
    return stoi(temp);
}


// Lis un ficher et, à partir de ses données initialise le tableau passer en paramètre
void textToTab(const char *_fichier, Graphe *graph) {
    // ifstream pour la lecture
    // lecture est le nom du flux
    std::ifstream lecture(_fichier);

    // respectivement le nb de lignes, de colones et un buffer qui lis valeur par valeur 
    int L, C, count;
    std::string buffer;

    lecture >> L >> C; // lis les deux première valeur d'un fichier

    int *_grille = graph->setNewGraph(L, C); // initialise le tab des altitudes
    int *_librairies = graph->setLibTab(L, C); // initialise le tab des librairie


    for (int i = 0; i < L; i++) { // parcours des lignes
        for (int j = 0; j < C; j++) { // parcours des colones
            lecture >> buffer; // lecture d'une altitude ou d'un L qui indique une librairie
            if (buffer[0] == 'L') {
                buffer.erase(0, 1); // on ignore le L
                buffer.erase(0, 1); // on ignore la 1er parenthèse
                count = extractInt(buffer); // on lit le count
                _librairies[i * C + j] = count;
                buffer.erase(0, intLenght(count) + 1); // on enlève la dernière parenthèse
                _grille[i * C + j] = stoi(buffer);
            } else {
                _grille[i * C + j] = stoi(buffer);
                _librairies[i * C + j] = -1;
            }
        }
    }
}

