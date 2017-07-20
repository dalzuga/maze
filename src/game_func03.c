#include "../headers/demo.h"

/**
 * set_wcolor - sets the wall color
 *
 * @instance: SDL window and renderer instance
 * @map: the current map
 * @p: the player struct
 *
 * Return: Nothing.
 */
void set_wcolor(SDL_Instance instance, int r, int g, int b)
{
	SDL_SetRenderDrawColor(instance.renderer, r, g, b, 0xFF);
}
