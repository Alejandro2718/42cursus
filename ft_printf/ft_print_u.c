/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:45:06 by alejjime          #+#    #+#             */
/*   Updated: 2025/02/01 16:49:26 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	leng_for_u(unsigned long long n, int base)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_unsigned(unsigned int n, int base, char *dec)
{
	char	*str;
	int		i;
	int		len;

	len = leng_for_u(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (n)
	{
		str[i] = dec[n % base];
		n /= base;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

int	print_u(char *s, va_list args)
{
	unsigned int	i;
	int				len;

	i = va_arg(args, unsigned int);
	if (i == 0)
	{
		len = print_char('0');
		return (len);
	}
	s = ft_itoa_unsigned(i, 10, "0123456789");
	len = ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
