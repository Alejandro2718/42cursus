/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:54:49 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/29 19:22:23 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	char	*hex;
	int		i;
	int		neg;
	int		len;

	hex = "0123456789abcdef";
	neg = 0;
	len = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	i = n;
	while (i /= base)
		len++;
	len += neg + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (neg)
		str[0] = '-';
	while (len > neg)
	{
		len--;
		str[len] = hex[n % base];
		n /= base;
	}
	return (str);
}
