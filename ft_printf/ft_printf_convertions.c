/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:48:26 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/30 20:04:01 by alejjime         ###   ########.fr       */
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
	int	len_convertion;

	len_convertion = 0;
	if (s[1] == '%')
		len_convertion = print_char('%');
	else if (s[1] == 'c')
		len_convertion = print_char(va_arg(args, int));
	else if (s[1] == 's')
		len_convertion = ft_putstr_fd(va_arg(args, char *), 1);
	// else if (s[1] == 'p')
	// 	len_convertion = ft_putstr_fd(ft_itoa_base(va_arg(args, unsigned long),
	// 				16, "0123456789abcdef"), 1);
	else if (s[1] == 'd' || s[1] == 'i')
		len_convertion = ft_putstr_fd(ft_itoa_base(va_arg(args, int), 10,
					"0123456789"), 1);
	// else if (s[i + 1] == 'u')
	// 	len_convertion = ft_putstr_fd(ft_itoa_base(va_arg(args, unsigned int),
	// 				10, "0123456789"), 1);
	else if (s[1] == 'x')
	{
		len_convertion = ft_putstr_fd(ft_itoa_base(va_arg(args, unsigned int),
					16, "0123456789abcdef"), 1);
	}
	else if (s[1] == 'X')
	{
		len_convertion = ft_putstr_fd(ft_itoa_base(va_arg(args, unsigned int),
					16, "0123456789ABCDEF"), 1);
	}
	return (len_convertion);
}
