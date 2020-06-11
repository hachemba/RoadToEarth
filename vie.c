/**
@file vie.c
@brief test du code du vie de l'hero
@date 06/06/2020
@version 1.0
@author hachem 
*/



#include "vie.h"


/*
@brief initialisation du vie du personnage
@param une vie v
@return rien



*/

void init_vie(vie *v)
{
	v->nbrVie=3;
	v->heart=IMG_Load("vie/heart.png");
	v->posVie.x=1045;
	v->posVie.y=7;
}
/*
@brief affichage du vie
@param une vie v
@param une surface screen
@return rien



*/



void afficher_vie(vie v,SDL_Surface *screen)
{
	for (int i = 0; i < v.nbrVie; ++i)
	{
		SDL_BlitSurface(v.heart, NULL,screen,&v.posVie);
		v.posVie.x+=53;
		
	}


}
