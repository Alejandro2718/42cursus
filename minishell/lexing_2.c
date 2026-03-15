/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:08:47 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/23 17:24:22 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	is_escapable(char c)
{
	return (c == '"' || c == '$' || c == '`' || c == '\\');
}

static char	*process_backslash(char const *prompt, unsigned int *i,
		char *result, unsigned int end)
{
	char	str[2];

	if (prompt[*i + 1] && *i + 1 < end && is_escapable(prompt[*i + 1]))
		(*i)++;
	str[0] = prompt[(*i)++];
	str[1] = '\0';
	return (append_str(result, ft_strdup(str)));
}

static char	*process_text(char const *prompt, unsigned int *i, char *result,
		unsigned int end)
{
	unsigned int	start;

	start = *i;
	while (*i < end && prompt[*i] && prompt[*i] != '\"' && prompt[*i] != '\\'
		&& prompt[*i] != '$')
		(*i)++;
	return (append_str(result, ft_substr(prompt, start, *i - start)));
}

char	*double_quoted_substr(char const *prompt, unsigned int start,
		size_t len)
{
	char			*result;
	unsigned int	i;
	unsigned int	end;

	result = ft_strdup("");
	if (!prompt || !result)
		return (NULL);
	i = start;
	end = start + len;
	while (i < end && prompt[i] && prompt[i] != '\"')
	{
		if (prompt[i] == '\\')
			result = process_backslash(prompt, &i, result, end);
		else if (prompt[i] == '$')
			result = append_str(result, expand_variable(prompt, &i));
		else
			result = process_text(prompt, &i, result, end);
	}
	return (result);
}
