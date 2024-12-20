/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:40:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/20 21:40:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function takes a uppercase as int value,
if is uppercase, this function transform to lower, otherwise
return the same int entered unchanged.
*/
#include <stddef.h>

int	ft_tolower(int c)
{
	int lower;

	if (c >= 'a' && c <= 'z')
	{
		lower = c + 32;
		return (lower);
	}
	return (c);
}
