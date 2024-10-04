/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/10/04 22:29:28 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/04 22:30:46 by anpayot          ###   ########.fr       */
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
=======
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
>>>>>>> da620217269a81b8e7033d6929c9d8a2aca3a3b2
	}
	return (dst);
}
