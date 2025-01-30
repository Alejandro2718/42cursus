/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:54:49 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/30 19:25:28 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*min_maximus(char *string)
{
	string = malloc(12);
	if (!string)
		return (NULL);
	string[0] = '-';
	string[1] = '2';
	string[2] = '1';
	string[3] = '4';
	string[4] = '7';
	string[5] = '4';
	string[6] = '8';
	string[7] = '3';
	string[8] = '6';
	string[9] = '4';
	string[10] = '8';
	string[11] = '\0';
	return (string);
}

void	negative_case(int *n, int *neg)
{
	if (*n < 0)
	{
		*neg = 1;
		*n = -(*n);
	}
	else
		*neg = 0;
}

int	leng(int i, int base, int len)
{
	i /= base;
	while (i)
	{
		i /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int n, int base, char *hex)
{
	char	*str;
	int		i;
	int		neg;
	int		len;

	len = 0;
	if (n == -2147483648)
		return (min_maximus(str));
	negative_case(&n, &neg);
	i = n;
	len = leng(i, base, len);
	len += neg + 1;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (neg)
		str[0] = '-';
	while (len-- > neg)
	{
		str[len] = hex[n % base];
		n /= base;
	}
	return (str);
}
