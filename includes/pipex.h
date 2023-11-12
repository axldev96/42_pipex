/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:32:49 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/12 17:53:28 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

# ifndef SYSCALL_ERROR
#  define SYSCALL_ERROR -1
# endif

typedef struct s_pipx
{
	int		ac;
	int		infile;
	int		outfile;
	char	**av;
	char	**env;
}			t_pipx;

// UTILS
void	set_pipx(t_pipx *pipx, int ac, char **av, char **env);

// PROCSS
void	parent(t_pipx *pipx);
void	first_child(t_pipx *pipx, int *fd);
void	middle_child(t_pipx *pipx, int *fd);

// ARGS
void	args(t_pipx *pipx);

#endif
