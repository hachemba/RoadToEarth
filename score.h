/**
@file score.h
@brief test du code du score
@date 06/06/2020
@version 1.0
@author hachem 
*/



#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include<stdio.h>
#include"SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct 
{
int total;
char chaine[20];
SDL_Surface *texte;
SDL_Rect posScore;
TTF_Font *police;
SDL_Color couleurNoire;	
}score;



void init_score(score *sc);
void afficher_score(score sc,SDL_Surface *screen);







#endif
