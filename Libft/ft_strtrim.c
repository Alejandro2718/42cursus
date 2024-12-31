/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:08:45 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/31 21:26:33 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
#include "libft.h"

int	set_in_string(char letter, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (letter == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		i;
	int		j;
	int		start;
	int		end;
	int		set_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	end = 0;
	while (set_in_string(s1[start], set) == 1)
		start++;
	while (set_in_string(s1[start + i], set) != 1)
		i++;
}
