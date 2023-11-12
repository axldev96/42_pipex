/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:37:40 by acaceres          #+#    #+#             */
/*   Updated: 2023/03/15 01:39:15 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*new_str;

	if (!s)
		return (0);
	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len >= (slen - start))
		len = slen - start;
	new_str = (char *) malloc ((len + 1) * sizeof (char));
	if (!new_str)
		return (0);
	while (s[i])
	{
		if (i == start)
			return (ft_strlcpy(new_str, &s[i], len + 1), new_str);
		i++;
	}
	return (new_str);
}
