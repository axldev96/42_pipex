/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:39:26 by acaceres          #+#    #+#             */
/*   Updated: 2023/09/30 11:10:58 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*link;

	if (!lst || !del)
		return ;
	current = *lst;
	link = NULL;
	while (current)
	{
		link = current->next;
		del(current->content);
		free(current);
		current = link;
	}
	*lst = NULL;
}
