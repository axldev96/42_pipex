/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 03:42:55 by acaceres          #+#    #+#             */
/*   Updated: 2023/06/20 12:26:43 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *s, char c)
{
	size_t	i;
	size_t	w;

	i = 1;
	w = 0;
	if (!s[0])
		return (0);
	if (s[0] != c)
		w++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			w++;
		i++;
	}
	return (w);
}

int	free_word(size_t i, char **str_arr)
{
	while (i--)
		free(str_arr[i]);
	return (free(str_arr), 0);
}

char	**return_arr(const char *s, char **str_arr, char c, char *word)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	start = 0;
	len = 0;
	while (s[start])
	{
		while (s[start + len] != c && s[start + len])
			len++;
		if (len > 0)
		{
			word = ft_substr(s, start, len);
			if (!word)
				return (free_word(i, str_arr), NULL);
			str_arr[i++] = word;
		}
		start += len;
		len = 0;
		if (s[start])
			start++;
	}
	return (str_arr[i] = 0, str_arr);
}

char	**ft_split(const char *s, char c)
{
	char	**str_arr;

	str_arr = 0;
	if (!s)
		return (0);
	str_arr = (char **) malloc ((count_word(s, c) + 1) * sizeof (char *));
	if (!str_arr)
		return (0);
	return (return_arr(s, str_arr, c, NULL));
}

/* int main(void) */
/* { */
/* 	char	*s = "Hello Common"; */
/* 	char	c = ' '; */
/* 	int		i = 0; */

/* 	char	**result = ft_split(s, c); */

/* 	while (result[i]) */
/* 	{ */
/* 		printf("\n--%s\n", result[i]); */
/* 		i++; */
/* 	} */

/* 	return (0); */
/* } */
