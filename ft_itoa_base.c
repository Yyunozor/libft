/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:33:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/17 20:01:43 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_num_length(long num, int base_len)
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

static int	get_sign_and_absolute(long *num, int base_len)
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

	if (!ft_is_valbase(base, &base_len))
		return (NULL);
	num = (long)value;
	sign = get_sign_and_absolute(&num, base_len);
	num_len = get_num_length(num, base_len) + sign;
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
