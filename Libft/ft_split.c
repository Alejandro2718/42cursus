/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:51:41 by marvin            #+#    #+#             */
/*   Updated: 2025/01/02 18:12:53 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include "libft.h"

int	words_in_s(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != c)
		{
			i++;
		}
		words++;
		while (s[i] == c)
			i++;
	}
	return (words);
}

int	each_word_len(char *s, char c, int word_num)
{
	int		word_len;
	int		i;
	int		j;

	i = 0;
	while (s[i] == c)
		i++;
	j = 0;
	while (j <= word_num)
	{
		word_len = 0;
		while (s[i] != c)
		{
			word_len++;
			i++;
		}
		while (s[i] == c)
			i++;
		j++;
	}
	return (word_len);
}

char	*populate_array(char *s, char c, int word_num)
{
	char	*str_in;
	int		i;
	int		j;

	str_in = malloc(each_word_len(s, c, word_num) + 1);
	while ()

}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;

	if (!s || !c)
		return (NULL);
	words = words_in_s(s, c);
	array = malloc(words + 1);
	// hasta aqui bien
	i = 0;
	while (i < words)
	{
		array[i] = populate_array(s, c, i);
		i++;
	}
	array[i] = NULL;
	return (array);
}
