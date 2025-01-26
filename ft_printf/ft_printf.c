/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:49:10 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/26 17:28:55 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include "libftprintf.h"

void	print_char(char a)
{
	write(1, &a, 1);
}

static int	convertion(char *s, va_list args)
{
	int			i;
	const char	*flags = "cspdiuxX%";

	i = 0;
	if (letter_in_set(s[i], flags))
	{
		print_convertion(&s[i], args);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;

	i = 0;
	if (string)
	{
		while (string[i] != '\0')
		{
			if (string[i] == '%' && string[i + 1] != '\0')
			{
				va_start(args, string);
				if (convertion((char *)&string[i], args))
					i += 2;
			}
			print_char(string[i]);
			i++;
		}
	}
	return (i);
}
