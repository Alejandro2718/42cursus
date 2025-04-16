/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:53:08 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/16 15:55:44 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 400

void	ft_put_pixel(t_data *img, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
	{
		pxl = img->addr + (y * img->line_length + x * (img->bits_per_pixel
					/ 8));
		*(unsigned int *)pxl = color;
	}
}

int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		center_x;
	int		center_y;
	double	r;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fract-ol");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	//
	center_x = 250;
	center_y = 200;
	for (double theta = 0; theta < 10 * M_PI; theta += 0.01)
	{
		ft_put_pixel(&img, x, y, 0x00FF00);
		r = 5 * theta; // makes the spiral "grow"
		x = center_x + (int)(r * cos(theta));
		y = center_y + (int)(r * sin(theta));
		ft_put_pixel(&img, x, y, 0xFF00FF); // purple
	}
	// Cuando la imagen este lista la display
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
