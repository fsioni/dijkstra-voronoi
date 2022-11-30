#ifndef TP_NOTE_GRAPHE_H
#define TP_NOTE_GRAPHE_H

#include <vector>

enum Cardinalite {Nord, Ouest, Sud, Est};

class Graphe {
public:
    Graphe();
    Graphe(int _nbLigne, int _nbColonne, int _altitudes[]);
    Graphe(const char * _fichier);

    int* setNewGraph(int _nbLigne, int _nbColonne);

    void afficher();
    void testVoisins(int _indice);
private:
    int nbLigne, nbColonne;
    int *grille;
    int getIndice(int _ligne, int _colonne);
    int getLigne(int _indice); // i / C
    int getColonne(int _indice); // i % C
    int getAltitude(int _indice);

    int nbVoisins(int _indice);

    bool isVoisinExists(int _indice, Cardinalite _cardi);
    bool isVoisinNordExists(int _indice);
    bool isVoisinOuestExists(int _indice);
    bool isVoisinSudExists(int _indice);
    bool isVoisinEstExists(int _indice);

    int getVoisin(int _indice, Cardinalite _cardi); //0 : Nord - 1 : Ouest - 2 : Sud - 3 : Est

    int getNord(int _indice); // i-C
    int getSud(int _indice); // i+C
    int getEst(int _indice); // i+1
    int getOuest(int _indice); // i-1
};


#endif //TP_NOTE_GRAPHE_H
