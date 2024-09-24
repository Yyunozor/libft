/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 22:46:03 by anpayot           #+#    #+#             */
/*   Updated: 2024/09/24 23:52:21 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>#include <stddef.h>

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len = 0;
	size_t src_len = 0;
	size_t i = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
    dst[dst_len + i] = '\0';
    return (dst_len + src_len);
}
