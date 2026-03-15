/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:44:19 by artem             #+#    #+#             */
/*   Updated: 2025/11/29 19:16:38 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	if_not_found(t_cmd_list *cmd_list);
int	if_dir(t_cmd_list *cmd_list, char *exe_path);

static char	*get_cmd_if_path_given(char *cmd)
{
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

static char	*get_executable_path(t_cmd_list *cmd_list)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	if (ft_strchr(cmd_list->cmd[0], '/'))
		return (get_cmd_if_path_given(cmd_list->cmd[0]));
	paths = ft_split(getenv("PATH"), ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
			tmp = ft_strjoin(paths[i], "/");
		else
			tmp = ft_strdup(paths[i]);
		path = ft_strjoin(tmp, cmd_list->cmd[0]);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (free_split(paths), path);
		free(path);
		i++;
	}
	return (free_split(paths), NULL);
}

static void	execute_or_print_error(
	char *exe_path,
	t_cmd_list *cmd_list,
	char **env)
{
	int	status;

	status = 0;
	if (!exe_path)
	{
		status = if_not_found(cmd_list);
		free_cmd_list(&cmd_list);
		exit(status);
	}
	if (execve(exe_path, cmd_list->cmd, env) == -1)
	{
		status = if_dir(cmd_list, exe_path);
		free(exe_path);
		free_cmd_list(&cmd_list);
		exit(status);
	}
	exit(0);
}

static void	execute_cmd(t_shell *shell)
{
	char		*exe_path;
	t_redir		*redir;
	t_cmd_list	*cmd_list;

	cmd_list = shell->cmd_list;
	redir = cmd_list->redir;
	while (redir)
	{
		redirections(redir->type, redir->filename, shell->fd);
		redir = redir->next;
	}
	if (!cmd_list->cmd[0])
		exit(0);
	if (is_builtin_child(cmd_list->cmd[0]))
	{
		builtin_cmd(cmd_list, shell->env, shell->exit_status);
		exit(0);
	}
	exe_path = get_executable_path(cmd_list);
	execute_or_print_error(exe_path, cmd_list, shell->env);
}

void	execute_child_process(t_shell *shell, int *p, int prev_p)
{
	if (prev_p != -1)
	{
		dup2(prev_p, STDIN_FILENO);
		close(prev_p);
	}
	if (shell->cmd_list->next)
	{
		dup2(p[1], STDOUT_FILENO);
		close(p[0]);
		close(p[1]);
	}
	execute_cmd(shell);
}
