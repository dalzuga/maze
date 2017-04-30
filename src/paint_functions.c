#include "../headers/demo.h"

/**
 * paint_environment - paints the environment from the player's POV
 *
 * @instance: SDL window and renderer instance
 * @map: address of map
 * @p: address of player
 *
 */
void paint_environment(SDL_Instance instance, int **map, GamePlayer *p)
{
	SDL_SetRenderDrawColor(instance.renderer, 0x80, 0x80, 0x80, 0xFF);
	/* SDL_RenderDrawLine(instance.renderer, 50, 100, 200, 400); */

	printf("---------------1--------------\n");
	printf("player: %p | map: %p\n", (void *) p, (void *) map);

	paint_walls(instance, map, p);
	print_calculations(map, p); /* if DEBUG equals 2 */
}

/**
 * paint_walls - paints the walls
 *
 * @instance: SDL window and renderer instance
 * @map: address of map
 * @p: address of player
 *
 */
void paint_walls(SDL_Instance instance __attribute__ ((unused)),
		 int **map __attribute__ ((unused)),
		 GamePlayer *p __attribute__((unused)))
{
	paint_projection(instance, map, p); /* call helper */
}

/**
 * paint_projection - paints the wall
 *
 * @instance: SDL window and renderer instance
 * @map: address of map
 * @p: address of player
 *
 */
void paint_projection(SDL_Instance instance __attribute__ ((unused)),
		      int **map __attribute__ ((unused)),
		      GamePlayer *p __attribute__((unused)))
{
	/* declarations */
	int i;
	double slice_height;
	double d_slice; /* distance to wall slice */
	double precompute[2];
	int top __attribute__ ((unused)), bottom __attribute__ ((unused));
	int px, py;

	/* inits */
	precompute[0] = WALL_HEIGHT * 277;

	calculate_pposition(map, p, &px, &py);

	for (i = 0; i < X_RES; i++)
	{
		d_slice = calculate_dslice(map, p, i, &px, &py);
		/* slice_height = WALL_HEIGHT / d_slice * 277; */
		slice_height = precompute[0] / d_slice; /* see ^^ */
		precompute[1] = slice_height / 2;
		top = Y_RES / 2 + precompute[1];
		bottom = Y_RES / 2 - precompute[1];
		if (DEBUG == 1)
		{
			printf("---------------4--------------\n");
			printf("slice_height: %f, top: %d, bottom: %d\n",
			       slice_height, top, bottom);
			printf("------------------------------\n");
			if (poll_events() == 1)
			{
				break;
			}
			usleep(5000);
			/* getline(NULL, 0, stdin); */
		}

		SDL_RenderDrawLine(instance.renderer, i, top, i, bottom);
		SDL_RenderPresent(instance.renderer);
	}
}
