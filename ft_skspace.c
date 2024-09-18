#include <libft.h>

int	ft_skspace(const char *str)
{
	int i = 0;
	while (ft_isspace(str[i]))  // Use standard C library function
		i++;
	return (i);
}