/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:57:45 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/18 09:08:05 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_command(t_pipx *pipx, char **cmd_path)
{
	char	*cmd;

	cmd = NULL;
	if (pipx->av[pipx->exec_av_count + pipx->heredoc + 2][0] == '\0'
			|| pipx->av[pipx->exec_av_count + pipx->heredoc + 2][0] == ' ')
	{
		cmd = ft_strdup(pipx->av[pipx->exec_av_count + pipx->heredoc + 2]);
		*cmd_path = get_path(pipx, cmd);
		ft_free((void *)&cmd);
	}
	else
	{
		cmd = pipx->execve_av[pipx->exec_av_count][0];
		*cmd_path = get_path(pipx, cmd);
	}
	return (cmd);
}
