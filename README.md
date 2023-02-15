# Projet LIFAPC
## Graphe d’un terrain et diagramme de Voronoï

## 🧐 A propos
Programme en C++ permettant de générer un graphe d’un terrain et un diagramme de Voronoï correspondant au résultat de l'algorithme de Dijkstra (avec et sans coût).


## Sujet de TP
[Disponible ici](https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAP6/tp09-voronoi.pdf "Sujet du TP noté")



### 🏁 Prérequis
`g++`

### 📁 Structure des dossiers
```
├── bin
│
├── data
│
├── obj
│
├── src
│   ├── Graphe.h/cpp
│   ├── graphe_main.h/cpp
│   ├── graphe_tests.h/cpp
│   └── MReadWrite.h/cpp
│
├── Makefile
│
└── README.md
```

### 👨🏻‍💻 Compilation

- Ouvrir un terminal dans le dossier du projet

- Compiler avec
```
make
```  

- Nettoyer les fichiers objets et exécutables avec
```
make clean
``` 

### 🚀 Lancement

- Lancer le programme avec
```
./bin/graphe_main
```

- Lancer les tests avec
```
./bin/graphe_tests
```


### 📝 Utilisation et modification des graphes
Un graphe est de la forme suivante, sous la forme d'un fichier `.txt`:
```
nombre_lignes nombre_colonnes
valeur valeur ... valeur
...
valeur valeur ... valeur

exemple : 
2 4
1 2 3 4
5 6 7 8
```

- Les valeurs sont composées avec la forme suivante :


Si le noeud possède une librairie :
```
L(Coût)Altitude
exemple :
L(2)4
```

Si le noeud ne possède pas de librairie :
```
Altitude
exemple : 4
```

- Charger un graphe

Appeler le constructeur prenant un fichier en paramètre
```
exemple
Graphe g("./data/exempleGraphe.txt");
```

- Afficher un graphe
```cpp
g.afficher();
```

- Afficher les diagrammes de Voronoï
```
Diagramme de Voronoï avec Dijkstra sans coût :
g.applyDijsktra(); 

Diagramme de Voronoï avec Dijkstra avec coût :
g.VoronoiLivraison();
```



## ✍️ Auteurs <a name = "authors"></a>

- [Farès SIONI](https://forge.univ-lyon1.fr/p1907037) : p1907037
- [Edouard THINOT](https://forge.univ-lyon1.fr/p1909945) : p1909945
