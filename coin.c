/**
@file coin.c
@brief test du code coin
@date 06/06/2020
@version 1.0
@author hachem 
*/



#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "coin.h"

/**
@brief initialiser le tableau d'image du coin
@param coin c
@param l'abscisse x du coin 
@param l'ordonnée y du coin
@return rien

*/
void init_coin(coin *c,int x,int y)
{
	c->tab[0]=IMG_Load("coin/coin1.png");
	c->tab[1]=IMG_Load("coin/coin2.png");
	c->tab[2]=IMG_Load("coin/coin3.png");
	c->tab[3]=IMG_Load("coin/coin4.png");
	c->tab[4]=IMG_Load("coin/coin5.png");
	c->tab[5]=IMG_Load("coin/coin6.png");
	c->tab[6]=IMG_Load("coin/coin7.png");
	c->tab[7]=IMG_Load("coin/coin8.png");

	c->pos.x=x;
	c->pos.y=y;
        c->pos.w=41;
	c->pos.h=42;
	c->frame=0;
}
/********************************************************************************************************/
/********************************************************************************************************/


/*
@brief l'animation du mouvement du coin
@param coin c 
@return rien
*/
void animer_coin(coin *c)
{
	//SDL_Delay(40);
	if(c->frame==7)
		c->frame=0;
	else
		c->frame++;
}
/*

@brief l'affichage du coin
@param coin c
@param screen surface
@param parametre du camera
@return rien

*/
void afficher(coin c,SDL_Surface *screen,SDL_Rect camera)
{
	
		 SDL_Rect pos;
                pos.x=c.pos.x-camera.x;
                 pos.y=c.pos.y-camera.y;
		
		 SDL_BlitSurface(c.tab[c.frame],NULL,screen,&pos);

}
