/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:19:16 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/08 12:23:00 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strrchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    while (i >= 0)
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i--;
    }
    return (0);
}
