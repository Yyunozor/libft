#include <limits.h>

long	ft_lloverflow(int sign)
{
	if (sign == 1)
		return (LLONG_MAX);
	return (LLONG_MIN);
}
