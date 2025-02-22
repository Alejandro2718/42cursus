/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:55:30 by marvin            #+#    #+#             */
/*   Updated: 2024/12/27 19:31:53 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function takes a lowercase as int value,
if is lowercase, this transform to upper, otherwise
return the same int entered unchanged.
*/
#include "libft.h"

int	ft_toupper(int c)
{
	int	upper;

	if (c >= 'a' && c <= 'z')
	{
		upper = c - 32;
		return (upper);
	}
	return (c);
}
