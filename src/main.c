#include "../headers/demo.h"

int main(void)
{
	/* declarations */
	MazeStruct maze;

	init_function(&maze);

	/* inits */
	if (init_instance(&instance) != 0)
		return (1);

	if (check_edge_cases() != 0)
	{
		return (1);
	}

	game_start(instance);

	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();

	return (0);
}

/**
 * check_edge_cases - check game parameters before running
 *
 * Return: 0 on success, 1 on failure.
 */
int check_edge_cases(void)
{
	if (X_RES <= 0 || Y_RES <= 0)
	{
		printf("Wrong resolution.\n");
		return (1);
	}

	if (FOV_ANGLE <= 0 || BLOCK_UNITS <= 0 || WALL_HEIGHT <= 0)
	{
		printf("Wrong game parameters.\n");
		return (1);
	}

	if (MAP_ROWS < 3 || MAP_COLS < 3)
	{
		printf("Wrong game parameters.\n");
		return (1);
	}

	return (0);
}
