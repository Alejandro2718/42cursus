/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:40:37 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/23 17:17:40 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function takes two strings and try to find the 
little string into the big string, return big if little 
is empty and null if little is not find into big 
*/
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (j < len && big[j] != '\0')
	{
		while (j < len && little[i] == big[j])
		{
			if (i == 0)
				temp = j;
			if (little[i + 1] == '\0')
				return ((char *)&big[temp]);
			i++;
			j++;
		}
		if (i > 0)
			j = temp + 1;
		else
			j++;
		i = 0;
	}
	return (NULL);
}
