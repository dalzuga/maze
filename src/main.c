#include "../headers/demo.h"

int main(void)
{
	/* declarations */
	MazeStruct maze;

	/* inits */
	maze.map = NULL;
	maze.p = NULL;
	maze.instance.window = NULL;
	maze.instance.renderer = NULL;

	init_main(&maze);

	game_main(&maze);

	return (0);
}

void exit_function(MazeStruct *maze)
{
	SDL_DestroyRenderer(maze->instance.renderer);
	SDL_DestroyWindow(maze->instance.window);
	SDL_Quit();

	exit(1);
}
