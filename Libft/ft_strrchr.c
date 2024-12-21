/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:18:26 by alejjime          #+#    #+#             */
/*   Updated: 2024/12/21 20:11:36 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This function returns a pointer to
the last appearance of a character onward
*/

char	*ft_strrchr(const char *str, int chr)
{
	char	*temp;
	int		i;
	char	*string;

	i = 0;
	string = (char *)str;
	while (string[i] != '\0')
	{
		if (string[i] == (char)chr)
		{
			temp = &string[i];
		}
		i++;
	}
	if (chr == '\0')
	{
		return ((char *)&string[i]);
	}
	return (temp);
}
