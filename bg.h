
/**
@file bg.c
@brief test du code du background
@date 06/06/2020
@version 1.0
@author amal
*/



#ifndef BG_H_INCLUDED
#define BG_H_INCLUDED
#include<stdio.h>
#include"SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct  background
{

	    SDL_Surface *background;
            SDL_Surface *background_tile;
	    //SDL_Rect camera;
	    SDL_Rect posbg;
}background;
void initialiser_background (background *b);
void afficher_background (SDL_Surface *screen,background b,SDL_Rect camera);

#endif // BG_H_INCLUDED
