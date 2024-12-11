/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:29:16 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/11 20:29:07 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function check if "a" is in the alphabet by checking
the ascii value from A-a to Z-z, return (1) if "a" is in
the alphabet and return (0) if not.
*/
int	ft_isalpha(int a)
{
	if (a >= 'A' && a <= 'Z' || a >= 'a' && a <= 'z')
	{
		return (1);
	}
	else
		return (0);
}
