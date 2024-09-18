#include <limits.h>

long long ft_lloverflow(int sign, long long LLONG_MAX, long long LLONG_MIN)
{
	if (sign == 1)
		return (LLONG_MAX);
	return (LLONG_MIN);
}

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
	while (ft_isdigit(str[i])
	{
		if (result > (LLONG_MAX - (str[i] - '0')) / 10)
			return (ft_lloverflow(sign, LLONG_MAX, LLONG_MIN));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
