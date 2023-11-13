/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:40:38 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 07:55:12 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_pipx(t_pipx *pipx, int ac, char **av, char **env)
{
	pipx->infile = -1;
	pipx->outfile = -1;
	pipx->set_cmd = 2;
	pipx->ac = ac;
	pipx->execve_av = NULL;
	pipx->exec_av_count = 0;
	pipx->env = env;
	pipx->av = av;
	pipx->command_count = -1;
	pipx->last_child_pid = -1;
}
