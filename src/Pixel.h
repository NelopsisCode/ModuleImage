#ifndef __PXL
#define __PXL

/**
@class <Pixel>

@brief Contient une couleur en RGB

r = rouge
g = vert
b = bleu
*/

class Pixel{
private:

	unsigned char r,g,b;

public:

/**
@brief Constructeur

Crée un Pixel de couloir noire (255, 255, 255)
*/
	Pixel();

/**
@brief Constructeur par copie

Crée un Pixel identique à un autre Pixel.

Exemple de code
@code
Pixel(couleur);
@endcode

@param [in] nr quantité de rouge du pixel
@param [in] ng quantité de vert du pixel
@param [in] nb quantité de bleu du pixel
*/
	Pixel(unsigned char nr,unsigned char ng,unsigned char nb);


/**
@brief Accesseur Rouge
Renvoie le rouge du Pixel

*/
	unsigned char getRouge()const;


/**
@brief Accesseur Vert

Renvoie le vert du Pixel
*/
	unsigned char getVert()const;


/**
@brief Accesseur Bleu

Renvoie le bleu du Pixel
*/
	unsigned char getBleu()const;



/**
@brief Mutateur Rouge

Modifie le rouge du Pixel

Exemple de code
@code
setRouge(255);
@endcode
*/
	void setRouge(unsigned char nr);


/**
@brief Mutateur Vert

Modifie le vert du Pixel

Exemple de code
@code
setVert(255);
@endcode
*/
	void setVert(unsigned char ng);


/**
@brief Mutateur Bleu

Modifie le bleu du Pixel

Exemple de code
@code
setBleu(255);
@endcode
*/
	void setBleu(unsigned char nb);

};

#endif
