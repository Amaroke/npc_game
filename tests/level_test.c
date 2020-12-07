/**
 *\file level_test.c
 *\brief Définition d'un environnement de tests.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 7 décembre 2020
*/


#include<stdlib.h>
#include<stdio.h>
#include"../affichage.h"
#include"../event.h"
#include"../fonctions_SDL.h"
#include"../jeu.h"
#include"../joueur.h"
#include"../ressources.h"
#include"../sprite.h"
#include"../terrain.h"


void test_init()
{
    SDL_Window **window;
    SDL_Renderer **renderer;
    ressources_t *ressources; 
    game_t * game;

    init(window, renderer, ressources, game);
    
}


/**
 *\brief Programme principal qui effectue les tests de sprite.
*/
int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}