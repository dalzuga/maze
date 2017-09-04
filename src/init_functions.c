#include "../headers/demo.h"

/**
 * init function - allocates and initializes all the members of the maze struct
 * @maze: pointer to the maze struct
 */
void init_main(MazeStruct *maze)
{
	/* start SDL window and renderer */
	if (init_instance(&(maze->instance)) != 0)
		exit(2);

	if (DEFAULT_MAP)
	{
		/* check #define'd values */
		if (check_hardcoded_values() != 0)
			exit_function(maze);

		/* allocate and init map and player */
		game_init_params(&(maze->map), &(maze->p));

		/* load default map */
		default_map(maze->map);
	}
	else
	{
		if (load_map(maze, maze->map) == 1)
		{
			perror("load_map");
			exit(2);
		}
	}
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
