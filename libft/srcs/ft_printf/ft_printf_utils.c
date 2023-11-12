/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:07:58 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/01 10:27:56 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_printf(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_printf(int n, int count, int re)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (ft_putchar_printf('-') == -1)
			return (-1);
		count++;
		n *= -1;
	}
	if (n >= 10)
	{
		count += ft_putnbr_printf(n / 10, 0, re);
		if (count == -1 || ft_putchar_printf(n % 10 + '0') == -1)
			return (-1);
		count++;
	}
	else
	{
		if (ft_putchar_printf(n + '0') == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	count;
	int	base_len;
	int	re;

	count = 0;
	re = 0;
	base_len = ft_strlen_printf(base);
	if (n >= (unsigned long)base_len)
	{
		re = ft_putnbr_base(n / base_len, base);
		if (re == -1)
			return (-1);
		count += re;
		re = ft_putchar_printf(base[n % base_len]);
		if (re == -1)
			return (-1);
		count += re;
	}
	else
	{
		if (ft_putchar_printf(base[n % base_len]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putptr_printf(void *ptr)
{
	int	count;
	int	re;

	count = 0;
	re = ft_putstr_printf("0x");
	if (re == -1)
		return (-1);
	count += re;
	re = ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
	if (re == -1)
		return (-1);
	count += re;
	return (count);
}

int	ft_putunsig_printf(unsigned int n)
{
	int				count;
	int				re;

	count = 0;
	re = 0;
	if (n >= 10)
	{
		re = ft_putunsig_printf(n / 10);
		if (re == -1)
			return (-1);
		count += re;
		re = ft_putchar_printf(n % 10 + '0');
		if (re == -1)
			return (-1);
		count += re;
	}
	else
	{
		re = ft_putchar_printf(n + '0');
		if (re == -1)
			return (-1);
		count += re;
	}
	return (count);
}
