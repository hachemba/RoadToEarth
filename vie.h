/**
@file vie.h
@brief test du code de vie
@date 06/06/2020
@version 1.0
@author hachem 
*/





#ifndef VIE_H_INCLUDED
#define VIE_H_INCLUDED
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 


typedef struct 
{
int nbrVie;
SDL_Surface * heart;
SDL_Rect posVie;	
}vie;



void init_vie(vie *v);
void afficher_vie(vie v,SDL_Surface *screen);







#endif
