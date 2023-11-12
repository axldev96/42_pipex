/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 08:18:25 by acaceres          #+#    #+#             */
/*   Updated: 2023/06/21 08:19:53 by acaceres         ###   ########.fr       */
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

long	ft_atol(const char *str)
{
	long	result;
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
