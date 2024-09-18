#include <limits.h>

// Handles overflow and underflow for any type
long long ft_loverflow(int sign, long LONG_MAX, long LONG_MIN)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

// Your ft_atol function
long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = ft_skspace(str);
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
			return (ft_loverflow(sign, LONG_MAX, LONG_MIN));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
