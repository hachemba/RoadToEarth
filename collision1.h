/**
@file collision1.h
@brief test du code du  collision
@date 06/06/2020
@version 1.0
@author amal
*/






#ifndef COLLISION1_H_INCLUDED
#define COLLISION1_H_INCLUDED
#include "perso.h"
#include "bg.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int 
collision(SDL_Rect rec1,SDL_Rect rec2);


void init(perssonage p,SDL_Rect pos[]);

int collision_right(background b,perssonage p);
int collision_left(background b,perssonage p);
int collision_top(background b,perssonage p);
int collision_down(background b,perssonage *p);
SDL_Color GetPixel(SDL_Surface *x_background,int x,int y);
int collision_gravite(background b,perssonage p);

int collision_mort(background b,perssonage p);

   
 int collision_enigme(background b,perssonage p);
 


  #endif // DS_H_INCLUDED

