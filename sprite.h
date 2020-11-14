/**
 *\file sprite.h
 *\brief Bibliothèque des sprites.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 nov 2020
*/

#ifndef SPRITE_H
#define SPRITE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct sprite_s
{
    int x; /*!< Abscisses par rapport au centre de l'image.*/
    int y; /*!< Ordonnée par rapport au centre de l'image. */
    int h; /*!< Hauteur du sprite. */
    int w; /*!< Largeur du sprite. */
    int v; /*!< Vitesse de déplacement du sprite. */
    bool is_visible; /*!< Le sprite est visible ou non. */
} sprite_t;

/**
 *\brief La fonction initialise un sprite.
 *\param sprite Le sprite à initialiser.
 *\param x L'abscisse.
 *\param y L'ordonnée.
 *\param w La largeur.
 *\param h La hauteur.
 *\param v La vitesse.
 *\param is_visible La visibilité du sprite.
*/
void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v, bool is_visible);

/**
 *\brief La fonction affiche les données d'un sprite dans le terminal.
 *\param sprite Le sprite à afficher.
*/
void print_sprite_test(sprite_t *sprite);

#endif