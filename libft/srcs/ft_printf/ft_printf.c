/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:08:56 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/01 10:27:20 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_flag(const char *str, int i, va_list args);
static int	ft_iterate(const char *str, int re, int count, va_list args);

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;
	int		re;

	if (!str)
		return (-1);
	count = 0;
	re = 0;
	va_start(args, str);
	count = ft_iterate(str, re, count, args);
	return (va_end(args), count);
}

static int	ft_iterate(const char *str, int re, int count, va_list args)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			re = ft_check_flag(str, ++i, args);
			if (re == -1)
				return (-1);
			count += re;
			i++;
		}
		if (str[i] != '%' && str[i] != '\0')
		{
			if (ft_putchar_printf(str[i]) == -1)
				return (-1);
			count++;
			i++;
		}
	}
	return (count);
}

static int	ft_check_flag(const char *str, int i, va_list args)
{
	int		re;

	re = 0;
	if (str[i] == 'c')
		re = ft_putchar_printf(va_arg(args, int));
	else if (str[i] == 's')
		re = ft_putstr_printf(va_arg(args, char *));
	else if (str[i] == 'p')
		re = ft_putptr_printf(va_arg(args, void *));
	else if (str[i] == 'd' || str[i] == 'i')
		re = ft_putnbr_printf(va_arg(args, int), 0, re);
	else if (str[i] == 'u')
		re = ft_putunsig_printf(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		re = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str[i] == 'X')
		re = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str[i] == '%')
		re = ft_putchar_printf('%');
	if (re == -1)
		return (-1);
	return (re);
}

int	ft_putchar_printf(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_printf(char *s)
{
	int	count;
	int	re;

	count = 0;
	re = 0;
	if (!s)
	{
		re = write(1, "(null)", 6);
		if (re == -1)
			return (-1);
		return (re);
	}
	while (*s)
	{
		re = ft_putchar_printf(*s++);
		if (re == -1)
			return (-1);
		count += re;
	}
	return (count);
}
