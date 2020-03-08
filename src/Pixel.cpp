#include "Pixel.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


Pixel::Pixel(){

	r = 255;
	g = 255;
	b = 255;
}


Pixel::Pixel(unsigned char nr,unsigned char ng,unsigned char nb){

	r = nr;
	g = ng;
	b = nb;
}

	//accesseurs
unsigned char Pixel::getRouge()const{ return r;}
unsigned char Pixel::getVert()const{ return g;}
unsigned char Pixel::getBleu()const{ return b;}

	//mutateur
void Pixel::setRouge(unsigned char nr){ r = nr;}
void Pixel::setVert(unsigned char ng){ g = ng;}
void Pixel::setBleu(unsigned char nb){ b = nb;}
