/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:24:43 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/23 19:05:32 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **arr, char **ptr)
{
	while (ptr-- > arr)
		free(*ptr);
	free(arr);
}

static size_t	ft_counter(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (!s[1] || s[1] == c))
			count++;
		s++;
	}
	return (count);
}

static char	*ft_nxtwrd(const char **s, char c)
{
	const char	*start;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	return (ft_substr(start, 0, *s - start));
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_counter(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	ptr = res;
	while (words--)
	{
		*ptr = ft_nxtwrd(&s, c);
		if (!*ptr++)
			return (ft_free(res, ptr - 1), NULL);
	}
	*ptr = NULL;
	return (res);
}
