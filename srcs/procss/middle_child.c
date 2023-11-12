/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:02:04 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/12 17:46:44 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	middle_child(t_pipx *pipx, int *fd)
{
	char *fake[] = { "grep", "-i", "name", NULL };
	pid_t	middle_pid = fork();

	if (middle_pid == SYSCALL_ERROR)
	{
		printf("error in fork middle child\n");
		exit(EXIT_FAILURE);
	}
	if (middle_pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(pipx->outfile, 1);
		close(fd[0]);
		execve("/bin/grep", fake, pipx->env);
		perror("execve");
	}
}
