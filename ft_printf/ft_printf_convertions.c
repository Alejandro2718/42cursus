/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:48:26 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/29 18:48:27 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_char(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_convertion(char *s, va_list args)
{
	int	i;
	int	len_convertion;

	i = 0;
	len_convertion = 0;
	if (s[i + 1] == '%')
	{
		len_convertion = print_char('%');
	}
	else if (s[i + 1] == 'c')
	{
		len_convertion = print_char(va_arg(args, int));
	}
	else if (s[i + 1] == 's')
	{
		len_convertion = ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if (s[i + 1] == 'd')
	{
		len_convertion = ft_putstr_fd(ft_itoa_base(va_arg(args, int), 10), 1);
	}
	return (len_convertion);
}
