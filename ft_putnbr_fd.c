/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:14:31 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/17 00:15:03 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_fd(int n, int fd)
{
	char	*num_str;

	num_str = ft_itoa(n);
	if (!num_str)
		return ;
	ft_putstr_fd(num_str, fd);
	free(num_str);
}
