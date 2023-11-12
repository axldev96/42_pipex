/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:47:09 by acaceres          #+#    #+#             */
/*   Updated: 2023/04/03 07:28:48 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int n)
{
	if (n == 0)
		return (0);
	return (1 + count_digits(n / 10));
}

char	*fill_reverse(char *n_str, int dig, int n)
{
	n_str[0] = '-';
	n_str[dig] = '\0';
	while (n)
	{
		n_str[dig - 1] = n % 10 + '0';
		n /= 10;
		dig--;
	}
	return (n_str);
}

char	*ft_itoa(int n)
{
	int		dig;
	char	*n_str;

	n_str = NULL;
	dig = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		dig = 1;
	}
	dig += count_digits(n);
	n_str = (char *) malloc ((dig + 1) * sizeof (char));
	if (!n_str)
		return (0);
	return (fill_reverse(n_str, dig, n));
}
