/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:17:00 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/18 12:37:34 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_heredoc(t_pipx *pipx, char *line, char *delimiter, int delimitr_len)
{
	int		w;

	w = -1;
	while (1)
	{
		write(STDIN_FILENO, HERE_PROMPT, 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL || !ft_strncmp(delimiter, line, delimitr_len))
			break ;
		w = write(pipx->infile, line, ft_strlen(line));
		if (w == SYSCALL_ERROR)
		{
			ft_free((void *)&line);
			ft_free((void *)&delimiter);
			print_err_exit("Error writing in heredoc file\n");
		}
		ft_free((void *)&line);
	}
	ft_free((void *)&line);
	ft_free((void *)&delimiter);
}

void	heredoc(t_pipx *pipx)
{
	char	*line;
	char	*delimiter;
	int		delimiter_len;

	delimiter = ft_strjoin(pipx->delimiter, "\n");
	delimiter_len = ft_strlen(delimiter);
	line = NULL;
	run_heredoc(pipx, line, delimiter, delimiter_len);
	close(pipx->infile);
	pipx->infile = open(HEREDOC_FILE, O_RDONLY);
	if (pipx->infile == -1)
		perror("bash: ");
}
