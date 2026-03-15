/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:53:46 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/23 18:33:13 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
			MAIN FLOW -------------------------------------------
*/

int	dispatch_next_token(const char *prompt, int *i, t_token_list *list,
		int no_space)
{
	t_token	*token;
	char	c;

	token = NULL;
	if (!prompt || !i || !list)
		return (-1);
	c = prompt[*i];
	if (c == '|' || c == '>' || c == '<')
		token = read_operator(prompt, i);
	else if (c == '\'')
		token = read_single_quoted(prompt, i);
	else if (c == '"')
		token = read_double_quoted(prompt, i);
	else
		token = read_word(prompt, i);
	if (!token)
		return (-1);
	token->no_space_before = no_space;
	append_token(list, token);
	return (0);
}

static int	check_no_space(t_token_list *list, const char *prompt, int i)
{
	char	prev;

	if (!list->tail)
		return (0);
	prev = prompt[i - 1];
	return (prev != ' ' && prev != '\t');
}

static t_token	*create_end_token(void)
{
	t_token	*token;

	token = create_token();
	if (!token)
		return (NULL);
	token->type = T_END;
	token->value = NULL;
	token->next = NULL;
	return (token);
}

t_token_list	*lexer(const char *prompt)
{
	t_token_list	*list;
	t_token			*end_token;
	int				i;

	if (!prompt)
		return (NULL);
	list = init_token_list();
	if (!list)
		return (NULL);
	i = 0;
	skip_whitespace(prompt, &i);
	while (prompt[i])
	{
		if (dispatch_next_token(prompt, &i, list, check_no_space(list, prompt,
					i)) < 0)
			return (free_token_list(list), NULL);
		skip_whitespace(prompt, &i);
	}
	end_token = create_end_token();
	if (!end_token)
		return (free_token_list(list), NULL);
	append_token(list, end_token);
	return (list);
}
