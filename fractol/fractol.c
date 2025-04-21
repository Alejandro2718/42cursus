/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:08 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/21 18:24:17 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	double	re;
	double	im;
	int		color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	// Draw visualization to demonstrate complex plane mapping
	for (int y = 0; y < WINDOW_HEIGHT; y++)
	{
		for (int x = 0; x < WINDOW_WIDTH; x++)
		{
			// Map pixel coordinates to complex plane
			re = map_pixel_to_real(x, WINDOW_WIDTH);
			im = map_pixel_to_imag(y, WINDOW_HEIGHT);
			// Create a color based on complex coordinates
			color = map_complex_to_color(re, im);
			// Put pixel on the image
			ft_put_pixel(&img, x, y, color);
		}
	}
	// Display the image
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
