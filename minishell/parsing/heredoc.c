/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:34:55 by artem             #+#    #+#             */
/*   Updated: 2025/11/28 09:49:10 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	exe_process(char *file, int *p)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
	close(p[0]);
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strlen(line) == ft_strlen(file)
			&& ft_strncmp(line, file, ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		write(p[1], line, ft_strlen(line));
		write(p[1], "\n", 1);
		free(line);
	}
	close(p[1]);
	exit(0);
}

int	heredoc_rd(char *file)
{
	pid_t	pid;
	int		p[2];
	int		status;

	if (pipe(p) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	signal_int(HEREDOC);
	if (pid == 0)
		exe_process(file, p);
	signal_int(HEREDOC);
	waitpid(pid, &status, 0);
	close(p[1]);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(p[0]);
		return (-1);
	}
	return (p[0]);
}

void	init_heredoc(t_shell *shell)
{
	t_redir	*r;

	r = shell->cmd_list->redir;
	while (r)
	{
		if (r->type == T_HEREDOC)
			shell->fd = heredoc_rd(r->filename);
		r = r->next;
	}
}
