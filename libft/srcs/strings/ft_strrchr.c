/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:07:00 by acaceres          #+#    #+#             */
/*   Updated: 2023/03/13 17:06:37 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		ic;
	char	*cy;

	i = ft_strlen(s);
	ic = (char)c;
	cy = (char *)s;
	while (i >= 0)
	{
		if (cy[i] == ic)
			return (&cy[i]);
		i--;
	}
	return (0);
}
