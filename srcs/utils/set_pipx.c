/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:40:38 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/18 13:44:46 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_pipx(t_pipx *pipx, int ac, char **av, char **env)
{
	pipx->heredoc = 0;
	if (BONUS && ac > 5 && !ft_strncmp(av[1], "here_doc", 9))
		pipx->heredoc = 1;
	else if (BONUS && !ft_strncmp(av[1], "here_doc", 9) && ac <= 5)
		print_error_usage();
	pipx->infile = -1;
	pipx->outfile = -1;
	pipx->set_cmd = 2 + pipx->heredoc;
	pipx->ac = ac;
	pipx->delimiter = NULL;
	pipx->execve_av = NULL;
	pipx->exec_av_count = 0;
	pipx->env = env;
	pipx->av = av;
	pipx->command_count = -1;
}
