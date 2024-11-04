/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 05/11/2024 00:33:52 by anpayot           #+#    #+#             */
/*   Updated: 05/11/2024 00:34:11 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len_unsigned(unsigned long long num, int base_len)
{
	int	len = (num == 0);
	
	while (num != 0)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long long value, const char *base)
{
	char				*result;
	unsigned long long	num;
	int					base_len;
	int					num_len;

	if (!ft_isvalid_base(base, &base_len))
		return (NULL);
	num = value;
	num_len = ft_num_len_unsigned(num, base_len);
	result = (char *)malloc(num_len + 1);
	if (!result)
		return (NULL);
	result[num_len] = '\0';

	while (num_len-- > 0)
	{
		result[num_len] = base[num % base_len];
		num /= base_len;
	}
	return (result);
}
