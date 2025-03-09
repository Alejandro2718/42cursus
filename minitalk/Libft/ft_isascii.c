/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:22:08 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/11 20:32:09 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function check if "as" is in the ascii table by checking
the ascii value from 0 to 127, return (1) if "as" is in
the ascii table and return (0) if not.
*/
int	ft_isascii(int as)
{
	if (as >= 0 && as <= 127)
	{
		return (1);
	}
	return (0);
}
