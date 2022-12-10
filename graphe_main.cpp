#include "Graphe.h"
#include <iostream>

int main () {

    Graphe g1;
    //g1.afficher();

    Graphe g2("./data/exempleGraphe.txt");
    g2.afficher();
    std::cout << g2.getValuationVoisin(3, Cardinalite::Sud) << std::endl;
    g2.applyDijsktra();
     /*
    g1.testVoisins(0);
    g1.testVoisins(1);
    g1.testVoisins(6);
    g1.testVoisins(7);
    g1.testVoisins(11);
    g1.testVoisins(17);
    g1.testVoisins(18);
    g1.testVoisins(23);*/
    
    return 0;
}