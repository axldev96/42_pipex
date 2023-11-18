/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:32:49 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/17 03:18:58 by acaceres         ###   ########.fr       */
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

# ifndef PATH
#  define PATH "PATH="
# endif

typedef struct s_pipx
{
	int		ac;
	int		infile;
	int		outfile;
	int		command_count;
	int		set_cmd;
	int		exec_av_count;
	int		heredoc;
	int		aqui;
	pid_t	first_pid;
	pid_t	last_child_pid;
	char	*delimiter;
	char	***execve_av;
	char	**av;
	char	**env;
}			t_pipx;

// UTILS
void	set_pipx(t_pipx *pipx, int ac, char **av, char **env);
void	get_execve_av(t_pipx *pipx);
void	heredoc(t_pipx *pipx);
void	print_error(char *str);
void	print_error_usage(void);
void	command_error(void);

// PROCSS
void	parent(t_pipx *pipx);
void	first_child(t_pipx *pipx, int *fd);
void	middle_child(t_pipx *pipx, int *fd, int *fd_aux);
void	last_child(t_pipx *pipx, int *fd);

// ARGS
void	args(t_pipx *pipx);
char	*get_path(t_pipx *pipx, char *path);

#endif
