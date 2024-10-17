/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_overflow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:11:16 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/17 18:13:22 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_handle_overflow(long result, int base_len, int digit, int sign)
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
