#include "../headers/demo.h"

/**
 *
 *
 */
void draw_stuff(SDL_Instance instance)
{
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(instance.renderer, 50, 100, 200, 400);
}

/**
 * draw_column - draws a line from top to bottom in SDL renderer, with
 * y-coordinate increasing downwards (this behavior is dependent on SDL 2.0)
 *
 * @maze: pointer to the maze struct
 * @top: integer
 * @bottom: integer
 */
void draw_column(MazeStruct *maze, int x, int top, int bottom)
{
	SDL_RenderDrawLine(maze->instance.renderer, x, top, x, bottom);
}
