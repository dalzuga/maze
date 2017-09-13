#include "../headers/demo.h"

int timespec_subtract(struct timespec *result, struct timespec *start,
		      struct timespec *end)
{
	/* subtract seconds */
	result->tv_sec = end->tv_sec - start->tv_sec;

	/* subtract nanoseconds */
	result->tv_nsec = end->tv_nsec - start->tv_nsec;

	/* fix remainder */
	if (result->tv_nsec < 0)
	{
		result->tv_sec--;
		result->tv_nsec += BILLION;
	}

	return (end->tv_sec < start->tv_sec);
}

int fps_calc(int count, struct timespec time_used)
{
	int fps = 0;
	double td;

	td = (time_used.tv_sec * BILLION + time_used.tv_nsec) / BILLION;

	fps = (int) ((double) count / (double) td);

	return (fps);
}
