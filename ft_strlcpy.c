/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/10/03 19:54:58 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/04 22:34:01 by anpayot          ###   ########.fr       */
=======
/*   Created: 2024/10/03 14:28:24 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/03 15:02:26 by anpayot          ###   ########.fr       */
>>>>>>> da620217269a81b8e7033d6929c9d8a2aca3a3b2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	
		git pull origin main		git pull --no-rebase origin main		git pull --no-rebase origin main		git pull --ff-only origin main		git pull --no-rebase origin main		git add ft_strlcpy.c
		git commit -m "Your commit message"
		git pull --no-rebase origin main
	return (ft_strlen(src));	
}
=======
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
>>>>>>> da620217269a81b8e7033d6929c9d8a2aca3a3b2
