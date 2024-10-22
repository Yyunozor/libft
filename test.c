/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:07:12 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/23 00:18:34 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
	char str[] = "Hello, World!";
	printf("%s\n", ft_revstr(str, ft_strlen(str)));
	ft_putstr_fd("Hello, World!\n", 1);
	printf("%s\n", ft_strchr("Hello, World!", 'W'));
	return (0);
}
