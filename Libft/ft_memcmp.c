/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:16:49 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/27 18:08:01 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function takes two memories pointers
and comparate them:
- Negative, if the str1 is less than str2.
- Positive, if the str2 is less than str1.
- zero, if the str1 is equal to str2.
*/
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	i = 0;
	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (string1[i] < string2[i])
			return (-1);
		if (string1[i] > string2[i])
			return (1);
		i++;
	}
	return (0);
}
