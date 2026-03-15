/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:16:40 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/29 17:54:37 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_all_env(void)
{
	extern char	**environ;
	int			i;
	char		*equal_sign;
	char		*name;

	i = 0;
	while (environ[i])
	{
		equal_sign = ft_strchr(environ[i], '=');
		if (equal_sign)
		{
			name = ft_substr(environ[i], 0, equal_sign - environ[i]);
			printf("declare -x %s=\"%s\"\n", name, equal_sign + 1);
			free(name);
		}
		else
			printf("declare -x %s\n", environ[i]);
		i++;
	}
}

static void	process_export_arg(char **cmd, int *i)
{
	char	*eq;
	char	*name;
	char	*value;

	eq = ft_strchr(cmd[*i], '=');
	if (eq)
	{
		name = ft_substr(cmd[*i], 0, eq - cmd[*i]);
		value = ft_strdup(eq + 1);
		if (cmd[*i + 1] && !ft_strchr(cmd[*i + 1], '='))
		{
			value = ft_strjoin(value, cmd[*i + 1]);
			(*i)++;
		}
		setenv(name, value, 1);
		free(name);
		free(value);
	}
}

int	builtin_export(char **cmd, char **envp)
{
	int	i;
	int	exit_status;

	(void)envp;
	if (!cmd[1])
		return (print_all_env(), 0);
	exit_status = 0;
	i = 1;
	while (cmd[i])
	{
		if (!is_valid_identifier(cmd[i]))
		{
			ft_putstr_fd("export: `", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			exit_status = 1;
		}
		else
			process_export_arg(cmd, &i);
		i++;
	}
	return (exit_status);
}
