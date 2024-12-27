/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:25:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/27 18:22:26 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function return a pointer to the location
of the string beginning with the searched letter
*/
#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	int		i;
	char	temp;
	char	*string;

	i = 0;
	string = (char *)str;
	while (string[i] != '\0')
	{
		if (string[i] == (char)search_str)
			return (&string[i]);
		i++;
	}
	if (search_str == '\0')
		return ((char *)&string[i]);
	return (NULL);
}
