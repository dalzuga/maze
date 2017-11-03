#include "../headers/demo.h"

/**
 * calc_mod360 - special modding function, guarantees range [0, 360)
 *
 * @angle: the angle to mod
 *
 * Return: the resulting angle.
 */
double calc_mod360(double angle)
{
	while (angle < 0)
	{
		angle += 360;
	}

	while (angle >= 360)
	{
		angle -= 360;
	}

	return (angle);
}
