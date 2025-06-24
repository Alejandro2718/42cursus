/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:52:16 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/27 19:32:46 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function take the pointer to a string and
fill with '\0'(NULL) many spaces, from the pointer, 
as the size_t indicate.
Used to erase values of a string. 
*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
