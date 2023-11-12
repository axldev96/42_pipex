/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 07:29:08 by acaceres          #+#    #+#             */
/*   Updated: 2023/09/30 11:09:59 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *node)
{
	if (!node)
		write(1, "Empty list.\n", 12);
	while (node)
	{
		while (*(char *)node->content)
			write(1, (char *)node->content++, 1);
		node = node->next;
	}
}
