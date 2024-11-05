/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:28:40 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 14:29:39 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long num, int base_len)
{
	int	len;

	len = (num == 0);
	while (num != 0)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

static int	ft_sign_abs(long *num, int base_len)
{
	if (*num < 0 && base_len == 10)
	{
		*num = -*num;
		return (1);
	}
	return (0);
}

char	*ft_itoa_base(int value, const char *base)
{
	char		*result;
	long		num;
	int			base_len;
	int			sign;
	int			num_len;

	if (!ft_isvalid_base(base, &base_len))
		return (NULL);
	num = (long)value;
	sign = ft_sign_abs(&num, base_len);
	num_len = ft_num_len(num, base_len) + sign;
	result = (char *)malloc(num_len + 1);
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	while (num_len-- > sign)
	{
		result[num_len] = base[num % base_len];
		num /= base_len;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
	char *result;

	// Test with base 10
	result = ft_itoa_base(12345, "0123456789");
	printf("Base 10: \t\t%s\t(Expected: 12345)\n", result);
	free(result);

	// Test with base 2
	result = ft_itoa_base(42, "01");
	printf("Base 2: \t\t%s\t(Expected: 101010)\n", result);
	free(result);

	// Test with base 8
	result = ft_itoa_base(12345, "01234567");
	printf("Base 8: \t\t%s\t(Expected: 30071)\n", result);
	free(result);

	// Test with base 16
	result = ft_itoa_base(12345, "0123456789ABCDEF");
	printf("Base 16: \t\t%s\t(Expected: 3039)\n", result);
	free(result);

	// Test with negative number in base 10
	result = ft_itoa_base(-12345, "0123456789");
	printf("Base 10 (negative): \t%s\t(Expected: -12345)\n", result);
	free(result);

	// Test with invalid base
	result = ft_itoa_base(12345, "01234");
	if (result == NULL)
		printf("Invalid base: \t\tNULL\t\t(Expected: Invalid base: NULL)\n");

	return (0);
}
*/