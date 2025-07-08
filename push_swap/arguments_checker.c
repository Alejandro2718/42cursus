/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:38:59 by alejjime          #+#    #+#             */
/*   Updated: 2025/07/08 19:00:30 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if ((ft_strncmp(argv[i], argv[j], ft_strlen(argv[i]))) == 0
				&& ft_strlen(argv[i]) == ft_strlen(argv[j]))
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	int_size(char *argv)
{
	int		temp;
	char	*str1;

	temp = ft_atoi(argv);
	str1 = ft_itoa(temp);
	if (!ft_strncmp(str1, argv, ft_strlen(argv)))
		return (0);
	else
		return (1);
}

int	check_arg(char *argv)
{
	int	i;

	i = 0;
	if (int_size(argv) || (argv[i] == '-' && !(ft_isdigit(argv[i + 1]))))
	{
		ft_printf("Error\n");
		return (0);
	}
	i++;
	if (argv && ft_strncmp(argv, "", ft_strlen(argv)))
	{
		while (argv[i] != '\0')
		{
			if (ft_isdigit(argv[i]) && argv[i] != '-')
				i++;
			else
			{
				ft_printf("Error\n");
				return (0);
			}
		}
		return (1);
	}
	ft_printf("Error\n");
	return (0);
}
