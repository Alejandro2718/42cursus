/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:38 by alejjime          #+#    #+#             */
/*   Updated: 2025/03/09 14:57:29 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupf(char *s)
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

int	leng_for_x(unsigned long long n, int base)
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

char	*ft_itoa_x(unsigned long long n, int base, char *hex)
{
	char	*str;
	int		i;
	int		len;

	if (n == 0)
		return (ft_strdupf("0"));
	len = leng_for_x(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
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

int	print_x_hex(char *s, va_list args, char *base)
{
	unsigned long long	n;
	int					len;

	len = 0;
	n = (unsigned long long)va_arg(args, unsigned int);
	s = ft_itoa_x(n, 16, base);
	len += ft_putsprint_fd(s, 1);
	free(s);
	return (len);
}
