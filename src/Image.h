#ifndef __IMG__
#define __IMG__


#include <SDL2/SDL.h> //Bibliothèque graphique


#include "Pixel.h"
#include <stdlib.h>
#include <string>

#define TAILLE_CANVA 200
#define NOM_CANVA "Minecraft"
#define COULEUR_DESTRUCTION_CANVA Pixel(102,255,255)

/**
\class <Image>

@brief Contient un tableau de Pixel, et ses dimensions.

@param dimx dimension x du tableau \n
@param dimy dimension y du tableau \n
@param tab un pointeur sur un tableau de Pixel 
*/

class Image{

private:

	unsigned int dimx, dimy;
	Pixel * tab;

public:

/**
@brief Constructeur par défaut de la classe Image

Construit une image vide.
*/
	Image();

	/**
@brief Constructeur par copie de la Classe Image

Initialise dimx et dimy (après vérification avec les assert)
puis alloue le tableau de pixel dans le tas (image noire).

Exemple de code
@code
Image(5,3);
@endcode

@param [in] dimensionX La longueur de l'image
@param [in] dimensionY La Hauteur de l'image
*/
	Image(unsigned int dimensionX,
		unsigned int dimensionY);

/**
@brief Destructeur de la classe Image

Désallocation de la mémoire du tableau de pixels
et mise à jour des champs dimx et dimy à 0

*/
	~Image();


/**
@brief Accesseur

Récupère le pixel original de coordonnées (x,y).

Exemple de code
@code
getPix(2,1);
@endcode

@param [in] x La coordonnée x du pixel à retourner
@param [in] y La coordonnée y du pixel à retourner

*/
	Pixel& getPix(unsigned int x,
		unsigned int y)const;


/**
@brief Mutateur

Modifie le pixel de coordonnées (x,y).

Exemple de code
@code
setPix(5,3);
@endcode
@param [in] x La coordonnée x du pixel à modifier
@param [in] y La coordonnée y du pixel à modifier
@param [in] couleur La couleur a appliqué lors de la modification du pixel

*/
	void setPix(unsigned int x,
		unsigned int y, 
		const Pixel& couleur);


/**
@brief Dessine un rectangle plein de la couleur dans l'image 

Change tout les pixels des coordonnées min aux coordonnées max par le pixel en paramètre. 

Exemple de code
@code
dessinerRectangle(1,2,5,7,couleur);
@endcode

Attention aux coordonnées : Xmax (resp. Ymax) doit être plus grand que Xmin (resp. Ymin).
Exemple d'erreur
@code
dessinerRectangle(5,7,1,2,couleur);
@endcode

@param [in] Xmin La coordonnée X du premier Pixel du rectangle
@param [in] Ymin La coordonnée Y du premier Pixel du rectangle
@param [in] Xmax La coordonnée X du dernier Pixel du rectangle
@param [in] Ymax La coordonnée Y du dernier Pixel du rectangle
@param [in] couleur La couleur du rectangle
*/
	void dessinerRectangle (unsigned int Xmin, 
		unsigned int Ymin,
		unsigned int Xmax,
		unsigned int Ymax, 
		const Pixel& couleur);


/**
@brief Efface l'image

Efface l'image en la remplissant de la couleur en paramètre. \n
La procédure appelle la procédure dessinerRectangle() avec: \n
Xmin = 0   Xmax = dimx (resp. Y)

Exemple de code
@code
effacer(couleur);
@endcode

@param [in] couleur Couleur utilisée pour recouvrir l'image.
*/
	void effacer (const Pixel& couleur);


/** 
@brief Série de test vérifiant le fonctionnement de la classe Image

Vérifie que le module fonctionne et
que les données membres de l'objet sont conformes.
*/
	void testRegression ();


/**
@brief Sauvegarde l'image

Enregistre l'image pixel par pixel dans un .txt, en donnant les
couleurs de chaque Pixel.

Exemple de code
@code
sauver(nomFichier);
@endcode

@param [in] filename La destination du fichier où stocker l'image.
*/
	void sauver(const std::string & filename)const;


/**
@brief Ouvre l'image

Lis l'image contenue dans un fichier .txt et la place dans une variable
de type Image, pour chaque Pixel.

Exemple de code
@code
ouvrir(nomFichier);
@endcode

@param [in] filename La destination du fichier qui contient l'image à ouvrir.
*/
	void ouvrir(const std::string & filename);


/**
@brief Affiche

Affiche l'Image pixel par pixel, en donnant les couleurs de chaque Pixel.
*/
	void afficherConsole();

/**
@brief Appel les 3 procédures de dessin

afficherInit pour initiliser l'Image \n 
afficherBoucle pour afficher l'image et permettre de zoomer/dezoomer \n
afficherDetruit pour terminer le programme.

*/
	void afficher() const;

/**
@brief Initialise et vérifie

Initialise les paramètres pour dessiner l'image.\n 
Cette fonction vérifie pour chaque paramètre si il a bien été initialisé et retourne une erreur si ce n'est pas le cas.

@param [in] canva Espace de dessin pour le programme.
@param [in] renderer Variable indispensable pour effectuer le rendu du dessin sur l'Image.
@param [in] textureImg Contient la texture à dessiner sur le canva

*/
	void afficherInit(SDL_Window*& canva, 
		SDL_Renderer*& renderer, 
		SDL_Texture*& textureImg) const;


/**
@brief Gère la boucle de dessin


@param [in] canva Le canva où le dessin est effectué.
@param [in] renderer L'outil de rendu utilisé pour dessiner sur le canva.
@param [in] textureImg La texture à dessiner sur le canva

*/
	void afficherBoucle(SDL_Window* canva, 
		SDL_Renderer* renderer, 
		SDL_Texture* textureImg) const;


/**
@brief Détruit l'image, libère la mémoire utilisée et quitte SQL2.


@param [in] canva Le canva à détruire.
@param [in] renderer L'outil de rendu à détruire.
@param [in] textureImg La texture à détruire.

*/
	void afficherDetruit(SDL_Window*& canva, 
		SDL_Renderer*& renderer, 
		SDL_Texture*& textureImg) const;

/**
@brief Gère les contrôles 
T et G pour zoomer et dézoomer, échape pour quitter le programme.

@param [in,out] zoom La valeur du zoom à appliquer lorsque l'utilisateur appuie sur T et G.

*/
	bool Event(float& zoom) const;


/**
@brief Permet d'appliquer le zoom à l'image

@param [in] canva Le canva où le dessin est effectué.
@param [in] renderer L'outil de rendu utilisé pour dessiner sur le canva.
@param [in] textureImg La texture à dessiner sur le canva.
@param [in] zoom La valeur du zoom à appliquer sur la structure sur le canva.
*/
	void dessiner(SDL_Window* canva, 
		SDL_Renderer* renderer, 
		SDL_Texture* textureImg, float zoom = 1.5) const;

};


#endif
