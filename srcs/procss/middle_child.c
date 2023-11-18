/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:47:41 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/17 03:16:57 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	middle_child(t_pipx *pipx, int *fd, int *fd_aux)
{
	pid_t	mid_pid;
	char	*cmd_path;
	char	*cmd;

	pipx->exec_av_count++;
	if (pipx->av[pipx->exec_av_count + pipx->heredoc + 2][0] == '\0'
			|| pipx->av[pipx->exec_av_count + pipx->heredoc + 2][0] == ' ')
	{
		cmd = ft_strdup(pipx->av[pipx->exec_av_count + pipx->heredoc + 2]);
		cmd_path = get_path(pipx, cmd);
		ft_free((void *)&cmd);
	}
	else
	{
		cmd = pipx->execve_av[pipx->exec_av_count][0];
		cmd_path = get_path(pipx, cmd);
	}
	mid_pid = fork();
	if (mid_pid == SYSCALL_ERROR)
	{
		ft_free_3d_arr((void ****)&pipx->execve_av);
		printf("error in fork middle child\n");
		exit(EXIT_FAILURE);
	}
	if (mid_pid == 0)
	{
		close(fd[1]);
		close(fd_aux[0]);
		dup2(fd[0], 0);
		dup2(fd_aux[1], 1);
		close(fd[0]);
		close(fd_aux[1]);
		if (!pipx->execve_av[pipx->exec_av_count][0] || !cmd_path)
		{
			ft_free_3d_arr((void ****)&pipx->execve_av);
			exit(EXIT_FAILURE);
		}
		execve(cmd_path, pipx->execve_av[pipx->exec_av_count], pipx->env);
		ft_free_3d_arr((void ****)&pipx->execve_av);
		exit(EXIT_FAILURE);
	}
	else
		ft_free((void *)&cmd_path);
}
