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

	/* check #define'd values */
	if (check_edge_cases() != 0)
		exit_function(maze);

	/* allocate and init map and player */
	game_init_params(&(maze->map), &(maze->p));
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
	int coord[2] = {START_X, START_Y};
	int i;

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

	for (i = 0; i < 2; i++)
	{
		if (coord[i] < BLOCK_UNITS)
		{
			printf("Player inside border wall.\n");
			return (1);
		}
	}

	if (START_X >= BLOCK_UNITS * (MAP_COLS - 1))
	{
			printf("Player inside border wall.\n");
			return (1);
	}

	if (START_Y >= BLOCK_UNITS * (MAP_ROWS - 1))
	{
			printf("Player inside border wall.\n");
			return (1);
	}

	return (0);
}

/**
 * game_init_params - allocates and initializes a map and player. Both must be
 * freed by the user of this function.
 *
 * @map: address of map
 * @p: address of player
 *
 * Return: Nothing.
 */
void game_init_params(GameMap **map, GamePlayer **p)
{
	*map = make_map(MAP_ROWS, MAP_COLS);
	/*
	 * Debug problem found
         * (*map)->array[1][1] = 0;
	 * (*map)->array[1][2] = 0;
	 * (*map)->array[2][2] = 0;
         */

	*p = malloc(sizeof(GamePlayer));
	if (*p == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	(*p)->px = START_X;
	(*p)->py = START_Y;
	(*p)->theta = START_THETA;

	(*p)->x = (*p)->px / BLOCK_UNITS;
	(*p)->y = (*p)->py / BLOCK_UNITS;

	/* set distance to projector plane */
	(*p)->dpp = X_RES / 2 / tan((FOV_ANGLE / 2) * M_PI / 180);
}
