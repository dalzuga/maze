#include "../headers/demo.h"

/**
 * init function - allocates and initializes all the members of the maze struct
 * @maze: pointer to the maze struct
 */
void init_main(MazeStruct *maze)
{
	if (init_instance(&(maze->instance)) != 0)
		exit(2);

	if (check_edge_cases() != 0)
		exit_function(maze);
}

int init_instance(SDL_Instance *instance)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n",
			SDL_GetError());
		return (1);
	}

	/* Create a new window instance */
	instance->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED,
					    SDL_WINDOWPOS_CENTERED,
					    X_RES,
					    Y_RES, 0);

	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return (1);
	}

	/* Create a new Renderer instance linked to the window */
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
						SDL_RENDERER_ACCELERATED |
						SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n",
			SDL_GetError());
		SDL_Quit();
		return (1);
	}
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
		printf("Undefined game parameters.\n");
		return (1);
	}

	if (MAP_ROWS < 3 || MAP_COLS < 3)
	{
		printf("Insufficient map size.\n");
		return (1);
	}

	return (0);
}
