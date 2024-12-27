/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:40:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/27 19:31:53 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function takes a uppercase as int value,
if is uppercase, this function transform to lower, otherwise
return the same int entered unchanged.
*/
#include "libft.h"

int	ft_tolower(int c)
{
	int	lower;

	if (c >= 'A' && c <= 'Z')
	{
		lower = c + 32;
		return (lower);
	}
	return (c);
}
