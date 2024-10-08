/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:19:05 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/08 13:17:36 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while(n--)
	{
		if (*p1++ != *p2++)
			return (*(p1 - 1) - *(p2 - 1));
	}
	return (0);
}

#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*str1 = "salut";
	char	*str2 = "saluu";
	printf("memcmp_lib:\t%d\n", memcmp(str1, str2, strlen(str1)));
	printf("ft_memcmp:\t%d\n", ft_memcmp(str1, str2, strlen(str1)));

	return (0);
}