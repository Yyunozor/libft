/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:54:06 by anpayot           #+#    #+#             */
/*   Updated: 2024/11/05 00:55:37 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Convert an unsigned long long integer to a string in the specified base
char	*ft_utoa_base(unsigned long long value, const char *base)
{
	int		base_len;
	int		num_len;
	char	*result;

	if (!ft_isvalid_base(base, &base_len))
		return (NULL);
	num_len = ft_numlen_base(value, base_len);
	result = (char *)malloc(num_len + 1);
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	while (num_len > 0) 
	{
		result[--num_len] = base[value % base_len];
		value /= base_len;
	}
	return (result);
}
