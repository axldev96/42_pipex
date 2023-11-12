/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:03:23 by acaceres          #+#    #+#             */
/*   Updated: 2023/04/23 21:29:06 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	new_str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!new_str)
		return (0);
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	return (new_str[i] = '\0', new_str);
}
