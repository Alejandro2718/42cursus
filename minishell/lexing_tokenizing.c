/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_tokenizing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanilov <adanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:21:29 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/29 18:25:59 by adanilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	set_operator_type(t_token *token, const char *prompt, int *i)
{
	if (prompt[*i] == '|' && ++(*i))
		token->type = T_PIPE;
	else if (prompt[*i] == '>')
	{
		token->type = T_REDIR_OUT;
		if (prompt[++(*i)] == '>' && ++(*i))
			token->type = T_REDIR_OUT_APPEND;
	}
	else if (prompt[*i] == '<')
	{
		token->type = T_REDIR_IN;
		if (prompt[++(*i)] == '<' && ++(*i))
			token->type = T_HEREDOC;
	}
}

t_token	*read_operator(const char *prompt, int *i)
{
	t_token	*token;
	int		j;

	token = create_token();
	if (!token)
		return (NULL);
	j = *i;
	set_operator_type(token, prompt, i);
	token->value = ft_calloc((*i - j) + 1, sizeof(char));
	if (!token->value)
		return (free(token), NULL);
	ft_strlcpy(token->value, &prompt[j], (*i - j) + 1);
	return (token);
}

static int	until_end_single_quoted(const char *prompt, int *end, int *start)
{
	while (prompt[*end] != '\0' && prompt[*end] != '\'')
		(*end)++;
	return (*end - *start);
}

t_token	*read_single_quoted(const char *prompt, int *i)
{
	t_token	*token;
	int		start;
	int		end;
	int		len;

	if (!prompt || !i)
		return (NULL);
	start = *i + 1;
	end = start;
	len = until_end_single_quoted(prompt, &end, &start);
	if (prompt[end] == '\0')
		return (NULL);
	token = create_token();
	if (!token)
		return (NULL);
	token->value = single_quoted_substr(prompt, start, len);
	if (!token->value)
	{
		free(token);
		return (NULL);
	}
	token->type = T_WORD;
	*i = end + 1;
	return (token);
}
