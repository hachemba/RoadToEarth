/**
@file bg.c
@brief test du code bg
@date 06/06/2020
@version 1.0
@author amal
*/





#include "bg.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

void initialiser_background(background *b)
{
b->background=NULL;
b->background=IMG_Load("bg.png");
b->background_tile=NULL;
b->background_tile=IMG_Load("2001.png"); 


}
void afficher_background (SDL_Surface *screen,background b,SDL_Rect camera)
{

SDL_BlitSurface(b.background,&camera,screen,NULL);
}


