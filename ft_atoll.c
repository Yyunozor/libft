/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/25 11:36:58 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lloverflow(int sign)
{
	if (sign == 1)
		return (LLONG_MAX);
	return (LLONG_MIN);
}

long	ft_atoll(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result > (LLONG_MAX - (str[i] - '0')) / 10)
			return (ft_lloverflow(sign));
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	const char *str1 = "12345";
	const char *str2 = "-98765";
	const char *str3 = "0";
	const char *str4 = "9223372036854775807"; // LLONG_MAX
	const char *str5 = "-9223372036854775808"; // LLONG_MIN

	long long num1 = ft_atoll(str1);
	long long num2 = ft_atoll(str2);
	long long num3 = ft_atoll(str3);
	long long num4 = ft_atoll(str4);
	long long num5 = ft_atoll(str5);

	long long orig_num1 = atoll(str1);
	long long orig_num2 = atoll(str2);
	long long orig_num3 = atoll(str3);
	long long orig_num4 = atoll(str4);
	long long orig_num5 = atoll(str5);

	printf("Number 1:\t%lld (Original:\t%lld)\n", num1, orig_num1);
	printf("Number 2:\t%lld (Original:\t%lld)\n", num2, orig_num2);
	printf("Number 3:\t%lld (Original:\t%lld)\n", num3, orig_num3);
	printf("Number 4:\t%lld (Original:\t%lld)\n", num4, orig_num4);
	printf("Number 5:\t%lld (Original:\t%lld)\n", num5, orig_num5);

	return 0;
}
*/