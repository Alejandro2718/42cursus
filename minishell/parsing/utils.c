/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:33:47 by artem             #+#    #+#             */
/*   Updated: 2025/11/29 18:24:32 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	is_redir(t_token_type type)
{
	return (type == T_REDIR_OUT || type == T_REDIR_IN
		|| type == T_REDIR_OUT_APPEND || type == T_HEREDOC);
}

int	token_size(t_token *lst)
{
	int		size;
	t_token	*tmp;

	tmp = lst;
	size = 0;
	while (tmp && tmp->type != T_PIPE && tmp->type != T_END)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	redir_size(t_token *lst)
{
	t_token	*tmp;
	int		size;

	tmp = lst;
	size = 0;
	while (tmp && tmp->type != T_PIPE && tmp->type != T_END)
	{
		if (is_redir(tmp->type))
			size++;
		tmp = tmp->next;
	}
	return (size);
}

char	*expand_exit_status(char *str, int exit_status)
{
	char	*result;
	char	*exit_str;
	char	*temp;
	char	*pos;
	char	*marker;

	if (!str)
		return (NULL);
	marker = "\x01EXIT_STATUS\x01";
	pos = ft_strnstr(str, marker, ft_strlen(str));
	if (!pos)
		return (ft_strdup(str));
	exit_str = ft_itoa(exit_status);
	result = ft_substr(str, 0, pos - str);
	temp = ft_strjoin(result, exit_str);
	free(result);
	result = temp;
	temp = ft_strjoin(result, pos + ft_strlen(marker));
	free(result);
	free(exit_str);
	return (temp);
}

void	expand_cmd_exit_status(t_cmd_list *cmd_list, int exit_status)
{
	int		i;
	char	*expanded;
	char	*marker;

	marker = "\x01EXIT_STATUS\x01";
	while (cmd_list)
	{
		i = 0;
		while (cmd_list->cmd[i])
		{
			if (ft_strnstr(cmd_list->cmd[i], marker,
					ft_strlen(cmd_list->cmd[i])))
			{
				expanded = expand_exit_status(cmd_list->cmd[i], exit_status);
				free(cmd_list->cmd[i]);
				cmd_list->cmd[i] = expanded;
			}
			i++;
		}
		cmd_list = cmd_list->next;
	}
}
