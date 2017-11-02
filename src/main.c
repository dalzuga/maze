#include "../headers/demo.h"

/**
 * main - main program entry point
 *
 * Return: 0 on success;
 */
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

/**
 * exit_function - main program exit point
 */
void exit_function(MazeStruct *maze)
{
	SDL_DestroyRenderer(maze->instance.renderer);
	SDL_DestroyWindow(maze->instance.window);
	SDL_Quit();

	exit(1);
}
