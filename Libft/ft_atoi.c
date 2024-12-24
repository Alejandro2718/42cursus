/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:13:06 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/24 21:16:31 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	temp;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		i++;
		negative = 1;
	}
	else if (str[i] == '+')
	{
		i++;
		negative = 0;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		temp = temp + (str[i] - '0');
		if (str[i + 1] != '\0')
			temp *= 10;
		i++;
	}
	if (negative)
		return (temp * -1);
	return (temp);
}
