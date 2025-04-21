/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:04:50 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/21 18:34:36 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

double	map_pixel_to_real(int x, int width)
{
	return (MIN_RE + x * (MAX_RE - MIN_RE) / width);
}

double	map_pixel_to_imag(int y, int height)
{
	return (MAX_IM - y * (MAX_IM - MIN_IM) / height);
}

/*
 * Function to create a color based on complex plane position
 * This is a simple visualization to demonstrate mapping
 */
int	map_complex_to_color(double re, double im)
{
	int r;
	int g;
	int b;

	// Map real part to red (0-255)
	r = (int)((re - MIN_RE) / (MAX_RE - MIN_RE) * 255);
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;

	// Map imaginary part to green (0-255)
	g = (int)((im - MIN_IM) / (MAX_IM - MIN_IM) * 255);
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;

	// Blue can be a function of distance from origin
	b = (int)(sqrt(re * re + im * im) / 3.0 * 255);
	if (b > 255)
		b = 255;

	return ((r << 16) | (g << 8) | b);
}