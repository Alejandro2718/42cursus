/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:40:37 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/27 19:32:00 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function takes two strings and try to find the 
little string into the big string, return big if little 
is empty and null if little is not find into big 
*/
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (j < len && big[j] != '\0')
	{
		i = 0;
		while (j + i < len && little[i] != '\0' && little[i] == big[j + i])
		{
			if (little[i + 1] == '\0')
				return ((char *)&big[j]);
			i++;
		}
		j++;
	}
	return (NULL);
}
