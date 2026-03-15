/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:04:28 by adanilov          #+#    #+#             */
/*   Updated: 2025/11/29 17:09:07 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	create_redir(t_cmd_list **list, t_token **token);

t_cmd_list	*create_new_list(t_token *token)
{
	t_cmd_list	*list;
	int			cmd_size;
	int			rd_size;

	rd_size = redir_size(token);
	cmd_size = token_size(token) - (rd_size * 2);
	list = malloc(sizeof(t_cmd_list));
	if (!list)
		return (NULL);
	list->cmd = malloc((cmd_size + 1) * sizeof(char *));
	if (!list->cmd)
	{
		free(list);
		return (NULL);
	}
	list->redir = NULL;
	list->next = NULL;
	return (list);
}

static void	concatenate_into_cmd_argument(
	t_cmd_list ***list,
	t_token ***token,
	int *cmd_counter)
{
	char	*concatenated;
	char	*temp;

	concatenated = ft_strdup((**token)->value);
	**token = (**token)->next;
	while (**token && (**token)->type == T_WORD
		&& (**token)->no_space_before)
	{
		temp = ft_strjoin(concatenated, (**token)->value);
		free(concatenated);
		concatenated = temp;
		**token = (**token)->next;
	}
	(**list)->cmd[(*cmd_counter)++] = concatenated;
}

int	fill_list_node(t_cmd_list **list, t_token **token)
{
	int		i;

	i = 0;
	while (*token && (*token)->type != T_PIPE && (*token)->type != T_END)
	{
		if (is_redir((*token)->type))
		{
			if ((*token)->next->type != T_WORD)
			{
				ft_putstr_fd("syntax error: Redirection without filename\n", 2);
				return (0);
			}
			create_redir(list, token);
		}
		else if ((*token)->type == T_WORD)
			concatenate_into_cmd_argument(&list, &token, &i);
		else
			*token = (*token)->next;
	}
	(*list)->cmd[i] = 0;
	return (1);
}

t_cmd_list	*create_list_from_tokens(t_token_list *tokens)
{
	t_cmd_list	*list;
	t_cmd_list	*list_head;
	t_cmd_list	*list_cur;
	t_token		*token;

	token = tokens->head;
	list_head = NULL;
	list_cur = NULL;
	while (token && token->type != T_END)
	{
		list = create_new_list(token);
		if (!fill_list_node(&list, &token))
		{
			free_cmd_list(&list);
			return (NULL);
		}
		if (!list_head)
			list_head = list;
		else
			list_cur->next = list;
		list_cur = list;
		if (token && token->type == T_PIPE)
			token = token->next;
	}
	return (list_head);
}
