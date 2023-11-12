/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:11:03 by acaceres          #+#    #+#             */
/*   Updated: 2023/03/15 00:58:48 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	len;
	char			*nw_str;

	len = ft_strlen(s1);
	nw_str = (char *) malloc ((len + 1) * sizeof (char));
	if (!nw_str)
		return (0);
	nw_str[len] = '\0';
	while (len--)
		nw_str[len] = s1[len];
	return (nw_str);
}
