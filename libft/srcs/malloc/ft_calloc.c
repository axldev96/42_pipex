/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:22:29 by acaceres          #+#    #+#             */
/*   Updated: 2023/09/30 11:15:10 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;

	c = (char *)malloc(count * size);
	if (!c)
		return (NULL);
	ft_bzero(c, count * size);
	return (c);
}
