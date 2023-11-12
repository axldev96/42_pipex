/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:50:37 by acaceres          #+#    #+#             */
/*   Updated: 2023/09/30 11:10:21 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	void	*content;

	if (!lst)
		return (NULL);
	content = f(lst->content);
	node = ft_lstnew(content);
	if (!node)
		return (del(content), NULL);
	node->next = ft_lstmap(lst->next, f, del);
	return (node);
}
