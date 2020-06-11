/**
@file perso.c
@brief test du code du personnage
@date 06/06/2020
@version 1.0
@author hachem et amal
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
#include "perso.h"
#include "vie.h"
#include"score.h"
/*
@brief nombre de frame du personnages
@param personnage p
@return nmbre de frame


*/
int nb_frames_p=10;

void setrects(perssonage *p)
{

int i=0,j=0;


for(i=0;i<4;i++)
{
    for(j=0;j<10;j++)
    {
    p->rects[ i ][ j ].x = 80 * j;
    p->rects[ i ][ j ].y = 150 * i;
    p->rects[ i ][ j ].w = 80;
    p->rects[ i ][ j ].h =150;

    }

}
}
/*
@brief initialisation du personnage
@param un personnage p
@return rien
*/

void initialiser_perssonage (perssonage *p)
 {
p->onground=1;  //position  initiale
p->vitesse.x=0;
p->vitesse.y=0;
p->perssonage=IMG_Load("hero.png");
p->frame=1;
p->direction=0; //stable right
p->posperso.x=10;
p->posperso.y=370;
p->posperso.w=80;
p->posperso.h=150;
init_vie(&p->Vie);
init_score(&p->Score);
setrects (p);
}

/*
@brief animation du personnage
@param personnage p
@return rien

*/
void animer_perso(perssonage *p)
{



p->frame++;
if(p->frame==10)
{
p->frame=0;
}


}

/*
@brief mouvement du personnage
@param un personnage p
@return rien

*/
void mouvementright (perssonage *p,int *startTicks)
{
p->direction=2;
int tempsActuel;
tempsActuel=SDL_GetTicks();
if(tempsActuel- *startTicks>=300)
{*startTicks=tempsActuel;
p->vitesse.x+=1;
}
if(p->vitesse.x>=20)
{
p->vitesse.x=20;
}
if(p->onground==0){
p->posperso.x+=p->vitesse.x;
p->posperso.y+=p->vitesse.y;}
else
{p->posperso.x+=p->vitesse.x;}




}
void mouvementleft (perssonage *p,int *startTicks)
{
p->direction=3;
int tempsActuel;
tempsActuel=SDL_GetTicks();
if(tempsActuel- *startTicks>=300)
{
*startTicks=tempsActuel;
p->vitesse.x-=1;
}
if(p->vitesse.x<=-20)
{
p->vitesse.x=-20;
}
if(p->onground==0){
p->posperso.x+=p->vitesse.x;
p->posperso.y+=p->vitesse.y;}
else
{p->posperso.x+=p->vitesse.x;}

}
/*
@brief mouvement bas
@param personnage p
return rien


*/

void mouvementdown (perssonage *p)
{
p->posperso.y+=p->vitesse.y;
p->direction=0;
}



/*
@brief le saut du charactere
@param personnage p
@return rien

*/
void mouvementjump (perssonage *p)
{

p->posperso.y+=p->vitesse.y;
p->direction=0; 
}

/*
@brief affichage du personnage
@param personnage p
@param surface  screen
@param parametre de la poition de la camera

*/

void afficher_perssonage (perssonage p,SDL_Surface *screen,SDL_Rect camera)
 { 
        SDL_Rect pos;        
        pos.x=p.posperso.x-camera.x;
        pos.y=p.posperso.y-camera.y;
    SDL_BlitSurface(p.perssonage,&p.rects[p.direction][p.frame],screen,&pos);
  
 }

 
                     
