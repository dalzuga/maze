#include "../headers/demo.h"

int main(void)
{
	/* declarations */
	MazeStruct maze;

	/* inits */
	init_main(&maze);

	game_start(maze.instance);

	SDL_DestroyRenderer(maze.instance.renderer);
	SDL_DestroyWindow(maze.instance.window);
	SDL_Quit();

	return (0);
}
