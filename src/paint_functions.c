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

	/* paint_walls(instance, map, p); */
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
	int i, j;		/* declarations */

	for (i = 0; i < Y_RES; i++)
	{
		for (j = 0; j < X_RES; j++)
		{
		}
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
