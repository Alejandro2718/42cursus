/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_p_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:37:05 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/31 20:14:07 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	aux;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	len--;
	while (i < len)
	{
		aux = str[i];
		str[i] = str[len];
		str[len] = aux;
		i++;
		len--;
	}
	return (str);
}

char	*ft_itoa_hex(unsigned long long n, int base, char *hex)
{
	char	*str;
	int		i;
	int		len;

	len = leng(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = hex[0];
		str[1] = '\0';
		return (str);
	}
	i = 0;
	while (n)
	{
		str[i] = hex[n % base];
		n /= base;
		i++;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

int	print_p_hex(char *s, va_list args)
{
	unsigned long long	n;
	int					len;

	n = (unsigned long long)va_arg(args, void *);
	s = ft_itoa_hex(n, 16, "0123456789abcdef");
	len = ft_putstr_fd("0x", 1);
	len += ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
