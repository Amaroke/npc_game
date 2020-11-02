/**
 *\file sprite.h
 *\brief Bibliothèque des sprites.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 nov 2020
*/

#ifndef SPRITE_H
#define SPRITE_H

typedef struct sprite_s
{
    int x; /*!< Abscisses par rapport au centre de l'image.*/
    int y; /*!< Ordonnée par rapport au centre de l'image. */
    int h; /*!< Hauteur du sprite. */
    int w; /*!< Largeur du sprite. */
    int v; /*!< Vitesse de déplacement du sprite. */
} sprite_t;

void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v);

void print_sprite(sprite_t *sprite);

#endif