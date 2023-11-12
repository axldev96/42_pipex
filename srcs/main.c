/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:34:22 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/12 17:53:38 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipx	pipx;

	if (ac < 5 && av)
		return (printf("av error\n"), 0);
	//init_pipex(&pipx);
	set_pipx(&pipx, ac, av, env);
	args(&pipx);
	parent(&pipx);
	return (0);
}
