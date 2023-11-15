/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:34:22 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/15 04:11:11 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipx	pipx;

	if (ac < 5 && av && env)
		return (printf("av error\n"), 0);
	set_pipx(&pipx, ac, av, env);
	args(&pipx);
	if (pipx.heredoc)
		heredoc(&pipx);
	get_execve_av(&pipx);
	parent(&pipx);
	return (0);
}
