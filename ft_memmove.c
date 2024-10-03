/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:52:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/03 14:23:43 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	p_dest = (unsigned char *)dst;
	p_src = (const unsigned char *)src;
	if (p_dest < p_src)
	{
		while (len--)
			*p_dest++ = *p_src++;
	}
	else
	{
		p_dest += len;
		p_src += len;
		while(len--)
			*--p_dest = *--p_src;
	}
	return (dst);
}
