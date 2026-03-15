/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:53:39 by alejjime          #+#    #+#             */
/*   Updated: 2025/11/23 17:16:35 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*append_str(char *result, char *to_add)
{
	char	*new_result;

	if (!to_add)
		return (result);
	new_result = ft_strjoin(result, to_add);
	free(to_add);
	if (!new_result)
		return (result);
	free(result);
	return (new_result);
}

char	*get_env_value(char *var_name)
{
	char	*value;

	if (!var_name)
		return (ft_strdup(""));
	value = getenv(var_name);
	if (!value)
		return (ft_strdup(""));
	return (ft_strdup(value));
}

char	*single_quoted_substr(char const *prompt, unsigned int start,
		size_t len)
{
	return (ft_substr(prompt, start, len));
}

static char	*process_text_word(const char *word, unsigned int *i, char *result)
{
	unsigned int	start;

	start = *i;
	while (word[*i] && word[*i] != '$')
		(*i)++;
	return (append_str(result, ft_substr(word, start, *i - start)));
}

char	*expand_word_variables(const char *word)
{
	char			*result;
	unsigned int	i;

	if (!word)
		return (NULL);
	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (word[i])
	{
		if (word[i] == '$')
			result = append_str(result, expand_variable(word, &i));
		else
			result = process_text_word(word, &i, result);
	}
	return (result);
}
