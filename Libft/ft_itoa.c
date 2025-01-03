/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:47:58 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/03 20:44:55 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function transform a int into
its representation in ascii and store
it in a *char, asigning memory to create this.
*/
#include "libft.h"

char	*spe_case(void)
{
	char	*string;

	string = malloc(2);
	if (!string)
		return (NULL);
	string[0] = '0';
	string[1] = '\0';
	return (string);
}

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

char	*negative(char *string, int n, int n_num)
{
	int	temp;
	int	i;

	if (n == -2147483648)
		return (min_maximus(string));
	temp = -n;
	n_num = 1;
	while (temp > 0)
	{
		temp = temp / 10;
		n_num++;
	}
	string = malloc(n_num + 1);
	if (!string)
		return (NULL);
	temp = -n;
	string[n_num] = '\0';
	while (--n_num > 0)
	{
		string[n_num] = (temp % 10) + '0';
		temp = temp / 10;
	}
	string[0] = '-';
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		n_num;
	int		temp;
	int		i;

	if (n == 0)
		return (spe_case());
	if (n < 0)
		return (negative(string, n, 0));
	n_num = 0;
	temp = n;
	while (n > 0)
	{
		n = n / 10;
		n_num++;
	}
	string = ft_calloc(n_num + 1, sizeof(char));
	i = n_num;
	while (n_num-- > 0)
	{
		string[n_num] = (temp % 10) + '0';
		temp = temp / 10;
	}
	string[i] = '\0';
	return (string);
}
