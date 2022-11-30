#include <fstream>
#include "MReadWrite.h"
#include "Graphe.h"

// Lis un ficher et, à partir de ses données initialise le tableau passer en paramètre
void textToTab (const char * _fichier, Graphe* graph) {
    // ifstream pour la lecture
    // lecture est le nom du flux
    std::ifstream lecture (_fichier) ;

    // respectivement le nb de lignes, de colones et un buffer qui lis valeur par valeur 
    int L, C, buffer; 

    lecture >> L >> C; // lis les deux première valeur d'un fichier

    int *_grille = graph->setNewGraph(L, C);


    for (int i = 0; i < L; i++ ) { // parcours des lignes
        for (int j = 0; j < C; j++) { // parcours des colones
            lecture >> buffer; // lecture d'une altitude
            _grille[i*C+j] = buffer; //
        }
    }
}

