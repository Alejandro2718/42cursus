/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:04:16 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/03 14:50:36 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function compares n bytes of both strings
and return a integer:
- Negative, if the str1 is less than str2.
- Positive, if the str2 is less than str1.
- zero, if the str1 is equal to str2.
*/
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				j;
	unsigned char	*c1;
	unsigned char	*c2;

	j = 0;
	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < n)
	{
		if (c1[i] < c2[i])
			return (-1);
		if (c1[i] > c2[i])
			return (1);
		i++;
	}
	return (0);
}
