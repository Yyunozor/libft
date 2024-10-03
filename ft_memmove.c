<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:52:22 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/03 14:08:03 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
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
		while (len--)
			*--p_dest = *--p_src;
	}
	return (dst);
=======
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	// If the pointers are equal, no move is needed
	if (dst == src || len == 0)
		return (dst);

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;

	// Check for overlap: If destination is after the source, copy backwards
	if (d > s)
	{
		// Copy backwards: Start from the end
		i = len;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
	{
		// Copy forwards: No overlap or destination is before the source
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

#include <stdio.h>
#include <string.h>
int main(void)
{
    char buffer1[] = "123456789";
    char buffer2[] = "123456789";

    // Overlapping memory regions, should handle it correctly
    printf("Original memmove: %s\n", (char *)memmove(buffer1 + 3, buffer1, 6));
    printf("ft_memmove: %s\n", (char *)ft_memmove(buffer2 + 3, buffer2, 6));

    // Test with non-overlapping regions
    char buffer3[] = "Hello, world!";
    char buffer4[] = "Hello, world!";
    printf("Original memmove: %s\n", (char *)memmove(buffer3 + 7, buffer3, 5));
    printf("ft_memmove: %s\n", (char *)ft_memmove(buffer4 + 7, buffer4, 5));

    return 0;
>>>>>>> 0ea90de363fa9afb480c87a42b5028a8d782f66e
}
