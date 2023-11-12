/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:38:07 by acaceres          #+#    #+#             */
/*   Updated: 2023/03/10 16:38:52 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((char *)dst <= (char *)src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		((char *)dst)[len] = ((char *)src)[len];
	return (dst);
}
