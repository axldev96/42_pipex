/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:06:23 by acaceres          #+#    #+#             */
/*   Updated: 2023/04/25 05:56:36 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	s_chars(char c)
{
	return (c == ' '
		|| c == '\n'
		|| c == '\f'
		|| c == '\t'
		|| c == '\r'
		|| c == '\v');
}

int	ft_atoi(const char *str)
{
	int		result;
	char	sign;

	result = 0;
	sign = 1;
	while (s_chars(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = sign * -1;
	while (ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	return (result * sign);
}
