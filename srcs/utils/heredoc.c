/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:17:00 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/15 04:58:38 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex here_doc LIMITER cmd cmd1 file
// cmd << LIMITER | cmd1 >> file

void	heredoc(t_pipx *pipx)
{
	char	*line;
	char	*delimiter;
	int		delimiter_len;
	int		w;

	delimiter = ft_strjoin(pipx->delimiter, "\n");
	delimiter_len = ft_strlen(delimiter);
	line = NULL;
	w = -1;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || !ft_strncmp(delimiter, line, delimiter_len))
			break ;
		w = write(pipx->infile, line, ft_strlen(line));
		if (w == SYSCALL_ERROR)
		{
			ft_free((void *)&line);
			ft_free((void *)&delimiter);
			printf("Error writing in heredoc file\n");
			exit(EXIT_FAILURE);
		}
		ft_free((void *)&line);
	}
	ft_free((void *)&line);
	ft_free((void *)&delimiter);
	close(pipx->infile);
	pipx->infile = open(".heredoc", O_RDONLY);
	if (pipx->infile == -1)
	{
		printf("Error opening heredoc file\n");
		exit(EXIT_FAILURE);
	}
}
