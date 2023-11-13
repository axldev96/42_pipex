/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:47:41 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 07:58:23 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	middle_child(t_pipx *pipx, int *fd, int *fd_aux)
{
	char *fake; // = { "cat", "-e", NULL };
	pid_t	last_pid;

	fake = get_path(pipx, pipx->execve_av[pipx->exec_av_count][0]);
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
		execve(fake, pipx->execve_av[pipx->exec_av_count], pipx->env);
		perror("execve");
	}
}
