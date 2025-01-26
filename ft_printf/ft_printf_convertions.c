/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:48:26 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/26 17:34:35 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	letter_in_set(char letter, const char *set)
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

void	print_convertion(char *s, va_list args)
{
	int	i;

	i = 0;
	if (s[i + 1] == '%')
	{
		print_char('%');
	}
	if (s[i + 1] == 'c')
	{
		print_char(va_arg(args, int));
	}
}
