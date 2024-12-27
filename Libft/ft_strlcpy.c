/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:39:19 by marvin            #+#    #+#             */
/*   Updated: 2024/12/27 19:32:15 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function take source and destination and size, then 
copy size bytes from source to destination and return the
lenght of source.
*/
#include "libft.h"
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	j;

	j = 0;
	if (size > 0)
	{
		while (j < size - 1 && src[j] != '\0')
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	j = 0;
	while (src[j] != '\0')
		j++;
	return (j);
}
