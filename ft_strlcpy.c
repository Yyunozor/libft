/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:28:24 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/03 15:02:26 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    const char *src_start = src;
    
    if (dstsize > 0)
    {
        while (dstsize-- > 1 && *src)
        {
            *dst++ = *src++;
        }
        *dst = '\0';  // NUL-terminate the destination string if space is available
    }

    // Return the total length of src (as if it was fully copied)
	while (*src++)
	{}
	return src - src_start - 1;
}

#include <stdio.h>
int main(void)
{
    char src[] = "Hello, World!";
    char dst[6];
    size_t len;

    len = ft_strlcpy(dst, src, sizeof(dst));
    printf("Copied string: %s\n", dst);
    printf("Length of src: %zu\n", len);
    return 0;
}
