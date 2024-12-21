/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:04:16 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/21 19:28:42 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function compares n bytes of both strings
and return a integer: 
- Negative, if the str1 is less than str2.
- Positive, if the str2 is less than str1.
- zero, if the str1 is equal to str2.
*/
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while ((char)s1[i] != '\0' && (char)s2[i] != '\0' && i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
