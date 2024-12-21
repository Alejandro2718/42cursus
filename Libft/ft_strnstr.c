/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:40:37 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/21 22:16:28 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little == "")
		return ((char *)big);
	while (i < len)
	{
		while (little[i] != '\0')
		{
			if ((char *)little[i] != (char *)big[i + j])
				i = 0;
			i++;
		}
		j++;
	}
	return (NULL);
}
