/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:27:43 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/17 19:54:46 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static long	ft_handle_overflow(long result, int base_len, int digit, int sign)
{
	long	max_int;
	long	min_int;

	max_int = (long)INT_MAX;
	min_int = (long)INT_MIN;
	if (result > max_int / base_len
		|| (result == max_int / base_len && digit > max_int % base_len))
	{
		if (sign == 1)
		{
			return (max_int);
		}
		else
		{
			return (min_int);
		}
	}
	return (result);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int			base_len;
	long		result;
	int			sign;
	int			digit;
	const char	*base_ptr;

	if (!ft_is_valbase(base, &base_len))
		return (0);
	sign = ft_get_sign(&str);
	result = 0;
	while (*str)
	{
		base_ptr = ft_strchr(base, *str);
		if (!base_ptr)
			break ;
		digit = base_ptr - base;
		result = ft_handle_overflow(result, base_len, digit, sign);
		result = result * base_len + digit;
		str++;
	}
	return ((int)(result * sign));
}
