#include "../headers/demo.h"

/**
 * calc_pxpy - calculates player position in the center of the player's
 * block. This is necessary because we are using finer resolution to position
 * player inside the block itself.
 *
 *
 */
void calc_pxpy(GamePlayer *p)
{
	p->px = (p->x + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;
	p->py = (p->y + 1) * BLOCK_UNITS - BLOCK_UNITS / 2;

	if (DEBUG == 1)
	{
		printf("---------------2--------------\n");
		printf("p->x: %d, px: %d, ", p->x, p->px);
		printf("p->y: %d, py: %d\n", p->y, p->py);
	}
}
