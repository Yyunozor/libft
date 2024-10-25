/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/25 11:34:00 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	handle_overflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

static int	ft_get_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = ft_get_sign(&str);
	result = 0;
	while (ft_isdigit(*str))
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (handle_overflow(sign));
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"
int main(void)
{
	const char *str1 = "12345";
	const char *str2 = "-67890";
	const char *str3 = "0";
	const char *str4 = "9223372036854775807";
	const char *str5 = "-9223372036854775808";
	const char *str6 = "123abc";
	const char *str7 = "abc123";
	const char *str8 = "  123";
	const char *str9 = "  -123";
	const char *str10 = "  +123";
	
	long result1 = ft_atol(str1);
	long result2 = ft_atol(str2);
	long result3 = ft_atol(str3);
	long result4 = ft_atol(str4);
	long result5 = ft_atol(str5);
	long result6 = ft_atol(str6);
	long result7 = ft_atol(str7);
	long result8 = ft_atol(str8);
	long result9 = ft_atol(str9);
	long result10 = ft_atol(str10);
	
	printf("ft_atol(\"%s\") = %ld\n", str1, result1);
	printf("atol(\"%s\")    = %ld\n", str1, atol(str1));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str2, result2);
	printf("atol(\"%s\")    = %ld\n", str2, atol(str2));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str3, result3);
	printf("atol(\"%s\")    = %ld\n", str3, atol(str3));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str4, result4);
	printf("atol(\"%s\")    = %ld\n", str4, atol(str4));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str5, result5);
	printf("atol(\"%s\")    = %ld\n", str5, atol(str5));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str6, result6);
	printf("atol(\"%s\")    = %ld\n", str6, atol(str6));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str7, result7);
	printf("atol(\"%s\")    = %ld\n", str7, atol(str7));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str8, result8);
	printf("atol(\"%s\")    = %ld\n", str8, atol(str8));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str9, result9);
	printf("atol(\"%s\")    = %ld\n", str9, atol(str9));
	printf("\n");
	printf("ft_atol(\"%s\") = %ld\n", str10, result10);
	printf("atol(\"%s\")    = %ld\n", str10, atol(str10));
	return 0;
}
*/