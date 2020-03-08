Module Image
-------------------------------
# I-Présentation et contexte

  * Cette bibliothèque est capable d'afficher et de manipuler une image.
  * Nous l'avons codé dans le cadre de l'UE LIFAP4 de notre deuième année de PeiP (Parcours des Ecoles 
d'Ingenieurs Polytech)	
  * Notre groupe est composé de : ARTHUR CESCHIA (11804605), MATHIAS FLAGEY (11801888), 
THOMAS PISCIONE (11808121)

-------------------------------
# II-Organisation de l'archive

L'archive 11801888_11808121_11804605.tar.gz est composée selon cette arborescence:
  * src: Contient les code sources (.h et .cpp) du projet.
  * data: Contient les images générées par le programme.
  * bin: Contient les executables générés lors de la compilation.
  * obj: Contient les fichiers objet générés lors de la compilation.
  * doc: Contient la documentation générée avec Doxygen au format html.

-------------------------------
# III-Compilation et rôle des executables

Avant toute chose il faut installer la bibliothèque SDL dont le lien est disponible dans la partie IV.
Pour compiler sous LINUX, ouvrez un terminal dans le dossier 11801888_11808121_11804605 et lancez la commande make.
Le makefile va alors s'executer et créer 3 executables:

 * affichage: affiche une image de Steve (minecraft) sur laquelle il est possible de zoomer/dezoomer avec les touches G et T.
 * exemple: crée 2 images dans le dossier data/. La première.
 * test: lance la fonction testRegression() qui test chaque fonction du module Image.

Pour les lancer il suffit d'utiliser les commandes ./bin/affichage, ./bin/exemple, ./bin/test

-------------------------------
# IV-Documentation et bibliothèque graphique

 *La documentation Doxygen du module image peut être générée avec la commande: doxygen doc/image.doxy 
et visionnée avec la commande: [browser] doc/html/index.html où [browser] est le nom du navigateur avec lequel la documentation doit être visionnée.

 *La bibliothèque SDL2 utilisée pour afficher les images est disponible au lien suivant: 
https://www.libsdl.org/




