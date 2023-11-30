#include "../plib.h"

float	plib_fast_square_root(float number)
{
	int	i;
	float	x;
	float	y;

	x = number * 0.5;
	y = number;
	i = *(int *) &y;
	i = 0x5f3759df - (i >> 1);
	y = * (float *) &i;
	y = y * (1.5 - (x * y * y));
	y = y * (1.5 - (x * y * y));
	return (number * y);
}
