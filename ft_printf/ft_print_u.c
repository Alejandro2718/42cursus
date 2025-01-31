/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:45:06 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/31 20:48:10 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_unsigned(unsigned int n, int base, char *dec)
{
	char	*str;
	int		i;
	int		len;

	len = leng(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (n)
	{
		str[i] = dec[n % base];
		n /= base;
		i++;
	}
	return (ft_strrev(str));
}

int	print_u(char *s, va_list args)
{
	unsigned int	i;
	int				len;

	i = va_arg(args, unsigned int);
	s = ft_itoa_unsigned(i, 10, "0123456789");
	len = ft_putstr_fd(s, 1);
	free(s);
	return (len);
}
