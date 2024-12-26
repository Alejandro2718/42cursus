/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:33:17 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/26 14:53:39 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function created a copy with the 
same memory space from the oringal gave as 
parameter.
And return a pointer to the beginning of
the block of memory copied from the original.
*/
#include "libft.h"

char	*strdup(const char *s)
{
	char	*copy;
	int		size;
	int		i;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}

	copy = malloc((size + 1) * sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
