/**
 *\file fonctions_SDL.h
 *\brief Surcouche de la bibliothèque SDL2.
 *\author MOSELLE Marie-Luc & MATHIEU STEINBACH Hugo
 *\date 2 novembre 2020
*/

#ifndef FONCTIONS_SDL_H
#define FONCTIONS_SDL_H

#include <SDL2/SDL.h>

/**
 * \brief La fonction initialise la SDL et crée la fenêtre du jeu ainsi que le renderer.
 * \param window la fenêtre du jeu.
 * \param renderer le renderer.
 * \param width largeur de l'écran de jeu.
 * \param height hauteur de l'écran de jeu.
 * \return -1 en cas d'erreur, 0 sinon
*/
int init_sdl(SDL_Window **window, SDL_Renderer **renderer, int width, int height);

/**
 * \brief La fonction charge l'image à partir d'un fichier.
 * \param nomfichier le chemin de l'image à charger.
 * \param renderer le renderer de l'écran.
 * \param r la couleur rouge.
 * \param g la couleur verte.
 * \param b la couleur bleue.
*/
SDL_Texture *charger_image(const char *nomfichier, SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b);

/**
 * \brief La fonction vide le contenu graphique du renderer lié à l'écran de jeu.
 * \param renderer le renderer de l'écran.
*/
void clear_renderer(SDL_Renderer *renderer);

/**
 * \brief La fonction met à jour l'écran avec le contenu du renderer.
 * \param renderer le renderer de l'écran.
*/
void update_screen(SDL_Renderer *renderer);

/**
 * \brief La fonction met le programme en pause pendant un laps de temps.
 * \param time ce laps de temps en milliseconde.
*/
void pause(int time);

/**
 * \brief La fonction nettoie le renderer et la fenêtre du jeu en mémoire.
 * \param renderer le renderer à nettoyer.
 * \param window la fenêtre à nettoyer.
*/
void clean_sdl(SDL_Renderer *renderer, SDL_Window *window);

/**
 * \brief La fonction applique la texture.
 * \param texture la texture à appliquer.
 * \param renderer le renderer sur lequel on applique la texture.
 * \param x l'abscisse du renderer où on place la texture.
 * \param y l'ordonnée du renderer où on place la texture.
*/
void apply_texture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y);

/**
 * \brief La fonction nettoie une texture en mémoire
 * \param texture la texture à nettoyer
*/
void clean_texture(SDL_Texture *texture);

#endif