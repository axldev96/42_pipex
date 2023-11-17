/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:02:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/16 21:38:57 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	last_child(t_pipx *pipx, int *fd)
{
	pid_t	last_pid;
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
		printf("trahs: %s\n", pipx->execve_av[pipx->exec_av_count][0]);
	//printf("cmd: %s\n", cmd);
	last_pid = fork();
	if (last_pid == SYSCALL_ERROR)
	{
		ft_free_3d_arr((void ****)&pipx->execve_av);
		printf("error in fork middle child\n");
		exit(EXIT_FAILURE);
	}
	pipx->last_child_pid = last_pid;
	if (last_pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(pipx->outfile, 1);
		close(fd[0]);
		if (!pipx->execve_av[pipx->exec_av_count][0])
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
