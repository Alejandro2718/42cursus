/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:31:15 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/27 21:55:07 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function create a space in memory
for a substring from the s string.
from the start point untill len, both
passed as paramethers.
*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			s_len;
	char			*sub;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return ((char *)malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
