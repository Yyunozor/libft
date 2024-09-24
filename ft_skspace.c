/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:05:40 by anpayot           #+#    #+#             */
/*   Updated: 2024/09/24 12:17:42 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_skspace(const char *str)
{
	int i = 0;
	while (ft_isspace(str[i]))  // Use standard C library function
		i++;
	return (i);
}