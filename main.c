
/**
@file main.c
@brief le menu du jeu
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
#include "bg.h"
#include "vie.h"
#include "score.h"
#include "enemie.h"
#include "perso.h"
#include "scrolling.h"
#include "collision1.h"
#include "coin.h"
#include "enigme.h"

int main ()
{

  
    int done=1,collision1,collision2,collision3,collision4,collision5,startTicks,collision6,collision_enig;
    int collision_coin1,collision_coin2;
     char image[20];
    enigme e;
    int alea,solution,r,running=0,run=0;
    init_enigme(&e);
    perssonage p;
    background b;
   
  enemie E;
  set_clips(&E);
   inisialiser_enemie (&E);
    SDL_Event event;
    SDL_Rect camera= {0,0,1200,600};
    SDL_Surface *screen=NULL;

    screen = SDL_SetVideoMode(1200, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    
  
    
    initialiser_background (&b);
    initialiser_perssonage (&p);

    coin c1,c2;
    SDL_Rect poscoin1,poscoin2;
    poscoin1.x=300;
    poscoin1.y=100;
    poscoin2.x=550;
    poscoin2.y=250;
    init_coin(&c1,poscoin1.x,poscoin1.y);
    init_coin(&c2,poscoin2.x, poscoin2.y);
     score sc;
    init_score(&sc);

    while(done)
    {
    

         while( SDL_PollEvent(&event))
{
        switch(event.type)
        {
            case SDL_QUIT:
                done = 0;
                break;
             case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    startTicks=SDL_GetTicks();
                    p.vitesse.x=10;
                    break;
                case SDLK_LEFT :
                     startTicks=SDL_GetTicks();
                    p.vitesse.x=-10;
                    break;
                case SDLK_UP :
                    p.onground=0;
                    p.vitesse.y=-20;
                    break;
                case SDLK_DOWN :
                    p.vitesse.y=10;
                    break;

                case SDLK_ESCAPE :
               
                    done=0;
                
                break;
               
                case SDLK_z : //up

                    p.onground=0;
                    p.vitesse.y=-20;
                    break;
                case SDLK_x : //down

                    p.vitesse.y=10;
                    break;
                case SDLK_d : //right

                    p.vitesse.x=10;
                    break;
                case SDLK_q : //left

                    p.vitesse.x=-10;
                    break;

                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
               
                case SDLK_ESCAPE :

                    done=0;
                    break;
                case SDLK_d : //right

                    p.vitesse.x=0;
                    break;
                case SDLK_q : //left

                    p.vitesse.x=0;
                    break;
                case SDLK_x : //down

                    p.vitesse.y=0;
                    break;
                case SDLK_RIGHT:
                    p.vitesse.x=0;
                    break;

                case SDLK_LEFT :
                    p.vitesse.x=0;
                    break;
                case SDLK_DOWN :
                    p.vitesse.y=0;
                    break;

                }
              break;
        }
 }

  collision1=collision_right( b, p);
   collision2=collision_left(b,p);
  collision3=collision_top( b, p);
 collision4=collision_down( b,&p);
 collision5=collision_mort( b, p);
collision6=collision_gravite( b, p);
 SDL_Rect coin1= {c1.pos.x,c1.pos.y,c1.pos.w,c1.pos.h};
        SDL_Rect coin2= {c2.pos.x,c2.pos.y,c2.pos.w,c2.pos.h};
        collision_coin1=collision(coin1,p.posperso);
        collision_coin2=collision(coin2,p.posperso);
        collision_enig=collision_enigme( b,p);

 if(collision4==0 && p.vitesse.y>0)
        {
            p.vitesse.y=0;
        }
if(collision6==0)
        {
            p.vitesse.y+=4;// gravity 
        }
  if ( p.vitesse.x>0 && collision1==0)
        {    animer_perso (&p);
            mouvementright (&p,&startTicks);
           
        }
        else if (p.vitesse.x<0 && collision2==0 )
        { animer_perso  (&p);

            mouvementleft (&p,&startTicks);
           
        }
        else if (p.vitesse.y<0 && collision3==0 )
        {  animer_perso  (&p);
            mouvementjump (&p);
            

        }
        else if (p.vitesse.y>0 && collision4==0)
        {
             animer_perso (&p);
            mouvementdown (&p);
        }
        if(collision_coin1==1)
        {
          
            sc.total=sc.total+10;
            c1.pos.x+=1300;
            c1.pos.y-=10;

        }
        if(p.posperso.x>c1.pos.x+c1.pos.w+500)
        {
            c1.pos.x+=1300;
            c1.pos.y-=10;
        }

        if(collision_coin2==1)
        {
          
            sc.total=sc.total+10;
            c2.pos.x+=1300;
              c2.pos.y-=10;
        }
        if(p.posperso.x>c2.pos.x+c2.pos.w+500)
        {
            c2.pos.x+=1300;
              c2.pos.y-=10;
        }
if(collision5==1)
{
p.posperso.x-=100;
SDL_Delay(100);
p.Vie.nbrVie--;

}
if(collision_enig==1)
{
generate_afficher (screen, image,&e,&alea);
    solution=solution_e(image);
    resolution(&r);
    afficher_resultat (screen,solution,r,&e);
p.posperso.x+=100;
p.vitesse.x=0;
p.vitesse.y=0;

}
     
      
         set_camera(&camera,p.posperso);
         afficher_background (screen,b,camera); 
         afficher_perssonage ( p,screen, camera);
        afficher_vie(p.Vie,screen);
         update_ennemi(&E);
        MoveEnnemi(&E);
       afficher_enemie (&E,screen,camera);
         animation (&E);
        afficher(c1,screen,camera);
        afficher(c2,screen,camera);
        animer_coin(&c1);
        animer_coin(&c2);
        afficher_score(sc,screen); // y a un ptit prob ici
        SDL_Flip(screen);
        SDL_Delay(10);
      }

    

    return 0;
}












