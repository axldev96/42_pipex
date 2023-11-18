/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:52:06 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/18 12:38:06 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	process_success(t_pipx *pipx, int *fd)
{
	ft_free_3d_arr((void ****)&pipx->execve_av);
	unlink(HEREDOC_FILE);
	close(fd[0]);
	close(fd[1]);
	close(pipx->infile);
	close(pipx->outfile);
	exit(EXIT_SUCCESS);
}

static void	exec_middles(t_pipx *pipx, int *fd_aux, int *fd_tmp)
{
	int	i;

	i = -1;
	while (++i < pipx->command_count)
	{
		if (pipe(fd_aux) == SYSCALL_ERROR)
		{
			ft_free_3d_arr((void ****)&pipx->execve_av);
			perror("bash: ");
			exit(EXIT_FAILURE);
		}
		middle_child(pipx, fd_tmp, fd_aux);
		close(fd_aux[1]);
		fd_tmp[0] = fd_aux[0];
		fd_tmp[1] = fd_aux[1];
	}
}

static void	exec_childs(t_pipx *pipx, int *fd)
{
	int	fd_aux[2];
	int	fd_tmp[2];

	first_child(pipx, fd);
	fd_tmp[0] = fd[0];
	fd_tmp[1] = fd[1];
	close(fd[1]);
	if (pipx->command_count > 0)
	{
		exec_middles(pipx, fd_aux, fd_tmp);
		last_child(pipx, fd_aux);
		close(fd_aux[0]);
		close(fd_aux[1]);
	}
	else
		last_child(pipx, fd);
}

void	parent(t_pipx *pipx)
{
	int	fd[2];
	int	i;

	i = -1;
	if (pipe(fd) == SYSCALL_ERROR)
	{
		ft_free_3d_arr((void ****)&pipx->execve_av);
		perror("bash: ");
		exit(EXIT_FAILURE);
	}
	exec_childs(pipx, fd);
	while (++i < pipx->command_count + 2)
		waitpid(-1, NULL, 0);
	process_success(pipx, fd);
}
