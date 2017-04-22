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
	SDL_RenderDrawLine(instance.renderer, 50, 100, 200, 400);

	printf("player: %p | map: %p\n", (void *) p, (void *) map);

	paint_walls(instance, map, p);
	paint_calculations(map, p);
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
	int slice_height;
	long unsigned int d_slice; /* distance to wall slice */
	long unsigned int precompute[2];
	int top __attribute__ ((unused)), bottom __attribute__ ((unused));

	precompute[0] = WALL_HEIGHT * 277;

	for (i = 0; i < X_RES; i++)
	{
		d_slice = calculate_dslice(map, p, i);
		/* slice_height = WALL_HEIGHT / d_slice * 277; */
		slice_height = precompute[0] / d_slice; /*see ^^ above comment*/
		precompute[1] = slice_height / 2;
		top = Y_CENTER + precompute[1];
		bottom = Y_CENTER - precompute[1];
		/* if (DEBUG == 1) */
		/* { */
		/* 	printf("top: %d, bottom: %d\n", top, bottom); */
		/* 	usleep(50000); */
		/* 	/\* getline(NULL, 0, stdin); *\/ */
		/* } */
	}
}

/**
 * paint_calculations - gets necessary calculations
 *
 *
 */
void paint_calculations(int **map __attribute__((unused)), GamePlayer *p)
{
	int start_angle, end_angle;
	int alpha;		    /* alpha is the angle of the ray being
				       cast */

	start_angle = p->theta - FIELD_ANGLE / 2;
	end_angle = p->theta + FIELD_ANGLE / 2;
	alpha = 90 - start_angle;

	if (DEBUG)
	{
		printf("start angle: %d, end angle: %d, alpha: %d, cos(alpha): \
%d\n", start_angle, end_angle, alpha, (int) round(cos(alpha)));
	}
}
