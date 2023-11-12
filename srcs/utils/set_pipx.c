/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:40:38 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/12 17:53:14 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_pipx(t_pipx *pipx, int ac, char **av, char **env)
{
	pipx->infile = -1;
	pipx->outfile = -1;
	pipx->ac = ac;
	pipx->env = env;
	pipx->av = av;
}
