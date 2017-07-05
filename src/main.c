#include "../headers/demo.h"

int main(void)
{
	/* declarations */
	MazeStruct maze;
	int i;

	/* inits */
	init_main(&maze);

	SDL_SetRenderDrawColor(maze.instance.renderer, 0x80, 0x80, 0x80, 0xFF);
	for (i = 0; i < 40; i++)
	{
		usleep(1000);
		draw_column(&maze, i * 6, 10, 120);
		SDL_RenderPresent(maze.instance.renderer);
	}

	game_main(maze.instance);

	return (0);
}

void exit_function(MazeStruct *maze)
{
	SDL_DestroyRenderer(maze->instance.renderer);
	SDL_DestroyWindow(maze->instance.window);
	SDL_Quit();

	exit(1);
}
