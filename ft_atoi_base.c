/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:27:43 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/17 18:13:27 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, const char *base)
{
	int			base_len;
	long		result;
	int			sign;
	int			digit;
	const char	*base_ptr;

	if (!ft_is_valid_base(base, &base_len))
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
