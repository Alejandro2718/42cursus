/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:25:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/20 22:25:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/
char	*ft_strchr(const char *str, int search_str)
{
	int		i;
	char	temp;

	i = 0;
	temp = search_str + '0';
	while (str[i] != '\0')
	{
		if (str[i] == temp)
			return (str);
		i++;
	}
}
