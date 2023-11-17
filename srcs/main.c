/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:34:22 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/17 05:02:17 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_leaks(void)
{
	system("leaks pipex");
}

int	main(int ac, char **av, char **env)
{
	t_pipx	pipx;

	//atexit(ft_leaks);
	if (ac < 5 && av && env)
		return (print_error_usage(), 0);
	set_pipx(&pipx, ac, av, env);
	args(&pipx);
	if (pipx.heredoc)
		heredoc(&pipx);
	get_execve_av(&pipx);
	parent(&pipx);
	return (0);
}
