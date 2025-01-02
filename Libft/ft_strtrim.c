/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:08:45 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/02 16:01:31 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function return a copy of the string give
as a paramether but deleting the beginning and the end
of the string that matches with the set gave as paramether too.
(Look for the each character from set into s1)
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
	int		i;
	int		start;
	int		end;
	char	*s1_copy;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	while (set_in_string((char)s1[start], (char *)set) \
	== 1 && s1[start] != '\0')
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && set_in_string((char)s1[end], (char *)set) == 1)
		end--;
	if (start > end)
		return (ft_strdup(""));
	s1_copy = (char *)malloc(end - start + 2);
	if (!s1_copy)
		return (NULL);
	ft_strlcpy(s1_copy, &s1[start], end - start + 2);
	return (s1_copy);
}
