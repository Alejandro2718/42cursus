/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:49:10 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/25 16:23:14 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include "libftprintf.h"

void	print_char(char a)
{
	write(1, &a, 1);
}

int	ft_printf(const char *string, ...)
{
	int	i;

	i = 0;
	if (string)
	{
		while (string[i] != '\0')
		{
			print_char(string[i]);
			i++;
		}
	}
	return (i);
}
