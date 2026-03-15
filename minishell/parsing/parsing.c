/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artem <artem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:24:04 by artemdanilo       #+#    #+#             */
/*   Updated: 2025/11/29 00:22:46 by artem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	close_prev_and_update(int *prev_p, int *p, t_cmd_list *cmd_list)
{
	if (*prev_p != -1)
		close(*prev_p);
	if (cmd_list->next)
	{
		close(p[1]);
		*prev_p = p[0];
	}
}

static void	handle_empty_env(t_cmd_list *cmd_list)
{
	int		i;
	char	**cmd;

	cmd = cmd_list->cmd;
	while (cmd[0] && cmd[0][0] == '\0' && cmd[1])
	{
		i = 0;
		free(cmd[0]);
		while (cmd[i + 1])
		{
			cmd[i] = cmd[i + 1];
			i++;
		}
		cmd[i] = NULL;
	}
}

static void	handle_cmd(t_shell *shell, pid_t pid, int *p, int *prev_p)
{
	t_cmd_list	*cmd_list;

	cmd_list = shell->cmd_list;
	if (!cmd_list->cmd[0] || cmd_list->cmd[0][0] == '\0')
		shell->exit_status = 0;
	else if (is_builtin_parent(cmd_list->cmd[0]))
		shell->exit_status = builtin_cmd(cmd_list, shell->env,
				shell->exit_status);
	else
	{
		if (cmd_list->next)
			pipe(p);
		pid = fork();
		if (pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			execute_child_process(shell, p, *prev_p);
		}
		if (!cmd_list->next)
			shell->last_pid = pid;
		signal_int(EXEC);
		signal_quit();
		close_prev_and_update(prev_p, p, cmd_list);
	}
}

static void	execution_process(t_shell *shell, pid_t pid, int *prev_p)
{
	t_cmd_list	*head;
	t_cmd_list	*cmd_list;
	int			p[2];

	cmd_list = shell->cmd_list;
	head = cmd_list;
	while (cmd_list)
	{
		init_heredoc(shell);
		shell->cmd_list = cmd_list;
		handle_empty_env(cmd_list);
		handle_cmd(shell, pid, p, prev_p);
		cmd_list = cmd_list->next;
	}
	shell->cmd_list = head;
}

void	parsing(t_shell *shell)
{
	pid_t		pid;
	int			prev_p;
	int			err;

	prev_p = -1;
	shell->last_pid = -1;
	shell->fd = 0;
	pid = -1;
	execution_process(shell, pid, &prev_p);
	if (prev_p != -1)
		close(prev_p);
	pid = wait(&err);
	while (pid > 0)
	{
		if (pid == shell->last_pid)
		{
			if (WIFEXITED(err))
				shell->exit_status = WEXITSTATUS(err);
			else if (WIFSIGNALED(err))
				shell->exit_status = 128 + WTERMSIG(err);
		}
		pid = wait(&err);
	}
}
