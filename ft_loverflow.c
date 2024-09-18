#include <limits.h>

long	ft_loverflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}
