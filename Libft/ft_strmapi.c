/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:45:36 by alejjime          #+#    #+#             */
/*   Updated: 2025/01/03 21:25:36 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function apply a external function
passed as argument to each character of
an string (passed as argument too), and
return a new string created with malloc
with the result of apllying this function
to the string
*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	new_str = malloc(i + 1);
	if (new_str == NULL)
		return (NULL);
	new_str[i + 1] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	return (new_str);
}
