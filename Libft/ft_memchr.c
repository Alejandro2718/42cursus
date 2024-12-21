/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:31:34 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/21 20:25:08 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function search for a char in the 
memory area and return a pointer
to the char onward.
*/
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*string;

	string = (char *)s;
	i = 0;
	while (i < n)
	{
		if (string[i] == (char)c)
		{
			return (&string[i]);
		}
		i++;
	}
	return (NULL);
}
