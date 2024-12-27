/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:40:33 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/27 19:32:12 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function return the lenght of a string by taking
the pointer(char *s) to that string and go throught
it until find the '\0' value. 
*/
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
