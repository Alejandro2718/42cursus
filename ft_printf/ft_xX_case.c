/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:38 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/31 20:47:55 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_x(unsigned long long n, int base, char *hex)
{
	char	*str;
	int		i;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = leng(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (n)
	{
		str[i] = hex[n % base];
		n /= base;
		i++;
	}
	return (ft_strrev(str));
}

int	print_x_hex(char *s, va_list args, char *base)
{
	unsigned long long	n;
	int					len;

	len = 0;
	n = (unsigned long long)va_arg(args, void *);
	s = ft_itoa_x(n, 16, base);
	len += ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
