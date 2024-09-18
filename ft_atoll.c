#include <libft.h>

long long	ft_atoll(const char *str)
{
	int			i;
	int			sign;
	long long	result;

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
		if (result > (LLONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return LLONG_MAX;
			else
				return LLONG_MIN;
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
 #include <stdio.h>
int	main(void)
{
	printf("%lld\n", ft_atoll("92233720368547758070")); // Expect overflow: LLONG_MAX
	printf("%lld\n", ft_atoll("9223372036854775807")); // Expect: LLONG_MAX
	printf("%lld\n", ft_atoll("1"));                    // Expect: 1
	printf("%lld\n", ft_atoll("0"));                    // Expect: 0
	printf("%lld\n", ft_atoll("-1"));                   // Expect: -1
	printf("%lld\n", ft_atoll("-9223372036854775808")); // Expect: LLONG_MIN
	printf("%lld\n", ft_atoll("-92233720368547758070")); // Expect overflow: LLONG_MIN
	return (0);
}
*/