/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_3d_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:30:30 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/17 01:09:09 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_3d_arr(void ****ptr)
{
	int	i;

	i = 0;
	if (!*ptr)
		return ;
	while ((*ptr)[i])
		ft_free_2d_arr(&(*ptr)[i++]);
	ft_free((void *)ptr);
	*ptr = NULL;
}
