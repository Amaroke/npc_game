/**
 *\file fonctions_SDL.h
 *\brief Déclaration des fonctions de la surcouche de la bibliothèque SDL2.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#ifndef FONCTIONS_SDL_H
#define FONCTIONS_SDL_H

//Constantes

#define SCREEN_WIDTH 992
#define COLUMN 31
#define SCREEN_HEIGHT 544
#define ROW 17
#define BLOC_SIZE 32

#include <SDL2/SDL.h>

/**
 * \brief La fonction initialise SDL et crée la fenêtre du jeu ainsi que l'affichage.
 * \param window La fenêtre du jeu.
 * \param renderer L'affichage.
 * \param width La largeur de l'écran de jeu.
 * \param height La hauteur de l'écran de jeu.
 * \return Une erreur en cas de problème.
*/
int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height);

/**
 * \brief La fonction nettoie l'affihage et la fenêtre du jeu en mémoire.
 * \param renderer L'affichage à nettoyer.
 * \param window La fenêtre à nettoyer.
*/
void clean_sdl(SDL_Renderer *renderer, SDL_Window *window);

/**
 * \brief La fonction charge l'image à partir d'un fichier.
 * \param file Le chemin de l'image à charger.
 * \param renderer Le renderer de l'écran.
 * \param r La valeur du rouge des pixels à régler invisible.
 * \param g La valeur du vert des pixels à régler invisible.
 * \param b La valeur du bleu des pixels à régler invisible.
*/
SDL_Texture *load_picture(const char *file, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b);

/**
 * \brief La fonction vide le contenu graphique de l'affichage lié à l'écran de jeu.
 * \param renderer l'affichage de l'écran.
*/
void clear_renderer(SDL_Renderer *renderer);

/**
 * \brief La fonction met à jour l'écran avec le contenu de l'affichage.
 * \param renderer l'affichage de l'écran.
*/
void update_screen(SDL_Renderer *renderer);

/**
 * \brief La fonction met le programme en pause pendant un laps de temps.
 * \param time Ce laps de temps en milliseconde.
*/
void pause(int time);

/**
 * \brief La fonction applique la texture.
 * \param texture La texture à appliquer.
 * \param renderer L'affichage sur lequel on applique la texture.
 * \param src Le rectangle source de la texture.
 * \param x Les abscisses.
 * \param y Les ordonnées.
*/
void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect src, int x, int y);

/**
 * \brief La fonction nettoie une texture en mémoire.
 * \param texture La texture à nettoyer.
*/
void clean_texture(SDL_Texture *texture);

#endif