/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:29:28 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/04 22:36:45 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (d > s)
	{
		d += len;
		s += len;
		while (len--)		git pull --no-rebase origin main		git pull --no-rebase origin main		git push origin main		git push origin main		git push origin main		git push origin main		git push origin main
			*(--d) = *(--s);
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}
