#ifndef TP_NOTE_GRAPHE_H
#define TP_NOTE_GRAPHE_H

#include <vector>

// Definition des différentes cardinalités
enum Cardinalite {Nord, Ouest, Sud, Est};

class Graphe {
public:
    
    /******************************/
    /*Constructeurs & destructeur*/
    /****************************/

    Graphe();
    Graphe(int _nbLigne, int _nbColonne, int _altitudes[]);
    // Prend un paramètre un ficher txt pour affecter les altitudes au graphe
    Graphe(const char * _fichier);
    ~Graphe();

    /********************************/
    /*Fonctions et procédure public*/
    /******************************/

    // Initialise le tableau avec le nombre de lignes et de colones passés en paramètre 
    int* setNewGraph(int _nbLigne, int _nbColonne);

    bool* setLibTab(int _nbLigne, int _nbColonne);

    // Affiche le graphe (les altitudes)
    void afficher();
    
    // Affiche le status des voisins en fonction l'indice en paramètre
    void testVoisins(int _indice);
    void setAltitude(int _indice, int _newAlti);
    float getValuationVoisin(int _indice, Cardinalite _cardi);

private:
    
    /****************/
    /*Donnée membre*/
    /**************/

    int nbLigne, nbColonne; // nombre de ligne & de colonne
    int *grille; // tableau 1D d'entier
    bool *librairies; // tableau de booléén (vrai si il ya un librairie)

    /*******************************/
    /*Fonction et procédure membre*/
    /*****************************/

    // Renvoi l'indice du tableau sous forme 1D 
    int getIndice(int _ligne, int _colonne);
    // Renvoi la ligne de l'indice passer en paramètre
    int getLigne(int _indice);
    // Renvoi la colonne de l'indice passer en paramètre
    int getColonne(int _indice);
    // Renvoi l'altitude de l'indice passer en paramètre
    int getAltitude(int _indice);

    // Renvoi le nombre de voisin que possède l'indice passer en paramètre
    int nbVoisins(int _indice);

    // Renvoi vrai si le voisin de l'indice, pour une cardinalité passer en paramètre existe, faux sinon
    bool isVoisinExists(int _indice, Cardinalite _cardi);
    // Renvoi vrais si l'indice à un voisin nord, faux sinon
    bool isVoisinNordExists(int _indice);
    // Renvoi vrais si l'indice à un voisin ouest, faux sinon
    bool isVoisinOuestExists(int _indice);
    // Renvoi vrais si l'indice à un voisin sud, faux sinon
    bool isVoisinSudExists(int _indice);
    // Renvoi vrais si l'indice à un voisin est, faux sinon
    bool isVoisinEstExists(int _indice);

    // Renvoi l'altitude (int) du voisin de _indice (paramètre) pour une certaine cardinalité 
    int getVoisin(int _indice, Cardinalite _cardi);


    // Renvoi l'altitude du voisin nord
    int getNord(int _indice);
    // Renvoi l'altitude du voisin sud
    int getSud(int _indice);
    // Renvoi l'altitude du voisin est
    int getEst(int _indice);
    // Renvoi l'altitude du voisin ouest
    int getOuest(int _indice);

    // Procédure de test

    void testRegression(); // affectue un série de tests 

};


#endif //TP_NOTE_GRAPHE_H
