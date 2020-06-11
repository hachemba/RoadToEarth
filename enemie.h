/**
@file enemie.h
@brief test du code de l'enemie.h
@date 06/06/2020
@version 1.0
@author hachem 
*/





#ifndef DS7_H_INCLUDED
#define DS7_H_INCLUDED

#define DIRECTIONS_ENEMIE 2
#define NBR_FRAMES 3
typedef struct enemie
{
SDL_Surface *enemie;
SDL_Rect PosEnemie;
SDL_Rect clips[DIRECTIONS_ENEMIE][NBR_FRAMES];
int frame;
int direction;
int moving;
int state;
int onground;
}enemie;

void set_clips(enemie *E);
void inisialiser_enemie (enemie *E);
void MoveEnnemi(enemie *E);
void update_ennemi(enemie *E);
void afficher_enemie (enemie *E,SDL_Surface *screen,SDL_Rect camera);
void animation (enemie *E);


 #endif // DS_H_INCLUDED
