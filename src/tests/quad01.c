#include <stdio.h>

/**
 * calc_quad01 - helper for calc_quadrants()
 *
 */
double calc_quad01(double tplusb)
{
	while (tplusb <= -180)
	{
		tplusb += 360;
	}

	while (tplusb > 180)
	{
		tplusb -= 360;
	}

	return (tplusb);
}

int main()
{
	double tplusb;

	tplusb = 1000;
	printf("tplusb = %.1f\n", tplusb);
	printf("calc_quad01: %f\n", calc_quad01(tplusb));

	printf("---\n");

	tplusb = 180;
	printf("tplusb = %.1f\n", tplusb);
	printf("calc_quad01: %f\n", calc_quad01(tplusb));

	printf("---\n");

	tplusb = -180;
	printf("tplusb = %.1f\n", tplusb);
	printf("calc_quad01: %f\n", calc_quad01(tplusb));

	printf("---\n");

	tplusb = 360;
	printf("tplusb = %.1f\n", tplusb);
	printf("calc_quad01: %f\n", calc_quad01(tplusb));

	printf("---\n");

	tplusb = -360;
	printf("tplusb = %.1f\n", tplusb);
	printf("calc_quad01: %f\n", calc_quad01(tplusb));

	return (0);
}
