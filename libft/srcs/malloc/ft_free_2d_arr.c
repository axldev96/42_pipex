/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 04:20:56 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 07:38:12 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_arr(void ***ptr)
{
	int	i;

	i = 0;
	if (!*ptr)
		return ;
	while ((*ptr)[i])
		ft_free(&(*ptr)[i++]);
	ft_free((void *)ptr);
}
