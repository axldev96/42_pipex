/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:38:07 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/17 01:27:56 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	args_heredoc(t_pipx *pipx)
{
	pipx->infile = open(".heredoc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipx->infile == SYSCALL_ERROR)
	{
		printf("args: here_doc open error\n");
		exit(EXIT_FAILURE);
	}
	pipx->delimiter = pipx->av[2];
	pipx->command_count = pipx->ac - 6;
	pipx->outfile = open(pipx->av[pipx->ac - 1],
			O_CREAT | O_WRONLY | O_APPEND,
			S_IRUSR | S_IWUSR);
	if (pipx->outfile == SYSCALL_ERROR)
	{
		printf("outfile open error\n");
		exit(EXIT_FAILURE);
	}
}

void	args(t_pipx *pipx)
{
	if (pipx->heredoc)
		args_heredoc(pipx);
	else
	{
		pipx->infile = open(pipx->av[1], O_RDONLY);
		if (pipx->infile == SYSCALL_ERROR)
		{
			write(2, "bash: ", 6);
			write(2, pipx->av[1], ft_strlen(pipx->av[1]));
			write(2,": ", 2);
			write(2, "No such file or directory\n", 26);
		}
		pipx->command_count = pipx->ac - 5;
		pipx->outfile = open(pipx->av[pipx->ac - 1],
				O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR);
		if (pipx->outfile == SYSCALL_ERROR)
		{
			printf("outfile open error\n");
			exit(EXIT_FAILURE);
		}
	}
}
