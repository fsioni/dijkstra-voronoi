#include "Graphe.h"
#include <iostream>

int main () {

    Graphe g1;
    //g1.afficher();

    Graphe g2("./data/ex3Graphe.txt");
    g2.afficher();

    g2.applyDijsktra();

    /*int i, j, n;

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 10; j++) {
            n = 10*i + j; // Certaines valeurs de n correspondent Ã  des couleurs
            if (n > 108) break;
            std::cout <<"\033[1;"<<n<<"m"<<" Couleur " << n << "\033[0m";
            // On rÃ©cupÃ¨re l'indice n de la couleur d'affichage puis on affiche n
        }
        std::cout << std::endl;
    }*/
    
    return 0;
}