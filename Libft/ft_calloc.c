/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:42:54 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/26 14:40:20 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function takes the nmemb spaces and
the size of data type size to create a 
pointer to a memory space with the required
space.
returns the pointer to the beginning of this new
memory block  
*/
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	char	*transform;
	size_t	total;
	size_t	i;

	i = 0;
	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	memory = malloc(total);
	if (!memory)
		return (NULL);
	transform = (char *)memory;
	while (i < total)
	{
		transform[i] = 0;
		i++;
	}
	return (memory);
}
