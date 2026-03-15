/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 09:30:05 by artem             #+#    #+#             */
/*   Updated: 2025/11/29 18:03:55 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int		builtin_export(char **cmd, char **envp);
void	builtin_env(char **envp);
int		builtin_exit(char **cmd);

void	builtin_echo(char **cmd, int exit_status)
{
	int	i;
	int	no_newline;

	(void)exit_status;
	no_newline = 0;
	i = 1;
	if (cmd[1] && ft_strncmp(cmd[1], "-n", 2) == 0 && cmd[1][2] == '\0')
	{
		no_newline = 1;
		i = 2;
	}
	while (cmd[i])
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1])
			printf(" ");
		i++;
	}
	if (!no_newline)
		printf("\n");
}

void	builtin_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("pwd");
}

int	builtin_cd(char **cmd)
{
	char	*path;
	char	cwd[1024];

	if (cmd[1] && cmd[2])
		return (ft_putstr_fd("cd: too many arguments\n", 2), 1);
	if (!cmd[1])
	{
		path = getenv("HOME");
		if (!path)
			return (ft_putstr_fd("cd: HOME not set\n", 2), 1);
	}
	else
		path = cmd[1];
	if (getcwd(cwd, sizeof(cwd)))
		setenv("OLDPWD", cwd, 1);
	if (chdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)))
		setenv("PWD", cwd, 1);
	return (0);
}

void	builtin_unset(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		unsetenv(cmd[i]);
		i++;
	}
}

int	builtin_cmd(t_cmd_list *cmd_list, char **envp, int exit_status)
{
	char	*cmd;
	int		ret;

	cmd = cmd_list->cmd[0];
	ret = 0;
	if (ft_strncmp(cmd, "echo", 4) == 0)
		builtin_echo(cmd_list->cmd, exit_status);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		ret = builtin_cd(cmd_list->cmd);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		builtin_pwd();
	else if (ft_strncmp(cmd, "export", 6) == 0)
		ret = builtin_export(cmd_list->cmd, envp);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		builtin_unset(cmd_list->cmd);
	else if (ft_strncmp(cmd, "env", 3) == 0)
		builtin_env(envp);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		ret = builtin_exit(cmd_list->cmd);
	return (ret);
}
