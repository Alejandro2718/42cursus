/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list_redirections.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:50:53 by adanilov          #+#    #+#             */
/*   Updated: 2025/11/29 15:52:36 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	concatenate_into_filename(t_redir *redir_lst, t_token **token)
{
	char	*temp;

	*token = (*token)->next;
	while (*token && (*token)->type == T_WORD && (*token)->no_space_before)
	{
		temp = ft_strjoin(redir_lst->filename, (*token)->value);
		free(redir_lst->filename);
		redir_lst->filename = temp;
		*token = (*token)->next;
	}
}

static t_redir	*create_and_fill_redir_node(t_token **token)
{
	t_redir	*lst;

	lst = malloc(sizeof(t_redir));
	if (!lst)
		return (NULL);
	lst->type = (*token)->type;
	*token = (*token)->next;
	lst->filename = ft_strdup((*token)->value);
	if (!lst->filename)
	{
		free(lst);
		return (NULL);
	}
	return (lst);
}

void	create_redir(t_cmd_list **list, t_token **token)
{
	t_redir	*redir_lst;
	t_redir	*tmp_lst;

	redir_lst = create_and_fill_redir_node(token);
	concatenate_into_filename(redir_lst, token);
	redir_lst->next = NULL;
	if (!(*list)->redir)
		(*list)->redir = redir_lst;
	else
	{
		tmp_lst = (*list)->redir;
		while (tmp_lst->next)
			tmp_lst = tmp_lst->next;
		tmp_lst->next = redir_lst;
	}
	redir_lst = NULL;
}
