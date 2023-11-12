/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:38:07 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/12 17:47:00 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	args(t_pipx *pipx)
{
	pipx->infile = open(pipx->av[1], O_RDONLY);
	if (pipx->infile == SYSCALL_ERROR)
	{
		printf("Infile open error\n");
		exit(EXIT_FAILURE);
	}
	pipx->outfile = open(pipx->av[pipx->ac - 1],
			O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (pipx->outfile == SYSCALL_ERROR)
	{
		printf("outfile open error\n");
		exit(EXIT_FAILURE);
	}
}
