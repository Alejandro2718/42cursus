/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:59:37 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/14 17:26:07 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;
	const unsigned char	*buffer;

	s = (const unsigned char *) src;
	buffer = s;
	d = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		d[i] = buffer[i];
		i++;
	}

	return (dest);
}
