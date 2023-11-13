/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:02:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 08:00:27 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	last_child(t_pipx *pipx, int *fd)
{
	char *fake; //= { "wc", "-l", NULL };
	pid_t	last_pid;

	fake = get_path(pipx, pipx->execve_av[pipx->exec_av_count][0]);
	last_pid = fork();
	if (last_pid == SYSCALL_ERROR)
	{
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
		execve(fake, pipx->execve_av[pipx->exec_av_count], pipx->env);
		perror("execve");
	}
}
