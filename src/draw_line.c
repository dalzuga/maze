/**
 * draw_line - draws a line on SDL window.
 *
 */
int draw_line(SDL_Instance instance, int col, int height)
{
	int top = Y_RES / 2 + height / 2;
	int bottom = Y_RES / 2 - height / 2;

	SDL_RenderDrawLine(instance.renderer, i, top, i, bottom);

	return (0);
}

/**
 *
 *
 */
int get_dhi(GameMap map, GamePlayer p, double ap)
{
	double alpha = (90 - ap);
	int c, i, j, Px, Py, dy, Ya;

	i = Py / 64;
	j = Px / 64;

	for (c = 0; i <= map->cols && j <= map->rows; c++)
	{
		i = dhi_i(Px, dy, c, Ya, alpha);
		j = dhi_j(Px, dy, c, Ya);
	}

	return (dhi_dhi(Px, dy, c, Ya));
}

int dhi_i(int Px, int dy, int c, int Ya, double alpha)
{
	int i;

	i = Px;
	i += dy * tan(alpha * M_PI / 180);
	i += c * Ya * tan(alpha * M_PI / 180);
	i = i / 64;

	return (i);
}

int dhi_j(int Px, int dy, int c, int Ya)
{
	int j;

	j = Py;
	j += dy;
	j += c * Ya;
	j = j / 64;
}

int dhi_dhi(int Px, int dy, int c, int Ya)
{
	int dhi;

	return ((Px + dy + c * Ya) / 64);
}
