/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:13:06 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/25 14:40:54 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This functions takes a pointer to a string
and convert the numbers in the string into 
integer and return it
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	temp;

	i = 0;
	negative = 0;
	temp = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + (str[i] - '0');
		i++;
	}
	if (negative)
		return (temp * -1);
	return (temp);
}
