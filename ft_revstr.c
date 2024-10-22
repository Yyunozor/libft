/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:34:57 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/22 23:55:46 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str, size_t len)
{
	char	*start;
	char	*end;

	start = str;
	end = str + len - 1;
	while (start < end)
		ft_swap(start++, end--);
	return (str);
}

#include <stdio.h>
int main()
{
	char str[] = "Hello, World!";
	printf("%s\n", ft_revstr(str, ft_strlen(str)));
	return (0);
}