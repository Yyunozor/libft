#include <libft.h>

long	ft_loverflow(int sign)
{
	if (sign == 1)
		return (INT_MAX);
	return (INT_MIN);
}
