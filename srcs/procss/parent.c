/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:52:06 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 15:59:30 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	process_success(t_pipx *pipx, int *fd, int *fd_aux)
{
	ft_free_3d_arr((void ****)&pipx->execve_av);
	close(fd[0]);
	close(fd[1]);
	close(fd_aux[0]);
	close(fd_aux[1]);
	close(pipx->infile);
	close(pipx->outfile);
	exit(EXIT_SUCCESS);
}

static void	exec_middles(t_pipx *pipx, int *fd_aux, int *fd_tmp)
{
	while (pipx->command_count)
	{
		if (pipe(fd_aux) == SYSCALL_ERROR)
		{
			printf("pipe(): middle function error\n");
			exit(EXIT_FAILURE);
		}
		middle_child(pipx, fd_tmp, fd_aux);
		close(fd_aux[1]);
		fd_tmp[0] = fd_aux[0];
		fd_tmp[1] = fd_aux[1];
		pipx->command_count--;
	}
}

void	parent(t_pipx *pipx)
{
	int	fd[2];
	int	fd_aux[2];
	int	fd_tmp[2];

	if (pipe(fd) == SYSCALL_ERROR)
	{
		printf("pipe(): function error\n");
		exit(EXIT_FAILURE);
	}
	first_child(pipx, fd);
	fd_tmp[0] = fd[0];
	fd_tmp[1] = fd[1];
	close(fd[1]);
	if (pipx->command_count > 0)
	{
		exec_middles(pipx, fd_aux, fd_tmp);
		last_child(pipx, fd_aux);
	}
	else
		last_child(pipx, fd);
	waitpid(pipx->last_child_pid, NULL, 0);
	process_success(pipx, fd, fd_aux);
}
