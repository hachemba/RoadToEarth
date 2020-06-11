/**
@file score.c
@brief test du code du score
@date 06/06/2020
@version 1.0
@author hachem 
*/





#include<stdio.h>
#include"SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "score.h"

/*
@brief initialisation du score
@param score sc
@return rien
*/

void init_score(score *sc)
{
     
	sc->total=0000;
        sc->texte= NULL;
        sc->police= NULL;
        sc->couleurNoire.r=255;
        sc->couleurNoire.g=255;
        sc->couleurNoire.b=255;
	sc->posScore.x=0;
	sc->posScore.y=0;
        sc->police=TTF_OpenFont("font.ttf", 65);
        sprintf (sc->chaine,"[%d]",sc->total);
        sc->texte=TTF_RenderText_Blended(sc->police,sc->chaine,sc->couleurNoire);
 
}
/*
@brief l'affichage du score
@param le score sc
@param screen surface
@return rien



*/

void afficher_score(score sc,SDL_Surface *screen)
{
                sprintf (sc.chaine,"[%d]",sc.total);
                 sc.texte=TTF_RenderText_Blended(sc.police,sc.chaine,sc.couleurNoire);
                 SDL_BlitSurface(sc.texte,NULL,screen,&sc.posScore);
}
