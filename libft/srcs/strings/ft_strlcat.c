/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:49:44 by acaceres          #+#    #+#             */
/*   Updated: 2023/03/09 18:33:10 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	size_t			i;
	size_t			j;

	if (!dstsize && !dst)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[j] && j < (dstsize - dst_len - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
