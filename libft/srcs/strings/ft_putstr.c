/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:11:37 by acaceres          #+#    #+#             */
/*   Updated: 2023/06/24 14:17:57 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_putchar(*str++) == -1)
			return (-1);
		i++;
	}
	return (i);
}
