#include "Image.h" 

#include <iostream> //Pour les flux (cout)
#include <fstream> //Pour gérer la lecture et l'écriture dans un fichier
#include <cassert> //Pour les assert()

//Génération de nombres aléatoires
#include <stdlib.h> //Pour srand() et rand()
#include <time.h> //Pour time()


using namespace std; 


//Constructeur

Image::Image(){

	dimx=0;
	dimy=0;

	tab=NULL;

}

//Constructeur par copie

Image::Image(unsigned int dimensionX,
	unsigned int dimensionY)
{

	dimx = dimensionX;
	dimy = dimensionY;
	tab = new Pixel[dimx*dimy];

}

//Destructeur

Image::~Image()
{

	delete[] tab;
	dimx=0;
	dimy=0;
	cout << "image détruite" <<endl;

}

//Accesseur, retourne le pixel dont les coordonnées sont passées en paramètre.

Pixel& Image::getPix(unsigned int x,
	unsigned int y)const
{
	return tab[y * dimx + x];
}


//Mutateur, modifie le pixel dont les coordonnées sont passées en paramètre avec la couleur. 

void Image::setPix(unsigned int x,
	unsigned int y, 
	const Pixel& couleur)
{
	tab[ y * dimx + x].setRouge(couleur.getRouge());
	tab[ y * dimx + x].setVert(couleur.getVert());
	tab[ y * dimx + x].setBleu(couleur.getBleu());
}


//Fonctions membre

void Image::dessinerRectangle (unsigned int Xmin, 
	unsigned int Ymin,
	unsigned int Xmax,
	unsigned int Ymax,
	const Pixel& couleur)
{

	assert (Xmin <= Xmax);
	assert (Ymin <= Ymax);
	for (unsigned int i = Ymin; i <= Ymax; i++){

		for (unsigned int j = Xmin; j <= Xmax ; j++){

			setPix(j,i,couleur);
		}
	}
}



void Image::effacer (const Pixel& couleur){
//dessine un rectangle de la taille de l'image pour l'effacer. 

	dessinerRectangle(0, 0,dimx - 1,dimy - 1,couleur);
}



void Image::testRegression()
{

	srand((unsigned int)time(NULL)); // Pour générer des nombres aléatoires avec rand()

	Pixel n(0, 0, 0);


	effacer(n);


	cout << "test setPix"<< endl;
//Set de Pixels aléatoires sur tous les pixels de l'image.
	for (unsigned int i = 0; i < dimx; i++)
	{
		for (unsigned int j = 0; j < dimy; j++)
		{
			unsigned int r = rand() % 255;
			unsigned int v = rand() % 255;
			unsigned int b = rand() % 255;
			Pixel p(r, v, b);
			setPix(i, j, p);
		}
	}

	cout << "Ok"<< endl;

	cout << "test getPix"<< endl;
//Lecture et test des Pixels qui ont été set dans l'étape précédente.
	for (unsigned int i = 0; i < dimx; i++)
	{
		for (unsigned int j = 0; j < dimy; j++)
		{
			unsigned int r = getPix(i, j).getRouge();
			unsigned int v = getPix(i, j).getVert();
			unsigned int b = getPix(i, j).getBleu();
			assert(r <= 255 && r >= 0);
			assert(v <= 255 && v >= 0);
			assert(b <= 255 && b >= 0);
		}
	}

	cout << "Ok"<< endl;

//sauvegarde de l'image dans le dossier data
	sauver("./data/test1.ppm");

	cout << "Test effacer"<< endl;
	effacer(n);
//On vérifie que chaque pixel a été effacé.
	for (unsigned int i = 0; i < dimx; i++)
	{
		for (unsigned int j = 0; j < dimy; j++)
		{
			assert(getPix(i, j).getRouge() == 0 && 
				getPix(i, j).getVert() == 0 && 
				getPix(i, j).getBleu() == 0);
		}
	}
	cout << "Ok"<< endl;

	dimx = 10;
	dimy = 10;

	cout << "test rectangle"<< endl;
//dessin d'un rectangle aléatoire avec une couleur aléatoire.
	unsigned int X1 = rand() % (dimx - 1);
	unsigned int X2 = rand() % (dimx - 1 - X1) + X1;
	unsigned int Y1 = rand() % (dimy - 1);
	unsigned int Y2 = rand() % (dimy - 1 - Y1) + Y1;

	unsigned int rRec = rand() % 255;
	unsigned int vRec = rand() % 255;
	unsigned int bRec = rand() % 255;
	Pixel p(rRec, vRec, bRec);
	dessinerRectangle(X1, Y1, X2, Y2, p);

//On vérifie que le rectangle a bien été dessiné à l'endroit souhaité et avec la couleur souhaitée
	for (unsigned int i = 0; i < dimx; i++)
	{
		for (unsigned int j = 0; j < dimy; j++)
		{
			unsigned int r = getPix(i, j).getRouge();
			unsigned int v = getPix(i, j).getVert();
			unsigned int b = getPix(i, j).getBleu();
			if (i >= X1 && i <= X2 && j >= Y1 && j <= Y2)
			{
				assert(r == rRec && v == vRec && b == bRec);
			}
			else
			{
				assert(r == 0 && v == 0 && b == 0);
			}
		}
	}

	cout << "Ok" << endl;


	cout << "Test Sauver/ouvrir" << endl;
//Sauvegarde de l'image qui test le rectangle
	sauver("./data/test2.ppm");
//On re ouvre et vérifie l'ouverture de la première image
	ouvrir("./data/test1.ppm");

	for (unsigned int i = 0; i < dimx; i++)
	{
		for (unsigned int j = 0; j < dimy; j++)
		{
			unsigned int r = getPix(i, j).getRouge();
			unsigned int v = getPix(i, j).getVert();
			unsigned int b = getPix(i, j).getBleu();
			assert(r <= 255 && r >= 0);
			assert(v <= 255 && v >= 0);
			assert(b <= 255 && b >= 0);
		}
	}

	cout << "OK" << endl;

	cout << "Test afficher console" << endl;

	ouvrir("./data/test2.ppm");

	afficherConsole();

	cout << "OK" << endl;

	//Pour que le script ne retire pas de points à cause des images dans le dossier data/.
	remove("./data/test1.ppm");
	remove("./data/test2.ppm");

	cout << "Toutes les fonctions ont été testées sans erreur." <<endl;

}



void Image::sauver(const std::string & filename) const 
{
	ofstream fichier (filename.c_str());

	assert(fichier.is_open());

	fichier << "P3" << endl;
	fichier << dimx << " " << dimy << endl;
	fichier << "255" << endl;

	for(unsigned int y = 0; y < dimy; y++)
	{
		for(unsigned int x = 0; x < dimx; x++)
		{
			Pixel pix = getPix(x,y);

			fichier << (int) pix.getRouge() << " " << (int) pix.getVert() << " " << (int) pix.getBleu() << " ";
		}
	}
	cout << "Sauvegarde de l'image " << filename << " ... OK\n";
	fichier.close();
	
}


void Image::ouvrir(const string & filename) {

	ifstream fichier (filename.c_str());
	assert(fichier.is_open());

	int r,g,b;

	string mot;

	dimx = dimy = 0;

	fichier >> mot >> dimx >> dimy >> mot;

	assert(dimx > 0 && dimy > 0);

	if (tab != NULL)
		delete [] tab;

	tab = new Pixel [dimx*dimy];

	for(unsigned int y=0; y < dimy; y++)
	{

		for(unsigned int x=0; x < dimx; x++) 
		{
			fichier >> r >> g >> b;
			getPix(x,y).setRouge(r);
			getPix(x,y).setVert(g);
			getPix(x,y).setBleu(b);
		}
	}
	fichier.close();
	cout << "Lecture de l'image " << filename << " ... OK\n";
}


void Image::afficherConsole(){

	cout << dimx << " " << dimy << endl;

	for(unsigned int y=0; y < dimy; y++) 
	{
		for(unsigned int x=0; x < dimx; x++) 
		{
			Pixel pix = getPix(x,y);

			cout << (int)pix.getRouge() << " " <<(int)pix.getVert() << " " << (int)pix.getBleu() << " ";
		}
		cout << endl;
	}
}


//affichage de l'image avec SDL
void Image::afficher() const
{

	SDL_Window  * canva        = NULL;
	SDL_Renderer* renderer      = NULL;
	SDL_Texture * textureImg  = NULL; 


	afficherInit(canva, renderer, textureImg);

	afficherBoucle(canva, renderer, textureImg);

	afficherDetruit(canva, renderer, textureImg);

}

void Image::afficherInit(SDL_Window*& canva, 
	SDL_Renderer*& renderer, 
	SDL_Texture*& textureImg) const
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Problème d'initialisation de SDL: " << SDL_GetError() << endl;
		exit(1);
	}

	canva = SDL_CreateWindow(
		NOM_CANVA, 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		TAILLE_CANVA, TAILLE_CANVA,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
		);

	if(canva == NULL)
	{
		cout << "Problème d'ouverture du canva: " 
		<< SDL_GetError() << endl;
		afficherDetruit(canva, renderer, textureImg); 
		exit(1);
	}

	renderer = SDL_CreateRenderer(canva, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL)
	{
		cout << "Problème dans la création de SDL_Renderer: " 
		<< SDL_GetError() << endl;
		afficherDetruit(canva, renderer, textureImg); 
		exit(1);
	}

	SDL_SetRenderDrawColor(renderer, 
		COULEUR_DESTRUCTION_CANVA.getRouge(), 
		COULEUR_DESTRUCTION_CANVA.getBleu(),
		COULEUR_DESTRUCTION_CANVA.getVert(), 
		255);

	if(textureImg != NULL)
		SDL_DestroyTexture(textureImg);


	textureImg = SDL_CreateTexture(renderer, 
		SDL_PIXELFORMAT_RGB888, 
		SDL_TEXTUREACCESS_STATIC, 
		dimx, dimy);

	if(textureImg == NULL)
	{
		cout << "Echec de la création de la texture: " 
		<< SDL_GetError() << endl;
		afficherDetruit(canva, renderer, textureImg);
		exit(1);
	}

	unsigned int* pixels = new unsigned int[dimx * dimy];

	for(unsigned int i = 0; i < dimx * dimy; i++)
	{

		pixels[i] = (     255          << 24) | 
		(tab[i].getRouge() << 16) | 
		(tab[i].getVert () << 8)  |
		(tab[i].getBleu () << 0);
	}


	SDL_UpdateTexture(textureImg, NULL, 
		(const void*) pixels, sizeof(unsigned int) * dimx);

	delete[] pixels;

}


void Image::afficherBoucle(SDL_Window* canva, 
	SDL_Renderer* renderer, 
	SDL_Texture* textureImg) const
{    
	float zoom = 1.5;

	while(Event(zoom))
	{
		dessiner(canva, renderer, textureImg, zoom);
	}
}

//
void Image::afficherDetruit(SDL_Window*& canva, 
	SDL_Renderer*& renderer, 
	SDL_Texture*& textureImg) const
{
	if(canva != NULL)
		SDL_DestroyWindow(canva);
	if(renderer != NULL)
		SDL_DestroyRenderer(renderer);
	if(textureImg != NULL)
		SDL_DestroyTexture(textureImg);

	canva       = NULL;
	renderer     = NULL;
	textureImg = NULL;

	SDL_Quit();
}


//Procédure appliquant le zoom en redessinant l'image à chaque event.
void Image::dessiner(SDL_Window* canva,
	SDL_Renderer* renderer, 
	SDL_Texture* textureImg, 
	float zoom) const
{
	int w, h;
	SDL_GetWindowSize(canva, &w, &h);

	SDL_Rect rect;
	rect.x = w/2 - (zoom * dimx)/2;
	rect.y = h/2 - (zoom * dimy)/2;
	rect.w = zoom * dimx;
	rect.h = zoom * dimy;

	SDL_RenderClear(renderer);

	if(SDL_RenderCopy(renderer, textureImg, NULL, &rect) != 0)
	{
		cout << "Echec lors de l'ecriture: "
		<< SDL_GetError() << endl;
	}

	SDL_RenderPresent(renderer);
}


//Gestion des events (touches G,T,échap)
bool Image::Event(float& zoom) const
{
	const float ZOOM = 0.25;

	SDL_Event event;
	SDL_WaitEvent(&event);

	switch(event.type)
	{
		case SDL_KEYDOWN:
		{
			if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				return false;
			}

			if(event.key.keysym.scancode == SDL_SCANCODE_T)
			{
				zoom += ZOOM;
			}

			if(event.key.keysym.scancode == SDL_SCANCODE_G)
			{
				zoom -= ZOOM;

				if(zoom < 0.5) 
				{
					zoom = 0.5;
				}
			}
			break;
		}
		case SDL_QUIT:
		{
			return false;
		}
	}

	return true;
}
