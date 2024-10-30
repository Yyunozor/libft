/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:29:10 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/30 21:30:49 by anpayot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putlong_recursive(long n, char *buffer, int i)
{
	if (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		ft_putlong_recursive(n / 10, buffer, i);
	}
	else
		ft_putstr(&buffer[i + 1]);
}

void	ft_putlong(long n)
{
	char	buffer[21];
	int		i;

	i = 20;
	buffer[i--] = '\0';
	if (n == LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	ft_putlong_recursive(n, buffer, i);
}
