/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:30:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/08 14:09:54 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_loverflow(int sign)
{
	if (sign == 1)
		return (9223372036854775807);
	return (-9223372036854775808);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = ft_skspace(str);
	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
	}
	while (ft_isnumver(*str))
	{
		if (result > (9223372036854775807 - (*str)) / 10)
			return (ft_loverflow(sign));
		result = result * 10 + (*str - '0');
	}
	return (result * sign);
}
