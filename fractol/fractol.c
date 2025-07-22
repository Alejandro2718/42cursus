/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:08 by alejjime          #+#    #+#             */
/*   Updated: 2025/07/22 19:35:45 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_printf("Please enter:\n");
	ft_printf("\t\"./fractol mandelbrot\"\n");
	ft_printf("\t\tOR\n");
	ft_printf("\t\"./fractol julia <real_part> <imaginary_part>\"\n");
	ft_printf("Examples:\n");
	ft_printf("\t./fractol julia -1.729 0\n");
	ft_printf("\t./fractol julia -0.4 0.6\n");
	ft_printf("\t./fractol julia 0.285 0.01\n");
}

static int	is_valid_float(char *str)
{
	int	i;
	int	has_dot;

	i = 0;
	has_dot = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
	Two possible prompts:
		./fractol mandelbrot
		./fractol julia <r> <i>
*/
int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		fractol.name = argv[1];
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connec);
	}
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!is_valid_float(argv[2]) || !is_valid_float(argv[3]))
		{
			ft_printf("Error: Invalid numeric parameters for Julia set\n");
			print_usage();
			return (1);
		}
		fractol.name = argv[1];
		fractol.julia_x = atodbl(argv[2]);
		fractol.julia_y = atodbl(argv[3]);
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connec);
	}
	else
	{
		print_usage();
		return (1);
	}
	return (0);
}
