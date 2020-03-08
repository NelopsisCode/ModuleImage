#include "Image.h"

int main (int argc, char** argv) {
	
   //Affichage de base
	Image image (10,10);
	
	
	Pixel noir (0, 0, 0);
	Pixel vert (0, 192, 0);
	Pixel cyan (128, 255, 255);
	
	image.effacer(noir);
	image.dessinerRectangle(3, 0, 5, 2, vert);
	image.dessinerRectangle(1, 4, 7, 4, vert);
	image.dessinerRectangle(4, 3, 4, 6, vert);
	image.dessinerRectangle(3, 6, 3, 9, vert);
	image.dessinerRectangle(5, 6, 5, 9, vert);
	image.setPix(1,2,vert);
	image.setPix(1,3,vert);
	image.setPix(7,2,vert);
	image.setPix(7,3,vert);
	image.setPix(2,9,vert);
	image.setPix(6,9,vert);
	image.setPix(3,1,cyan);
	image.setPix(5,1,cyan);
	
    //image.afficher();

   //Affichage de Steve
	Image steve (16,28);


	Pixel blanc(255,255,255);
	Pixel bleu(0,128,255);
	Pixel marron(88,41,0);
	Pixel marron2(153,76,0);
	Pixel beige(255,204,153);
	Pixel violet(127,0,255);
	Pixel violet2(102,0,204);
	Pixel gris(96,96,96);

	steve.effacer(Pixel(102,255,255));
	steve.dessinerRectangle(4,0,11,1,marron);
	steve.dessinerRectangle(4,2,11,7,beige);
	steve.dessinerRectangle(0,8,15,11,bleu);
	steve.dessinerRectangle(0,12,3,19,beige);
	steve.dessinerRectangle(12,12,15,19,beige);
	steve.dessinerRectangle(4,12,11,18,bleu);
	steve.dessinerRectangle(4,18,11,25,violet);
	steve.dessinerRectangle(4,26,11,27,gris);
	steve.setPix(4,2,marron);
	steve.setPix(11,2,marron);
	steve.setPix(6,4,violet2);
	steve.setPix(5,4,blanc);
	steve.setPix(9,4,violet2);
	steve.setPix(10,4,blanc);
	steve.dessinerRectangle(7,5,8,6,marron2);
	steve.setPix(6,6,marron2);
	steve.setPix(9,6,marron2);
	steve.dessinerRectangle(7,8,8,9,beige);
	steve.setPix(6,8,beige);
	steve.setPix(9,8,beige);
	steve.setPix(9,18,violet2);
	steve.setPix(10,19,violet2);
	steve.setPix(10,18,bleu);
	steve.setPix(11,18,bleu);
	steve.setPix(11,19,bleu);
	steve.dessinerRectangle(5,22,6,22,violet2);
	steve.dessinerRectangle(9,22,10,22,violet2);
	steve.afficher(); 
	
	return 0;    
}