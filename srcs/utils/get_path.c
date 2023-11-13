/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:12:46 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/13 09:06:33 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**splitd_env(t_pipx *pipx)
{
	char	**path_arr;

	path_arr = NULL;
	while (*pipx->env)
	{
		if (!ft_strncmp(*pipx->env, PATH, 5))
		{
			path_arr = ft_split(*pipx->env + 5, ':');
			if (!path_arr)
				return (NULL);
			return (path_arr);
		}
		pipx->env++;
	}
	return (NULL);
}

static char
	*get_full_command(char **path_arr, char *full_command, char *command)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (path_arr[i])
	{
		tmp = ft_strjoin(path_arr[i], "/");
		if (!tmp)
			break ;
		full_command = ft_strjoin(tmp, command);
		ft_free((void *)&tmp);
		if (!full_command)
			break ;
		if (access(full_command, X_OK) == 0)
			break ;
		ft_free((void *)&full_command);
		i++;
	}
	return (full_command);
}

static char	*get_relative_path(t_pipx *pipx, char *command)
{
	char	**path_arr;
	char	*full_command;

	full_command = NULL;
	path_arr = NULL;
	if (!command)
		return (NULL);
	path_arr = splitd_env(pipx);
	if (!path_arr)
		return (NULL);
	full_command = get_full_command(path_arr, full_command, command);
	if (!path_arr)
		return (NULL);
	ft_free_2d_arr((void ***)&path_arr);
	return (full_command);
}

static char	*get_absolute_path(char *path)
{
	if (!ft_strncmp(path, "/", 1)
		|| !ft_strncmp(path, "./", 2)
		|| !ft_strncmp(path, "../", 3))
		return (ft_strdup(path));
	return (NULL);
}

char	*get_path(t_pipx *pipx, char *path)
{
	char	*command;

	command = get_absolute_path(path);
	if (command)
		return (command);
	command = get_relative_path(pipx, path);
	return (command);
}
