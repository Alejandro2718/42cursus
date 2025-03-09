/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:23:20 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/29 17:07:52 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function allocate memory for
the concatenation of 2 strings
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	int		i;
	int		j;
	char	*result;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	total = i + j;
	result = malloc(total + 1);
	start = result;
	if (!result)
		return (NULL);
	while (*s1 != '\0')
		*result++ = *s1++;
	while (*s2 != '\0')
		*result++ = *s2++;
	*result = '\0';
	return (start);
}
