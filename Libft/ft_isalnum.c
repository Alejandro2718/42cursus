/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:59:25 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/11 20:31:02 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function check if "an" is in the alphabet/number by checking
the ascii value from A-a to Z-z or 0 to 9, return (1) if "an" is in
the alphabet/number and return (0) if not.
*/
int	ft_isalnum(int an)
{
	if (an >= 'A' && an <= 'Z' || an >= 'a' && an <= 'z' \
	|| an >= '0' && an <= '9')
	{
		return (1);
	}
	return (0);
}
