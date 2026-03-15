/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:14:39 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/23 17:47:47 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	skip_whitespace(const char *prompt, int *i)
{
	while (prompt[*i] && (prompt[*i] == ' ' || prompt[*i] == '\t'))
		(*i)++;
}

static int	is_word_delimiter(char c)
{
	return (!c || isspace(c) || c == '|' || c == '>' || c == '<' || c == '\''
		|| c == '"');
}

static char	*process_backslashes(char *str)
{
	char	*result;
	char	*temp;
	char	ch[2];
	int		i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1])
			i++;
		ch[0] = str[i++];
		ch[1] = '\0';
		temp = ft_strjoin(result, ch);
		free(result);
		result = temp;
	}
	return (result);
}

static void	process_word_expansions(t_token *token)
{
	char	*temp;

	if (ft_strchr(token->value, '\\'))
	{
		temp = process_backslashes(token->value);
		free(token->value);
		token->value = temp;
	}
	if (ft_strchr(token->value, '$'))
	{
		temp = expand_word_variables(token->value);
		if (temp)
		{
			free(token->value);
			token->value = temp;
		}
	}
}

t_token	*read_word(const char *prompt, int *i)
{
	t_token	*token;
	int		j;

	token = create_token();
	if (!token)
		return (NULL);
	j = *i;
	while (!is_word_delimiter(prompt[*i]))
		(*i)++;
	token->value = ft_calloc((*i - j) + 1, sizeof(char));
	if (!token->value)
		return (free(token), NULL);
	ft_strlcpy(token->value, &prompt[j], (*i - j) + 1);
	process_word_expansions(token);
	token->type = T_WORD;
	return (token);
}
