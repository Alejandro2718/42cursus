/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:51:41 by marvin            #+#    #+#             */
/*   Updated: 2025/01/05 17:24:10 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function split a string gave as paramether
based on an delimiter	character(which wont be included).
Splits the string in as many strings as necesary.
Return  an array of strings, ends with a NULL pointer.
*/
#include "libft.h"

int	words_in_s(char *s, char c)
{
	int	i;
	int	words;

	if (!s || *s == '\0')
		return (0);
	i = 0;
	words = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == c || s[i] == '\0')
			words++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (words);
}

int	each_word_len(char *s, char c, int word_num)
{
	int	word_len;
	int	i;
	int	j;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	j = 0;
	while (j <= word_num)
	{
		word_len = 0;
		while (s[i] != c && s[i] != '\0')
		{
			word_len++;
			i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
		j++;
	}
	return (word_len);
}

char	*populate_array(char *s, char c, int word_num)
{
	char	*str_in;
	int		i;
	int		start;
	int		p;

	p = each_word_len(s, c, word_num);
	str_in = ft_calloc(p + 1, sizeof(char));
	i = 0;
	while (word_num-- >= 0)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	i = 0;
	while (p--)
	{
		str_in[i] = s[start + i];
		i++;
	}
	str_in[i] = '\0';
	return (str_in);
}

char	**special_case(char **array, char *s)
{
	array = malloc(2 * sizeof(char *));
	if (!array)
		return (NULL);
	if (*s == '\0')
		array[0] = NULL;
	else
		array[0] = ft_strdup(s);
	array[1] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	if (c == '\0')
		return (special_case(array, (char *)s));
	words = words_in_s((char *)s, c);
	array = ft_calloc(words + 1, sizeof(char *));
	i = 0;
	while (i < words)
	{
		array[i] = populate_array((char *)s, c, i);
		if (!array[i])
		{
			while (i > 0)
				free(array[--i]);
			free(array);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
