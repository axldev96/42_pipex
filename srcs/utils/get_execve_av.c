/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_execve_av.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 06:11:13 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/15 04:47:58 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_execve_av(t_pipx *pipx)
{
	int	i;
	int	j;

	j = 0;
	i = 2 + pipx->heredoc;
	if (pipx->heredoc)
		pipx->execve_av = malloc(sizeof(char *) * (pipx->ac - 4 + 1));
	else
		pipx->execve_av = malloc(sizeof(char *) * (pipx->ac - 3 + 1));
	if (!pipx->execve_av)
		return ;
	while (i < (pipx->ac - 1))
	{
		pipx->execve_av[j] = ft_split(pipx->av[i], ' ');
		j++;
		i++;
	}
	pipx->execve_av[j] = NULL;
}
