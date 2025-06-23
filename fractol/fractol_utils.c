/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejjime <alejjime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:04:50 by alejjime          #+#    #+#             */
/*   Updated: 2025/05/03 17:51:37 by alejjime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Malloc problems");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations_definition = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, win_ptr:
			KeyPress,
			KeyPressMask,
			Key_handler,
			fractol);
	mlx_hook(fractol->mlx_window, 
			ButtonPress,
			ButtonPressMask,
			mouse_handler,
			fractol);
	mlx_hook(fractol->mlx_window, 
			DestroyNotify,
			StructureNotifyMask,
			close_handler,
			fractol);
	mlx_hook(fractol->mlx_window, 
			MotionNotify,
			PointerMotionMask,
			julia_track,
			fractol);
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
	events_init(fractol);
	data_init(fractol);
}
