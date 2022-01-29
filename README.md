# Hangman (Jeu du pendu)

## Descritpion du projet
L'objectif du projet est de créer le jeu du pendu en C++ en __programmation orientée objet__ ainsi qu'une interface graphique __GUI__ permettant de visualiser le jeu. Etant sous Windows, j'ai décidé d'utiliser la librairie __PDCurses__ en utilisant l'éditeur __Code::Blocks__. Mais le projet se compile sur tout OS (cf 'Instructions pour la compilation du code source').  

_____________________________________________________

## Contenu du repository
* Jeu compilé  
`Hangman.exe` : Fichier executable du jeu  
`frenchssaccent.dic` : Dictionnaire de mots français (à mettre dans le même répertoire que Hangman.exe)

* Code source  
`main.cpp` : code principal  
`hangman.h` : définition de la classe _Hangman_  
`hangman.cpp` : déclaration des méthodes de la classe _Hangman_  
`Projet_PDCurses.cbp` : Projet Code::Blocks  
`frenchssaccent.dic` : Dictionnaire de mots français

## Instructions pour la compilation du code source
⇨ __Il faut au préalable télécharger la librairie PDCurses (ou Ncurses) sur sa machine__

* Pour Windows sous Code::Blocks :
1) Télécharger [PDCurses](https://sourceforge.net/projects/pdcurses/)
2) Télécharger `main.cpp`, `hangman.h`, `hangman.cpp` et `frenchssaccent.dic` dans un même répertoire __Hangman__
3) Déplacer la librairie PDCurses à l'emplacement : 
_C:\Program Files\CodeBlocks\MinGW\PDCurses_
3) Lier la librairie au compilateur de Code::Blocks :  
<img src="Tuto_PDCurses1.png" alt="drawing" width="450"/>  \, <img src="Tuto_PDCurses2.png" alt="drawing" width="450"/>
4) Lancer le projet `Projet_PDCurses.cbp` et compiler le code source

* Windows avec MinGW dans la console:
1) Télécharger [PDCurses](https://sourceforge.net/projects/pdcurses/)
2) Télécharger `main.cpp`, `hangman.h`, `hangman.cpp` et `frenchssaccent.dic` dans un même répertoire __Hangman__
3) Créer un dossier __include__ dans lequel mettre `hangman.h` et les fichiers de la librairie PDCURSES `pannel.h`, `curses.h` et `curspriv.h`
4) Copier coller le dossier __wincon__ de la librairie PDCURSES dans __Hangman__
5) Dans le dossier __wincon__ excécuter la commande `make -f Makefile WIDE=Y DLL=Y` => crée la librairie statique `pdcurses.a` et `pdcurses.dll`
6) Copier coller `pdcurses.a` et `pdcurses.dll` dans __Hangman__
7) Exécuter dans __Hangman__ : g++ -o Hangman_game main.cpp hangman.cpp -I"path\Hangman\include" -L"path\Hangman\wincon" -lpdcurses
8) `Hangman_game.exe` est créé dans __Hangman__

* Linux et Mac : 
1) Télécharger [NCURSES](https://invisible-island.net/ncurses/)
2) La documentation en ligne est plus simple pour lier NCURSES (s'inspirer de la section ci-dessus si besoin)

## Comment jouer ?
- Exécuter le programme
- Appuyer sur ENTRÉE pour commencer le jeu
- 1 joueur (mot aléatoire à deviner tirer aléatoirement dans un dictionnaire français) appuyer sur 'o'  ('one')
- 2 joueurs (un joueur choisit le mot à faire deviner) appuyer sur 't' ('two')
  - Taper les lettres du mot à faire deviner une par une, les unes à la suite des autres
  - Appuyer sur __";"__ pour cacher le mot et commencer le jeu du pendu
- Deviner le mot caché en tapant successivement les lettres auquelles vous pensez 
- Fin de partie : Appuyer sur ENTRÉE pour quitter

_____________________________________________________

# Commentaires

## Évolution du projet
Objectifs principaux :  
- Se familiariser avec PDCurses
- Coder le jeu du pendu pour un mot caché fixé (juste affichage des lettres)
- Coder la GUI (dessin du bonhomme et nombre de vie)

Puis rajout de règles et de fonctionnalités :
- Rajout de l'affichage des lettres demandées
- Affichage d'une erreur si le joueur demande une lettre déjà demandée
- 2 joueurs : Demander un mot à faire deviner à l'autre joueur
- 1 joueur : Tirer un mot aléatoire dans un dictionnaire

Pistes d'amélioration:
- Faire un autre affichage propre type "menu de jeu" avec les choix 1 ou 2 joueurs
- Rajouter la possibilité de changer de langue en ajoutant d'autres dictionnaires 

## Sources
* [Téléchargement PDCurses](https://sourceforge.net/projects/pdcurses/)
* [Téléchargement NCURSES](https://invisible-island.net/ncurses/)
* [Tuto PDCurses/NCURSES](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
* [CppReference std::vector](https://en.cppreference.com/w/cpp/container/vector)
* [CppReference std::find](https://en.cppreference.com/w/cpp/algorithm/find)
* [CppReference std::uniform_int_distribution](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution)
* [CppReference std::random_device](https://en.cppreference.com/w/cpp/numeric/random/random_device)
