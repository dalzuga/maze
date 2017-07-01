#include "../headers/demo.h"

/**
 *
 *
 */
int get_dhi(int Px, int Py, int dy, int Ya, double ap)
{
	double alpha = (90 - ap);
	int c, i, j, Px, Py, dy, Ya;

	i = Py / 64;
	j = Px / 64;

	for (c = 0; ; c++)
	{
		i = dhi_i(Px, dy, c, Ya, alpha);
		j = dhi_j(Px, dy, c, Ya);
		printf("i: %d\n", i);
		printf("j: %d\n", j);
	}

	return (dhi_dhi(Px, dy, c, Ya, alpha));
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

int dhi_j(int Py, int dy, int c, int Ya)
{
	int j;

	j = Py;
	j += dy;
	j += c * Ya;
	j = j / 64;

	return (j);
}

int dhi_dhi(int Px, int dy, int c, int Ya, double alpha)
{
	int dhi;

	dhi = (Px + dy + c * Ya);
	dhi = dhi / sin(alpha * M_PI / 180);

	return (dhi);
}
