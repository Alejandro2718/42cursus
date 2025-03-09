/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:18:26 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/27 19:16:10 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function returns a pointer to
the last appearance of a character onward
*/
#include "libft.h"

char	*ft_strrchr(const char *str, int chr)
{
	char	*temp;
	int		i;

	i = 0;
	temp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)chr)
			temp = (char *)&str[i];
		i++;
	}
	if ((char)chr == '\0')
		return ((char *)&str[i]);
	return (temp);
}
