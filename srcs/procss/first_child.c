/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:55:23 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 09:11:44 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipx *pipx, int *fd)
{
	char *fake;
	pid_t	first_pid;

	fake = get_path(pipx, pipx->execve_av[pipx->exec_av_count][0]);
	first_pid = fork();
	if (first_pid == SYSCALL_ERROR)
	{
		printf("error in fork first child\n");
		exit(EXIT_FAILURE);
	}
	if (first_pid == 0)
	{
		close(fd[0]);
		dup2(pipx->infile, 0);
		dup2(fd[1], 1);
		close(fd[1]);
		close(pipx->infile);
		execve(fake, pipx->execve_av[pipx->exec_av_count], pipx->env);
		perror("execve");
	}
}
