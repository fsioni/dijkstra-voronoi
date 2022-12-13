#include "Graphe.h"

int main() {

    Graphe g1;
    g1.afficher();

    Graphe g2("./data/exempleGraphe.txt");
    g2.afficher();

    g2.applyDijsktra(); //Affiche le diagramme de Voronoi pour le Dijsktra sans coût
    g2.VoronoiLivraison(); //Affiche le diagramme de Voronoi pour le Dijsktra avec coût

    return 0;
}