
/**
@file coin.h
@brief test du code coin
@date 06/06/2020
@version 1.0
@author hachem 
*/



#ifndef COIN_H_INCLUDED
#define COIN_H_INCLUDED




typedef struct  coin
{
	SDL_Surface *tab[8];
	SDL_Rect pos;
	int frame;
}coin;

void init_coin(coin *c,int x, int y);
void animer_coin(coin *c);
void afficher(coin c,SDL_Surface *screen,SDL_Rect camera);
  #endif // DS_H_INCLUDED
