/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:33:37 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/17 18:56:07 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, const char *base)
{
	char		*result;
	char		*ptr;
	size_t		base_len;
	long		num;
	int			sign;

	if (!ft_is_valbase(base, &base_len))
		return (NULL);
	num = (long)value;
	sign = ft_get_sign(&num, base_len);
	result = (char *)malloc(34);
	if (!result)
		return (NULL);
	ptr = result;
	if (num == 0)
		*ptr++ = base[0];
	while (num > 0)
	{
		*ptr++ = base[num % base_len];
		num /= base_len;
	}
	if (sign == -1)
		*ptr++ = '-';
	*ptr = '\0';
	return (ft_revstr(result, ptr - result));
}
