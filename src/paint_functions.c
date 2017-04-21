#include "../headers/demo.h"

/**
 * paint - paints the environment symbolized by the map
 *
 */
void paint_environment(SDL_Instance instance, int **map, GamePlayer *p)
{
	SDL_SetRenderDrawColor(instance.renderer, 0x80, 0x80, 0x80, 0xFF);
	SDL_RenderDrawLine(instance.renderer, 50, 100, 200, 400);

	printf("player: %p", (void *) p);
	printf("map: %p", (void *) map);
}
