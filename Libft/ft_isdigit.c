/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:42:58 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/11 20:29:31 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function check if "d" is in a number(digit) by checking
the ascii value from 0 to 9, return (1) if "d" is a number
 and return (0) if not.
*/
int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
	{
		return (1);
	}
	else
		return (0);
}
