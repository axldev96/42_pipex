/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:02:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/18 12:12:13 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exec(t_pipx *pipx, char *cmd_path, int *fd)
{
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(pipx->outfile, 1);
	close(fd[0]);
	if (!pipx->execve_av[pipx->exec_av_count][0] || !cmd_path)
	{
		ft_free_3d_arr((void ****)&pipx->execve_av);
		exit(EXIT_FAILURE);
	}
	execve(cmd_path, pipx->execve_av[pipx->exec_av_count], pipx->env);
	ft_free_3d_arr((void ****)&pipx->execve_av);
	exit(EXIT_FAILURE);
}

void	last_child(t_pipx *pipx, int *fd)
{
	pid_t	pid;
	char	*cmd_path;

	pipx->exec_av_count++;
	check_command(pipx, &cmd_path);
	pid = fork();
	if (pid == SYSCALL_ERROR)
	{
		ft_free_3d_arr((void ****)&pipx->execve_av);
		perror("bash: ");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		ft_exec(pipx, cmd_path, fd);
	else
		ft_free((void *)&cmd_path);
}
