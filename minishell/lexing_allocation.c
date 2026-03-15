/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:16:48 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/29 18:26:08 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_token(t_token *token)
{
	if (!token)
		return ;
	if (token->value)
		free(token->value);
	free(token);
}

void	free_token_list(t_token_list *list)
{
	t_token	*cur;
	t_token	*next;

	if (!list)
		return ;
	cur = list->head;
	while (cur)
	{
		next = cur->next;
		free_token(cur);
		cur = next;
	}
	free(list);
}

t_token_list	*init_token_list(void)
{
	t_token_list	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_token	*create_token(void)
{
	t_token	*token;

	token = malloc(sizeof(*token));
	if (!token)
		return (NULL);
	token->type = T_WORD;
	token->value = NULL;
	token->no_space_before = 0;
	token->next = NULL;
	return (token);
}

void	append_token(t_token_list *list, t_token *token)
{
	if (!list || !token)
		return ;
	if (!list->head)
	{
		list->head = token;
		list->tail = token;
	}
	else
	{
		list->tail->next = token;
		list->tail = token;
	}
}
