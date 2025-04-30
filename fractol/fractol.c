/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:08 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/30 18:55:21 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Two possible prompts:
		./fractol mandelbrot
		./fractol julia <r> <i>
*/
int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		/*
		If prompt correct, start the fractal app
		*/
		fractol.name = argv[1];
		fractol_init(&fractol);
		// fractol_render(&fractol); // POR HACER
		mlx_loop(fractol.mlx_connec);
	}
	else
	{
		/*If prompt wrong, display error message*/
		ft_printf("Please enter:\n\t\"./fractol mandelbrot\" \n\t\tor \
			\n\t\"./fractol julia <value1> <value2>\"\n");
	}
}
