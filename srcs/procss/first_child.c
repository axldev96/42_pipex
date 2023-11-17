/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:55:23 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/17 03:19:29 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipx *pipx, int *fd)
{
	char	*cmd_path;
	char	*cmd;

	if (pipx->av[pipx->exec_av_count + pipx->heredoc + 2][0] == '\0'
			|| pipx->av[pipx->exec_av_count + pipx->heredoc + 2][0] == ' ')
		cmd = ft_strdup(pipx->av[pipx->exec_av_count + pipx->heredoc + 2]);
	else
		cmd = pipx->execve_av[pipx->exec_av_count][0];
	cmd_path = get_path(pipx, cmd);
	pipx->first_pid = fork();
	if (pipx->first_pid == SYSCALL_ERROR)
	{
		ft_free_3d_arr((void ****)&pipx->execve_av);
		printf("error in fork first child\n");
		exit(EXIT_FAILURE);
	}
	if (pipx->first_pid == 0)
	{
		close(fd[0]);
		dup2(pipx->infile, 0);
		if (pipx->infile == -1)
			exit(EXIT_FAILURE);
		dup2(fd[1], 1);
		close(fd[1]);
		close(pipx->infile);
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
	{
		//waitpid(pipx->first_pid, NULL, 0);
		ft_free((void *)&cmd_path);
	}
}
