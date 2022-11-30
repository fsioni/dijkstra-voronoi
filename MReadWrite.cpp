#include <fstream>
#include <iostream>
#include "MReadWrite.h"

// Lis un ficher et, à partir de ses données initialise le tableau passer en paramètre
void textToTab (const char * _fichier, int * _tab) {
    // ifstream pour la lecture
    // lecture est le nom du flux
    std::ifstream lecture (_fichier) ;

    // respectivement le nb de lignes, de colones et un buffer qui lis valeur par valeur 
    int L, C, buffer; 

    lecture >> L >> C; // lis les deux première valeur d'un fichier

    for (int i = 0; i < L; i++ ) { // parcours des lignes
        for (int j = 0; j < C; j++) { // parcours des colones
            lecture >> buffer; // lecture d'une altitude
            _tab[i*C+j] = buffer; // 
        }
    }
}

