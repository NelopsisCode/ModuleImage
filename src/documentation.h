/**

@mainpage Page d'accueil



@section Introduction

Voici la documentation de notre module image, crée pour le TD de LIFAP4. \n
Code écrit en C++

@section Contenu

L'archive 11801888_11808121_11804605.tar.gz est composée selon cette arborescence:
  * src: Contient les code sources (.h et .cpp) du projet.
  * data: Contient les images générées par le programme.
  * bin: Contient les executables générés lors de la compilation.
  * obj: Contient les fichiers objet générés lors de la compilation.
  * doc: Contient la documentation générée avec Doxygen au format html.

@section Compilation

Testé sous Linux
Dépendance : SDL

Avant toute chose il faut installer la bibliothèque SDL dont le lien est disponible dans la partie IV.
Pour compiler sous LINUX, ouvrez un terminal dans le dossier 11801888_11808121_11804605 et lancez la commande make.
Le makefile va alors s'executer et créer 3 executables:

 * affichage: affiche une image de Steve (minecraft) sur laquelle il est possible de zoomer/dezoomer avec les touches G et T. \n
 * exemple: crée 2 images dans le dossier data/. \n
 * test: lance la fonction testRegression() qui test chaque fonction du module Image.




@section Exécution

Pour exécuter :\n
$./bin/affichage, \n
$./bin/exemple, \n
$./bin/test


@section Auteurs

@author ARTHUR CESCHIA (11804605), 
@author MATHIAS FLAGEY (11801888), 
@author THOMAS PISCIONE (11808121)

*/