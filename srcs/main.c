/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:34:22 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 07:41:40 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipx	pipx;

	if (ac < 4 && av && env)
		return (printf("av error\n"), 0);
	set_pipx(&pipx, ac, av, env);
	//char	*path = get_path(&pipx, av[2]);
	//printf("command: %s\n", path);
	//init_pipex(&pipx);
	args(&pipx);
	get_execve_av(&pipx);
	parent(&pipx);
	return (0);
}
