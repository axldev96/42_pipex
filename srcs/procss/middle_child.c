/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:47:41 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 15:58:20 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	middle_child(t_pipx *pipx, int *fd, int *fd_aux)
{
	char	*cmd_path;
	pid_t	last_pid;

	cmd_path = get_path(pipx, pipx->execve_av[++pipx->exec_av_count][0]);
	last_pid = fork();
	if (last_pid == SYSCALL_ERROR)
	{
		printf("error in fork middle child\n");
		exit(EXIT_FAILURE);
	}
	if (last_pid == 0)
	{
		printf("In the middle\n");
		close(fd[1]);
		close(fd_aux[0]);
		dup2(fd[0], 0);
		dup2(fd_aux[1], 1);
		close(fd[0]);
		close(fd_aux[1]);
		execve(cmd_path, pipx->execve_av[pipx->exec_av_count], pipx->env);
		perror("execve");
	}
	else
		ft_free((void *)&cmd_path);
}
