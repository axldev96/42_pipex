/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:52:06 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/12 17:51:44 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent(t_pipx *pipx)
{
	int	fd[2];

	if (pipe(fd) == SYSCALL_ERROR)
	{
		printf("pipe(): function error\n");
		exit(EXIT_FAILURE);
	}
	first_child(pipx, fd);
	middle_child(pipx, fd);
	wait(NULL);
	close(fd[0]);
	close(fd[1]);
	close(pipx->infile);
	close(pipx->outfile);
	exit(EXIT_SUCCESS);
}
