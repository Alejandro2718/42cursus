/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:04:50 by alejjime          #+#    #+#             */
/*   Updated: 2025/04/30 18:54:41 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Malloc problems");
	exit(EXIT_FAILURE);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connec = mlx_init();
	if (fractol->mlx_connec == NULL)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connec, WINDOW_WIDTH,
			WINDOW_HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connec);
		free(fractol->mlx_connec);
		malloc_error();
	}
	fractol->img.img_pit = mlx_new_image(fractol->mlx_connec, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (fractol->img.img_pit == NULL)
	{
		mlx_destroy_window(fractol->mlx_connec, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connec);
		free(fractol->mlx_connec);
		malloc_error();
	}
	fractol->img.pixel_pit = mlx_get_data_addr(fractol->img.img_pit,
			&fractol->img.bits_p_pixel, &fractol->img.line_len,
			&fractol->img.endian);
	// events_init(fractol);// POR HACER
	// data_init(fractol);// POR HACER
}
