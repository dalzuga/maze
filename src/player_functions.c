#include "../headers/demo.h"

/* make_player - creates a player */
GamePlayer *make_player(void)
{
	GamePlayer *p;

	p = malloc(sizeof(GamePlayer));
	if (p == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	p->px = START_X;
	p->py = START_Y;
	p->theta = START_THETA % 360;

	p->x = p->px / BLOCK_UNITS;
	p->y = p->py / BLOCK_UNITS;

	/* set distance to projector plane */
	p->dpp = X_RES / 2 / tan((FOV_ANGLE / 2) * M_PI / 180);

	return (p);
}
