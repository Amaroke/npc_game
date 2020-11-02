/**
 *\file sprite.h
 *\brief Bibliothèque de sprite.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 13 mai 2020
*/

#ifndef SPRITE_H
#define SPRITE_H
#include "biblio.h"

/**
 *\struct sprite_t 
 *\brief Représentation d'un sprite.
*/
typedef struct sprite_s
{
	int x;			/*!< Abscisses par rapport au centre de l'image.*/
	int y;			/*!< Ordionnée par rapport au centre de l'image. */
	int h;			/*!< Hauteur du sprite. */
	int w;			/*!< Largeur du sprite. */
	int v;			/*!< Vitesse de déplacement verticale. */
	int is_visible; /*!< Visibilité du sprite. */
	int hp;			/*!< Points de vie du sprite. */
} sprite_t;

/**
 *\brief La fonction initialise le sprite.
 *\param x La position en abcisse.
 *\param y La position en ordonnée.
 *\param w La largeur.
 *\param h La hauteur.
 *\param v La vitesse verticale.
 *\param visible La visibilité.
 *\param hp Les points de vie.
*/
void init_sprite(sprite_t *sprite, int x, int y, int w, int h, int v, int visible, int hp);

/**
 *\brief La fonction affiche le sprite.
 *\param sprite Le sprite.
*/
void print_sprite(sprite_t *sprite);

/**
 *\brief La fonction définit le sprite comme invisible.
 *\param sprite Le sprite.
*/
void set_invisible(sprite_t *sprite);

/**
 *\brief La fonction définit le sprite comme visible.
 *\param sprite Le sprite.
*/
void set_visible(sprite_t *sprite);

#endif