#include "Graphe.h"
#include <iostream>

int main() {
    std::cout<<"-----------------------------------------Début----------------------------------------------"<<std::endl;
    std::cout<<"Création et affichage avec le constructeur par défaut : "<<std::endl<<std::endl;
    
    Graphe g1;
    g1.afficher();

    std::cout<<"--------------------------------------------------------------------------------------------"<<std::endl;

    std::cout<<"Création et affichage avec le constructeur qui utilise un fichier : "<<std::endl<<std::endl;
    Graphe g2("./data/ex3Graphe.txt");
    g2.afficher();

    std::cout<<std::endl<<"--------------------------------------------------------------------------------------------"<<std::endl;


    g2.applyDijsktra(); //Affiche le diagramme de Voronoi pour le Dijsktra sans coût

    std::cout<<"--------------------------------------------------------------------------------------------"<<std::endl;

    g2.VoronoiLivraison(); //Affiche le diagramme de Voronoi pour le Dijsktra avec coût

    std::cout<<"------------------------------------------THE-END----------------------------------------------"<<std::endl;

    return 0;
}