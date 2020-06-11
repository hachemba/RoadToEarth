/**
@file scrolling.h
@brief test du code scrolling.h
@date 06/06/2020
@version 1.0
@author amal
*/





#ifndef SCROLLING_H_INCLUDED
#define SCROLLING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "bg.h"

void set_camera(SDL_Rect *camera,SDL_Rect posperso);
#endif // SCROLLING_H_INCLUDED
