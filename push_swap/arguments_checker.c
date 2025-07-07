/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:38:59 by alejjime          #+#    #+#             */
/*   Updated: 2025/07/02 19:18:50 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int int_size(char *argv)
{
	int temp = ft_atoi(argv);
	
	char *str1 = ft_itoa(temp);

	if (!ft_strncmp(str1, argv, ft_strlen(argv)))
		return (0);
	else
		return (1);
}

int	check_arg(char *argv)
{
	int	i;

	i = 0;
	if (int_size(argv) || (argv[i] == '-' && !(ft_isdigit(argv[i+1]))))
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
