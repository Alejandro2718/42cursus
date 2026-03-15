/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:12:20 by artem             #+#    #+#             */
/*   Updated: 2025/11/23 10:54:17 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	redirections(t_token_type s_redir, char *file, int cmd_fd)
{
	int	fd;
	int	stream;

	fd = 0;
	stream = STDOUT_FILENO;
	if (s_redir == T_REDIR_OUT)
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (s_redir == T_REDIR_OUT_APPEND)
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (s_redir == T_REDIR_IN)
		fd = open(file, O_RDONLY);
	else if (s_redir == T_HEREDOC)
		fd = cmd_fd;
	if (s_redir == T_REDIR_IN || s_redir == T_HEREDOC)
		stream = STDIN_FILENO;
	if (fd < 0 || dup2(fd, stream) < 0)
	{
		perror("redir");
		exit(1);
	}
	close(fd);
}
