/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:32:37 by alejjime          #+#    #+#             */
/*   Updated: 2025/05/03 18:05:41 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;

	(void)color;

	offset = (y * img->line_len) + (x * (img->bits_p_pixel / 8));
	color = *(unsigned int *)(img->pixel_pit + offset);
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, +2, 0, WINDOW_WIDTH);
	c.y = map(x, +2, -2, 0, WINDOW_HEIGHT);
	while (i < fractol->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractol->iterations_definition);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractol->img, PURPLE);
}
/*
Mandelbrot set exist between:
	x Real: -2 and 1
	y Imagi: -1.5 and 1.5
*/

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WINDOW_HEIGHT)
	{
		x = -1;
		while (++x < WINDOW_WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connec, fractol->mlx_window, fractol->img.img_pit, 0, 0);
}
