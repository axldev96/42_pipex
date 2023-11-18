/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:19:10 by acaceres          #+#    #+#             */
/*   Updated: 2023/11/18 12:26:06 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_error_usage(void)
{
	print_error("\nError: Program argumentes error\n");
	print_error("Mandatory usage: ./pipex infile cmd cmd1 outfile\n");
	print_error("Multiple pipes usage: ./pipex infile cmd cmd1 ... outfile\n");
	print_error("Heredoc usage: ./pipex here_doc delimiter cmd cmd1 outfile\n");
	exit(EXIT_FAILURE);
}

void	command_error(void)
{
	perror("");
}

void	command_not_found(char *path)
{
	print_error("bash: ");
	print_error(path);
	print_error(": ");
	print_error("command not found\n");
}

void	print_err_exit(char *error)
{
	print_error(error);
	exit(EXIT_FAILURE);
}
