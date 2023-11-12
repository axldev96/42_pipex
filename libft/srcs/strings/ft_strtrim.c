/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:49:22 by acaceres          #+#    #+#             */
/*   Updated: 2023/03/18 22:49:23 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_check(const char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (0);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && set_check(set, s1[i]))
		i++;
	while (s1[j] && set_check(set, s1[j]))
		j--;
	return (ft_substr(s1, i, j + 1 - i));
}
