/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:57:58 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/29 09:39:27 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_rec(int fd, char *rec, char *tmp);
static char	*set_line(char **rec, char *line);
static char	*reset_rec(char *rec, int line_len);

char	*get_next_line(int fd)
{
	static char	*rec;
	char		*tmp;
	char		*line;

	line = NULL;
	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (ft_free((void *)&rec), NULL);
	if (!rec)
	{
		rec = ft_strdup("");
		if (!rec)
			return (rec = NULL, NULL);
	}
	rec = set_rec(fd, rec, tmp);
	if (!rec)
		return (NULL);
	line = set_line(&rec, line);
	if (!line)
		return (ft_free((void *)&rec), rec = NULL, NULL);
	return (line);
}

static char	*set_rec(int fd, char *rec, char *tmp)
{
	char	*buff;
	int		_r;

	_r = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free((void *)&rec), NULL);
	while (_r > 0)
	{
		_r = read(fd, buff, BUFFER_SIZE);
		if (_r == -1)
			return (ft_free((void *)&buff), ft_free((void *)&rec), NULL);
		buff[_r] = '\0';
		tmp = rec;
		rec = ft_strjoin(rec, buff);
		if (!rec)
			return (ft_free((void *)&tmp), ft_free((void *)&buff), NULL);
		ft_free((void *)&tmp);
		if (ft_strchr(rec, '\n'))
			break ;
	}
	return (ft_free((void *)&buff), rec);
}

static char	*set_line(char **rec, char *line)
{
	int	line_len;
	int	i;

	i = -1;
	line_len = 0;
	if (!*rec)
		return (NULL);
	while ((*rec)[line_len])
	{
		if ((*rec)[line_len++] == '\n')
			break ;
	}
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	while (++i < line_len)
		line[i] = (*rec)[i];
	line[i] = '\0';
	if (line[0] == '\0')
		return (ft_free((void *)&line), NULL);
	*rec = reset_rec(*rec, line_len);
	if (!*rec)
		return (rec = NULL, line);
	return (line);
}

static char	*reset_rec(char *rec, int line_len)
{
	char	*new_rec;

	new_rec = NULL;
	if (!rec)
		return (NULL);
	new_rec = ft_strdup(&rec[line_len]);
	ft_free((void *)&rec);
	if (!new_rec)
		return (NULL);
	return (new_rec);
}
