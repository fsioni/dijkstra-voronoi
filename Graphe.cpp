#include "Graphe.h"
#include <iostream>
#include <math.h>
#include <queue>
#include <assert.h>
#include "MReadWrite.h"
#include <iomanip>


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
}

Graphe::~Graphe() {
    delete grille;
}

int* Graphe::setNewGraph(int _nbLigne, int _nbColonne) {
    nbLigne = _nbLigne;
    nbColonne = _nbColonne;
    grille = new int[nbLigne*nbColonne];
    return grille;
}

int* Graphe::setLibTab(int _nbLigne, int _nbColonne) {
    nbLigne = _nbLigne;
    nbColonne = _nbColonne;
    librairies = new int [nbLigne*nbColonne];
    return librairies;
}

void Graphe::afficher() {
    for (int i = 0; i < nbLigne; ++i) {
        for (int j = 0; j < nbColonne; ++j) {
            int indice = getIndice(i, j);
            std::cout << (librairies[indice] != -1 ? "L" : "") << getAltitude(indice) << " ";
        }
        std::cout << std::endl;
    }
}

void Graphe::testVoisins(int _indice) {
    std::cout << "\n";
    std::cout << "Pour la valeur : " << getAltitude(_indice) << std::endl;

    if(isVoisinExists(_indice, Cardinalite::Nord)){
        std::cout << "L'indice " << _indice << " a un voisin nord\n";
        std::cout << "Son altitude est : " << getAltitude(getVoisin(_indice, Cardinalite::Nord)) << std::endl;
    }else {
        std::cout << "L'indice " << _indice << " n'a pas de voisin nord\n";
    }

    if(isVoisinExists(_indice, Cardinalite::Ouest)){
        std::cout << "L'indice " << _indice << " a un voisin Ouest\n";
        std::cout << "Son altitude est : " << getAltitude(getVoisin(_indice, Cardinalite::Ouest)) << std::endl;
    }else {
        std::cout << "L'indice " << _indice << " n'a pas de voisin Ouest\n";
    }

    if(isVoisinExists(_indice, Cardinalite::Sud)){
        std::cout << "L'indice " << _indice << " a un voisin Sud\n";
        std::cout << "Son altitude est : " << getAltitude(getVoisin(_indice, Cardinalite::Sud)) << std::endl;
    }else {
        std::cout << "L'indice " << _indice << " n'a pas de voisin Sud\n";
    }

    if(isVoisinExists(_indice, Cardinalite::Est)){
        std::cout << "L'indice " << _indice << " a un voisin Est\n";
        std::cout << "Son altitude est : " << getAltitude(getVoisin(_indice, Cardinalite::Est)) << std::endl;
    }else {
        std::cout << "L'indice " << _indice << " n'a pas de voisin Est\n";
    }
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

void Graphe::setAltitude(int _indice, int _newAlti) {
    grille[_indice] = _newAlti;
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
    return _indice-nbColonne >= 0;
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

double Graphe::getValuationVoisin(int _indice, Cardinalite _cardi) {
    int voisinIndice = 0;
    switch (_cardi) {
        case Cardinalite::Nord :
            voisinIndice = getNord(_indice);
            break;
        case Cardinalite::Ouest :
            voisinIndice = getOuest(_indice);
            break;
        case Cardinalite::Sud :
            voisinIndice = getSud(_indice);
            break;
        case Cardinalite::Est :
            voisinIndice = getEst(_indice);
            break;
    }

    int currAltitude = getAltitude(_indice);

    int differenceAlti = currAltitude - getAltitude(voisinIndice);
    differenceAlti *= differenceAlti;
    return sqrt(1 + differenceAlti);
}

int Graphe::getNord(int _indice) {
    if(isVoisinExists(_indice, Cardinalite::Nord)){
        return _indice - nbColonne;
    }
    std::cout << "\nPour l'indice : " << _indice << " Il n'y a pas de voisin Nord\n";
    return -1;
}

int Graphe::getOuest(int _indice) {
    if(isVoisinExists(_indice, Cardinalite::Ouest)){
        return _indice - 1;
    }
    std::cout << "\nPour l'indice : " << _indice << " Il n'y a pas de voisin Ouest\n";
    return -1;
}

int Graphe::getSud(int _indice) {
    if(isVoisinExists(_indice, Cardinalite::Sud)){
        return _indice + nbColonne;
    }
    std::cout << "\nPour l'indice : " << _indice << " Il n'y a pas de voisin Sud\n";
    return -1;
}

int Graphe::getEst(int _indice) {
    if(isVoisinExists(_indice, Cardinalite::Est)){
        return _indice + 1;
    }
    std::cout << "\nPour l'indice : " << _indice << " Il n'y a pas de voisin Est\n";
    return -1;
}

void Graphe::testRegression() {

    // 1) test pour le constructeur de graphe avec 3 paramètre
    // -> setNewGraph

    int tab[6] = {1,2,3,4,5,6};
    Graphe gExemple(2,3,tab);
    assert(gExemple.nbLigne == 2);
    assert(gExemple.nbColonne == 3);

    for (int i = 0; i < 4; ++i) { // test grille 
        assert(gExemple.grille[i] == i+1);
    } 
    
    // 2) test pour le constructeur de graphe avec fichier 
    // -> setLibTab

    Graphe gExemple2("./data/ex2Graphe.txt"); // constructeur avec ficher
    assert (gExemple2.nbLigne == 3);
    assert (gExemple2.nbColonne == 4);

    for (int i = 0; i < gExemple2.nbColonne*gExemple2.nbLigne; ++i) { // test grille 
        assert(gExemple2.grille[i] == i);
    }     
    // Test pour l'emplacement des librairies
    assert (gExemple2.librairies[0] == false);
    assert (gExemple2.librairies[1] == false);
    assert (gExemple2.librairies[2] == false);
    assert (gExemple2.librairies[3] == false);
    assert (gExemple2.librairies[4] == false);
    assert (gExemple2.librairies[5] == false);
    assert (gExemple2.librairies[6]);
    assert (gExemple2.librairies[7] == false);
    assert (gExemple2.librairies[8] == false);
    assert (gExemple2.librairies[9] == false);
    assert (gExemple2.librairies[10] == false);
    assert (gExemple2.librairies[11]);

    // 3) Test afficher -> affiche les altitudes du graphe

    std::cout<<"Test procédure affiche qui affiche les altitudes du graphe :"<<std::endl;
    gExemple2.afficher();

    // 4) Test getIndice -> prend en paramètre la ligne et la colonne et renvoie l'indice correspond pour un tableau 1D

    for (int i = 0; i < gExemple2.nbLigne; ++i){
        for (int j = 0; j < gExemple2.nbColonne; ++j) {
            assert(gExemple2.getIndice(i,j) == i * gExemple2.nbColonne + j);
        }
    }
    
    // 5) Test getLigne -> prend en paramètre un indice (du tableau 1D) et renvoit la ligne à laquelle appartient cette indice

    for (int i = 0; i < 12; ++i){
        assert(gExemple2.getLigne(i) == floor(i / gExemple2.nbColonne));
    }

    // 6) Test getColonne -> prend en paramètre un indice (tableau 1D) et renvoit la colonne à laquelle appartient cette indice

    for (int i = 0; i < 12; ++i){
        assert(gExemple2.getColonne(i) == i % gExemple2.nbColonne);
    }

    // 7) Test nbVoisins -> prend en paramètre un indice (tableau 1D) et renvoi le nombre de voisin qui existe

    assert (gExemple2.nbVoisins(0) == 2);
    assert (gExemple2.nbVoisins(1) == 3);
    assert (gExemple2.nbVoisins(2) == 3);
    assert (gExemple2.nbVoisins(3) == 2);
    assert (gExemple2.nbVoisins(4) == 3); 
    assert (gExemple2.nbVoisins(5) == 4);
    assert (gExemple2.nbVoisins(7) == 3);
    assert (gExemple2.nbVoisins(8) == 2);
    assert (gExemple2.nbVoisins(10) == 3);
    assert (gExemple2.nbVoisins(11) == 2);

    // 8) Test isVoisinNordExists -> prend en paramètre un indice et renvoie vrais si sont voisin nord exist

    assert(gExemple2.isVoisinNordExists(0) == false);
    assert(gExemple2.isVoisinNordExists(3) == false);
    assert(gExemple2.isVoisinNordExists(4) == true);
    assert(gExemple2.isVoisinNordExists(5) == true);
    assert(gExemple2.isVoisinNordExists(9) == true);
    assert(gExemple2.isVoisinNordExists(11) == true);

    // 9) Test isVoisinSudExists -> prend en paramètre un indice et renvoie vrais si sont voisin sud exist

    assert(gExemple2.isVoisinSudExists(0) == true);
    assert(gExemple2.isVoisinSudExists(3) == true);
    assert(gExemple2.isVoisinSudExists(5) == true);
    assert(gExemple2.isVoisinSudExists(8) == false);
    assert(gExemple2.isVoisinSudExists(11) == false);

    // 10) Test isVoisinEstExists -> prend en paramètre un indice et renvoie vrais si sont voisin est exist

    assert(gExemple2.isVoisinEstExists(0) == true);
    assert(gExemple2.isVoisinEstExists(5) == true);
    assert(gExemple2.isVoisinEstExists(7) == false);
    assert(gExemple2.isVoisinEstExists(8) == true);
    assert(gExemple2.isVoisinEstExists(11) == false);

    // 11) Test isVoisinOuestExists -> prend en paramètre un indice et renvoie vrais si sont voisin ouest exist

    assert(gExemple2.isVoisinOuestExists(0) == false);
    assert(gExemple2.isVoisinOuestExists(5) == true);
    assert(gExemple2.isVoisinOuestExists(3) == true);
    assert(gExemple2.isVoisinOuestExists(8) == false);
    assert(gExemple2.isVoisinOuestExists(11) == true);

    // 12) Test getNord -> prend en paramètre un indice et renvoie l'indice de sont voisin nord si il existe (-1 sinon)

    assert(gExemple2.getNord(0) == -1);
    assert(gExemple2.getNord(7) == 3);
    assert(gExemple2.getNord(4) == 0);
    assert(gExemple2.getNord(6) == 2);
    assert(gExemple2.getNord(11) == 7);

    // 13) Test getSud -> prend en paramètre un indice et renvoie l'indice de sont voisin sud si il existe (-1 sinon)

    assert(gExemple2.getSud(0) == 4);
    assert(gExemple2.getSud(7) == 11);
    assert(gExemple2.getSud(4) == 8);
    assert(gExemple2.getSud(6) == 10);
    assert(gExemple2.getSud(11) == -1);

    // 14) Test getEst -> prend en paramètre un indice et renvoie l'indice de sont voisin est si il existe (-1 sinon)

    assert(gExemple2.getEst(0) == 1);
    assert(gExemple2.getEst(7) == -1);
    assert(gExemple2.getEst(4) == 5);
    assert(gExemple2.getEst(6) == 7);
    assert(gExemple2.getEst(11) == -1);

    // 15) Test getOuest -> prend en paramètre un indice et renvoie l'indice de sont voisin ouest si il existe (-1 sinon)

    assert(gExemple2.getOuest(0) == -1);
    assert(gExemple2.getOuest(7) == 6);
    assert(gExemple2.getOuest(4) == -1);
    assert(gExemple2.getOuest(6) == 5);
    assert(gExemple2.getOuest(11) == 10);

    // 16) Test isVoisinExists -> prend en paramètre un indice et un cardinalité (Nord, sud, est et ouest), renvoi vrais si le voison pour
    // la cardinalité passé en paramètre existe.

    assert((gExemple2.getNord(4) == 0) && (gExemple2.isVoisinExists(4,Cardinalite::Nord) == true));
    assert((gExemple2.getSud(4) == 8) && (gExemple2.isVoisinExists(4,Cardinalite::Sud) == true));
    assert((gExemple2.getEst(4) == 5) && (gExemple2.isVoisinExists(4,Cardinalite::Est) == true));
    assert((gExemple2.getOuest(4) == -1) && (gExemple2.isVoisinExists(4,Cardinalite::Ouest) == false));

    //17) Test getVoisin -> prend un paramètre un indice et une cardinalité et, renvoi l'indice du voisin pour cette cardinalité

    assert((gExemple2.getNord(0) == -1) && (gExemple2.getVoisin(0,Cardinalite::Nord) == -1));
    assert((gExemple2.getSud(0) == 4) && (gExemple2.getVoisin(0,Cardinalite::Sud) == 4));
    assert((gExemple2.getEst(0) == 1) && (gExemple2.getVoisin(0,Cardinalite::Est) == 1));
    assert((gExemple2.getOuest(0) == -1) && (gExemple2.getVoisin(0,Cardinalite::Ouest) == -1));
}   

struct PQElement { // element de notre file de priorité
    int indice;
    double valuation;

    PQElement(int _indice, double _valuation) : indice(_indice), valuation(_valuation) {} // constructeur

    bool operator<(const PQElement& _other) const { // surcharge de l'opérateur de comparaison
        return valuation < _other.valuation;
    }
};

void Graphe::applyDijsktra() {
    int taille = nbLigne * nbColonne;
    std::vector<double> valuation(taille);
    std::vector<int> precedent(taille);
    for (int i = 0; i < taille; ++i) {
        precedent[i] = i; // initialisation chaque élément du tableau à pour précédent lui même
        valuation[i] = -1; // initialisation du tableau valuation 
    }

    std::priority_queue<PQElement> aTraiter; // file de priorité (celui tous en haut de la pile est celui qu'on doit traiter)

    for (int i = 0; i < taille; ++i) { // initialise l'emplacement des différentes librairie
        if(librairies[i]){ // si il y a une librairie ici
            valuation[i] = 0; // alors la plus proche librairie c'est elle même
            precedent[i] = -1; // un librairie n'a donc pas de precedent
            aTraiter.push(PQElement(i, 0));
        }
    }

    while(!aTraiter.empty()){
        PQElement curr = aTraiter.top(); // je vais traiter mon élément avec la plus grande priorité
        aTraiter.pop(); // donc je peux l'enlever

        for (int i = 0; i < 4; ++i) { // pour tous les voisin (Nord sud est ouest)
            if(isVoisinExists(curr.indice, (Cardinalite)i)){ // si une voison exist pour cette cardinalité
                int voisinIndice = getVoisin(curr.indice, (Cardinalite)i); // je récupère son indice
                double valuationVoisin = getValuationVoisin(curr.indice, (Cardinalite)i); // je récupère sa valuation
                double dv = valuation[voisinIndice]; // on récupère la valuation du voisin
                double dc = valuation[curr.indice]; // on récupère la valuation de la où je me trouve
                double dnv = dc + valuationVoisin; // je calcule la distance entre ces deux points
                if(precedent[voisinIndice] == voisinIndice || dnv < dv){ // si je n'ai pas de précédent ou que ma nouvelle distance est plus petite que la précédente valuation de mon voisin 
                    precedent[voisinIndice] = curr.indice; // mon nouveau point le plus proche devient celui sur lequel j'ai lancer le traitement 
                    valuation[voisinIndice] = dnv; // ma distance qui me sépare de la librairie la plus proche est mis à jour
                    aTraiter.push(PQElement(voisinIndice, dnv)); // on le passe chez les noirs 
                }
            }
        }
    }

    //Afficher les tableaux de valuation et de precedent
    std::cout <<"\n Valuation : \n";
    for (int i = 0; i < taille; ++i) {
        std::cout << valuation[i] << " ";
        if(i%nbColonne == nbColonne-1){
            std::cout << "\n";
        }
    }
    std::cout << "\n Precedent : \n";
    for (int i = 0; i < taille; ++i) {
        std::cout << precedent[i] << " ";
        if(i%nbColonne == nbColonne-1){
            std::cout << "\n";
        }
    }

    printVoronoi(valuation, precedent);
}

void Graphe::printVoronoi(std::vector<double> valuation, std::vector<int> precedent) {
    std::cout << "\n\n";
    int librairieCount = 1;
    int tabColors[nbLigne*nbColonne];
    int indicePred;

    for (int i = 0; i < nbLigne*nbColonne; ++i) {
        if (precedent[i] == -1) {
            if(librairieCount+40 > 46) {
                std::cout<<"J'ai plus de couleur pour peindre les librairies";
                break;
            }
            tabColors[i] = librairieCount+40;
            librairieCount++;
        }
    }

    for (int i = 0; i < nbLigne*nbColonne; ++i) {  // a
        if (precedent[i] == -1) {
            std::cout<<std::setw(5);
            std::cout <<"\033[30;"<<tabColors[i]<<"m"<<" "<< "\033[0m";
            std::cout <<"\033[30;"<<tabColors[i]<<"m"<<"LIB "<< "\033[0m";
            std::cout <<"\033[30;"<<tabColors[i]<<"m"<<" "<< "\033[0m";
        } else {
            indicePred = precedent[i];
            while (precedent[indicePred] != -1) {
                indicePred = precedent[indicePred];
            }
            std::cout.precision(4);
            std::cout<<std::setw(5);
            std::cout <<"\033[30;"<<tabColors[indicePred]<<"m"<<valuation[i]<<" "<< "\033[0m";
        }
        if(i%nbColonne == nbColonne-1){
            std::cout<<std::endl;
        }
    }
}