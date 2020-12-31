/**
 *\file vortex.c
 *\brief Définition des fonctions du vortex.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 31 décembre 2020
*/

#include "vortex.h"

// Constantes nb animation

SDL_Rect array_sprite[NB_ANIMATIONS_VORTEX] = {{0, 0, 32, 32}, {32, 0, 32, 32}, {64, 0, 32, 32}, {96, 0, 32, 32}, {0, 32, 32, 32}, {32, 32, 32, 32}, {64, 32, 32, 32}, {96, 32, 32, 32}};

void init_vortex(vortex_t *vortex)
{

for(int i = 0 ; i < NB_ANIMATIONS_VORTEX; i++)
{
    vortex->animation[i] = array_sprite[i];
}
    vortex->animation_speed = 2;
    vortex->frames = NB_ANIMATIONS_VORTEX;
    vortex->current_frame = 0;
}