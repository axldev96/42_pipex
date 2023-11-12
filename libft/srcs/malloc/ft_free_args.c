/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:00:16 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/29 05:44:52 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_args(size_t argc, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, argc);
	i = 0;
	while (i++ < argc)
		free(va_arg(args, void *));
	va_end(args);
}
