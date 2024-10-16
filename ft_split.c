/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:24:43 by anpayot           #+#    #+#             */
/*   Updated: 2024/10/16 18:46:55 by anpayot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **arr, char **ptr)
{
	while (ptr-- > arr)
		free(*ptr);
	free(arr);
}

static size_t	word_count(const char *s, char c)
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

static char	*get_next_word(const char **s, char c)
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
	words = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	ptr = res;
	while (words--)
	{
		*ptr = get_next_word(&s, c);
		if (!*ptr++)
			return (free_all(res, ptr - 1), NULL);
	}
	*ptr = NULL;
	return (res);
}
/*
#include <assert.h>
#include <string.h>
#include <stdio.h>

void print_split_result(char **res)
{
	while (*res)
	{
		printf("'%s'\n", *res);
		res++;
	}
}

void test_ft_split()
{
	char *str1 = "Hello World";
	char **res1 = ft_split(str1, ' ');
	assert(res1 != NULL);
	assert(strcmp(res1[0], "Hello") == 0);
	assert(strcmp(res1[1], "World") == 0);
	assert(res1[2] == NULL);
	printf("\nTest 1 passed:\n");
	print_split_result(res1);

	char *str2 = "42 is the answer";
	char **res2 = ft_split(str2, ' ');
	assert(res2 != NULL);
	assert(strcmp(res2[0], "42") == 0);
	assert(strcmp(res2[1], "is") == 0);
	assert(strcmp(res2[2], "the") == 0);
	assert(strcmp(res2[3], "answer") == 0);
	assert(res2[4] == NULL);
	printf("\nTest 2 passed:\n");
	print_split_result(res2);

	char *str3 = "   leading spaces";
	char **res3 = ft_split(str3, ' ');
	assert(res3 != NULL);
	assert(strcmp(res3[0], "leading") == 0);
	assert(strcmp(res3[1], "spaces") == 0);
	assert(res3[2] == NULL);
	printf("\nTest 3 passed:\n");
	print_split_result(res3);

	char *str4 = "trailing spaces   ";
	char **res4 = ft_split(str4, ' ');
	assert(res4 != NULL);
	assert(strcmp(res4[0], "trailing") == 0);
	assert(strcmp(res4[1], "spaces") == 0);
	assert(res4[2] == NULL);
	printf("\nTest 4 passed:\n");
	print_split_result(res4);

	char *str5 = "   multiple   spaces   ";
	char **res5 = ft_split(str5, ' ');
	assert(res5 != NULL);
	assert(strcmp(res5[0], "multiple") == 0);
	assert(strcmp(res5[1], "spaces") == 0);
	assert(res5[2] == NULL);
	printf("\nTest 5 passed:\n");
	print_split_result(res5);

	printf("\nAll tests passed!\n");
}

int main()
{
	test_ft_split();
	return 0;
}
*/
/*
static void	free_all(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

static size_t	word_count(const char *s, char c)
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

static char	*get_next_word(const char **s, char c)
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
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words)
	{
		res[i] = get_next_word(&s, c);
		if (!res[i++])
			return (free_all(res, i - 1), NULL);
	}
	res[i] = NULL;
	return (res);
}
*/