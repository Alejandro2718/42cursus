/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:53:49 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/23 16:50:04 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	process_escape_char(char c)
{
	if (c == 'n')
		return ('\n');
	else if (c == 't')
		return ('\t');
	else if (c == 'r')
		return ('\r');
	else if (c == 'a')
		return ('\a');
	else if (c == 'b')
		return ('\b');
	else if (c == 'v')
		return ('\v');
	else if (c == 'f')
		return ('\f');
	else if (c == '\\')
		return ('\\');
	else
		return (c);
}

void	case_backslash(const char *prompt, unsigned int *i)
{
	if (prompt[*i + 1] == '"' || prompt[*i + 1] == '$' || prompt[*i + 1] == '`'
		|| prompt[*i + 1] == '\\' || prompt[*i + 1] == '\n')
		(*i)++;
}

char	*extract_var_name(const char *prompt, unsigned int *i)
{
	unsigned int	start;

	start = *i;
	while (prompt[*i] && (ft_isalnum(prompt[*i]) || prompt[*i] == '_'))
		(*i)++;
	if (*i > start)
		return (ft_substr(prompt, start, *i - start));
	return (NULL);
}

static char	*expand_variable_auxiliar(const char *prompt, unsigned int *i,
		char **var_name)
{
	if (prompt[*i] == '?')
	{
		(*i)++;
		return (ft_strdup("\x01EXIT_STATUS\x01"));
	}
	else if (prompt[*i] == '$')
	{
		(*i)++;
		return (ft_itoa(getpid()));
	}
	else if (ft_isdigit(prompt[*i]))
	{
		(*i)++;
		return (ft_strdup(""));
	}
	else
	{
		*var_name = extract_var_name(prompt, i);
		if (!*var_name)
		{
			return (ft_strdup("$"));
		}
	}
	return (NULL);
}

char	*expand_variable(const char *prompt, unsigned int *i)
{
	char	*var_name;
	char	*result;

	var_name = NULL;
	(*i)++;
	if (prompt[*i] == '{')
	{
		(*i)++;
		var_name = extract_var_name(prompt, i);
		if (prompt[*i] != '}')
			return (free(var_name), ft_strdup("$"));
		(*i)++;
	}
	result = expand_variable_auxiliar(prompt, i, &var_name);
	if (result)
		return (result);
	result = get_env_value(var_name);
	return (free(var_name), result);
}
