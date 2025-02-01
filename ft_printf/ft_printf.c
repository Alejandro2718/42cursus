/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:49:10 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/01 16:33:31 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include "ft_printf.h"

static int	letter_in_set(char letter, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (letter == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%' && letter_in_set(string[i + 1], "cspdiuxX%"))
		{
			len += print_convertion((char *)&string[i], args);
			i += 2;
			if (string[i] == '\0')
				break ;
		}
		else
		{
			len += print_char(string[i]);
			i++;
		}
	}
	va_end(args);
	return (len);
}
