#include "Graphe.h"
#include <iostream>
#include <math.h>
#include "MReadWrite.h"


Graphe::Graphe() {
    setNewGraph(4, 6);

    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            int indice = getIndice(i, j);
            grille[indice] = indice;
        }
    }
}

Graphe::Graphe(int _nbLigne, int _nbColonne, int *_altitudes) {
    setNewGraph(_nbLigne, _nbColonne);

    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            int indice = getIndice(i, j);
            grille[indice] = _altitudes[indice];
        }
    }
}

Graphe::Graphe(const char *_fichier) {
    textToTab(_fichier, this);
/*
    std::cout << "Nb ligne : " << nbLigne << std::endl;
    std::cout << "Nb colonnes : " << nbColonne << std::endl;
    for(int i = 0; i<nbLigne; i++){
        for (int j = 0; j < nbColonne; ++j) {
            std::cout << grille[0] << std::endl;
        }
    }
    */
}

int* Graphe::setNewGraph(int _nbLigne, int _nbColonne) {
    nbLigne = _nbLigne;
    nbColonne = _nbColonne;
    grille = new int[nbLigne*nbColonne];
    return grille;
}

void Graphe::afficher() {
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            int indice = getIndice(i, j);
            std::cout << getAltitude(indice) << " ";
        }
        std::cout << std::endl;
    }
}

void Graphe::testVoisins(int _indice) {
    std::cout << "\n";

    isVoisinExists(_indice, Cardinalite::Nord)
    ? std::cout << "L'indice " << _indice << " a un voisin nord\n"
    : std::cout << "L'indice " << _indice << " n'a pas de voisin nord\n";

    isVoisinExists(_indice, Cardinalite::Ouest)
    ? std::cout << "L'indice " << _indice << " a un voisin ouest\n"
    : std::cout << "L'indice " << _indice << " n'a pas de voisin ouest\n";

    isVoisinExists(_indice, Cardinalite::Sud)
    ? std::cout << "L'indice " << _indice << " a un voisin sud\n"
    : std::cout << "L'indice " << _indice << " n'a pas de voisin sud\n";

    isVoisinExists(_indice, Cardinalite::Est)
    ? std::cout << "L'indice " << _indice << " a un voisin est\n"
    : std::cout << "L'indice " << _indice << " n'a pas de voisin est\n";
}

int Graphe::getIndice(int _ligne, int _colonne) {
    return _ligne * nbColonne + _colonne;
}

int Graphe::getLigne(int _indice) {
    return floor(_indice / nbColonne);
}

int Graphe::getColonne(int _indice) {
    return _indice % nbColonne;
}

int Graphe::getAltitude(int _indice) {
    return grille[_indice];
}

int Graphe::nbVoisins(int _indice) {
    int nb_voisins = 0;
    isVoisinExists(_indice, Cardinalite::Nord) && nb_voisins++;
    isVoisinExists(_indice, Cardinalite::Ouest) && nb_voisins++;
    isVoisinExists(_indice, Cardinalite::Sud) && nb_voisins++;
    isVoisinExists(_indice, Cardinalite::Est) && nb_voisins++;

    return nb_voisins;
}

bool Graphe::isVoisinNordExists(int _indice) {
    return _indice-nbColonne > 0;
}

bool Graphe::isVoisinOuestExists(int _indice) {
    return _indice%nbColonne != 0;
}

bool Graphe::isVoisinSudExists(int _indice) {
    return (nbLigne-1)*nbColonne > _indice;
}

bool Graphe::isVoisinEstExists(int _indice) {
    return _indice%nbColonne != nbColonne-1;
}

bool Graphe::isVoisinExists(int _indice, Cardinalite _cardi) {
    switch (_cardi) {
        case Cardinalite::Nord : 
            return isVoisinNordExists(_indice);
            break;
        case Cardinalite::Ouest : 
            return isVoisinOuestExists(_indice);
            break;
        case Cardinalite::Sud : 
            return isVoisinSudExists(_indice);
            break;
        case Cardinalite::Est : 
            return isVoisinEstExists(_indice);
            break;
    }
    return false;
}

int Graphe::getVoisin(int _indice, Cardinalite _cardi) {
    switch (_cardi) {
        case Cardinalite::Nord :
            return getNord(_indice);
            break;
        case Cardinalite::Ouest :
            return getOuest(_indice);
            break;
        case Cardinalite::Sud :
            return getSud(_indice);
            break;
        case Cardinalite::Est :
            return getEst(_indice);
            break;
    }
    return -1;
}

int Graphe::getNord(int _indice) {
    if(isVoisinExists(_indice, Cardinalite::Nord)){
        return _indice - nbColonne;
    }
    return -1;
}

int Graphe::getOuest(int _indice) {
    if(isVoisinExists(_indice, Cardinalite::Ouest)){
        return _indice - 1;
    }
    return -1;
}

int Graphe::getSud(int _indice) {
    if(isVoisinExists(_indice, Cardinalite::Sud)){
        return _indice + nbColonne;
    }
    return -1;
}

int Graphe::getEst(int _indice) {
    if(isVoisinExists(_indice, Cardinalite::Est)){
        return _indice + 1;
    }
    return -1;
}

void Graphe::testRegression() {
    // 1 ) getIndice

}