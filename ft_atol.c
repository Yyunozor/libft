#include <limits.h>

long	ft_atoll(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return LONG_MAX;
			else
				return LONG_MIN;
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

#include <stdio.h>

int	main(void)
{
	printf("%ld\n", ft_atoll("92233720368547758070")); // Expect overflow: LLONG_MAX
	printf("%ld\n", ft_atoll("1"));                    // Expect: 1
	printf("%ld\n", ft_atoll("0"));                    // Expect: 0
	printf("%ld\n", ft_atoll("-1"));                   // Expect: -1
	printf("%ld\n", ft_atoll("-9223372036854775808")); // Expect: LLONG_MIN
	return (0);
}
