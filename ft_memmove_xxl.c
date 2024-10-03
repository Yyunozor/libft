/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_xxl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 00:24:24 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/03 00:36:02 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_forward(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t	*d_word;
	const size_t	*s_word;

	if ((size_t)d % sizeof(size_t) == (size_t)s % sizeof(size_t))
	{
		d_word = (size_t *)d;
		s_word = (const size_t *)s;
		while (len >= sizeof(size_t))
		{
			*d_word++ = *s_word++;
			len -= sizeof(size_t);
		}
		d = (unsigned char *)d_word;
		s = (const unsigned char *)s_word;
	}
	while (len--)
		*d++ = *s++;
}

static void	copy_backward(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t	*d_word;
	const size_t	*s_word;

	if ((size_t)d % sizeof(size_t) == (size_t)s % sizeof(size_t))
	{
		d_word = (size_t *)(d + len);
		s_word = (const size_t *)(s + len);
		while (len >= sizeof(size_t))
		{
			len -= sizeof(size_t);
			*--d_word = *--s_word;
		}
		d = (unsigned char *)d_word;
		s = (const unsigned char *)s_word;
	}
	while (len--)
		d[len] = s[len];
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		copy_forward((unsigned char *)dst, (const unsigned char *)src, len);
	else
		copy_backward((unsigned char *)dst, (const unsigned char *)src, len);
	return (dst);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer1[] = "123456789dd";
    char buffer2[] = "123456789dsasd";

    // Overlapping memory regions
    printf("Original memmove: %s\n", (char *)memmove(buffer1 + 3, buffer1, 6));
    printf("ft_memmove: %s\n", (char *)ft_memmove(buffer2 + 3, buffer2, 6));

    // Test with large data (aligned and unaligned cases)
    char large_src[1024] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vestibulum nec.";
    char large_dst[1024];

    printf("\nTesting large data copy...\n");
    ft_memmove(large_dst, large_src, sizeof(large_src));
    printf("Large copy result: %s\n", large_dst);

    // Test unaligned copy
    printf("\nTesting unaligned copy...\n");
    ft_memmove(large_dst + 1, large_src + 1, sizeof(large_src) - 1);
    printf("Unaligned copy result: %s\n", large_dst + 1);

    // Test with len = 0
    printf("\nTesting len = 0 (no movement):\n");
    char src_empty[] = "Hello";
    char dst_empty[] = "World";
    ft_memmove(dst_empty, src_empty, 0);
    printf("Result (dst_empty): %s\n", dst_empty);

    // Test with src == dst
    printf("\nTesting src == dst (should not change):\n");
    char same_buffer[] = "SameBuffer";
    ft_memmove(same_buffer, same_buffer, strlen(same_buffer));
    printf("Result (same_buffer): %s\n", same_buffer);

    return 0;
}
