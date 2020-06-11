/**
@file collision1.c
@brief test du code du collision
@date 06/06/2020
@version 1.0
@author amal
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
#include "collision1.h"
#include "perso.h"
#include "bg.h"

 int collision(SDL_Rect rec1,SDL_Rect rec2)
{
    if(rec1.y >= rec2.y + rec2.h)
        return 0;
    if(rec1.x >= rec2.x + rec2.w)
        return 0;
    if(rec1.y + rec1.h <= rec2.y)
        return 0;
    if(rec1.x + rec1.w <= rec2.x)
        return 0;
    return 1;
}
     


   SDL_Color GetPixel(SDL_Surface *x_background,int x,int y)
    {
        SDL_Color color;
        Uint32 col=0;
        //Determine position
        char* pPosition=(char* ) x_background->pixels;
        pPosition+= (x_background->pitch * (y));
        pPosition+= (x_background->format->BytesPerPixel *(x));
        memcpy(&col ,pPosition ,x_background->format->BytesPerPixel);
        //convertir color
        SDL_GetRGB(col,x_background->format, &color.r, &color.g, &color.b);
        return (color);
    }

void init(perssonage p,SDL_Rect pos[])
{
int x,y,w,h;

x= p.posperso.x;
y=  p.posperso.y;
w = 80;
h =  130;
//left
pos[0].x=x;
pos[0].y=y;

pos[1].x=x;
pos[1].y=y+h;

pos[2].x=x;
pos[2].y=y+h/2;
//right
pos[3].x=x+w;
pos[3].y=y;

pos[4].x=x+w;
pos[4].y=y+h;

pos[5].x=x+w;
pos[5].y=y+h/2;

//up
pos[6].x=x;
pos[6].y=y;

pos[7].x=x+w/2;
pos[7].y=y;

pos[8].x=x+w;
pos[8].y=y;

//down
pos[9].x=x;
pos[9].y=y+h;

pos[10].x=x+w/2;
pos[10].y=y+h;

pos[11].x=x+w;
pos[11].y=y+h;
}
int collision_right(background b,perssonage p)
    {
       
SDL_Rect pos[12];
int collision=0;
int i;
SDL_Color color;


init(p,pos);

for(i=3;i<6;i++)
{//printf("pos.x=%d et pos.y=%d\n",pos[i].x,pos[i].y);
//printf("n=%d",i+1);
 color=GetPixel(b.background_tile,pos[i].x,pos[i].y);
 if (color.r==255 && color.g==255 && color.b==255) collision=1;
}
//printf ("%d\n",collision);
return collision;

    }
int collision_left(background b,perssonage p)
    {
       
SDL_Rect pos[12];
int collision=0;
int i;
SDL_Color color;


init(p,pos);

for(i=0;i<3;i++)
{//printf("pos.x=%d et pos.y=%d\n",pos[i].x,pos[i].y);
//printf("n=%d",i+1);
 color=GetPixel(b.background_tile,pos[i].x,pos[i].y);
 if (color.r==255 && color.g==255 && color.b==255) collision=1;
}
//printf ("%d\n",collision);
return collision;

    }

int collision_top(background b,perssonage p)
    {
       
SDL_Rect pos[12];
int collision=0;
int i;
SDL_Color color;


init(p,pos);

for(i=6;i<9;i++)
{//printf("pos.x=%d et pos.y=%d\n",pos[i].x,pos[i].y);
//printf("n=%d",i+1);
 color=GetPixel(b.background_tile,pos[i].x,pos[i].y);
 if (color.r==255 && color.g==255 && color.b==255) {collision=1; }
}
//printf ("%d\n",collision);
return collision;

    }


int collision_down(background b,perssonage *p)
    {
       
SDL_Rect pos[12];
int collision=0;
int i;
SDL_Color color;


init(*p,pos);
for(i=9;i<12;i++)
{//printf("pos.x=%d et pos.y=%d\n",pos[i].x,pos[i].y);
//printf("n=%d",i+1);
 color=GetPixel(b.background_tile,pos[i].x,pos[i].y);
 if (color.r==255 && color.g==255 && color.b==255) 
{
collision=1;}

}
color=GetPixel(b.background_tile,pos[10].x,pos[10].y);
 if (color.r==255 && color.g==255 && color.b==255) 
p->posperso.y-=5;
//printf ("%d\n",collision);
return collision;


    }

int collision_mort(background b,perssonage p)
    {
       
SDL_Rect pos[12];
int collision=0;
int i;
SDL_Color color;


init(p,pos);
for(i=9;i<12;i++)
{//printf("pos.x=%d et pos.y=%d\n",pos[i].x,pos[i].y);
//printf("n=%d",i+1);
 color=GetPixel(b.background_tile,pos[i].x,pos[i].y);
 if (color.r==25 && color.g==33 && color.b==118) 
{
collision=1;}

}

return collision;


    }


int collision_gravite(background b,perssonage p)
    {
       
SDL_Rect pos;
int collision=0;
int x,y,w,h;

x= p.posperso.x;
y=  p.posperso.y;
w = 100;
h =  100;
SDL_Color color;
pos.x=x+w/2;
pos.y=y+h;


 color=GetPixel(b.background_tile,pos.x,pos.y);
 if (color.r==255 && color.g==255 && color.b==255) 
{
collision=1;}


return collision;


    }








int collision_enigme(background b,perssonage p)
    {
       
SDL_Rect pos[12];
int collision=0;
int i;
SDL_Color color;


init(p,pos);

for(i=0;i<12;i++)
{//printf("pos.x=%d et pos.y=%d\n",pos[i].x,pos[i].y);
//printf("n=%d",i+1);
 color=GetPixel(b.background_tile,pos[i].x,pos[i].y);
 if (color.r==24 && color.g==118 && color.b==56) collision=1;
}
//printf ("%d\n",collision);
return collision;

    }




