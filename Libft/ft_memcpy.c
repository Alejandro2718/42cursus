/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:06:09 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/18 17:53:07 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function take a source and destination,
and a number, the function will copy n number of
bytes from source to destination and return the destination
with what was copied from source into the dest
*/
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	i = 0;
	if (s == d)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
