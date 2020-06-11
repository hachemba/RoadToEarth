/**
@file scrolling.c
@brief test du code du scrolling
@date 06/06/2020
@version 1.0
@author amal
*/







#include "scrolling.h"

#include "bg.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include "perso.h"

void set_camera(SDL_Rect *camera,SDL_Rect posperso)
{
    camera->x = ( posperso.x + 100 / 2 ) - 1200 / 2;
    camera->y = ( posperso.y + 100/ 2 ) - 600 / 2;

     if( camera->x < 0 )
    {
        camera->x = 0;
    }
    if( camera->y < 0 )
    {
        camera->y = 0;
    }
    if( camera->x > 9000 - camera->w )
    {
        camera->x = 9000 - camera->w;
    }
    if( camera->y > 600 - camera->h )
    {
        camera->y = 600 - camera->h;
    }
}



