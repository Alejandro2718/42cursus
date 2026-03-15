/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_tokenizing_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 17:32:24 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/29 17:53:25 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	until_end_double_quoted(const char *prompt, int *end, int *start)
{
	while (prompt[*end] != '\0' && prompt[*end] != '\"')
		(*end)++;
	return (*end - *start);
}

t_token	*read_double_quoted(const char *prompt, int *i)
{
	t_token	*token;
	int		start;
	int		end;
	int		len;

	if (!prompt || !i)
		return (NULL);
	start = *i + 1;
	end = start;
	len = until_end_double_quoted(prompt, &end, &start);
	if (prompt[end] == '\0')
		return (NULL);
	token = create_token();
	if (!token)
		return (NULL);
	token->value = double_quoted_substr(prompt, start, len);
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	token->type = T_WORD;
	*i = end + 1;
	return (token);
}
