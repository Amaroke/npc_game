/**
 *\file enemies.h
 *\brief Déclaration des fonctions de l'ennemi.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 janvier 2021
*/

#ifndef ENEMIES_H
#define ENEMIES_H

#define MOVING_STEP 1
#define ORIENTATION_ENEMY_DOWN 0
#define ORIENTATION_ENEMY_RIGHT 4
#define ORIENTATION_ENEMY_UP 8
#define ORIENTATION_ENEMY_LEFT 12
#define NB_ANIMATIONS_ENEMY 4

#include <SDL2/SDL.h>
#include "sprite.h"

typedef struct enemy_s
{
    sprite_t sprite;        /*!<Le sprite de l'ennemi.*/
    int orientation;        /*!<L'orientation de l'ennemi.*/
    int last_orientation;   /*!<La dernière orientation de l'ennemi.*/
    SDL_Rect animation[16]; /*!<Les sprites découpés des animations de l'ennemi.*/
    int animation_speed;    /*!<La vitesse d'animation.*/
    int current_frame;      /*!<La frame actuelle.*/
    int frames;             /*!<Le nombre de sprites que compose une animation complète.*/
    int frame;              /*!<Le calcul de la frame suivante.*/
    bool is_moving;         /*!<L'ennemi se déplace-t-il ?*/
    int movement;           /*!<Le nombre de déplacement restant au sprite avant une réorientation.*/
} enemy_t;

/**
*\brief La fonction initialise l'ennemi'.
*\param enemy L'ennemi à initialiser.
*\param x La coordonnée en abscisse.
*\param y La coordonnée en ordonnée.
*\param orientation L'orientation de l'ennemi.
*\param speed La vitesse de déplacement de l'ennemi.
*\param is_visible L'ennemi est visible.
*/
void init_enemy(enemy_t *enemy, int x, int y, int orientation, int speed, bool is_visible);

#endif